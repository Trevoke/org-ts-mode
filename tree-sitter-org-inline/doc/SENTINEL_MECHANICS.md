# How Markdown's Sentinel Tokens Actually Work

## The Critical Misunderstanding (Phases 7-8)

In Phases 7-8, we thought:
- ❌ Scanner **emits** sentinel tokens
- ❌ Sentinels appear in parse tree
- ❌ Need to make plain_text external to emit sentinels

**All of this was WRONG!**

## The Correct Understanding (from markdown source)

### 1. Sentinels are Grammar Markers, Not Tokens

In `tree-sitter-markdown-inline/grammar.js`:

```javascript
_whitespace: $ => seq(
  choice($._whitespace_ge_2, / /),
  optional($._last_token_whitespace)  // <-- Sentinel as OPTIONAL at END
),
```

The sentinel is an **optional token** at the **end of a grammar rule**.

### 2. Sentinels NEVER Get Emitted

In `tree-sitter-markdown-inline/src/scanner.c`:

```c
static bool scan(Scanner *s, TSLexer *lexer, const bool *valid_symbols) {
    // ... handles *, _, `, $, ~ ...
    switch (lexer->lookahead) {
        case '`': return parse_backtick(...);
        case '$': return parse_dollar(...);
        case '*': return parse_star(...);
        case '_': return parse_underscore(...);
        case '~': return parse_tilde(...);
    }
    return false;
}
```

Notice: **NO CODE TO EMIT SENTINELS!** The scanner only handles concrete delimiters.

### 3. Tree-Sitter Tracks Which Tokens Were Valid

When tree-sitter parses a rule like:
```javascript
_whitespace: $ => seq(/ /, optional($._last_token_whitespace))
```

The parse state records: "I just parsed whitespace, and `_last_token_whitespace` was valid here."

This information is available in the `valid_symbols` array on the **next** parse invocation.

### 4. Scanner CHECKS Sentinels to Know Context

In `tree-sitter-markdown-inline/src/scanner.c` (emphasis parsing):

```c
static bool parse_underscore(Scanner *s, TSLexer *lexer, const bool *valid_symbols) {
    // ... consume underscore and count them ...

    // Check what came BEFORE using sentinels:
    if (valid_symbols[EMPHASIS_CLOSE_UNDERSCORE] &&
        !valid_symbols[LAST_TOKEN_WHITESPACE] &&  // <-- CHECKING!
        (!valid_symbols[LAST_TOKEN_PUNCTUATION] ||
         next_symbol_punctuation || next_symbol_whitespace)) {
        // Closing delimiter
        lexer->result_symbol = EMPHASIS_CLOSE_UNDERSCORE;
        return true;
    }

    if (!next_symbol_whitespace &&
        (!next_symbol_punctuation ||
         valid_symbols[LAST_TOKEN_PUNCTUATION] ||  // <-- CHECKING!
         valid_symbols[LAST_TOKEN_WHITESPACE])) {   // <-- CHECKING!
        // Opening delimiter
        lexer->result_symbol = EMPHASIS_OPEN_UNDERSCORE;
        return true;
    }

    return false;
}
```

**Key insight**: The scanner uses `valid_symbols[LAST_TOKEN_*]` to determine what came before, then decides how to parse the current delimiter.

### 5. Sentinels Don't Appear in Parse Tree

Because sentinels are `optional()` in the grammar and never actually get emitted by the scanner, they **never appear in the parse tree**. They're purely a communication mechanism between grammar and scanner.

## How This Solves Subscript vs Underline

For org-mode, we can use the same pattern:

### Grammar Changes

```javascript
// Add sentinels to externals
externals: $ => [
  $.subscript,
  $.superscript,
  // Sentinels (never emitted, only checked)
  $._last_token_alphanumeric,
  $._last_token_whitespace,
]

// plain_text stays as REGEX but ends with sentinel
plain_text: $ => seq(
  /[^<{\\\[@*\/~=+_^:\n]+/,  // The actual text pattern
  optional(choice(
    $._last_token_alphanumeric,  // If ended with [a-zA-Z0-9]
    $._last_token_whitespace      // If ended with whitespace
  ))
)
```

### Scanner Changes

```c
// Scanner NEVER emits sentinels, only checks them
bool tree_sitter_org_inline_external_scanner_scan(...) {
  // When encountering '_'
  if (lexer->lookahead == '_') {
    // Check what came before using sentinels
    bool after_alnum = valid_symbols[LAST_TOKEN_ALPHANUMERIC];
    bool after_space = valid_symbols[LAST_TOKEN_WHITESPACE];

    if (after_alnum && valid_symbols[SUBSCRIPT]) {
      // After alphanumeric → must be subscript
      // Parse H_2O
      lexer->advance(lexer, false);
      if (parse_script(lexer)) {
        lexer->result_symbol = SUBSCRIPT;
        return true;
      }
    }

    if (after_space && valid_symbols[UNDERLINE_OPEN]) {
      // After whitespace → must be underline
      lexer->advance(lexer, false);
      if (!iswspace(lexer->lookahead)) {
        lexer->result_symbol = UNDERLINE_OPEN;
        return true;
      }
    }
  }

  return false;
}
```

## Why This Works (Unlike Phase 8)

**Phase 8 failed because:**
- Made plain_text external → broke parsing after non-external tokens
- Scanner tried to emit sentinels → consumed input incorrectly
- Test pass rate dropped to 39.4%

**This approach works because:**
- ✅ plain_text stays as regex → normal parsing continues
- ✅ Sentinels are just optional flags in grammar
- ✅ Scanner checks flags, doesn't emit them
- ✅ No input is consumed for sentinels
- ✅ Works seamlessly with non-external tokens

## Implementation Requirements

1. **Add sentinels to externals** (but DON'T implement emission!)
2. **Add sentinels as optional at end of plain_text rule**
3. **Scanner checks `valid_symbols[SENTINEL]`** to determine context
4. **Never call `lexer->result_symbol = SENTINEL`** - sentinels are never emitted!

## Key References

- `doc/markdown-inline-grammar.js`: Full markdown grammar with sentinel usage
- `doc/markdown-inline-scanner.c`: Full markdown scanner showing sentinel checking
- Lines 318-331 in scanner.c: Emphasis parsing using sentinels
- Lines 338, 454-457 in grammar.js: Sentinel placement in rules

**Date**: 2025-11-12
**Status**: Correct understanding documented, ready to implement Phase 9
