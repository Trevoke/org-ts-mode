# Subscript/Superscript External Scanner Design

## Goal
Use external scanner to parse subscript/superscript as atomic tokens, solving the lookahead problem that dynamic precedence cannot address.

## Strategy

### Token Approach: Atomic vs. Structured

**Current grammar (FAILS):**
```javascript
subscript: $ => seq(
  alias(/[a-zA-Z0-9]+/, $.base),
  '_',
  alias(/[^\s\n]+/, $.script)
)
```

This creates a structured parse tree: `(subscript (base) (script))`
Problem: `plain_text` consumes base before subscript can match.

**New approach (ATOMIC):**
```javascript
subscript: $ => $.SUBSCRIPT  // External token - atomic
```

This creates: `(subscript)` - single atomic node
Similar to `footnote_reference`, `timestamp`, etc. in inline grammar.

### Scanner Responsibilities

1. **Detect subscript pattern:** `BASE_SCRIPT` where:
   - BASE: one or more alphanumeric characters
   - _: underscore marker
   - SCRIPT: valid script content (see below)

2. **Detect superscript pattern:** `BASE^SCRIPT`

3. **Validate SCRIPT content** per org-mode spec:
   - Single asterisk: `*`
   - Braced expression: `{...}` with balanced braces
   - Parenthesized expression: `(...)` with balanced parens
   - SIGN CHARS FINAL: `[+-]?[a-zA-Z0-9,.\\]*[a-zA-Z0-9]`

4. **Implement "underline takes priority":**
   - If pattern is `_text_` (opening and closing underscore), it's underline markup
   - Scanner should NOT emit SUBSCRIPT in this case
   - Return false to let text_markup match

5. **Bounding:** Invalid patterns return false without consuming anything

## Validation Algorithm

### For Subscript (_)

```c
bool scan_subscript(TSLexer *lexer) {
    // 1. Verify we're at alphanumeric character (BASE start)
    if (!is_alnum(lexer->lookahead)) {
        return false;
    }

    // 2. Consume BASE (one or more alphanumeric)
    int base_len = 0;
    while (is_alnum(lexer->lookahead)) {
        lexer->advance(lexer, false);
        base_len++;
    }

    // 3. Check for underscore marker
    if (lexer->lookahead != '_') {
        return false;  // Not a subscript
    }
    lexer->advance(lexer, false);  // Consume '_'

    // 4. Check for "underline takes priority" case
    // If next char is non-whitespace and we can find closing '_', it's underline
    if (!iswspace(lexer->lookahead) && has_closing_underscore(lexer)) {
        return false;  // Let underline match instead
    }

    // 5. Validate and consume SCRIPT
    if (!scan_script(lexer)) {
        return false;  // Invalid script pattern
    }

    // 6. Success - emit SUBSCRIPT token
    lexer->mark_end(lexer);
    lexer->result_symbol = SUBSCRIPT;
    return true;
}
```

### Underline Detection

```c
bool has_closing_underscore(TSLexer *lexer) {
    // Look ahead to see if there's a closing underscore
    // Pattern: _content_ where content doesn't start/end with whitespace

    // Skip first character (must be non-whitespace for underline)
    if (iswspace(lexer->lookahead)) {
        return false;  // Underline can't start with whitespace
    }

    // Scan ahead looking for closing '_'
    // Stop at: whitespace, newline, or maximum lookahead distance
    int lookahead_distance = 0;
    const int MAX_LOOKAHEAD = 100;  // Reasonable limit

    while (lookahead_distance < MAX_LOOKAHEAD) {
        if (lexer->lookahead == '_') {
            // Found potential closing underscore
            // Check that previous char wasn't whitespace
            // (we can't look backward in tree-sitter scanner)
            // So we need to track this as we scan
            return true;
        }

        if (lexer->lookahead == '\n' || lexer->lookahead == 0) {
            return false;  // Hit end without finding closing '_'
        }

        lexer->advance(lexer, false);
        lookahead_distance++;
    }

    return false;  // Didn't find closing underscore in reasonable distance
}
```

**Problem with above:** Tree-sitter lexer advances are destructive - we can't "peek ahead" without consuming. We need a different approach.

### Better Underline Detection

Since we can't look ahead without consuming, we use heuristics:

```c
bool looks_like_underline(TSLexer *lexer) {
    // Heuristic: If immediate next char is lowercase letter, likely underline
    // Examples: "_text_", "_foo_"
    // Not underline: "_2O", "_i", "_123"
    //
    // This is imperfect but covers common cases
    // Org-mode spec says "underline takes priority" but doesn't define
    // how to disambiguate in all cases

    int32_t next = lexer->lookahead;

    // Common underline patterns:
    // - Lowercase word: _text_
    // - Multiple words: _some text_
    if (next >= 'a' && next <= 'z') {
        // Likely underline - lowercase words are typically underlined
        return true;
    }

    // Subscript patterns:
    // - Numbers: _2, _123
    // - Single letter: _i, _x
    // - Braced: _{...}
    // - Asterisk: _*
    if ((next >= '0' && next <= '9') ||
        next == '{' || next == '(' || next == '*') {
        return false;  // Definitely subscript
    }

    // Ambiguous: single uppercase letter "_N"
    // Could be subscript or underline
    // Org-mode convention: subscripts are usually lowercase (H_2O, x_i)
    // Treat uppercase as potential underline
    if (next >= 'A' && next <= 'Z') {
        return true;  // Likely underline
    }

    return false;
}
```

### SCRIPT Validation

```c
bool scan_script(TSLexer *lexer) {
    int32_t first = lexer->lookahead;

    // Case 1: Single asterisk
    if (first == '*') {
        lexer->advance(lexer, false);
        // Check that asterisk is followed by space/EOL (not more content)
        if (iswspace(lexer->lookahead) || lexer->lookahead == '\n' ||
            lexer->lookahead == 0) {
            return true;
        }
        return false;  // Asterisk followed by more content - invalid
    }

    // Case 2: Braced expression {...}
    if (first == '{') {
        return scan_balanced(lexer, '{', '}');
    }

    // Case 3: Parenthesized expression (...)
    if (first == '(') {
        return scan_balanced(lexer, '(', ')');
    }

    // Case 4: SIGN CHARS FINAL pattern
    // Optional sign
    if (first == '+' || first == '-') {
        lexer->advance(lexer, false);
    }

    // One or more: alphanumeric, comma, backslash, dot
    int char_count = 0;
    while (is_alnum(lexer->lookahead) ||
           lexer->lookahead == ',' ||
           lexer->lookahead == '\\' ||
           lexer->lookahead == '.') {
        lexer->advance(lexer, false);
        char_count++;
    }

    // Must have at least one character
    if (char_count == 0) {
        return false;
    }

    // Must end with alphanumeric (FINAL requirement)
    // Check by looking at what terminated the loop
    // If we hit whitespace/EOL, the last char was valid FINAL
    if (iswspace(lexer->lookahead) || lexer->lookahead == '\n' ||
        lexer->lookahead == 0) {
        return true;
    }

    return false;  // Ended with non-alphanumeric
}

bool scan_balanced(TSLexer *lexer, char open, char close) {
    int depth = 1;
    lexer->advance(lexer, false);  // Consume opening bracket

    while (depth > 0 && lexer->lookahead != '\n' && lexer->lookahead != 0) {
        if (lexer->lookahead == open) {
            depth++;
        } else if (lexer->lookahead == close) {
            depth--;
        }
        lexer->advance(lexer, false);
    }

    return depth == 0;  // Successfully balanced
}
```

## Grammar Changes

### Externals Array

```javascript
externals: $ => [
  $.TAGS,
  $.SUBSCRIPT,
  $.SUPERSCRIPT
],
```

### Grammar Rules

```javascript
subscript: $ => $.SUBSCRIPT,
superscript: $ => $.SUPERSCRIPT,
```

### Test Expectations

Tests expect atomic tokens:
```
(inline
  (title_only
    (title
      (subscript))))
```

NOT structured:
```
(subscript (base) (script))  // ← We don't create this anymore
```

## Bounding Properties

1. **Invalid base:** If no alphanumeric at current position → return false immediately
2. **Missing marker:** If base not followed by _ or ^ → return false, BASE is consumed by plain_text
3. **Invalid script:** If script validation fails → return false, let other rules try
4. **Underline priority:** If pattern looks like underline → return false, let text_markup match
5. **Isolation:** Subscript/superscript failures don't affect other inline elements

**Wait - Issue with point #2:** If we consume BASE and then find no marker, we can't "unconsume" the BASE. This is a problem.

### Solution: Lookahead Before Committing

```c
bool scan_subscript(TSLexer *lexer) {
    // 1. Must start with alphanumeric
    if (!is_alnum(lexer->lookahead)) {
        return false;
    }

    // 2. Scan BASE to find its length
    int base_len = 0;
    while (is_alnum(peek_ahead(lexer, base_len))) {
        base_len++;
    }

    // 3. Check if underscore follows BASE
    if (peek_ahead(lexer, base_len) != '_') {
        return false;  // No underscore - not a subscript
    }

    // 4. NOW we know it's a subscript pattern - start consuming
    // ... rest of validation
}
```

**Problem:** TSLexer doesn't have `peek_ahead()` - we can only advance.

### Alternative: Accept that some matches will fail

If we consume BASE and then don't find _, that's a parse error. The user's input is invalid. This is actually okay - it's bounded to just this token, doesn't cascade.

Actually, looking at how the scanner is called: it's only called when `valid_symbols[SUBSCRIPT]` is true. That means the grammar is specifically looking for a subscript at this position. If we return false, the grammar will try other rules.

So the flow is:
1. Grammar tries `subscript` rule → calls scanner
2. Scanner checks if current position is valid subscript
3. If no: return false → grammar tries next rule (e.g., plain_text)
4. If yes: consume and return true → grammar accepts subscript

This means we DON'T consume anything if we return false. The scanner shouldn't advance lexer if validation fails.

Let me reconsider the algorithm with this understanding...

## Revised Algorithm: Non-Destructive Validation

```c
bool scan_subscript(TSLexer *lexer) {
    // Strategy: Scan forward, but only call mark_end() if fully valid
    // If invalid, parser will reset position automatically

    // 1. Must start with alphanumeric
    if (!is_alnum(lexer->lookahead)) {
        return false;  // Not subscript - no advance made
    }

    // 2. Consume BASE
    while (is_alnum(lexer->lookahead)) {
        lexer->advance(lexer, false);
    }

    // 3. Must have underscore
    if (lexer->lookahead != '_') {
        return false;  // Parser will reset - base not consumed
    }
    lexer->advance(lexer, false);

    // 4. Check for underline pattern
    if (looks_like_underline(lexer)) {
        return false;  // Let underline match
    }

    // 5. Validate script
    if (!scan_script(lexer)) {
        return false;  // Invalid script
    }

    // 6. Success!
    lexer->mark_end(lexer);
    lexer->result_symbol = SUBSCRIPT;
    return true;
}
```

**Key insight:** When we return false, tree-sitter automatically resets the lexer position. We don't need to manually "unconsume". This makes the implementation much simpler!

## Implementation Plan

1. ✓ Design validation logic (this document)
2. Add SUBSCRIPT, SUPERSCRIPT to enum in scanner.c
3. Implement scan_subscript() and helper functions
4. Update externals array in grammar.js
5. Change subscript rule to use $.SUBSCRIPT
6. Generate parser and test with simple cases
7. Implement scan_superscript() (similar logic)
8. Change superscript rule to use $.SUPERSCRIPT
9. Test both together
10. Run full test suite and verify bounding behavior
