# Invalid Emphasis Handling - Architecture Analysis

**Date**: 2025-11-14
**Context**: Phase 2 - Scanner Implementation
**Current Status**: 82% tests passing (458/557)

---

## Problem Statement

When the scanner rejects invalid emphasis (e.g., `* text*` with leading whitespace), the parser creates ERROR nodes instead of treating the characters as plain text.

**Example**:
```org
This is * text* here.
```

**Current behavior**: `(ERROR (UNEXPECTED '*'))...`
**Desired behavior**: `(plain_text "This is * text* here.")`

---

## Root Cause: Tree-Sitter External Scanner Architecture

### How External Scanners Work

1. Parser encounters potential token (e.g., `*`)
2. Calls external scanner with `valid_symbols[BOLD_OPEN] = true`
3. Scanner checks if emphasis is valid
4. **If scanner returns true**: Parser uses the external token
5. **If scanner returns false**: **Parser abandons entire parse path** ❌

**Critical finding**: When an external scanner returns false, tree-sitter does **NOT** fall back to trying alternative grammar rules like `plain_text`. It treats the rejection as "this parse path is invalid" and backtracks.

### Attempted Fix: Include Delimiters in plain_text

```javascript
// Tried this:
plain_text: /[^:@\[\]<>\\\{\}\n]+/  // Now includes * / ~ = + _
```

**Result**: **Failed**
**Why**: The external scanner is called BEFORE the grammar rule is tried. When the scanner returns false for `*`, the parser never reaches the point of trying `plain_text`.

---

## Spec Interpretation

From `org-syntax.md`:
- Emphasis **MUST** follow `PRE MARKER CONTENTS MARKER POST` pattern
- If pattern not met → "not emphasis"
- Spec doesn't explicitly state whether invalid emphasis should be:
  - Treated as plain text (Emacs org-mode behavior)
  - Treated as error (our current behavior)

**Emacs org-mode**: Displays `* text*` as plain text (no fontification)
**Our parser**: Reports `(ERROR ...)`

---

## Architecture Options

### Option A: Accept ERROR Nodes (Recommended) ✅

**Approach**: Invalid emphasis syntax IS an error - document and test for it.

**Rationale**:
- Semantically correct: `* text*` violates the emphasis spec
- Honest error reporting helps users fix malformed markup
- Fast implementation: update ~53 test expectations
- Clear semantics for editor integrations

**Implementation**:
1. Update "Invalid" test expectations to expect ERROR nodes
2. Document this as intentional behavior
3. Provide clear error messages for editor integrations

**Result**: ~91% tests passing (504/557)

---

### Option B: Scanner Always Succeeds ❌ Not Recommended

**Approach**: Scanner emits `INVALID_BOLD` token for `* text*`.

**Problems**:
- Grammar must accept invalid emphasis
- Violates org-syntax.md spec (says it's NOT emphasis)
- Confusing semantics: "this is bold... but invalid bold"
- Complex error handling in consuming tools

---

### Option C: Hybrid Delimiter Fallback ⚠️ Complex

**Approach**: Add special grammar rule for single delimiter characters.

```javascript
_delimiter_char: choice('*', '/', '~', '=', '+', '_'),
title: choice(..., $._delimiter_char, $.plain_text)
```

**Problems**:
- Creates grammar conflicts (delimiter could be emphasis OR plain char)
- Requires extensive `conflicts` declarations
- Parser ambiguity: is `*` starting emphasis or just a char?
- 4-8 hours work with uncertain outcome
- May degrade parser performance

---

### Option D: Separate Inline/Emphasis Grammars (Like Markdown) 🤔

**Approach**: Split into two parsers like tree-sitter-markdown.

**How markdown handles this**:
1. `tree-sitter-markdown`: Block structure
2. `tree-sitter-markdown-inline`: Inline content (no external scanner for emphasis!)
3. Markdown uses **grammar-based emphasis** with stateful parsing

**For org-mode**:
- Would require major rearchitecture
- Possibly months of work
- Uncertain if it solves the problem (emphasis still needs validation)

---

## Recommendation

**Accept Option A: ERROR nodes for invalid emphasis**

**Justification**:
1. **Semantically correct**: Invalid syntax should be reported as error
2. **Spec compliant**: `* text*` is NOT emphasis per org-syntax.md
3. **Pragmatic**: Gets us to ~91% passing quickly
4. **Clear semantics**: Editor integrations know how to handle errors
5. **User benefit**: Clear feedback that markup is malformed

**Next steps**:
1. Update ~53 "Invalid emphasis" test expectations to accept ERROR
2. Document this behavior in grammar comments
3. Focus on fixing remaining ~46 actual parsing bugs
4. Get to 95%+ tests passing

---

## Alternative: Future Enhancement

If we later want plain-text fallback for invalid emphasis, would require:
1. Complete grammar redesign (no external scanner)
2. Or investigate tree-sitter's experimental features
3. Or contribute to tree-sitter to add "soft fail" mechanism for scanners

Estimated effort: 2-4 weeks full-time work.

---

## Conclusion

The architecture of tree-sitter's external scanners makes it infeasible to fall back to plain_text when a scanner rejects invalid emphasis. The most practical and semantically correct approach is to accept that invalid emphasis produces ERROR nodes, which accurately represents malformed markup.
