/**
 * @file External scanner for Org-mode inline grammar (tree-sitter-org-inline)
 * @author Tree-sitter Org-mode Contributors
 * @license MIT
 *
 * This external scanner handles inline objects that require lookahead or
 * stateful parsing that cannot be expressed with regular expressions.
 *
 * Context: This scanner is part of the INLINE grammar, which is injected into
 * nodes from the block grammar (tree-sitter-org). The block grammar has already
 * parsed headline structure (stars, keywords, priorities), so this scanner only
 * needs to handle the title content.
 *
 * Current responsibilities:
 * 1. Title/tags separation - Detecting `:tag:` pattern at end of title content
 * 2. Future: Bold, italic, links, and other inline markup
 *
 * Strategy (REVISED):
 * - Peek ahead to detect tag pattern at EOL
 * - Advance only through title portion (not entire line)
 * - Mark end at correct boundary
 * - Save state for tags emission on next call
 */

#include <tree_sitter/parser.h>
#include <wctype.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>

// Token types (must match order in grammar.js externals array)
enum TokenType {
    TITLE_TEXT,  // Title portion (before tags)
    TAGS,        // Tags portion (:tag1:tag2:)
};

// Scanner state structure
typedef struct {
    bool has_tags;              // Whether current content has tags
    uint32_t title_len;         // Length of title (for next scan)
} Scanner;

// Forward declarations
static bool scan_title(Scanner *scanner, TSLexer *lexer);
static bool scan_tags(Scanner *scanner, TSLexer *lexer);
static bool is_valid_tag_char(int32_t c);
static bool find_tags_at_end(TSLexer *lexer, uint32_t *out_title_len, uint32_t *out_tags_len);

/**
 * Create and initialize a new scanner instance
 */
void *tree_sitter_org_inline_external_scanner_create() {
    Scanner *scanner = (Scanner *)calloc(1, sizeof(Scanner));
    scanner->has_tags = false;
    scanner->title_len = 0;
    return scanner;
}

/**
 * Destroy scanner and free memory
 */
void tree_sitter_org_inline_external_scanner_destroy(void *payload) {
    Scanner *scanner = (Scanner *)payload;
    free(scanner);
}

/**
 * Serialize scanner state to buffer
 */
unsigned tree_sitter_org_inline_external_scanner_serialize(void *payload, char *buffer) {
    Scanner *scanner = (Scanner *)payload;

    if (sizeof(Scanner) > TREE_SITTER_SERIALIZATION_BUFFER_SIZE) {
        return 0;
    }

    memcpy(buffer, scanner, sizeof(Scanner));
    return sizeof(Scanner);
}

/**
 * Deserialize scanner state from buffer
 */
void tree_sitter_org_inline_external_scanner_deserialize(void *payload, const char *buffer, unsigned length) {
    Scanner *scanner = (Scanner *)payload;

    if (length == 0) {
        scanner->has_tags = false;
        scanner->title_len = 0;
        return;
    }

    if (length == sizeof(Scanner)) {
        memcpy(scanner, buffer, sizeof(Scanner));
    }
}

/**
 * Main scanning function
 */
bool tree_sitter_org_inline_external_scanner_scan(void *payload, TSLexer *lexer, const bool *valid_symbols) {
    Scanner *scanner = (Scanner *)payload;

    // Try to scan title
    if (valid_symbols[TITLE_TEXT]) {
        return scan_title(scanner, lexer);
    }

    // Try to scan tags
    if (valid_symbols[TAGS]) {
        return scan_tags(scanner, lexer);
    }

    return false;
}

/**
 * Scan title portion
 *
 * Strategy:
 * 1. Peek ahead to find if tags exist at EOL
 * 2. Advance only through title portion
 * 3. Save state for tags scan
 */
static bool scan_title(Scanner *scanner, TSLexer *lexer) {
    // Reset state
    scanner->has_tags = false;
    scanner->title_len = 0;

    uint32_t title_len = 0;
    uint32_t tags_len = 0;

    // Peek ahead to detect tags
    bool found_tags = find_tags_at_end(lexer, &title_len, &tags_len);

    if (found_tags && title_len > 0) {
        // Has tags - advance only through title
        scanner->has_tags = true;
        scanner->title_len = title_len;

        // Advance through title (excluding space before tags)
        for (uint32_t i = 0; i < title_len; i++) {
            if (lexer->lookahead == '\n' || lexer->lookahead == 0) break;
            lexer->advance(lexer, false);
        }

        lexer->mark_end(lexer);
        lexer->result_symbol = TITLE_TEXT;
        return true;
    }

    if (found_tags && title_len == 0) {
        // Only tags, no title - return false to let tags be parsed
        scanner->has_tags = true;
        return false;
    }

    // No tags - entire content is title
    while (lexer->lookahead != '\n' && lexer->lookahead != 0) {
        lexer->advance(lexer, false);
    }

    if (lexer->get_column(lexer) > 0) {
        lexer->mark_end(lexer);
        lexer->result_symbol = TITLE_TEXT;
        return true;
    }

    return false;  // Empty
}

/**
 * Scan tags portion
 */
static bool scan_tags(Scanner *scanner, TSLexer *lexer) {
    if (!scanner->has_tags) {
        return false;
    }

    // Skip space before tags
    if (lexer->lookahead == ' ') {
        lexer->advance(lexer, false);
    }

    // Consume tags
    uint32_t count = 0;
    while (lexer->lookahead != '\n' && lexer->lookahead != 0) {
        lexer->advance(lexer, false);
        count++;
    }

    if (count > 0) {
        lexer->mark_end(lexer);
        lexer->result_symbol = TAGS;
        scanner->has_tags = false;  // Reset
        return true;
    }

    return false;
}

/**
 * Peek ahead to find tags at end of line
 *
 * This function does NOT advance the lexer - it only peeks.
 * Returns true if tags found, with lengths in output parameters.
 */
static bool find_tags_at_end(TSLexer *lexer, uint32_t *out_title_len, uint32_t *out_tags_len) {
    #define MAX_LINE 4096
    int32_t buffer[MAX_LINE];
    uint32_t len = 0;

    // Read line into buffer (WITHOUT advancing lexer)
    TSLexer temp = *lexer;
    while (temp.lookahead != '\n' && temp.lookahead != 0 && len < MAX_LINE) {
        buffer[len++] = temp.lookahead;
        temp.advance(&temp, false);
    }

    if (len == 0) {
        *out_title_len = 0;
        *out_tags_len = 0;
        return false;
    }

    // Scan backwards for tag pattern
    int32_t pos = len - 1;

    // Must end with ':'
    if (buffer[pos] != ':') {
        *out_title_len = len;
        *out_tags_len = 0;
        return false;
    }

    // Scan backwards through tags
    bool in_tag = false;
    int32_t tags_start = -1;
    int32_t tag_count = 0;

    pos--;
    while (pos >= 0) {
        int32_t c = buffer[pos];

        if (c == ':') {
            if (in_tag) {
                // End of a tag (going backwards)
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
            *out_tags_len = len - pos - 1;  // Tags after space
            return true;
        } else {
            // Invalid character
            break;
        }

        pos--;
    }

    // Check if tags at start of line
    if (tags_start == 0 && tag_count > 0 && !in_tag) {
        *out_title_len = 0;
        *out_tags_len = len;
        return true;
    }

    // No valid tags found
    *out_title_len = len;
    *out_tags_len = 0;
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
