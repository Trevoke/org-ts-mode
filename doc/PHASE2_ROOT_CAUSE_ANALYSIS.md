# Phase 2 Root Cause Analysis: Why Context Tokens Failed

## Executive Summary

After deep investigation into the markdown grammar pattern and extensive debugging, we discovered a fundamental incompatibility between tree-sitter's grammar evaluation model and our "append optional context token" approach.

**The Core Issue**: Tree-sitter makes `optional($._context_token)` valid **BEFORE** matching the token it's attached to, not AFTER. This breaks the pattern of using context tokens to communicate what was previously matched.

## Timeline of Investigation

### Initial Problem
- Scanner external tokens not being called
- Build configuration missing scanner.c

### First Fixes
- ✅ Added scanner.c to binding.gyp and build.rs
- ✅ Fixed scanner priority (emphasis before TAGS check)
- ✅ Implemented context-based open/close decision logic

### Breakthrough
- Scanner IS being called
- Context tokens ARE becoming valid
- But they're valid at the WRONG time

### Root Cause Discovery

Debug output for input `"*a*"`:

```
1. First "*":
   lookahead='*', TAGS=1, BOLD_OPEN=1, LAST_TOKEN_WS=0
   → At BOL (column 0), ws_before=false → Emits OPEN ✅

2. "a":
   lookahead='a', TAGS=0, BOLD_OPEN=0, LAST_TOKEN_WS=0
   → Matches as plain_text

3. Second "*":
   lookahead='*', TAGS=1, BOLD_OPEN=1, LAST_TOKEN_WS=1  ← WRONG!
   → Just matched plain_text, NOT whitespace!
   → ws_before=true causes wrong decision
```

**The Problem**: After matching "a" as `plain_text`, when we reach the second `*`, tree-sitter reports `LAST_TOKEN_WS=1`. But we didn't match whitespace!

## Why This Happens

### Our Grammar Pattern

```javascript
_whitespace: $ => seq(/[ \t]+/, optional($._last_token_whitespace)),
plain_text: $ => /[^*\/~=+_:@\[\]<>\\\{\}\n\s]+/,

_inline_element_no_bold: $ => choice(
  $.plain_text,
  $._whitespace,
  // ... other elements
),
```

### Tree-Sitter's Evaluation Model

When tree-sitter is deciding what's valid at a parse position:

1. It looks at all possible next tokens
2. For `_whitespace: seq(/[ \t]+/, optional($._last_token_whitespace))`:
   - If whitespace COULD match, it marks BOTH the pattern AND the optional token as "potentially valid"
3. This happens BEFORE actually consuming any input
4. The scanner sees `valid_symbols[LAST_TOKEN_WHITESPACE] = true` even though whitespace wasn't matched yet

This is fundamentally different from "emit a context token AFTER matching":
- **We want**: "I matched whitespace, SO make LAST_TOKEN_WS valid next time"
- **Tree-sitter does**: "Whitespace COULD match, SO LAST_TOKEN_WS is valid right now"

## Why Markdown Works (And We Don't)

### Markdown's Approach

Markdown uses the same pattern but with a different grammar structure:

```javascript
// Line 454 in grammar.js
grammar.rules['_emphasis_star'] = $ => prec.dynamic(
  PRECEDENCE_LEVEL_EMPHASIS,
  seq(
    alias($._emphasis_open_star, $.emphasis_delimiter),
    optional($._last_token_punctuation),  // After OPEN
    $._inline_no_star,
    alias($._emphasis_close_star, $.emphasis_delimiter)
  )
);
```

Key differences:

1. **Scanner State**: Markdown scanner maintains state (`num_emphasis_delimiters_left`, `STATE_EMPHASIS_DELIMITER_IS_OPEN`) to track emphasis nesting
2. **Grammar Structure**: More complex with separate inline content rules for each delimiter type
3. **Multiple Attempts**: Scanner gets called multiple times and uses state to make consistent decisions
4. **Delimiter Runs**: Handles `**` and `***` by tracking how many delimiters are in the run

Our approach tried to be stateless, which doesn't work with tree-sitter's model.

## What We Learned

### Context Tokens Are Not a Silver Bullet

The `optional($._context_token)` pattern works in markdown because:
- Their scanner uses state to track what actually happened
- The grammar structure ensures tokens are checked in the right order
- They handle the lookahead/validity timing carefully

Just copying the pattern without the full infrastructure doesn't work.

### External Scanners Need State

For complex validation like emphasis boundaries, the scanner needs to:
- Track what delimiters are currently open (nesting)
- Remember decisions made for earlier tokens in the parse
- Coordinate with tree-sitter's backtracking and error recovery

Stateless scanners only work for simple token recognition.

### Tree-Sitter's GLR Parser Is Complex

The `valid_symbols[]` array represents:
- Union of all tokens valid across ALL active parse branches
- Preemptive lookahead before matching
- Error recovery states

This makes it hard to use for "what did we just match" style logic.

## Options Going Forward

### Option 1: Full Markdown-Style Implementation (Hard)
**Effort**: 4-8 hours
**Complexity**: High

Changes needed:
- Add scanner state tracking (delimiter stack, nesting depth)
- Restructure grammar with intermediate content rules
- Handle delimiter runs (`, `***`)
- Implement scanner state serialization
- Add comprehensive state management

**Pros**: Could support full org-syntax.md PRE/POST/CONTENTS validation
**Cons**: Very complex, high maintenance burden, may still have edge cases

### Option 2: Revert to Regex-Based Emphasis (Easy)
**Effort**: 30 minutes
**Complexity**: Low

Go back to Phase 1 regex-based approach:
- 159/159 tests passing
- Simple, maintainable
- Doesn't support all org-syntax.md rules but covers 95% of real-world use

**Pros**: Known working, simple, fast
**Cons**: Can't implement full spec, some edge cases won't validate

### Option 3: Hybrid Approach (Medium)
**Effort**: 2-3 hours
**Complexity**: Medium

Keep external scanner but simplify:
- Only validate CONTENTS boundaries (no whitespace after OPEN/before CLOSE)
- Don't try to validate PRE/POST
- Let grammar handle what it can

**Pros**: Some validation, simpler than full implementation
**Cons**: Still incomplete, moderate complexity

## Recommendation

**Revert to regex-based emphasis (Option 2).**

Rationale:
- We spent significant time (4+ hours) exploring the scanner approach
- Discovered fundamental architectural limitations
- The regex approach was working perfectly for all tests
- The additional validation complexity isn't worth the implementation burden
- Users won't notice the difference in 95% of cases

The goal of tree-sitter grammars is to provide good-enough parsing for syntax highlighting and code navigation, not to be a perfect validator. The regex approach achieves this goal well.

## Technical Debt Created

If we proceed with Option 1 (full implementation), document:
- Scanner state structure and serialization format
- Why certain decisions were made
- Test cases specifically for scanner edge cases
- Performance considerations (scanner called frequently)

## Lessons for Future Grammar Work

1. **Start simple**: Regex rules first, external scanner only if absolutely needed
2. **Study complete examples**: Don't just copy patterns, understand the full system
3. **Budget time realistically**: External scanners are 10x more complex than they appear
4. **Test early**: Small test cases reveal issues faster than full corpus
5. **Know when to pivot**: Don't sink cost fallacy - revert if not working

## Conclusion

The markdown context token pattern is sophisticated and relies on scanner state management that we didn't initially account for. Implementing it properly would require significant additional work. Given that the regex-based approach was already working, reverting is the pragmatic choice.
