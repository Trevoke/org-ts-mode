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
  TAGS,  // Phase 5
  BOLD,
  ITALIC,
  CODE,
  VERBATIM,
  UNDERLINE,
  STRIKE_THROUGH,
};

// Context for PRE character validation
typedef enum {
  CONTEXT_START,        // Beginning of input (valid PRE)
  CONTEXT_AFTER_SPACE,  // After whitespace or valid PRE char (valid PRE)
  CONTEXT_AFTER_ALNUM,  // After alphanumeric (invalid PRE for markup)
} ContextType;

// Scanner state
typedef struct {
  ContextType context;  // Track what came before for PRE validation
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

// Helper: Parse markup content and validate POST
// Returns true if valid markup pattern found
static bool parse_markup_content(TSLexer *lexer, int32_t delimiter) {
  // Content must not start with whitespace
  if (iswspace(lexer->lookahead)) return false;

  bool has_content = false;
  int32_t last_char = 0;

  // Parse content until we find the closing delimiter
  while (lexer->lookahead != delimiter && lexer->lookahead != '\n' && lexer->lookahead != 0) {
    last_char = lexer->lookahead;
    has_content = true;
    lexer->advance(lexer, false);
  }

  // Must have content and not end with whitespace
  if (!has_content || iswspace(last_char)) return false;

  // Must find closing delimiter
  if (lexer->lookahead != delimiter) return false;

  lexer->advance(lexer, false); // Consume closing delimiter

  // Validate POST character
  if (!is_valid_post_char(lexer->lookahead)) return false;

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
  scanner->context = CONTEXT_START;  // Start in valid PRE context
  return scanner;
}

// Destroy scanner instance
void tree_sitter_org_inline_external_scanner_destroy(void *payload) {
  Scanner *scanner = (Scanner *)payload;
  free(scanner);
}

// Serialize scanner state
unsigned tree_sitter_org_inline_external_scanner_serialize(
  void *payload,
  char *buffer
) {
  Scanner *scanner = (Scanner *)payload;
  buffer[0] = (char)scanner->context;
  return 1;
}

// Deserialize scanner state
void tree_sitter_org_inline_external_scanner_deserialize(
  void *payload,
  const char *buffer,
  unsigned length
) {
  Scanner *scanner = (Scanner *)payload;
  if (length > 0) {
    scanner->context = (ContextType)buffer[0];
  } else {
    scanner->context = CONTEXT_START;
  }
}

// Main scanning function
bool tree_sitter_org_inline_external_scanner_scan(
  void *payload,
  TSLexer *lexer,
  const bool *valid_symbols
) {
  Scanner *scanner = (Scanner *)payload;

  // Check if we're at beginning of line (always valid PRE)
  bool at_bol = (lexer->get_column(lexer) == 0);
  bool valid_pre_context = at_bol ||
                          (scanner->context == CONTEXT_START) ||
                          (scanner->context == CONTEXT_AFTER_SPACE);

  // Try text markup
  // PRE validation: Use context OR trust grammar (if called, it's likely valid)
  // We track context when we can, but if we lost track, allow it anyway
  // The POST validation is what really matters for correctness
  if (true) {  // Always try markup if symbol is valid (grammar controls positioning)
    // Bold: *text*
    if (valid_symbols[BOLD] && lexer->lookahead == '*') {
      lexer->advance(lexer, false);
      if (parse_markup_content(lexer, '*')) {
        lexer->mark_end(lexer);
        lexer->result_symbol = BOLD;
        // Update context based on what follows
        scanner->context = iswspace(lexer->lookahead) ? CONTEXT_AFTER_SPACE : CONTEXT_AFTER_ALNUM;
        return true;
      }
      return false;
    }

    // Italic: /text/
    if (valid_symbols[ITALIC] && lexer->lookahead == '/') {
      lexer->advance(lexer, false);
      if (parse_markup_content(lexer, '/')) {
        lexer->mark_end(lexer);
        lexer->result_symbol = ITALIC;
        scanner->context = iswspace(lexer->lookahead) ? CONTEXT_AFTER_SPACE : CONTEXT_AFTER_ALNUM;
        return true;
      }
      return false;
    }

    // Code: ~text~
    if (valid_symbols[CODE] && lexer->lookahead == '~') {
      lexer->advance(lexer, false);
      if (parse_markup_content(lexer, '~')) {
        lexer->mark_end(lexer);
        lexer->result_symbol = CODE;
        scanner->context = iswspace(lexer->lookahead) ? CONTEXT_AFTER_SPACE : CONTEXT_AFTER_ALNUM;
        return true;
      }
      return false;
    }

    // Verbatim: =text=
    if (valid_symbols[VERBATIM] && lexer->lookahead == '=') {
      lexer->advance(lexer, false);
      if (parse_markup_content(lexer, '=')) {
        lexer->mark_end(lexer);
        lexer->result_symbol = VERBATIM;
        scanner->context = iswspace(lexer->lookahead) ? CONTEXT_AFTER_SPACE : CONTEXT_AFTER_ALNUM;
        return true;
      }
      return false;
    }

    // Strike-through: +text+
    if (valid_symbols[STRIKE_THROUGH] && lexer->lookahead == '+') {
      lexer->advance(lexer, false);
      if (parse_markup_content(lexer, '+')) {
        lexer->mark_end(lexer);
        lexer->result_symbol = STRIKE_THROUGH;
        scanner->context = iswspace(lexer->lookahead) ? CONTEXT_AFTER_SPACE : CONTEXT_AFTER_ALNUM;
        return true;
      }
      return false;
    }

    // Underline: _text_
    // Special handling: check it's not a subscript
    if (valid_symbols[UNDERLINE] && lexer->lookahead == '_') {
      lexer->advance(lexer, false);
      if (parse_markup_content(lexer, '_')) {
        lexer->mark_end(lexer);
        lexer->result_symbol = UNDERLINE;
        scanner->context = iswspace(lexer->lookahead) ? CONTEXT_AFTER_SPACE : CONTEXT_AFTER_ALNUM;
        return true;
      }
      return false;
    }
  }

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
        scanner->context = CONTEXT_AFTER_ALNUM;  // Subscript ends with alnum
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
        scanner->context = CONTEXT_AFTER_ALNUM;  // Superscript ends with alnum
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
        scanner->context = CONTEXT_START;  // Tags are at end, reset for next line
        return true;
      }
      // Not a valid tags pattern, let other parsers handle the ':'
      return false;
    }
  }

  // If we reach here and see whitespace, update context for next call
  if (iswspace(lexer->lookahead)) {
    scanner->context = CONTEXT_AFTER_SPACE;
  }

  // CRITICAL: State cleanup when we don't match anything
  // If scanner was called but we're returning false, something else will parse
  // (likely plain_text). Update context to reflect what we see NOW.
  // This prevents stale context from causing future mismatches.
  else if (iswalnum(lexer->lookahead)) {
    // Next char is alphanumeric - after whatever parses, we'll be AFTER_ALNUM
    scanner->context = CONTEXT_AFTER_ALNUM;
  }
  else if (is_valid_pre_char(lexer->lookahead)) {
    // Next char is a valid PRE char - maintain AFTER_SPACE context
    scanner->context = CONTEXT_AFTER_SPACE;
  }
  // Otherwise keep current context (might be delimiter, special char, etc.)

  return false;
}
