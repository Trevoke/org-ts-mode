/**
 * @file External scanner for Org-mode inline grammar (tree-sitter-org-inline)
 * @author Tree-sitter Org-mode Contributors
 * @license MIT
 *
 * This scanner validates emphasis boundaries according to org-syntax.md rules.
 * It also handles tag scanning at the end of headlines.
 *
 * Architecture:
 * - Character classification: PRE/POST character validation
 * - Boundary validation: Opening/closing delimiter validation
 * - Lookahead scanning: Find valid closing delimiters
 * - State management: Grammar-controlled nesting via valid_symbols
 * - Serialization: Save/restore state for incremental parsing
 *
 * Design principles:
 * - Correctness first (implement org-syntax.md exactly)
 * - Clear code (obvious is better than clever)
 * - Minimal state (only what's needed for incremental parsing)
 * - Bounded resources (fixed limits, no dynamic allocation)
 * - Testable (clear inputs/outputs for each function)
 *
 * References:
 * - org-syntax.md lines 1744-1777 (emphasis specification)
 * - doc/SCANNER_ARCHITECTURE.md (detailed design)
 * - doc/EMPHASIS_RULES_REFERENCE.md (implementation rules)
 */

#include <tree_sitter/parser.h>
#include <wctype.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <assert.h>
#include <stdio.h>  // For debug fprintf

// ============================================================================
// CONSTANTS AND ENUMS
// ============================================================================

/**
 * Token types (must match order in grammar.js externals array)
 */
enum TokenType {
    TAGS,  // Tags portion (:tag1:tag2:)

    // Emphasis markers (scanner validates PRE/POST/CONTENTS boundaries)
    BOLD_OPEN,
    BOLD_CLOSE,
    ITALIC_OPEN,
    ITALIC_CLOSE,
    UNDERLINE_OPEN,
    UNDERLINE_CLOSE,
    CODE_OPEN,
    CODE_CLOSE,
    VERBATIM_OPEN,
    VERBATIM_CLOSE,
    STRIKE_OPEN,
    STRIKE_CLOSE,

    // Delimiter fallback - emitted when emphasis is invalid
    DELIMITER_CHAR,

    // Plain colon - colon not part of valid tags
    PLAIN_COLON,

    // Plain link - scanner handles to ensure priority over plain_text
    PLAIN_LINK,

    // Plain text - scanner handles subscript/superscript boundary detection
    PLAIN_TEXT,

    // Code and verbatim - scanner emits entire construct as single token
    CODE,       // ~content~
    VERBATIM,   // =content=

    // Line break - scanner validates PRE (not backslash)
    LINE_BREAK,  // \\ at end of line
};

/**
 * Maximum nesting depth for emphasis
 *
 * Rationale: 16 levels is more than enough for any realistic document.
 * org-syntax.md doesn't specify a limit, but we need bounded state for
 * serialization and performance.
 */
#define MAX_EMPHASIS_DEPTH 16

/**
 * Maximum lookahead distance for finding matching closer
 *
 * Rationale: Prevents scanner from hanging on very long content.
 * 1000 characters is more than enough for any reasonable emphasis content.
 * If content exceeds this, emphasis delimiter will be treated as plain text.
 */
#define MAX_LOOKAHEAD_DISTANCE 1000

/**
 * Serialization format version
 */
#define SERIALIZATION_VERSION 0x01

/**
 * Serialization buffer size (fixed)
 *
 * Layout (6 bytes):
 * [0-3]: last_char (int32_t)
 * [4]: at_line_start (bool)
 * [5]: state_flags (uint8_t)
 */
#define SERIALIZATION_SIZE 6

/**
 * State flags (currently unused, reserved for future extensions)
 */
#define STATE_FLAG_NONE 0x00

// ============================================================================
// DATA STRUCTURES
// ============================================================================

/**
 * Scanner state structure
 *
 * This structure maintains the minimal state needed for incremental parsing:
 * - Delimiter stack: Tracks which emphasis delimiters are currently open
 * - Stack depth: Current depth of the delimiter stack
 * - State flags: Reserved for future extensions
 *
 * Design:
 * - Fixed size (20 bytes) for efficient serialization
 * - No pointers (simplifies serialization)
 * - No dynamic allocation (performance and simplicity)
 */
// New stateless scanner structure
typedef struct {
    int32_t last_char;      // Last character seen (for PRE boundary)
    bool at_line_start;     // Are we at beginning of line?
    uint8_t state_flags;    // Bit flags for tags state
} Scanner;  // 8 bytes total (6 data + 2 padding, down from 20)

// State flag bits
#define FLAG_IN_TAGS 0x01

/**
 * Scanning context (stack-allocated, not serialized)
 *
 * Groups related data to reduce function parameter count.
 * Passed to helper functions to avoid global state.
 */
typedef struct {
    Scanner *scanner;           // Scanner state
    TSLexer *lexer;            // Tree-sitter lexer
    const bool *valid_symbols;  // What grammar expects
} ScanContext;

// ============================================================================
// FORWARD DECLARATIONS
// ============================================================================

// Character classification
static inline bool is_pre_char(int32_t c, bool at_line_start);
static inline bool is_post_char(int32_t c, bool at_line_end);
static inline bool is_whitespace(int32_t c);
static inline bool is_emphasis_marker(int32_t c);
static inline bool at_line_boundary(TSLexer *lexer);

// Boundary validation
static bool validate_opening_boundary(ScanContext *ctx, char marker, int32_t prev_char, bool at_line_start);
static bool validate_closing_boundary(ScanContext *ctx, char marker, int32_t prev_char);

// Lookahead scanning
static bool find_closing_delimiter(ScanContext *ctx, char marker);

// Serialization
static unsigned serialize(Scanner *scanner, char *buffer);
static void deserialize(Scanner *scanner, const char *buffer, unsigned length);

// Tag scanning (preserve existing functionality)
static bool scan_tags(ScanContext *ctx);
static bool is_valid_tag_char(int32_t c);

// Plain text scanning with subscript/superscript boundary detection
static bool scan_plain_text(ScanContext *ctx);
static bool is_valid_script_pattern(TSLexer *lexer);
static bool is_plain_text_delimiter(int32_t c);

// Plain link scanning
static bool scan_plain_link(ScanContext *ctx);
static bool is_at_plain_link_start(TSLexer *lexer);

// Inline source block detection
static bool is_at_inline_src_start(TSLexer *lexer);

// Inline babel call detection
static bool is_at_inline_babel_call_start(TSLexer *lexer);

// ============================================================================
// CHARACTER CLASSIFICATION FUNCTIONS
// ============================================================================

/**
 * Check if character is valid PRE (before opening marker)
 *
 * PRE: whitespace, -, (, {, ', ", or beginning of line
 * Source: org-syntax.md lines 1756-1757
 *
 * @param c Character to check (int32_t for unicode support)
 * @param at_line_start true if at beginning of line
 * @return true if valid PRE character
 */
static inline bool is_pre_char(int32_t c, bool at_line_start) {
    // Beginning of line is always valid PRE
    if (at_line_start) {
        return true;
    }

    // Unknown previous character (never scanned by scanner) - skip validation
    // This is a limitation of the Tree-sitter API: we can't access characters
    // that were consumed by the grammar rather than the scanner
    if (c == 0) {
        return true;  // Assume valid when unknown
    }

    // Check explicit PRE character set
    return c == ' '  || c == '\t' || c == '\n' ||
           c == '-'  || c == '('  || c == '{' ||
           c == '\'' || c == '"';
}

/**
 * Check if character is valid POST (after closing marker)
 *
 * POST: whitespace, -, ., ,, ;, :, !, ?, ', ), }, [, ", \, or end of line
 * Source: org-syntax.md lines 1768-1769
 *
 * @param c Character to check
 * @param at_line_end true if at end of line
 * @return true if valid POST character
 */
static inline bool is_post_char(int32_t c, bool at_line_end) {
    // End of line is always valid POST
    if (at_line_end) {
        return true;
    }

    // Check explicit POST character set
    return c == ' '  || c == '\t' || c == '\n' ||
           c == '-'  || c == '.'  || c == ',' ||
           c == ';'  || c == ':'  || c == '!' ||
           c == '?'  || c == '\'' || c == ')' ||
           c == '}'  || c == '['  || c == '"' ||
           c == '\\';
}

/**
 * Check if character is whitespace
 *
 * @param c Character to check
 * @return true if whitespace (space, tab, newline)
 */
static inline bool is_whitespace(int32_t c) {
    return c == ' ' || c == '\t' || c == '\n';
}

/**
 * Check if character is an emphasis marker
 *
 * @param c Character to check
 * @return true if *, /, _, +, ~, or =
 */
static inline bool is_emphasis_marker(int32_t c) {
    return c == '*' || c == '/' || c == '_' ||
           c == '+' || c == '~' || c == '=';
}

/**
 * Check if at line boundary
 *
 * @param lexer Tree-sitter lexer
 * @return true if at beginning or end of line, or EOF
 */
static inline bool at_line_boundary(TSLexer *lexer) {
    return lexer->lookahead == '\n' ||
           lexer->lookahead == '\r' ||
           lexer->eof(lexer);
}

// ============================================================================
// STATE MANAGEMENT FUNCTIONS
// ============================================================================



// Delimiter stack functions removed in Phase 2.1
// Scanner is now stateless - grammar controls nesting via valid_symbols

// ============================================================================
// BOUNDARY VALIDATION FUNCTIONS
// ============================================================================

/**
 * PRE boundary validation (simple form for testing)
 *
 * Valid PRE characters: whitespace | - | ( | { | ' | " | BOL
 * Source: org-syntax.md lines 1756-1757
 *
 * @param ch Character to check (int32_t for unicode support)
 * @param at_bol true if at beginning of line
 * @return true if valid PRE character
 */
static bool is_valid_pre_char(int32_t ch, bool at_bol) {
    if (at_bol) return true;
    if (iswspace(ch)) return true;
    if (ch == '-' || ch == '(' || ch == '{' ||
        ch == '\'' || ch == '"') return true;
    return false;
}

/**
 * POST boundary validation (simple form for testing)
 *
 * Valid POST characters: whitespace | - | . | , | ; | : | ! | ? | ' | ) | } | [ | " | \ | EOL
 * Source: org-syntax.md lines 1768-1769
 *
 * @param ch Character to check
 * @return true if valid POST character
 */
static bool is_valid_post_char(int32_t ch) {
    if (ch == 0 || ch == '\n') return true;  // EOL
    if (iswspace(ch)) return true;
    if (ch == '-' || ch == '.' || ch == ',' || ch == ';' ||
        ch == ':' || ch == '!' || ch == '?' || ch == '\'' ||
        ch == ')' || ch == '}' || ch == '[' || ch == '"' ||
        ch == '\\') return true;
    return false;
}

/**
 * Validate opening boundary for emphasis
 *
 * Rules (org-syntax.md):
 * 1. Character before marker must be valid PRE
 * 2. Character after marker must NOT be whitespace (CONTENTS boundary)
 * 3. Marker must not be at EOF
 *
 * Note: This function temporarily advances the lexer to peek at the character
 * after the marker. The caller is responsible for restoring the lexer position
 * if needed (typically this is called in a lookahead context).
 *
 * @param ctx Scanning context
 * @param marker The emphasis marker character (*, /, _, +, ~, =)
 * @param prev_char Character immediately before marker
 * @param at_line_start true if marker is at beginning of line
 * @return true if valid opening boundary
 */
static bool validate_opening_boundary(
    ScanContext *ctx,
    char marker,
    int32_t prev_char,
    bool at_line_start
) {
    if (ctx == NULL || ctx->lexer == NULL) {
        return false;
    }

    TSLexer *lexer = ctx->lexer;

    // Rule 1: Check PRE character
    if (!is_pre_char(prev_char, at_line_start)) {
        return false;
    }

    // We're currently positioned at the marker, need to look at next char
    // Advance past marker to check what follows
    lexer->advance(lexer, false);

    // Rule 3: Marker at EOF is invalid
    if (lexer->eof(lexer)) {
        return false;
    }

    // Rule 2: Character immediately after marker must not be whitespace
    if (is_whitespace(lexer->lookahead)) {
        return false;  // Invalid: whitespace after opening marker
    }

    // Valid opening boundary
    return true;
}

/**
 * Validate closing boundary for emphasis
 *
 * Rules (org-syntax.md):
 * 1. Character before marker must NOT be whitespace (CONTENTS boundary)
 * 2. Character after marker must be valid POST
 *
 * Note: This function temporarily advances the lexer to peek at the character
 * after the marker. The caller is responsible for restoring the lexer position.
 *
 * @param ctx Scanning context
 * @param marker The emphasis marker character
 * @param prev_char Character immediately before marker
 * @return true if valid closing boundary
 */
static bool validate_closing_boundary(
    ScanContext *ctx,
    char marker,
    int32_t prev_char
) {
    if (ctx == NULL || ctx->lexer == NULL) {
        return false;
    }

    TSLexer *lexer = ctx->lexer;

    // Rule 1: Character before marker must not be whitespace
    if (is_whitespace(prev_char)) {
        return false;  // Invalid: whitespace before closing marker
    }

    // We're currently at the marker, need to look at next char
    // Advance past marker to check what follows
    lexer->advance(lexer, false);

    // Check if we're at line boundary
    bool at_line_end = at_line_boundary(lexer);

    // Rule 2: Character after marker must be valid POST
    if (!is_post_char(lexer->lookahead, at_line_end)) {
        return false;  // Invalid POST character
    }

    // Valid closing boundary
    return true;
}

// ============================================================================
// LOOKAHEAD SCANNING FUNCTIONS
// ============================================================================

/**
 * Look ahead to find valid closing delimiter
 *
 * Uses mark_end() mechanism to lookahead without consuming input.
 * This function is called AFTER the opening delimiter has been consumed
 * and mark_end() has been called to mark the token boundary.
 *
 * Scans forward to find a matching marker with valid closing boundary.
 * Stops at line end (org emphasis cannot span lines) or max lookahead distance.
 *
 * Implementation notes:
 * - mark_end() must be called BEFORE this function
 * - This function advances the lexer for lookahead only
 * - The token boundary remains at the opening delimiter (set by mark_end)
 * - If matching closer found, returns true (caller emits OPEN token)
 * - If no closer found, returns false (delimiter is plain text)
 *
 * Precondition: lexer positioned AFTER opening marker, mark_end() called
 * Postcondition: lexer position advanced (lookahead), token boundary unchanged
 *
 * @param ctx Scanning context
 * @param marker Delimiter to find
 * @return true if valid closing delimiter found
 */
/**
 * Check if a character at current position could be a valid closer for parent emphasis
 *
 * This is a quick check - we verify:
 * 1. The previous character is not whitespace (no trailing whitespace in CONTENTS)
 * 2. We're not at distance 0 (not empty CONTENTS)
 *
 * We don't fully validate POST here (would require another lookahead),
 * but this is conservative - if it MIGHT be a valid closer, we stop.
 */
static inline bool could_be_valid_closer(int32_t prev_char, int distance) {
    return distance > 0 && !is_whitespace(prev_char);
}

static bool find_closing_delimiter(ScanContext *ctx, char marker) {
    if (ctx == NULL || ctx->lexer == NULL) {
        return false;
    }

    TSLexer *lexer = ctx->lexer;
    const bool *valid_symbols = ctx->valid_symbols;
    int32_t prev_char = 0;
    int distance = 0;

    // Determine which parent emphasis we're nested inside (if any)
    // If a CLOSE token is valid, we're inside that emphasis type
    // We must not cross that parent's closing boundary
    bool inside_bold = valid_symbols[BOLD_CLOSE] && marker != '*';
    bool inside_italic = valid_symbols[ITALIC_CLOSE] && marker != '/';
    bool inside_underline = valid_symbols[UNDERLINE_CLOSE] && marker != '_';
    bool inside_strike = valid_symbols[STRIKE_CLOSE] && marker != '+';
    // Note: code/verbatim don't allow nested emphasis, handled separately

    // Track previous character for boundary validation
    // Start with whatever came after opening marker
    if (!lexer->eof(lexer)) {
        prev_char = lexer->lookahead;
    }

    // Scan forward looking for closing marker
    // Stop at: EOF, newline, or max lookahead distance
    while (!lexer->eof(lexer) && distance < MAX_LOOKAHEAD_DISTANCE) {
        int32_t current = lexer->lookahead;

        // Note: Emphasis CAN span newlines per org-syntax.md line 1186:
        // "while many objects may contain newlines"
        // The constraint is only that CONTENTS cannot begin/end with whitespace.
        // Blank lines terminate the paragraph (handled by grammar), not the scanner.
        //
        // EXCEPTION: Code (~) and verbatim (=) are opaque and contain "a string"
        // per org-syntax.md line 1765-1766. They should be line-scoped to avoid
        // capturing too much content. This matches practical org-mode behavior.
        if ((current == '\n' || current == '\r') && (marker == '~' || marker == '=')) {
            return false;  // Code/verbatim cannot span lines
        }

        // Check if we've hit a parent emphasis's closing boundary
        // If so, we cannot find a valid closer for our marker within scope
        // This prevents crossing emphasis boundaries (org-syntax requirement)
        if (inside_bold && current == '*' && could_be_valid_closer(prev_char, distance)) {
            return false;  // Would cross bold boundary
        }
        if (inside_italic && current == '/' && could_be_valid_closer(prev_char, distance)) {
            return false;  // Would cross italic boundary
        }
        if (inside_underline && current == '_' && could_be_valid_closer(prev_char, distance)) {
            return false;  // Would cross underline boundary
        }
        if (inside_strike && current == '+' && could_be_valid_closer(prev_char, distance)) {
            return false;  // Would cross strike boundary
        }

        // Found potential closing marker
        if (current == marker) {
            // Validate closing boundary
            // Need to check that previous char is not whitespace (no trailing whitespace)
            // and that next char (after marker) is valid POST char

            // Check for EMPTY CONTENTS (org-syntax: CONTENTS may not be empty)
            // If distance == 0, we found the closer immediately after opener = empty CONTENTS
            if (distance == 0) {
                // Empty CONTENTS is invalid per spec
                // The marker becomes part of potential content, continue looking
                prev_char = current;
                lexer->advance(lexer, false);
                distance++;
                continue;
            }

            // Check CONTENTS boundary (no trailing whitespace before closer)
            if (is_whitespace(prev_char)) {
                // Invalid: whitespace before closer
                // Continue looking for another potential closer
                prev_char = current;
                lexer->advance(lexer, false);
                distance++;
                continue;
            }

            // Advance past the closing marker to check POST boundary
            lexer->advance(lexer, false);
            distance++;

            // Check POST boundary
            bool at_line_end = at_line_boundary(lexer);
            if (is_post_char(lexer->lookahead, at_line_end)) {
                // Valid closing found!
                // Note: Token boundary is still at opening marker (mark_end was called before)
                return true;
            }

            // Invalid POST boundary, continue looking
            // lexer is now past the invalid closer marker
            prev_char = marker;  // The marker we just passed
            continue;
        }

        // Track previous character for next iteration
        prev_char = current;

        // Advance to next character
        lexer->advance(lexer, false);
        distance++;
    }

    // Reached EOF, newline, or max distance without finding valid closing
    return false;
}

// is_valid_emphasis removed in Phase 2.1
// Emphasis validation now done inline in scan_emphasis without stack checking

// ============================================================================
// SERIALIZATION FUNCTIONS
// ============================================================================

/**
 * Serialize scanner state to buffer
 *
 * Format (version 1, 20 bytes):
 * [0]: Version (0x01)
 * [1]: Stack depth (0-MAX_EMPHASIS_DEPTH)
 * [2]: State flags
 * [3]: Padding
 * [4-19]: Delimiter stack (16 bytes)
 *
 * @param scanner Scanner state
 * @param buffer Output buffer (must be at least SERIALIZATION_SIZE bytes)
 * @return Number of bytes written
 */
static unsigned serialize(Scanner *scanner, char *buffer) {
    if (!scanner) return 0;

    // Serialize: last_char (4) + at_line_start (1) + state_flags (1) = 6 bytes
    memcpy(buffer, &scanner->last_char, sizeof(int32_t));
    buffer[4] = scanner->at_line_start ? 1 : 0;
    buffer[5] = scanner->state_flags;

    return 6;
}

/**
 * Deserialize scanner state from buffer
 *
 * If buffer is invalid or corrupted, resets to clean state.
 * This ensures graceful degradation - we never fail to parse,
 * we just might parse from scratch for this chunk.
 *
 * @param scanner Scanner state to populate
 * @param buffer Input buffer
 * @param length Buffer length
 */
static void deserialize(Scanner *scanner, const char *buffer, unsigned length) {
    if (!scanner) return;

    if (length == 0 || !buffer) {
        // Clean state
        scanner->last_char = 0;
        scanner->at_line_start = true;
        scanner->state_flags = 0;
        return;
    }

    if (length >= 6) {
        memcpy(&scanner->last_char, buffer, sizeof(int32_t));
        scanner->at_line_start = buffer[4] != 0;
        scanner->state_flags = buffer[5];
    } else {
        // Invalid buffer, use clean state
        scanner->last_char = 0;
        scanner->at_line_start = true;
        scanner->state_flags = 0;
    }
}

// ============================================================================
// PLAIN TEXT SCANNING WITH SUBSCRIPT/SUPERSCRIPT BOUNDARY DETECTION
// ============================================================================

/**
 * Check if character is a delimiter that ends plain text
 *
 * These are characters that can start other inline objects.
 * Plain text stops before these to let the grammar match them.
 *
 * Also stops at whitespace so plain_link can match at word boundaries.
 */
static bool is_plain_text_delimiter(int32_t c) {
    // Whitespace - stop so plain_link can match at word boundaries
    if (c == ' ' || c == '\t') {
        return true;
    }
    // Emphasis markers
    if (c == '*' || c == '/' || c == '_' || c == '+' || c == '~' || c == '=') {
        return true;
    }
    // Link/bracket markers
    if (c == '[' || c == ']' || c == '<' || c == '>') {
        return true;
    }
    // Other object markers
    // Note: '{' needs special handling (could start macro {{{)
    if (c == '{' || c == '@' || c == '\\') {
        return true;
    }
    // LaTeX markers
    if (c == '$') {
        return true;
    }
    // Line boundary
    if (c == '\n' || c == 0) {
        return true;
    }
    return false;
}

/**
 * Validate SCRIPT pattern for subscript/superscript
 *
 * SCRIPT is one of:
 * - Single asterisk (*)
 * - Braced content {...} with balanced braces
 * - Parenthesized content (...) with balanced parens
 * - Pattern: SIGN? CHARS FINAL
 *   - SIGN (optional): + or -
 *   - CHARS: zero or more alphanumeric, comma, backslash, dot
 *   - FINAL: exactly one alphanumeric
 *
 * Source: org-syntax.md lines 1621-1637
 *
 * @param lexer Lexer positioned at start of potential SCRIPT
 * @return true if valid SCRIPT pattern exists
 */
static bool is_valid_script_pattern(TSLexer *lexer) {
    int32_t c = lexer->lookahead;

    // Case 1: Single asterisk
    if (c == '*') {
        return true;  // Don't advance - just validate
    }

    // Case 2: Braced content {...}
    if (c == '{') {
        lexer->advance(lexer, false);
        int depth = 1;
        while (depth > 0 && lexer->lookahead != '\n' && !lexer->eof(lexer)) {
            if (lexer->lookahead == '{') depth++;
            else if (lexer->lookahead == '}') depth--;
            lexer->advance(lexer, false);
        }
        return depth == 0;
    }

    // Case 3: Parenthesized content (...)
    if (c == '(') {
        lexer->advance(lexer, false);
        int depth = 1;
        while (depth > 0 && lexer->lookahead != '\n' && !lexer->eof(lexer)) {
            if (lexer->lookahead == '(') depth++;
            else if (lexer->lookahead == ')') depth--;
            lexer->advance(lexer, false);
        }
        return depth == 0;
    }

    // Case 4: SIGN? CHARS FINAL
    // Optional sign
    if (c == '+' || c == '-') {
        lexer->advance(lexer, false);
        c = lexer->lookahead;
    }

    // Must have at least one alphanumeric (the FINAL)
    if (!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))) {
        return false;
    }

    // Valid - we have at least one alphanumeric
    return true;
}

/**
 * Scan plain text with subscript/superscript boundary detection
 *
 * Scans characters as plain text, but stops BEFORE:
 * - alphanumeric followed by _ or ^ with valid SCRIPT pattern (subscript/superscript)
 * - whitespace followed by letter (to let plain_link check happen)
 *
 * Note: plain_link detection is handled in main scan function, not here.
 *
 * @param ctx Scanning context
 * @return true if plain text token emitted
 */
static bool scan_plain_text(ScanContext *ctx) {
    TSLexer *lexer = ctx->lexer;
    const bool *valid_symbols = ctx->valid_symbols;
    Scanner *scanner = ctx->scanner;
    bool has_content = false;
    int32_t last_consumed = 0;  // Track last character consumed for PRE validation

    while (true) {
        // Mark current position as potential token end
        lexer->mark_end(lexer);

        int32_t c = lexer->lookahead;

        // Stop at line boundary or EOF
        if (c == '\n' || c == 0 || lexer->eof(lexer)) {
            break;
        }

        // Handle spaces: consume them, but stop if next char could be plain_link
        if (c == ' ' || c == '\t') {
            // Consume all consecutive whitespace
            while ((lexer->lookahead == ' ' || lexer->lookahead == '\t') && !lexer->eof(lexer)) {
                last_consumed = lexer->lookahead;
                lexer->advance(lexer, false);
                has_content = true;
            }
            // Mark after whitespace
            lexer->mark_end(lexer);

            // If next char is a letter and plain_link is valid, stop here
            // to let main scan check for protocol://
            c = lexer->lookahead;
            if (valid_symbols[PLAIN_LINK] &&
                ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))) {
                break;
            }
            // Otherwise continue scanning
            continue;
        }

        // Stop at other delimiters (now includes space/tab via is_plain_text_delimiter)
        if (is_plain_text_delimiter(c)) {
            break;
        }

        // Stop at colon - might be start of a plain link or tags
        // Let grammar/other scanner functions handle it
        if (c == ':') {
            break;
        }

        // Check for subscript/superscript boundary
        bool is_alnum = (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9');
        if (is_alnum) {
            // Check for inline source block: src_LANG{ or src_LANG[
            // Must check BEFORE consuming to allow stopping before 's'
            // Note: is_at_inline_src_start advances lexer, but if we return,
            // tree-sitter resets to mark_end position (before 's')
            if (c == 's' && is_at_inline_src_start(lexer)) {
                // Pattern matches - stop before 's'
                // Mark is already before 's' (set at top of loop)
                if (has_content) {
                    scanner->last_char = last_consumed;
                    lexer->result_symbol = PLAIN_TEXT;
                    return true;
                }
                // No content before 's' - return false, let Priority 2 handle it
                return false;
            }

            // Check for inline babel call: call_NAME(...)
            // Must check BEFORE consuming to allow stopping before 'c'
            if (c == 'c' && is_at_inline_babel_call_start(lexer)) {
                // Pattern matches - stop before 'c'
                // Mark is already before 'c' (set at top of loop)
                if (has_content) {
                    scanner->last_char = last_consumed;
                    lexer->result_symbol = PLAIN_TEXT;
                    return true;
                }
                // No content before 'c' - return false, let Priority 2 handle it
                return false;
            }

            // Advance past alphanumeric
            last_consumed = c;
            lexer->advance(lexer, false);
            int32_t next = lexer->lookahead;

            if (next == '_' || next == '^') {
                // Potential subscript/superscript
                // Mark AFTER alnum, BEFORE _/^ (for invalid script case)
                lexer->mark_end(lexer);

                // Now advance past _/^ to check script pattern
                lexer->advance(lexer, false);

                if (is_valid_script_pattern(lexer)) {
                    // Valid subscript/superscript!
                    // We need token to end BEFORE alnum, but mark is AFTER alnum
                    // We can't "un-mark". Emit what we have (includes alnum).
                    // This will cause subscript to fail (it needs alnum at start)
                    // and fall back to plain_text for whole thing.
                    //
                    // Workaround: if no prior content, return false to let subscript try
                    if (has_content) {
                        // Emit up to mark (includes alnum). Subscript won't match next.
                        // Not ideal but better than ERROR
                        scanner->last_char = last_consumed;  // Track for PRE validation
                        lexer->result_symbol = PLAIN_TEXT;
                        return true;
                    }
                    // No content before - let subscript/superscript match from start
                    return false;
                }

                // NOT a valid script pattern
                // Token ends AFTER alnum, BEFORE _/^ (mark is already set correctly)
                // The _/^ will be handled by next scan (e.g., UNDERLINE_CLOSE)
                has_content = true;
                scanner->last_char = last_consumed;  // Track for PRE validation
                lexer->result_symbol = PLAIN_TEXT;
                return true;
            }

            // Not followed by _ or ^, just regular alphanumeric
            // Update mark to include it
            lexer->mark_end(lexer);
            has_content = true;
            continue;
        }

        // Regular character - consume it
        last_consumed = c;
        lexer->advance(lexer, false);
        has_content = true;
    }

    if (has_content) {
        scanner->last_char = last_consumed;  // Track for PRE validation
        lexer->result_symbol = PLAIN_TEXT;
        return true;
    }

    return false;
}

// ============================================================================
// PLAIN LINK SCANNING
// ============================================================================

/**
 * Check if character is valid in plain link path
 *
 * Path can contain most characters except whitespace and newlines.
 * Also stops at certain delimiters that likely end the link.
 */
static bool is_plain_link_path_char(int32_t c) {
    // Stop at whitespace, newlines, EOF
    if (c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == 0) {
        return false;
    }
    // Stop at characters that typically end a URL in text context
    // Note: We allow most punctuation since URLs can contain them
    // But we stop at common sentence-ending punctuation when followed by space
    return true;
}

/**
 * Check if current position looks like the start of a plain link (protocol://)
 *
 * Looks ahead to see if we have: LETTER+ :// (without advancing mark_end)
 * This is used by scan_plain_text to stop before plain_link patterns.
 *
 * NOTE: This function advances the lexer for lookahead but the caller
 * should NOT rely on the final lexer position.
 *
 * @param lexer Lexer positioned at potential protocol start
 * @return true if pattern looks like protocol://
 */
static bool is_at_plain_link_start(TSLexer *lexer) {
    // Protocol must start with letter
    int32_t c = lexer->lookahead;
    if (!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))) {
        return false;
    }

    // Advance past first letter
    lexer->advance(lexer, false);

    // Consume rest of protocol: [a-zA-Z0-9.-]*
    // NOTE: Don't include + as protocol char - it's an emphasis marker
    while (true) {
        c = lexer->lookahead;
        // Don't consume emphasis markers
        if (c == '+' || c == '~' || c == '=' || c == '*' || c == '/' || c == '_') {
            break;
        }
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') ||
            (c >= '0' && c <= '9') || c == '.' || c == '-') {
            lexer->advance(lexer, false);
        } else {
            break;
        }
    }

    // Must have :// next
    if (lexer->lookahead != ':') {
        return false;
    }
    lexer->advance(lexer, false);

    if (lexer->lookahead != '/') {
        return false;
    }
    lexer->advance(lexer, false);

    if (lexer->lookahead != '/') {
        return false;
    }

    // Looks like protocol://
    return true;
}

/**
 * Check if current position looks like a COMPLETE inline source block
 *
 * Pattern: src_LANG{BODY} or src_LANG[HEADERS]{BODY} where:
 * - LANG is non-empty and contains no whitespace, '[', or '{'
 * - HEADERS (optional) is balanced [] with no newlines
 * - BODY is content followed by closing '}' on the same line
 *
 * This function advances the lexer for lookahead. The caller should NOT
 * rely on the final lexer position - tree-sitter will reset if scan returns false.
 *
 * @param lexer Lexer positioned at potential 's' of 'src_'
 * @return true if pattern is a complete inline_src_block
 */
static bool is_at_inline_src_start(TSLexer *lexer) {
    // Must start with 's'
    if (lexer->lookahead != 's') {
        return false;
    }
    lexer->advance(lexer, false);

    // Must have 'r'
    if (lexer->lookahead != 'r') {
        return false;
    }
    lexer->advance(lexer, false);

    // Must have 'c'
    if (lexer->lookahead != 'c') {
        return false;
    }
    lexer->advance(lexer, false);

    // Must have '_'
    if (lexer->lookahead != '_') {
        return false;
    }
    lexer->advance(lexer, false);

    // Must have at least one LANG character (not whitespace, '[', '{')
    int32_t c = lexer->lookahead;
    if (c == ' ' || c == '\t' || c == '\n' || c == '[' || c == '{' || c == 0) {
        return false;  // No language name
    }

    // Consume LANG characters
    while (true) {
        c = lexer->lookahead;
        // Stop at whitespace, '[', '{', EOF, newline
        if (c == ' ' || c == '\t' || c == '\n' || c == '[' || c == '{' || c == 0 || lexer->eof(lexer)) {
            break;
        }
        lexer->advance(lexer, false);
    }

    // Optional: [HEADERS] section
    if (lexer->lookahead == '[') {
        lexer->advance(lexer, false);  // Consume '['
        int bracket_depth = 1;
        while (bracket_depth > 0 && !lexer->eof(lexer)) {
            c = lexer->lookahead;
            if (c == '\n' || c == 0) {
                return false;  // Unclosed headers
            }
            if (c == '[') {
                bracket_depth++;
            } else if (c == ']') {
                bracket_depth--;
            }
            lexer->advance(lexer, false);
        }
        if (bracket_depth != 0) {
            return false;  // Unclosed headers
        }
    }

    // Must have '{' to start body
    if (lexer->lookahead != '{') {
        return false;
    }
    lexer->advance(lexer, false);  // Consume '{'

    // Scan body looking for closing '}' on same line
    int brace_depth = 1;
    while (brace_depth > 0 && !lexer->eof(lexer)) {
        c = lexer->lookahead;
        if (c == '\n' || c == 0) {
            return false;  // Unclosed body - not a valid inline_src_block
        }
        if (c == '{') {
            brace_depth++;
        } else if (c == '}') {
            brace_depth--;
        }
        lexer->advance(lexer, false);
    }

    // Valid if we found matching closing brace
    return (brace_depth == 0);
}

/**
 * Check if current position looks like a COMPLETE inline babel call
 *
 * Pattern: call_NAME(ARGS) or call_NAME[HEADER](ARGS)[HEADER] where:
 * - NAME is non-empty and contains no whitespace, '[]', or '()'
 * - HEADER (optional) is balanced [] with no newlines
 * - ARGS is content followed by closing ')' on the same line
 *
 * This function advances the lexer for lookahead. The caller should NOT
 * rely on the final lexer position - tree-sitter will reset if scan returns false.
 *
 * @param lexer Lexer positioned at potential 'c' of 'call_'
 * @return true if pattern is a complete inline_babel_call
 */
static bool is_at_inline_babel_call_start(TSLexer *lexer) {
    // Must start with 'c'
    if (lexer->lookahead != 'c') {
        return false;
    }
    lexer->advance(lexer, false);

    // Must have 'a'
    if (lexer->lookahead != 'a') {
        return false;
    }
    lexer->advance(lexer, false);

    // Must have 'l'
    if (lexer->lookahead != 'l') {
        return false;
    }
    lexer->advance(lexer, false);

    // Must have 'l'
    if (lexer->lookahead != 'l') {
        return false;
    }
    lexer->advance(lexer, false);

    // Must have '_'
    if (lexer->lookahead != '_') {
        return false;
    }
    lexer->advance(lexer, false);

    // Must have at least one NAME character (not whitespace, '[', ']', '(', ')')
    int32_t c = lexer->lookahead;
    if (c == ' ' || c == '\t' || c == '\n' || c == '[' || c == ']' ||
        c == '(' || c == ')' || c == 0) {
        return false;  // No name
    }

    // Consume NAME characters
    while (true) {
        c = lexer->lookahead;
        // Stop at whitespace, brackets, parens, EOF, newline
        if (c == ' ' || c == '\t' || c == '\n' || c == '[' || c == ']' ||
            c == '(' || c == ')' || c == 0 || lexer->eof(lexer)) {
            break;
        }
        lexer->advance(lexer, false);
    }

    // Optional: [INSIDE_HEADER] section
    if (lexer->lookahead == '[') {
        lexer->advance(lexer, false);  // Consume '['
        int bracket_depth = 1;
        while (bracket_depth > 0 && !lexer->eof(lexer)) {
            c = lexer->lookahead;
            if (c == '\n' || c == 0) {
                return false;  // Unclosed header
            }
            if (c == '[') {
                bracket_depth++;
            } else if (c == ']') {
                bracket_depth--;
            }
            lexer->advance(lexer, false);
        }
        if (bracket_depth != 0) {
            return false;  // Unclosed header
        }
    }

    // Must have '(' to start arguments
    if (lexer->lookahead != '(') {
        return false;
    }
    lexer->advance(lexer, false);  // Consume '('

    // Scan arguments looking for closing ')' on same line
    int paren_depth = 1;
    while (paren_depth > 0 && !lexer->eof(lexer)) {
        c = lexer->lookahead;
        if (c == '\n' || c == 0) {
            return false;  // Unclosed arguments - not a valid inline_babel_call
        }
        if (c == '(') {
            paren_depth++;
        } else if (c == ')') {
            paren_depth--;
        }
        lexer->advance(lexer, false);
    }

    // Must have found closing paren
    if (paren_depth != 0) {
        return false;
    }

    // Optional: [END_HEADER] section after arguments
    if (lexer->lookahead == '[') {
        lexer->advance(lexer, false);  // Consume '['
        int bracket_depth = 1;
        while (bracket_depth > 0 && !lexer->eof(lexer)) {
            c = lexer->lookahead;
            if (c == '\n' || c == 0) {
                return false;  // Unclosed end header
            }
            if (c == '[') {
                bracket_depth++;
            } else if (c == ']') {
                bracket_depth--;
            }
            lexer->advance(lexer, false);
        }
        // Note: We don't strictly require the end header to be closed
        // for the call itself to be valid, but if it starts it should close
        if (bracket_depth != 0) {
            return false;
        }
    }

    // Valid inline babel call
    return true;
}

/**
 * Scan plain link: protocol://path
 *
 * Protocol: [a-zA-Z][a-zA-Z0-9+.-]*
 * Then: ://
 * Path: valid path characters until whitespace/newline
 *
 * This must be called BEFORE scan_plain_text to prevent plain_text
 * from consuming the protocol letters.
 *
 * @param ctx Scanning context
 * @return true if plain link token emitted
 */
static bool scan_plain_link(ScanContext *ctx) {
    TSLexer *lexer = ctx->lexer;

    // Mark start position
    lexer->mark_end(lexer);

    // Protocol must start with letter
    int32_t c = lexer->lookahead;
    if (!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))) {
        return false;
    }

    // Consume protocol: first letter
    lexer->advance(lexer, false);

    // Consume rest of protocol: [a-zA-Z0-9+.-]*
    while (true) {
        c = lexer->lookahead;
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') ||
            (c >= '0' && c <= '9') || c == '+' || c == '.' || c == '-') {
            lexer->advance(lexer, false);
        } else {
            break;
        }
    }

    // Must have :// next
    if (lexer->lookahead != ':') {
        return false;  // Not a plain link
    }
    lexer->advance(lexer, false);

    if (lexer->lookahead != '/') {
        return false;
    }
    lexer->advance(lexer, false);

    if (lexer->lookahead != '/') {
        return false;
    }
    lexer->advance(lexer, false);

    // Must have at least one path character
    if (!is_plain_link_path_char(lexer->lookahead) || lexer->eof(lexer)) {
        return false;  // Empty path
    }

    // Consume path characters
    while (is_plain_link_path_char(lexer->lookahead) && !lexer->eof(lexer)) {
        lexer->advance(lexer, false);
    }

    // Successfully matched plain link
    lexer->mark_end(lexer);
    lexer->result_symbol = PLAIN_LINK;
    return true;
}

// ============================================================================
// TAG SCANNING FUNCTIONS (PRESERVE EXISTING FUNCTIONALITY)
// ============================================================================

/**
 * Scan tags - validates and consumes tags from current position
 *
 * Can be called when lexer is at a space before tags, or at ':' for tags at start.
 * Format: SPACE:tag1:tag2:...:tagN: where tags contain only alphanumeric, _, @, #, %
 * Space is required unless tags are at the start of content.
 * Must end at EOL or EOF.
 *
 * @param ctx Scanning context
 * @return true if tags found and emitted
 */
static bool scan_tags(ScanContext *ctx) {
    if (ctx == NULL || ctx->lexer == NULL) {
        return false;
    }

    TSLexer *lexer = ctx->lexer;

    // Mark current position - if we fail, token ends here (no consumption)
    lexer->mark_end(lexer);

    // Check if we're at a space (preceding tags) or ':' (tags at start)
    bool has_preceding_space = false;

    if (lexer->lookahead == ' ') {
        // Consume space and check if next char is ':'
        lexer->advance(lexer, false);
        if (lexer->lookahead != ':') {
            // Not tags - return false WITHOUT updating mark_end
            // The lexer position has advanced but the token end hasn't
            return false;
        }
        has_preceding_space = true;
        // We're now at ':', continue to tag parsing
    }

    // Should now be at ':' character
    if (lexer->lookahead != ':') {
        return false;
    }

    // Read and validate tags format
    bool in_tag = false;
    bool has_any_tag = false;
    int32_t tag_char_count = 0;

    while (lexer->lookahead != '\n' && !lexer->eof(lexer)) {
        int32_t c = lexer->lookahead;

        if (c == ':') {
            if (in_tag && tag_char_count > 0) {
                // End of current tag AND start of next tag
                has_any_tag = true;
                // Stay in_tag=true, just reset counter for next tag
                tag_char_count = 0;
            } else if (!in_tag) {
                // Start of first/new tag
                in_tag = true;
                tag_char_count = 0;
            } else {
                // Empty tag "::" - invalid
                return false;
            }
        } else if (is_valid_tag_char(c)) {
            if (!in_tag) {
                // Tag character outside of :tag: - invalid
                return false;
            }
            tag_char_count++;
        } else {
            // Invalid character in tags
            return false;
        }

        lexer->advance(lexer, false);
    }

    // Must end with ':' (so tag_char_count should be 0 - not building a tag name)
    // and we must have seen at least one tag
    if (!has_any_tag || tag_char_count > 0) {
        return false;
    }

    // Valid tags!
    lexer->mark_end(lexer);
    lexer->result_symbol = TAGS;
    return true;
}

/**
 * Check if character is valid in tag name
 *
 * Valid tag characters: alphanumeric, _, @, #, %
 *
 * @param c Character to check
 * @return true if valid tag character
 */
static bool is_valid_tag_char(int32_t c) {
    return (c >= 'a' && c <= 'z') ||
           (c >= 'A' && c <= 'Z') ||
           (c >= '0' && c <= '9') ||
           c == '_' || c == '@' || c == '#' || c == '%';
}

// ============================================================================
// CODE AND VERBATIM SCANNING
// ============================================================================

/**
 * Scan entire code or verbatim construct as a single token
 *
 * For code (~content~) and verbatim (=content=), we emit the entire construct
 * as a single token because:
 * 1. Content is opaque (no parsing inside)
 * 2. Content may contain the marker character (e.g., ~outer ~inner~)
 *    when that character isn't at a valid closing position
 *
 * @param ctx Scanning context
 * @param marker The delimiter character ('~' for code, '=' for verbatim)
 * @param token_type The token type to emit (CODE or VERBATIM)
 * @return true if token emitted, false otherwise
 */
static bool scan_code_or_verbatim(ScanContext *ctx, char marker, enum TokenType token_type) {
    if (ctx == NULL || ctx->lexer == NULL) {
        return false;
    }

    TSLexer *lexer = ctx->lexer;
    Scanner *scanner = ctx->scanner;

    // Mark the start position - if we fail, this ensures tree-sitter knows
    // we didn't consume anything
    lexer->mark_end(lexer);

    // Must start with marker
    if (lexer->lookahead != marker) {
        return false;
    }

    // Check PRE boundary
    if (!is_pre_char(scanner->last_char, scanner->at_line_start)) {
        return false;
    }

    // Consume opening marker
    lexer->advance(lexer, false);

    // Mark end after marker - if we fail later, caller can emit DELIMITER_CHAR for just the marker
    lexer->mark_end(lexer);

    // Check CONTENTS boundary (no leading whitespace)
    if (is_whitespace(lexer->lookahead) || lexer->eof(lexer)) {
        return false;  // Invalid: leading whitespace or empty
    }

    // Track previous character for boundary validation
    int32_t prev_char = lexer->lookahead;
    int distance = 0;

    // Scan content looking for valid closing marker
    while (!lexer->eof(lexer) && distance < MAX_LOOKAHEAD_DISTANCE) {
        int32_t current = lexer->lookahead;

        // Code/verbatim cannot span lines
        if (current == '\n' || current == '\r') {
            return false;
        }

        // Found potential closing marker
        if (current == marker) {
            // Check EMPTY CONTENTS
            if (distance == 0) {
                // Empty contents - marker becomes content, continue
                prev_char = current;
                lexer->advance(lexer, false);
                distance++;
                continue;
            }

            // Check CONTENTS boundary (no trailing whitespace)
            if (is_whitespace(prev_char)) {
                // Invalid closer, continue looking
                prev_char = current;
                lexer->advance(lexer, false);
                distance++;
                continue;
            }

            // Advance past closing marker to check POST
            lexer->advance(lexer, false);
            distance++;

            // Check POST boundary
            bool at_line_end = at_line_boundary(lexer);
            if (is_post_char(lexer->lookahead, at_line_end)) {
                // Valid code/verbatim construct!
                lexer->mark_end(lexer);
                lexer->result_symbol = token_type;
                scanner->last_char = marker;  // The closing marker
                return true;
            }

            // Invalid POST, continue looking
            prev_char = marker;
            continue;
        }

        // Regular character - consume it
        prev_char = current;
        lexer->advance(lexer, false);
        distance++;
    }

    // No valid closing found
    return false;
}

// ============================================================================
// MAIN SCAN FUNCTION
// ============================================================================

/**
 * Scan emphasis delimiter (lookahead-based version)
 *
 * Phase 2.2: Uses find_closing_delimiter to determine OPEN vs CLOSE.
 * Grammar controls nesting via valid_symbols array.
 *
 * Strategy:
 * 1. Check if OPEN or CLOSE is valid in this context (via valid_symbols)
 * 2. Validate PRE boundary
 * 3. Consume delimiter and mark_end (token boundary)
 * 4. Check CONTENTS boundary (no leading whitespace for OPEN)
 * 5. Use lookahead to find matching closer:
 *    - If can_open && matching closer found -> emit OPEN
 *    - If can_close && valid POST boundary -> emit CLOSE
 *    - Otherwise -> return false (delimiter is plain text)
 *
 * @param ctx Scanning context
 * @return true if token emitted, false otherwise
 */
static bool scan_emphasis(ScanContext *ctx) {
    if (ctx == NULL || ctx->lexer == NULL || ctx->valid_symbols == NULL) {
        return false;
    }

    TSLexer *lexer = ctx->lexer;
    Scanner *scanner = ctx->scanner;
    const bool *valid_symbols = ctx->valid_symbols;

    // Determine which delimiter we're looking at
    char delimiter = (char)lexer->lookahead;

    // Check if it's an emphasis marker
    if (!is_emphasis_marker(delimiter)) {
        return false;
    }

    // Map delimiter to token types
    enum TokenType open_token, close_token;
    switch (delimiter) {
        case '*':
            open_token = BOLD_OPEN;
            close_token = BOLD_CLOSE;
            break;
        case '/':
            open_token = ITALIC_OPEN;
            close_token = ITALIC_CLOSE;
            break;
        case '_':
            open_token = UNDERLINE_OPEN;
            close_token = UNDERLINE_CLOSE;
            break;
        case '+':
            open_token = STRIKE_OPEN;
            close_token = STRIKE_CLOSE;
            break;
        case '~':
            open_token = CODE_OPEN;
            close_token = CODE_CLOSE;
            break;
        case '=':
            open_token = VERBATIM_OPEN;
            close_token = VERBATIM_CLOSE;
            break;
        default:
            return false;
    }

    // Check if OPEN or CLOSE is valid in this context
    bool can_open = valid_symbols[open_token];
    bool can_close = valid_symbols[close_token];

    if (!can_open && !can_close) {
        return false;  // Neither valid here
    }

    // Validate PRE boundary before consuming delimiter (only for OPEN, not CLOSE)
    if (can_open && !is_pre_char(scanner->last_char, scanner->at_line_start)) {
        #ifdef DEBUG_SCANNER
        fprintf(stderr, "PRE validation failed: last_char=%d (%c), at_line_start=%d, delimiter=%c\n",
                scanner->last_char,
                (scanner->last_char >= 32 && scanner->last_char < 127) ? scanner->last_char : '?',
                scanner->at_line_start,
                delimiter);
        #endif
        return false;  // Invalid PRE character
    }

    // Consume delimiter
    lexer->advance(lexer, false);
    lexer->mark_end(lexer);  // Mark token boundary at delimiter

    // Validate POST boundary (peek ahead)
    bool at_line_end = at_line_boundary(lexer);

    // Check CONTENTS boundary (no leading whitespace for OPEN)
    if (is_whitespace(lexer->lookahead)) {
        // Leading whitespace - can't be OPEN, might be CLOSE
        if (can_close && is_post_char(lexer->lookahead, at_line_end)) {
            lexer->result_symbol = close_token;
            return true;
        }
        return false;  // Invalid delimiter
    }

    // EOF check
    if (lexer->eof(lexer)) {
        // At EOF - can't be OPEN, might be CLOSE
        if (can_close && is_post_char(lexer->lookahead, at_line_end)) {
            lexer->result_symbol = close_token;
            return true;
        }
        return false;
    }

    // Phase 2.2: Use lookahead to determine OPEN vs CLOSE
    if (can_open) {
        // Try to find matching closer using lookahead
        // This will validate the full emphasis construct
        if (find_closing_delimiter(ctx, delimiter)) {
            // Found valid matching closer - emit OPEN
            lexer->result_symbol = open_token;
            return true;
        }

        // No matching closer found
        // If can_close and has valid POST, emit CLOSE
        if (can_close && is_post_char(lexer->lookahead, at_line_end)) {
            lexer->result_symbol = close_token;
            return true;
        }

        // Neither OPEN (no closer) nor CLOSE (not valid) - delimiter is plain text
        return false;
    }

    // Only CLOSE is valid (OPEN not allowed in this context)
    if (can_close) {
        if (is_post_char(lexer->lookahead, at_line_end)) {
            lexer->result_symbol = close_token;
            return true;
        }
        return false;
    }

    return false;
}

/**
 * Main external scanner function
 *
 * Called by tree-sitter during parsing. Decides what to scan based on
 * what tokens the grammar marks as valid (valid_symbols array).
 *
 * Strategy:
 * 1. Check if TAGS token is valid -> scan for tags
 * 2. Check for emphasis tokens -> validate emphasis
 * 3. Return false if nothing to scan
 *
 * @param payload Scanner state (opaque pointer)
 * @param lexer Tree-sitter lexer
 * @param valid_symbols Array indicating which tokens grammar expects
 * @return true if token emitted, false otherwise
 */
bool tree_sitter_org_inline_external_scanner_scan(
    void *payload,
    TSLexer *lexer,
    const bool *valid_symbols
) {
    Scanner *scanner = (Scanner *)payload;

    // Skip leading newlines and update at_line_start tracking
    // This handles the case where content starts after a newline (like in test corpus)
    while (lexer->lookahead == '\n' && !lexer->eof(lexer)) {
        lexer->advance(lexer, true);  // true = skip (don't include in token)
    }

    // Update at_line_start tracking based on current lexer column position
    uint32_t col = lexer->get_column(lexer);
    scanner->at_line_start = (col == 0);

    // Update last_char at the start of each scan
    // This tracks the character at the current position (before we advance)
    // After we emit a token and advance, this becomes the "last character" for the next scan
    int32_t current_char = lexer->lookahead;

    // Create scanning context
    ScanContext ctx = {
        .scanner = scanner,
        .lexer = lexer,
        .valid_symbols = valid_symbols
    };

    // Debug output (uncomment when debugging):
    // fprintf(stderr, "DEBUG SCAN: at '%c' valid_symbols: PLAIN_TEXT=%d\n",
    //         current_char, valid_symbols[PLAIN_TEXT]);

    // Priority 0: Code and verbatim scanning (entire construct as single token)
    // Check for ~ (code) or = (verbatim) and emit full construct
    // The scan_code_or_verbatim function handles same-delimiter nesting correctly
    // by scanning the full content and finding the proper closing position.
    //
    // IMPORTANT: We check PRE boundary first. If PRE fails, skip to DELIMITER_CHAR
    // handling to avoid scan_code_or_verbatim corrupting lexer position.
    if (lexer->lookahead == '~' && valid_symbols[CODE]) {
        // Check PRE boundary before trying scan_code_or_verbatim
        if (is_pre_char(scanner->last_char, scanner->at_line_start)) {
            if (scan_code_or_verbatim(&ctx, '~', CODE)) {
                return true;
            }
            // CODE failed - if DELIMITER_CHAR is valid, emit it for just the marker
            // scan_code_or_verbatim has already called mark_end after the marker
            if (valid_symbols[DELIMITER_CHAR]) {
                lexer->result_symbol = DELIMITER_CHAR;
                scanner->last_char = '~';
                return true;
            }
            return false;
        }
        // PRE boundary failed - fall through to Priority 1 emphasis handling
        // which will emit DELIMITER_CHAR if valid
    }
    if (lexer->lookahead == '=' && valid_symbols[VERBATIM]) {
        if (is_pre_char(scanner->last_char, scanner->at_line_start)) {
            if (scan_code_or_verbatim(&ctx, '=', VERBATIM)) {
                return true;
            }
            // VERBATIM failed - emit DELIMITER_CHAR for just the marker
            if (valid_symbols[DELIMITER_CHAR]) {
                lexer->result_symbol = DELIMITER_CHAR;
                scanner->last_char = '=';
                return true;
            }
            return false;
        }
        // PRE boundary failed - fall through to Priority 1
    }

    // Priority 0.5: Line break scanning
    // Pattern: PRE \\ SPACE \n where PRE is not backslash
    // We check: lookahead is '\', last_char is not '\', then verify \\ + optional space + newline
    if (lexer->lookahead == '\\' && valid_symbols[LINE_BREAK]) {
        // PRE check: last_char must not be backslash
        // Also reject if last_char is unknown (0) - the unknown char might be backslash
        // Exception: at_line_start means no PRE needed (beginning of line is valid PRE)
        bool pre_valid = scanner->at_line_start ||
                         (scanner->last_char != 0 && scanner->last_char != '\\');
        if (pre_valid) {
            // Look for \\ followed by optional spaces and newline
            lexer->advance(lexer, false);  // Consume first backslash
            if (lexer->lookahead == '\\') {
                lexer->advance(lexer, false);  // Consume second backslash
                // Skip optional trailing spaces/tabs
                while (lexer->lookahead == ' ' || lexer->lookahead == '\t') {
                    lexer->advance(lexer, false);
                }
                // Must end with newline
                if (lexer->lookahead == '\n' || lexer->eof(lexer)) {
                    if (lexer->lookahead == '\n') {
                        lexer->advance(lexer, false);  // Consume newline
                    }
                    lexer->mark_end(lexer);
                    lexer->result_symbol = LINE_BREAK;
                    scanner->last_char = '\n';
                    scanner->at_line_start = true;
                    return true;
                }
            }
            // Not a valid line break - return false to let grammar try other rules
            // Note: We've advanced past the first backslash, which may cause issues.
            // Tree-sitter will reset lexer position on false return.
            return false;
        }
        // PRE is backslash - not a valid line break, fall through
    }

    // Priority 1: Emphasis scanning (MUST come before TAGS!)
    // Only try if we're at an emphasis marker character
    // Note: ~ and = are handled by code/verbatim above, but still check here for
    // cases where CODE/VERBATIM isn't valid (e.g., partial matches or closers)
    if (is_emphasis_marker(lexer->lookahead) &&
        (valid_symbols[BOLD_OPEN] || valid_symbols[BOLD_CLOSE] ||
         valid_symbols[ITALIC_OPEN] || valid_symbols[ITALIC_CLOSE] ||
         valid_symbols[UNDERLINE_OPEN] || valid_symbols[UNDERLINE_CLOSE] ||
         valid_symbols[CODE_OPEN] || valid_symbols[CODE_CLOSE] ||
         valid_symbols[VERBATIM_OPEN] || valid_symbols[VERBATIM_CLOSE] ||
         valid_symbols[STRIKE_OPEN] || valid_symbols[STRIKE_CLOSE] ||
         valid_symbols[DELIMITER_CHAR])) {

        // Special case: Inside code/verbatim, all emphasis markers except the closer are invalid
        // When CODE_CLOSE is valid, we're inside ~code~, so reject other emphasis markers
        // When VERBATIM_CLOSE is valid, we're inside =verbatim=, so reject other emphasis markers
        bool inside_code = valid_symbols[CODE_CLOSE];
        bool inside_verbatim = valid_symbols[VERBATIM_CLOSE];

        if (inside_code || inside_verbatim) {
            // Check if this is the expected closer
            bool is_code_closer = (inside_code && lexer->lookahead == '~');
            bool is_verbatim_closer = (inside_verbatim && lexer->lookahead == '=');

            if (!is_code_closer && !is_verbatim_closer) {
                // This is a different emphasis marker inside code/verbatim - treat as plain text
                lexer->advance(lexer, false);
                lexer->mark_end(lexer);
                lexer->result_symbol = DELIMITER_CHAR;
                scanner->last_char = 0;  // Reset to unknown
                return true;
            }
        }

        // Track position before scan_emphasis to detect if delimiter was consumed
        uint32_t col_before = lexer->get_column(lexer);

        bool result = scan_emphasis(&ctx);
        if (result) {
            // Successfully emitted a token
            // Reset last_char to 0 (unknown) because grammar will consume characters
            // between scanner invocations, making the delimiter position stale
            scanner->last_char = 0;
        } else if (valid_symbols[DELIMITER_CHAR]) {
            // scan_emphasis failed - emit DELIMITER_CHAR as fallback
            // This allows emphasis markers to appear as plain text when:
            // - Invalid opening position (PRE boundary fails)
            // - No valid closing delimiter found
            // - Invalid closing position (POST boundary fails)
            // - Inside code/verbatim content (marker not at valid closing position)
            // Check if scan_emphasis consumed the delimiter (position changed)
            uint32_t col_after = lexer->get_column(lexer);
            if (col_after > col_before) {
                // Delimiter was consumed by scan_emphasis, just emit
                lexer->result_symbol = DELIMITER_CHAR;
            } else {
                // Delimiter was NOT consumed - advance and emit
                lexer->advance(lexer, false);
                lexer->mark_end(lexer);
                lexer->result_symbol = DELIMITER_CHAR;
            }
            scanner->last_char = 0;  // Reset to unknown
            return true;
        }
        // DELIMITER_CHAR not valid - return false and let grammar handle it
        return result;
    }

    // Priority 2: Handle alphanumeric - could be plain_link, subscript/superscript, or plain_text
    // Need to check in correct order to avoid consuming characters needed by other rules
    {
        int32_t c = lexer->lookahead;
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {
            // Check for inline source block pattern: src_LANG{ or src_LANG[
            // Must check BEFORE consuming any characters
            if (c == 's' && is_at_inline_src_start(lexer)) {
                // Looks like inline source block - return false so grammar handles it
                // tree-sitter will reset lexer to original position
                return false;
            }

            // Check for inline babel call pattern: call_NAME(...)
            // Must check BEFORE consuming any characters
            if (c == 'c' && is_at_inline_babel_call_start(lexer)) {
                // Looks like inline babel call - return false so grammar handles it
                // tree-sitter will reset lexer to original position
                return false;
            }

            // First, check if this single char + next char forms subscript/superscript
            // Peek at next character WITHOUT consuming
            // Actually, we need to consume to peek. Let's use a different approach:
            // - Advance one char
            // - Check if next is _ or ^ with valid script
            // - If yes, don't emit - return false so grammar's subscript/superscript matches
            // - If no, check for plain_link pattern
            // - If plain_link, scan it
            // - Otherwise emit as plain_text

            lexer->advance(lexer, false);  // Consume first letter
            int32_t next = lexer->lookahead;

            // Check for subscript (char_) or superscript (char^)
            if (next == '_' || next == '^') {
                // Might be subscript/superscript - check if valid pattern follows
                lexer->advance(lexer, false);  // Consume _ or ^

                // Check if we're in an emphasis context where subscript/superscript aren't valid
                // If any emphasis closer is valid, we're inside emphasis
                bool in_emphasis = valid_symbols[BOLD_CLOSE] || valid_symbols[ITALIC_CLOSE] ||
                                   valid_symbols[UNDERLINE_CLOSE] || valid_symbols[STRIKE_CLOSE] ||
                                   valid_symbols[CODE_CLOSE] || valid_symbols[VERBATIM_CLOSE];

                if (is_valid_script_pattern(lexer)) {
                    if (!in_emphasis) {
                        // Valid subscript/superscript and NOT in emphasis context
                        // Return false so grammar's token() rule can match from original position.
                        // tree-sitter will reset lexer to original position when we return false.
                        return false;
                    }
                    // In emphasis context - subscript/superscript not allowed
                    // Emit what we have as plain_text (including the alnum + _/^)
                    // Actually, we should only emit up to the alnum, not the _/^
                    // The _/^ might be an emphasis closer (for underline)
                    // But we already consumed it... Let's mark before the _/^
                    // That's not possible now. Let's just emit everything consumed
                    // and let the next scan handle what follows.
                }
                // Not a valid script OR in emphasis context
                // Emit what we have so far
                if (valid_symbols[PLAIN_TEXT]) {
                    lexer->mark_end(lexer);
                    lexer->result_symbol = PLAIN_TEXT;
                    scanner->last_char = next;  // Track the _/^ we consumed
                    return true;
                }
            }

            // Not subscript/superscript - check for plain_link
            // We've consumed one letter, check if rest looks like protocol://
            // Track last consumed char for PRE validation
            int32_t prev_char = c;  // c was first alphanumeric consumed

            if (valid_symbols[PLAIN_LINK]) {
                // Continue checking for protocol pattern
                // Need letters followed by ://
                // NOTE: Don't consume emphasis markers as protocol chars - they could be closers!
                while (true) {
                    c = lexer->lookahead;
                    // Check for emphasis markers that could be closers
                    if (c == '+' || c == '~' || c == '=' || c == '*' || c == '/' || c == '_') {
                        // Could be emphasis closer, stop consuming
                        break;
                    }
                    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') ||
                        (c >= '0' && c <= '9') || c == '.' || c == '-') {
                        prev_char = c;  // Track before advancing
                        lexer->advance(lexer, false);
                    } else {
                        break;
                    }
                }

                // Check for :// or mailto:
                if (lexer->lookahead == ':') {
                    prev_char = ':';
                    lexer->advance(lexer, false);
                    if (lexer->lookahead == '/') {
                        prev_char = '/';
                        lexer->advance(lexer, false);
                        if (lexer->lookahead == '/') {
                            prev_char = '/';
                            lexer->advance(lexer, false);
                            // It's a plain link! Consume the path
                            while (is_plain_link_path_char(lexer->lookahead) && !lexer->eof(lexer)) {
                                prev_char = lexer->lookahead;
                                lexer->advance(lexer, false);
                            }
                            lexer->mark_end(lexer);
                            lexer->result_symbol = PLAIN_LINK;
                            scanner->last_char = prev_char;  // Track last char of URL
                            return true;
                        }
                    } else {
                        // Not ://, check for mailto: pattern
                        // After consuming protocol letters and ':', if next looks like an email, it's mailto
                        // Email format: local@domain (simplified check)
                        int32_t email_char = lexer->lookahead;
                        if ((email_char >= 'a' && email_char <= 'z') ||
                            (email_char >= 'A' && email_char <= 'Z') ||
                            (email_char >= '0' && email_char <= '9')) {
                            // Could be mailto: - consume email-like content until whitespace
                            while (is_plain_link_path_char(lexer->lookahead) && !lexer->eof(lexer)) {
                                prev_char = lexer->lookahead;
                                lexer->advance(lexer, false);
                            }
                            // Emit as plain_link (mailto:address)
                            lexer->mark_end(lexer);
                            lexer->result_symbol = PLAIN_LINK;
                            scanner->last_char = prev_char;
                            return true;
                        }
                    }
                }
            }

            // Not a plain_link either - emit what we consumed as PLAIN_TEXT
            if (valid_symbols[PLAIN_TEXT]) {
                lexer->mark_end(lexer);
                lexer->result_symbol = PLAIN_TEXT;
                scanner->last_char = prev_char;  // Track last consumed char
                return true;
            }
        }
    }

    // Priority 3: Tag scanning (only if at colon)
    // Note: We only call scan_tags when at ':' directly.
    bool started_at_colon = (lexer->lookahead == ':');

    if (valid_symbols[TAGS] && started_at_colon) {
        bool result = scan_tags(&ctx);
        if (result) {
            scanner->last_char = current_char;
            return true;
        }
        // TAGS failed at colon - emit PLAIN_COLON
        if (valid_symbols[PLAIN_COLON]) {
            lexer->advance(lexer, false);
            lexer->mark_end(lexer);
            lexer->result_symbol = PLAIN_COLON;
            scanner->last_char = ':';
            return true;
        }
    }

    // Priority 4: Plain colon (colon not part of valid tags)
    // This handles colons when TAGS wasn't even valid
    if (valid_symbols[PLAIN_COLON] && lexer->lookahead == ':') {
        lexer->advance(lexer, false);
        lexer->mark_end(lexer);
        lexer->result_symbol = PLAIN_COLON;
        scanner->last_char = ':';
        return true;
    }

    // Priority 5: Handle { - could be macro {{{ or standalone brace
    // If it's {{{, let grammar match macro. Otherwise emit as plain text.
    if (lexer->lookahead == '{') {
        lexer->advance(lexer, false);
        if (lexer->lookahead == '{') {
            lexer->advance(lexer, false);
            if (lexer->lookahead == '{') {
                // It's {{{ - macro start. Return false to let grammar handle.
                return false;
            }
            // Just {{, not a macro. Emit both braces as plain text.
            if (valid_symbols[PLAIN_TEXT]) {
                lexer->mark_end(lexer);
                lexer->result_symbol = PLAIN_TEXT;
                scanner->last_char = '{';
                return true;
            }
        }
        // Single { - emit as plain text
        if (valid_symbols[PLAIN_TEXT]) {
            lexer->mark_end(lexer);
            lexer->result_symbol = PLAIN_TEXT;
            scanner->last_char = '{';
            return true;
        }
    }

    // Priority 6: Plain text with subscript/superscript boundary detection
    // Stops before alphanumeric + _ or ^ patterns to let sub/superscript match
    if (valid_symbols[PLAIN_TEXT]) {
        bool result = scan_plain_text(&ctx);
        if (result) {
            // scan_plain_text sets scanner->last_char directly
            return true;
        }
    }

    return false;
}

// ============================================================================
// SCANNER LIFECYCLE FUNCTIONS
// ============================================================================

/**
 * Create scanner
 *
 * Allocates and initializes scanner state.
 *
 * @return Pointer to new scanner, or NULL on allocation failure
 */
void *tree_sitter_org_inline_external_scanner_create() {
    Scanner *scanner = calloc(1, sizeof(Scanner));
    if (scanner) {
        scanner->last_char = 0;
        scanner->at_line_start = true;
        scanner->state_flags = 0;
    }
    return scanner;
}

/**
 * Destroy scanner
 *
 * Frees scanner state memory.
 *
 * @param payload Scanner state (opaque pointer)
 */
void tree_sitter_org_inline_external_scanner_destroy(void *payload) {
    if (payload != NULL) {
        free(payload);
    }
}

/**
 * Serialize scanner state
 *
 * Saves scanner state to buffer for incremental parsing.
 *
 * @param payload Scanner state (opaque pointer)
 * @param buffer Output buffer
 * @return Number of bytes written
 */
unsigned tree_sitter_org_inline_external_scanner_serialize(void *payload, char *buffer) {
    Scanner *scanner = (Scanner *)payload;

    if (scanner == NULL || buffer == NULL) {
        return 0;
    }

    return serialize(scanner, buffer);
}

/**
 * Deserialize scanner state
 *
 * Restores scanner state from buffer for incremental parsing.
 *
 * @param payload Scanner state (opaque pointer)
 * @param buffer Input buffer
 * @param length Buffer length
 */
void tree_sitter_org_inline_external_scanner_deserialize(
    void *payload,
    const char *buffer,
    unsigned length
) {
    Scanner *scanner = (Scanner *)payload;

    if (scanner == NULL) {
        return;
    }

    deserialize(scanner, buffer, length);
}
