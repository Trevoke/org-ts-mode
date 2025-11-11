# Phase 3 Design: Subscript/Superscript/Underline Disambiguation

## The Hard Problem

Three patterns compete for `_`:
1. **Underline**: `_text_` (emphasis markup)
2. **Subscript**: `H_2O` (chemical formula)  
3. **Plain text**: `_` (when neither pattern matches)

Plus superscript `x^2` which doesn't conflict but has similar structure.

## Org-Mode Spec Rule

**"Underline takes priority"** when ambiguous.

## Phase 2 Success Pattern

Bold works perfectly with:
```javascript
bold: $ => token(seq('*', /content/, '*')),  // Atomic all-or-nothing

plain_text: $ => choice(
  /[^*\n]+/,  // Stop at *
  '*',        // Catch solo *
),
```

**Key insight**: `token()` makes pattern atomic. If doesn't fully match, returns nothing, parser tries plain_text.

## Challenge for Subscript/Superscript

Bold pattern: `*content*` - starts with distinctive `*`
Subscript pattern: `BASE_SCRIPT` - `_` comes AFTER base

Problem: By the time parser sees `_`, the BASE is already consumed as plain_text.

Example: "The formula x^2"
- Parser matches "The formula x" as plain_text
- Sees `^` but base `x` is gone
- Can't form superscript

## Solution 1: Token with Backward Scanning (Block Grammar Approach)

Block grammar uses:
```javascript
subscript: $ => token(seq(/[a-zA-Z0-9]+/, '_', /[^\n]+/))
```

This works because:
- `token()` scans from current position
- Pattern requires alphanumeric at START
- So subscript only matches at word boundaries

For inline, we can do the SAME:
```javascript
subscript: $ => token(seq(
  /[a-zA-Z0-9]+/,  // BASE
  '_',
  // SCRIPT (proper pattern)
  choice(
    '*',
    seq('{', /[^}]+/, '}'),
    seq('(', /[^)]+/, ')'),
    /[+-]?[a-zA-Z0-9,.\\]+[a-zA-Z0-9]/
  )
)),
```

And make plain_text NOT match alphanumeric followed by `_` or `^`:
```javascript
plain_text: $ => choice(
  /[^a-zA-Z0-9_^\n]+/,  // Non-alphanumeric
  /[a-zA-Z0-9]+/,       // Alphanumeric NOT followed by _/^
),
```

Wait, regex can't do negative lookahead in tree-sitter...

## Solution 2: External Scanner

Scanner emits tokens from anywhere in input:

```javascript
externals: $ => [
  $.SUBSCRIPT,    // Emitted when scanner finds BASE_SCRIPT
  $.SUPERSCRIPT,  // Emitted when scanner finds BASE^SCRIPT
  $.UNDERLINE,    // Emitted when scanner finds _TEXT_
]
```

Scanner is called at each position. It checks:
1. Is current position start of alphanumeric? Check for subscript/superscript
2. Is current position start of `_`? Check for underline vs subscript

Actually, looking at the tree-sitter-org-inline scanner.c backup, it already tries this approach!

Let me read it to see what went wrong.
