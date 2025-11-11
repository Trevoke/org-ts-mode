# Precedence Experiment: Can it solve "underline takes priority"?

## Question
Can tree-sitter precedence (`prec()` or `prec.dynamic()`) solve the "underline markup takes priority over subscript" rule without an external scanner?

## The Conflict

Input: `(_text_)` should parse as:
- ✅ Underline: `(` + `_text_` + `)`
- ❌ NOT subscript: BASE=`(` + `_` + SCRIPT=`text_)`

## Current Grammar State

```javascript
// Subscript BASE is currently alphanumeric-only
subscript: $ => seq(
  alias(/[a-zA-Z0-9]+/, $.base),  // Restricted pattern
  '_',
  alias(/[^\s\n]+/, $.script)
),
```

**Problem:** This deviates from org-spec which says BASE is "any non-whitespace character".

If we match the spec:
```javascript
subscript: $ => seq(
  alias(/[^\s]+/, $.base),  // Any non-whitespace (per spec)
  '_',
  alias(/[^\s\n]+/, $.script)
),
```

Then `(_text_)` becomes ambiguous.

## Experiments to Try

### Experiment 1: Static Precedence

```javascript
title: $ => prec.right(repeat1(choice(
  prec(10, $.text_markup),    // HIGH - underline should win
  prec(1, $.subscript),       // LOW
  prec(1, $.plain_text)
))),
```

**Hypothesis:** Tree-sitter will prefer underline parse because higher precedence.

**Challenge:** The lookahead problem:
1. Parser sees `(`
2. Doesn't know `_text_` follows yet
3. May commit to `(` as plain_text before seeing full pattern
4. Can't backtrack to make it subscript BASE

**Prediction:** Probably won't work fully, but worth testing.

### Experiment 2: Dynamic Precedence

```javascript
title: $ => prec.right(repeat1(choice(
  prec.dynamic(10, $.text_markup),   // HIGH - runtime preference
  prec.dynamic(1, $.subscript),      // LOW
  prec(1, $.plain_text)
))),
```

**Hypothesis:** `prec.dynamic()` resolves at parse time based on context, might handle lookahead better.

**From tree-sitter docs:**
> "Dynamic precedence is resolved during parsing and can depend on the parse context"

**Prediction:** Better chance than static precedence, but still might hit lookahead issues.

### Experiment 3: Ordering + Precedence

```javascript
// Try underline BEFORE subscript in choice order
title: $ => prec.right(repeat1(choice(
  prec(10, $.text_markup),    // FIRST in order + HIGH precedence
  prec(1, $.subscript),
  prec(1, $.plain_text)
))),
```

**Hypothesis:** Choice order + precedence might give underline first chance to match.

**Prediction:** Tree-sitter uses GLR parsing, so order shouldn't matter much - it explores all paths. But worth testing.

### Experiment 4: Make Subscript More Restrictive

Instead of matching full org-spec, compromise:

```javascript
// Only allow alphanumeric or single special chars as BASE
subscript: $ => seq(
  alias(/[a-zA-Z0-9]|\(|\[/, $.base),  // Limited set
  '_',
  alias(/[^\s\n]+/, $.script)
),
```

**Hypothesis:** Reduce conflict surface - only allow specific special chars that rarely start underlined text.

**Prediction:** Pragmatic but incomplete. Would handle `H_2O` and `x_i` but not all org-spec cases.

## Test Cases

For each experiment, test:

```
Input                   Expected Parse
------                  --------------
H_2O                    subscript (H, 2O)
x_i                     subscript (x, i)
(_text_)                underline (_text_)
(x_2)                   plain_text + subscript OR ambiguous?
_text_                  underline (_text_)
a_b_c                   subscript (a, b) + plain_text OR underline conflict?
```

## Expected Results

My prediction:
- **Experiment 1 (static prec):** Won't fully work due to lookahead
- **Experiment 2 (dynamic prec):** Best chance, but uncertain
- **Experiment 3 (order + prec):** Similar to Experiment 1
- **Experiment 4 (restrictive):** Will work but incomplete spec support

## Why Precedence Might Not Be Enough

Tree-sitter precedence resolves conflicts when:
1. Multiple **complete** parses are valid
2. Parser has built both parse trees
3. Precedence picks the winner

But with subscript, the issue is:
- Parser must decide what `(` is **before** seeing `_`
- It's not a conflict between complete parses
- It's a **lookahead problem**

This is fundamentally different from something like:
```javascript
// Both complete patterns can match "3 + 4"
expression: $ => choice(
  prec(2, $.addition),    // 3 + 4
  prec(1, $.number)       // 3
),
```

Here precedence works because both patterns can match from the start, and precedence picks between complete parses.

## Conclusion

Worth testing Experiment 2 (dynamic precedence), but I'm not optimistic it fully solves the problem.

The fundamental issue is lookahead, which precedence doesn't directly address. External scanner or restrictive patterns (current alphanumeric-only) are more robust solutions.
