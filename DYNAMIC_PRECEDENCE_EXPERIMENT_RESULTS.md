# Dynamic Precedence Experiment Results

## Hypothesis
Can `prec.dynamic()` solve the subscript/underline parsing conflict without requiring an external scanner?

## Implementation

### Changes Made
Modified `tree-sitter-org-inline/grammar.js` to use dynamic precedence hierarchy:

```javascript
title: $ => prec.right(repeat1(choice(
  prec(4, $.plain_link),              // Static high precedence
  prec.dynamic(10, $.text_markup),    // HIGHEST: underline takes priority
  prec.dynamic(5, $.subscript),       // MEDIUM: beats plain_text
  prec.dynamic(5, $.superscript),     // MEDIUM: beats plain_text
  // ... other rules
  prec(1, $.plain_text)               // LOWEST: fallback
)))
```

**Rationale:**
- `text_markup` (including underline) at precedence 10 → highest priority per org-mode spec
- `subscript/superscript` at precedence 5 → middle priority to beat plain_text
- `plain_text` at precedence 1 → lowest priority as fallback

## Test Results

### Summary
**13 tests, 0 passing, 13 failing**

### Detailed Analysis

#### ✓ Test #11: "Subscript at start of title" - **WORKS**
```
Input: "H_2O"
Expected: (subscript)
Actual: (subscript) ✓
```

**Why it works:** Subscript pattern matches from the very beginning of the input.
- Iteration 1: `subscript` matches base="H", "_", script="2O" → complete match
- `plain_text` would also match "H", but subscript wins due to higher precedence

#### ✗ Test #5: "Simple subscript in title" - **FAILS**
```
Input: "Water molecule H_2O notation"
Expected: (plain_text) (subscript) (plain_text)
Actual: (plain_text) (underline MISSING "_") ✗
```

**Why it fails - Parse trace:**
1. **Iteration 1** of `repeat1`:
   - `subscript` tries: base matches "Water", looks for "_", finds " " (space) → FAIL
   - `plain_text` tries: matches "Water molecule H" (stops before "_") → SUCCESS ✓

2. **Iteration 2** - now at "_2O notation":
   - `subscript` tries: base must be alphanumeric, but current char is "_" → FAIL
   - `underline` tries: matches opening "_", content "2O notation", expects closing "_" → NOT FOUND → ERROR

**Root cause:** `plain_text` consumed the base character "H" in iteration 1, so subscript can't match in iteration 2.

#### ✗ Test #4: "Simple superscript in title" - **FAILS**
```
Input: "The formula x^2 is quadratic"
Expected: (plain_text) (superscript) (plain_text)
Actual: (plain_text) (ERROR) ✗
```

**Why it fails:** Same lookahead problem
- `plain_text` matches "The formula x" (stops before "^")
- Superscript can't match "^2" because base "x" was already consumed

## Core Problem Identified

### This is a **Lookahead Problem**, NOT a **Precedence Conflict**

**Precedence works when:**
- Multiple complete parses exist for the same input
- Parser builds both parse trees
- Precedence chooses between them

**Our problem:**
- Parser commits to consuming "H" as part of `plain_text` in iteration 1
- By iteration 2, "H" is gone, so subscript pattern can't match
- No competing complete parses exist → precedence has nothing to resolve

### Visualization

```
Input: "Water molecule H_2O notation"
       └─────────────┘└┘└─┘ └──────┘
           Step 1    │ │ │   Step 3
                     │ │ │
              PROBLEM: H is consumed before
              we know it's part of H_2O
```

**Iteration boundaries in `repeat1(choice(...))`:**
```
Iteration 1: "Water molecule H" → plain_text ✓ (greedy match)
Iteration 2: "_2O notation"     → ? (no base available)
             └─ subscript needs alphanumeric base HERE, but it's gone
```

## Why Dynamic Precedence is Insufficient

### Tree-sitter GLR Parsing Limitations

1. **GLR explores all paths concurrently**, but paths are bounded by token/regex matches
2. **Precedence resolves conflicts** when multiple COMPLETE parses are valid
3. **Cannot "look ahead"** to prevent greedy matching in earlier iterations

### The Missing Piece

To solve this, we need:
- **Context awareness**: Detect "alphanumeric + underscore + content" as a pattern
- **Backward/forward scanning**: Look back to check if preceding char is alphanumeric when seeing "_"
- **Atomic parsing**: Consume "H_2O" as a single unit, not piece by piece

**None of these are possible with pure grammar rules and precedence.**

## Conclusion

### Verdict: ❌ Dynamic Precedence Alone Cannot Solve This Problem

**Why the precedence_experiment.md prediction was correct:**
> "Tree-sitter precedence resolves conflicts when multiple complete parses are valid.
> But with subscript, the issue is:
> - Parser must decide what `(` is **before** seeing `_`
> - It's not a conflict between complete parses
> - It's a **lookahead problem**"

### What We Learned

1. **Dynamic precedence successfully implements "underline takes priority"**
   - When both underline and subscript are valid, underline wins (precedence 10 vs 5)
   - This part works as intended

2. **Dynamic precedence CANNOT prevent plain_text from consuming the base**
   - This is the fundamental blocker
   - No amount of precedence tuning can solve lookahead problems

3. **Position matters:**
   - Subscript/superscript work at start of input (test #11 passes)
   - Subscript/superscript fail mid-text (all other tests fail)

## Next Steps

### Option 1: External Scanner (Recommended)
Implement context-aware scanning in C (see SUBSCRIPT_SUPERSCRIPT_ANALYSIS.md Approach 3)

**Pros:**
- Can look ahead/behind to validate patterns
- Can implement org-mode spec correctly ("underline takes priority")
- Precedent exists (TAGS scanner already works this way)

**Cons:**
- More complex (C code)
- Harder to debug than grammar rules

### Option 2: Restructure Grammar
Completely rethink how subscript/superscript are parsed

**Possible approach:**
- Make `plain_text` exclude alphanumeric chars (only match whitespace/punct)
- Create separate `word` rule for alphanumeric sequences
- Make subscript match `word + _ + script`

**Pros:**
- Pure grammar solution
- No C code needed

**Cons:**
- Major restructuring of inline grammar
- May break other patterns
- Unclear if it solves the problem fully

### Option 3: Accept Limited Support
Keep current block-level subscript/superscript working (8/8 tests pass), document inline limitation

**Pros:**
- No additional work
- Works for standalone subscript/superscript lines

**Cons:**
- Can't use in headlines: `* H_2O molecule structure`
- Can't use mid-text: `The formula x^2 is important`
- Incomplete org-mode support

## Recommendation

**Proceed with Option 1: External Scanner**

### Rationale:
1. Precedent exists (TAGS scanner in same grammar)
2. Org-spec compliance requires context awareness anyway ("underline takes priority")
3. Dynamic precedence experiment confirmed that pure grammar approach is insufficient
4. This is a one-time implementation that enables full org-mode compatibility

### Implementation Plan:
1. Study existing TAGS scanner in `tree-sitter-org-inline/src/scanner.c`
2. Add `SUBSCRIPT_MARKER` and `SUPERSCRIPT_MARKER` to externals
3. Implement scan functions that validate BASE_SCRIPT and BASE^SCRIPT patterns
4. Update grammar to use external markers
5. Test incrementally with existing test suite

## References

- **precedence_experiment.md**: Predicted this outcome ("precedence might not be enough")
- **SUBSCRIPT_SUPERSCRIPT_ANALYSIS.md**: Recommended external scanner (Approach 3)
- **Tree-sitter GLR parsing**: https://tree-sitter.github.io/tree-sitter/creating-parsers#the-grammar-dsl
- **Dynamic precedence docs**: https://tree-sitter.github.io/tree-sitter/creating-parsers#dynamic-precedence
