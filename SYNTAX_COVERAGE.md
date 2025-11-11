# Org-Mode Syntax Coverage Analysis

Based on the official spec at https://orgmode.org/worg/org-syntax.html

## Legend
- ✅ Fully implemented with tests
- 🟡 Partially implemented
- ❌ Not implemented
- 📋 Planned for inline grammar

---

## ELEMENTS

### Greater Elements

| Element | Status | Tests | Notes |
|---------|--------|-------|-------|
| **Greater Blocks** (center, quote, special) | ✅ | Yes | Implemented as generic `block` |
| **Drawers** | ✅ | Yes | Pattern `:NAME:` ... `:end:` |
| **Dynamic Blocks** | ✅ | Yes | Pattern `#+begin: NAME ... #+end:` for dynamic content |
| **Footnote Definitions** | 🟡 | Yes | References work, but definitions as greater elements? |
| **Inlinetasks** | ❌ | No | Requires 15+ stars |
| **Plain Lists** (Items) | ✅ | Yes | Bullets, ordered, unordered |
| **Property Drawers** | ✅ | Yes | `:properties:` ... `:end:` |
| **Tables** | ✅ | Yes | Org tables with `|` |

### Lesser Elements

| Element | Status | Tests | Notes |
|---------|--------|-------|-------|
| **Blocks** (comment, example, export, src, verse) | ✅ | Yes | Generic block implementation |
| **Clock Elements** | ✅ | Yes | `CLOCK: TIMESTAMP` with 3 formats supported |
| **Diary Sexp** | ✅ | Yes | `%%SEXP` pattern with balanced parens |
| **Planning** | ✅ | Yes | DEADLINE, SCHEDULED, CLOSED |
| **Comments** | ✅ | Yes | Lines starting with `#` |
| **Fixed Width Areas** | ✅ | Yes | Lines starting with `:` and space |
| **Horizontal Rules** | ✅ | Yes | Five or more hyphens |
| **Keywords/Directives** | ✅ | Yes | `#+KEY: VALUE` |
| **LaTeX Environments** | ✅ | Yes | `\begin{NAME}` ... `\end{NAME}` - nested envs limited |
| **Node Properties** | 🟡 | Partial | In property drawers, but `:NAME+:` syntax? |
| **Paragraphs** | ✅ | Yes | Default element |
| **Table Rows** | ✅ | Yes | Rows and rules |

### Headings and Sections

| Element | Status | Tests | Notes |
|---------|--------|-------|-------|
| **Headings** | 🟡 | Yes | STARS, KEYWORD, PRIORITY, TITLE - missing COMMENT keyword |
| **Sections** | ✅ | Implicit | Content between headings |
| **Zeroth Section** | ✅ | Implicit | Content before first heading |

**Heading Components Missing:**
- ❌ COMMENT keyword (literal "COMMENT" in title makes heading non-TODO)
- 🟡 TAGS (currently absorbed into title, will be in inline grammar)

---

## OBJECTS (Inline Grammar Scope)

These should be parsed by the inline grammar within paragraphs, titles, table cells, etc.

### Implemented in Block Grammar (Should Move to Inline)

| Object | Status | Notes |
|--------|--------|-------|
| **Entities** | ✅ | `\NAME`, `\NAME{}`, `\ SPACES` |
| **LaTeX Fragments** | ✅ | `\NAME`, `$$...$$`, `$...$` |
| **Footnote References** | ✅ | `[fn:LABEL]`, `[fn::DEF]` |
| **Links** | ✅ | `[[URL]]`, `[[URL][DESC]]` - but block-level only |
| **Macros** | ✅ | `{{{NAME}}}`, `{{{NAME(ARGS)}}}` |
| **Subscript/Superscript** | ✅ | `CHAR_SCRIPT`, `CHAR^SCRIPT` |
| **Timestamps** | ✅ | Active `<>`, Inactive `[]` |

### Not Implemented (Need in Inline Grammar)

| Object | Status | Notes |
|--------|--------|-------|
| **Citations** | ❌ | `[cite STYLE: @KEY]` - Org 9.5+ |
| **Citation References** | ❌ | `@KEY` within citations |
| **Export Snippets** | ✅ | `@@BACKEND:VALUE@@` - backend-specific export formatting |
| **Inline Babel Calls** | ❌ | `call_NAME(ARGS)` |
| **Inline Source Blocks** | ❌ | `src_LANG{BODY}` or `src_LANG[HEADERS]{BODY}` |
| **Line Breaks** | ❌ | `\\` at end of line |
| **Radio Links** | ❌ | Text matched by radio targets |
| **Plain Links** | ❌ | `http://example.com` without brackets |
| **Angle Links** | ✅ | `<http://example.com>` - protocol-based URL links |
| **Regular Links (inline)** | 📋 | Currently block-level, need inline |
| **Targets** | ✅ | `<<TARGET>>` - internal link anchors |
| **Radio Targets** | ❌ | `<<<RADIO>>>` |
| **Statistics Cookies** | ✅ | `[50%]`, `[1/2]` - both percentage and fraction formats |
| **Table Cells (objects)** | 🟡 | Tables exist, but cell contents not parsed for objects |
| **Text Markup** | ✅ | Bold `*`, Italic `/`, Underline `_`, Code `~`, Verbatim `=`, Strike `+` all implemented |
| **Plain Text** | ✅ | Default object type in inline grammar |

### Inline Grammar Status

**Implemented:**
- ✅ Title/tags separation (8/8 tests)
- ✅ External scanner for tag detection
- ✅ Text markup: bold, italic, underline, code, verbatim, strike-through (11/11 tests)
- ✅ Statistics cookies: percentage and fraction formats (11/11 tests)
- ✅ Export snippets: backend-specific formatting (11/11 tests)
- ✅ Targets: internal link anchors `<<NAME>>` (11/11 tests)
- ✅ Angle links: protocol-based URLs `<PROTOCOL:PATH>` (14/14 tests)
- ✅ Plain text with proper whitespace handling
- ✅ Colons in titles (distinct from tags)

**TODO for Inline Grammar:**
- Links within paragraphs (not just block-level)
- Plain links (bare URLs without brackets)
- Radio targets (`<<<RADIO>>>`)
- Line breaks (`\\`)
- Inline babel/source blocks
- Citations (Org 9.5+)

---

## CRITICAL GAPS

### High Priority (Common in Org Files)

1. **Text Markup** (`*bold*`, `/italic/`, `_underline_`, `~code~`, `=verbatim=`, `+strike+`)
   - **Status**: ✅ **COMPLETE** - all 6 markup types implemented (11/11 tests)
   - **Impact**: Very common in org files
   - **Location**: Inline grammar
   - **Bounding**: Excellent - self-contained, localized failures, graceful degradation

2. **COMMENT Keyword in Headlines** ⚠️  **BLOCKED**
   - **Impact**: Common for disabling sections
   - **Location**: Block grammar headline
   - **Complexity**: HIGH - token conflict with greedy title regex
   - **Issue**: Title pattern `/[^\n]+/` creates implicit token that consumes "COMMENT..." before COMMENT token can match
   - **Solution needed**: External scanner for title that checks for/excludes COMMENT, or restructure title to not be a simple regex
   - **Bounding Impact**: This demonstrates poor bounding - title's greediness prevents proper keyword recognition

3. **Fixed Width Areas** (`: content`)
   - **Status**: ✅ **COMPLETE** (5/5 tests passing)
   - **Impact**: Common for code/output examples
   - **Location**: Block grammar
   - **Bounding**: Excellent - distinctive start pattern, graceful degradation

4. **Inline Links** (currently block-only)
   - **Status**: 📋 **NEXT PRIORITY**
   - **Impact**: Links should work within paragraphs
   - **Location**: Move from block to inline grammar
   - **Complexity**: Medium - need to handle in object context

5. **Table Cells as Object Containers**
   - **Impact**: Table cells should contain objects (links, markup, etc.)
   - **Location**: Inline grammar injection into table cells
   - **Complexity**: Medium

### Medium Priority

6. **Line Breaks** (`\\`)
   - **Status**: 📋 **Deferred** (requires paragraph inline parsing)
   - **Impact**: Used for manual line wrapping
   - **Complexity**: Medium - requires paragraph restructuring

7. **Plain Links** (URLs without brackets)
   - **Impact**: Convenient for quick links
   - **Complexity**: Medium - need link type detection

8. **Statistics Cookies** (`[50%]`, `[1/2]`)
   - **Status**: ✅ **COMPLETE** (11/11 tests passing)
   - **Impact**: Used in task lists and progress tracking
   - **Location**: Inline grammar
   - **Bounding**: Excellent - bracket-delimited, self-contained, graceful degradation

9. **Export Snippets** (`@@backend:content@@`)
   - **Status**: ✅ **COMPLETE** (11/11 tests passing)
   - **Impact**: Used for multi-format export
   - **Location**: Inline grammar
   - **Bounding**: Excellent - double-@ delimiters, self-contained, graceful degradation

### Low Priority (Advanced/Rare)

11. **Diary Sexp** (`%%(...)`)**
    - **Status**: ✅ **COMPLETE** (7/7 tests passing)
    - **Impact**: Advanced scheduling
    - **Complexity**: Medium - needs balanced paren matching
    - **Bounding**: Excellent - distinctive %% marker, single-line constraint, self-contained

12. **LaTeX Environments** (`\begin{...}`)
    - **Status**: ✅ **COMPLETE** (7/7 tests passing)
    - **Impact**: Academic documents (equations, align, matrix, proof, etc.)
    - **Complexity**: Medium - nested environments partially supported
    - **Bounding**: Excellent - distinctive \begin{}/\end{} markers, self-contained, graceful degradation
    - **Note**: Deeply nested environments (e.g., cases inside align) are a known limitation

13. **Dynamic Blocks** (`#+begin: name`)
    - **Status**: ✅ **COMPLETE** (8/8 tests passing)
    - **Impact**: Advanced block types (clocktable, columnview, etc.)
    - **Complexity**: Low - extends existing block pattern
    - **Bounding**: Excellent - distinctive colon markers, self-contained, graceful degradation

14. **Inlinetasks** (15+ stars)
    - **Impact**: Niche feature
    - **Complexity**: Medium

15. **Radio Targets/Links**
    - **Impact**: Rare advanced feature
    - **Complexity**: High - requires cross-document analysis

16. **Citations** (`[cite:@key]`)
    - **Impact**: Org 9.5+ only
    - **Complexity**: Medium

17. **Inline Babel/Source Blocks**
    - **Impact**: Advanced literate programming
    - **Complexity**: Medium

18. **Node Property `:NAME+:` Syntax**
    - **Impact**: Property accumulation
    - **Complexity**: Low - extend existing pattern

---

## SUMMARY

### Block Grammar (tree-sitter-org)
- **Total Elements**: ~25 types
- **Implemented**: ~20 types (✅ 80%)
- **Partial**: ~4 types (🟡 16%)
- **Missing**: ~5 types (❌ 20%)
- **Test Coverage**: 146/146 tests passing

### Inline Grammar (tree-sitter-org-inline)
- **Total Objects**: ~25 types
- **Implemented**: ~11 types (title/tags, 6 markup types, statistics cookies, export snippets, targets, angle links, plain text)
- **In Block (Should Move)**: ~7 types (entities, latex, footnotes, links, macros, sub/super, timestamps)
- **Missing**: ~7 types
- **Test Coverage**: 66/66 tests passing

### Overall Syntax Coverage
- **Fully Functional**: ~35%
- **Partial/Usable**: ~50%
- **Missing**: ~50%

### What's Working Well
✅ Core structure (headlines, sections, paragraphs)
✅ Planning and timestamps
✅ **Clock elements** (time tracking)
✅ **Diary sexp** (advanced scheduling: %%(lisp-expression))
✅ Lists and tables (structure)
✅ Blocks and drawers
✅ **Dynamic blocks** (clocktable, columnview: #+begin: name ... #+end:)
✅ **LaTeX environments** (equations, align, matrix: \begin{name} ... \end{name})
✅ Properties
✅ Comments and horizontal rules
✅ Directives/keywords
✅ Fixed width areas
✅ Title/tags separation (inline grammar)
✅ **Complete text markup** (all 6 types: bold, italic, underline, code, verbatim, strike-through)
✅ **Statistics cookies** (progress tracking: [50%], [2/5])
✅ **Export snippets** (backend-specific export: @@html:...@@)

### What's Missing That Users Will Notice
❌ Inline links in paragraphs - **Very Common**
❌ COMMENT keyword in headlines - **BLOCKED**
❌ Line breaks - **Requires paragraph restructuring**
❌ Objects in table cells
