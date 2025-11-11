# Subscript/Superscript Implementation Analysis

## Org-Mode Specification

From [orgmode.org/worg/org-syntax.html](https://orgmode.org/worg/org-syntax.html):

### Pattern: `CHAR_SCRIPT` or `CHAR^SCRIPT`

**CHAR:** "Any non-whitespace character"

**SCRIPT** has three valid forms:
1. Single asterisk: `*`
2. Expression in curly brackets `{}` or parentheses `()` with balanced nesting
3. Pattern `SIGN CHARS FINAL` (no whitespace between):
   - SIGN: optional `+`, `-`, or empty
   - CHARS: optional alphanumeric, commas, backslashes, dots
   - FINAL: required alphanumeric character

### Critical Rule: **"Underline markup takes priority"**

Example from spec: `(_text_)` is parsed as underline, **not** subscript.

This means:
- When `_` could be either underline delimiter or subscript marker, choose underline
- Subscript/superscript are only recognized when underline/text markup doesn't match

## Current Implementation Status

### Block Grammar (working)
```javascript
// grammar.js (block level)
subscript: $ => token(seq(
  /[a-zA-Z0-9]+/,  // Base text: alphanumeric word
  '_',             // Underscore separator
  /[^\n]+/         // Script content: anything until newline
)),
```

**Why it works in block grammar:**
- Each subscript is on its own line (block-level element)
- `token()` makes the entire pattern atomic (BASE + `_` + SCRIPT consumed together)
- No ambiguity with surrounding context
- Tests: 8/8 passing

### Inline Grammar (failing)
```javascript
// tree-sitter-org-inline/grammar.js (inline level)
subscript: $ => seq(
  alias(/[a-zA-Z0-9]+/, $.base),  // Base text: alphanumeric word
  '_',                             // Underscore separator
  alias(/[^\s\n]+/, $.script)      // Script content
),
```

**Why it fails in inline grammar:**
- Cannot use `token()` - would prevent base from being parsed as separate plain_text first
- Parser consumes "The formula x" as plain_text, then encounters "^2" with no base
- No distinctive opening delimiter (unlike `[fn:`, `{{{`, etc.)
- Tests: 0/13 passing

## Approach Analysis

### Approach 1: Token() with Atomic Parsing ❌

**Implementation:**
```javascript
subscript: $ => token(seq(/[a-zA-Z0-9]+/, '_', /[^\s\n]+/))
```

**Pros:**
- Simple, clean bounding
- Works in block grammar

**Cons:**
- Doesn't work inline - base must be recognized before we know it's part of subscript
- In "text x^2", parser sees "text x" as potential plain_text before seeing "^"
- Fails all 13 tests

**Verdict:** ❌ Not viable for inline contexts

---

### Approach 2: Regular seq() with High Precedence ❌ (Current)

**Implementation:**
```javascript
title: $ => prec.right(repeat1(choice(
  prec(3, $.subscript),  // Before text_markup
  prec(3, $.text_markup),
  prec(1, $.plain_text)
))),

subscript: $ => seq(
  alias(/[a-zA-Z0-9]+/, $.base),
  '_',
  alias(/[^\s\n]+/, $.script)
),
```

**Pros:**
- Allows base to be parsed contextually
- Follows org-spec priority: underline > subscript

**Cons:**
- Fails because plain_text pattern can still match "x^" before subscript rule applies
- Precedence doesn't help when both patterns start the same way
- Requires plain_text to explicitly exclude alphanumeric-before-`_`/`^`
- Creates complex interdependencies

**Verdict:** ❌ Failed in testing (0/13 tests pass)

---

### Approach 3: External Scanner (Context-Aware) ✅ (Recommended)

**Implementation strategy:**
```c
// Add to externals array
externals: $ => [
  $.TAGS,
  $.SUBSCRIPT_MARKER,    // Emitted when BASE_ pattern detected
  $.SUPERSCRIPT_MARKER   // Emitted when BASE^ pattern detected
],
```

```c
// scanner.c
bool scan_subscript(TSLexer *lexer) {
  // Look backward to verify BASE (alphanumeric before current position)
  // Look forward to verify SCRIPT (valid pattern after _)
  // Validate org-mode rules (not inside underline context)
  // Only emit if all conditions met
}
```

**Pros:**
- Can look backward to check if preceding character is valid BASE
- Can look forward to validate SCRIPT pattern
- Can track context (are we inside underline markup?)
- Respects org-spec: "underline markup takes priority"
- Precedent: Our TAGS scanner already works this way
- Precise bounding - only emits when pattern is valid

**Cons:**
- More complex implementation (C code)
- Requires state tracking for underline context
- Scanner code is harder to debug than grammar rules

**Implementation notes:**
```c
// In scanner.c
enum TokenType {
  TAGS,
  SUBSCRIPT_START,  // Emitted at '_' when pattern valid
  SUPERSCRIPT_START // Emitted at '^' when pattern valid
};

static bool scan_subscript(TSLexer *lexer) {
  // 1. Verify we're at '_' or '^'
  if (lexer->lookahead != '_' && lexer->lookahead != '^') return false;

  // 2. Look backward: verify preceding char is non-whitespace (BASE requirement)
  // Note: Can't actually look backward in tree-sitter, so need different approach

  // ALTERNATIVE: Scanner emits when seeing CHAR + _ pattern
  // Grammar then validates SCRIPT portion
}
```

**Better strategy:**
```javascript
// Grammar provides context, scanner validates
subscript: $ => seq(
  $.base,              // Parsed by grammar
  $._SUBSCRIPT_START,  // External token at '_'
  $.script             // Parsed by grammar
),

// Scanner only emits _SUBSCRIPT_START when:
// - Current char is '_'
// - Next char is valid SCRIPT start (non-whitespace)
// - NOT inside underline context
```

**Verdict:** ✅ Most viable, follows precedent from tree-sitter-markdown emphasis handling

---

### Approach 4: Negative Lookahead in plain_text ⚠️

**Implementation:**
```javascript
// Exclude alphanumeric chars immediately before _ or ^
plain_text: $ => /(?![a-zA-Z0-9][_^])[^*\/~=_+:@\[\]<>\\\{\}\^\n]+/
```

**Pros:**
- Pure grammar solution (no C code)
- Conceptually simple

**Cons:**
- Tree-sitter regex doesn't support full lookahead/lookbehind
- Would need complex negative patterns
- Hard to maintain
- May not respect "underline takes priority" rule

**Verdict:** ⚠️ Limited by tree-sitter regex capabilities

---

### Approach 5: Accept Block-Level Only 🤔

**Implementation:**
Keep current block grammar implementation, don't migrate to inline.

**Pros:**
- Already works (8/8 tests passing in block grammar)
- Simple, no additional complexity
- Covers common use cases (H_2O on its own line)

**Cons:**
- Can't use subscript/superscript in titles: `* H_2O molecule structure`
- Can't use inline: `The formula x^2 is important`
- Incomplete org-mode support

**Verdict:** 🤔 Pragmatic short-term, but incomplete

---

## Recommendation

**Implement Approach 3: External Scanner**

### Rationale:

1. **Precedent exists:** Our inline grammar already uses external scanner for TAGS
2. **Org-spec compliance:** Can implement "underline takes priority" correctly
3. **Clean bounding:** Scanner validates context before emitting token
4. **Similar problems solved:** tree-sitter-markdown likely uses scanner for emphasis

### Implementation Plan:

```c
// tree-sitter-org-inline/src/scanner.c

enum TokenType {
  TAGS,
  SUBSCRIPT_MARKER,   // Emitted at valid _ position
  SUPERSCRIPT_MARKER  // Emitted at valid ^ position
};

typedef struct {
  uint8_t markup_depth;  // Track if we're inside underline markup
} Scanner;

bool scan_subscript_marker(TSLexer *lexer) {
  // Only scan at '_' character
  if (lexer->lookahead != '_') return false;

  // Look ahead: verify next char starts valid SCRIPT
  // (non-whitespace, or '{', or '(')
  lexer->advance(lexer, false);
  if (iswspace(lexer->lookahead)) return false;

  // Emit marker - grammar will parse BASE before, SCRIPT after
  lexer->mark_end(lexer);
  return true;
}
```

```javascript
// tree-sitter-org-inline/grammar.js

externals: $ => [
  $.TAGS,
  $._SUBSCRIPT_MARKER,
  $._SUPERSCRIPT_MARKER
],

subscript: $ => seq(
  $.base,                // Alphanumeric word
  alias($._SUBSCRIPT_MARKER, '_'),  // Scanner-validated marker
  $.script               // Pattern after marker
),

base: $ => /[a-zA-Z0-9]+/,
script: $ => choice(
  '*',                   // Single asterisk
  seq('{', /[^}]+/, '}'),  // Braced expression
  seq('(', /[^)]+/, ')'),  // Parenthesized expression
  /[+-]?[a-zA-Z0-9,.\\]+[a-zA-Z0-9]/  // SIGN CHARS FINAL pattern
),
```

### Testing Strategy:

1. Start with simple cases: `x^2`, `H_2O`
2. Test priority: `_text_` should be underline, not subscript
3. Test complex scripts: `x^{y^{z}}`, `A_i,j`
4. Test edge cases: `x ^2` (space = no subscript), `x_` (no script = no subscript)

### Bounding Properties:

- ✅ **Localized failures:** Invalid subscript falls back to plain text + markers
- ✅ **No cascading:** Underline markup unaffected by subscript parsing
- ✅ **Clear boundaries:** Scanner validates entire context before emitting
- ✅ **Org-spec compliant:** "Underline takes priority" implemented in scanner logic

---

## Alternative: Defer to Future Enhancement

If external scanner implementation proves too complex for current scope:

1. **Keep block-level working** (8/8 tests passing)
2. **Document inline limitation** in SYNTAX_COVERAGE.md
3. **Mark as "partial support"** - works in some contexts
4. **Revisit after LaTeX fragments** migration (similar delimiter challenges)

This maintains systematic progress while acknowledging complexity.
