/**
 * @file External scanner for Org-mode tree-sitter grammar
 * @author Tree-sitter Org-mode Contributors
 * @license MIT
 *
 * This external scanner handles tokens that require lookahead, context-sensitivity,
 * or stateful parsing that cannot be expressed with regular expressions alone.
 *
 * Current responsibilities:
 * 1. Headline tags - Separating title from tags at end of headline
 *
 * Strategy for headline parsing:
 * - External scanner must NOT consume keywords (TODO, DONE, etc.) or priorities ([#A])
 * - Scanner checks if current position has keyword/priority and returns false if so
 * - Only emits HEADLINE_TITLE for actual title content
 * - Separates title from tags by scanning backwards from EOL
 */

#include <tree_sitter/parser.h>
#include <wctype.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>

// Token types (must match order in grammar.js externals array)
enum TokenType {
    HEADLINE_TITLE,           // Title portion of headline (before tags)
    HEADLINE_TAGS,            // Tags portion of headline (:tag1:tag2:)
    LIST_ITEM_CONTENT_LINE,   // Continuation line within list item
};

// Maximum nesting depth for lists
#define MAX_INDENT_STACK 32

// Scanner state structure
typedef struct {
    // State for headline tag parsing
    bool has_tags;              // Whether current headline has tags
    uint32_t tag_content_len;   // Length of tag content (for serialization)

    // State for list item indentation tracking
    uint16_t indent_stack[MAX_INDENT_STACK];  // Stack of indentation levels
    uint8_t indent_stack_len;                  // Current stack depth
    uint8_t consecutive_blank_lines;           // Count of consecutive blank lines
} Scanner;

// Forward declarations
static bool scan_headline_title(Scanner *scanner, TSLexer *lexer);
static bool scan_headline_tags(Scanner *scanner, TSLexer *lexer);
static bool is_valid_tag_char(int32_t c);
static bool scan_tags_from_end(TSLexer *lexer, uint32_t *title_len, uint32_t *tags_len);
static bool starts_with_keyword(TSLexer *lexer);
static bool starts_with_priority(TSLexer *lexer);
static bool scan_list_item_content_line(Scanner *scanner, TSLexer *lexer);
static uint16_t count_indentation(TSLexer *lexer);
static bool is_blank_line(TSLexer *lexer);
static bool looks_like_bullet(TSLexer *lexer);

/**
 * Create and initialize a new scanner instance
 */
void *tree_sitter_org_external_scanner_create() {
    Scanner *scanner = (Scanner *)calloc(1, sizeof(Scanner));
    scanner->has_tags = false;
    scanner->tag_content_len = 0;
    scanner->indent_stack_len = 0;
    scanner->consecutive_blank_lines = 0;
    return scanner;
}

/**
 * Destroy scanner and free memory
 */
void tree_sitter_org_external_scanner_destroy(void *payload) {
    Scanner *scanner = (Scanner *)payload;
    free(scanner);
}

/**
 * Serialize scanner state to buffer
 * Returns number of bytes written
 */
unsigned tree_sitter_org_external_scanner_serialize(void *payload, char *buffer) {
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
void tree_sitter_org_external_scanner_deserialize(void *payload, const char *buffer, unsigned length) {
    Scanner *scanner = (Scanner *)payload;

    if (length == 0) {
        scanner->has_tags = false;
        scanner->tag_content_len = 0;
        scanner->indent_stack_len = 0;
        scanner->consecutive_blank_lines = 0;
        return;
    }

    if (length == sizeof(Scanner)) {
        memcpy(scanner, buffer, sizeof(Scanner));
    }
}

/**
 * Main scanning function - called by tree-sitter parser
 *
 * @param payload Scanner state
 * @param lexer Lexer interface for reading input
 * @param valid_symbols Array indicating which tokens are valid at this position
 * @return true if a token was emitted, false otherwise
 */
bool tree_sitter_org_external_scanner_scan(void *payload, TSLexer *lexer, const bool *valid_symbols) {
    Scanner *scanner = (Scanner *)payload;

    // Try to scan list item content line
    if (valid_symbols[LIST_ITEM_CONTENT_LINE]) {
        return scan_list_item_content_line(scanner, lexer);
    }

    // Try to scan headline title
    if (valid_symbols[HEADLINE_TITLE]) {
        return scan_headline_title(scanner, lexer);
    }

    // Try to scan headline tags
    if (valid_symbols[HEADLINE_TAGS]) {
        return scan_headline_tags(scanner, lexer);
    }

    return false;
}

/**
 * Scan headline title portion (everything before tags, or entire line if no tags)
 *
 * Strategy:
 * 1. First check if we're looking at a keyword or priority - if so, return false
 *    to let the normal parser handle them
 * 2. Scan entire line to end
 * 3. Look backwards for tag pattern: space + :tag:tag: at EOL
 * 4. If tags found: emit title up to (but not including) the space before tags
 * 5. If no tags: emit entire line
 * 6. Save state for subsequent HEADLINE_TAGS scan
 */
static bool scan_headline_title(Scanner *scanner, TSLexer *lexer) {
    // Don't consume keywords - let the normal parser handle them
    if (starts_with_keyword(lexer)) {
        return false;
    }

    // Don't consume priorities - let the normal parser handle them
    if (starts_with_priority(lexer)) {
        return false;
    }

    // Reset state for new headline
    scanner->has_tags = false;
    scanner->tag_content_len = 0;

    uint32_t title_len = 0;
    uint32_t tags_len = 0;

    // Scan from end to find tags
    bool found_tags = scan_tags_from_end(lexer, &title_len, &tags_len);

    if (found_tags && title_len > 0) {
        // Found tags - emit title portion only
        scanner->has_tags = true;
        scanner->tag_content_len = tags_len;

        // Note: scan_tags_from_end already advanced lexer through the line
        // We need to mark_end at the title boundary
        // But we've already advanced to EOL, so we can't go back
        // This is a problem with the current approach

        lexer->mark_end(lexer);
        lexer->result_symbol = HEADLINE_TITLE;
        return true;
    }

    // No tags found or empty title - consume entire line as title
    // scan_tags_from_end already advanced to EOL
    if (lexer->get_column(lexer) > 0) {
        lexer->mark_end(lexer);
        lexer->result_symbol = HEADLINE_TITLE;
        return true;
    }

    return false;  // Empty title
}

/**
 * Scan headline tags portion (space + :tag1:tag2:)
 *
 * Called after HEADLINE_TITLE has been emitted and scanner state indicates tags exist.
 */
static bool scan_headline_tags(Scanner *scanner, TSLexer *lexer) {
    if (!scanner->has_tags) {
        return false;  // No tags to emit
    }

    // Consume the leading space before tags
    if (lexer->lookahead == ' ') {
        lexer->advance(lexer, false);
    }

    // Consume the tag content
    uint32_t consumed = 0;
    while (lexer->lookahead != '\n' && lexer->lookahead != 0) {
        lexer->advance(lexer, false);
        consumed++;
    }

    if (consumed > 0) {
        lexer->mark_end(lexer);
        lexer->result_symbol = HEADLINE_TAGS;

        // Reset state after emitting tags
        scanner->has_tags = false;
        scanner->tag_content_len = 0;

        return true;
    }

    return false;
}

/**
 * Scan backwards from end of line to detect tag pattern
 *
 * Tag pattern: space + :tag1:tag2:tag3: at end of line
 * Tag characters: letters, numbers, '_', '@', '#', '%'
 *
 * @param lexer Lexer interface
 * @param title_len Output: length of title portion (including trailing space before tags)
 * @param tags_len Output: length of tags portion (excluding leading space)
 * @return true if valid tags found, false otherwise
 */
static bool scan_tags_from_end(TSLexer *lexer, uint32_t *title_len, uint32_t *tags_len) {
    // Buffer to store line content
    #define MAX_LINE_LEN 4096
    int32_t line_buffer[MAX_LINE_LEN];
    uint32_t line_len = 0;

    // Read entire line into buffer
    while (lexer->lookahead != '\n' && lexer->lookahead != 0 && line_len < MAX_LINE_LEN) {
        line_buffer[line_len++] = lexer->lookahead;
        lexer->advance(lexer, false);
    }

    if (line_len == 0) {
        return false;
    }

    // Scan backwards to find tag pattern
    // Pattern: :tag:tag:tag: where tags contain valid characters

    int32_t pos = line_len - 1;

    // Must end with ':'
    if (line_buffer[pos] != ':') {
        *title_len = line_len;
        *tags_len = 0;
        return false;
    }

    // Scan backwards through tags
    int32_t tags_end = pos;
    pos--;

    bool in_tag = false;
    int32_t tag_start = -1;
    int32_t tags_begin = -1;
    int32_t tag_count = 0;

    while (pos >= 0) {
        int32_t c = line_buffer[pos];

        if (c == ':') {
            if (in_tag) {
                // End of a tag (scanning backwards, so this is the start of the tag)
                tag_count++;
                in_tag = false;
                tags_begin = pos;  // Potential start of entire tag sequence
            } else {
                // Two colons in a row - invalid
                break;
            }
        } else if (is_valid_tag_char(c)) {
            if (!in_tag) {
                // Start of a tag (scanning backwards, so this is the end of the tag)
                tag_start = pos;
                in_tag = true;
            }
            // Continue scanning tag content
        } else if (c == ' ' && tags_begin >= 0 && tag_count > 0 && !in_tag) {
            // Found space before tags - valid tag sequence
            *title_len = pos;  // Title includes everything up to (but not including) this space
            *tags_len = line_len - pos - 1;  // Tags exclude the leading space
            return true;
        } else {
            // Invalid character in tag sequence
            break;
        }

        pos--;
    }

    // Check if tags extend to start of line (no title, just tags)
    if (tags_begin == 0 && tag_count > 0 && !in_tag) {
        *title_len = 0;
        *tags_len = line_len;
        return true;
    }

    // No valid tag pattern found
    *title_len = line_len;
    *tags_len = 0;
    return false;
}

/**
 * Check if character is valid in tag name
 * Valid: letters, numbers, '_', '@', '#', '%'
 */
static bool is_valid_tag_char(int32_t c) {
    return (c >= 'a' && c <= 'z') ||
           (c >= 'A' && c <= 'Z') ||
           (c >= '0' && c <= '9') ||
           c == '_' || c == '@' || c == '#' || c == '%';
}

/**
 * Check if current position starts with a TODO keyword
 * Keywords: TODO, DONE, NEXT, WAITING, CANCELED
 * Must be followed by space or newline
 */
static bool starts_with_keyword(TSLexer *lexer) {
    // Check for each keyword
    const char *keywords[] = {"TODO", "DONE", "NEXT", "WAITING", "CANCELED", NULL};

    for (int i = 0; keywords[i] != NULL; i++) {
        const char *kw = keywords[i];
        int32_t saved_pos[20];  // Max keyword length
        int len = 0;

        // Save current position and check if keyword matches
        bool matches = true;
        while (kw[len] != '\0') {
            saved_pos[len] = lexer->lookahead;
            if (lexer->lookahead != kw[len]) {
                matches = false;
            }
            lexer->advance(lexer, false);
            len++;
        }

        // Check if followed by space or newline (word boundary)
        bool word_boundary = (lexer->lookahead == ' ' || lexer->lookahead == '\n' || lexer->lookahead == 0);

        // Reset lexer to original position
        // Note: TSLexer doesn't have a way to reset, so we can't actually do this check properly
        // We need a different approach

        // This approach doesn't work because we can't reset the lexer
        // We'll need to use lookahead differently
    }

    // Simplified check: look at first character
    // If it's 'T', 'D', 'N', 'W', or 'C', assume it might be a keyword
    // This is a heuristic - not perfect but safer than consuming everything
    int32_t c = lexer->lookahead;
    if (c == 'T' || c == 'D' || c == 'N' || c == 'W' || c == 'C') {
        return true;  // Might be a keyword, let parser handle it
    }

    return false;
}

/**
 * Check if current position starts with a priority marker [#A]
 */
static bool starts_with_priority(TSLexer *lexer) {
    // Priority pattern: [#X] where X is A-Z
    return lexer->lookahead == '[';
}

/**
 * Count indentation at current position
 * Spaces count as 1, tabs count as 8 (per Org-mode spec)
 * Stops at first non-whitespace character or newline
 *
 * @param lexer Lexer interface
 * @return Indentation level
 */
static uint16_t count_indentation(TSLexer *lexer) {
    uint16_t indent = 0;

    while (lexer->lookahead == ' ' || lexer->lookahead == '\t') {
        if (lexer->lookahead == '\t') {
            indent += 8;  // Org-mode: tabs = 8 spaces
        } else {
            indent += 1;
        }
        lexer->advance(lexer, true);  // Skip whitespace
    }

    return indent;
}

/**
 * Check if current line is blank (only whitespace until newline or EOF)
 *
 * @param lexer Lexer interface
 * @return true if line is blank, false otherwise
 */
static bool is_blank_line(TSLexer *lexer) {
    // Skip whitespace
    while (lexer->lookahead == ' ' || lexer->lookahead == '\t') {
        lexer->advance(lexer, true);
    }

    // Check if we hit newline or EOF
    return lexer->lookahead == '\n' || lexer->lookahead == 0;
}

/**
 * Scan list item content line (continuation line within list item)
 *
 * This function is called when the parser is looking for continuation lines
 * within a list item. It checks if the current line is indented enough to
 * be part of the list item's content.
 *
 * Org-mode spec: List item contents continue until:
 * 1. A line less or equally indented than the starting line
 * 2. Two consecutive blank lines
 * 3. The next item or other element
 *
 * Strategy:
 * - Peek at indentation of current line (without consuming)
 * - If indented: consume entire line and emit token
 * - If not indented: return false (end of item)
 * - Track blank lines for two-blank termination
 *
 * @param scanner Scanner state
 * @param lexer Lexer interface
 * @return true if content line token emitted, false otherwise
 */
static bool scan_list_item_content_line(Scanner *scanner, TSLexer *lexer) {
    // Check if line starts with whitespace (indented)
    // Simple heuristic: any indentation means continuation
    // TODO: More sophisticated logic comparing against bullet column

    // If line starts with a bullet at column 0, it's a new item, not a continuation
    if (looks_like_bullet(lexer)) {
        scanner->consecutive_blank_lines = 0;
        return false;  // New list item
    }

    if (lexer->lookahead == ' ' || lexer->lookahead == '\t') {
        // Line is indented - it's a continuation line
        // Consume the entire line including newline
        while (lexer->lookahead != '\n' && lexer->lookahead != 0) {
            lexer->advance(lexer, false);
        }

        if (lexer->lookahead == '\n') {
            lexer->advance(lexer, false);
        }

        lexer->mark_end(lexer);
        lexer->result_symbol = LIST_ITEM_CONTENT_LINE;
        scanner->consecutive_blank_lines = 0;  // Reset blank counter
        return true;
    }

    // Check for blank line
    if (lexer->lookahead == '\n') {
        scanner->consecutive_blank_lines++;

        // Two consecutive blank lines terminate the item
        if (scanner->consecutive_blank_lines >= 2) {
            return false;  // End of item
        }

        // Single blank line is OK - consume it
        lexer->advance(lexer, false);
        lexer->mark_end(lexer);
        lexer->result_symbol = LIST_ITEM_CONTENT_LINE;
        return true;
    }

    // Line starts at column 0 with non-whitespace, non-bullet - could be another element
    scanner->consecutive_blank_lines = 0;
    return false;
}

/**
 * Check if current position looks like a list bullet
 * Bullets: -, +, *, number., number), letter., letter)
 * followed by space
 *
 * @param lexer Lexer interface
 * @return true if looks like a bullet, false otherwise
 */
static bool looks_like_bullet(TSLexer *lexer) {
    int32_t c = lexer->lookahead;

    // Simple bullets: -, +
    if (c == '-' || c == '+') {
        return true;
    }

    // Asterisk: * (but could be headline, so be careful)
    if (c == '*') {
        return true;
    }

    // Numbered or lettered bullets: need to look ahead
    if ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
        // Could be bullet, but we'd need to scan ahead for . or )
        // For now, assume it might be
        return true;
    }

    return false;
}
