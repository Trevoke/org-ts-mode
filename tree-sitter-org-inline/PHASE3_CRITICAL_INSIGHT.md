# Phase 3 Critical Insight: Apply Bold Pattern to Subscript

## How Bold Works (Phase 2 Success)

```javascript
title: $ => repeat1(choice(
  prec(2, $.bold),       // Higher precedence
  prec(1, $.plain_text), // Lower precedence
)),

bold: $ => token(seq('*', /content/, '*')),  // Atomic

plain_text: $ => choice(
  /[^*\n]+/,  // Text without *
  '*',        // Solo * (when bold doesn't match)
),
```

**Parsing "text *bold* more":**

1. Position 0: Tries bold → starts with 't', not '*' → try plain_text → matches "text "
2. Position 5: Tries bold → starts with '*', scans full pattern `*bold*` → SUCCESS, emits bold
3. Position 11: Tries bold → starts with ' ', not '*' → try plain_text → matches " more"

**Key**: At position 5, BOTH bold and plain_text could match (since plain_text matches '*'). But bold has higher precedence AND succeeds with token(), so it wins.

## Applying to Subscript

**Subscript pattern**: `BASE_SCRIPT` where BASE is alphanumeric

Can we do the same?

```javascript
subscript: $ => token(seq(
  /[a-zA-Z0-9]+/,  // BASE
  '_',
  /script/         // SCRIPT
)),

plain_text: $ => choice(
  /[^a-zA-Z0-9_^\n*]+/,  // Non-alphanumeric
  /[a-zA-Z0-9]+/,        // Alphanumeric
  '_',                   // Solo _
  '^',                   // Solo ^
),
```

**Parsing "text H_2O more":**

1. Position 0: Tries subscript → starts with 't'... checks full pattern `t_???` → no '_' found → try plain_text → matches "text "
2. Position 5: Tries subscript → starts with 'H', scans `H_2O` → SUCCESS, emits subscript!
3. Position 9: Tries subscript → starts with ' ', not alphanumeric → try plain_text → matches " more"

**This should work!**

## But Wait - What About "text" Alone?

**Parsing "text more":**

1. Position 0: Tries subscript → starts with 't'... checks `text ` → looking for '_' after alphanumerics → finds ' ' instead → pattern fails
2. Falls back to plain_text → matches "text "

**Critical**: token() scans entire pattern atomically. If ANY part fails, returns nothing.

So:
- `token(seq(/[a-zA-Z0-9]+/, '_', /script/))` at position with "text " scans "text" then looks for '_', finds ' ', **fails**
- Parser tries plain_text, which matches "text "

## Precedence Handles Overlap

Both subscript and plain_text can start with alphanumeric. But:
- subscript has `prec(2)` - tried first
- plain_text has `prec(1)` - fallback

At each alphanumeric position:
1. Try subscript (atomic token) - if full pattern matches, emit it
2. If subscript fails, try plain_text - match just the word

## Underline vs Subscript Disambiguation

Both can start with alphanumeric before '_':
- Underline: `_text_` - but this starts with `_`, not alphanumeric!
- Subscript: `H_2O` - starts with alphanumeric

Wait, underline pattern is `_text_`, which starts with `_`. So it doesn't conflict with subscript which starts with alphanumeric!

Let's map the patterns:

| Pattern | Starts With | Full Pattern |
|---------|-------------|--------------|
| Bold | `*` | `*content*` |
| Underline | `_` | `_content_` |
| Subscript | alphanumeric | `BASE_SCRIPT` |
| Superscript | alphanumeric | `BASE^SCRIPT` |

**No conflict at starting position!**

- If position is `*` → try bold
- If position is `_` → try underline
- If position is alphanumeric → try subscript AND superscript
- Otherwise → plain_text

## The Full Solution (No Scanner Needed!)

```javascript
title: $ => repeat1(choice(
  prec(3, $.bold),        // * patterns
  prec(3, $.underline),   // _ patterns
  prec(2, $.subscript),   // alphanumeric_script
  prec(2, $.superscript), // alphanumeric^script
  prec(1, $.plain_text),  // fallback
)),

bold: $ => token(seq('*', /[^\s*][^*\n]*[^\s*]|[^\s*\n]/, '*')),

underline: $ => token(seq('_', /[^\s_][^_\n]*[^\s_]|[^\s_\n]/, '_')),

subscript: $ => token(seq(
  /[a-zA-Z0-9]+/,  // BASE
  '_',
  choice(
    '*',                                            // Single asterisk
    seq('{', /[^}\n]+/, '}'),                      // Braced
    seq('(', /[^)\n]+/, ')'),                      // Parenthesized
    /[+-]?[a-zA-Z0-9,.\\]*[a-zA-Z0-9]/            // SIGN CHARS FINAL
  )
)),

superscript: $ => token(seq(
  /[a-zA-Z0-9]+/,  // BASE
  '^',
  choice(
    '*',
    seq('{', /[^}\n]+/, '}'),
    seq('(', /[^)\n]+/, ')'),
    /[+-]?[a-zA-Z0-9,.\\]*[a-zA-Z0-9]/
  )
)),

plain_text: $ => choice(
  /[^a-zA-Z0-9*_^\n]+/,  // Non-word chars
  /[a-zA-Z0-9]+/,        // Words (when not subscript/superscript)
  '*',                   // Solo * (when not bold)
  '_',                   // Solo _ (when not underline/subscript)
  '^',                   // Solo ^ (when not superscript)
),
```

## Wait - Underline vs Subscript Ambiguity

Actually, there IS ambiguity: `A_b`

- Could be: subscript (A with subscript b)
- Could be: underline starting (waiting for closing _)

But they start at DIFFERENT positions:
- Subscript `A_b` starts at position of 'A'
- Underline `_b` starts at position of '_'

So at position of 'A': try subscript → `A_b` matches → emit subscript ✓

The "underline takes priority" rule applies when the pattern is `_text_` which is COMPLETE underline.

Actually, let me re-read the org-mode spec... The phrase is: "emphasis markup takes priority". This means if `_text_` can form emphasis (underline), it should, rather than treating it as subscript start + plain text.

But in our parsing:
- At position of `_`: try underline `_text_`
- If it matches (has closing `_`), emit underline
- If it doesn't match, try subscript (but subscript starts with alphanumeric, not `_`)
- So `_text` (no closing) becomes plain_text '_' + 'text'

For `H_2O`:
- At position of 'H': try subscript `H_2O`
- Matches → emit subscript
- Underline is never tried (it starts with `_`, not 'H')

**No ambiguity in practice!** The patterns have different starting characters.

## Testing the Theory

Let's write tests for these cases:

1. `_text_` → underline ✓
2. `H_2O` → subscript ✓
3. `x^2` → superscript ✓
4. `_incomplete` → plain_text ('_' + 'incomplete') ✓
5. `The _important note_ here` → underline within text ✓
6. `Water H_2O molecule` → subscript within text ✓
7. `Both _text_ and H_2O` → underline + subscript ✓

This should all work with just token() patterns, no scanner needed!

## Why Did Original Implementation Fail?

Looking back at the failed implementation, it tried to use scanner but had issues with space handling (spaces in extras) and coordination between scanner and grammar.

Our approach:
- ✓ No spaces in extras (learned from Phase 2)
- ✓ Atomic tokens with token() (learned from Phase 2)
- ✓ plain_text stops at ALL delimiters
- ✓ Precedence handles ordering
- ✓ No scanner needed for basic subscript/superscript

## Next Step

Implement this and test it!
