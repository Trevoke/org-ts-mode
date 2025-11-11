# Inline Grammar Analysis and Rebuild Plan

## Problem Statement

The inline grammar is broken due to subscript/superscript implementation that didn't consider the grammar holistically. Specifically, 13 out of 16 subscript/superscript tests are failing, and there are conflicts with underline markup.

## Root Cause Analysis

### The Core Issue: Lookahead and Atomicity

The fundamental problem is that subscript/superscript objects require **looking backward** at what character came before:

```
"The formula x^2 is"
            ↑  ↑
            CHAR (x) must be any non-whitespace
```

In the current grammar:
1. `plain_text` excludes `_` and `^` but **consumes "x"** first
2. Then subscript tries to match `"_2"` but there's no CHAR before it
3. Parser fails because "^2" doesn't match any pattern

### Conflict: Subscript vs Underline

Per org-mode spec:
- `_text_` = underline markup (TWO underscores, matching delimiters)
- `H_2O` = subscript (ONE underscore after CHAR)
- **When ambiguous, underline takes priority**: `(_text_)` should parse as underline

Current grammar can't distinguish these because both patterns start with `_`.

## Org-Mode Specification Deep Dive

### Subscript/Superscript Structure

**Pattern**: `CHAR_SCRIPT` or `CHAR^SCRIPT`

**CHAR**: "Any non-whitespace character" (not just alphanumeric!)

**SCRIPT** (three forms):
1. Single asterisk: `*`
2. Bracketed: `{...}` or `(...)` with balanced brackets
3. Alphanumeric: `[+-]?[a-zA-Z0-9,\\.]+[a-zA-Z0-9]`

**Examples**: `x^2`, `x^-2`, `x^{y^{z}}`, `A_i,j`, `pecularity^*`

### Text Markup Rules (Bold, Italic, Underline, etc.)

**PRE characters** (what can come before):
- Whitespace, `-`, `(`, `{`, `'`, `"`, or **beginning of line**

**POST characters** (what can come after):
- Whitespace, `-`, `.`, `,`, `;`, `:`, `!`, `?`, `'`, `)`, `}`, `[`, `"`, `\`, or **end of line**

**Critical**: `PRE MARKER CONTENTS MARKER POST` must not have whitespace between components

### Key Insight: Precedence Rules

1. **Underline markup takes priority** over subscript when ambiguous
2. Text markup requires specific PRE/POST characters
3. Subscript/superscript require any non-whitespace CHAR

## Bounding Strategy

To isolate failures and make tests more debuggable, we need to make objects as **atomic** as possible:

### Atomic Token Strategy

Use `token()` to make complex patterns indivisible:

```javascript
// GOOD: Atomic - parser sees whole thing or nothing
subscript: $ => token(seq(/[^\s]/, '_', /[a-zA-Z0-9]+/))

// BAD: Compositional - parts can be consumed separately
subscript: $ => seq($.base, '_', $.script)
```

### Layered Precedence

Objects should have clear precedence layers:

1. **Layer 4**: Links with protocols (contain `:` internally)
2. **Layer 3**: Complex objects (markup, subscript, superscript, links, timestamps, footnotes)
3. **Layer 2**: Structural tokens (`:` for tags)
4. **Layer 1**: Plain text (fallback)

### Principle: Fail Early, Fail Local

When a pattern doesn't match, the error should be:
- **Local**: Only that object type fails, not the entire title
- **Clear**: The token type in the error message indicates what was expected
- **Recoverable**: Parser can continue with remaining text

## Systematic Rebuild Plan

### Phase 1: Foundation (Plain Text Only)

**Goal**: Establish baseline with only plain text parsing

**Test**: "Simple text without any markup"

**Implementation**:
```javascript
inline: $ => $.title_only,
title_only: $ => field('title', $.title),
title: $ => repeat1($.plain_text),
plain_text: $ => /[^\n]+/  // Temporarily: match everything
```

**Success Criteria**: All existing non-markup tests pass

### Phase 2: Add Simple Objects (No Conflicts)

**Order** (add one at a time with tests):
1. `<<target>>` and `<<<radio_target>>>` (unique markers)
2. `{{{macro}}}` (unique markers)
3. `@@backend:snippet@@` (unique markers)
4. `\entity` (unique marker)
5. `[[link]]` and `<protocol:link>` (unique markers)
6. `[fn:ref]` (unique marker, but test vs `[50%]`)
7. `[50%]` and `[1/2]` (statistics cookies)
8. Timestamps `<2024-01-01>` and `[2024-01-01]` (test vs cookies)

**For each object**:
- Make it `token()` to ensure atomicity
- Add specific tests for boundaries (before/after text)
- Test conflicts with similar patterns
- Update plain_text to exclude its delimiters

### Phase 3: Add Text Markup (Complex PRE/POST Rules)

**Order**:
1. Bold `*text*`
2. Italic `/text/`
3. Code `~text~`
4. Verbatim `=text=`
5. Strike-through `+text+`
6. Underline `_text_` (LAST - conflicts with subscript)

**For each markup**:
- Implement PRE/POST character validation
- Test with all valid PRE characters
- Test with all valid POST characters
- Test nested/adjacent markup
- Test that `CONTENTS` cannot start/end with whitespace

**Implementation approach**:
- Use external scanner for PRE/POST validation (context-aware)
- OR use `token()` with complex regex (if possible)

### Phase 4: Add Subscript/Superscript (External Scanner Required)

**Why external scanner**:
1. Need to look backward at CHAR (context)
2. Complex SCRIPT patterns (three forms)
3. Must yield to underline when ambiguous
4. CHAR is any non-whitespace (too broad for token)

**External scanner logic**:
```c
bool scan_subscript(Lexer *lexer, const bool *valid_symbols) {
  if (!valid_symbols[SUBSCRIPT]) return false;

  // We're called when parser expects subscript after CHAR
  // CHAR was already consumed by plain_text

  if (lexer->lookahead != '_') return false;
  lexer->advance(lexer, false);  // Consume '_'

  // Check for underline conflict: _text_
  // If we see another _ soon, this might be underline
  // Give up and let underline parser handle it
  if (is_underline_pattern(lexer)) return false;

  // Parse SCRIPT (three forms)
  if (lexer->lookahead == '*') {
    lexer->advance(lexer, false);
    lexer->result_symbol = SUBSCRIPT;
    return true;
  }

  // ... handle other SCRIPT forms
}
```

**Alternative: Token with negative lookahead**:
```javascript
// Match subscript but NOT underline
subscript: $ => token(seq(
  /[^\s]/,           // CHAR
  '_',
  choice(
    '*',
    /[a-zA-Z0-9,\\.]*/
  ),
  // How to ensure next char isn't _ (underline)?
  // Can't do negative lookahead in tree-sitter regex
))
```

**Decision**: Need external scanner for proper implementation

### Phase 5: Add Tags (External Scanner)

**Pattern**: `:tag1:tag2:` at end of title

**Complexity**:
- Colons appear in many contexts (timestamps, links, export snippets)
- Tags must be at END of title with space before
- Need to validate tag format

**External scanner logic**:
- When parser sees `:`, check if it's start of tags
- Look ahead to find matching `:` delimiters
- Validate tag names (alphanumeric, `@`, `%`, `#`, `_`)
- Ensure it's at end of line

### Phase 6: Integration and Optimization

**Tasks**:
1. Run full test suite
2. Profile performance (watch for slow parses)
3. Minimize conflicts
4. Optimize precedence levels
5. Add inline to block grammar injection queries

## Testing Strategy

### Test Structure

Organize tests by **object type** and **interaction**:

```
test/corpus/
  01_plain_text.txt          # Baseline
  02_targets.txt             # No conflicts
  03_macros.txt              # No conflicts
  04_entities.txt            # No conflicts
  05_links.txt               # Test [[]] vs [fn:] vs [50%]
  06_timestamps.txt          # Test <> vs <link>
  07_statistics_cookies.txt  # Test [50%] vs [fn:] vs [2024]
  08_footnotes.txt           # Test [fn:] vs [50%] vs [2024]
  09_text_markup_bold.txt    # PRE/POST rules
  10_text_markup_italic.txt
  11_text_markup_code.txt
  12_text_markup_underline.txt  # Test _text_ vs subscript
  13_subscript_superscript.txt  # Test x_2 vs _text_
  14_tags.txt                # Test :tag: vs plain : vs @@:@@ vs <protocol:>
  15_interactions.txt        # Cross-object tests
```

### Test Patterns

For each object type:

1. **Standalone**: Object alone
2. **With plain text before**: `"text before <object>"`
3. **With plain text after**: `"<object> text after"`
4. **Multiple instances**: `"<obj1> text <obj2>"`
5. **At boundaries**: Start of title, end of title
6. **Near similar patterns**: Test disambiguation
7. **With tags**: `"<object> :tag:"`

### Bounding Tests

To verify isolation:

```
==================
Bold with invalid closing (should fail locally)
==================

Text with *bold but no closing

---

(inline
  (title_only
    (title
      (plain_text)  # "Text with "
      (ERROR)       # "*bold but no closing"
    )))

# NOT: (ERROR (inline ...)) - whole title shouldn't fail
```

## Implementation Order

1. ✅ **Phase 0**: Document analysis (this file)
2. **Phase 1**: Strip down to plain text, verify baseline
3. **Phase 2**: Add simple objects one by one
4. **Phase 3**: Add text markup (bold, italic, code, verbatim, strike)
5. **Phase 4a**: Design external scanner for subscript/superscript
6. **Phase 4b**: Implement and test subscript/superscript
7. **Phase 4c**: Add underline AFTER subscript (test priority)
8. **Phase 5**: Add tags with external scanner
9. **Phase 6**: Integration, optimization, performance testing

## Success Criteria

- [ ] All 186 original tests pass
- [ ] All subscript/superscript tests pass (13 currently failing)
- [ ] All new object interaction tests pass
- [ ] No slow parse warnings (<10,000 bytes/ms)
- [ ] Parse errors are local (don't cascade)
- [ ] Clear tree structure (atomic objects, no leaking internals)

## Next Steps

1. Commit this analysis document
2. Create Phase 1 implementation (plain text baseline)
3. Set up new test structure
4. Begin incremental rebuild

## Questions for Consideration

1. **Should we use external scanner for text markup PRE/POST validation?**
   - Pros: Accurate, context-aware
   - Cons: More complex, harder to debug
   - Decision: TBD based on Phase 3 results

2. **Should base/script be separate nodes in subscript/superscript?**
   - Pros: More structured tree, easier queries
   - Cons: Harder to parse atomically
   - Decision: Start atomic, add structure if needed

3. **Should we support nested markup (e.g., `*bold _underline_*`)?**
   - Org-mode spec: Not standard but some exporters support it
   - Decision: Out of scope for initial implementation

4. **How to handle malformed input gracefully?**
   - `*bold without closing` - treat as plain text with `*`?
   - `x_` - incomplete subscript, treat as plain text?
   - Decision: Define in Phase 2 based on org-mode behavior
