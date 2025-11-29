# Known Limitations: tree-sitter-org-inline

**Last Updated:** 2025-11-28

This document describes known limitations of the inline parser.

---

## 1. Subscript/Superscript Token Boundary Bug

### What Doesn't Work

Subscript and superscript only work at the **start of input**, never after text:

```org
# These work:
x^2                    # superscript at start
H_2O                   # subscript at start

# These produce ERROR:
The formula is x^2     # superscript after text
Water is H_2O          # subscript after text
*bold x^2*             # in any context after text
```

### Why

The org-syntax spec defines subscript/superscript as `CHAR_SCRIPT` where CHAR is the preceding character. The grammar implements this as:

```javascript
subscript: $ => token(seq(/[a-zA-Z0-9]/, '_', ...))
```

The problem is tree-sitter's lexer tokenization:
1. Plain text regex matches characters up to (but not including) `_` or `^`
2. The preceding alphanumeric is consumed by plain text
3. When we reach `_` or `^`, the subscript token can't match because it needs the alphanumeric

This is a **fundamental token boundary conflict**, not a grammar bug.

### Attempted Fix (Did Not Work)

Scanner-based boundary detection was implemented and tested:
1. Added `PLAIN_TEXT` external token to scanner
2. Scanner detects `alphanumeric + _ or ^` patterns
3. Stops BEFORE consuming the alphanumeric using `mark_end()`
4. Subscript/superscript after text worked!

**However**, this approach conflicted with `plain_link` matching:
- Scanner emits PLAIN_TEXT for "https" (stops at colon)
- Grammar's `repeat1(choice(...))` keeps consuming
- `plain_link` never gets a chance to match from position 0

The fundamental issue: once plain_text starts building via `repeat1()`,
tree-sitter doesn't backtrack to try `plain_link` even though `plain_link`
has higher precedence.

### Alternative Approaches (Not Yet Tried)

1. **Lexer function in grammar.js**: Use tree-sitter's lexer to handle
   the token boundary, rather than the external scanner
2. **Restructure plain_link**: Make it not use `token()` so it can be
   tried at any position
3. **External plain_link scanner**: Handle plain_link detection in the
   scanner with higher priority than plain_text

### Workarounds

1. Place subscript/superscript at start of input or after delimiters
2. Use LaTeX for math expressions: `$x^2$` (once enabled)

---

## 2. LaTeX Fragments in Emphasis (Pending)

### Current Status

LaTeX fragments are not yet enabled inside emphasis:

```org
# Not yet working:
*bold $\alpha$*
/italic \(x^2\)/
```

### Why

The `plain_text_emphasis` regex currently includes `$`, preventing LaTeX matching.

### Planned Fix

Update `plain_text_emphasis` to exclude `$` and add `latex_fragment` to emphasis context. This is a straightforward change - LaTeX tokens are self-delimiting.

---

## 3. Invalid Patterns Produce ERROR Nodes

### What Happens

Malformed emphasis patterns produce `ERROR` nodes instead of gracefully falling back to `plain_text`:

```org
# These produce ERROR nodes:
**                        # empty bold
//                        # empty italic
*one *two*                # unmatched opener
*cross /boundaries* here/ # crossing delimiters
*nested *bold* bold*      # same-delimiter nesting
```

### Why

The scanner correctly rejects these patterns per org-syntax.md spec. However, tree-sitter's error recovery produces ERROR nodes rather than clean fallback.

### Impact

**Low.** These patterns are rare in real org files.

### Workaround

Avoid malformed patterns. For literal asterisks, use code: `~*~`

---

## 4. Some PRE/POST Edge Cases Produce ERROR

### What Happens

Certain PRE/POST character combinations may produce ERROR:

```org
}*bold*    # Right brace before (may ERROR)
*bold*[    # Left bracket after (may ERROR)
```

### Why

Scanner/grammar handoff when `_delimiter_char` fallback is emitted.

### Impact

**Low.** Unusual punctuation patterns.

---

## 5. Missing Objects

The following org-syntax objects are not yet implemented:

| Object | Syntax | Status |
|--------|--------|--------|
| Citations | `[cite:@key]` | Planned |
| Citation References | Inside citations | Planned |
| Inline Babel Calls | `call_name(args)` | Planned |
| Inline Source Blocks | `src_lang{code}` | Planned |
| Line Breaks | `\\` at EOL | Planned |

---

## What Works Well

Despite the limitations above, the parser correctly handles:

- **All emphasis types:** bold, italic, underline, code, verbatim, strike-through
- **All link types:** regular, angle, plain
- **Objects in emphasis:** links, macros, timestamps, footnotes, targets, statistics cookies
- **Cross-delimiter nesting:** `*bold /italic/*`
- **PRE/POST validation:** Most boundary cases work correctly
- **Entities:** `\alpha`, `\nbsp`, etc.

---

## Reporting Issues

If you encounter behavior not covered by these limitations:

1. Check if it's a known limitation above
2. Check org-syntax.md for expected behavior
3. Create a minimal test case
4. File an issue with input, expected output, and actual output
