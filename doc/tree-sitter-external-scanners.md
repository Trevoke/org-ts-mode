# Tree-sitter External Scanners

**Source:** https://tree-sitter.github.io/tree-sitter/creating-parsers/4-external-scanners.html

## Overview

External scanners allow handling tokens that resist regular expression description. Many languages have tokens whose structure is impossible or inconvenient to describe with a regular expression, including:

- **Python**: Indent/dedent tokens
- **Bash/Ruby**: Heredocs
- **Ruby**: Percent strings
- **Context-sensitive tokens**: Tokens that depend on indentation or other state

External scanners are a set of C functions that grammar authors can write by hand to add custom logic for recognizing certain tokens.

## When to Use External Scanners

Use external scanners when you need to:

1. Track state across tokens (e.g., indentation levels)
2. Handle context-sensitive lexing
3. Implement tokens that require lookahead beyond what regex can express
4. Handle complex string literals or heredocs
5. Implement indent/dedent tokens for indentation-sensitive languages

## Implementation Guide

### Step 1: Add Externals to Grammar

Add an `externals` section to your `grammar.js` listing the token names:

```javascript
module.exports = grammar({
  name: 'my_language',

  externals: $ => [
    $.indent,
    $.dedent,
    $.newline
  ],

  rules: {
    // Your grammar rules...
  }
});
```

### Step 2: Create Scanner File

Create a file at `src/scanner.c` (this exact path is required for the CLI to recognize it).

Update your build configuration:
- Add to `binding.gyp`
- Update `bindings/rust/build.rs`

### Step 3: Define Token Types

Create an enum matching the `externals` array order:

```c
#include "tree_sitter/parser.h"
#include "tree_sitter/alloc.h"
#include "tree_sitter/array.h"

enum TokenType {
  INDENT,    // Must match order in grammar.js externals
  DEDENT,
  NEWLINE
};
```

**Important**: The enum order must exactly match the order in your grammar's `externals` array.

## Required API Functions

You must implement five functions with specific naming based on your language name. Replace `my_language` with your grammar's name.

### 1. Create Function

```c
void * tree_sitter_my_language_external_scanner_create() {
  // Allocate and initialize scanner state
  // Return NULL if no state is needed
  return ts_calloc(1, sizeof(ScannerState));
}
```

**Purpose**: Initializes the scanner object.

**Timing**: Called once when your language is set on a parser.

**Return**: Pointer to scanner state, or `NULL` if no state management is needed.

### 2. Destroy Function

```c
void tree_sitter_my_language_external_scanner_destroy(void *payload) {
  // Free any allocated memory
  ts_free(payload);
}
```

**Purpose**: Frees any memory used by your scanner.

**Timing**: Called once when a parser is deleted or assigned a different language.

**Note**: Safe to leave empty if `create` didn't allocate anything.

### 3. Serialize Function

```c
unsigned tree_sitter_my_language_external_scanner_serialize(
  void *payload,
  char *buffer
) {
  // Copy the complete state of your scanner into buffer
  // Return the number of bytes written
  ScannerState *state = (ScannerState *)payload;

  if (sizeof(ScannerState) > TREE_SITTER_SERIALIZATION_BUFFER_SIZE) {
    return 0;  // State too large
  }

  memcpy(buffer, state, sizeof(ScannerState));
  return sizeof(ScannerState);
}
```

**Purpose**: Copies the complete state of your scanner into the provided byte buffer.

**Timing**: Called every time the external scanner successfully recognizes a token.

**Constraints**: Maximum buffer size is `TREE_SITTER_SERIALIZATION_BUFFER_SIZE`.

**Return**: Number of bytes written to the buffer.

### 4. Deserialize Function

```c
void tree_sitter_my_language_external_scanner_deserialize(
  void *payload,
  const char *buffer,
  unsigned length
) {
  // Restore scanner state from buffer
  ScannerState *state = (ScannerState *)payload;

  // Recommended: explicitly clear state first
  memset(state, 0, sizeof(ScannerState));

  if (length > 0) {
    memcpy(state, buffer, length);
  }
}
```

**Purpose**: Restores the scanner state from serialized bytes.

**Best Practice**: Explicitly clear state variables before restoration from buffer.

**Parameters**:
- `payload`: Your scanner state pointer
- `buffer`: Serialized state data
- `length`: Number of bytes to read

### 5. Scan Function

```c
bool tree_sitter_my_language_external_scanner_scan(
  void *payload,
  TSLexer *lexer,
  const bool *valid_symbols
) {
  // Contains the custom lexing logic
  // Return true if a token was recognized, false otherwise

  if (valid_symbols[INDENT] || valid_symbols[DEDENT]) {
    // Common logic for related tokens

    if (valid_symbols[INDENT]) {
      // Specific logic for INDENT
      lexer->result_symbol = INDENT;
      return true;
    }

    if (valid_symbols[DEDENT]) {
      // Specific logic for DEDENT
      lexer->result_symbol = DEDENT;
      return true;
    }
  }

  return false;  // No token recognized
}
```

**Purpose**: Contains the core lexing logic.

**Return**:
- `true` if a token was recognized
- `false` if no token matched (allows Tree-sitter's internal lexer to try)

**Parameters**:
- `payload`: Your scanner state pointer
- `lexer`: The TSLexer struct with lexing utilities
- `valid_symbols`: Boolean array indicating which tokens are valid at this position

## The TSLexer Structure

The `TSLexer` struct provides the following fields and functions:

### Fields

#### `int32_t lookahead`

The current character (Unicode code point) being examined.

```c
if (lexer->lookahead == '\n') {
  // Handle newline
}
```

#### `TSSymbol result_symbol`

Assign the recognized token type to this field.

```c
lexer->result_symbol = INDENT;
return true;
```

### Functions

#### `void (*advance)(TSLexer *lexer, bool skip)`

Move to the next character.

**Parameters**:
- `skip`: If `true`, treats current character as whitespace (not part of token)

```c
// Include character in token
lexer->advance(lexer, false);

// Skip whitespace
while (lexer->lookahead == ' ' || lexer->lookahead == '\t') {
  lexer->advance(lexer, true);
}
```

#### `void (*mark_end)(TSLexer *lexer)`

Mark the current position as the end of the token. Subsequent `advance()` calls won't increase the token size.

```c
// Mark end after consuming significant characters
lexer->mark_end(lexer);

// Continue scanning for lookahead without including in token
while (lexer->lookahead == ' ') {
  lexer->advance(lexer, false);
}
```

#### `uint32_t (*get_column)(TSLexer *lexer)`

Get the current column position (number of codepoints from the start of the line).

```c
uint32_t column = lexer->get_column(lexer);
if (column == 0) {
  // At start of line
}
```

#### `bool (*is_at_included_range_start)(const TSLexer *lexer)`

Check if the parser just skipped some characters in the document (useful for multi-language documents).

```c
if (lexer->is_at_included_range_start(lexer)) {
  // We're at the start of a new included range
}
```

#### `bool (*eof)(const TSLexer *lexer)`

Check if we've reached the end of the file.

```c
while (!lexer->eof(lexer)) {
  // Process characters
  lexer->advance(lexer, false);
}
```

**Critical**: Always use `eof()` when looping through characters to prevent infinite loops.

## Scanning Pattern

### Basic Structure

```c
bool tree_sitter_my_language_external_scanner_scan(
  void *payload,
  TSLexer *lexer,
  const bool *valid_symbols
) {
  // Only try to scan tokens that are valid at this position
  if (!valid_symbols[MY_TOKEN]) {
    return false;
  }

  // Implement your scanning logic
  while (lexer->lookahead == ' ') {
    lexer->advance(lexer, true);  // Skip whitespace
  }

  // Check for token pattern
  if (/* pattern matches */) {
    lexer->result_symbol = MY_TOKEN;
    return true;
  }

  return false;
}
```

### Example: Indentation Tracking

```c
typedef struct {
  Array(uint32_t) indent_stack;
} Scanner;

void * tree_sitter_my_language_external_scanner_create() {
  Scanner *scanner = ts_calloc(1, sizeof(Scanner));
  array_init(&scanner->indent_stack);
  array_push(&scanner->indent_stack, 0);  // Start at column 0
  return scanner;
}

bool tree_sitter_my_language_external_scanner_scan(
  void *payload,
  TSLexer *lexer,
  const bool *valid_symbols
) {
  Scanner *scanner = (Scanner *)payload;

  if (valid_symbols[INDENT] || valid_symbols[DEDENT]) {
    uint32_t column = lexer->get_column(lexer);
    uint32_t current_indent = *array_back(&scanner->indent_stack);

    if (valid_symbols[INDENT] && column > current_indent) {
      array_push(&scanner->indent_stack, column);
      lexer->result_symbol = INDENT;
      return true;
    }

    if (valid_symbols[DEDENT] && column < current_indent) {
      array_pop(&scanner->indent_stack);
      lexer->result_symbol = DEDENT;
      return true;
    }
  }

  return false;
}
```

## Helper Utilities

### Memory Allocation

Always use Tree-sitter's allocation functions instead of standard libc functions:

```c
#include "tree_sitter/alloc.h"

void *ptr = ts_malloc(size);
void *ptr = ts_calloc(count, size);
void *ptr = ts_realloc(old_ptr, new_size);
ts_free(ptr);
```

**Why**: Enables custom allocator overrides via `ts_set_allocator`.

### Array Macros

Tree-sitter provides convenient array macros in `tree_sitter/array.h`:

```c
#include "tree_sitter/array.h"

// Declare array type
typedef struct {
  Array(int) indent_levels;
} Scanner;

// Initialize
void * tree_sitter_my_language_external_scanner_create() {
  Scanner *scanner = ts_calloc(1, sizeof(Scanner));
  array_init(&scanner->indent_levels);
  return scanner;
}

// Operations
array_push(&scanner->indent_levels, 4);
int value = *array_back(&scanner->indent_levels);
array_pop(&scanner->indent_levels);
uint32_t len = scanner->indent_levels.size;

// Cleanup
void tree_sitter_my_language_external_scanner_destroy(void *payload) {
  Scanner *scanner = (Scanner *)payload;
  array_delete(&scanner->indent_levels);
  ts_free(scanner);
}
```

**Note**: Avoid underscore-prefixed functions; they're internal helpers.

## Advanced Topics

### Error Recovery Mode

During error recovery, the external scanner is called with all `valid_symbols` set to `true`.

**Options**:
1. Add a sentinel token to detect error recovery mode
2. Return `false` to defer to Tree-sitter's internal lexer

```c
// Check if too many tokens are valid (might be error recovery)
int valid_count = 0;
for (int i = 0; i < TOKEN_COUNT; i++) {
  if (valid_symbols[i]) valid_count++;
}

if (valid_count > EXPECTED_MAX) {
  // Likely in error recovery, be conservative
  return false;
}
```

### External Keywords

When you use literal strings in `externals`:

```javascript
externals: $ => [
  'if',
  'then',
  $.custom_token
]
```

These keywords are tokenized by the external scanner. If these literals don't appear elsewhere in your grammar, the scanner has sole responsibility for recognizing them.

### Scanner Priority

External scanners have priority over normal lexing when their tokens are marked valid. This means if both an external token and a regex-based token could match, the external scanner runs first.

## Critical Warnings

### ⚠️ Infinite Loops

External scanners can easily create infinite loops if not careful:

```c
// DANGEROUS - might loop forever
while (lexer->lookahead != '\n') {
  lexer->advance(lexer, false);
}

// SAFE - always check EOF
while (!lexer->eof(lexer) && lexer->lookahead != '\n') {
  lexer->advance(lexer, false);
}
```

### ⚠️ Zero-Width Tokens

Be careful with tokens that don't consume any characters. They can cause parsing issues.

### ⚠️ Always Use eof()

When looping through characters, always check `lexer->eof(lexer)` to prevent reading beyond the end of the file.

## Complete Example

Here's a complete example for a simple indentation-based language:

```c
#include "tree_sitter/parser.h"
#include "tree_sitter/alloc.h"
#include "tree_sitter/array.h"
#include <string.h>

enum TokenType {
  NEWLINE,
  INDENT,
  DEDENT
};

typedef struct {
  Array(uint16_t) indent_length_stack;
} Scanner;

void * tree_sitter_python_external_scanner_create() {
  Scanner *scanner = ts_calloc(1, sizeof(Scanner));
  array_init(&scanner->indent_length_stack);
  array_push(&scanner->indent_length_stack, 0);
  return scanner;
}

void tree_sitter_python_external_scanner_destroy(void *payload) {
  Scanner *scanner = (Scanner *)payload;
  array_delete(&scanner->indent_length_stack);
  ts_free(scanner);
}

unsigned tree_sitter_python_external_scanner_serialize(
  void *payload,
  char *buffer
) {
  Scanner *scanner = (Scanner *)payload;
  size_t size = scanner->indent_length_stack.size;

  if (size * sizeof(uint16_t) + sizeof(size) > TREE_SITTER_SERIALIZATION_BUFFER_SIZE) {
    return 0;
  }

  memcpy(buffer, &size, sizeof(size));
  memcpy(buffer + sizeof(size), scanner->indent_length_stack.contents,
         size * sizeof(uint16_t));

  return size * sizeof(uint16_t) + sizeof(size);
}

void tree_sitter_python_external_scanner_deserialize(
  void *payload,
  const char *buffer,
  unsigned length
) {
  Scanner *scanner = (Scanner *)payload;
  scanner->indent_length_stack.size = 0;

  if (length > 0) {
    size_t size;
    memcpy(&size, buffer, sizeof(size));
    array_grow(&scanner->indent_length_stack, size);
    scanner->indent_length_stack.size = size;
    memcpy(scanner->indent_length_stack.contents,
           buffer + sizeof(size),
           size * sizeof(uint16_t));
  }

  if (scanner->indent_length_stack.size == 0) {
    array_push(&scanner->indent_length_stack, 0);
  }
}

bool tree_sitter_python_external_scanner_scan(
  void *payload,
  TSLexer *lexer,
  const bool *valid_symbols
) {
  Scanner *scanner = (Scanner *)payload;

  if (valid_symbols[NEWLINE]) {
    lexer->result_symbol = NEWLINE;
    lexer->advance(lexer, false);

    if (lexer->lookahead == '\n') {
      return true;
    }

    if (lexer->lookahead == '\r') {
      lexer->advance(lexer, false);
      if (lexer->lookahead == '\n') {
        return true;
      }
    }
  }

  if (valid_symbols[INDENT] || valid_symbols[DEDENT]) {
    uint16_t indent_length = 0;

    while (!lexer->eof(lexer)) {
      if (lexer->lookahead == ' ') {
        indent_length++;
        lexer->advance(lexer, false);
      } else if (lexer->lookahead == '\t') {
        indent_length += 8;
        lexer->advance(lexer, false);
      } else {
        break;
      }
    }

    uint16_t current_indent = *array_back(&scanner->indent_length_stack);

    if (valid_symbols[INDENT] && indent_length > current_indent) {
      array_push(&scanner->indent_length_stack, indent_length);
      lexer->result_symbol = INDENT;
      return true;
    }

    if (valid_symbols[DEDENT] && indent_length < current_indent) {
      array_pop(&scanner->indent_length_stack);
      lexer->result_symbol = DEDENT;
      return true;
    }
  }

  return false;
}
```

## Tips and Best Practices

1. **Start simple**: Begin with a minimal scanner and add complexity gradually
2. **Test thoroughly**: External scanners are harder to debug than regular grammar rules
3. **Keep state minimal**: Smaller state = easier serialization and debugging
4. **Check valid_symbols**: Always respect the `valid_symbols` array
5. **Handle EOF**: Always check `eof()` in loops
6. **Use mark_end**: When lookahead is needed but shouldn't be part of the token
7. **Debug with prints**: Use `fprintf(stderr, ...)` for debugging scanner behavior
8. **Validate serialization**: Ensure your state fits within `TREE_SITTER_SERIALIZATION_BUFFER_SIZE`

## Common Use Cases

### Indent/Dedent Tokens

Perfect for Python, YAML, Haskell-like languages.

### Heredocs

Handle multi-line string literals with custom delimiters (Bash, Ruby, PHP).

### String Interpolation

Context-sensitive string parsing with embedded expressions.

### Comment Handling

Complex comment structures (nested comments, documentation comments).

### Preprocessor Directives

C-style preprocessor directives that span multiple lines.

## Resources

- Tree-sitter official docs: https://tree-sitter.github.io/tree-sitter/
- Example scanners in tree-sitter org: https://github.com/tree-sitter/
- Tree-sitter Python scanner (good example): https://github.com/tree-sitter/tree-sitter-python/blob/master/src/scanner.c
