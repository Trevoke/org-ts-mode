# Test Results Analysis - CORRECTION

**Date**: 2025-11-13
**Analysis**: Based on actual tree-sitter test runs

---

## CRITICAL CORRECTION TO PREVIOUS ANALYSIS

I previously stated **"121/121 tests passing"** for the inline grammar. This was **INCORRECT**.

After running `tree-sitter test` on both grammars, the actual results are:

---

## Actual Test Results

### Block Grammar ✅
```
Total parses: 186
Successful parses: 186
Failed parses: 0
Success percentage: 100.00%
Average speed: 10511 bytes/ms
```

**Status**: ✅ **ALL TESTS PASSING**

---

### Inline Grammar ⚠️
```
Total tests: 159
Passing tests: 141 (88.7%)
Failing tests: 18 (11.3%)
```

**Status**: ⚠️ **18 TESTS FAILING**

---

## Failing Tests Breakdown

### 1. Subscript/Superscript (13 failures) - CRITICAL

**Failing tests**:
- ✗ Simple superscript in title
- ✗ Simple subscript in title
- ✗ Superscript with sign
- ✗ Subscript with comma
- ✗ Superscript with braces
- ✗ Multiple subscripts and superscripts
- ✗ Superscript with asterisk
- ✗ Subscript at start of title
- ✗ Superscript at end of title
- ✗ Subscript vs underline distinction
- ✗ Subscript with single character base
- ✗ Superscript with single character script
- ✗ Subscript with numbers in base

**Root cause**:
- Subscript uses `_` which **conflicts with underline markup** `_text_`
- Parser interprets `H_2O` as underline, not subscript
- Superscript has whitespace/boundary detection issues

**Example failure** (Simple subscript):
```org
H_2O molecule
```

**Expected**:
```
(subscript
  (base "H")
  (script "2"))
(plain_text "O molecule")
```

**Actual**:
```
(underline
  (MISSING "_"))  # Tries to parse as underline, fails
```

**Impact**: **CRITICAL** - This is a fundamental parsing bug, not just missing features

---

### 2. Footnote Parsing (2 failures) - MODERATE

**Failing tests**:
- ✗ Footnote with special characters in label
- ✗ Footnote with link in definition

**Root cause**:
- Footnote definition content not parsed recursively (doesn't allow inline objects)
- Special characters in label not properly escaped

**Example failure** (Footnote with link):
```org
Text with footnote[fn:1:See [[link]]]
```

**Expected**: Link should be parsed inside footnote definition

**Actual**: Link not recognized, ERROR node created

---

### 3. Entity Parsing (1 failure) - LOW

**Failing tests**:
- ✗ Non-breaking space entity

**Root cause**: Non-breaking space entity `\_` has special handling that's not working

---

### 4. Timestamp vs Footnote Ambiguity (1 failure) - MODERATE

**Failing tests**:
- ✗ Inactive timestamp vs footnote reference

**Root cause**: `[2024-01-15]` could be footnote or timestamp - precedence issue

---

### 5. Tag Parsing (1 failure) - LOW

**Failing tests**:
- ✗ Only tags (no title)

**Root cause**: Headlines with tags but empty title not handled

**Example**:
```org
* :tag1:tag2:
```

---

## Impact on Rearchitecture Plan

### Previous Assessment (INCORRECT)
- "121/121 tests passing"
- "Basic implementation working, just needs expansion"

### Corrected Assessment
- **141/159 tests passing (88.7%)**
- **Subscript/superscript fundamentally broken** (13/16 tests fail)
- **Cannot claim inline grammar is "working well"**

---

## Updated Recommendations

### BEFORE Rearchitecture: Fix Broken Features (NEW PHASE)

**Priority 1 - Fix Subscript/Superscript** (CRITICAL):

The subscript/superscript conflict with underline is a **fundamental design issue** that proves the need for context-specific rules.

**Problem**:
```javascript
// Current grammar allows this ambiguity:
_text_     // Could be: underline OR subscript "text" + underscore
H_2O       // Parsed as: underline (broken) instead of subscript
```

**Solution 1 (Quick fix)**: Use precedence to prefer subscript over underline
```javascript
subscript: $ => prec.dynamic(10, seq(
    /[^\s_]/,  // Base (non-whitespace, not underscore)
    '_',
    $._script_content
)),

underline: $ => prec.dynamic(1, seq(  // Lower precedence
    '_',
    /[^_\n]+/,
    '_'
)),
```

**Solution 2 (Proper fix - requires rearchitecture)**: Context-specific rules
- When at word boundary → could be underline
- When after alphanumeric → likely subscript
- Use scanner to disambiguate based on context

**Estimated effort**: 1-2 days (quick fix) or as part of rearchitecture (proper fix)

---

**Priority 2 - Fix Footnote Recursive Parsing** (MODERATE):

Footnote definitions should allow inline objects (links, markup, etc.)

**Current**:
```javascript
footnote_reference: $ => seq(
    '[fn:',
    optional($.label),
    optional(seq(':', /[^\]]+/)),  // Plain regex - no recursion
    ']'
),
```

**Fixed**:
```javascript
footnote_reference: $ => seq(
    '[fn:',
    optional($.label),
    optional(seq(':', repeat1($._inline_element))),  // Allow inline objects
    ']'
),
```

**Estimated effort**: 1 day

---

**Priority 3 - Fix Timestamp/Footnote Precedence** (MODERATE):

Give timestamps higher precedence than footnote references when both match.

**Estimated effort**: 1 hour

---

**Priority 4 - Fix Edge Cases** (LOW):

- Non-breaking space entity
- Empty title with tags

**Estimated effort**: 2-3 hours

---

## Revised Implementation Timeline

### NEW Phase -1: Fix Broken Features (Week 0)
**Before starting rearchitecture, fix the broken tests**

**Tasks**:
1. [ ] Fix subscript/superscript vs underline conflict (1-2 days)
   - Quick fix: Adjust precedence
   - Or: Part of context-specific rules implementation
2. [ ] Fix footnote recursive parsing (1 day)
3. [ ] Fix timestamp/footnote precedence (1 hour)
4. [ ] Fix edge cases (2-3 hours)

**Goal**: Get to **159/159 tests passing** before rearchitecting

**Rationale**:
- Don't build new features on broken foundation
- These bugs prove the need for rearchitecture (especially subscript/superscript conflict)
- Easier to validate rearchitecture if all tests pass first

---

### Then: Original Phase 0-8 (Weeks 1-12)

Follow the original plan from [INLINE_GRAMMAR_REARCHITECTURE_PLAN.md](INLINE_GRAMMAR_REARCHITECTURE_PLAN.md)

---

## Updated Starting Point Recommendation

### Option A: Fix Then Rearchitect (RECOMMENDED)

**Week 0**: Fix broken tests (get to 159/159)
- Provides clean baseline
- Validates that fixes work
- Easier to track regressions

**Week 1+**: Start rearchitecture with all tests passing

**Total timeline**: 13 weeks (1 week fix + 12 weeks rearchitecture)

---

### Option B: Rearchitect With Fixes (ALTERNATIVE)

**Week 1-2**: Start with context-specific rules (Phase 1)
- Fixes subscript/superscript naturally as part of implementation
- Fixes footnote recursion as part of implementation

**Week 3+**: Continue with rest of plan

**Total timeline**: 12 weeks (fixes incorporated into rearchitecture)

**Risk**: Harder to validate - mixing fixes with new features

---

## Key Insights from Test Results

### 1. Subscript/Superscript Conflict Validates Rearchitecture Need

The `_` conflict between subscript and underline is **EXACTLY** the type of problem that context-specific rules solve.

**In markdown**, they handle this with emphasis delimiters by:
- Using scanner to look ahead for matching close
- Using context-specific rules to prevent conflicts
- Disambiguating based on surrounding characters

**We need the same approach** for org-mode's `_` ambiguity.

---

### 2. Recursive Parsing Missing

Footnote definitions don't allow nested inline objects. This proves that **recursive inline parsing** is not fully implemented.

This is easier to fix with proper context-specific rules:
```javascript
footnote_reference: $ => seq(
    '[fn:',
    optional($.label),
    optional(seq(':', repeat1($._inline_element_in_footnote))),  // Context-specific
    ']'
),
```

---

### 3. Precedence Not Systematic

Timestamp vs footnote conflict shows that precedence is ad-hoc, not systematic.

The rearchitecture's **systematic precedence hierarchy** would fix this:
```javascript
const PRECEDENCE = {
    FOOTNOTE_REFERENCE: 12,
    TIMESTAMP: 10,  // Lower precedence - footnote wins
};
```

---

## Corrected Metrics

### Current State (CORRECTED)
- **Block grammar**: 186/186 tests (100%) ✅
- **Inline grammar**: 141/159 tests (88.7%) ⚠️
- **Combined**: 327/345 tests (94.8%)
- **Critical bugs**: Subscript/superscript broken (13/16 tests fail)

### After Fixes (Week 0)
- **Inline grammar**: 159/159 tests (100%) ✅
- **Combined**: 345/345 tests (100%)

### After Rearchitecture (Week 13)
- **Inline grammar**: 300+ tests (100%) ✅
- **Coverage**: 90%+ of org syntax spec
- **All 17 inline object types**: Implemented

---

## Conclusion

**The test results STRENGTHEN the case for rearchitecture**, not weaken it:

1. ✅ **Subscript/superscript conflict** proves we need context-specific rules
2. ✅ **Missing recursive parsing** proves we need better inline object handling
3. ✅ **Precedence issues** prove we need systematic hierarchy
4. ✅ **18 failing tests** prove current implementation is incomplete

**Recommendation**:
- **Fix the 18 failing tests first** (Week 0)
- **Then proceed with rearchitecture** (Weeks 1-12)
- **Total timeline**: 13 weeks

This gives us:
- Clean baseline (all tests passing)
- Validation that fixes work
- Easier to track regressions during rearchitecture
- Proof that current architecture is insufficient (even with fixes)

---

## Action Items

1. **Immediate** (Week 0):
   - [ ] Create branch: `fix-inline-test-failures`
   - [ ] Fix subscript/superscript conflict
   - [ ] Fix footnote recursive parsing
   - [ ] Fix timestamp/footnote precedence
   - [ ] Fix edge cases
   - [ ] Verify all 159 tests pass

2. **Then** (Week 1+):
   - [ ] Create branch: `rearchitect-inline-grammar`
   - [ ] Follow [INLINE_GRAMMAR_REARCHITECTURE_PLAN.md](INLINE_GRAMMAR_REARCHITECTURE_PLAN.md)
   - [ ] Expand to 300+ tests
   - [ ] Implement all 17 object types

---

**End of Corrected Analysis**
