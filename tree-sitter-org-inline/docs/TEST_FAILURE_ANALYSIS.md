# Test Failure Analysis Report

## Executive Summary

**Total Tests:** 391
**Passing:** 186 (47.6%)
**Failing:** 205 (52.4%)

After comprehensive analysis, the 205 failing tests fall into **3 distinct categories**:

| Category | Count | Root Cause | Fix Required |
|----------|-------|------------|--------------|
| **A: Node Structure Mismatch** | ~150 | Tests expect `text_markup(bold(...))` but parser produces `bold(...)` directly | Update test expectations |
| **B: Wrong Spec Interpretation** | ~30 | Tests expect trailing whitespace to be valid, but spec says invalid | Update test expectations |
| **C: Parser Behavior Issues** | ~25 | Parser produces ERROR nodes or wrong structure | Investigate parser/scanner |

---

## Category A: Node Structure Mismatch (~150 tests)

### The Problem

The grammar defines `text_markup` as a wrapper:
```javascript
text_markup: $ => choice(
  $.bold,
  $.italic,
  $.underline,
  $.code,
  $.verbatim,
  $.strike_through
),
```

But `build_choices_array()` adds `bold`, `italic`, etc. directly to inline elements, NOT `text_markup`:
```javascript
const all_emphasis = ['bold', 'italic', 'underline', 'strike_through'];
choices.push(...allowed_emphasis);
```

### Result

- **Tests expect:** `(text_markup (bold (plain_text)))`
- **Parser produces:** `(bold (plain_text))`

### Affected Test Files

1. `text_markup.txt` - ALL tests (~20)
2. `scanner_pre_post_chars.txt` - ALL PRE/POST tests (~60)
3. `scanner_boundary_validation.txt` - Most tests (~40)
4. `scanner_emphasis_basic.txt` - ALL tests (~15)
5. `nesting_restrictions.txt` - Many tests (~15)

### Fix Options

**Option 1: Update Tests** (Recommended)
- Remove `text_markup` wrapper from all test expectations
- Change `(text_markup (bold ...))` to `(bold ...)`

**Option 2: Update Grammar**
- Change `build_choices_array` to use `'text_markup'` instead of individual emphasis types
- This would require restructuring how emphasis exclusion works

**Recommendation:** Option 1 - simpler, doesn't change parser behavior

---

## Category B: Wrong Spec Interpretation (~30 tests)

### The Problem

Several tests labeled "Invalid" have INCORRECT expectations that contradict the org-mode specification.

### Spec Quote (Lines 1765-1767 of org-syntax.md)

> **CONTENTS:** Either a string (when MARKER represents code or verbatim) or a series of objects from the standard set. **In both cases, CONTENTS may not begin or end with whitespace.**

### Affected Tests

#### Trailing Whitespace Tests (WRONG expectations)

| Test | Input | Test Expects | Spec Says | Correct Expectation |
|------|-------|--------------|-----------|---------------------|
| Invalid: Trailing whitespace in bold | `*bold *` | text_markup ✓ | INVALID | plain_text only |
| Invalid: Multiple spaces trailing in bold | `*bold  *` | text_markup ✓ | INVALID | plain_text only |
| Invalid: Tab trailing in bold | `*bold\t*` | text_markup ✓ | INVALID | plain_text only |
| Invalid: Trailing whitespace in italic | `/italic /` | text_markup ✓ | INVALID | plain_text only |
| Invalid: Trailing whitespace in underline | `_underline _` | text_markup ✓ | INVALID | plain_text only |
| Invalid: Trailing whitespace in strike | `+strike +` | text_markup ✓ | INVALID | plain_text only |
| Invalid: Trailing whitespace in code | `~code ~` | text_markup ✓ | INVALID | plain_text only |
| Invalid: Trailing whitespace in verbatim | `=verbatim =` | text_markup ✓ | INVALID | plain_text only |

#### Leading Whitespace Tests (CORRECT expectations, but wrong actual behavior)

| Test | Input | Test Expects | Parser Produces | Status |
|------|-------|--------------|-----------------|--------|
| Invalid: Leading whitespace in bold | `* bold*` | plain_text | ERROR node | Parser issue |

### Fix Required

1. **Trailing whitespace tests:** Change expectations to `plain_text` only
2. **Leading whitespace tests:** Parser currently produces ERROR - investigate why

---

## Category C: Parser/Scanner Behavior Issues (~25 tests)

### The Problem

Some tests fail because the parser produces ERROR nodes or unexpected structure.

### Sub-categories

#### C1: Beginning-of-Line Emphasis Issues

Tests like "Bold at start of line" show ERROR nodes:
```
*Bold* at start
```
- **Expected:** `(bold (plain_text))`
- **Actual:** `(ERROR) ...` or wrong structure

**Root Cause:** Scanner PRE boundary validation may be incorrectly handling BOL

#### C2: Invalid Leading Whitespace Produces ERROR Instead of Plain Text

```
This is * bold* text.
```
- **Expected:** All plain_text (graceful degradation)
- **Actual:** ERROR node

**Root Cause:** When emphasis fails to match, the `*` should become plain_text via `_delimiter_char`, but something is breaking

#### C3: Title/Tags Edge Cases

```
Title with colon and tags
Title with colon but no tags
```

These involve the title/tags separation logic which has known issues.

---

## Detailed Test-by-Test Analysis

### scanner_boundary_validation.txt

| Line | Test Name | Expected | Actual | Category | Fix |
|------|-----------|----------|--------|----------|-----|
| 2 | Invalid: Leading whitespace in bold | plain_text | ERROR | C | Parser fix |
| 15 | Invalid: Trailing whitespace in bold | text_markup | text_markup | B | Change to plain_text |
| 31 | Invalid: Both leading and trailing | plain_text | plain_text | ✅ | None |
| 44 | Invalid: Multiple spaces leading | plain_text | plain_text | ✅ | None |
| 57 | Invalid: Multiple spaces trailing | text_markup | text_markup | B | Change to plain_text |
| 74 | Invalid: Tab leading | plain_text | plain_text | ✅ | None |
| 87 | Invalid: Tab trailing | text_markup | text_markup | B | Change to plain_text |
| ... | (similar pattern for italic, underline, code, verbatim, strike) | | | | |

### scanner_pre_post_chars.txt

| Line | Test Name | Expected | Actual | Category | Fix |
|------|-----------|----------|--------|----------|-----|
| 2 | PRE: Space before bold | text_markup(bold) | bold | A | Remove text_markup wrapper |
| 18 | PRE: Tab before bold | text_markup(bold) | bold | A | Remove text_markup wrapper |
| 34 | PRE: Hyphen before bold | text_markup(bold) | bold | A | Remove text_markup wrapper |
| ... | (ALL PRE tests) | text_markup(X) | X | A | Remove text_markup wrapper |
| ... | (ALL POST tests) | text_markup(X) | X | A | Remove text_markup wrapper |
| 932 | Invalid PRE: Digit before bold | text_markup | bold or plain | A+? | Verify behavior |
| 949 | Invalid PRE: Right paren before bold | text_markup | ? | B | Spec says invalid |
| 992 | Invalid PRE: Comma before bold | text_markup | ? | B | Spec says invalid |

### text_markup.txt

ALL tests in this file fail due to Category A (node structure mismatch).
- Every test expects `(text_markup (bold/italic/... ...))`
- Parser produces `(bold/italic/... ...)` directly

### nesting_restrictions.txt

Most tests fail due to Category A.
Some tests may have additional issues with nesting logic.

---

## Fix Plan

### Phase 1: Fix Category A (Node Structure) - ~150 tests

**Approach:** Bulk update test expectations

**Script:**
```bash
# For all test corpus files, replace:
# (text_markup\n        (bold -> (bold
# etc.
sed -i 's/(text_markup\n\s*(bold/(bold/g' test/corpus/*.txt
# ... similar for italic, underline, code, verbatim, strike_through
```

**Or manually:** Update each test file to remove `text_markup` wrapper

**Estimated effort:** 1-2 hours

### Phase 2: Fix Category B (Spec Interpretation) - ~30 tests

**Approach:** Update specific tests with wrong expectations

1. **Trailing whitespace tests:** Change from expecting markup to expecting plain_text
2. **Invalid PRE tests:** Verify spec requirements, update expectations accordingly

**Files to update:**
- `scanner_boundary_validation.txt`
- `scanner_pre_post_chars.txt`

**Estimated effort:** 1 hour

### Phase 3: Investigate Category C (Parser Issues) - ~25 tests

**Approach:** Debug and fix parser/scanner

1. **BOL emphasis:** Check scanner PRE validation for beginning-of-line
2. **ERROR instead of plain_text:** Check `_delimiter_char` fallback mechanism
3. **Title/tags:** Known complex area, may need dedicated investigation

**Estimated effort:** 2-4 hours

---

## Priority Recommendation

1. **Do Phase 1 first** - Biggest impact, mechanical fix
2. **Do Phase 2 second** - Align tests with spec
3. **Do Phase 3 last** - Requires deeper investigation

**Expected result after Phase 1+2:** ~180 tests passing (up from 186)
**Expected result after Phase 3:** ~200+ tests passing

---

## Appendix: Spec Reference

### PRE Characters (Valid before opening marker)
- Whitespace (space, tab)
- `-` (hyphen)
- `(` (left paren)
- `{` (left brace)
- `'` (single quote)
- `"` (double quote)
- Beginning of line

### POST Characters (Valid after closing marker)
- Whitespace (space, tab)
- `-` (hyphen)
- `.` (period)
- `,` (comma)
- `;` (semicolon)
- `:` (colon)
- `!` (exclamation)
- `?` (question mark)
- `'` (single quote)
- `)` (right paren)
- `}` (right brace)
- `[` (left bracket)
- `"` (double quote)
- `\` (backslash)
- End of line

### Invalid PRE Characters (NOT listed, therefore invalid)
- Letters (a-z, A-Z)
- Digits (0-9)
- `)` (right paren)
- `}` (right brace)
- `.` (period)
- `,` (comma)
- Most punctuation not in list

### CONTENTS Rules
- May NOT begin with whitespace
- May NOT end with whitespace
- May contain internal whitespace
- For code/verbatim: plain string only
- For bold/italic/underline/strike: can contain other markup (cross-nesting allowed)
