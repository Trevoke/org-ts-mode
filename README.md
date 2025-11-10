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
- [x] Verse blocks (`#+begin_verse`)
- [x] Center blocks (`#+begin_center`)
- [x] Blocks under headlines
- [x] Multiple blocks

**Tests**: 8/8 passing

**Bounding Success**: Blocks have distinctive delimiters (`#+begin_` / `#+end_`) that prevent confusion with other elements. Generic `block_type` pattern accepts any block name, allowing verse and center blocks to work with zero code changes. Perfect example of extensible design - adding new block types requires only test cases, not grammar modifications.

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

#### ✅ Generic Drawers (100% test coverage)
- [x] LOGBOOK drawers (`:LOGBOOK:` ... `:end:`)
- [x] Custom named drawers (`:NOTES:`, `:DETAILS:`, etc.)
- [x] Drawers with multiple lines of content
- [x] Multiple drawers in sequence
- [x] Drawers with content after

**Tests**: 5/5 passing

**Bounding Success**: Generic drawers use `:NAME:` ... `:end:` pattern (lowercase `end`). Distinguished from property drawers by lowercase vs uppercase END delimiter. Modified paragraph pattern to exclude `:` at start (changed to `/[^*#|\[\-+:0-9a-z\n]/`). Drawer content uses negative lookahead regex to stop before `:end:` marker. Zero cascading failures.

**Implementation Notes**: Drawer names use same pattern as property keys (`/[A-Z_-]+/`). Content pattern: `/([^:]|:[^eE]|:[eE][^nN]|:[eE][nN][^dD]|:[eE][nN][dD][^:])+/` - matches any text but stops before `:end:`.

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

#### ✅ Lists (100% test coverage)
- [x] Unordered lists with `-` bullet
- [x] Unordered lists with `+` bullet
- [x] Ordered lists with numbers (`1.`, `2.`)
- [x] Ordered lists with letters (`a.`, `b.`)
- [x] Lists under headlines
- [x] Nested list support (via indentation)

**Tests**: 5/5 passing

**Bounding Success**: List bullets (-, +, digits, letters) are distinctive start patterns. Modified paragraph rule to exclude `-`, `+`, digits, and lowercase letters at start (changed to `/[^*#|\[\-+0-9a-z\n]/`). Used `prec.right(repeat1(...))` for grouping consecutive list items. List precedence set to prec(1) to prefer lists over paragraphs. Zero cascading failures.

**Implementation Notes**: Bullets wrapped in `token()` for atomic matching. List items support optional indentation for nesting.

**Known Limitations**:
- Checkboxes (`[ ]`, `[X]`, `[-]`) not yet implemented - parsing conflicts with content pattern
- Description lists (tags with `::`) not yet implemented
- Multi-line list items not supported

#### ✅ Standalone Timestamps (100% test coverage)
- [x] Active timestamps (`<2024-01-15 Mon>`)
- [x] Inactive timestamps (`[2024-01-15 Mon]`)
- [x] Timestamps with time (`<2024-01-15 Mon 14:30>`)
- [x] Timestamps under headlines
- [x] Multiple timestamps

**Tests**: 6/6 passing

**Bounding Success**: Timestamps use distinctive delimiters (`<` for active, `[` for inactive). Implemented as atomic tokens using `token(seq(...))` to prevent component leakage. Single `[` for timestamps doesn't conflict with `[[` for links. Content patterns use simple regex: `<[^>\n]+>` and `[^\]\n]+]`. Zero cascading failures.

**Implementation Notes**: Reuses same atomic pattern as planning line timestamps but as standalone block-level elements. Basic date/time support implemented; repeaters and delays can be added later without grammar changes.

#### ✅ Macros (100% test coverage)
- [x] Simple macros without arguments (`{{{title}}}`)
- [x] Macros with single argument (`{{{author(John)}}`)
- [x] Macros with multiple arguments (`{{{date(2024, 01, 15)}}}`)
- [x] Macros under headlines
- [x] Multiple macros
- [x] Macro names with underscores and hyphens

**Tests**: 6/6 passing

**Bounding Success**: Macros use highly distinctive `{{{` and `}}}` delimiters that don't conflict with any existing features. Modified paragraph pattern to exclude `{` from line starts (changed to `/[^*#|\[\-+:{0-9a-z\n]/`). Macro name pattern: `/[a-zA-Z][a-zA-Z0-9_-]*/`. Args pattern: `/[^})]+/` (excludes `}` and `)` to prevent greedy matching). Zero cascading failures.

**Implementation Notes**: Block-level elements (full lines). Macro arguments can contain commas for multiple values; escaped commas (`\,`) not yet implemented but can be added without grammar changes.

#### ✅ Footnotes (100% test coverage)
- [x] Simple footnote references (`[fn:1]`)
- [x] Named footnote references (`[fn:note1]`)
- [x] Inline footnotes with definitions (`[fn:label:definition]`)
- [x] Anonymous footnotes (`[fn::definition]`)
- [x] Footnotes under headlines
- [x] Multiple footnotes

**Tests**: 6/6 passing

**Bounding Success**: Footnotes use `[fn:` pattern (3-character sequence) that's highly distinctive. Initial conflict: footnotes were parsed as timestamps because both use `[`. Solution: made timestamp inactive pattern more specific - `[\d...]` must start with digit, which prevents matching `[fn:...]`. Both footnote_reference and timestamp are atomic tokens (using `token()`), so pattern specificity resolved the conflict. Modified footnote_reference precedence to `prec(2)` to prefer over timestamp. Zero cascading failures.

**Implementation Notes**: Block-level elements (full lines). Atomic token implementation means no separate child nodes for label/definition, but this maintains clean bounding. Supports all three footnote types: named references, inline with definitions, and anonymous.

**Key Technical Insight**: When multiple features use `token()` with overlapping patterns (both starting with `[`), precedence alone doesn't help - you must make patterns mutually exclusive through specificity (e.g., `[` + digit vs `[fn:`).

#### ✅ LaTeX Fragments (100% test coverage)
- [x] Display math with double dollar (`$$E = mc^2$$`)
- [x] Simple inline math (`$x$`)
- [x] Inline math with expressions (`$a + b = c$`)
- [x] LaTeX under headlines
- [x] Multiple LaTeX fragments
- [x] Display math with Greek letters (`$$\alpha + \beta$$`)

**Tests**: 6/6 passing

**Bounding Success**: LaTeX fragments use `$` and `$$` delimiters that are completely unique - not used by any other Org-mode feature. No paragraph pattern modification needed. Atomic token implementation with `token(seq(...))`. Pattern choice orders `$$...$$` before `$...$` to match longer pattern first. Content patterns: `/[^$]+/` for display math (allows newlines), `/[^$\n]+/` for inline math (single line). Zero cascading failures.

**Implementation Notes**: Block-level elements (full lines). Supports basic LaTeX math notation. Advanced patterns like `\(...\)` and `\[...\]` can be added later without grammar changes. Current implementation handles most common use cases.

#### ✅ Entities (100% test coverage)
- [x] Greek letters (`\alpha`, `\beta`)
- [x] Non-breaking space (`\nbsp`)
- [x] Entity with explicit braces (`\alpha{}`)
- [x] Entities under headlines
- [x] Multiple entities

**Tests**: 6/6 passing

**Bounding Success**: Entities use backslash `\` prefix followed by alphabetic name (`/[a-zA-Z]+/`). Backslash delimiter is unique in this context - not used by other block-level features. Optional `{}` suffix supported for disambiguation. Atomic token implementation with `token(seq(...))`. No paragraph pattern modification needed. Zero cascading failures.

**Implementation Notes**: Block-level elements (full lines). Supports standard Org entity names (alpha, beta, gamma, nbsp, etc.). Pattern recognizes alphabetic entity names only. Entity validation (checking against org-entities list) is left to higher-level tools.

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
