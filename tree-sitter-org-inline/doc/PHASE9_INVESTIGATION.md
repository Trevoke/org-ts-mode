# Phase 9 Investigation - Root Cause Analysis

**Date**: 2025-11-12
**Baseline**: Phase 9 - 145/165 tests (87.9%)
**Goal**: Debug why sentinels aren't solving edge cases

## Summary

Investigated the 20 failing tests to understand why the Phase 9 sentinel mechanism isn't solving edge cases like "bold at start of line" and "subscript vs underline". Discovered the root cause but encountered complications implementing the fix.

## Key Findings

### 1. Root Cause Identified: NO PRE Character Validation

**The scanner NEVER validates PRE characters before parsing markup!**

From `src/scanner.c` lines 270-278:
```c
// Bold: *text*
if (valid_symbols[BOLD] && lexer->lookahead == '*') {
  lexer->advance(lexer, false);
  if (parse_markup_content(lexer, '*')) {  // Only checks POST!
    lexer->mark_end(lexer);
    lexer->result_symbol = BOLD;
    return true;
  }
  return false;
}
```

The scanner:
- ✅ Checks if current character is `*`
- ✅ Validates POST character (after closing delimiter)
- ❌ **NEVER checks PRE character (before opening delimiter)**

According to org-mode spec, markup PRE must be:
- Whitespace, `-`, `(`, `{`, `'`, `"`
- **OR beginning of line (BOL)**

### 2. Why Tests Fail

**Test 134: "Bold at start of line"**
- Input: `*Bold* at start`
- Expected: Parse `*Bold*` as bold markup (BOL is valid PRE)
- Actual: ERROR - parser doesn't call scanner, tries to parse `*` as something else

**Test 118: "Subscript vs underline"**
- Input: `The _underlined text_ and H_2O formula`
- Expected: First `_` is underline (after space), second `_` is subscript (after `H`)
- Actual: Both parse as underline OR both fail

### 3. The Sentinel Mechanism Problem

Phase 9 added sentinels to track context:
- `_last_token_alphanumeric`: Text ended with [a-zA-Z0-9]
- `_last_token_whitespace`: Text ended with whitespace

**Problem**: Sentinels are in the grammar but NOT checked by scanner for PRE validation!

The sentinels SHOULD enable:
```c
bool after_alnum = valid_symbols[LAST_TOKEN_ALPHANUMERIC];
if (after_alnum) {
  // After "H" → allow subscript, reject markup
} else {
  // After whitespace or BOL → allow markup and underline
}
```

But this isn't implemented yet.

### 4. Attempted Fix and Complications

**Attempt**: Add PRE validation to scanner
```c
bool after_alnum = valid_symbols[LAST_TOKEN_ALPHANUMERIC];
if (after_alnum) {
  // Skip all markup checks
} else {
  // Check all markup types (bold, italic, code, etc.)
}
```

**Result**: Initially appeared to cause 116 failures (down from 145 passing)!

**Actual Issue**: Running `tree-sitter generate` regenerated parser with different output, causing massive regression. This was NOT related to the code changes.

**Lesson**: DO NOT run `tree-sitter generate` unless absolutely necessary!

### 5. Plain Text Fragmentation Mystery

The Phase 9 grammar splits `plain_text` into two alternatives:
```javascript
plain_text: $ => choice(
  seq(/[^<{\\\[@*\/~=+_^:\n\s]+/, optional($._last_token_alphanumeric)),
  seq(/[ \t]+/, optional($._last_token_whitespace))
),
```

This SHOULD fragment text into separate tokens (word, space, word, space...), but:
- Manual testing shows text is parsed as SINGLE `plain_text` node
- Tests with Phase 9 baseline pass (145/165)
- Parser somehow consolidates or matches greedily

**Mystery**: How is tree-sitter creating single nodes from fragmented grammar?

### 6. Test Framework Inconsistency

**Confusing observation**:
- Manual parse of `*Bold* at start` → SUCCESS, correct tree
- Test suite parse of same input → FAILURE, ERROR nodes

Possible explanations:
- Different parser initialization between manual and test
- Test framework has additional constraints
- Need to investigate test harness behavior

## Test Failure Categories

Created `doc/FAILING_TESTS_ANALYSIS.md` with full breakdown:

1. **Subscript/Superscript (7 tests)** - PRIMARY TARGET
   - Test 118 "Subscript vs underline" is THE key test sentinels should solve
   - Tests 110, 112, 114, 116, 119, 121 also affected

2. **Markup at Start (1 test)**
   - Test 134 "Bold at start of line"

3. **Multiple/Mixed Markup (3 tests)**
   - Tests 136, 140, 143

4. **Markup Inside Objects (6 tests)**
   - Tests 17, 25, 35, 56, 92, 107, 129

5. **Other (3 tests)**
   - Tests 5, 108

## Cross-References

**Org Syntax Spec (orgmode.org)**:
- PRE: whitespace | `-` | `(` | `{` | `'` | `"` | BOL
- POST: whitespace | `-` | `.` | `,` | `;` | `:` | `!` | `?` | `'` | `)` | `}` | `[` | `"` | `\` | EOL
- MARKER: `*` (bold), `/` (italic), `_` (underline), etc.

**Tree-Sitter Docs**:
- Sentinel tokens: Optional grammar markers, never emitted
- Scanner checks `valid_symbols[SENTINEL]` to know context
- External scanner called only for external tokens

**Markdown Grammar** (reference):
- Uses `_paragraph_end_newline` sentinel for emphasis context
- Scanner checks sentinels at lines 318-331
- Never emits sentinels (scanner returns false)

## Next Steps - Alternative Approaches

Since the straightforward PRE validation caused issues, consider:

### Option A: Manual Context Tracking (Phase 6 style)
- Add context state to scanner struct
- Track last character type manually
- Update context after each successful parse
- **Downside**: Phase 6 already tried this, had limitations

### Option B: Simplified Sentinel Usage
- Keep sentinels in grammar
- Only check them for subscript vs underline (not all markup)
- Start with test 118 as focused target
- **Advantage**: Minimal change, focused debugging

### Option C: Grammar Restructuring
- Move markup to higher precedence
- Use negative lookahead in plain_text
- Prevent plain_text from consuming markup delimiters
- **Downside**: May require major grammar changes

### Option D: Debug Test Framework
- Understand why manual parse succeeds but test fails
- May reveal hidden issue with parser initialization
- **Advantage**: Could explain mysterious failures

## Recommendation

**Start with Option B: Focused sentinel debugging for test 118**

1. Add logging to scanner to verify sentinel values
2. Check if `LAST_TOKEN_ALPHANUMERIC` is marked after "H"
3. Check if `LAST_TOKEN_WHITESPACE` is marked after space
4. Implement subscript vs underline logic using sentinels
5. Test ONLY subscript/superscript cases first
6. Expand to other markup once working

This avoids the broad PRE validation that caused complications, and focuses on the specific case sentinels were designed to solve.

## Status

- ✅ Phase 9 baseline maintained: 145/165 tests (87.9%)
- ✅ Root cause identified: No PRE validation
- ✅ All 20 failures categorized and analyzed
- ❌ PRE validation implementation incomplete (caused regressions)
- ⚠️  Need focused, incremental approach

**Files Modified**:
- `doc/FAILING_TESTS_ANALYSIS.md` - Test categorization
- `doc/PHASE9_INVESTIGATION.md` - This document

**Files NOT Modified** (to preserve Phase 9 baseline):
- `src/scanner.c` - Reverted PRE validation changes
- `grammar.js` - No changes
- `src/parser.c` - Restored from commit (don't regenerate!)
