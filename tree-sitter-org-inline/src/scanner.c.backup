/**
 * @file External scanner for Org-mode inline grammar (tree-sitter-org-inline)
 * @author Tree-sitter Org-mode Contributors
 * @license MIT
 *
 * This scanner validates tags at the end of headlines.
 * The grammar handles parsing title content (markup and plain text).
 *
 * Strategy:
 * - Scanner only emits TAGS token when at ':' character
 * - Validates tag format: :tag1:tag2:tag3:
 * - Grammar parses title content using built-in rules (bold, italic, etc.)
 * - No state needed - stateless validation
 */

#include <tree_sitter/parser.h>
#include <wctype.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>

// Token types (must match order in grammar.js externals array)
enum TokenType {
    TAGS,        // Tags portion (:tag1:tag2:)
    SUBSCRIPT,   // Subscript pattern (BASE_SCRIPT)
    SUPERSCRIPT, // Superscript pattern (BASE^SCRIPT)
    WORD,        // Alphanumeric word NOT followed by _/^
};

// Scanner state
typedef struct {
    // No state needed for simple tag detection
    int unused;  // Placeholder to avoid empty struct
} Scanner;

// Forward declarations
static bool scan_tags(Scanner *scanner, TSLexer *lexer);
static bool scan_subscript(Scanner *scanner, TSLexer *lexer);
static bool scan_superscript(Scanner *scanner, TSLexer *lexer);
static bool scan_word(Scanner *scanner, TSLexer *lexer);
static bool is_valid_tag_char(int32_t c);
static bool is_alnum(int32_t c);
static bool looks_like_underline(TSLexer *lexer);
static bool scan_script(TSLexer *lexer);
static bool scan_balanced(TSLexer *lexer, int32_t open, int32_t close);

/**
 * Create scanner
 */
void *tree_sitter_org_inline_external_scanner_create() {
    Scanner *scanner = (Scanner *)calloc(1, sizeof(Scanner));
    return scanner;
}

/**
 * Destroy scanner
 */
void tree_sitter_org_inline_external_scanner_destroy(void *payload) {
    free(payload);
}

/**
 * Serialize scanner state (no state needed)
 */
unsigned tree_sitter_org_inline_external_scanner_serialize(void *payload, char *buffer) {
    return 0;  // No state to serialize
}

/**
 * Deserialize scanner state (no state needed)
 */
void tree_sitter_org_inline_external_scanner_deserialize(void *payload, const char *buffer, unsigned length) {
    // No state to deserialize
}

/**
 * Main scanning function
 *
 * Emits TAGS, SUBSCRIPT, SUPERSCRIPT, or WORD tokens based on what grammar expects.
 * Order matters: try subscript/superscript before WORD (they're more specific).
 */
bool tree_sitter_org_inline_external_scanner_scan(void *payload, TSLexer *lexer, const bool *valid_symbols) {
    Scanner *scanner = (Scanner *)payload;

    // Try subscript first (highest priority for alphanumeric sequences)
    if (valid_symbols[SUBSCRIPT]) {
        if (scan_subscript(scanner, lexer)) {
            return true;
        }
    }

    // Try superscript (highest priority for alphanumeric sequences)
    if (valid_symbols[SUPERSCRIPT]) {
        if (scan_superscript(scanner, lexer)) {
            return true;
        }
    }

    // Try word (fallback for alphanumeric not followed by _/^)
    if (valid_symbols[WORD]) {
        if (scan_word(scanner, lexer)) {
            return true;
        }
    }

    // Try tags last
    if (valid_symbols[TAGS]) {
        return scan_tags(scanner, lexer);
    }

    return false;
}

/**
 * Scan tags - validates and consumes tags from current position
 *
 * Can be called when lexer is at a space before tags, or at ':' for tags at start.
 * Format: SPACE:tag1:tag2:...:tagN: where tags contain only alphanumeric, _, @, #, %
 * Space is required unless tags are at the start of content.
 * Must end at EOL or EOF.
 */
static bool scan_tags(Scanner *scanner, TSLexer *lexer) {
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

    while (lexer->lookahead != '\n' && lexer->lookahead != 0) {
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
 */
static bool is_valid_tag_char(int32_t c) {
    return (c >= 'a' && c <= 'z') ||
           (c >= 'A' && c <= 'Z') ||
           (c >= '0' && c <= '9') ||
           c == '_' || c == '@' || c == '#' || c == '%';
}

/**
 * Check if character is alphanumeric (letter or digit)
 */
static bool is_alnum(int32_t c) {
    return (c >= 'a' && c <= 'z') ||
           (c >= 'A' && c <= 'Z') ||
           (c >= '0' && c <= '9');
}

/**
 * Check if pattern looks like underline markup rather than subscript
 *
 * Heuristic rules (since we can't look ahead without consuming):
 * - Lowercase letter after _ suggests underline: _text_
 * - Numbers/braces after _ suggest subscript: _2, _{...}
 * - Asterisk after _ suggests subscript: _*
 * - Uppercase letters are ambiguous, treat as potential underline
 */
static bool looks_like_underline(TSLexer *lexer) {
    int32_t next = lexer->lookahead;

    // Common subscript patterns (NOT underline)
    if ((next >= '0' && next <= '9') ||  // _2, _123
        next == '{' || next == '(' ||     // _{...}, _(...)
        next == '*' ||                     // _*
        next == '+' || next == '-') {     // _+1, _-2
        return false;  // Definitely subscript
    }

    // Lowercase letters suggest underline
    if (next >= 'a' && next <= 'z') {
        return true;  // Likely underline: _text_
    }

    // Uppercase is ambiguous - could be subscript (A_N) or underline (_NOTE_)
    // Org-mode convention: most subscripts use lowercase
    // Be conservative: treat as potential underline
    if (next >= 'A' && next <= 'Z') {
        return true;  // Potentially underline
    }

    // Other characters (punctuation, etc.) - not typical underline
    return false;
}

/**
 * Scan and validate subscript pattern: BASE_SCRIPT
 *
 * Returns true if valid subscript found and consumed, false otherwise.
 * When returning false, lexer position is automatically reset by tree-sitter.
 */
static bool scan_subscript(Scanner *scanner, TSLexer *lexer) {
    // 1. Must start with alphanumeric (BASE)
    if (!is_alnum(lexer->lookahead)) {
        return false;
    }

    // 2. Consume BASE (one or more alphanumeric characters)
    while (is_alnum(lexer->lookahead)) {
        lexer->advance(lexer, false);
    }

    // 3. Must have underscore marker
    if (lexer->lookahead != '_') {
        return false;
    }
    lexer->advance(lexer, false);  // Consume '_'

    // 4. Check for "underline takes priority" case
    if (looks_like_underline(lexer)) {
        return false;  // Let text_markup (underline) match instead
    }

    // 5. Validate and consume SCRIPT
    if (!scan_script(lexer)) {
        return false;  // Invalid script pattern
    }

    // 6. Success - emit SUBSCRIPT token
    lexer->mark_end(lexer);
    lexer->result_symbol = SUBSCRIPT;
    return true;
}

/**
 * Scan and validate superscript pattern: BASE^SCRIPT
 *
 * Returns true if valid superscript found and consumed, false otherwise.
 */
static bool scan_superscript(Scanner *scanner, TSLexer *lexer) {
    // 1. Must start with alphanumeric (BASE)
    if (!is_alnum(lexer->lookahead)) {
        return false;
    }

    // 2. Consume BASE (one or more alphanumeric characters)
    while (is_alnum(lexer->lookahead)) {
        lexer->advance(lexer, false);
    }

    // 3. Must have caret marker
    if (lexer->lookahead != '^') {
        return false;
    }
    lexer->advance(lexer, false);  // Consume '^'

    // 4. Validate and consume SCRIPT
    if (!scan_script(lexer)) {
        return false;  // Invalid script pattern
    }

    // 5. Success - emit SUPERSCRIPT token
    lexer->mark_end(lexer);
    lexer->result_symbol = SUPERSCRIPT;
    return true;
}

/**
 * Scan and validate SCRIPT portion of subscript/superscript
 *
 * Valid SCRIPT formats per org-mode spec:
 * 1. Single asterisk: *
 * 2. Braced expression: {...} with balanced braces
 * 3. Parenthesized expression: (...) with balanced parens
 * 4. SIGN CHARS FINAL: [+-]?[a-zA-Z0-9,.\\]*[a-zA-Z0-9]
 *
 * Returns true if valid script consumed, false otherwise.
 */
static bool scan_script(TSLexer *lexer) {
    int32_t first = lexer->lookahead;

    // Empty script is invalid
    if (first == '\n' || first == 0 || iswspace(first)) {
        return false;
    }

    // Case 1: Single asterisk
    if (first == '*') {
        lexer->advance(lexer, false);
        // Asterisk must be followed by space/EOL/EOF (not more content)
        if (iswspace(lexer->lookahead) || lexer->lookahead == '\n' ||
            lexer->lookahead == 0) {
            return true;
        }
        // Asterisk followed by more content - continue as SIGN CHARS FINAL
        // Fall through to Case 4
    }

    // Case 2: Braced expression {...}
    else if (first == '{') {
        return scan_balanced(lexer, '{', '}');
    }

    // Case 3: Parenthesized expression (...)
    else if (first == '(') {
        return scan_balanced(lexer, '(', ')');
    }

    // Case 4: SIGN CHARS FINAL pattern
    // Optional sign (if not asterisk from Case 1)
    if (first != '*' && (first == '+' || first == '-')) {
        lexer->advance(lexer, false);
        first = lexer->lookahead;
    }

    // Must have at least one character
    if (first == '\n' || first == 0 || iswspace(first)) {
        return false;
    }

    // Consume CHARS: alphanumeric, comma, backslash, dot
    // Track last character to verify FINAL requirement
    int32_t last_char = 0;
    int char_count = 0;

    while (is_alnum(lexer->lookahead) ||
           lexer->lookahead == ',' ||
           lexer->lookahead == '\\' ||
           lexer->lookahead == '.') {
        last_char = lexer->lookahead;
        lexer->advance(lexer, false);
        char_count++;
    }

    // Must have consumed at least one character
    if (char_count == 0) {
        return false;
    }

    // Must end with alphanumeric (FINAL requirement)
    // Check last consumed character
    if (!is_alnum(last_char)) {
        return false;
    }

    // Valid script!
    return true;
}

/**
 * Scan balanced expression with open/close delimiters
 *
 * Examples: {...}, (...)
 * Supports nesting: {a{b}c}, (x(y)z)
 *
 * Returns true if balanced expression consumed, false otherwise.
 */
static bool scan_balanced(TSLexer *lexer, int32_t open, int32_t close) {
    int depth = 1;
    lexer->advance(lexer, false);  // Consume opening delimiter

    while (depth > 0 && lexer->lookahead != '\n' && lexer->lookahead != 0) {
        if (lexer->lookahead == open) {
            depth++;
        } else if (lexer->lookahead == close) {
            depth--;
        }
        lexer->advance(lexer, false);
    }

    // Successfully balanced if depth returned to 0
    return depth == 0;
}

/**
 * Scan alphanumeric word NOT followed by _ or ^
 *
 * This ensures subscript/superscript patterns are recognized instead of being
 * consumed as separate words. For example:
 * - "H_2O" → SUBSCRIPT (not WORD + underscore + WORD)
 * - "Water" → WORD (no _ or ^ following)
 *
 * Returns true if word consumed, false otherwise.
 */
static bool scan_word(Scanner *scanner, TSLexer *lexer) {
    // Must start with alphanumeric
    if (!is_alnum(lexer->lookahead)) {
        return false;
    }

    // Consume all alphanumeric characters
    while (is_alnum(lexer->lookahead)) {
        lexer->advance(lexer, false);
    }

    // Check what follows the alphanumeric sequence
    int32_t next = lexer->lookahead;

    // If followed by _ or ^, this should be subscript/superscript, not a word
    if (next == '_' || next == '^') {
        return false;  // Let subscript/superscript scanners handle it
    }

    // Valid word - emit WORD token
    lexer->mark_end(lexer);
    lexer->result_symbol = WORD;
    return true;
}
