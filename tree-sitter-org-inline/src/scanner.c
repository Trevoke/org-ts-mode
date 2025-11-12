/**
 * External scanner for org-mode inline grammar
 *
 * Handles context-sensitive parsing for:
 * - Subscript and superscript (requires lookbehind for CHAR)
 * - Tags (requires end-of-line detection)
 * - PRE/POST validation for text markup (future enhancement)
 */

#include <tree_sitter/parser.h>
#include <wctype.h>
#include <stdbool.h>
#include <string.h>

// Symbol enum - must match order in grammar.js externals array
enum TokenType {
  SUBSCRIPT,
  SUPERSCRIPT,
};

// Scanner state (currently no state needed)
typedef struct {
  // Reserved for future use
  int dummy;
} Scanner;

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

// Create scanner instance
void *tree_sitter_org_inline_external_scanner_create() {
  Scanner *scanner = (Scanner *)malloc(sizeof(Scanner));
  scanner->dummy = 0;
  return scanner;
}

// Destroy scanner instance
void tree_sitter_org_inline_external_scanner_destroy(void *payload) {
  Scanner *scanner = (Scanner *)payload;
  free(scanner);
}

// Serialize scanner state (currently no state)
unsigned tree_sitter_org_inline_external_scanner_serialize(
  void *payload,
  char *buffer
) {
  return 0; // No state to serialize
}

// Deserialize scanner state (currently no state)
void tree_sitter_org_inline_external_scanner_deserialize(
  void *payload,
  const char *buffer,
  unsigned length
) {
  // No state to deserialize
}

// Main scanning function
bool tree_sitter_org_inline_external_scanner_scan(
  void *payload,
  TSLexer *lexer,
  const bool *valid_symbols
) {
  // Try to scan subscript
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

  return false;
}
