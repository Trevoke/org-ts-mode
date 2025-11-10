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
    TAGS,  // Tags portion (:tag1:tag2:)
};

// Scanner state
typedef struct {
    // No state needed for simple tag detection
    int unused;  // Placeholder to avoid empty struct
} Scanner;

// Forward declarations
static bool scan_tags(Scanner *scanner, TSLexer *lexer);
static bool is_valid_tag_char(int32_t c);

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
 * Only emits TAGS token. The grammar handles parsing title content
 * (markup and plain text) using its own rules.
 */
bool tree_sitter_org_inline_external_scanner_scan(void *payload, TSLexer *lexer, const bool *valid_symbols) {
    Scanner *scanner = (Scanner *)payload;

    // Only scan for TAGS when grammar expects it
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
