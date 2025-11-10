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
| **Dynamic Blocks** | ❌ | No | Pattern `#+begin: NAME` not implemented |
| **Footnote Definitions** | 🟡 | Yes | References work, but definitions as greater elements? |
| **Inlinetasks** | ❌ | No | Requires 15+ stars |
| **Plain Lists** (Items) | ✅ | Yes | Bullets, ordered, unordered |
| **Property Drawers** | ✅ | Yes | `:properties:` ... `:end:` |
| **Tables** | ✅ | Yes | Org tables with `|` |

### Lesser Elements

| Element | Status | Tests | Notes |
|---------|--------|-------|-------|
| **Blocks** (comment, example, export, src, verse) | ✅ | Yes | Generic block implementation |
| **Clock Elements** | ❌ | No | `clock: TIMESTAMP` or `clock: [date]--[date] => HH:MM` |
| **Diary Sexp** | ❌ | No | `%%SEXP` pattern |
| **Planning** | ✅ | Yes | DEADLINE, SCHEDULED, CLOSED |
| **Comments** | ✅ | Yes | Lines starting with `#` |
| **Fixed Width Areas** | ❌ | No | Lines starting with `:` and space |
| **Horizontal Rules** | ✅ | Yes | Five or more hyphens |
| **Keywords/Directives** | ✅ | Yes | `#+KEY: VALUE` |
| **LaTeX Environments** | ❌ | No | `\begin{NAME}` ... `\end{NAME}` |
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
| **Export Snippets** | ❌ | `@@BACKEND:VALUE@@` |
| **Inline Babel Calls** | ❌ | `call_NAME(ARGS)` |
| **Inline Source Blocks** | ❌ | `src_LANG{BODY}` or `src_LANG[HEADERS]{BODY}` |
| **Line Breaks** | ❌ | `\\` at end of line |
| **Radio Links** | ❌ | Text matched by radio targets |
| **Plain Links** | ❌ | `http://example.com` without brackets |
| **Angle Links** | ❌ | `<http://example.com>` |
| **Regular Links (inline)** | 📋 | Currently block-level, need inline |
| **Targets** | ❌ | `<<TARGET>>` |
| **Radio Targets** | ❌ | `<<<RADIO>>>` |
| **Statistics Cookies** | ❌ | `[50%]`, `[1/2]` |
| **Table Cells (objects)** | 🟡 | Tables exist, but cell contents not parsed for objects |
| **Text Markup** | ❌ | Bold `*`, Italic `/`, Underline `_`, Code `~`, Verbatim `=`, Strike `+` |
| **Plain Text** | 📋 | Default object type |

### Inline Grammar Status

**Implemented:**
- ✅ Title/tags separation (8/8 tests)
- ✅ External scanner for tag detection

**TODO for Inline Grammar:**
- Text markup (bold, italic, underline, verbatim, code, strike-through)
- Links within paragraphs (not just block-level)
- Plain links, angle links
- Targets and radio targets
- Line breaks (`\\`)
- Export snippets
- Inline babel/source blocks
- Citations (Org 9.5+)
- Statistics cookies

---

## CRITICAL GAPS

### High Priority (Common in Org Files)

1. **Text Markup** (`*bold*`, `/italic/`, `_underline_`, `~code~`, `=verbatim=`, `+strike+`)
   - **Impact**: Very common in org files
   - **Location**: Inline grammar
   - **Complexity**: Requires PRE/POST character validation

2. **COMMENT Keyword in Headlines** ⚠️  **BLOCKED**
   - **Impact**: Common for disabling sections
   - **Location**: Block grammar headline
   - **Complexity**: HIGH - token conflict with greedy title regex
   - **Issue**: Title pattern `/[^\n]+/` creates implicit token that consumes "COMMENT..." before COMMENT token can match
   - **Solution needed**: External scanner for title that checks for/excludes COMMENT, or restructure title to not be a simple regex
   - **Bounding Impact**: This demonstrates poor bounding - title's greediness prevents proper keyword recognition

3. **Fixed Width Areas** (`: content`)
   - **Impact**: Common for code/output examples
   - **Location**: Block grammar
   - **Complexity**: Low - similar to comments

4. **Inline Links** (currently block-only)
   - **Impact**: Links should work within paragraphs
   - **Location**: Move from block to inline grammar
   - **Complexity**: Medium - need to handle in object context

5. **Table Cells as Object Containers**
   - **Impact**: Table cells should contain objects (links, markup, etc.)
   - **Location**: Inline grammar injection into table cells
   - **Complexity**: Medium

### Medium Priority

6. **Line Breaks** (`\\`)
   - **Impact**: Used for manual line wrapping
   - **Complexity**: Low - simple pattern

7. **Plain Links** (URLs without brackets)
   - **Impact**: Convenient for quick links
   - **Complexity**: Medium - need link type detection

8. **Statistics Cookies** (`[50%]`, `[1/2]`)
   - **Impact**: Used in task lists
   - **Complexity**: Low

9. **Export Snippets** (`@@backend:content@@`)
   - **Impact**: Used for multi-format export
   - **Complexity**: Low

10. **Clock Elements**
    - **Impact**: Time tracking feature
    - **Complexity**: Low - similar to planning lines

### Low Priority (Advanced/Rare)

11. **Diary Sexp** (`%%(...)`)**
    - **Impact**: Advanced scheduling
    - **Complexity**: Medium - needs balanced paren matching

12. **LaTeX Environments** (`\begin{...}`)
    - **Impact**: Academic documents
    - **Complexity**: Medium

13. **Dynamic Blocks** (`#+begin: name`)
    - **Impact**: Advanced block types
    - **Complexity**: Low

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
- **Implemented**: ~18 types (✅ 72%)
- **Partial**: ~4 types (🟡 16%)
- **Missing**: ~7 types (❌ 28%)
- **Test Coverage**: 112/112 tests passing

### Inline Grammar (tree-sitter-org-inline)
- **Total Objects**: ~25 types
- **Implemented**: ~1 type (title/tags)
- **In Block (Should Move)**: ~7 types (entities, latex, footnotes, links, macros, sub/super, timestamps)
- **Missing**: ~17 types
- **Test Coverage**: 8/8 tests passing (title/tags only)

### Overall Syntax Coverage
- **Fully Functional**: ~35%
- **Partial/Usable**: ~50%
- **Missing**: ~50%

### What's Working Well
✅ Core structure (headlines, sections, paragraphs)
✅ Planning and timestamps
✅ Lists and tables (structure)
✅ Blocks and drawers
✅ Properties
✅ Comments and horizontal rules
✅ Directives/keywords
✅ Title/tags separation (inline grammar)

### What's Missing That Users Will Notice
❌ Text markup (bold, italic, etc.) - **Very Common**
❌ Inline links in paragraphs
❌ Fixed width areas
❌ COMMENT keyword in headlines
❌ Clock elements
❌ Line breaks
❌ Objects in table cells
