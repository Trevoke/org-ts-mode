# Inline Grammar Rebuild Plan

## Status: Current Implementation Broken

**Problem**: 0/13 subscript tests passing, 0/11 markup tests passing
**Root Cause**: Space handling and scanner/regex coordination failures
**Solution**: Systematic rebuild with bounding and incremental testing

## Core Design Principles

### 1. Bounding
Each feature must:
- Have distinctive delimiters when possible
- Fail gracefully (degrade to plain_text)
- Not cascade errors to other elements
- Be independently testable

### 2. Space Handling Strategy

**Decision**: Include spaces in `extras`

```javascript
extras: $ => [' ', '\t', '\n'],
```

**Rationale**:
- Spaces between elements are noise, should be auto-skipped
- Content inside elements (like plain_text) explicitly matches spaces
- Simpler mental model: spaces are invisible between elements
- Follows tree-sitter-markdown precedent

**Trade-off**: Multiple spaces get collapsed. But for org-mode, this is acceptable (org itself normalizes spaces in export).

### 3. Scanner vs Grammar Balance

**Grammar handles**: Structure and distinctive patterns
**Scanner handles**: Context-sensitive disambiguation (underline vs subscript)

Don't over-use scanner. Only use when necessary for disambiguation.

## Phase 1: Plain Text Foundation

### Goals
1. Parse basic text without markup
2. Establish space handling works correctly
3. Create test infrastructure

### Implementation

```javascript
module.exports = grammar({
  name: 'org_inline',

  extras: $ => [' ', '\t', '\n'],  // Auto-skip whitespace

  rules: {
    inline: $ => $.title,

    title: $ => repeat1($.plain_text),

    // Just alphanumeric and common punctuation for now
    plain_text: $ => /[a-zA-Z0-9.,!?;:-]+/,
  }
});
```

### Tests

```
==================
Simple text
==================

Hello world

---

(inline
  (title
    (plain_text)
    (plain_text)))

==================
Text with punctuation
==================

Hello, world! How are you?

---

(inline
  (title
    (plain_text)
    (plain_text)
    (plain_text)
    (plain_text)
    (plain_text)))
```

### Success Criteria
- All Phase 1 tests pass
- Spaces between words are handled automatically
- No ERROR nodes in parse tree

## Phase 2: Simple Markup (Distinctive Delimiters)

### Goals
1. Add bold, italic, code, verbatim, strike
2. Verify bounding: markup failures don't break plain text
3. Verify no cascading: one markup type doesn't break others

### Implementation Strategy

**Key insight**: These all have distinctive delimiters that don't conflict:
- `*` for bold (not used in subscript/superscript)
- `/` for italic (not ambiguous)
- `~` for code (not ambiguous)
- `=` for verbatim (not ambiguous)
- `+` for strike (not ambiguous)

So we can use simple grammar rules without scanner.

```javascript
title: $ => repeat1(choice(
  $.bold,
  $.italic,
  $.code,
  $.verbatim,
  $.strike_through,
  $.plain_text,
)),

bold: $ => seq('*', /[^*\n]+/, '*'),
italic: $ => seq('/', /[^\/\n]+/, '/'),
// ... etc
```

### Org-Mode Spec Compliance

From spec: markup requires:
- Pre-char: Space, -, (, {, ', ", <, or start-of-line
- Post-char: Space, -, ., ,, ;, :, !, ?, ', ), }, [, ", or end-of-line
- Content: Not starting/ending with whitespace

**Phase 2 simplification**: Ignore PRE/POST for now. Just match the delimiters.
**Phase 2.5** (optional): Add PRE/POST validation via scanner.

### Tests

```
==================
Simple bold
==================

This is *bold* text

---

(inline
  (title
    (plain_text)
    (plain_text)
    (bold)
    (plain_text)))

==================
Multiple markup types
==================

*bold* and /italic/ and ~code~

---

(inline
  (title
    (bold)
    (plain_text)
    (italic)
    (plain_text)
    (code)))

==================
Invalid bold (no closing delimiter)
==================

This is *bold without closing

---

(inline
  (title
    (plain_text)
    (plain_text)))

// Note: *bold is treated as plain_text since it doesn't match
```

### Bounding Test

```
==================
Bold doesn't break italic
==================

*bold /italic* mixed/

---

// Should gracefully handle even though this is malformed
// The *bold /italic* won't match bold (contains /)
// So it becomes plain_text
(inline
  (title
    (plain_text)
    (plain_text)))
```

### Success Criteria
- All Phase 2 tests pass
- Invalid markup degrades to plain_text
- Multiple markup types coexist
- No ERROR nodes for valid input

## Phase 3: Complex Markup (Ambiguous Delimiters)

### The Hard Problem: Underline vs Subscript

Both use `_`:
- `_text_` is underline
- `H_2O` is subscript

Org-mode spec says: "underline takes priority"

### Disambiguation Strategy

**Option A: Heuristic-based (current approach)**
- Scanner looks at character after `_`
- Lowercase letter → likely underline
- Digit/brace → likely subscript

**Problems**:
- Heuristics fail: `_A` could be either
- Not spec-compliant: spec doesn't define heuristics

**Option B: Greedy matching with backtracking**
- Always try underline first (since it "takes priority")
- If underline fails (no closing `_`), try subscript
- Use dynamic precedence: underline > subscript

**Implementation**:
```javascript
title: $ => repeat1(choice(
  prec.dynamic(10, $.underline),  // Try first
  prec.dynamic(5, $.subscript),   // Try if underline fails
  $.plain_text,
)),

underline: $ => seq(
  '_',
  /[^\s_][^_\n]*[^\s_]|[^\s_\n]/,  // Content (not starting/ending with space)
  '_'
),

subscript: $ => seq(
  /[a-zA-Z0-9]+/,  // BASE
  '_',
  choice(
    '*',                                      // Single asterisk
    seq('{', /[^}]+/, '}'),                   // Braced
    /[+-]?[a-zA-Z0-9,.\\]+[a-zA-Z0-9]/       // SIGN CHARS FINAL
  )
),
```

**Problem with Option B**: Plain text will consume "H" before subscript gets a chance.

**Option C: Scanner-assisted**
- Scanner emits SUBSCRIPT_MARKER when at `_` followed by subscript pattern
- Scanner emits UNDERLINE_MARKER when at `_` followed by underline pattern
- Grammar uses these markers

```javascript
externals: $ => [
  $.SUBSCRIPT_MARKER,  // Emitted at `_` when BASE_SCRIPT pattern detected
  $.UNDERLINE_MARKER,  // Emitted at `_` when _TEXT_ pattern detected
],

underline: $ => seq(
  alias($.UNDERLINE_MARKER, '_'),
  /[^\s_][^_\n]*[^\s_]|[^\s_\n]/,
  '_'
),

subscript: $ => seq(
  /[a-zA-Z0-9]+/,  // BASE
  alias($.SUBSCRIPT_MARKER, '_'),
  choice(/* script patterns */)
),
```

**Problem with Option C**: Still have the "plain text consumes H" issue.

**Option D: Atomic tokens (like block grammar)**
- Scanner emits entire SUBSCRIPT token: "H_2O"
- Scanner emits entire UNDERLINE token: "_text_"
- Grammar just accepts these as atomic elements

```javascript
externals: $ => [
  $.SUBSCRIPT,
  $.SUPERSCRIPT,
  $.UNDERLINE,
],

subscript: $ => $.SUBSCRIPT,
superscript: $ => $.SUPERSCRIPT,
underline: $ => $.UNDERLINE,
```

Scanner logic:
```c
// At current position, look ahead:
// Does it match BASE_SCRIPT pattern? Emit SUBSCRIPT
// Does it match _TEXT_ pattern? Emit UNDERLINE
// Otherwise return false
```

**Advantage**: Clean separation, scanner handles all ambiguity
**Disadvantage**: Loses parse tree structure (no separate base/script nodes)

### Recommended: Option D (Atomic Tokens)

**Rationale**:
1. **Bounding**: Each element is self-contained
2. **Simplicity**: Grammar is clean, scanner has one job
3. **Precedent**: Block grammar uses this successfully
4. **Spec compliance**: Scanner can implement exact org-mode rules

**Trade-off**: Lose structured parse tree (can't query for "script" separately from "base")
**Mitigation**: Add fields to atomic token if needed, or parse structure in LSP layer

### Phase 3 Implementation

```javascript
module.exports = grammar({
  name: 'org_inline',

  externals: $ => [
    $.UNDERLINE,    // Matches _TEXT_ pattern
    $.SUBSCRIPT,    // Matches BASE_SCRIPT pattern
    $.SUPERSCRIPT,  // Matches BASE^SCRIPT pattern
  ],

  extras: $ => [' ', '\t', '\n'],

  rules: {
    inline: $ => $.title,

    title: $ => repeat1(choice(
      $.bold,
      $.italic,
      $.code,
      $.verbatim,
      $.strike_through,
      $.underline,    // Scanner emits this
      $.subscript,    // Scanner emits this
      $.superscript,  // Scanner emits this
      $.plain_text,
    )),

    bold: $ => seq('*', /[^*\n]+/, '*'),
    italic: $ => seq('/', /[^\/\n]+/, '/'),
    code: $ => seq('~', /[^~\n]+/, '~'),
    verbatim: $ => seq('=', /[^=\n]+/, '='),
    strike_through: $ => seq('+', /[^+\n]+/, '+'),

    underline: $ => $.UNDERLINE,
    subscript: $ => $.SUBSCRIPT,
    superscript: $ => $.SUPERSCRIPT,

    plain_text: $ => /[a-zA-Z0-9.,!?;:-]+/,
  }
});
```

Scanner logic:
```c
bool scan(TSLexer *lexer, const bool *valid_symbols) {
  // Try underline first (priority per spec)
  if (valid_symbols[UNDERLINE]) {
    if (scan_underline(lexer)) {
      return true;
    }
  }

  // Try subscript
  if (valid_symbols[SUBSCRIPT]) {
    if (scan_subscript(lexer)) {
      return true;
    }
  }

  // Try superscript
  if (valid_symbols[SUPERSCRIPT]) {
    if (scan_superscript(lexer)) {
      return true;
    }
  }

  return false;
}

bool scan_underline(TSLexer *lexer) {
  // Pattern: _TEXT_
  // TEXT: non-whitespace start, anything except _, non-whitespace end
  // OR: single non-whitespace char

  if (lexer->lookahead != '_') return false;
  lexer->advance(lexer, false);

  // Must have non-whitespace start
  if (iswspace(lexer->lookahead) || lexer->lookahead == '\n' || lexer->lookahead == 0) {
    return false;
  }

  // Scan content until we find closing _
  bool found_closing = false;
  int32_t last_non_ws = lexer->lookahead;

  while (lexer->lookahead != '\n' && lexer->lookahead != 0) {
    if (lexer->lookahead == '_') {
      // Potential closing
      // Check that we didn't end with whitespace
      if (!iswspace(last_non_ws)) {
        found_closing = true;
        lexer->advance(lexer, false);  // Consume closing _
        break;
      }
    }

    if (!iswspace(lexer->lookahead)) {
      last_non_ws = lexer->lookahead;
    }

    lexer->advance(lexer, false);
  }

  if (!found_closing) {
    return false;  // Tree-sitter resets position
  }

  lexer->mark_end(lexer);
  lexer->result_symbol = UNDERLINE;
  return true;
}

bool scan_subscript(TSLexer *lexer) {
  // Pattern: BASE_SCRIPT
  // BASE: one or more alphanumeric
  // _: underscore
  // SCRIPT: *, {...}, (...), or SIGN CHARS FINAL

  // Must start with alphanumeric
  if (!is_alnum(lexer->lookahead)) {
    return false;
  }

  // Consume BASE
  while (is_alnum(lexer->lookahead)) {
    lexer->advance(lexer, false);
  }

  // Must have underscore
  if (lexer->lookahead != '_') {
    return false;
  }
  lexer->advance(lexer, false);

  // Check: is this actually underline?
  // If next char suggests underline pattern, return false
  // Heuristic: lowercase word after _ suggests underline
  if (is_underline_pattern(lexer)) {
    return false;
  }

  // Validate and consume SCRIPT
  if (!scan_script(lexer)) {
    return false;
  }

  lexer->mark_end(lexer);
  lexer->result_symbol = SUBSCRIPT;
  return true;
}

bool is_underline_pattern(TSLexer *lexer) {
  // After consuming BASE_, we're at the character after _
  // Check if it looks like underline content

  int32_t next = lexer->lookahead;

  // Definite subscript patterns:
  if (next == '{' || next == '(' || next == '*' ||
      (next >= '0' && next <= '9') ||
      next == '+' || next == '-') {
    return false;  // Not underline
  }

  // Lowercase word suggests underline
  if (next >= 'a' && next <= 'z') {
    // But wait: could be H_i (index) which is subscript
    // Need more sophisticated check
    // For now: if it's a single lowercase letter followed by space/EOL, likely subscript (index)
    // If it's multiple lowercase letters, likely underline

    // This is heuristic and imperfect. Better approach:
    // Scan ahead for closing _. If found, it's underline. Otherwise subscript.
    // But scanning ahead is expensive...

    // Compromise: lowercase word of length > 1 suggests underline
    // Single letter suggests subscript (index)
    return is_multi_char_word(lexer);
  }

  // Uppercase letters: ambiguous
  // Could be _CONST_ (underline) or A_B (subscript)
  // Default to underline (per org-mode "underline takes priority")
  if (next >= 'A' && next <= 'Z') {
    return true;  // Treat as underline
  }

  return false;
}
```

### Phase 3 Tests

```
==================
Simple underline
==================

This is _underlined_ text

---

(inline
  (title
    (plain_text)
    (plain_text)
    (underline)
    (plain_text)))

==================
Simple subscript
==================

Water molecule H_2O notation

---

(inline
  (title
    (plain_text)
    (plain_text)
    (subscript)
    (plain_text)))

==================
Underline vs subscript distinction (CRITICAL TEST)
==================

The _underlined text_ and H_2O formula

---

(inline
  (title
    (plain_text)
    (plain_text)
    (underline)
    (plain_text)
    (subscript)
    (plain_text)))

==================
Subscript with single letter index
==================

Variable A_i notation

---

(inline
  (title
    (plain_text)
    (subscript)
    (plain_text)))

==================
Underline with multiple words
==================

This is _underlined text here_ example

---

(inline
  (title
    (plain_text)
    (plain_text)
    (underline)
    (plain_text)))
```

### Edge Cases to Test

```
==================
Space after underscore (not subscript or underline)
==================

H_ O should not match

---

(inline
  (title
    (plain_text)))

==================
No closing underscore (not underline)
==================

This is _incomplete

---

(inline
  (title
    (plain_text)))

==================
Underscore at end (no script)
==================

Variable x_

---

(inline
  (title
    (plain_text)))
```

### Success Criteria
- All Phase 3 tests pass
- Critical "underline vs subscript" test passes
- Edge cases handled gracefully (degrade to plain_text)
- No ERROR nodes for valid input

## Phase 4: Additional Features

Once Phases 1-3 work:
- Links (regular, angle, plain)
- Entities (\alpha)
- Macros ({{{name}}})
- Statistics cookies ([50%])
- Export snippets (@@html:...@@)
- Targets (<<>>>, <<<>>>)
- Tags (:tag1:tag2:)

Each follows same pattern:
1. Define grammar rules
2. Write tests
3. Verify bounding
4. Move to next feature

## Implementation Order

1. Create minimal Phase 1 grammar
2. Write Phase 1 tests
3. Run tests, verify all pass
4. Add Phase 2 features one at a time
5. Write tests for each, verify
6. Add Phase 3 with scanner
7. Write scanner tests
8. Iterate until all pass
9. Add Phase 4 features incrementally

## Success Metrics

- Phase 1: 100% tests passing
- Phase 2: 100% tests passing, no regressions in Phase 1
- Phase 3: 100% tests passing, no regressions in Phase 1-2
- Phase 4: 100% tests passing, no regressions

Current state: 0% passing
Target state: 100% passing with full bounding
