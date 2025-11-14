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
 * - State management: Delimiter stack for nesting prevention
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
 * Serialization format version
 */
#define SERIALIZATION_VERSION 0x01

/**
 * Serialization buffer size (fixed)
 *
 * Layout:
 * [0]: Version (0x01)
 * [1]: Stack depth (0-MAX_EMPHASIS_DEPTH)
 * [2]: State flags
 * [3]: Padding
 * [4-19]: Delimiter stack (16 bytes)
 */
#define SERIALIZATION_SIZE 20

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

// State management
static bool is_delimiter_on_stack(Scanner *scanner, char delimiter);
static bool push_delimiter(Scanner *scanner, char delimiter);
static bool pop_delimiter(Scanner *scanner, char delimiter);
static void clear_delimiter_stack(Scanner *scanner);

// Boundary validation
static bool validate_opening_boundary(ScanContext *ctx, char marker, int32_t prev_char, bool at_line_start);
static bool validate_closing_boundary(ScanContext *ctx, char marker, int32_t prev_char);

// Lookahead scanning
static bool find_closing_delimiter(ScanContext *ctx, char marker);
static bool is_valid_emphasis(ScanContext *ctx, char marker, int32_t prev_char, bool at_line_start);

// Serialization
static unsigned serialize(Scanner *scanner, char *buffer);
static void deserialize(Scanner *scanner, const char *buffer, unsigned length);

// Tag scanning (preserve existing functionality)
static bool scan_tags(ScanContext *ctx);
static bool is_valid_tag_char(int32_t c);

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

/**
 * Check if delimiter is on the stack
 *
 * Used to prevent same-delimiter nesting (e.g., *bold *nested* bold* is invalid).
 *
 * @param scanner Scanner state
 * @param delimiter Delimiter to check
 * @return true if delimiter is currently open
 */
static bool is_delimiter_on_stack(Scanner *scanner, char delimiter) {
    // Validate inputs
    if (scanner == NULL) {
        return false;
    }

    // Linear search (stack is small, typically 1-3 elements, max 16)
    for (uint8_t i = 0; i < scanner->stack_depth; i++) {
        if (scanner->delimiter_stack[i] == delimiter) {
            return true;
        }
    }

    return false;
}

/**
 * Push delimiter onto stack
 *
 * @param scanner Scanner state
 * @param delimiter Delimiter to push
 * @return true if successful, false if stack full or invalid delimiter
 */
static bool push_delimiter(Scanner *scanner, char delimiter) {
    // Validate inputs
    if (scanner == NULL) {
        return false;
    }

    if (!is_emphasis_marker(delimiter)) {
        return false;  // Invalid delimiter
    }

    // Check for stack overflow
    if (scanner->stack_depth >= MAX_EMPHASIS_DEPTH) {
        return false;  // Stack full
    }

    // Push delimiter
    scanner->delimiter_stack[scanner->stack_depth] = delimiter;
    scanner->stack_depth++;

    // Verify postcondition (debug builds)
    assert(scanner->stack_depth <= MAX_EMPHASIS_DEPTH);

    return true;
}

/**
 * Pop delimiter from stack
 *
 * @param scanner Scanner state
 * @param delimiter Expected delimiter (for validation)
 * @return true if successful and matches, false otherwise
 */
static bool pop_delimiter(Scanner *scanner, char delimiter) {
    // Validate inputs
    if (scanner == NULL) {
        return false;
    }

    // Check for stack underflow
    if (scanner->stack_depth == 0) {
        return false;  // Stack empty
    }

    // Verify that top of stack matches expected delimiter
    uint8_t top_idx = scanner->stack_depth - 1;
    if (scanner->delimiter_stack[top_idx] != delimiter) {
        return false;  // Mismatch (shouldn't happen with correct grammar)
    }

    // Pop delimiter
    scanner->stack_depth--;

    // Clear the popped slot (defensive programming)
    scanner->delimiter_stack[scanner->stack_depth] = 0;

    return true;
}

/**
 * Clear delimiter stack
 *
 * Used during initialization and error recovery.
 *
 * @param scanner Scanner state
 */
static void clear_delimiter_stack(Scanner *scanner) {
    if (scanner == NULL) {
        return;
    }

    scanner->stack_depth = 0;
    memset(scanner->delimiter_stack, 0, MAX_EMPHASIS_DEPTH);
}

// ============================================================================
// BOUNDARY VALIDATION FUNCTIONS
// ============================================================================

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
 * Scans forward to find a matching marker with valid closing boundary.
 * Stops at line end (org emphasis cannot span lines).
 *
 * Precondition: lexer positioned AFTER opening marker
 * Postcondition: if successful, lexer at closing marker; else, position undefined
 *
 * @param ctx Scanning context
 * @param marker Delimiter to find
 * @return true if valid closing delimiter found
 */
static bool find_closing_delimiter(ScanContext *ctx, char marker) {
    if (ctx == NULL || ctx->lexer == NULL) {
        return false;
    }

    TSLexer *lexer = ctx->lexer;
    int32_t prev_char = 0;

    // Track previous character for boundary validation
    // Start with whatever came after opening marker
    if (!lexer->eof(lexer)) {
        prev_char = lexer->lookahead;
    }

    // Scan forward looking for closing marker
    while (!lexer->eof(lexer)) {
        int32_t current = lexer->lookahead;

        // Stop at line end (emphasis cannot span lines)
        // Source: org-syntax.md - emphasis is line-scoped
        if (current == '\n' || current == '\r') {
            return false;  // No valid closing found before line end
        }

        // Found potential closing marker
        if (current == marker) {
            // Save current position to restore if validation fails
            uint32_t saved_column = lexer->get_column(lexer);

            // Validate closing boundary
            if (validate_closing_boundary(ctx, marker, prev_char)) {
                // Valid closing found!
                // Note: lexer is now positioned AFTER the closing marker
                // due to validate_closing_boundary advancing
                return true;
            }

            // Invalid closing boundary, restore position and keep looking
            // Note: We can't actually restore position in tree-sitter,
            // so we just continue from where validate_closing_boundary left us
            // This is okay because we're in a lookahead context
        }

        // Track previous character for next iteration
        prev_char = current;

        // Advance to next character
        lexer->advance(lexer, false);
    }

    // Reached EOF without finding valid closing
    return false;
}

/**
 * Check if emphasis is valid (complete validation)
 *
 * This function validates that:
 * 1. Opening boundary is valid
 * 2. Delimiter is not already on stack (no same-marker nesting)
 * 3. Closing delimiter exists with valid boundary
 *
 * This is a "pure" validation function - it doesn't modify scanner state.
 * It just answers: "Is this valid emphasis?"
 *
 * Note: This function advances the lexer during lookahead. The caller should
 * save/restore lexer position if needed.
 *
 * @param ctx Scanning context
 * @param marker The potential emphasis marker
 * @param prev_char Character before marker
 * @param at_line_start true if at beginning of line
 * @return true if valid emphasis pattern
 */
static bool is_valid_emphasis(
    ScanContext *ctx,
    char marker,
    int32_t prev_char,
    bool at_line_start
) {
    if (ctx == NULL) {
        return false;
    }

    // Check 1: Valid opening boundary
    // Note: This advances lexer past the marker
    if (!validate_opening_boundary(ctx, marker, prev_char, at_line_start)) {
        return false;
    }

    // Check 2: Delimiter not already on stack (no same-marker nesting)
    if (is_delimiter_on_stack(ctx->scanner, marker)) {
        return false;
    }

    // Check 3: Valid closing delimiter exists
    // Note: This advances lexer to the closing marker (or EOF/newline)
    bool has_closing = find_closing_delimiter(ctx, marker);

    return has_closing;
}

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

    // Check if we're at a space (preceding tags) or ':' (tags at start)
    bool has_preceding_space = false;

    if (lexer->lookahead == ' ') {
        // Consume the space before tags
        has_preceding_space = true;
        lexer->advance(lexer, false);
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
// MAIN SCAN FUNCTION
// ============================================================================

/**
 * Scan emphasis delimiter with state tracking
 *
 * Uses scanner state to make consistent open/close decisions and prevent
 * invalid nesting (e.g., *bold *inside* bold* is invalid).
 *
 * Strategy:
 * 1. Check if delimiter is currently open (on stack)
 * 2. If open: try CLOSE (with validation)
 * 3. If not open: try OPEN (with validation)
 * 4. Update stack on success
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

    fprintf(stderr, "DEBUG: scan_emphasis delimiter='%c', stack_depth=%d\n",
            delimiter, scanner->stack_depth);

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

    // Check if this delimiter is currently open
    bool is_open = is_delimiter_on_stack(scanner, delimiter);

    fprintf(stderr, "DEBUG: is_open=%d, valid_open=%d, valid_close=%d\n",
            is_open, valid_symbols[open_token], valid_symbols[close_token]);

    // CASE 1: Delimiter is OPEN → Try to CLOSE it
    if (is_open && valid_symbols[close_token]) {
        fprintf(stderr, "DEBUG: Trying CLOSE (delimiter on stack)\n");

        // Consume delimiter
        lexer->advance(lexer, false);
        lexer->mark_end(lexer);

        // POST validation: character after must be valid POST
        bool at_line_end = at_line_boundary(lexer);
        if (!is_post_char(lexer->lookahead, at_line_end)) {
            fprintf(stderr, "DEBUG: Invalid POST char '%c' - emitting DELIMITER_CHAR\n", (char)lexer->lookahead);
            // Invalid emphasis - emit closing delimiter as plain character
            lexer->result_symbol = DELIMITER_CHAR;
            return true;
        }

        // Pop delimiter from stack
        if (!pop_delimiter(scanner, delimiter)) {
            fprintf(stderr, "DEBUG: Failed to pop delimiter (shouldn't happen)\n");
            return false;
        }

        fprintf(stderr, "DEBUG: Emitting CLOSE, new_depth=%d\n", scanner->stack_depth);
        lexer->result_symbol = close_token;
        return true;
    }

    // CASE 2: Delimiter is NOT OPEN → Try to OPEN it
    if (!is_open && valid_symbols[open_token]) {
        fprintf(stderr, "DEBUG: Trying OPEN (delimiter not on stack)\n");

        // NOTE: Simplified PRE validation - we don't validate what came before
        // The grammar's context (what's valid_symbols[OPEN] is true) handles most cases
        // In the future, we could add stricter PRE validation if needed

        // Consume delimiter
        lexer->advance(lexer, false);
        lexer->mark_end(lexer);

        // CONTENTS validation: no whitespace after OPEN
        if (is_whitespace(lexer->lookahead)) {
            fprintf(stderr, "DEBUG: Whitespace after OPEN - emitting DELIMITER_CHAR\n");
            // Invalid emphasis - emit as plain delimiter character
            lexer->result_symbol = DELIMITER_CHAR;
            return true;
        }

        // Cannot be at EOF
        if (lexer->eof(lexer)) {
            fprintf(stderr, "DEBUG: EOF after OPEN - emitting DELIMITER_CHAR\n");
            // Invalid emphasis - emit as plain delimiter character
            lexer->result_symbol = DELIMITER_CHAR;
            return true;
        }

        // For recursive emphasis (bold, italic, underline, strike): check for empty content
        // Empty content = immediate closing delimiter (e.g., ** or // or __ or ++)
        if (delimiter == '*' || delimiter == '/' || delimiter == '_' || delimiter == '+') {
            if (lexer->lookahead == delimiter) {
                fprintf(stderr, "DEBUG: Empty content (immediate closing delimiter) - emitting DELIMITER_CHAR\n");
                // Invalid emphasis - emit as plain delimiter character
                lexer->result_symbol = DELIMITER_CHAR;
                return true;
            }
        }

        // For code/verbatim (opaque, non-nesting): validate entire content before emitting OPEN
        // Check for trailing whitespace and empty content
        if (delimiter == '~' || delimiter == '=') {
            fprintf(stderr, "DEBUG: Validating code/verbatim content\n");

            // Look ahead to find closing delimiter
            int content_len = 0;
            char last_char = '\0';
            bool found_close = false;

            // Save current position
            TSLexer *lex = lexer;

            // Scan content
            while (!lex->eof(lex) && lex->lookahead != '\n') {
                if (lex->lookahead == delimiter) {
                    // Found potential closing delimiter
                    found_close = true;
                    break;
                }

                last_char = (char)lex->lookahead;
                content_len++;
                lex->advance(lex, false);
            }

            // Validation checks
            if (!found_close) {
                fprintf(stderr, "DEBUG: No closing delimiter found - emitting DELIMITER_CHAR\n");
                lexer->result_symbol = DELIMITER_CHAR;
                return true;
            }

            if (content_len == 0) {
                fprintf(stderr, "DEBUG: Empty content - emitting DELIMITER_CHAR\n");
                lexer->result_symbol = DELIMITER_CHAR;
                return true;
            }

            // Check if last character before close is whitespace (trailing whitespace)
            if (is_whitespace(last_char)) {
                fprintf(stderr, "DEBUG: Trailing whitespace before close - emitting DELIMITER_CHAR\n");
                lexer->result_symbol = DELIMITER_CHAR;
                return true;
            }

            fprintf(stderr, "DEBUG: Code/verbatim content valid\n");
        }

        // Push delimiter to stack
        if (!push_delimiter(scanner, delimiter)) {
            fprintf(stderr, "DEBUG: Failed to push delimiter (stack full?)\n");
            return false;
        }

        fprintf(stderr, "DEBUG: Emitting OPEN, new_depth=%d\n", scanner->stack_depth);
        lexer->result_symbol = open_token;
        return true;
    }

    // CASE 3: Can't make valid decision - return false and let parser decide
    // DELIMITER_CHAR should ONLY be emitted when we've proven emphasis is invalid
    // (e.g., whitespace after OPEN, invalid POST char)
    // If we can't decide, return false and let the parser explore other paths
    fprintf(stderr, "DEBUG: No valid decision (is_open=%d, open_valid=%d, close_valid=%d) - returning false\n",
            is_open, valid_symbols[open_token], valid_symbols[close_token]);

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

    fprintf(stderr, "MAIN_SCAN: lookahead='%c' (0x%02x), TAGS=%d, BOLD_OPEN=%d\n",
            (lexer->lookahead >= 32 && lexer->lookahead < 127) ? lexer->lookahead : '?',
            lexer->lookahead,
            valid_symbols[TAGS],
            valid_symbols[BOLD_OPEN]);

    // Create scanning context
    ScanContext ctx = {
        .scanner = scanner,
        .lexer = lexer,
        .valid_symbols = valid_symbols
    };

    // Priority 1: Emphasis scanning (MUST come before TAGS!)
    // Only try if we're at an emphasis marker character
    if (is_emphasis_marker(lexer->lookahead) &&
        (valid_symbols[BOLD_OPEN] || valid_symbols[BOLD_CLOSE] ||
         valid_symbols[ITALIC_OPEN] || valid_symbols[ITALIC_CLOSE] ||
         valid_symbols[UNDERLINE_OPEN] || valid_symbols[UNDERLINE_CLOSE] ||
         valid_symbols[CODE_OPEN] || valid_symbols[CODE_CLOSE] ||
         valid_symbols[VERBATIM_OPEN] || valid_symbols[VERBATIM_CLOSE] ||
         valid_symbols[STRIKE_OPEN] || valid_symbols[STRIKE_CLOSE])) {
        fprintf(stderr, "MAIN_SCAN: Calling scan_emphasis\n");
        return scan_emphasis(&ctx);
    }

    // Priority 2: Tag scanning (only if not emphasis)
    if (valid_symbols[TAGS]) {
        return scan_tags(&ctx);
    }

    fprintf(stderr, "MAIN_SCAN: Returning false (no valid tokens)\n");
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
