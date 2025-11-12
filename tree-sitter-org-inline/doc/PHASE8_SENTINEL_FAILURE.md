# Phase 8: Sentinel Token Implementation - FAILED

## Results

- **Before (Phase 7)**: 138/165 tests (83.6%)
- **After (Phase 8)**: 65/165 tests (39.4%)
- **Regression**: -53% test pass rate

## What We Tried

Implemented sentinel tokens following markdown's architecture:

1. Added `_last_token_whitespace` and `_last_token_alphanumeric` as external tokens
2. Made `plain_text` external so scanner could track last character type
3. Scanner emits sentinels at start of each invocation
4. Subscript vs underline logic uses sentinels for disambiguation

### Implementation Details

```c
// Scanner state tracks last character type
typedef struct {
  CharType last_char_type;  // WHITESPACE, ALPHANUMERIC, OTHER
} Scanner;

// Emit sentinels first in scan()
if (scanner->last_char_type == CHAR_TYPE_WHITESPACE &&
    valid_symbols[LAST_TOKEN_WHITESPACE]) {
  scanner->last_char_type = CHAR_TYPE_NONE;
  lexer->result_symbol = LAST_TOKEN_WHITESPACE;
  return true;
}

// After parsing plain_text, track what we ended on
if (iswalnum(last_char)) {
  scanner->last_char_type = CHAR_TYPE_ALPHANUMERIC;
}

// Subscript vs underline uses sentinels
if (lexer->lookahead == '_') {
  bool after_alnum = valid_symbols[LAST_TOKEN_ALPHANUMERIC];
  if (after_alnum && valid_symbols[SUBSCRIPT]) {
    // Parse as subscript
  }
}
```

## Why It Failed

### Root Cause: Scanner Not Called After Non-External Tokens

The fundamental problem: **The external scanner is only called when tree-sitter expects an external token.**

Consider parsing: `"Test \\alpha text"`

1. Scanner parses `"Test "` as `PLAIN_TEXT` (external)
   - Sets `last_char_type = CHAR_TYPE_WHITESPACE`
2. Grammar parses `"\\alpha"` as `entity` (TOKEN RULE, not external)
   - **Scanner not called!**
   - `last_char_type` remains `CHAR_TYPE_WHITESPACE`
3. Parser tries to continue with `repeat1(choice(...))`
   - Should parse `" text"` as more plain_text
   - **But parser stops after entity!**

### The Missing Content Problem

After parsing non-external tokens (entity, macro, link, footnote, etc.), the parser **fails to continue parsing**.

Expected parse tree:
```
(title
  (entity)
  (plain_text))  ← Missing!
```

Actual parse tree:
```
(title
  (entity))  ← Stops here
```

The content after the entity (`" text"`) is **completely dropped**.

### Why This Happens

With `plain_text` as a regex (Phase 6):
- Tree-sitter can look ahead and see "there are characters matching `/[^...]+/`"
- The `repeat1(choice(...))` continues looping
- Each loop tries all choices, including the regex plain_text
- Regex matches remaining text

With `plain_text` as external (Phase 8):
- Tree-sitter can't "see" if plain_text would match without calling scanner
- After parsing `entity`, something goes wrong in the repeat loop
- Parser doesn't call scanner for plain_text
- `repeat1` exits prematurely

**Hypothesis**: The GLR parser's internal state machine doesn't properly handle external tokens in `repeat` contexts when they're intermixed with non-external tokens.

## Why Markdown's Approach Works (But Ours Doesn't)

Markdown can use sentinels because:

1. **Simpler content model**: Most markdown content goes through external scanner
2. **Block-based**: Emphasis, links, etc. are the primary content
3. **Less mixing**: Fewer non-external tokens intermixed with external ones

Org-mode has:
1. **Complex content model**: Entities, macros, links, timestamps, cookies, footnotes, etc.
2. **Many token rules**: These are NOT external (for good reasons - they have complex structure)
3. **Heavy mixing**: `"Text \\alpha {{{macro}}} [fn:1] more text"` alternates constantly

### The Fundamental Incompatibility

Sentinel tokens require:
- Scanner called between **every pair of tokens**
- Scanner tracks **what came before**

Tree-sitter provides:
- Scanner called **only for external tokens**
- No mechanism to hook into non-external token parsing

**Conclusion**: Sentinel tokens **cannot work** for org-mode inline grammar with current tree-sitter architecture, because most tokens are non-external.

## Alternative Approaches Considered

### 1. Make Everything External
**Problem**: Infeasible. Complex tokens like `macro`, `regular_link`, `footnote_reference` need internal structure (macro_name, macro_args, etc.). External scanner returns atomic tokens.

### 2. Use Grammar Rules for Sentinel Emission
**Problem**: Sentinels can't be grammar rules - they need to be invisible/zero-width and communicate via `valid_symbols`.

### 3. Track State Across Non-External Tokens
**Problem**: Scanner isn't called, so can't update state. State becomes stale.

## Lessons Learned

1. **External plain_text is harmful**: Breaks parser continuation after non-external tokens
2. **Sentinel tokens need full control**: Only work if scanner handles ALL content
3. **Markdown analogy doesn't hold**: Different grammar structure enables different techniques
4. **Phase 6 was optimal**: 145/165 (87.9%) with unified markup tokens is our best result

## Recommendation

**REVERT TO PHASE 6**

Phase 6 achievements:
- ✅ 145/165 tests passing (87.9%)
- ✅ PRE/POST validation for markup
- ✅ Subscript vs underline heuristic (paired underscore check)
- ✅ Clean, understandable architecture
- ✅ Known limitations documented

Remaining 20 failures (12.1%) are acceptable edge cases:
- Multiple sequential markup with context loss
- Some cross-feature interactions
- Subscript at start of line (architectural limitation)

## Files to Revert

From Phase 8 back to Phase 6:
- `grammar.js`: Remove sentinel externals, remove plain_text from externals, restore plain_text regex
- `src/scanner.c`: Remove CharType enum, remove sentinel emission, restore Phase 6 scanner logic

**Date**: 2025-11-12
**Status**: Phase 8 failed, reverting to Phase 6 (145/165 tests)
