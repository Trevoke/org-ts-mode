# Phase 10 Investigation - Why Scanner PRE Validation Fails

**Date**: 2025-11-12
**Starting Point**: Phase 9 - 145/165 tests (87.9%)
**Attempted Fix**: Add PRE validation using sentinels in scanner
**Result**: FAILED - 27 failures (7 new failures, regression from 20)

## Summary

Attempted to implement PRE character validation in the scanner using the existing sentinel mechanism. The approach was theoretically correct but practically failed because returning `false` from the scanner causes tree-sitter to create ERROR nodes with no recovery mechanism.

## The Attempted Fix

### Code Changes

Added PRE validation to all markup types:

```c
// Check sentinel state
bool after_alnum = valid_symbols[LAST_TOKEN_ALPHANUMERIC];
bool after_whitespace = valid_symbols[LAST_TOKEN_WHITESPACE];

// Bold: *text*
if (valid_symbols[BOLD] && lexer->lookahead == '*') {
  // PRE validation: reject if after alphanumeric
  if (after_alnum) {
    return false; // Invalid PRE, don't parse as bold
  }
  lexer->advance(lexer, false);
  // ... rest of parsing
}
```

Applied same logic to: bold, italic, code, verbatim, strike-through, underline.

### Why It Failed

**The Core Problem**: Scanner Return Value Semantics

When the external scanner returns `false`:
1. Tree-sitter interprets this as "this token is NOT valid at this position"
2. Tree-sitter looks for alternatives in the grammar
3. If no alternatives exist for the current character, creates an ERROR node
4. Parser cannot recover - the input is treated as malformed

**Example Failure**:

Input: `"This is *bold* text."`

Expected parse:
```
- plain_text: "This is "
- text_markup (bold): "*bold*"
- plain_text: " text."
```

Actual parse with PRE validation:
```
- plain_text: "This is "  [0-8]
- ERROR: "*"              [8-9]   ← Scanner returned false
- macro_name: "bold"      [9-13]  ← Tree-sitter tries alternatives
- ERROR: "*"              [13-14]
- macro_name: " text"     [15-19]
- ERROR: "."              [19-20]
```

The scanner was never even called! When plain_text matched "This is " and stopped at `*`, tree-sitter should have tried BOLD. But the parse table didn't consider BOLD valid at that position.

## Root Cause Analysis

### Why Wasn't Scanner Called?

Debug investigation revealed:
- Added `#ifdef DEBUG_SENTINELS` logging to scanner
- Compiled with `-DDEBUG_SENTINELS`
- **NO scanner log output** when parsing `"This is *bold* text."`
- This means: **Scanner was NEVER invoked for the `*` character**

### Parse Table Issue

The problem is in how tree-sitter generates the parse table:

1. **Grammar Structure**:
   ```javascript
   title: $ => repeat1(choice(
     prec(2, $.text_markup),  // Contains bold, italic, etc.
     prec(1, $.plain_text),   // Lower precedence
     // ... other tokens
   ))

   plain_text: $ => choice(
     seq(/[^<{\\\[@*\/~=+_^:\n\s]+/, optional($._last_token_alphanumeric)),
     seq(/[ \t]+/, optional($._last_token_whitespace))
   )
   ```

2. **Plain Text Exclusions**: The regex `[^<{\\\[@*\/~=+_^:\n\s]+` explicitly excludes `*`, so plain_text SHOULD stop before `*`.

3. **Parse Table Generation**: Tree-sitter analyzes the grammar and determines which tokens can follow which. With sentinels, the parse table might not correctly determine that `text_markup` can follow `plain_text`.

### Hypothesis: Sentinel Optionality

The sentinels are marked `optional()` in the grammar:
```javascript
seq(/[^<{\\\[@*\/~=+_^:\n\s]+/, optional($._last_token_alphanumeric))
```

When tree-sitter generates the parse table:
- It considers paths where the optional sentinel is present
- It considers paths where the optional sentinel is absent
- The parse table might become ambiguous or incorrectly structured

**This could explain why the scanner isn't being called** - the parse table doesn't know how to transition from `plain_text` to `text_markup` with sentinels in between.

## Test Results

### Baseline (Phase 9 - without PRE validation)

```bash
$ npm test
20 failures:
✗ Test 133: Simple bold in text  ← Was PASSING
✗ Test 134: Bold at start of line
✗ Test 135: Bold at end of line   ← Was PASSING
... (subscript/superscript failures)
```

Tests 133, 135, 137-139, 141-142 were PASSING.

### With PRE Validation

```bash
$ npm test
27 failures:
✗ Test 133: Simple bold in text  ← NEW FAILURE
✗ Test 134: Bold at start of line
✗ Test 135: Bold at end of line   ← NEW FAILURE
✗ Test 137: Simple italic         ← NEW FAILURE
✗ Test 138: Simple code           ← NEW FAILURE
✗ Test 139: Simple verbatim       ← NEW FAILURE
✗ Test 141: Simple underline      ← NEW FAILURE
✗ Test 142: Simple strike-through ← NEW FAILURE
... (all previous failures still present)
```

**7 NEW failures** - all basic markup tests that were previously working.

## Why This Approach Cannot Work

### Scanner Limitations

The external scanner is called ONLY when:
1. Tree-sitter determines an external token might be valid
2. The parse table allows the transition to that token

If the parse table doesn't allow the transition, **the scanner is never called**, and returning `false` from the scanner is irrelevant.

### GLR Parser Behavior

Tree-sitter uses a GLR (Generalized LR) parser:
- Builds parse table at grammar generation time
- Parse table determines which tokens are valid at each position
- External scanner is optimization for context-sensitive tokens
- But external scanner **cannot override** parse table decisions

### Sentinels Don't Affect Parse Table Correctly

The sentinels are marked as external tokens that are never emitted:
```javascript
externals: $ => [
  // ... other tokens
  $._last_token_alphanumeric,
  $._last_token_whitespace,
]
```

But the parse table generation might not correctly handle:
- Transitions from `plain_text` (with optional sentinel) to `text_markup`
- The optional nature of sentinels creates ambiguity
- Parse table might require sentinel to be explicitly present or absent

## Alternative Approaches

### Approach 1: Remove Optionality from Sentinels (RISKY)

Make sentinels **required** instead of optional:
```javascript
plain_text: $ => choice(
  seq(/[^<{\\\[@*\/~=+_^:\n\s]+/, $._last_token_alphanumeric),  // No optional()
  seq(/[ \t]+/, $._last_token_whitespace)
)
```

**Risk**: This might force tree-sitter to always expect a sentinel, breaking other parts of the grammar.

### Approach 2: Different Grammar Structure (COMPLEX)

Restructure grammar to explicitly handle PRE/POST at grammar level:
```javascript
title: $ => repeat1(choice(
  seq($.pre_char, $.text_markup),  // Markup requires PRE
  $.plain_text
))

pre_char: $ => /[ \t\-\(\{\'\"]/ // PRE characters
```

**Complexity**: Would require major grammar restructuring.

### Approach 3: Focus Only on Subscript vs Underline (TARGETED)

The subscript vs underline case is different because:
- Subscript `_` comes after alphanumeric (H_2O)
- Underline `_` comes after whitespace (_text_)
- Same delimiter, different contexts - this is WHY sentinels exist

Maybe sentinels work for this specific case even if they don't work for general markup.

**Next step**: Test ONLY the subscript logic, ignore general markup PRE validation.

### Approach 4: Manual Context in Scanner (Phase 6 Redux)

Go back to Phase 6 approach:
- Scanner maintains context state
- Updates context after each successful parse
- Uses context instead of sentinels

**Downside**: Phase 6 had limitations, didn't solve all edge cases.

## Recommendation

**Focus on Approach 3**: Test subscript vs underline disambiguation in isolation.

1. Keep baseline scanner (no PRE validation for markup)
2. Add logging ONLY for subscript/underline cases
3. Verify sentinels ARE set correctly for `_` after alphanumeric vs whitespace
4. If sentinels work for subscript, document why they work there but not for general markup
5. Accept that general markup PRE validation may need grammar changes, not scanner changes

## Files Modified (All Reverted)

- `src/scanner.c`: Added PRE validation - REVERTED
- Added `#include <stdio.h>` - REVERTED
- Added debug logging - REVERTED

## Status

- ✅ Attempted PRE validation with sentinels
- ✅ Discovered why it fails (scanner never called)
- ✅ Reverted to Phase 9 baseline: 145/165 tests (87.9%)
- ❌ PRE validation via scanner return value does NOT work
- ⚠️  Need alternative approach

**Conclusion**: Scanner-based PRE validation by returning `false` is fundamentally incompatible with how tree-sitter's parse table works. The sentinels exist and can be checked, but using them to reject tokens causes parse errors. Need to find a way to use sentinels for information WITHOUT rejecting tokens, or restructure the grammar entirely.
