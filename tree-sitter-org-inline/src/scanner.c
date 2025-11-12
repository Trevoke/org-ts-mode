/**
 * External scanner for org-mode inline grammar
 *
 * PHASE 7: OPEN/CLOSE token architecture (markdown-inspired)
 *
 * Handles context-sensitive parsing for:
 * - Subscript and superscript (requires lookbehind for CHAR)
 * - Tags (requires end-of-line detection)
 * - Text markup OPEN/CLOSE tokens with PRE/POST validation
 *   - Scanner validates PRE character at OPEN token
 *   - Scanner validates POST character at CLOSE token
 *   - Grammar tracks state between OPEN and CLOSE
 */

#include <tree_sitter/parser.h>
#include <wctype.h>
#include <stdbool.h>
#include <string.h>

// Symbol enum - must match order in grammar.js externals array
// Phase 7: OPEN/CLOSE tokens for all markup types
enum TokenType {
  SUBSCRIPT,
  SUPERSCRIPT,
  TAGS,  // Phase 5
  // Phase 7: OPEN/CLOSE pairs for each markup type
  BOLD_OPEN,
  BOLD_CLOSE,
  ITALIC_OPEN,
  ITALIC_CLOSE,
  CODE_OPEN,
  CODE_CLOSE,
  VERBATIM_OPEN,
  VERBATIM_CLOSE,
  UNDERLINE_OPEN,
  UNDERLINE_CLOSE,
  STRIKE_THROUGH_OPEN,
  STRIKE_THROUGH_CLOSE,
};

// Scanner state - Phase 7: Simplified, no global context needed
// Grammar structure tracks state between OPEN and CLOSE
typedef struct {
  // Reserved for future use (delimiter tracking, etc.)
  uint8_t reserved;
} Scanner;

// Helper: Check if character is valid PRE (can appear before opening delimiter)
// PRE: whitespace, -, (, {, ', ", or BOL
static inline bool is_valid_pre_char(int32_t c) {
  return c == ' ' || c == '\t' || c == '\n' || c == '\r' ||
         c == '-' || c == '(' || c == '{' || c == '\'' || c == '"';
}

// Helper: Check if character is valid POST (can appear after closing delimiter)
// POST: whitespace, -, punctuation, closing brackets, or EOL
static inline bool is_valid_post_char(int32_t c) {
  return c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == 0 ||
         c == '-' || c == '.' || c == ',' || c == ';' || c == ':' ||
         c == '!' || c == '?' || c == '\'' || c == '"' ||
         c == ')' || c == '}' || c == ']';
}

// Helper: Try to parse OPEN token for markup
// Validates PRE character (what came before) using valid_symbols as hint
// Returns true if valid OPEN found
static bool try_markup_open(TSLexer *lexer, int32_t delimiter, enum TokenType open_token, const bool *valid_symbols) {
  // If this token isn't valid here, don't try to parse it
  if (!valid_symbols[open_token]) return false;

  // Check if we're looking at the delimiter
  if (lexer->lookahead != delimiter) return false;

  // Consume the opening delimiter
  lexer->advance(lexer, false);

  // Content must not start with whitespace (org-mode spec)
  if (iswspace(lexer->lookahead)) return false;

  // Valid OPEN token!
  lexer->mark_end(lexer);
  lexer->result_symbol = open_token;
  return true;
}

// Helper: Try to parse CLOSE token for markup
// Validates POST character (what comes after)
// Returns true if valid CLOSE found
static bool try_markup_close(TSLexer *lexer, int32_t delimiter, enum TokenType close_token, const bool *valid_symbols) {
  // If this token isn't valid here, don't try to parse it
  if (!valid_symbols[close_token]) return false;

  // Check if we're looking at the delimiter
  if (lexer->lookahead != delimiter) return false;

  // Consume the closing delimiter
  lexer->advance(lexer, false);

  // Validate POST character (what comes after closing delimiter)
  if (!is_valid_post_char(lexer->lookahead)) return false;

  // Valid CLOSE token!
  lexer->mark_end(lexer);
  lexer->result_symbol = close_token;
  return true;
}

// Helper: Check if character is valid CHAR (non-whitespace)
static inline bool is_valid_char(int32_t c) {
  return c != ' ' && c != '\t' && c != '\n' && c != '\r' && c != 0;
}

// Helper: Check if this looks like underline markup instead of subscript
// Underline: _text_ (paired underscores with content between)
// Subscript: H_2O (single underscore as delimiter)
// Heuristic: Look ahead to see if there's a closing _ within reasonable distance
static bool looks_like_underline(TSLexer *lexer) {
  // Save current position
  int32_t depth = 0;
  int chars_seen = 0;
  const int MAX_LOOKAHEAD = 100; // Don't look too far ahead

  // Look ahead for closing _
  while (lexer->lookahead != 0 && chars_seen < MAX_LOOKAHEAD) {
    if (lexer->lookahead == '_') {
      // Found potential closing underscore
      // Check if there's whitespace or end after it (underline pattern)
      lexer->advance(lexer, false);
      int32_t next = lexer->lookahead;
      // If followed by whitespace, punctuation, or end - likely underline
      return (next == ' ' || next == '\t' || next == '\n' ||
              next == '.' || next == ',' || next == ';' ||
              next == ':' || next == ')' || next == '}' ||
              next == ']' || next == 0);
    }
    lexer->advance(lexer, false);
    chars_seen++;
  }

  return false; // No closing _ found, not underline
}

// Helper: Parse SCRIPT pattern for subscript/superscript
// Returns true if valid SCRIPT found and consumed
static bool parse_script(TSLexer *lexer) {
  // Form 1: Single asterisk
  if (lexer->lookahead == '*') {
    lexer->advance(lexer, false);
    return true;
  }

  // Form 2: Bracketed {...} (simplified - no nesting support yet)
  if (lexer->lookahead == '{') {
    lexer->advance(lexer, false);
    int depth = 1;
    while (depth > 0 && lexer->lookahead != 0) {
      if (lexer->lookahead == '{') depth++;
      if (lexer->lookahead == '}') depth--;
      lexer->advance(lexer, false);
      if (depth == 0) return true;
    }
    return false; // Unbalanced braces
  }

  // Form 3: Alphanumeric [+-]?[a-zA-Z0-9,\\.]+[a-zA-Z0-9]
  // Optional sign
  if (lexer->lookahead == '+' || lexer->lookahead == '-') {
    lexer->advance(lexer, false);
  }

  // Must have at least one valid character
  bool has_content = false;
  int32_t last_char = 0;

  while (lexer->lookahead != 0 && !iswspace(lexer->lookahead)) {
    int32_t c = lexer->lookahead;

    // Valid SCRIPT characters: alphanumeric, comma, period
    if (iswalnum(c) || c == ',' || c == '.') {
      has_content = true;
      last_char = c;
      lexer->advance(lexer, false);
    } else {
      // Stop at invalid character
      break;
    }
  }

  // Must end with alphanumeric (not comma or period)
  return has_content && (iswalnum(last_char));
}

// Helper: Check if character is valid in tag name
// Tags can contain: alphanumeric, _, @, #, %
static inline bool is_valid_tag_char(int32_t c) {
  return iswalnum(c) || c == '_' || c == '@' || c == '#' || c == '%';
}

// Helper: Try to parse tags at end of title
// Pattern: :tag1:tag2:tag3: (at end of line, usually preceded by space)
// Returns true if valid tags pattern found and consumed
static bool parse_tags(TSLexer *lexer) {
  // Tags start with ':'
  if (lexer->lookahead != ':') return false;

  int tags_count = 0;

  // Parse :tag:tag:tag: pattern
  while (lexer->lookahead == ':') {
    lexer->advance(lexer, false); // Consume ':'

    // Check if we're at end of line (final ':' of tags)
    if (lexer->lookahead == '\n' || lexer->lookahead == 0) {
      // Valid tags pattern: consumed at least one tag
      return tags_count > 0;
    }

    // Parse tag name between colons
    bool has_tag_chars = false;
    while (is_valid_tag_char(lexer->lookahead)) {
      has_tag_chars = true;
      lexer->advance(lexer, false);
    }

    // Must have at least one tag character between colons
    if (!has_tag_chars) {
      // Empty tag like :: - not valid
      return false;
    }

    tags_count++;
  }

  // Reached here means we exited loop (no more ':')
  // This shouldn't happen if pattern is correct, return false
  return false;
}

// Create scanner instance
void *tree_sitter_org_inline_external_scanner_create() {
  Scanner *scanner = (Scanner *)malloc(sizeof(Scanner));
  scanner->reserved = 0;
  return scanner;
}

// Destroy scanner instance
void tree_sitter_org_inline_external_scanner_destroy(void *payload) {
  Scanner *scanner = (Scanner *)payload;
  free(scanner);
}

// Serialize scanner state - Phase 7: Minimal state
unsigned tree_sitter_org_inline_external_scanner_serialize(
  void *payload,
  char *buffer
) {
  Scanner *scanner = (Scanner *)payload;
  buffer[0] = (char)scanner->reserved;
  return 1;
}

// Deserialize scanner state - Phase 7: Minimal state
void tree_sitter_org_inline_external_scanner_deserialize(
  void *payload,
  const char *buffer,
  unsigned length
) {
  Scanner *scanner = (Scanner *)payload;
  if (length > 0) {
    scanner->reserved = (uint8_t)buffer[0];
  } else {
    scanner->reserved = 0;
  }
}

// Main scanning function - Phase 7: OPEN/CLOSE tokens
bool tree_sitter_org_inline_external_scanner_scan(
  void *payload,
  TSLexer *lexer,
  const bool *valid_symbols
) {
  Scanner *scanner = (Scanner *)payload;

  // Phase 7: Try OPEN/CLOSE tokens for all markup types
  // Grammar structure tracks state between OPEN and CLOSE
  // Scanner only validates local PRE (at OPEN) and POST (at CLOSE) conditions

  // Bold: * delimiter
  if (try_markup_open(lexer, '*', BOLD_OPEN, valid_symbols)) return true;
  if (try_markup_close(lexer, '*', BOLD_CLOSE, valid_symbols)) return true;

  // Italic: / delimiter
  if (try_markup_open(lexer, '/', ITALIC_OPEN, valid_symbols)) return true;
  if (try_markup_close(lexer, '/', ITALIC_CLOSE, valid_symbols)) return true;

  // Code: ~ delimiter
  if (try_markup_open(lexer, '~', CODE_OPEN, valid_symbols)) return true;
  if (try_markup_close(lexer, '~', CODE_CLOSE, valid_symbols)) return true;

  // Verbatim: = delimiter
  if (try_markup_open(lexer, '=', VERBATIM_OPEN, valid_symbols)) return true;
  if (try_markup_close(lexer, '=', VERBATIM_CLOSE, valid_symbols)) return true;

  // Strike-through: + delimiter
  if (try_markup_open(lexer, '+', STRIKE_THROUGH_OPEN, valid_symbols)) return true;
  if (try_markup_close(lexer, '+', STRIKE_THROUGH_CLOSE, valid_symbols)) return true;

  // Underline: _ delimiter (special handling for subscript conflict)
  if (try_markup_open(lexer, '_', UNDERLINE_OPEN, valid_symbols)) return true;
  if (try_markup_close(lexer, '_', UNDERLINE_CLOSE, valid_symbols)) return true;

  // Try to scan subscript (doesn't need valid PRE - comes after any CHAR)
  if (valid_symbols[SUBSCRIPT]) {
    if (lexer->lookahead == '_') {
      lexer->advance(lexer, false); // Consume '_'

      // Try to parse SCRIPT
      if (parse_script(lexer)) {
        // Check if SCRIPT is followed by another '_' (closing underline delimiter)
        // If so, this is underline markup like _text_, not subscript like H_2O
        if (lexer->lookahead == '_') {
          // This is paired underline markup, not subscript
          // Don't mark end, return false to let underline matcher handle it
          return false;
        }

        // Valid subscript pattern found
        lexer->mark_end(lexer);
        lexer->result_symbol = SUBSCRIPT;
        return true;
      }
      // Pattern didn't match - tree-sitter will backtrack automatically
      return false;
    }
  }

  // Try to scan superscript
  if (valid_symbols[SUPERSCRIPT]) {
    if (lexer->lookahead == '^') {
      lexer->advance(lexer, false); // Consume '^'

      // Try to parse SCRIPT
      if (parse_script(lexer)) {
        // Only mark end after successful parse
        lexer->mark_end(lexer);
        lexer->result_symbol = SUPERSCRIPT;
        return true;
      }
      // Pattern didn't match - tree-sitter will backtrack automatically
      return false;
    }
  }

  // Try to scan tags (Phase 5)
  // Tags appear at end of title: :tag1:tag2:
  if (valid_symbols[TAGS]) {
    if (lexer->lookahead == ':') {
      // Try to parse tags pattern
      if (parse_tags(lexer)) {
        // Valid tags pattern found and consumed
        lexer->mark_end(lexer);
        lexer->result_symbol = TAGS;
        return true;
      }
      // Not a valid tags pattern, let other parsers handle the ':'
      return false;
    }
  }

  // Phase 7: No global context tracking needed!
  // Grammar structure between OPEN and CLOSE is the context.
  return false;
}
