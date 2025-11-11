# Org-Mode Specification: Subscript and Superscript

Extracted from org-mode official syntax: https://orgmode.org/worg/org-syntax.html

## Pattern

**Subscript**: `CHAR_SCRIPT`
**Superscript**: `CHAR^SCRIPT`

## CHAR Definition

**"Any non-whitespace character"**

This is ambiguous in practice because it would make `_text_` a subscript. The spec clarifies with the priority rule below.

## SCRIPT Definition

SCRIPT must be one of these three forms (no whitespace allowed):

### Form 1: Single Asterisk
```
x^*
```

### Form 2: Balanced Delimiters
Curly brackets: `{...}` or parentheses: `(...)`
- Must be balanced
- Can be nested: `x^{y^{z}}`

Examples:
```
x^{y+z}
H_{2}O
A_{i,j}
```

### Form 3: SIGN CHARS FINAL Pattern

Pattern: `[SIGN][CHARS][FINAL]`

- **SIGN**: Optional `+`, `-`, or empty
- **CHARS**: Zero or more of: alphanumeric, comma (`,`), backslash (`\`), dot (`.`)
- **FINAL**: Required alphanumeric character (must end with letter or digit)

Examples:
```
x^2
x^-2
A_i
A_i,j
x^\alpha
```

### Invalid SCRIPT Examples
```
x^          (no script)
x^-         (no FINAL)
x^,         (FINAL must be alphanumeric)
x^ 2        (space not allowed)
```

## Critical Rule: "Underline Takes Priority"

From spec: **"Emphasis markup (_text_) takes priority over subscript"**

This means:
- When `_` could be either underline opener or subscript marker, try underline first
- Only treat as subscript if underline doesn't match

### Disambiguation Examples

| Input | Interpretation | Reason |
|-------|----------------|--------|
| `_text_` | underline | Matched underline pattern |
| `H_2O` | subscript | No closing `_`, so must be subscript |
| `A_i` | subscript | Single letter after `_` |
| `_note_` | underline | Word enclosed in underscores |
| `A_B` | ambiguous | Could be either - spec unclear |

## Context Requirements (PRE/POST)

While not explicitly stated for subscript/superscript in the spec, org-mode emphasis markup requires:

**PRE** (before opening delimiter):
- Whitespace, `-`, `(`, `{`, `'`, `"`, `<`, or start-of-line

**POST** (after closing delimiter):
- Whitespace, `-`, `.`, `,`, `;`, `:`, `!`, `?`, `'`, `)`, `}`, `[`, `"`, or end-of-line

For subscript/superscript, the CHAR requirement ("non-whitespace") serves as implicit PRE validation.

## Whitespace Rules

Content rules:
- **BASE** (CHAR): Must be non-whitespace
- **SCRIPT**: No whitespace allowed within
- Space before SCRIPT is invalid: `H_ 2O` is NOT a subscript
- Space after SCRIPT ends the subscript: `H_2 O` has subscript `H_2`

## Examples from Real Org Documents

### Valid Subscripts
```
H_2O             # Water molecule
x_i              # Index notation
A_{n,m}          # Matrix element
log_2(x)         # Logarithm base 2
x_{\alpha}       # Greek letter subscript
```

### Valid Superscripts
```
x^2              # Square
x^{-1}           # Inverse
e^{i\pi}         # Euler's formula
2^{10}           # Power of 2
x^*              # Conjugate
```

### Underline (NOT Subscript)
```
_text_           # Underlined text
_important note_ # Multi-word underline
```

### Invalid/Ambiguous
```
H_ O             # Space after _ - not subscript
x_               # No SCRIPT - not subscript
_A               # Could be underline or subscript start
A_B              # Ambiguous: subscript or underline fragment
```

## Implementation Strategy

Given the ambiguity and the "underline takes priority" rule, the scanner must:

1. **At `_` character**:
   - Look ahead for closing `_` → if found, emit UNDERLINE
   - Look ahead for subscript SCRIPT pattern → if found, emit SUBSCRIPT
   - Priority: underline first

2. **At `^` character**:
   - Look ahead for superscript SCRIPT pattern → emit SUPERSCRIPT
   - No ambiguity (^ not used for other markup)

3. **Heuristics for `_` ambiguity**:
   - Multiple lowercase letters after `_` → likely underline (`_text_`)
   - Single letter/digit after `_` → likely subscript (`A_i`)
   - Brace/paren after `_` → definitely subscript (`A_{n}`)
   - Sign after `_` → definitely subscript (`x_-1`)

## Edge Cases to Test

```
_text_           # underline ✓
H_2O             # subscript ✓
A_i              # subscript ✓
_a_              # underline (single letter but enclosed)
A_a              # ambiguous - subscript by heuristic
_123             # subscript (digits)
text_text        # plain text if no match
x^2              # superscript ✓
^2               # plain text (no base)
```
