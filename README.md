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

#### ✅ Comments (100% test coverage)
- [x] Simple comments (`# comment text`)
- [x] Multiple comments
- [x] Comments under headlines
- [x] Comments between elements
- [x] Comments with special characters

**Tests**: 5/5 passing

**Bounding Success**: Comments use `# ` (hash + space) which is distinct from blocks (`#+`). Using `token(seq('#', ' '))` ensures atomic matching. Perfect isolation - zero cascading failures.

#### ✅ Property Drawers (100% test coverage)
- [x] Simple property drawers (`:PROPERTIES:` ... `:END:`)
- [x] Multiple properties per drawer
- [x] Property drawers with content after
- [x] Multiple headlines with property drawers

**Tests**: 4/4 passing

**Bounding Success**: Property drawers use distinctive `:PROPERTIES:` and `:END:` delimiters (all caps with colons). Cannot be confused with any other element. Position-specific (after headlines) adds additional isolation. Zero cascading failures.

#### ✅ Directives (100% test coverage)
- [x] Simple directives (`#+TITLE:`, `#+AUTHOR:`, etc.)
- [x] Multiple directives
- [x] Directives with content after
- [x] Common org directives (`#+OPTIONS:`, `#+STARTUP:`, etc.)
- [x] Directives between content

**Tests**: 5/5 passing

**Bounding Success**: Directives use `#+KEYWORD:` pattern (uppercase keyword + colon). Distinct from blocks (`#+begin_`), comments (`# `). Originally named "keyword" but renamed to "directive" to avoid conflict with headline TODO keywords. Perfect isolation - zero cascading failures.

#### ✅ Planning Lines (100% test coverage)
- [x] SCHEDULED planning lines
- [x] DEADLINE planning lines
- [x] CLOSED planning lines
- [x] Multiple planning keywords
- [x] Planning with content after

**Tests**: 6/6 passing

**Bounding Success**: Planning lines use uppercase keywords (DEADLINE, SCHEDULED, CLOSED) followed by `:` and timestamp. Implemented as atomic token (`token(seq(...))`) to prevent internal components from leaking. Higher precedence (`prec(2, ...)`) ensures they're matched before paragraphs. Zero cascading failures.

**Implementation Notes**: Initial attempt with separate timestamp components (date, day_name, time) caused massive cascading failures as patterns matched everywhere. Solution: make entire planning line atomic, including timestamp content. Timestamp matching uses simple regex patterns (`<[^>\n]+>` and `[^\]\n]+]`) rather than complex structured rules.

#### ✅ Links (100% test coverage)
- [x] Simple links without description (`[[url]]`)
- [x] Links with description (`[[url][description]]`)
- [x] File links (`[[file:path]]`)
- [x] ID links (`[[id:...]]`)
- [x] Multiple links
- [x] Links under headlines

**Tests**: 6/6 passing

**Bounding Success**: Links use distinctive `[[` and `]]` delimiters. Modified paragraph rule to exclude lines starting with `[` (changed `/[^*#|\n]/` to `/[^*#|\[\n]/`). Link target matched with `/[^\]\n]+/` pattern. Zero cascading failures.

**Implementation Notes**: Links are currently block-level elements (full lines). In Org-mode, links are inline objects that can appear within paragraphs. Future enhancement will require restructuring paragraphs to support inline elements.

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
- [ ] Timestamps (standalone, not just in planning lines)
- [ ] Footnotes

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
