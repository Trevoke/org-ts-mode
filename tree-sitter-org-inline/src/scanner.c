/**
 * @file External scanner for Org-mode inline grammar (tree-sitter-org-inline)
 * @author Tree-sitter Org-mode Contributors
 * @license MIT
 *
 * This scanner handles inline objects requiring lookahead or stateful parsing.
 *
 * Strategy (REVISED - Single Pass):
 * - Read entire line into buffer while advancing lexer
 * - Scan buffer backwards to find tag pattern
 * - Emit appropriate token based on what we found
 * - For title_with_tags: emit title, save state, then emit tags on next call
 */

#include <tree_sitter/parser.h>
#include <wctype.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>

// Token types
enum TokenType {
    TITLE_TEXT,  // Title portion
    TAGS,        // Tags portion
};

// Scanner state
typedef struct {
    bool emitting_tags;       // True if next call should emit tags
    uint32_t tags_start;      // Position where tags start in saved content
    uint32_t content_len;     // Length of saved content
    int32_t content[4096];    // Saved line content
} Scanner;

// Forward declarations
static bool scan_title(Scanner *scanner, TSLexer *lexer);
static bool scan_tags(Scanner *scanner, TSLexer *lexer);
static bool is_valid_tag_char(int32_t c);
static bool find_tags_in_buffer(int32_t *buffer, uint32_t len, uint32_t *out_title_len, uint32_t *out_tags_start);

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
 * Serialize scanner state
 */
unsigned tree_sitter_org_inline_external_scanner_serialize(void *payload, char *buffer) {
    Scanner *scanner = (Scanner *)payload;
    // Only serialize the flags, not the content buffer (too large)
    buffer[0] = scanner->emitting_tags ? 1 : 0;
    return 1;
}

/**
 * Deserialize scanner state
 */
void tree_sitter_org_inline_external_scanner_deserialize(void *payload, const char *buffer, unsigned length) {
    Scanner *scanner = (Scanner *)payload;
    if (length > 0) {
        scanner->emitting_tags = (buffer[0] == 1);
    } else {
        scanner->emitting_tags = false;
    }
}

/**
 * Main scanning function
 */
bool tree_sitter_org_inline_external_scanner_scan(void *payload, TSLexer *lexer, const bool *valid_symbols) {
    Scanner *scanner = (Scanner *)payload;

    // If we're in the middle of emitting tags, do that
    if (scanner->emitting_tags && valid_symbols[TAGS]) {
        return scan_tags(scanner, lexer);
    }

    // Otherwise try to scan title
    if (valid_symbols[TITLE_TEXT]) {
        return scan_title(scanner, lexer);
    }

    return false;
}

/**
 * Scan title - emits title portion, stopping at potential tags
 *
 * Strategy: Advance character by character. When we see " :" pattern,
 * emit TITLE_TEXT including the space and let TAGS scanner validate the rest.
 * If no " :" pattern found, consume entire line as title.
 */
static bool scan_title(Scanner *scanner, TSLexer *lexer) {
    // Skip leading whitespace
    while (lexer->lookahead == ' ' || lexer->lookahead == '\t' ||
           lexer->lookahead == '\n' || lexer->lookahead == '\r') {
        lexer->advance(lexer, true);
    }

    // If EOF, nothing to parse
    if (lexer->lookahead == 0) {
        return false;
    }

    // Special case: line starts with ':' means empty title with tags
    if (lexer->lookahead == ':') {
        scanner->emitting_tags = true;
        lexer->mark_end(lexer);  // Mark end at start (empty title)
        lexer->result_symbol = TITLE_TEXT;
        return true;
    }

    // Advance through content until we find " :" or reach EOL
    bool has_content = false;

    while (lexer->lookahead != '\n' && lexer->lookahead != 0) {
        int32_t c = lexer->lookahead;
        has_content = true;
        lexer->advance(lexer, false);

        // After advancing, check if we just passed a space and next is colon
        if (c == ' ' && lexer->lookahead == ':') {
            // Perfect! We're right after the space, before the colon
            // Emit title including the space, lexer positioned at colon
            scanner->emitting_tags = true;
            lexer->mark_end(lexer);  // Mark end at current position (after space, before colon)
            lexer->result_symbol = TITLE_TEXT;
            return true;
        }
    }

    // Reached EOL - entire line is title
    if (!has_content) {
        return false;
    }

    scanner->emitting_tags = false;
    lexer->mark_end(lexer);
    lexer->result_symbol = TITLE_TEXT;
    return true;
}

/**
 * Scan tags - validates and consumes tags from current position
 *
 * Expected format: :tag1:tag2:...:tagN: followed by EOL
 * If format is invalid, returns false and grammar will backtrack
 */
static bool scan_tags(Scanner *scanner, TSLexer *lexer) {
    if (!scanner->emitting_tags) {
        return false;
    }

    // Should be at ':' character now
    if (lexer->lookahead != ':') {
        scanner->emitting_tags = false;
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
                scanner->emitting_tags = false;
                return false;
            }
        } else if (is_valid_tag_char(c)) {
            if (!in_tag) {
                // Tag character outside of :tag: - invalid
                scanner->emitting_tags = false;
                return false;
            }
            tag_char_count++;
        } else {
            // Invalid character in tags
            scanner->emitting_tags = false;
            return false;
        }

        lexer->advance(lexer, false);
    }

    // Must end with ':' (so tag_char_count should be 0 - not building a tag name)
    // and we must have seen at least one tag
    if (!has_any_tag || tag_char_count > 0) {
        scanner->emitting_tags = false;
        return false;
    }

    // Valid tags!
    scanner->emitting_tags = false;
    lexer->mark_end(lexer);
    lexer->result_symbol = TAGS;
    return true;
}

/**
 * Find tags in buffer by scanning backwards
 * Returns true if tags found, with title_len and tags_start set
 */
static bool find_tags_in_buffer(int32_t *buffer, uint32_t len,
                                uint32_t *out_title_len, uint32_t *out_tags_start) {
    if (len == 0) {
        return false;
    }

    // Must end with ':'
    if (buffer[len - 1] != ':') {
        *out_title_len = len;
        return false;
    }

    // Scan backwards
    int32_t pos = len - 2;  // Start before final ':'
    bool in_tag = false;
    int32_t tags_start = -1;
    int32_t tag_count = 0;

    while (pos >= 0) {
        int32_t c = buffer[pos];

        if (c == ':') {
            if (in_tag) {
                // Found start of a tag
                tag_count++;
                in_tag = false;
                tags_start = pos;
            } else {
                // Two colons in a row - invalid
                break;
            }
        } else if (is_valid_tag_char(c)) {
            if (!in_tag) {
                in_tag = true;
            }
        } else if (c == ' ' && tags_start >= 0 && tag_count > 0 && !in_tag) {
            // Found space before tags!
            *out_title_len = pos;  // Title up to space
            *out_tags_start = pos + 1;  // Tags start after space
            return true;
        } else {
            // Invalid character
            break;
        }

        pos--;
    }

    // No valid tags
    *out_title_len = len;
    return false;
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
