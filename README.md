# Tree-sitter Grammar for Org-mode

A tree-sitter parser for Emacs Org-mode syntax.

## Current Status

This is an early-stage implementation following TDD principles. The grammar is being built incrementally, starting with the most fundamental structures.

### Implemented Features

#### ✅ Headlines (100% test coverage)
- [x] Basic headlines with stars (`*`, `**`, `***`)
- [x] TODO keywords (TODO, DONE, NEXT, WAITING, CANCELED)
- [x] Priority markers (`[#A]`, `[#B]`, `[#C]`)
- [x] Headline titles
- [x] Multiple heading levels

**Tests**: 7/7 passing

#### ✅ Paragraphs (100% test coverage)
- [x] Basic paragraph text
- [x] Multiple paragraphs
- [x] Paragraphs under headlines

**Tests**: 4/4 passing

#### ✅ Blocks (100% test coverage)
- [x] Source blocks with language (`#+begin_src LANG`)
- [x] Example blocks (`#+begin_example`)
- [x] Quote blocks (`#+begin_quote`)
- [x] Blocks under headlines
- [x] Multiple blocks

**Tests**: 5/5 passing

**Bounding Success**: Blocks have distinctive delimiters (`#+begin_` / `#+end_`) that prevent confusion with other elements. Implementation didn't break any existing tests.

#### ✅ Tables (100% test coverage)
- [x] Table rows with cells (`| cell | cell |`)
- [x] Table separators (`|---+---|`)
- [x] Tables under headlines
- [x] Multiple tables (when separated by other elements)

**Tests**: 4/4 passing

**Bounding Success**: Tables start with `|` which is distinctive from all other elements. Used `token()` + `prec(1, ...)` to disambiguate table separators from regular rows. No cascading test failures.

**Known Limitation**: Tables separated only by blank lines are currently treated as one table. Requires explicit element separator (headline, paragraph, etc.) between tables.

### TODO (Priority Order)

#### Next Sprint
1. [ ] **Inline Markup** - Requires careful design to avoid breaking headline/paragraph parsing
   - Bold (`*bold*`), Italic (`/italic/`), Code (`~code~`), etc.
   - Challenge: Must distinguish `*` as bold vs headline starter
   - Approach: May require two-phase parsing (block structure first, then inline)

2. [ ] **Tags** - Currently absorbed into headline title
   - Pattern: `:tag1:tag2:` at end of headlines
   - Challenge: Requires lookahead or external scanner

#### Future
- [ ] Lists (ordered, unordered, description)
- [ ] Links
- [ ] Timestamps
- [ ] Footnotes
- [ ] Property drawers

## Development Approach

This grammar is being developed using Test-Driven Development (TDD):
1. Write test cases first (in `test/corpus/`)
2. Implement grammar rules to pass tests
3. Iterate and refine

### Running Tests

```bash
tree-sitter test
```

### Building

```bash
tree-sitter generate
```

## Architecture Notes

The Org-mode syntax has a clear hierarchy between "Elements" (block-level structures) and "Objects" (inline structures), similar to how the markdown tree-sitter grammar separates block and inline parsing. Currently, this grammar uses a single parser, but may be split into dual parsers if needed for more complex features.

### Challenges

1. **Tags**: Org tags appear at the end of headlines (`:tag1:tag2:`), but tree-sitter's lexer makes it challenging to stop the title before tags without lookahead. This may require an external scanner.

2. **Inline Markup Boundaries**: Org markup requires specific PRE/POST delimiters (whitespace, punctuation, etc.), which adds complexity to the regex patterns.

3. **Context-sensitive Parsing**: Some Org structures are context-dependent (e.g., asterisks at line start are headlines, elsewhere they're bold markup).

## References

- [Org Syntax Specification](https://orgmode.org/worg/org-syntax.html)
- [Tree-sitter Documentation](https://tree-sitter.github.io/tree-sitter/)
- [Tree-sitter Markdown Grammar](https://github.com/tree-sitter-grammars/tree-sitter-markdown) (inspiration)

## License

MIT
