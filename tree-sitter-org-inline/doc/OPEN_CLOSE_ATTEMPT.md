# Phase 7: OPEN/CLOSE Architecture Attempt

## Motivation

After Phase 6 achieved 145/165 tests (87.9%) with unified markup tokens, we attempted to adopt markdown's OPEN/CLOSE token architecture to solve the context tracking problem.

## What We Tried

### Architecture Changes

1. **Split external tokens**: Changed from unified tokens (`bold`, `italic`, etc.) to separate OPEN/CLOSE pairs:
   ```javascript
   externals: [
     $.bold_open, $.bold_close,
     $.italic_open, $.italic_close,
     // ... etc
   ]
   ```

2. **Grammar structure**: Changed markup rules from atomic tokens to sequences:
   ```javascript
   // Before (Phase 6):
   text_markup: $ => choice($.bold, $.italic, ...)

   // After (Phase 7):
   bold: $ => seq($.bold_open, optional(/[^\n*]+/), $.bold_close)
   ```

3. **Scanner simplification**: Removed global context tracking, relying on grammar structure to track state between OPEN and CLOSE.

### Scanner Implementation

```c
// Separate helpers for OPEN and CLOSE
static bool try_markup_open(TSLexer *lexer, int32_t delimiter,
                            enum TokenType open_token,
                            const bool *valid_symbols) {
  if (!valid_symbols[open_token]) return false;
  if (lexer->lookahead != delimiter) return false;

  lexer->advance(lexer, false);  // Consume delimiter
  if (iswspace(lexer->lookahead)) return false;  // No leading whitespace

  lexer->mark_end(lexer);
  lexer->result_symbol = open_token;
  return true;
}

static bool try_markup_close(TSLexer *lexer, int32_t delimiter,
                             enum TokenType close_token,
                             const bool *valid_symbols) {
  if (!valid_symbols[close_token]) return false;
  if (lexer->lookahead != delimiter) return false;

  lexer->advance(lexer, false);  // Consume delimiter
  if (!is_valid_post_char(lexer->lookahead)) return false;  // POST validation

  lexer->mark_end(lexer);
  lexer->result_symbol = close_token;
  return true;
}
```

## Problems Encountered

### 1. Content Matching Failure

**Observation**: For input `*x*`:
- Scanner successfully returns BOLD_OPEN for first `*`
- Grammar enters `bold` rule
- Content regex `/[^\n*]+/` should match 'x' at position 1
- **But it doesn't!** Grammar fails to match content and BOLD_CLOSE
- `bold` node ends after just the BOLD_OPEN (1 character)
- Remaining "x*" causes parse errors

**Parse output**:
```
(inline
  (title_only
    (title
      (text_markup
        (bold))  # Only spans position 0-1 (just the first *)
      (plain_text)))  # "x" at position 1-2
  (ERROR))  # Second * at position 2-3
```

### 2. Plain Text Greedy Matching

**Issue**: When content patterns include delimiter characters, plain_text at the title level can match them before the scanner gets a chance to recognize CLOSE tokens.

**Attempted solutions**:
- Used delimiter-specific content patterns: `/[^\n*]+/` for bold, `/[^\n\/]+/` for italic, etc.
- Tried `token.immediate()` to force immediate matching
- Tried `prec.right()` to prioritize CLOSE over content
- Tried `alias()` to create named content nodes

**None worked** - fundamental issue with how content is matched inside the markup rule.

### 3. Test Results

**Before** (Phase 6 - unified tokens): 145/165 (87.9%)
**After** (Phase 7 - OPEN/CLOSE): 138/165 (83.6%)

The refactor **reduced** test pass rate by 4.3%.

## Root Cause Analysis

The problem appears to be a mismatch between how tree-sitter's GLR parser works and what the OPEN/CLOSE architecture requires:

1. **External scanner returns**: When scanner returns BOLD_OPEN, it only consumes the `*` delimiter
2. **Grammar continuation**: Grammar enters `bold` rule and tries to match content with a regex
3. **Regex not matching**: The content regex `/[^\n*]+/` inexplicably fails to match valid content
4. **Parse failure**: Grammar can't complete the `bold` sequence, backs out

**Hypothesis**: There may be a fundamental limitation in how external scanners interact with grammar rules when the external token is the first element of a sequence. The parser might not correctly transition from external scanner parsing to regex matching within the same rule.

## Key Learnings

1. **Markdown comparison isn't apples-to-apples**: Markdown's OPEN/CLOSE architecture works because:
   - Their content rules are more sophisticated
   - They have different precedence handling
   - Their scanner integration might be different

2. **Tree-sitter quirks**: External scanners have subtle interactions with grammar rules that aren't well documented

3. **Phase 6 was actually good**: Getting 87.9% test pass rate with proper PRE/POST validation using unified tokens was a solid achievement

4. **Context tracking limitation is acceptable**: The 20 failing tests (12.1%) in Phase 6 are mostly edge cases involving multiple sequential markup where context is lost

## Recommendation

**Revert to Phase 6 unified token approach** (145/165 tests).

Reasons:
- Higher test pass rate (87.9% vs 83.6%)
- Simpler architecture that actually works
- PRE/POST validation is implemented correctly
- Known limitations are documented and understood
- Remaining failures are acceptable edge cases

## Future Work

If OPEN/CLOSE architecture is revisited:
1. Study tree-sitter-markdown implementation in extreme detail
2. Understand the exact parser state machine behavior with external scanners
3. Consider using tree-sitter's `extras` or other advanced features
4. Possibly need sentinel tokens like markdown's `_last_token_whitespace`
5. May require restructuring how content is represented entirely

## Files Modified in This Attempt

- `grammar.js`: Added OPEN/CLOSE externals, restructured markup rules
- `src/scanner.c`: Simplified state, added try_markup_open/close helpers
- Test results: 138/165 passing (down from 145/165)

**Date**: 2025-11-12
**Status**: Phase 7 exploration complete - recommend revert to Phase 6
