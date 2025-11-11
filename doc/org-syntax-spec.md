# Org-Mode Syntax Specification

**Source:** https://orgmode.org/worg/dev/org-syntax.html

This document provides a technical reference for Org syntax as parsed by `org-element.el` and the export framework.

## Core Concepts

### Objects vs. Elements

The syntax divides into two classes:

- **Elements**: Syntactic components that exist at paragraph scope or broader (headings, sections, lists)
- **Objects**: Syntactic components that exist within smaller scopes (text markup, links, timestamps)

### Stratification

Elements stratify into headings, sections, greater elements, and lesser elements. Only headings, sections, property drawers, and planning lines are context-free; others require specific environments.

### Document Structure

An Org document is "a sequence of elements that can recursively contain other elements and/or objects." Documents begin with an optional zeroth section (content before the first heading), followed by heading hierarchies.

### Blank Lines and Indentation

- **Blank lines** (containing only whitespace and newlines) belong to the preceding element with narrowest scope
- However, list items and footnote definitions use blank lines structurally, so trailing blanks don't include inner elements
- **Indentation** consists of leading spaces and tabs
- Most elements allow indentation except headings, inlinetasks, footnote definitions, and diary sexps
- Common indentation across lines is discarded

## Elements

### Headings and Sections

**Heading Pattern**: `STARS KEYWORD PRIORITY COMMENT TITLE TAGS`

Components:
- **STARS**: One or more asterisks (mandatory space after)
- **KEYWORD** (optional): Todo keyword from `org-todo-keywords-1`
- **PRIORITY** (optional): `[#A]` format
- **COMMENT** (optional): String "COMMENT"
- **TITLE** (optional): Objects from standard set
- **TAGS** (optional): Colon-separated alphanumeric strings

Special heading types:
- Headings marked "COMMENT" are commented
- Headings titled `Footnotes` (per `org-footnote-section`) are footnote sections
- Those tagged with "ARCHIVE" are archived

**Sections** follow headings up to the next heading or document end and contain non-heading elements. The zeroth section precedes all headings and can contain property drawers.

### Greater Elements

Greater elements can contain other elements.

#### Greater Blocks

Pattern: `#+begin_NAME PARAMETERS\nCONTENTS\n#+end_NAME`

#### Drawers

Pattern: `:NAME:\nCONTENTS\n:end:`
- NAME contains word-constituents, hyphens, underscores

#### Dynamic Blocks

Pattern: `#+begin: NAME PARAMETERS\nCONTENTS\n#+end:`

#### Footnote Definitions

Pattern: `[fn:LABEL] CONTENTS`
- Must start unindented
- LABEL is numeric or follows `WORD` pattern

#### Inlinetasks

- Headings at `org-inlinetask-min-level` or deeper
- Optionally closed with: `STARS END`

#### Items

Pattern: `BULLET COUNTER-SET CHECKBOX TAG CONTENTS`

Components:
- **BULLET**: `*`, `-`, `+`, or `COUNTER.`/`COUNTER)`
- **CHECKBOX** (optional): `[ ]`, `[X]`, `[-]`
- **TAG** (optional): `TAG-TEXT ::`

#### Plain Lists

- Consecutive items of same indentation
- Ordered lists start with counters
- Descriptive lists contain tags

#### Property Drawers

Pattern: `:properties:\nCONTENTS\n:end:`
- Contains node properties
- Appears after headings

#### Tables

- Begin with `|` (org-type) or `+-` (table.el-type)
- Org tables end at first non-`|` line

### Lesser Elements

Lesser elements cannot contain other elements.

#### Blocks

Types: comment, example, export, source, verse

Pattern:
```
#+begin_NAME DATA
CONTENTS
#+end_NAME
```

#### Clocks

Pattern: `CLOCK: TIMESTAMP` or `CLOCK: RANGE => HH:MM`

#### Diary Sexps

Pattern: `%%SEXP` (unindented)

#### Planning

Pattern: `KEYWORD: TIMESTAMP`
- Keywords: DEADLINE, SCHEDULED, CLOSED
- Appears directly after headings

#### Comments

Lines starting with `#` plus whitespace

#### Fixed-width Areas

Lines starting with `:` plus space

#### Horizontal Rules

Five or more consecutive hyphens

#### Keywords

Pattern: `#+KEY: VALUE`
- When KEY is in `org-element-parsed-keywords`, VALUE contains standard objects

#### LaTeX Environments

Pattern: `\begin{NAME}EXTRA\nCONTENTS\n\end{NAME}`

#### Node Properties

Pattern: `:NAME: VALUE`
- Only appears in property drawers

#### Paragraphs

Default element containing standard objects

#### Table Rows

- Start with `|`
- Contain cells or rule rows

## Objects

Objects appear within: keywords, headings, inlinetasks, item tags, clocks, planning, paragraphs, table cells, and verse blocks.

Structure: `BEGIN CONTENTS END BLANK` or `BEGIN VALUE END BLANK`

### Entity Types

#### Entities

Patterns:
- `\NAME POST`
- `\NAME{}`
- `\___SPACES`

#### LaTeX Fragments

Patterns:
- `\NAME BRACKETS`
- `\(CONTENTS\)`
- `\[CONTENTS\]`
- `$$CONTENTS$$`

#### Export Snippets

Pattern: `@@BACKEND:VALUE@@`

#### Footnote References

Patterns:
- `[fn:LABEL]`
- `[fn:LABEL:DEFINITION]`
- `[fn::DEFINITION]`

#### Citations

Pattern: `[cite CITESTYLE: REFERENCES]`
- Optional prefix/suffix

#### Citation References

Pattern: `KEYPREFIX @KEY KEYSUFFIX`
- Within citations

#### Inline Babel Calls

Pattern: `call_NAME(ARGUMENTS)`
- Optional headers

#### Inline Source Blocks

Pattern: `src_LANG{BODY}`
- Optional headers

#### Line Breaks

Pattern: `PRE\\ SPACE`
- Ending non-blank lines

### Links

Four subtypes:

- **Radio**: `PRE RADIO POST` (matches radio targets)
- **Plain**: `PRE LINKTYPE:PATHPLAIN POST`
- **Angle**: `<LINKTYPE:PATHANGLE>`
- **Regular**: `[[PATHREG]]` or `[[PATHREG][DESCRIPTION]]`

### Macros

Patterns:
- `{{{NAME}}}`
- `{{{NAME(ARGUMENTS)}}}`

### Targets

Patterns:
- `<<TARGET>>`
- `<<<CONTENTS>>>`

### Statistics Cookies

Patterns:
- `[PERCENT%]`
- `[NUM1/NUM2]`

### Subscript/Superscript

Pattern: `CHAR_SCRIPT` or `CHAR^SCRIPT`

### Table Cells

Pattern: `CONTENTS SPACES|` or `CONTENTS SPACES END-OF-LINE`

### Timestamps

Seven patterns including:
- Active/inactive timestamps
- Timestamp ranges
- Diary sexps with optional time and repeater/delay

### Text Markup

Pattern: `PRE MARKER CONTENTS MARKER POST`

Markers:
- `*` - Bold
- `/` - Italic
- `_` - Underline
- `=` - Verbatim
- `~` - Code
- `+` - Strike-through

### Plain Text

Any unmatched string; whitespace collapses to single spaces

## Additional Details

- Syntax is case-insensitive unless specified otherwise
- Blank lines include trailing spaces in object definitions
- The document provides extensive examples throughout each section
- Includes a comprehensive entity reference listing Latin, Greek, Hebrew, Icelandic characters and special symbols
