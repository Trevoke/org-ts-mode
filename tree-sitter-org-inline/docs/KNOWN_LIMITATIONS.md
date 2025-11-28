# Known Limitations: tree-sitter-org-inline

**Last Updated:** 2025-11-28

This document describes known limitations of the inline parser that are architectural constraints rather than bugs.

---

## 1. Phase 3 Objects Not Available in Emphasis

### What Doesn't Work

LaTeX fragments, subscript, and superscript cannot be used inside text markup (bold, italic, underline, strike-through).

```org
# These patterns will NOT parse the inner objects:
*bold with x^2*           # superscript not parsed
/italic with H_2O/        # subscript not parsed
*bold with $\alpha$*      # LaTeX not parsed
_underline with x^{2+n}_  # superscript not parsed
```

### What Works

These objects work in all other contexts:

```org
# Outside emphasis:
Text with x^2             # superscript works
H_2O is water             # subscript works
The value is $\alpha$     # LaTeX works

# In link descriptions:
[[url][H_2O description]] # subscript works in link desc

# Mixed with emphasis (not nested):
*bold* with x^2           # both work, not nested
```

### Why

Tree-sitter parser state explosion. Testing showed:
- Without Phase 3 objects in emphasis: 182 parser states
- With Phase 3 objects in emphasis: 382 parser states (2.1x increase)

The combinatorial explosion comes from allowing all object types at all nesting levels.

### Workarounds

1. Place objects outside emphasis: `*bold* with x^2`
2. Use code/verbatim for formulas: `~x^2~`
3. Use LaTeX for complex math outside emphasis

### Future Resolution

A future optimization pass could:
- Use a custom scanner for emphasis content parsing
- Implement a two-pass strategy (emphasis first, then inner objects)
- Accept higher state count with performance testing

---

## 2. Invalid Patterns Produce ERROR Nodes

### What Happens

Malformed emphasis patterns produce `ERROR` nodes instead of gracefully falling back to `plain_text`.

```org
# These produce ERROR nodes:
**                        # empty bold
//                        # empty italic
*one *two*                # unmatched opener
*cross /boundaries* here/ # crossing delimiters
*nested *bold* bold*      # same-delimiter nesting
```

### Expected vs Actual

| Input | Expected | Actual |
|-------|----------|--------|
| `**` | `(plain_text)` | `(ERROR)` |
| `*one *two*` | `(plain_text) (bold)` | `(ERROR) (bold)` |

### Why

The scanner correctly rejects these patterns (per org-syntax.md spec). However, tree-sitter's error recovery mechanism produces ERROR nodes rather than cleanly falling back.

The `_delimiter_char` external token exists to catch rejected delimiters, but grammar consumption of this token has edge cases.

### Impact

**Low.** These patterns are rare in real org files:
- Empty emphasis serves no purpose
- Crossing boundaries is visually confusing
- Same-delimiter nesting is rejected by Emacs too

### Workaround

Avoid these patterns in org files. If you need literal asterisks, use:
- Code: `~*~`
- Verbatim: `=*=`
- Entity: `\ast`

---

## 3. Some PRE/POST Edge Cases Produce ERROR

### What Happens

Certain combinations of PRE and POST characters around emphasis may produce ERROR nodes.

### Spec Reference (org-syntax.md)

**PRE (before opening marker):** Beginning of line, whitespace, or one of: `- ( ' " { `

**POST (after closing marker):** End of line, whitespace, or one of: `- . , ; : ! ? ' " ) } [ `

### Edge Cases

Some valid PRE/POST combinations work incorrectly:
- Right brace before: `}*bold*` - may ERROR
- Left bracket after: `*bold*[` - may ERROR

### Impact

**Low.** These punctuation patterns are uncommon in real org text.

### Root Cause

Scanner/grammar handoff when `_delimiter_char` fallback is emitted. The grammar doesn't always consume the fallback token correctly in all contexts.

---

## 4. Missing Objects

The following org-syntax objects are not yet implemented:

| Object | Syntax | Priority |
|--------|--------|----------|
| Citations | `[cite:@key]` | P2 |
| Citation References | Inside citations | P3 |
| Inline Babel Calls | `call_name(args)` | P2 |
| Inline Source Blocks | `src_lang{code}` | P2 |
| Line Breaks | `\\` at EOL | P1 |

These will be added in future sprints.

---

## Reporting Issues

If you encounter behavior not covered by these limitations:

1. Check if it's a known limitation above
2. Check the org-syntax.md spec for expected behavior
3. Create a minimal test case
4. File an issue with input, expected output, and actual output
