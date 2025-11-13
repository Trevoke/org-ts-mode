
# Table of Contents

1.  [Introduction](#org7c5189c)
2.  [Terminology and conventions](#org9f208e7)
    1.  [Objects and Elements](#org20e677f)
    2.  [Blank lines](#Blanks)
    3.  [Indentation](#org3983f1c)
    4.  [The minimal and standard sets of objects](#org290e58a)
    5.  [Syntax patterns](#orgdf78642)
        1.  [General form](#org9db951c)
        2.  [Special tokens](#Special_Tokens)
        3.  [Case significance](#org6b5accb)
    6.  [References to lisp variables](#orgff340c9)
3.  [General structure of Org document](#org6866ffd)
4.  [Elements](#Elements)
    1.  [Headings and Sections](#Headings_and_Sections)
        1.  [Headings](#Headings)
        2.  [Sections](#Sections)
        3.  [The zeroth section](#Zeroth_section)
    2.  [Greater Elements](#Greater_Elements)
        1.  [Greater Blocks](#Greater_Blocks)
        2.  [Drawers and Property Drawers](#Drawers)
        3.  [Dynamic Blocks](#Dynamic_Blocks)
        4.  [Footnote Definitions](#Footnote_Definitions)
        5.  [Inlinetasks](#Inlinetasks)
        6.  [Items](#Items)
        7.  [Plain Lists](#Plain_Lists)
        8.  [Property Drawers](#Property_Drawers)
        9.  [Tables](#Tables)
    3.  [Lesser Elements](#Lesser_Elements)
        1.  [Blocks](#Blocks)
        2.  [Clock](#Clocks)
        3.  [Diary Sexp](#Diary_Sexp)
        4.  [Planning](#Planning)
        5.  [Comments](#Comments)
        6.  [Fixed Width Areas](#Fixed_Width_Areas)
        7.  [Horizontal Rules](#Horizontal_Rules)
        8.  [Keywords](#Keywords)
        9.  [LaTeX Environments](#LaTeX_Environments)
        10. [Node Properties](#Node_Properties)
        11. [Paragraphs](#Paragraphs)
        12. [Table Rows](#Table_Rows)
5.  [Objects](#Objects)
    1.  [Entities](#Entities)
    2.  [LaTeX Fragments](#LaTeX_Fragments)
    3.  [Export Snippets](#Export_Snippets)
    4.  [Footnote References](#Footnote_References)
    5.  [Citations](#Citations)
    6.  [Citation references](#Citation_References)
    7.  [Inline Babel Calls](#Inline_Babel_Calls)
    8.  [Inline Source Blocks](#Source_Blocks)
    9.  [Line Breaks](#Line_Breaks)
    10. [Links](#Links)
        1.  [Radio Links](#org11691d3)
        2.  [Plain links](#org907fd8e)
        3.  [Angle links](#org1e18b4b)
        4.  [Regular links](#orgfdd84dc)
    11. [Macros](#Macros)
    12. [Targets and Radio Targets](#Targets_and_Radio_Targets)
    13. [Statistics Cookies](#Statistics_Cookies)
    14. [Subscript and Superscript](#Subscript_and_Superscript)
    15. [Table Cells](#Table_Cells)
    16. [Timestamps](#Timestamps)
    17. [Text Markup](#Emphasis_Markers)
        1.  [Plain Text](#Plain_Text)
6.  [Appendix](#org436d834)
    1.  [Org Entities](#Entities_List)

<style>
  div.notes {
    background-color: #587e7244;
    position: relative;
    padding: 0em 0.3em;
    font-size: 0.95em;
    font-style: italic;
  }
  div.notes::before {
    content: 'Note';
    font-style: normal;
    font-weight: 500;
    color: #587e72;
    position: absolute;
    left: -2.6em;
  }
</style>


<a id="org7c5189c"></a>

# Introduction

Org is a plaintext format composed of simple, yet versatile, forms
which represent formatting and structural information.  It is designed
to be both intuitive to use, and capable of representing complex
documents.  Like Markdown ([RFC7763](https://datatracker.ietf.org/doc/html/rfc7763)), Org may be considered a
lightweight markup language.  However, while Markdown refers to a
collection of similar syntaxes, Org is a single syntax.

This document describes and comments on Org syntax as it is currently
read by its parser (`org-element.el`) and, therefore, by the export
framework. This is intended as a technical document for developers and
those particularly interested in the syntax. Most users will be better
served by [the Org manual](https://orgmode.org/manual/).


<a id="org9f208e7"></a>

# Terminology and conventions


<a id="org20e677f"></a>

## Objects and Elements

The components of this syntax can be divided into two classes:
&ldquo;[objects](#Objects)&rdquo; and &ldquo;[elements](#Elements)&rdquo;.  To better understand these classes,
consider the paragraph as a unit of measurement.  *Elements* are
syntactic components that exist at the same or greater scope than a
paragraph, i.e. which could not be contained by a paragraph.
Conversely, *objects* are syntactic components that exist with a smaller
scope than a paragraph, and so can be contained within a paragraph.

Elements can be stratified into &ldquo;[headings](#Headings)&rdquo;, &ldquo;[sections](#Sections)&rdquo;, &ldquo;[greater
elements](#Greater_Elements)&rdquo;, and &ldquo;[lesser elements](#Lesser_Elements)&rdquo;, from broadest scope to
narrowest.  Along with objects, these sub-classes define categories of
syntactic environments.  Only [headings](#Headings), [sections](#Sections), [property drawers](#Property_Drawers), and
[planning lines](#Planning) are context-free<sup><a id="fnr.1" class="footref" href="#fn.1" role="doc-backlink">1</a></sup><sup>, </sup><sup><a id="fnr.2" class="footref" href="#fn.2" role="doc-backlink">2</a></sup>, every other syntactic
component only exists within specific environments. This is a core
concept of the syntax.

Expanding on the stratification of elements, lesser elements are
elements that cannot contain any other elements.  As such, a paragraph
is considered a lesser element.  Greater elements can themselves
contain greater elements or lesser elements. Sections contain both
greater and lesser elements, and headings can contain a section and
other headings.


<a id="Blanks"></a>

## Blank lines

A line containing only spaces, tabs, newlines, and line feeds (`\t\n\r`)
is considered a *blank line*.  Blank lines can be used to separate
paragraphs and other elements.

Blank lines are considered a part of a preceding element.

A simple example is blank lines after a drawer:

    :drawer:
    Text.
    :end:
    
    
    The blank lines above are considered a part of the drawer.

However, in some cases, multiple Org elements may be candidates to
&ldquo;own&rdquo; the blank lines:

    * Heading
    Paragraph inside heading, blank lines may be considered a part of this
    paragraph or, similarly, a part of the parent section or heading.
    
    
    * Another heading

By convention, with the exception of [list items](#Items) and [footnote
definitions](#Footnote_Definitions) blank lines belong to the preceding element with the
narrowest possible scope.

In the above example, blank lines are considered a direct part of the
paragraph, not the heading or section:

    (heading (section (paragraph <blank lines> ...)))

Blank lines at the end of [list items](#Items) and [footnote definitions](#Footnote_Definitions) do not
include the containing elements because list items and footnote
definitions are using blank lines as a part of their syntax definition:

    - Item 1
    
    - Item 2
      :drawer:
      inside item 2
      :end:
    
    
    The above list item ends with two consequative blank lines.
    So, we do not include these structurally important blank lines into
    the inner elements inside the item.


<a id="org3983f1c"></a>

## Indentation

Indentation consists of a series of space and tab characters at the
beginning of a line.  Most elements can be indentated, with the
exception of [headings](#Headings), [inlinetasks](#Inlinetasks), [footnote definitions](#Footnote_Definitions), and [diary
sexps](#Diary_Sexp).  Indentation is only syntactically meaningful in plain lists,
where indentation is calculated assuming that space characters occupy
a single character and tab characters occupy 8 characters.

The common indentation of all the lines within an element is
discarded.  This also applies to single-line elements.

**Examples**

    This paragraph will not contain
    a long sequence of spaces before "a".
    
    This paragraph does not have leading spaces according to the parser.
    
    #+begin_src emacs-lisp
      (+ 1 2)
    #+end_src
    The above source block preserves two leading spaces inside the code
    after removing the common indentation.


<a id="org290e58a"></a>

## The minimal and standard sets of objects

To simplify references to common collections of objects, we define two
useful sets.  The *<a id="org360f63a">minimal set</a> of objects* refers to [plain text](#Plain_Text),
[text markup](#Emphasis_Markers), [entities](#Entities), [LaTeX fragments](#LaTeX_Fragments), [superscripts and subscripts](#Subscript_and_Superscript).
The *<a id="org16495ef">standard set</a> of objects* refers to the entire set of objects,
excluding [citation references](#Citation_References) and [table cells](#Table_Cells).


<a id="orgdf78642"></a>

## Syntax patterns


<a id="org9db951c"></a>

### General form

Most elements and objects will be described with the help of syntax
patterns, consisting of a series of named tokens written in uppercase
and separated by a space, like so:

    TOKEN1 TOKEN2

These tokens are often named roughly according to their semantic
meaning, For instance, &ldquo;KEY&rdquo; and &ldquo;VALUE&rdquo; when describing
[Keywords](#Keywords). Tokens will be specified as either a string, or a series of
elements or objects.

<div class="infobox" id="org0bbf0db">
<p>
Unless otherwise specified, a space in a pattern represents one or
more horizontal whitespace characters.
</p>

</div>

Patterns will often also contain static structures that serve to
differentiate a particular element or object type from others, but
have no semantic meaning.  These are simply included in the pattern
verbatim.  For instance, if a pattern consists of two plus signs (`+`)
immediately followed by a TOKEN it would be written like so:

    ++TOKEN

Since tokens are written in uppercase, any letters in static
structures are distinguished by being written in lowercase.


<a id="Special_Tokens"></a>

### Special tokens

In a few cases, an instance of an element or object must be preceded
or succeeded by a certain pattern, which is not itself part of the
element or object.  These patterns are specified using the *PRE* and
*POST* tokens respectively, like so:

    PRE TOKEN POST

*PRE* and *POST* tokens are only matched against the contents of the
containing object. For example, *bold* object within link description is
only matched against the description text `*bold* description`, not
against the full containing link text:

    [[https://orgmode.org][*bold* description]]


<a id="org6b5accb"></a>

### Case significance

In this document, unless specified otherwise, case is insignificant.


<a id="orgff340c9"></a>

## References to lisp variables

Some parts of Org syntax are configurable via special keywords in the
file or via Elisp settings in Emacs.  This syntax document exposes
these variable parts by referencing to Elisp variables.

Elisp programs utilizing the syntax may directly refer to the Elisp
variable values.  Other users of this syntax reference can use to the
default values we provide here.


<a id="org6866ffd"></a>

# General structure of Org document

Any Org document is represented by a sequence of [elements](#Elements), that can
recursively contain other [elements](#Elements) and/or [objects](#Objects).

An example document below can be represented as recursive syntax tree:

    #+title: An example Org document (this line is a keyword)
    
    The document begins with optional zeroth section (everything before
    the first heading), followed by a sequence of headings. (paragraph)
    
    
        :note:
        Zeroth section can contain other elements - keyword, paragraph,
        and drawer in this example.
    
        The drawer, in turn, contains the previous and this paragraph; and
        this paragraph consists of plain text objects, and a single *bold
        markup*.
        :end:
    
    * Heading
    
    Contains an optional section that is, similar to zeroth section,
    followed by other subheadings.
    
    ** Sub-heading 1 with no section and no child headings
    ** Sub-heading 2
    ... has a section, but not child subheadings.
    
    * Another heading

    (org-data ...
     (zeroth-section ...
      (keyword ...)
      (paragraph ...)
      (drawer
       (paragraph ...)
       (pragraph (plain-text) (bold (plain-text)))))
     (heading
      (section (paragraph ...))
      (heading)
      (heading (section ...)))
     (heading))


<a id="Elements"></a>

# Elements

The most general representation of an Org syntax element is a sequence
of markup defining the element itself, its contents, and the [blank
lines](#Blanks) after.

    BEGIN
    CONTENTS
    END
    BLANK

or

    BEGIN
    VALUE
    END
    BLANK

-   **BEGIN:** Opening markup, belong to the element.
-   **CONTENTS:** Element contents - a sequence of child elements/objects.
-   **VALUE:** Element value, taken verbatim, when no child
    elements/objects are allowed.
-   **END:** Closing markup, belong to the element.
-   **BLANK:** Blank lines after, belongs to the element.

Not every Org element contains all the above components.  An example
below demonstrates structure of some common Org elements, marking the
parts corresponding to the above structure.

    * Heading title is a part of the headline element itself <BEGIN>
    
    
    Text inside heading is considered a part of its CONTENTS and can
    contain other elements recursively.  This paragraph only has CONTENTS,
    no BEGIN, no END, and a BLANK line.
    
    :drawer:
    The same works at the deeper levels, with this drawer having
    =:drawer:= line as BEGIN, this paragraph belonging to drawer CONTENTS,
    =:end:= representing END, and no BLANK after.
    :end:
    #+begin_comment
    A comment is taken verbatim, with this text not parsed recursively and
    considered a part of the comment block element itself.
    =#+begin_commend= is BEGIN, =#+end_comment= - END, and VALUE is this
    text.
    #+end_comment
    This is the end of the heading, no END exists for headings.


<a id="Headings_and_Sections"></a>

## Headings and Sections


<a id="Headings"></a>

### Headings

A Heading is an *unindented* line structured according to the following pattern:

    STARS KEYWORD PRIORITY COMMENT TITLE TAGS

-   **STARS:** A string consisting of one or more asterisks (up to
    `org-inlinetask-min-level`<sup><a id="fnr.oiml" class="footref" href="#fn.oiml" role="doc-backlink">3</a></sup> if the `org-inlinetask` library is
    loaded) suffixed by a space character.  The number of asterisks is
    used to define the level of the heading.  Space character after
    asterisks is mandatory.

-   **KEYWORD (optional):** A string which is a member of
    `org-todo-keywords-1`<sup><a id="fnr.otkw1" class="footref" href="#fn.otkw1" role="doc-backlink">4</a></sup>.
    Case is significant.  This is called a &ldquo;todo keyword&rdquo;. <sup><a id="fnr.5" class="footref" href="#fn.5" role="doc-backlink">5</a></sup>

-   **PRIORITY (optional):** A single alphanumeric character preceded by a
    hash sign `#` and enclosed within square brackets (e.g. `[#A]` or `[#1]`).  This
    is called a &ldquo;priority cookie&rdquo;.

-   **COMMENT (optional):** String &ldquo;COMMENT&rdquo;.  Case is significant.

-   **TITLE (optional):** A series of objects from the <a href="#org16495ef">standard set</a>,
    excluding line break objects.  It is matched after `KEYWORD` and
    `PRIORITY`.

-   **TAGS (optional):** A series of colon-separated strings consisting of
    alpha-numeric characters, underscores, at signs, hash signs, and
    percent signs (`_@#%`).

**Examples**

    *
    ** DONE
    *** Some e-mail
    **** TODO [#A] COMMENT Title :tag:a2%:

If heading has `COMMENT`, it will be considered as &ldquo;commented&rdquo;.

If the TITLE of a heading is exactly the value of `org-footnote-section`
(`Footnotes` by default), it will be considered as a &ldquo;footnote section&rdquo;.
Case is significant.

If `ARCHIVE` is one of the tags given, the heading will be considered as
&ldquo;archived&rdquo;.  Case is significant.

All content following a heading &#x2014; up to either the next heading, or the end of the
document, forms a section contained by the heading. This is optional, as the
next heading may occur immediately in which case no section is formed.


<a id="Sections"></a>

### Sections

Sections contain one or more non-heading elements.  With the exception
of the text before the first heading in a document (which is
considered a section), sections only occur within headings.

**Example**

Consider the following document:

    An introduction.
    * A Heading
    Some text.
    ** Sub-Topic 1
    ** Sub-Topic 2
    *** Additional entry

Its internal structure could be summarized as:

    (document
     (section)
     (heading
      (section)
      (heading)
      (heading
       (heading))))

Sections do not include blank lines immediately following the parent
heading.  It also means that headings containing only blank lines do
not contain any section.

    * Heading without section, but with blank lines
    
    * Another heading with section
    
    This is a section. It includes everything from "This is" down to "Last
    heading", including the trailing blank lines.
    
    * Last heading

[Zeroth section](#Zeroth_section) follows the same rule.


<a id="Zeroth_section"></a>

### The zeroth section

All elements before the first heading in a document lie in a special
section called the *zeroth section*.  It may be preceded by blank
lines.  Unlike a normal section, the zeroth section can immediately
contain a [property drawer](#Property_Drawers), optionally preceded by [comments](#Comments).  It cannot
however, contain [planning](#Planning).


<a id="Greater_Elements"></a>

## Greater Elements

Unless otherwise specified, greater elements can directly contain
any greater or [lesser element](#Lesser_Elements) except:

-   Elements of their own type.
-   [Planning](#Planning), which may only occur in a [heading](#Headings).
-   [Property drawers](#Property_Drawers), which may only occur in a [heading](#Headings) or the [zeroth
    section](#Zeroth_section).
-   [Node properties](#Node_Properties), which can only be found in [property drawers](#Property_Drawers).
-   [Items](#Items), which may only occur in [plain lists](#Plain_Lists).
-   [Table rows](#Table_Rows), which may only occur in [tables](#Tables).


<a id="Greater_Blocks"></a>

### Greater Blocks

Greater blocks are structured according to the following pattern:

    #+begin_NAME PARAMETERS
    CONTENTS
    #+end_NAME

-   **NAME:** A string consisting of any non-whitespace characters, which
    is not the NAME of a [lesser block](#Blocks).  Greater blocks are treated
    differently based on their subtype, which is determined by the NAME
    as follows:
    -   `center`, a &ldquo;center block&rdquo;
    -   `quote`, a &ldquo;quote block&rdquo;
    -   any other value, a &ldquo;special block&rdquo;
-   **PARAMETERS (optional):** A string consisting of any characters other
    than a newline.
-   **CONTENTS:** A collection of zero or more elements, subject to the
    following condition:
    -   No line may start with `#+end_NAME`.


<a id="Drawers"></a>

### Drawers and Property Drawers

Drawers are structured according to the following pattern:

    :NAME:
    CONTENTS
    :end:

-   **NAME:** A string consisting of word-constituent characters, hyphens
    and underscores (`-_`).
-   **CONTENTS:** A collection of zero or more elements, except another drawer.


<a id="Dynamic_Blocks"></a>

### Dynamic Blocks

Dynamic blocks are structured according to the following pattern:

    #+begin: NAME PARAMETERS
    CONTENTS
    #+end:

-   **NAME:** A string consisting of non-whitespace characters.
-   **PARAMETERS (optional):** A string consisting of any characters but a newline.
-   **CONTENTS:** A collection of zero or more elements, except another
    dynamic block.


<a id="Footnote_Definitions"></a>

### Footnote Definitions

Footnote definitions must occur at the start of an *unindented* line,
and are structured according to the following pattern:

    [fn:LABEL] CONTENTS

-   **LABEL:** Either a number or an instance of the pattern `WORD`, where
    `WORD` represents a string consisting of word-constituent characters,
    hyphens and underscores (`-_`).

-   **CONTENTS (optional):** A collection of zero or more elements.  It
    ends at the next footnote definition, the next heading, two
    consecutive blank lines, or the end of buffer.

**Examples**

    [fn:1] A short footnote.
    
    [fn:2] This is a longer footnote.
    
    It even contains a single blank line.


<a id="Inlinetasks"></a>

### Inlinetasks

Inlinetasks are syntactically a [heading](#Headings) with a level of at least
`org-inlinetask-min-level`<sup><a id="fnr.oiml.3" class="footref" href="#fn.oiml" role="doc-backlink">3</a></sup>, i.e. starting with at least that
many asterisks.

Optionally, inlinetasks can be ended with a second heading with a
level of at least `org-inlinetask-min-level`<sup><a id="fnr.oiml.3" class="footref" href="#fn.oiml" role="doc-backlink">3</a></sup>, with no optional
components (i.e. only STARS and TITLE provided) and the string `END` as
the TITLE. This allows the inlinetask to contain elements.

**Examples**

    *************** TODO some tiny task
    This is a paragraph, it lies outside the inlinetask above.
    *************** TODO some small task
                     DEADLINE: <2009-03-30 Mon>
                     :PROPERTIES:
                       :SOMETHING: or other
                     :END:
                     And here is some extra text
    *************** END

Inlinetasks are only recognized after the `org-inlinetask` library is
loaded.


<a id="Items"></a>

### Items

Items are structured according to the following pattern:

    BULLET COUNTER-SET CHECK-BOX TAG CONTENTS

-   **BULLET:** One of the two forms below, followed by either a
    whitespace character or line ending.
    -   An asterisk (`*`), hyphen (`-`), or plus sign (`+`) character.
        Note that asterisk `*` character starting at the beginning of
        line and followed by whitespace cannot be an item as it would
        match a [heading](#Headings).
    -   Either the pattern `COUNTER.` or `COUNTER)`.
        -   **COUNTER:** Either a number or a single letter (a-z).
-   **COUNTER-SET (optional):** An instance of the pattern `[@COUNTER]`.
-   **CHECK-BOX (optional):** A single whitespace character, an `X`
    character, or a hyphen enclosed by square brackets (i.e. `[ ]`, `[X]`, or `[-]`).
-   **TAG (optional):** An instance of the pattern `TAG-TEXT ::` where
    `TAG-TEXT` is the text up until the last occurrence of the substring
    `" :: "` (two colons surrounded by whitespace, without the quotes) on
    that line.  `TAG-TEXT` is then parsed with the <a href="#org16495ef">standard set</a> of objects.
-   **CONTENTS (optional):** A collection of zero or more elements, ending
    at the first instance of one of the following:
    -   The next item.
    -   The first line less or equally indented than the starting line,
        not counting lines within other non-paragraph elements or
        [inlinetask](#Inlinetasks) boundaries.
    -   Two consecutive blank lines.

**Examples**

    - item
    3. [@3] set to three
    + [-] tag :: item contents
     * item, note whitespace in front
    * not an item, but heading - heading takes precedence


<a id="Plain_Lists"></a>

### Plain Lists

A *plain list* is a set of consecutive [items](#Items) of the same indentation.

<div class="infobox" id="orgee70b45">
<p>
Note that item elements can contain other lists.  This allows creating
nested lists.
</p>

</div>

If first item in a plain list has a COUNTER in its BULLET, the plain
list will be an &ldquo;ordered plain-list&rdquo;.  If it contains a TAG, it will
be a &ldquo;descriptive list&rdquo;.  Otherwise, it will be an &ldquo;unordered list&rdquo;.

For example, consider the following excerpt of an Org document:

    1. item 1
    2. [X] item 2
       - some tag :: item 2.1

Its internal structure is as follows:

    (ordered-plain-list
     (item
       (paragraph))
     (item
      (paragraph)
      (descriptive-plain-list
       (item
         (paragraph)))))


<a id="Property_Drawers"></a>

### Property Drawers

Property drawers are a special type of [drawer](#Drawers) containing properties
attached to a [heading](#Headings) or [inlinetask](#Inlinetasks).  They are located right after a heading
and its [planning](#Planning) information, as shown below:

    HEADLINE
    PROPERTYDRAWER
    
    HEADLINE
    PLANNING
    PROPERTYDRAWER

Property drawer can also be present in [zeroth section](#Zeroth_section):

    BEGINNING-OF-FILE
    BLANK-LINES
    COMMENT
    PROPERTYDRAWER

`BLANK-LINES` and `COMMENT` are optional.

Property Drawers are structured according to the following pattern:

    :properties:
    CONTENTS
    :end:

-   **CONTENTS:** A collection of zero or more [node properties](#Node_Properties), not
    separated by blank lines.

**Example**

    * Heading
    :PROPERTIES:
    :CUSTOM_ID: someid
    :END:


<a id="Tables"></a>

### Tables

Tables are started by a line beginning with either:

-   A vertical bar (`|`), forming an &ldquo;org&rdquo; type table.
-   The string `+-` followed by a sequence of plus (`+`) and minus (`-`)
    signs, forming a &ldquo;table.el&rdquo; type table.

Tables cannot be immediately preceded by such lines, as the current
line would the be part of the earlier table.

Org tables contain [table rows](#Table_Rows), and end at the first line not starting
with a vertical bar. An Org table can be followed by a number of
`#+TBLFM: FORMULAS` lines, where `FORMULAS` represents a string consisting
of any characters but a newline.

Table.el tables end at the first line not starting with either
a vertical line (`|`) or a plus sign (`+`).

**Examples**

    Org table:
    | Name  | Phone | Age | Age - 24 |
    |-------+-------+-----+----------|
    | Peter |  1234 |  24 |       -1 |
    | Anna  |  4321 |  25 |        7 |
    | Susan |  9876 |  18 |          |
    #+TBLFM: @<$4..@>>$4 = $3 - @+1$3
    
    Table.el table:
    +------+-----+-----+
    |Name  |Phone|Age  |
    +------+-----+-----+
    |Peter |1234 |24   |
    +------+-----+-----+
    |Anna  |4321 |25   |
    |Turner|     |     |
    +------+-----+-----+


<a id="Lesser_Elements"></a>

## Lesser Elements

Lesser elements cannot contain any other element.

Only [keywords](#Keywords) which are a member of `org-element-parsed-keywords`<sup><a id="fnr.oepkw" class="footref" href="#fn.oepkw" role="doc-backlink">6</a></sup>, [verse
blocks](#Blocks), [paragraphs](#Paragraphs) or [table rows](#Table_Rows) can contain objects.


<a id="Blocks"></a>

### Blocks

Like [greater blocks](#Greater_Blocks), blocks are structured according to the following pattern:

    #+begin_NAME DATA
    CONTENTS
    #+end_NAME

-   **NAME:** A string consisting of any non-whitespace characters.  The
    type of the block is determined based on the value as follows:
    -   `comment`, a &ldquo;comment block&rdquo;,
    -   `example`, an &ldquo;example block&rdquo;,
    -   `export`, an &ldquo;export block&rdquo;,
    -   `src`, a &ldquo;source block&rdquo;,
    -   `verse`, a &ldquo;verse block&rdquo;.
        The NAME must be one of these values.  Otherwise, the pattern
        forms a greater block.
-   **DATA (optional):** A string consisting of any characters but a newline.
    -   In the case of an export block, this is mandatory and must be a
        single word.
    -   In the case of a source block, this is mandatory and must follow
        the pattern `LANGUAGE SWITCHES ARGUMENTS` with:
        -   **LANGUAGE:** A string consisting of any non-whitespace characters
        -   **SWITCHES:** Any number of SWITCH patterns, separated by a single
            space character
            -   **SWITCH:** Either the pattern `-l "FORMAT"` where `FORMAT`
                represents a string consisting of any characters but a double
                quote (`"`) or newline, or the pattern `-S` or `+S` where `S`
                represents a single alphabetic character
        -   **ARGUMENTS:** A string consisting of any character but a newline.
-   **CONTENTS (optional):** A string consisting of any characters
    (including newlines) subject to the same two conditions of greater
    block&rsquo;s CONTENTS, i.e.
    
    -   No line may start with `#+end_NAME`.
    -   Lines beginning with an asterisk must be quoted by a comma (`,*`)
        and lines beginning with `#+` may be quoted by a comma when
        necessary (`#+`).
    
    CONTENTS will contain Org objects and not support comma-quoting when
    the block is a verse block, it is otherwise not parsed.

**Example**

    #+begin_verse
        There was an old man of the Cape
       Who made himself garments of crepe.
           When asked, “Do they tear?”
          He replied, “Here and there,
     But they’re perfectly splendid for shape!”
    #+end_verse

    #+begin_src emacs-lisp
    "This string
    * has "*" escaped.
    Otherwise, '* has "*" escaped.' would be treated as a heading (which
    is context-free)."
    
    "#+ lines may or may not need to be escaped:
    #+end_src if not escaped, would be this source block.
    However,
    #+keyword: does not interfere with code block end and may be left as is.
    #+keyword may be escaped as well, optionally - parser removes all the
    commas in ,* and ,#+ lines."
    #+end_src


<a id="Clocks"></a>

### Clock

A clock element is structured according to the following pattern:

    clock: INACTIVE-TIMESTAMP
    clock: INACTIVE-TIMESTAMP-RANGE DURATION
    clock: DURATION

-   **INACTIVE-TIMESTAMP:** An inactive [timestamp](#Timestamps) object.
-   **INACTIVE-TIMESTAMP-RANGE:** An inactive range [timestamp](#Timestamps) object.
-   **DURATION:** An instance of the pattern `=> HH:MM`.
    -   **HH:** A number consisting of any number of digits.
    -   **MM:** A two digit number.

**Examples**

    clock: [2024-10-12]
    CLOCK: [2019-03-25 Mon 10:49]--[2019-03-25 Mon 11:31] =>  0:42
    clock: => 12:30


<a id="Diary_Sexp"></a>

### Diary Sexp

A diary sexp<sup><a id="fnr.7" class="footref" href="#fn.7" role="doc-backlink">7</a></sup> element is an
*unindented* line structured according to the following pattern:

    %%SEXP

-   **SEXP:** A string starting with an open parenthesis `(`, with balanced
    opening and closing parentheses.

**Example**

    %%(org-calendar-holiday)


<a id="Planning"></a>

### Planning

A planning element is structured according to the following pattern:

    HEADING
    PLANNING

-   **HEADING:** A [heading](#Headings) element.
-   **PLANNING:** A line consisting of one or more `KEYWORD: TIMESTAMP`
    patterns (termed &ldquo;info&rdquo; patterns).
    -   **KEYWORD:** Either the string `DEADLINE`, `SCHEDULED`, or `CLOSED`.
    -   **TIMESTAMP:** A [timestamp](#Timestamps) object.

PLANNING must directly follow HEADING without any blank lines in
between.

When a keyword is repeated in a planning element, the last instance of it has
priority.

**Example**

    *** TODO watch "The Matrix"
        SCHEDULED: <1999-03-31 Wed>
    *** TODO take over the world with Org mode
        SCHEDULED: <2006-03-12 Sun> DEADLINE: <2034-03-22 Wed>


<a id="Comments"></a>

### Comments

A &ldquo;comment line&rdquo; starts with a hash character (`#`) and either a whitespace
character or the immediate end of the line.

Comments consist of one or more consecutive comment lines.

**Example**

    # Just a comment
    #
    # Over multiple lines


<a id="Fixed_Width_Areas"></a>

### Fixed Width Areas

A &ldquo;fixed-width line&rdquo; starts with a colon character (`:`) and either a
space character or the immediate end of the line.

Fixed-width areas consist of one or more consecutive fixed-width lines.

**Example**

    : This is a
    : fixed width area


<a id="Horizontal_Rules"></a>

### Horizontal Rules

A horizontal rule is formed by a line consisting of at least five
consecutive hyphens (`-----`).


<a id="Keywords"></a>

### Keywords

Keywords are structured according to the following pattern:

    #+KEY: VALUE

-   **KEY:** A string consisting of any non-whitespace characters, other
    than `call` (which would forms a [babel call](#Babel_Call) element).
-   **VALUE:** A string consisting of any characters but a newline.

When KEY is a member of `org-element-parsed-keywords`<sup><a id="fnr.oepkw.6" class="footref" href="#fn.oepkw" role="doc-backlink">6</a></sup>, VALUE can contain
the <a href="#org16495ef">standard set</a> objects, excluding [footnote references](#Footnote_References).

Note that while instances of this pattern are preferentially parsed as
[affiliated keywords](#Affiliated_Keywords), a keyword with the same KEY as an affiliated
keyword may occur so long as it is not immediately preceding a valid
element that can be affiliated.  For example, an instance of
`#+caption: hi` followed by a blank line will be parsed as a keyword,
not an affiliated keyword.

1.  Babel Call

    Babel calls are structured according to one of the following patterns:
    
        #+call: NAME(ARGUMENTS)
        #+call: NAME[HEADER1](ARGUMENTS)
        #+call: NAME(ARGUMENTS)[HEADER2]
        #+call: NAME[HEADER1](ARGUMENTS)[HEADER2]
    
    -   **NAME:** A string consisting of any non-newline characters except for
        square brackets, or parentheses (`[]()`).
    -   **ARGUMENTS (optional):** A string consisting of any non-newline
        characters.  Opening and closing parenthesis must be balanced.
    -   **HEADER1 (optional), HEADER2 (optional):** A string consisting of any
        non-newline characters.  Opening and closing square brackets must be
        balanced.

2.  Affiliated Keywords

    With the exception of [comments](#Comments), [clocks](#Clocks), [headings](#Headings), [inlinetasks](#Inlinetasks),
    [items](#Items), [node properties](#Node_Properties), [planning](#Planning), [property drawers](#Property_Drawers), [sections](#Sections), and
    [table rows](#Table_Rows), every other element type can be assigned attributes.
    
    This is done by adding specific [keywords](#Keywords), named *affiliated* keywords,
    immediately above the element considered (a blank line cannot lie
    between the affiliated keyword and element). Structurally, affiliated
    keyword are not considered an element in their own right but a
    property of the element they apply to.
    
    Affiliated keywords are structured according to one of the following pattern:
    
        #+KEY: VALUE
        #+KEY[OPTVAL]: VALUE
        #+attr_BACKEND: VALUE
    
    -   **KEY:** A string which is a member of
        `org-element-affiliated-keywords`<sup><a id="fnr.oeakw" class="footref" href="#fn.oeakw" role="doc-backlink">8</a></sup>.
    -   **BACKEND:** A string consisting of alphanumeric characters, hyphens,
        or underscores (`-_`).
    -   **OPTVAL (optional):** A string consisting of any characters but a
        newline.  Opening and closing square brackets must be balanced.
        This term is only valid when KEY is a member of
        `org-element-dual-keywords`<sup><a id="fnr.oedkw" class="footref" href="#fn.oedkw" role="doc-backlink">9</a></sup>.
    -   **VALUE:** A string consisting of any characters but a newline, except
        in the case where KEY is member of
        `org-element-parsed-keywords`<sup><a id="fnr.oepkw.6" class="footref" href="#fn.oepkw" role="doc-backlink">6</a></sup> in which case VALUE
        is a series of objects from the <a href="#org16495ef">standard set</a>, excluding footnote
        references.
    
    Repeating an affiliated keyword before an element will usually result
    in the prior VALUEs being overwritten by the last instance of KEY.
    The sole exception to this is `#+header:` keywords, where in the case of multiple
    `:opt val` declarations the last declaration on the first line it occurs on has
    priority.
    
    There are two situations under which the VALUEs will be concatenated:
    
    1.  If KEY is a member of `org-element-dual-keywords`<sup><a id="fnr.oedkw.9" class="footref" href="#fn.oedkw" role="doc-backlink">9</a></sup>.
    2.  If the affiliated keyword is an instance of the pattern
        `#+attr_BACKEND: VALUE`.
    
    When no element immediately follows an instance of the &ldquo;affiliated
    keyword&rdquo; pattern, the keyword is a normal, non-affiliated keyword.
    
    The following example contains three affiliated keywords:
    
        #+name: image-name
        #+caption: This is a caption for
        #+caption: the image linked below
        [[file:some/image.png]]


<a id="LaTeX_Environments"></a>

### LaTeX Environments

LaTeX environments are structured according to the following pattern:

    \begin{NAME}EXTRA
    CONTENTS
    \end{NAME}

-   **NAME:** A non-empty string consisting of alphanumeric or asterisk characters
-   **EXTRA (optional):** A string which does not contain the substring
    `\end{NAME}`.
-   **CONTENTS (optional):** A string which does not contain the substring
    `\end{NAME}`.

**Examples**

    \begin{align*}
    2x - 5y &= 8 \\
    3x + 9y &= -12
    \end{align*}


<a id="Node_Properties"></a>

### Node Properties

Node properties can only exist in [property drawers](#Property_Drawers), and are structured
according to one of the following patterns:

    :NAME: VALUE
    :NAME:
    :NAME+: VALUE
    :NAME+:

-   **NAME:** A non-empty string containing any non-whitespace characters
    which does not end in a plus characters (`+`).
-   **VALUE (optional):** A string containing any characters but a newline.


<a id="Paragraphs"></a>

### Paragraphs

Paragraphs are the default element, which means that any
unrecognized context is a paragraph.

Empty lines and other elements end paragraphs.

Paragraphs can contain the <a href="#org16495ef">standard set</a> of objects.


<a id="Table_Rows"></a>

### Table Rows

A table row consists of a vertical bar (`|`) followed by:

-   Any number of [table cells](#Table_Cells), forming a &ldquo;standard&rdquo; type row.
-   A hyphen (`-`), forming a &ldquo;rule&rdquo; type row.  Any non-newline characters
    can follow the hyphen and this will still be a &ldquo;rule&rdquo; type row

Table rows can only exist in [tables](#Tables) with Org type.


<a id="Objects"></a>

# Objects

Objects can only be found in the following elements:

-   [keywords](#Keywords) or [affiliated keywords](#Affiliated_Keywords) VALUEs, when KEY is a member of
    `org-element-parsed-keywords`<sup><a id="fnr.oepkw.6" class="footref" href="#fn.oepkw" role="doc-backlink">6</a></sup>,
-   [heading](#Headings) TITLEs,
-   [inlinetask](#Inlinetasks) TITLEs,
-   [item](#Items) TAGs,
-   [clock](#Clocks) INACTIVE-TIMESTAMP and INACTIVE-TIMESTAMP-RANGE, which can
    only contain inactive timestamps,
-   [planning](#Planning) TIMESTAMPs, which can only be timestamps,
-   [paragraphs](#Paragraphs),
-   [table cells](#Table_Cells),
-   [table rows](#Table_Rows), which can only contain table cell objects,
-   [verse blocks](#Blocks).

Org syntax objects have a similar structure to [elements](#Elements), except blank
lines being replaced by trailing spaces:

    BEGIN CONTENTS END BLANK
    BEGIN VALUE END BLANK

Most objects cannot contain objects.  Those which can will be
specified.  Furthermore, while many objects may contain newlines, a
blank line often terminates the element that the object is a part of,
such as a paragraph.

Trailing spaces at the end of objects are considered a part of those
objects.

    This *bold markup*      also includes the subsequent trailing spaces into
    the bold object.
    
    *This is not a bold markup
    
    because the previous blank line separates the containing paragraph*.


<a id="Entities"></a>

## Entities

Entities are structured according to the following patterns:

    \NAME POST
    \NAME{}
    \_SPACES

Where NAME and POST are not separated by a whitespace character.

-   **NAME:** A string with a valid association in either
    `org-entities`<sup><a id="fnr.oe" class="footref" href="#fn.oe" role="doc-backlink">10</a></sup> or
    `org-entities-user`.
-   **[POST](#Special_Tokens):** Either:
    -   The end of line.
    -   A non-alphabetic character.
-   **SPACES:** One or more spaces, constituting a whitespace entity with
    name `_SPACES` from `org-entities` or `org-entities-user`.

**Example**

    1\cent.
    1.5em space:\_   here, all three spaces in =\_   = constitute the entity name.


<a id="LaTeX_Fragments"></a>

## LaTeX Fragments

LaTeX fragments are structured according to one of the following patterns:

    \NAME BRACKETS
    \(CONTENTS\)
    \[CONTENTS\]

-   **NAME:** A string consisting of alphabetic characters which does not
    have an association in either `org-entities` or `org-entities-user`.
-   **BRACKETS (optional):** An instance of one of the following patterns,
    not separated from NAME by whitespace.
    
        [CONTENTS1]
        {CONTENTS1}
    
    -   **CONTENTS1:** A string consisting of any characters but `{`, `}`, `[`,
        `]`, or a newline.
    -   **CONTENTS2:** A string consisting of any characters but `{`, `}`, or a newline.
-   **CONTENTS:** A string consisting of any characters, so long as it does
    not contain the substring `\)` in the case of the
    second template, or `\]` in the case of the third template.

**Examples**

    \enlargethispage{2\baselineskip}
    \(e^{i \pi}\)

Org also supports TeX-style inline LaTeX fragments, structured
according the following pattern:

    $$CONTENTS$$
    PRE$CHAR$POST
    PRE$BORDER1 BODY BORDER2$POST

-   **[PRE](#Special_Tokens):** Either the beginning of line or a character other than `$`.
-   **CHAR:** A non-whitespace character that is not `.`, `,`, `?`, `;`, or a
    double quote (`"`).
-   **[POST](#Special_Tokens):** Any punctuation character (including parentheses and
    quotes), a space character, or the end of line.
-   **BORDER1:** A non-whitespace character that is not `.`, `,`, `;`, or `$`.
-   **BODY:** A string consisting of any characters except `$`.
-   **BORDER2:** A non-whitespace character that is not `.`, `,`, or `$`.

**Example**

    $$1+1=2$$


<a id="Export_Snippets"></a>

## Export Snippets

Export snippets are structured according to the following pattern:

    @@BACKEND:VALUE@@

-   **BACKEND:** A string consisting of one or more alphanumeric characters and hyphens.
-   **VALUE (optional):** A string containing anything but the string `@@`.


<a id="Footnote_References"></a>

## Footnote References

Footnote references are structured according to one of the following patterns:

    [fn:LABEL]
    [fn:LABEL:DEFINITION]
    [fn::DEFINITION]

-   **LABEL:** A string containing one or more word constituent characters,
    hyphens and underscores (`-_`).
-   **DEFINITION (optional):** One or more objects from the <a href="#org16495ef">standard set</a>,
    so long as opening and closing square brackets are balanced within
    DEFINITION.

If the reference follows the second pattern, it is called an &ldquo;inline
footnote&rdquo;.  If it follows the third pattern, i.e. if LABEL is omitted,
it is called an &ldquo;anonymous footnote&rdquo;.

Note that the first pattern may not occur on an *unindented* line, as it
is then a [footnote definition](#Footnote_Definitions).


<a id="Citations"></a>

## Citations

Citations are structured according to the following pattern:

    [cite CITESTYLE: REFERENCES]
    [cite CITESTYLE: GLOBALPREFIX;REFERENCES]
    [cite CITESTYLE: REFERENCES;GLOBALSUFFIX]
    [cite CITESTYLE: GLOBALPREFIX;REFERENCES;GLOBALSUFFIX]

Where &ldquo;cite&rdquo; and `CITESTYLE` are *not* separated by whitespace.
Whitespace after the leading colon or before the closing square
bracket is not significant.

-   **CITESTYLE (optional):** An instance of either the pattern `/STYLE` or `/STYLE/VARIANT`
    -   **STYLE:** A string made of any alphanumeric character, `_`, or `-`.
    -   **VARIANT:** A string made of any alphanumeric character, `_`, `-`, or `/`.
-   **GLOBALPREFIX (optional):** One or more objects from the <a href="#org16495ef">standard set</a>,
    so long as all square brackets are balanced within GLOBALPREFIX, and
    it does not contain any semicolons (`;`) or subsequence that matches
    `@KEY`.
-   **REFERENCES:** One or more [citation reference](#Citation_References) objects, separated by
    semicolons (`;`).
-   **GLOBALSUFFIX (optional):** One or more objects from the <a href="#org16495ef">standard set</a>,
    so long as all square brackets are balanced within GLOBALSUFFIX, and
    it does not contain any semicolons (`;`) or subsequence that matches
    `@KEY`.

**Examples**

    [cite:@key]
    [cite/t: see;@source1;@source2;by Smith /et al./]


<a id="Citation_References"></a>

## Citation references

A reference to an individual resource is given in a *citation reference*
object.  Citation references are only found within [citations](#Citations), and are
structured according to the following pattern:

    KEYPREFIX @KEY KEYSUFFIX

Where KEYPREFIX, @​KEY, and KEYSUFFIX are not separated by whitespace
(all the whitespace is significant).

-   **KEYPREFIX (optional):** One or more objects from the <a href="#org360f63a">minimal set</a>,
    so long as all square brackets are balanced within KEYPREFIX, and
    it does not contain any semicolons (`;`) or subsequence that matches
    `@KEY`.
-   **KEY:** A string made of any word-constituent character, `-`, `.`, `:`,
    `?`, `!`, `` ` ``, `'`, `/`, `*`, `@`, `+`, `|`, `(`, `)`, `{`, `}`, `<`, `>`, `&`, `_`, `^`, `$`, `#`, `%`, or
    `~`.
-   **KEYSUFFIX (optional):** One or more objects from the <a href="#org360f63a">minimal set</a>,
    so long as all square brackets are balanced within KEYPREFIX, and
    it does not contain any semicolons (`;`).

**Examples**

    [cite:@key]
    [cite/t:see;@foo p. 7;@bar pp. 4;by foo]
    [cite/a/f:c.f.;the very important @@atkey @ once;the crucial @baz vol. 3]


<a id="Inline_Babel_Calls"></a>

## Inline Babel Calls

Inline Babel calls are structured according to one of the following patterns:

    call_NAME(ARGUMENTS)
    call_NAME[HEADER1](ARGUMENTS)
    call_NAME(ARGUMENTS)[HEADER2]
    call_NAME[HEADER1](ARGUMENTS)[HEADER2]

-   **NAME:** A string consisting of any non-whitespace characters except
    for square brackets or parentheses (`[](​)`).
-   **ARGUMENTS, HEADER1 (optional), HEADER2 (optional):** A string
    consisting of zero or more non-newline characters.  Opening and
    closing square brackets must be balanced within HEADER1 and HEADER2,
    and opening and closing parenthesis - within ARGUMENTS.


<a id="Source_Blocks"></a>

## Inline Source Blocks

Inline source blocks follow any of the following patterns:

    src_LANG{BODY}
    src_LANG[HEADERS]{BODY}

-   **LANG:** A string consisting of any characters other than whitespace,
    the opening square bracket (`[`), or opening curly bracket (`{`).
-   **HEADERS (optional), BODY:** A string consisting of zero or more
    non-newline characters.  Opening and closing square brackets must be
    balanced within HEADERS, and opening and closing curly brackets
    within BODY.


<a id="Line_Breaks"></a>

## Line Breaks

Line breaks must occur at the end of an otherwise non-blank line, and
are structured according to the following pattern:

    PRE\\SPACE

-   **[PRE](#Special_Tokens):** Anything but backslash (`\`).
-   **SPACE:** Zero or more tab and space characters.


<a id="Links"></a>

## Links

While links are a single object, they come in four subtypes: &ldquo;radio&rdquo;,
&ldquo;angle&rdquo;, &ldquo;plain&rdquo;, and &ldquo;regular&rdquo; links.


<a id="org11691d3"></a>

### Radio Links

Radio-type links are structured according to the following pattern:

    PRE RADIO POST

-   **[PRE](#Special_Tokens):** A non-alphanumeric character.
-   **RADIO:** One or more objects matched by some [radio target](#Targets_and_Radio_Targets).  It can
    contain the <a href="#org360f63a">minimal set</a> of objects.
-   **[POST](#Special_Tokens):** A non-alphanumeric character.

**Example**

    This is some <<<*important* information>>> which we refer to lots.
    Make sure you remember the *important* information.

The first instance of `*important* information` defines a radio target,
which is matched by the second instance of `*important* information`,
forming a radio link.


<a id="org907fd8e"></a>

### Plain links

Plain-type links are structured according to the following pattern:

    PRE LINKTYPE:PATHPLAIN POST

-   **[PRE](#Special_Tokens):** A non word constituent character.
-   **LINKTYPE:** A string which is one of the link type strings in
    `org-link-parameters`<sup><a id="fnr.olp" class="footref" href="#fn.olp" role="doc-backlink">11</a></sup>.
-   **PATHPLAIN:** A string containing non-whitespace non-bracket (`()[]<>`)
    characters, optionally containing parenthesis-wrapped non-whitespace
    non-bracket substrings up to a depth of two. The string must end
    with either a non-punctation non-whitespace character, a forwards
    slash, or a parenthesis-wrapped substring.<sup><a id="fnr.12" class="footref" href="#fn.12" role="doc-backlink">12</a></sup>
-   **[POST](#Special_Tokens):** A non word constituent character.

**Example**

    Be sure to look at https://orgmode.org.


<a id="org1e18b4b"></a>

### Angle links

Angle-type essentially provide a method to disambiguate plain links
from surrounding text, and are structured according to the following
pattern:

    <LINKTYPE:PATHANGLE>

-   **LINKTYPE:** A string which is one of the link type strings in
    `org-link-parameters`<sup><a id="fnr.olp.11" class="footref" href="#fn.olp" role="doc-backlink">11</a></sup>
-   **PATHANGLE:** A string containing any character but `>`., where newlines
    and indentation are ignored.

The angle brackets allow for a more permissive PATH syntax, without
accidentally matching surrounding text.


<a id="orgfdd84dc"></a>

### Regular links

Plain-type links are structured according to one of the following two patterns:

    [[PATHREG]]
    [[PATHREG][DESCRIPTION]]

-   **PATHREG:** An instance of one of the seven following annotated patterns:
    
        FILENAME               ("file" type)
        LINKTYPE:PATHINNER     ("LINKTYPE" type)
        LINKTYPE://PATHINNER   ("LINKTYPE" type)
        id:ID                  ("id" type)
        #CUSTOM-ID             ("custom-id" type)
        (CODEREF)              ("coderef" type)
        FUZZY                  ("fuzzy" type)
    
    Any sequence of spaces, tabs, and newlines inside PATHREG is treated
    as a single space.<sup><a id="fnr.13" class="footref" href="#fn.13" role="doc-backlink">13</a></sup>
    
    -   **FILENAME:** A string representing an absolute or relative file path.
    -   **LINKTYPE:** A string which is one of the link type strings in
        `org-link-parameters`<sup><a id="fnr.olp.11" class="footref" href="#fn.olp" role="doc-backlink">11</a></sup>
    -   **PATHINNER:** A string consisting of any character besides square brackets.
    -   **ID:** A string consisting of any character besides square brackets.
    -   **CUSTOM-ID:** A string consisting of any character besides square brackets.
    -   **CODEREF:** A string consisting of any character besides square brackets.
    -   **FUZZY:** A string consisting of any character besides square brackets.
    
    Square brackets and backslashes can be present in PATHREG so long as
    they are escaped by a backslash (i.e. `\]`, `\\`).
-   **DESCRIPTION (optional):** One or more objects enclosed by square
    brackets.  It can contain the <a href="#org360f63a">minimal set</a> of objects as well as
    [export snippets](#Export_Snippets), [inline babel calls](#Inline_Babel_Calls), [inline source blocks](#Source_Blocks), [macros](#Macros),
    and [statistics cookies](#Statistics_Cookies).  It can also contain another link, but only
    when it is a plain or angle link.  It can contain square brackets,
    but not `]]`.

**Examples**

    [[https://orgmode.org][The Org project homepage]]
    [[file:orgmanual.org]]
    [[Regular links]]


<a id="Macros"></a>

## Macros

Macros are structured according to one of the following patterns:

    {{{NAME}}}
    {{{NAME(ARGUMENTS)}}}

-   **NAME:** A string starting with a alphabetic character followed by
    any number of alphanumeric characters, hyphens and underscores (`-_`).
-   **ARGUMENTS (optional):** A string consisting of any characters, so
    long as it does not contain the substring `}}}`.  Values within
    ARGUMENTS are separated by commas.  Non-separating commas have to be
    escaped with a backslash character.

**Examples**

    {{{title}}}
    {{{one_arg_macro(1)}}}
    {{{two_arg_macro(1, 2)}}}
    {{{two_arg_macro(1\,a, 2)}}}


<a id="Targets_and_Radio_Targets"></a>

## Targets and Radio Targets

Targets are structured according to the following pattern:

    <<TARGET>>

-   **TARGET:** A string containing any character but `<`, `>`, or `\n`.  It
    cannot start or end with a whitespace character.

Radio targets are structured according to the following pattern:

    <<<CONTENTS>>>

-   **CONTENTS:** One or more objects from the <a href="#org360f63a">minimal set</a>, starting and
    ending with a non-whitespace character, and containing any character
    but `<`, `>`, or `\n`.


<a id="Statistics_Cookies"></a>

## Statistics Cookies

Statistics cookies are structured according to one of the following patterns:

    [PERCENT%]
    [NUM1/NUM2]

-   **PERCENT (optional):** A non-negative integer.
-   **NUM1 (optional):** A non-negative integer.
-   **NUM2 (optional):** A non-negative integer.


<a id="Subscript_and_Superscript"></a>

## Subscript and Superscript

Subscripts are structured according to the following pattern:

    CHAR_SCRIPT

Superscripts are structured according to the following pattern:

    CHAR^SCRIPT

-   **CHAR:** Any non-whitespace character.
-   **SCRIPT:** One of the following constructs:
    -   A single asterisk character (`*`).
    -   An expression enclosed in curly brackets (`{`, `}`) or in round braces
        (`(`, `)`), which may itself contain balanced curly or round brackets
        and the <a href="#org16495ef">standard set</a> of objects.
    -   An instance of the pattern:
        
            SIGN CHARS FINAL
        
        With no whitespace between SIGN, CHARS and FINAL.
        
        -   **SIGN (optional):** Either a plus sign character (`+`), a minus sign
            character (`-`), or the empty string.
        -   **CHARS:** Either the empty string, or a string consisting of any
            number of alphanumeric characters, commas, backslashes, and
            dots.
        -   **FINAL:** An alphanumeric character.

Examples:

    pecularity^*
    x^2
    x^-2
    y_(i^th, i is odd)
    x^{y^{z}}
    A_i,j

In rare occasions, subscript syntax clashes with [underline markup](#Emphasis_Markers):

    (_text_)

[Underline markup](#Emphasis_Markers) takes priority in such case, to keep consistency with
other types of markup:

    (_text_)
    (*text*)
    (/text/)
    ...


<a id="Table_Cells"></a>

## Table Cells

Table cells are structured according to the following patterns:

    CONTENTS SPACES|
    CONTENTS SPACES END-OF-LINE

-   **CONTENTS:** Zero or more objects not containing the vertical bar
    character (`|`).  It can contain the <a href="#org360f63a">minimal set</a> of objects,
    [citations](#Citations), [export snippets](#Export_Snippets), [footnote references](#Footnote_References), [links](#Links), [macros](#Macros),
    [radio targets](#Targets_and_Radio_Targets), [targets](#Targets_and_Radio_Targets), and [timestamps](#Timestamps).
-   **SPACES:** A string consisting of zero or more of space characters,
    used to align the table columns.
-   **END-OF-LINE:** Line ending.

The final vertical bar (`|`) may be omitted in the last cell of a [table row](#Table_Rows).


<a id="Timestamps"></a>

## Timestamps

Timestamps are structured according to one of the seven following patterns:

    <%%(SEXP)>                                                     (diary)
    <%%(SEXP) TIME>                                                (diary)
    <%%(SEXP) TIME-TIME>                                           (diary)
    <DATE TIME REPEATER-OR-DELAY>                                  (active)
    [DATE TIME REPEATER-OR-DELAY]                                  (inactive)
    <DATE TIME REPEATER-OR-DELAY>--<DATE TIME REPEATER-OR-DELAY>   (active range)
    <DATE TIME-TIME REPEATER-OR-DELAY>                             (active range)
    [DATE TIME REPEATER-OR-DELAY]--[DATE TIME REPEATER-OR-DELAY]   (inactive range)
    [DATE TIME-TIME REPEATER-OR-DELAY]                             (inactive range)

-   **SEXP:** A string consisting of any characters but `>` and `\n`.
-   **DATE:** An instance of the pattern:
    
        YYYY-MM-DD DAYNAME
    
    -   **Y, M, D:** A digit.
    -   **DAYNAME (optional):** A string consisting of non-whitespace
        characters except `+`, `-`, `]`, `>`, a digit, or `\n`.
-   **TIME (optional):** An instance of the pattern `H:MM` where `H`
    represents a one to two digit number (and can start with `0`), and `M`
    represents a single digit.
-   **REPEATER-OR-DELAY (optional):** An instance of a single `REPEATER` and/or an
    instance of a single `DELAY` in any order.
-   **REPEATER (optional):** An instance of the following pattern:
    
        MARK VALUE UNIT
        MARK VALUE UNIT/VALUE UNIT
    
    Where MARK, VALUE and UNIT are not separated by whitespace characters.
    
    -   **MARK:** Either the string `+` (cumulative type), `++` (catch-up type),
        or `.+` (restart type).
    -   **VALUE:** A number.
    -   **UNIT:** Either the character `h` (hour), `d` (day), `w` (week), `m`
        (month), or `y` (year).
-   **DELAY (optional):** An instance of the following pattern:
    
        MARK VALUE UNIT
    
    Where MARK, VALUE and UNIT are not separated by whitespace characters.
    
    -   **MARK:** Either  `-` (all type) or `--` (first type).
    -   **VALUE:** A number.
    -   **UNIT:** Either the character `h` (hour), `d` (day), `w` (week), `m`
        (month), or `y` (year).

**Examples**

    <1997-11-03 Mon 19:15>
    <%%(diary-float t 4 2)>
    <%%(diary-float t 4 2) 12:00-14:00>
    [2004-08-24 Tue]--[2004-08-26 Thu]
    <2012-02-08 Wed 20:00 ++1d>
    <2030-10-05 Sat +1m -3d>
    <2012-03-29 Thu ++1y/2y>


<a id="Emphasis_Markers"></a>

## Text Markup

There are six text markup objects, which are all structured according
to the following pattern:

    PRE MARKER CONTENTS MARKER POST

Where PRE, MARKER, CONTENTS, MARKER and POST are not separated by
whitespace characters.

-   **[PRE](#Special_Tokens):** Either a whitespace character, `-`, `(`, `{`, `'`, `"`, or the beginning
    of a line.
-   **MARKER:** A character that determines the object type, as follows:
    -   `*`, a *bold* object,
    -   `/`, an *italic* object,
    -   `_` an *underline* object,
    -   `=`, a *verbatim* object,
    -   `~`, a *code* object
    -   `+`, a *strike-through* object.
-   **CONTENTS:** Either a string (when MARKER represents code or
    verbatim) or a series of objects from the <a href="#org16495ef">standard set</a>. In both
    cases, CONTENTS may not begin or end with whitespace.
-   **[POST](#Special_Tokens):** Either a whitespace character, `-`, `.`, `,`, `;`, `:`, `!`, `?`, `'`, `)`, `}`,
    `[`, `"`, `\` (backslash), or the end of a line.

**Examples**

    Org is a /plaintext markup syntax/ developed with *Emacs* in 2003.
    The canonical parser is =org-element.el=, which provides a number of
    functions starting with ~org-element-~.


<a id="Plain_Text"></a>

### Plain Text

Any string that doesn&rsquo;t match any other object can be considered a
plain text object.<sup><a id="fnr.14" class="footref" href="#fn.14" role="doc-backlink">14</a></sup>
Within a plain text object, all whitespace is collapsed to a single
space. For instance, `hello\n there` is equivalent to `hello there`.


<a id="org436d834"></a>

# Appendix


<a id="Entities_List"></a>

## Org Entities

<table border="2" cellspacing="0" cellpadding="6" rules="groups" frame="hsides">


<colgroup>
<col  class="org-left" />

<col  class="org-left" />
</colgroup>
<thead>
<tr>
<th scope="col" class="org-left">Name</th>
<th scope="col" class="org-left">Character</th>
</tr>
</thead>
<tbody>
<tr>
<td class="org-left"><i>Letters</i></td>
<td class="org-left">&#xa0;</td>
</tr>

<tr>
<td class="org-left">LATIN</td>
<td class="org-left">&#xa0;</td>
</tr>

<tr>
<td class="org-left"><code>Agrave</code></td>
<td class="org-left">&Agrave;</td>
</tr>

<tr>
<td class="org-left"><code>agrave</code></td>
<td class="org-left">&agrave;</td>
</tr>

<tr>
<td class="org-left"><code>Aacute</code></td>
<td class="org-left">&Aacute;</td>
</tr>

<tr>
<td class="org-left"><code>aacute</code></td>
<td class="org-left">&aacute;</td>
</tr>

<tr>
<td class="org-left"><code>Acirc</code></td>
<td class="org-left">&Acirc;</td>
</tr>

<tr>
<td class="org-left"><code>acirc</code></td>
<td class="org-left">&acirc;</td>
</tr>

<tr>
<td class="org-left"><code>Amacr</code></td>
<td class="org-left">&Amacr;</td>
</tr>

<tr>
<td class="org-left"><code>amacr</code></td>
<td class="org-left">&amacr;</td>
</tr>

<tr>
<td class="org-left"><code>Atilde</code></td>
<td class="org-left">&Atilde;</td>
</tr>

<tr>
<td class="org-left"><code>atilde</code></td>
<td class="org-left">&atilde;</td>
</tr>

<tr>
<td class="org-left"><code>Auml</code></td>
<td class="org-left">&Auml;</td>
</tr>

<tr>
<td class="org-left"><code>auml</code></td>
<td class="org-left">&auml;</td>
</tr>

<tr>
<td class="org-left"><code>Aring</code></td>
<td class="org-left">&Aring;</td>
</tr>

<tr>
<td class="org-left"><code>AA</code></td>
<td class="org-left">&Aring;</td>
</tr>

<tr>
<td class="org-left"><code>aring</code></td>
<td class="org-left">&aring;</td>
</tr>

<tr>
<td class="org-left"><code>AElig</code></td>
<td class="org-left">&AElig;</td>
</tr>

<tr>
<td class="org-left"><code>aelig</code></td>
<td class="org-left">&aelig;</td>
</tr>

<tr>
<td class="org-left"><code>Ccedil</code></td>
<td class="org-left">&Ccedil;</td>
</tr>

<tr>
<td class="org-left"><code>ccedil</code></td>
<td class="org-left">&ccedil;</td>
</tr>

<tr>
<td class="org-left"><code>Egrave</code></td>
<td class="org-left">&Egrave;</td>
</tr>

<tr>
<td class="org-left"><code>egrave</code></td>
<td class="org-left">&egrave;</td>
</tr>

<tr>
<td class="org-left"><code>Eacute</code></td>
<td class="org-left">&Eacute;</td>
</tr>

<tr>
<td class="org-left"><code>eacute</code></td>
<td class="org-left">&eacute;</td>
</tr>

<tr>
<td class="org-left"><code>Ecirc</code></td>
<td class="org-left">&Ecirc;</td>
</tr>

<tr>
<td class="org-left"><code>ecirc</code></td>
<td class="org-left">&ecirc;</td>
</tr>

<tr>
<td class="org-left"><code>Euml</code></td>
<td class="org-left">&Euml;</td>
</tr>

<tr>
<td class="org-left"><code>euml</code></td>
<td class="org-left">&euml;</td>
</tr>

<tr>
<td class="org-left"><code>Igrave</code></td>
<td class="org-left">&Igrave;</td>
</tr>

<tr>
<td class="org-left"><code>igrave</code></td>
<td class="org-left">&igrave;</td>
</tr>

<tr>
<td class="org-left"><code>Iacute</code></td>
<td class="org-left">&Iacute;</td>
</tr>

<tr>
<td class="org-left"><code>iacute</code></td>
<td class="org-left">&iacute;</td>
</tr>

<tr>
<td class="org-left"><code>Idot</code></td>
<td class="org-left">&idot;</td>
</tr>

<tr>
<td class="org-left"><code>inodot</code></td>
<td class="org-left">&inodot;</td>
</tr>

<tr>
<td class="org-left"><code>Icirc</code></td>
<td class="org-left">&Icirc;</td>
</tr>

<tr>
<td class="org-left"><code>icirc</code></td>
<td class="org-left">&icirc;</td>
</tr>

<tr>
<td class="org-left"><code>Iuml</code></td>
<td class="org-left">&Iuml;</td>
</tr>

<tr>
<td class="org-left"><code>iuml</code></td>
<td class="org-left">&iuml;</td>
</tr>

<tr>
<td class="org-left"><code>Ntilde</code></td>
<td class="org-left">&Ntilde;</td>
</tr>

<tr>
<td class="org-left"><code>ntilde</code></td>
<td class="org-left">&ntilde;</td>
</tr>

<tr>
<td class="org-left"><code>Ograve</code></td>
<td class="org-left">&Ograve;</td>
</tr>

<tr>
<td class="org-left"><code>ograve</code></td>
<td class="org-left">&ograve;</td>
</tr>

<tr>
<td class="org-left"><code>Oacute</code></td>
<td class="org-left">&Oacute;</td>
</tr>

<tr>
<td class="org-left"><code>oacute</code></td>
<td class="org-left">&oacute;</td>
</tr>

<tr>
<td class="org-left"><code>Ocirc</code></td>
<td class="org-left">&Ocirc;</td>
</tr>

<tr>
<td class="org-left"><code>ocirc</code></td>
<td class="org-left">&ocirc;</td>
</tr>

<tr>
<td class="org-left"><code>Otilde</code></td>
<td class="org-left">&Otilde;</td>
</tr>

<tr>
<td class="org-left"><code>otilde</code></td>
<td class="org-left">&otilde;</td>
</tr>

<tr>
<td class="org-left"><code>Ouml</code></td>
<td class="org-left">&Ouml;</td>
</tr>

<tr>
<td class="org-left"><code>ouml</code></td>
<td class="org-left">&ouml;</td>
</tr>

<tr>
<td class="org-left"><code>Oslash</code></td>
<td class="org-left">&Oslash;</td>
</tr>

<tr>
<td class="org-left"><code>oslash</code></td>
<td class="org-left">&oslash;</td>
</tr>

<tr>
<td class="org-left"><code>OElig</code></td>
<td class="org-left">&OElig;</td>
</tr>

<tr>
<td class="org-left"><code>oelig</code></td>
<td class="org-left">&oelig;</td>
</tr>

<tr>
<td class="org-left"><code>Scaron</code></td>
<td class="org-left">&Scaron;</td>
</tr>

<tr>
<td class="org-left"><code>scaron</code></td>
<td class="org-left">&scaron;</td>
</tr>

<tr>
<td class="org-left"><code>szlig</code></td>
<td class="org-left">&szlig;</td>
</tr>

<tr>
<td class="org-left"><code>Ugrave</code></td>
<td class="org-left">&Ugrave;</td>
</tr>

<tr>
<td class="org-left"><code>ugrave</code></td>
<td class="org-left">&ugrave;</td>
</tr>

<tr>
<td class="org-left"><code>Uacute</code></td>
<td class="org-left">&Uacute;</td>
</tr>

<tr>
<td class="org-left"><code>uacute</code></td>
<td class="org-left">&uacute;</td>
</tr>

<tr>
<td class="org-left"><code>Ucirc</code></td>
<td class="org-left">&Ucirc;</td>
</tr>

<tr>
<td class="org-left"><code>ucirc</code></td>
<td class="org-left">&ucirc;</td>
</tr>

<tr>
<td class="org-left"><code>Uuml</code></td>
<td class="org-left">&Uuml;</td>
</tr>

<tr>
<td class="org-left"><code>uuml</code></td>
<td class="org-left">&uuml;</td>
</tr>

<tr>
<td class="org-left"><code>Yacute</code></td>
<td class="org-left">&Yacute;</td>
</tr>

<tr>
<td class="org-left"><code>yacute</code></td>
<td class="org-left">&yacute;</td>
</tr>

<tr>
<td class="org-left"><code>Yuml</code></td>
<td class="org-left">&Yuml;</td>
</tr>

<tr>
<td class="org-left"><code>yuml</code></td>
<td class="org-left">&yuml;</td>
</tr>

<tr>
<td class="org-left">LATIN (SPECIAL FACE)</td>
<td class="org-left">&#xa0;</td>
</tr>

<tr>
<td class="org-left"><code>fnof</code></td>
<td class="org-left">&fnof;</td>
</tr>

<tr>
<td class="org-left"><code>real</code></td>
<td class="org-left">&real;</td>
</tr>

<tr>
<td class="org-left"><code>image</code></td>
<td class="org-left">&image;</td>
</tr>

<tr>
<td class="org-left"><code>weierp</code></td>
<td class="org-left">&weierp;</td>
</tr>

<tr>
<td class="org-left"><code>ell</code></td>
<td class="org-left">&ell;</td>
</tr>

<tr>
<td class="org-left"><code>imath</code></td>
<td class="org-left">&imath;</td>
</tr>

<tr>
<td class="org-left"><code>jmath</code></td>
<td class="org-left">&jmath;</td>
</tr>

<tr>
<td class="org-left">GREEK</td>
<td class="org-left">&#xa0;</td>
</tr>

<tr>
<td class="org-left"><code>Alpha</code></td>
<td class="org-left">&Alpha;</td>
</tr>

<tr>
<td class="org-left"><code>alpha</code></td>
<td class="org-left">&alpha;</td>
</tr>

<tr>
<td class="org-left"><code>Beta</code></td>
<td class="org-left">&Beta;</td>
</tr>

<tr>
<td class="org-left"><code>beta</code></td>
<td class="org-left">&beta;</td>
</tr>

<tr>
<td class="org-left"><code>Gamma</code></td>
<td class="org-left">&Gamma;</td>
</tr>

<tr>
<td class="org-left"><code>gamma</code></td>
<td class="org-left">&gamma;</td>
</tr>

<tr>
<td class="org-left"><code>Delta</code></td>
<td class="org-left">&Delta;</td>
</tr>

<tr>
<td class="org-left"><code>delta</code></td>
<td class="org-left">&delta;</td>
</tr>

<tr>
<td class="org-left"><code>Epsilon</code></td>
<td class="org-left">&Epsilon;</td>
</tr>

<tr>
<td class="org-left"><code>epsilon</code></td>
<td class="org-left">&epsilon;</td>
</tr>

<tr>
<td class="org-left"><code>varepsilon</code></td>
<td class="org-left">&epsilon;</td>
</tr>

<tr>
<td class="org-left"><code>Zeta</code></td>
<td class="org-left">&Zeta;</td>
</tr>

<tr>
<td class="org-left"><code>zeta</code></td>
<td class="org-left">&zeta;</td>
</tr>

<tr>
<td class="org-left"><code>Eta</code></td>
<td class="org-left">&Eta;</td>
</tr>

<tr>
<td class="org-left"><code>eta</code></td>
<td class="org-left">&eta;</td>
</tr>

<tr>
<td class="org-left"><code>Theta</code></td>
<td class="org-left">&Theta;</td>
</tr>

<tr>
<td class="org-left"><code>theta</code></td>
<td class="org-left">&theta;</td>
</tr>

<tr>
<td class="org-left"><code>thetasym</code></td>
<td class="org-left">&thetasym;</td>
</tr>

<tr>
<td class="org-left"><code>vartheta</code></td>
<td class="org-left">&thetasym;</td>
</tr>

<tr>
<td class="org-left"><code>Iota</code></td>
<td class="org-left">&Iota;</td>
</tr>

<tr>
<td class="org-left"><code>iota</code></td>
<td class="org-left">&iota;</td>
</tr>

<tr>
<td class="org-left"><code>Kappa</code></td>
<td class="org-left">&Kappa;</td>
</tr>

<tr>
<td class="org-left"><code>kappa</code></td>
<td class="org-left">&kappa;</td>
</tr>

<tr>
<td class="org-left"><code>Lambda</code></td>
<td class="org-left">&Lambda;</td>
</tr>

<tr>
<td class="org-left"><code>lambda</code></td>
<td class="org-left">&lambda;</td>
</tr>

<tr>
<td class="org-left"><code>Mu</code></td>
<td class="org-left">&Mu;</td>
</tr>

<tr>
<td class="org-left"><code>mu</code></td>
<td class="org-left">&mu;</td>
</tr>

<tr>
<td class="org-left"><code>nu</code></td>
<td class="org-left">&nu;</td>
</tr>

<tr>
<td class="org-left"><code>Nu</code></td>
<td class="org-left">&Nu;</td>
</tr>

<tr>
<td class="org-left"><code>Xi</code></td>
<td class="org-left">&Xi;</td>
</tr>

<tr>
<td class="org-left"><code>xi</code></td>
<td class="org-left">&xi;</td>
</tr>

<tr>
<td class="org-left"><code>Omicron</code></td>
<td class="org-left">&Omicron;</td>
</tr>

<tr>
<td class="org-left"><code>omicron</code></td>
<td class="org-left">&omicron;</td>
</tr>

<tr>
<td class="org-left"><code>Pi</code></td>
<td class="org-left">&Pi;</td>
</tr>

<tr>
<td class="org-left"><code>pi</code></td>
<td class="org-left">&pi;</td>
</tr>

<tr>
<td class="org-left"><code>Rho</code></td>
<td class="org-left">&Rho;</td>
</tr>

<tr>
<td class="org-left"><code>rho</code></td>
<td class="org-left">&rho;</td>
</tr>

<tr>
<td class="org-left"><code>Sigma</code></td>
<td class="org-left">&Sigma;</td>
</tr>

<tr>
<td class="org-left"><code>sigma</code></td>
<td class="org-left">&sigma;</td>
</tr>

<tr>
<td class="org-left"><code>sigmaf</code></td>
<td class="org-left">&sigmaf;</td>
</tr>

<tr>
<td class="org-left"><code>varsigma</code></td>
<td class="org-left">&sigmaf;</td>
</tr>

<tr>
<td class="org-left"><code>Tau</code></td>
<td class="org-left">&Tau;</td>
</tr>

<tr>
<td class="org-left"><code>Upsilon</code></td>
<td class="org-left">&Upsilon;</td>
</tr>

<tr>
<td class="org-left"><code>upsih</code></td>
<td class="org-left">&upsih;</td>
</tr>

<tr>
<td class="org-left"><code>upsilon</code></td>
<td class="org-left">&upsilon;</td>
</tr>

<tr>
<td class="org-left"><code>Phi</code></td>
<td class="org-left">&Phi;</td>
</tr>

<tr>
<td class="org-left"><code>phi</code></td>
<td class="org-left">&phi;</td>
</tr>

<tr>
<td class="org-left"><code>varphi</code></td>
<td class="org-left">&varphi;</td>
</tr>

<tr>
<td class="org-left"><code>Chi</code></td>
<td class="org-left">&Chi;</td>
</tr>

<tr>
<td class="org-left"><code>chi</code></td>
<td class="org-left">&chi;</td>
</tr>

<tr>
<td class="org-left"><code>acutex</code></td>
<td class="org-left">&acute;x</td>
</tr>

<tr>
<td class="org-left"><code>Psi</code></td>
<td class="org-left">&Psi;</td>
</tr>

<tr>
<td class="org-left"><code>psi</code></td>
<td class="org-left">&psi;</td>
</tr>

<tr>
<td class="org-left"><code>tau</code></td>
<td class="org-left">&tau;</td>
</tr>

<tr>
<td class="org-left"><code>Omega</code></td>
<td class="org-left">&Omega;</td>
</tr>

<tr>
<td class="org-left"><code>omega</code></td>
<td class="org-left">&omega;</td>
</tr>

<tr>
<td class="org-left"><code>piv</code></td>
<td class="org-left">&piv;</td>
</tr>

<tr>
<td class="org-left"><code>varpi</code></td>
<td class="org-left">&piv;</td>
</tr>

<tr>
<td class="org-left"><code>partial</code></td>
<td class="org-left">&part;</td>
</tr>

<tr>
<td class="org-left">HEBREW</td>
<td class="org-left">&#xa0;</td>
</tr>

<tr>
<td class="org-left"><code>alefsym</code></td>
<td class="org-left">&alefsym;</td>
</tr>

<tr>
<td class="org-left"><code>aleph</code></td>
<td class="org-left">&aleph;</td>
</tr>

<tr>
<td class="org-left"><code>gimel</code></td>
<td class="org-left">&gimel;</td>
</tr>

<tr>
<td class="org-left"><code>beth</code></td>
<td class="org-left">&beth;</td>
</tr>

<tr>
<td class="org-left"><code>dalet</code></td>
<td class="org-left">&daleth;</td>
</tr>

<tr>
<td class="org-left">ICELANDIC</td>
<td class="org-left">&#xa0;</td>
</tr>

<tr>
<td class="org-left"><code>ETH</code></td>
<td class="org-left">&ETH;</td>
</tr>

<tr>
<td class="org-left"><code>eth</code></td>
<td class="org-left">&eth;</td>
</tr>

<tr>
<td class="org-left"><code>THORN</code></td>
<td class="org-left">&THORN;</td>
</tr>

<tr>
<td class="org-left"><code>thorn</code></td>
<td class="org-left">&thorn;</td>
</tr>

<tr>
<td class="org-left"><i>Punctuation</i></td>
<td class="org-left">&#xa0;</td>
</tr>

<tr>
<td class="org-left">DOTS AND MARKS</td>
<td class="org-left">&#xa0;</td>
</tr>

<tr>
<td class="org-left"><code>dots</code></td>
<td class="org-left">&hellip;</td>
</tr>

<tr>
<td class="org-left"><code>cdots</code></td>
<td class="org-left">&ctdot;</td>
</tr>

<tr>
<td class="org-left"><code>hellip</code></td>
<td class="org-left">&hellip;</td>
</tr>

<tr>
<td class="org-left"><code>middot</code></td>
<td class="org-left">&middot;</td>
</tr>

<tr>
<td class="org-left"><code>iexcl</code></td>
<td class="org-left">&iexcl;</td>
</tr>

<tr>
<td class="org-left"><code>iquest</code></td>
<td class="org-left">&iquest;</td>
</tr>

<tr>
<td class="org-left">DASH-LIKE</td>
<td class="org-left">&#xa0;</td>
</tr>

<tr>
<td class="org-left"><code>shy</code></td>
<td class="org-left">&shy;</td>
</tr>

<tr>
<td class="org-left"><code>ndash</code></td>
<td class="org-left">&ndash;</td>
</tr>

<tr>
<td class="org-left"><code>mdash</code></td>
<td class="org-left">&mdash;</td>
</tr>

<tr>
<td class="org-left">QUOTATIONS</td>
<td class="org-left">&#xa0;</td>
</tr>

<tr>
<td class="org-left"><code>quot</code></td>
<td class="org-left">&quot;</td>
</tr>

<tr>
<td class="org-left"><code>acute</code></td>
<td class="org-left">&acute;</td>
</tr>

<tr>
<td class="org-left"><code>ldquo</code></td>
<td class="org-left">&ldquo;</td>
</tr>

<tr>
<td class="org-left"><code>rdquo</code></td>
<td class="org-left">&rdquo;</td>
</tr>

<tr>
<td class="org-left"><code>bdquo</code></td>
<td class="org-left">&bdquo;</td>
</tr>

<tr>
<td class="org-left"><code>lsquo</code></td>
<td class="org-left">&lsquo;</td>
</tr>

<tr>
<td class="org-left"><code>rsquo</code></td>
<td class="org-left">&rsquo;</td>
</tr>

<tr>
<td class="org-left"><code>sbquo</code></td>
<td class="org-left">&sbquo;</td>
</tr>

<tr>
<td class="org-left"><code>laquo</code></td>
<td class="org-left">&laquo;</td>
</tr>

<tr>
<td class="org-left"><code>raquo</code></td>
<td class="org-left">&raquo;</td>
</tr>

<tr>
<td class="org-left"><code>lsaquo</code></td>
<td class="org-left">&lsaquo;</td>
</tr>

<tr>
<td class="org-left"><code>rsaquo</code></td>
<td class="org-left">&rsaquo;</td>
</tr>

<tr>
<td class="org-left"><i>Other</i></td>
<td class="org-left">&#xa0;</td>
</tr>

<tr>
<td class="org-left">MISC. (OFTEN USED)</td>
<td class="org-left">&#xa0;</td>
</tr>

<tr>
<td class="org-left"><code>circ</code></td>
<td class="org-left">&circ;</td>
</tr>

<tr>
<td class="org-left"><code>vert</code></td>
<td class="org-left">&vert;</td>
</tr>

<tr>
<td class="org-left"><code>vbar</code></td>
<td class="org-left">|</td>
</tr>

<tr>
<td class="org-left"><code>brvbar</code></td>
<td class="org-left">&brvbar;</td>
</tr>

<tr>
<td class="org-left"><code>S</code></td>
<td class="org-left">&sect;</td>
</tr>

<tr>
<td class="org-left"><code>sect</code></td>
<td class="org-left">&sect;</td>
</tr>

<tr>
<td class="org-left"><code>P</code></td>
<td class="org-left">&para;</td>
</tr>

<tr>
<td class="org-left"><code>para</code></td>
<td class="org-left">&para;</td>
</tr>

<tr>
<td class="org-left"><code>amp</code></td>
<td class="org-left">&amp;</td>
</tr>

<tr>
<td class="org-left"><code>lt</code></td>
<td class="org-left">&lt;</td>
</tr>

<tr>
<td class="org-left"><code>gt</code></td>
<td class="org-left">&gt;</td>
</tr>

<tr>
<td class="org-left"><code>tilde</code></td>
<td class="org-left">~</td>
</tr>

<tr>
<td class="org-left"><code>slash</code></td>
<td class="org-left">/</td>
</tr>

<tr>
<td class="org-left"><code>plus</code></td>
<td class="org-left">+</td>
</tr>

<tr>
<td class="org-left"><code>under</code></td>
<td class="org-left">_</td>
</tr>

<tr>
<td class="org-left"><code>equal</code></td>
<td class="org-left">=</td>
</tr>

<tr>
<td class="org-left"><code>asciicirc</code></td>
<td class="org-left">^</td>
</tr>

<tr>
<td class="org-left"><code>dagger</code></td>
<td class="org-left">&dagger;</td>
</tr>

<tr>
<td class="org-left"><code>dag</code></td>
<td class="org-left">&dagger;</td>
</tr>

<tr>
<td class="org-left"><code>Dagger</code></td>
<td class="org-left">&Dagger;</td>
</tr>

<tr>
<td class="org-left"><code>ddag</code></td>
<td class="org-left">&Dagger;</td>
</tr>

<tr>
<td class="org-left">WHITESPACE</td>
<td class="org-left">&#xa0;</td>
</tr>

<tr>
<td class="org-left"><code>nbsp</code></td>
<td class="org-left">&nbsp;</td>
</tr>

<tr>
<td class="org-left"><code>ensp</code></td>
<td class="org-left">&ensp;</td>
</tr>

<tr>
<td class="org-left"><code>emsp</code></td>
<td class="org-left">&emsp;</td>
</tr>

<tr>
<td class="org-left"><code>thinsp</code></td>
<td class="org-left">&thinsp;</td>
</tr>

<tr>
<td class="org-left">CURRENCY</td>
<td class="org-left">&#xa0;</td>
</tr>

<tr>
<td class="org-left"><code>curren</code></td>
<td class="org-left">&curren;</td>
</tr>

<tr>
<td class="org-left"><code>cent</code></td>
<td class="org-left">&cent;</td>
</tr>

<tr>
<td class="org-left"><code>pound</code></td>
<td class="org-left">&pound;</td>
</tr>

<tr>
<td class="org-left"><code>yen</code></td>
<td class="org-left">&yen;</td>
</tr>

<tr>
<td class="org-left"><code>euro</code></td>
<td class="org-left">&euro;</td>
</tr>

<tr>
<td class="org-left"><code>EUR</code></td>
<td class="org-left">&euro;</td>
</tr>

<tr>
<td class="org-left"><code>dollar</code></td>
<td class="org-left">$</td>
</tr>

<tr>
<td class="org-left"><code>USD</code></td>
<td class="org-left">$</td>
</tr>

<tr>
<td class="org-left">PROPERTY MARKS</td>
<td class="org-left">&#xa0;</td>
</tr>

<tr>
<td class="org-left"><code>copy</code></td>
<td class="org-left">&copy;</td>
</tr>

<tr>
<td class="org-left"><code>reg</code></td>
<td class="org-left">&reg;</td>
</tr>

<tr>
<td class="org-left"><code>trade</code></td>
<td class="org-left">&trade;</td>
</tr>

<tr>
<td class="org-left">SCIENCE ET AL.</td>
<td class="org-left">&#xa0;</td>
</tr>

<tr>
<td class="org-left"><code>minus</code></td>
<td class="org-left">&minus;</td>
</tr>

<tr>
<td class="org-left"><code>pm</code></td>
<td class="org-left">&plusmn;</td>
</tr>

<tr>
<td class="org-left"><code>plusmn</code></td>
<td class="org-left">&plusmn;</td>
</tr>

<tr>
<td class="org-left"><code>times</code></td>
<td class="org-left">&times;</td>
</tr>

<tr>
<td class="org-left"><code>frasl</code></td>
<td class="org-left">&frasl;</td>
</tr>

<tr>
<td class="org-left"><code>colon</code></td>
<td class="org-left">:</td>
</tr>

<tr>
<td class="org-left"><code>div</code></td>
<td class="org-left">&divide;</td>
</tr>

<tr>
<td class="org-left"><code>frac12</code></td>
<td class="org-left">&frac12;</td>
</tr>

<tr>
<td class="org-left"><code>frac14</code></td>
<td class="org-left">&frac14;</td>
</tr>

<tr>
<td class="org-left"><code>frac34</code></td>
<td class="org-left">&frac34;</td>
</tr>

<tr>
<td class="org-left"><code>permil</code></td>
<td class="org-left">&permil;</td>
</tr>

<tr>
<td class="org-left"><code>sup1</code></td>
<td class="org-left">&sup1;</td>
</tr>

<tr>
<td class="org-left"><code>sup2</code></td>
<td class="org-left">&sup2;</td>
</tr>

<tr>
<td class="org-left"><code>sup3</code></td>
<td class="org-left">&sup3;</td>
</tr>

<tr>
<td class="org-left"><code>radic</code></td>
<td class="org-left">&radic;</td>
</tr>

<tr>
<td class="org-left"><code>sum</code></td>
<td class="org-left">&sum;</td>
</tr>

<tr>
<td class="org-left"><code>prod</code></td>
<td class="org-left">&prod;</td>
</tr>

<tr>
<td class="org-left"><code>micro</code></td>
<td class="org-left">&micro;</td>
</tr>

<tr>
<td class="org-left"><code>macr</code></td>
<td class="org-left">&macr;</td>
</tr>

<tr>
<td class="org-left"><code>deg</code></td>
<td class="org-left">&deg;</td>
</tr>

<tr>
<td class="org-left"><code>prime</code></td>
<td class="org-left">&prime;</td>
</tr>

<tr>
<td class="org-left"><code>Prime</code></td>
<td class="org-left">&Prime;</td>
</tr>

<tr>
<td class="org-left"><code>infin</code></td>
<td class="org-left">&infin;</td>
</tr>

<tr>
<td class="org-left"><code>infty</code></td>
<td class="org-left">&infin;</td>
</tr>

<tr>
<td class="org-left"><code>prop</code></td>
<td class="org-left">&prop;</td>
</tr>

<tr>
<td class="org-left"><code>propto</code></td>
<td class="org-left">&prop;</td>
</tr>

<tr>
<td class="org-left"><code>not</code></td>
<td class="org-left">&not;</td>
</tr>

<tr>
<td class="org-left"><code>neg</code></td>
<td class="org-left">&not;</td>
</tr>

<tr>
<td class="org-left"><code>land</code></td>
<td class="org-left">&and;</td>
</tr>

<tr>
<td class="org-left"><code>wedge</code></td>
<td class="org-left">&and;</td>
</tr>

<tr>
<td class="org-left"><code>lor</code></td>
<td class="org-left">&or;</td>
</tr>

<tr>
<td class="org-left"><code>vee</code></td>
<td class="org-left">&or;</td>
</tr>

<tr>
<td class="org-left"><code>cap</code></td>
<td class="org-left">&cap;</td>
</tr>

<tr>
<td class="org-left"><code>cup</code></td>
<td class="org-left">&cup;</td>
</tr>

<tr>
<td class="org-left"><code>smile</code></td>
<td class="org-left">&smile;</td>
</tr>

<tr>
<td class="org-left"><code>frown</code></td>
<td class="org-left">&frown;</td>
</tr>

<tr>
<td class="org-left"><code>int</code></td>
<td class="org-left">&int;</td>
</tr>

<tr>
<td class="org-left"><code>therefore</code></td>
<td class="org-left">&there4;</td>
</tr>

<tr>
<td class="org-left"><code>there4</code></td>
<td class="org-left">&there4;</td>
</tr>

<tr>
<td class="org-left"><code>because</code></td>
<td class="org-left">&because;</td>
</tr>

<tr>
<td class="org-left"><code>sim</code></td>
<td class="org-left">&sim;</td>
</tr>

<tr>
<td class="org-left"><code>cong</code></td>
<td class="org-left">&cong;</td>
</tr>

<tr>
<td class="org-left"><code>simeq</code></td>
<td class="org-left">&cong;</td>
</tr>

<tr>
<td class="org-left"><code>asymp</code></td>
<td class="org-left">&asymp;</td>
</tr>

<tr>
<td class="org-left"><code>approx</code></td>
<td class="org-left">&asymp;</td>
</tr>

<tr>
<td class="org-left"><code>ne</code></td>
<td class="org-left">&ne;</td>
</tr>

<tr>
<td class="org-left"><code>neq</code></td>
<td class="org-left">&ne;</td>
</tr>

<tr>
<td class="org-left"><code>equiv</code></td>
<td class="org-left">&equiv;</td>
</tr>

<tr>
<td class="org-left"><code>triangleq</code></td>
<td class="org-left">&triangleq;</td>
</tr>

<tr>
<td class="org-left"><code>le</code></td>
<td class="org-left">&le;</td>
</tr>

<tr>
<td class="org-left"><code>leq</code></td>
<td class="org-left">&le;</td>
</tr>

<tr>
<td class="org-left"><code>ge</code></td>
<td class="org-left">&ge;</td>
</tr>

<tr>
<td class="org-left"><code>geq</code></td>
<td class="org-left">&ge;</td>
</tr>

<tr>
<td class="org-left"><code>lessgtr</code></td>
<td class="org-left">&lessgtr;</td>
</tr>

<tr>
<td class="org-left"><code>lesseqgtr</code></td>
<td class="org-left">&lesseqgtr;</td>
</tr>

<tr>
<td class="org-left"><code>ll</code></td>
<td class="org-left">&Lt;</td>
</tr>

<tr>
<td class="org-left"><code>Ll</code></td>
<td class="org-left">&Ll;</td>
</tr>

<tr>
<td class="org-left"><code>lll</code></td>
<td class="org-left">&Ll;</td>
</tr>

<tr>
<td class="org-left"><code>gg</code></td>
<td class="org-left">&Gt;</td>
</tr>

<tr>
<td class="org-left"><code>Gg</code></td>
<td class="org-left">&Gg;</td>
</tr>

<tr>
<td class="org-left"><code>ggg</code></td>
<td class="org-left">&Gg;</td>
</tr>

<tr>
<td class="org-left"><code>prec</code></td>
<td class="org-left">&pr;</td>
</tr>

<tr>
<td class="org-left"><code>preceq</code></td>
<td class="org-left">&prcue;</td>
</tr>

<tr>
<td class="org-left"><code>preccurlyeq</code></td>
<td class="org-left">&prcue;</td>
</tr>

<tr>
<td class="org-left"><code>succ</code></td>
<td class="org-left">&sc;</td>
</tr>

<tr>
<td class="org-left"><code>succeq</code></td>
<td class="org-left">&sccue;</td>
</tr>

<tr>
<td class="org-left"><code>succcurlyeq</code></td>
<td class="org-left">&sccue;</td>
</tr>

<tr>
<td class="org-left"><code>sub</code></td>
<td class="org-left">&sub;</td>
</tr>

<tr>
<td class="org-left"><code>subset</code></td>
<td class="org-left">&sub;</td>
</tr>

<tr>
<td class="org-left"><code>sup</code></td>
<td class="org-left">&sup;</td>
</tr>

<tr>
<td class="org-left"><code>supset</code></td>
<td class="org-left">&sup;</td>
</tr>

<tr>
<td class="org-left"><code>nsub</code></td>
<td class="org-left">&nsub;</td>
</tr>

<tr>
<td class="org-left"><code>sube</code></td>
<td class="org-left">&sube;</td>
</tr>

<tr>
<td class="org-left"><code>nsup</code></td>
<td class="org-left">&nsup;</td>
</tr>

<tr>
<td class="org-left"><code>supe</code></td>
<td class="org-left">&supe;</td>
</tr>

<tr>
<td class="org-left"><code>setminus</code></td>
<td class="org-left">&setminus;</td>
</tr>

<tr>
<td class="org-left"><code>forall</code></td>
<td class="org-left">&forall;</td>
</tr>

<tr>
<td class="org-left"><code>exist</code></td>
<td class="org-left">&exist;</td>
</tr>

<tr>
<td class="org-left"><code>exists</code></td>
<td class="org-left">&exist;</td>
</tr>

<tr>
<td class="org-left"><code>nexist</code></td>
<td class="org-left">&exist;</td>
</tr>

<tr>
<td class="org-left"><code>nexists</code></td>
<td class="org-left">&exist;</td>
</tr>

<tr>
<td class="org-left"><code>empty</code></td>
<td class="org-left">&empty;</td>
</tr>

<tr>
<td class="org-left"><code>emptyset</code></td>
<td class="org-left">&empty;</td>
</tr>

<tr>
<td class="org-left"><code>isin</code></td>
<td class="org-left">&isin;</td>
</tr>

<tr>
<td class="org-left"><code>in</code></td>
<td class="org-left">&isin;</td>
</tr>

<tr>
<td class="org-left"><code>notin</code></td>
<td class="org-left">&notin;</td>
</tr>

<tr>
<td class="org-left"><code>ni</code></td>
<td class="org-left">&ni;</td>
</tr>

<tr>
<td class="org-left"><code>nabla</code></td>
<td class="org-left">&nabla;</td>
</tr>

<tr>
<td class="org-left"><code>ang</code></td>
<td class="org-left">&ang;</td>
</tr>

<tr>
<td class="org-left"><code>angle</code></td>
<td class="org-left">&ang;</td>
</tr>

<tr>
<td class="org-left"><code>perp</code></td>
<td class="org-left">&perp;</td>
</tr>

<tr>
<td class="org-left"><code>parallel</code></td>
<td class="org-left">&parallel;</td>
</tr>

<tr>
<td class="org-left"><code>sdot</code></td>
<td class="org-left">&sdot;</td>
</tr>

<tr>
<td class="org-left"><code>cdot</code></td>
<td class="org-left">&sdot;</td>
</tr>

<tr>
<td class="org-left"><code>lceil</code></td>
<td class="org-left">&lceil;</td>
</tr>

<tr>
<td class="org-left"><code>rceil</code></td>
<td class="org-left">&rceil;</td>
</tr>

<tr>
<td class="org-left"><code>lfloor</code></td>
<td class="org-left">&lfloor;</td>
</tr>

<tr>
<td class="org-left"><code>rfloor</code></td>
<td class="org-left">&rfloor;</td>
</tr>

<tr>
<td class="org-left"><code>lang</code></td>
<td class="org-left">&lang;</td>
</tr>

<tr>
<td class="org-left"><code>rang</code></td>
<td class="org-left">&rang;</td>
</tr>

<tr>
<td class="org-left"><code>langle</code></td>
<td class="org-left">&lang;</td>
</tr>

<tr>
<td class="org-left"><code>rangle</code></td>
<td class="org-left">&rang;</td>
</tr>

<tr>
<td class="org-left"><code>hbar</code></td>
<td class="org-left">&hbar;</td>
</tr>

<tr>
<td class="org-left"><code>mho</code></td>
<td class="org-left">&mho;</td>
</tr>

<tr>
<td class="org-left">ARROWS</td>
<td class="org-left">&#xa0;</td>
</tr>

<tr>
<td class="org-left"><code>larr</code></td>
<td class="org-left">&larr;</td>
</tr>

<tr>
<td class="org-left"><code>leftarrow</code></td>
<td class="org-left">&larr;</td>
</tr>

<tr>
<td class="org-left"><code>gets</code></td>
<td class="org-left">&larr;</td>
</tr>

<tr>
<td class="org-left"><code>lArr</code></td>
<td class="org-left">&lArr;</td>
</tr>

<tr>
<td class="org-left"><code>Leftarrow</code></td>
<td class="org-left">&lArr;</td>
</tr>

<tr>
<td class="org-left"><code>uarr</code></td>
<td class="org-left">&uarr;</td>
</tr>

<tr>
<td class="org-left"><code>uparrow</code></td>
<td class="org-left">&uarr;</td>
</tr>

<tr>
<td class="org-left"><code>uArr</code></td>
<td class="org-left">&uArr;</td>
</tr>

<tr>
<td class="org-left"><code>Uparrow</code></td>
<td class="org-left">&uArr;</td>
</tr>

<tr>
<td class="org-left"><code>rarr</code></td>
<td class="org-left">&rarr;</td>
</tr>

<tr>
<td class="org-left"><code>to</code></td>
<td class="org-left">&rarr;</td>
</tr>

<tr>
<td class="org-left"><code>rightarrow</code></td>
<td class="org-left">&rarr;</td>
</tr>

<tr>
<td class="org-left"><code>rArr</code></td>
<td class="org-left">&rArr;</td>
</tr>

<tr>
<td class="org-left"><code>Rightarrow</code></td>
<td class="org-left">&rArr;</td>
</tr>

<tr>
<td class="org-left"><code>darr</code></td>
<td class="org-left">&darr;</td>
</tr>

<tr>
<td class="org-left"><code>downarrow</code></td>
<td class="org-left">&darr;</td>
</tr>

<tr>
<td class="org-left"><code>dArr</code></td>
<td class="org-left">&dArr;</td>
</tr>

<tr>
<td class="org-left"><code>Downarrow</code></td>
<td class="org-left">&dArr;</td>
</tr>

<tr>
<td class="org-left"><code>harr</code></td>
<td class="org-left">&harr;</td>
</tr>

<tr>
<td class="org-left"><code>leftrightarrow</code></td>
<td class="org-left">&harr;</td>
</tr>

<tr>
<td class="org-left"><code>hArr</code></td>
<td class="org-left">&hArr;</td>
</tr>

<tr>
<td class="org-left"><code>Leftrightarrow</code></td>
<td class="org-left">&hArr;</td>
</tr>

<tr>
<td class="org-left"><code>crarr</code></td>
<td class="org-left">&crarr;</td>
</tr>

<tr>
<td class="org-left"><code>hookleftarrow</code></td>
<td class="org-left">&crarr;</td>
</tr>

<tr>
<td class="org-left">FUNCTION NAMES</td>
<td class="org-left">&#xa0;</td>
</tr>

<tr>
<td class="org-left"><code>arccos</code></td>
<td class="org-left">arccos</td>
</tr>

<tr>
<td class="org-left"><code>arcsin</code></td>
<td class="org-left">arcsin</td>
</tr>

<tr>
<td class="org-left"><code>arctan</code></td>
<td class="org-left">arctan</td>
</tr>

<tr>
<td class="org-left"><code>arg</code></td>
<td class="org-left">arg</td>
</tr>

<tr>
<td class="org-left"><code>cos</code></td>
<td class="org-left">cos</td>
</tr>

<tr>
<td class="org-left"><code>cosh</code></td>
<td class="org-left">cosh</td>
</tr>

<tr>
<td class="org-left"><code>cot</code></td>
<td class="org-left">cot</td>
</tr>

<tr>
<td class="org-left"><code>coth</code></td>
<td class="org-left">coth</td>
</tr>

<tr>
<td class="org-left"><code>csc</code></td>
<td class="org-left">csc</td>
</tr>

<tr>
<td class="org-left"><code>deg</code></td>
<td class="org-left">&deg;</td>
</tr>

<tr>
<td class="org-left"><code>det</code></td>
<td class="org-left">det</td>
</tr>

<tr>
<td class="org-left"><code>dim</code></td>
<td class="org-left">dim</td>
</tr>

<tr>
<td class="org-left"><code>exp</code></td>
<td class="org-left">exp</td>
</tr>

<tr>
<td class="org-left"><code>gcd</code></td>
<td class="org-left">gcd</td>
</tr>

<tr>
<td class="org-left"><code>hom</code></td>
<td class="org-left">hom</td>
</tr>

<tr>
<td class="org-left"><code>inf</code></td>
<td class="org-left">inf</td>
</tr>

<tr>
<td class="org-left"><code>ker</code></td>
<td class="org-left">ker</td>
</tr>

<tr>
<td class="org-left"><code>lg</code></td>
<td class="org-left">lg</td>
</tr>

<tr>
<td class="org-left"><code>lim</code></td>
<td class="org-left">lim</td>
</tr>

<tr>
<td class="org-left"><code>liminf</code></td>
<td class="org-left">liminf</td>
</tr>

<tr>
<td class="org-left"><code>limsup</code></td>
<td class="org-left">limsup</td>
</tr>

<tr>
<td class="org-left"><code>ln</code></td>
<td class="org-left">ln</td>
</tr>

<tr>
<td class="org-left"><code>log</code></td>
<td class="org-left">log</td>
</tr>

<tr>
<td class="org-left"><code>max</code></td>
<td class="org-left">max</td>
</tr>

<tr>
<td class="org-left"><code>min</code></td>
<td class="org-left">min</td>
</tr>

<tr>
<td class="org-left"><code>Pr</code></td>
<td class="org-left">Pr</td>
</tr>

<tr>
<td class="org-left"><code>sec</code></td>
<td class="org-left">sec</td>
</tr>

<tr>
<td class="org-left"><code>sin</code></td>
<td class="org-left">sin</td>
</tr>

<tr>
<td class="org-left"><code>sinh</code></td>
<td class="org-left">sinh</td>
</tr>

<tr>
<td class="org-left"><code>sup</code></td>
<td class="org-left">&sup;</td>
</tr>

<tr>
<td class="org-left"><code>tan</code></td>
<td class="org-left">tan</td>
</tr>

<tr>
<td class="org-left"><code>tanh</code></td>
<td class="org-left">tanh</td>
</tr>

<tr>
<td class="org-left">SIGNS &amp; SYMBOLS</td>
<td class="org-left">&#xa0;</td>
</tr>

<tr>
<td class="org-left"><code>bull</code></td>
<td class="org-left">&bull;</td>
</tr>

<tr>
<td class="org-left"><code>bullet</code></td>
<td class="org-left">&bull;</td>
</tr>

<tr>
<td class="org-left"><code>star</code></td>
<td class="org-left">*</td>
</tr>

<tr>
<td class="org-left"><code>lowast</code></td>
<td class="org-left">&lowast;</td>
</tr>

<tr>
<td class="org-left"><code>ast</code></td>
<td class="org-left">&lowast;</td>
</tr>

<tr>
<td class="org-left"><code>odot</code></td>
<td class="org-left">o</td>
</tr>

<tr>
<td class="org-left"><code>oplus</code></td>
<td class="org-left">&oplus;</td>
</tr>

<tr>
<td class="org-left"><code>otimes</code></td>
<td class="org-left">&otimes;</td>
</tr>

<tr>
<td class="org-left"><code>check</code></td>
<td class="org-left">&checkmark;</td>
</tr>

<tr>
<td class="org-left"><code>checkmark</code></td>
<td class="org-left">&check;</td>
</tr>

<tr>
<td class="org-left">MISCELLANEOUS (SELDOM USED)</td>
<td class="org-left">&#xa0;</td>
</tr>

<tr>
<td class="org-left"><code>ordf</code></td>
<td class="org-left">&ordf;</td>
</tr>

<tr>
<td class="org-left"><code>ordm</code></td>
<td class="org-left">&ordm;</td>
</tr>

<tr>
<td class="org-left"><code>cedil</code></td>
<td class="org-left">&cedil;</td>
</tr>

<tr>
<td class="org-left"><code>oline</code></td>
<td class="org-left">&oline;</td>
</tr>

<tr>
<td class="org-left"><code>uml</code></td>
<td class="org-left">&uml;</td>
</tr>

<tr>
<td class="org-left"><code>zwnj</code></td>
<td class="org-left">&zwnj;</td>
</tr>

<tr>
<td class="org-left"><code>zwj</code></td>
<td class="org-left">&zwj;</td>
</tr>

<tr>
<td class="org-left"><code>lrm</code></td>
<td class="org-left">&lrm;</td>
</tr>

<tr>
<td class="org-left"><code>rlm</code></td>
<td class="org-left">&rlm;</td>
</tr>

<tr>
<td class="org-left">SMILIES</td>
<td class="org-left">&#xa0;</td>
</tr>

<tr>
<td class="org-left"><code>smiley</code></td>
<td class="org-left">&#9786;</td>
</tr>

<tr>
<td class="org-left"><code>blacksmile</code></td>
<td class="org-left">&#9787;</td>
</tr>

<tr>
<td class="org-left"><code>sad</code></td>
<td class="org-left">&#9785;</td>
</tr>

<tr>
<td class="org-left"><code>frowny</code></td>
<td class="org-left">&#9785;</td>
</tr>

<tr>
<td class="org-left">SUITS</td>
<td class="org-left">&#xa0;</td>
</tr>

<tr>
<td class="org-left"><code>clubs</code></td>
<td class="org-left">&clubs;</td>
</tr>

<tr>
<td class="org-left"><code>clubsuit</code></td>
<td class="org-left">&clubs;</td>
</tr>

<tr>
<td class="org-left"><code>spades</code></td>
<td class="org-left">&spades;</td>
</tr>

<tr>
<td class="org-left"><code>spadesuit</code></td>
<td class="org-left">&spades;</td>
</tr>

<tr>
<td class="org-left"><code>hearts</code></td>
<td class="org-left">&hearts;</td>
</tr>

<tr>
<td class="org-left"><code>heartsuit</code></td>
<td class="org-left">&heartsuit;</td>
</tr>

<tr>
<td class="org-left"><code>diams</code></td>
<td class="org-left">&diams;</td>
</tr>

<tr>
<td class="org-left"><code>diamondsuit</code></td>
<td class="org-left">&diams;</td>
</tr>

<tr>
<td class="org-left"><code>diamond</code></td>
<td class="org-left">&diamond;</td>
</tr>

<tr>
<td class="org-left"><code>Diamond</code></td>
<td class="org-left">&diamond;</td>
</tr>

<tr>
<td class="org-left"><code>loz</code></td>
<td class="org-left">&loz;</td>
</tr>

<tr>
<td class="org-left">=_ =</td>
<td class="org-left">&ensp;{}</td>
</tr>

<tr>
<td class="org-left">=_  =</td>
<td class="org-left">&ensp;&ensp;{}</td>
</tr>

<tr>
<td class="org-left">=_   =</td>
<td class="org-left">&ensp;&ensp;&ensp;{}</td>
</tr>

<tr>
<td class="org-left">=_    =</td>
<td class="org-left">&ensp;&ensp;&ensp;&ensp;{}</td>
</tr>

<tr>
<td class="org-left">=_     =</td>
<td class="org-left">&ensp;&ensp;&ensp;&ensp;&ensp;{}</td>
</tr>

<tr>
<td class="org-left">=_      =</td>
<td class="org-left">&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;{}</td>
</tr>

<tr>
<td class="org-left">=_       =</td>
<td class="org-left">&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;{}</td>
</tr>

<tr>
<td class="org-left">=_        =</td>
<td class="org-left">&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;{}</td>
</tr>

<tr>
<td class="org-left">=_         =</td>
<td class="org-left">&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;{}</td>
</tr>

<tr>
<td class="org-left">=_          =</td>
<td class="org-left">&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;{}</td>
</tr>

<tr>
<td class="org-left">=_           =</td>
<td class="org-left">&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;{}</td>
</tr>

<tr>
<td class="org-left">=_            =</td>
<td class="org-left">&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;{}</td>
</tr>

<tr>
<td class="org-left">=_             =</td>
<td class="org-left">&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;{}</td>
</tr>

<tr>
<td class="org-left">=_              =</td>
<td class="org-left">&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;{}</td>
</tr>

<tr>
<td class="org-left">=_               =</td>
<td class="org-left">&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;{}</td>
</tr>

<tr>
<td class="org-left">=_                =</td>
<td class="org-left">&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;{}</td>
</tr>

<tr>
<td class="org-left">=_                 =</td>
<td class="org-left">&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;{}</td>
</tr>

<tr>
<td class="org-left">=_                  =</td>
<td class="org-left">&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;{}</td>
</tr>

<tr>
<td class="org-left">=_                   =</td>
<td class="org-left">&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;{}</td>
</tr>

<tr>
<td class="org-left">=_                    =</td>
<td class="org-left">&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;{}</td>
</tr>
</tbody>
</table>


# Footnotes

<sup><a id="fn.1" href="#fnr.1">1</a></sup> In particular, the parser requires stars at column 0 to be
quoted by a comma when they do not define a heading.

<sup><a id="fn.2" href="#fnr.2">2</a></sup> It also means that only headings and sections can be recognized
just by looking at the beginning of the line.  Planning lines and
property drawers can be recognized by looking at one or two lines
above.

As a consequence, using `org-element-at-point` or `org-element-context`
will move up to the parent heading, and parse top-down from there
until context around the original location is found.

<sup><a id="fn.3" href="#fnr.3">3</a></sup> The default value of
`org-inlinetask-min-level` is `15`.

<sup><a id="fn.4" href="#fnr.4">4</a></sup> By default, `org-todo-keywords-1` only
contains `TODO` and `DONE`, however `org-todo-keywords-1` is set on a
per-document basis.

<sup><a id="fn.5" href="#fnr.5">5</a></sup> Implementation note:
todo keywords cannot be hardcoded in a tokenizer, the tokenizer must
be configurable at runtime so that in-file todo keywords are properly
interpreted.

<sup><a id="fn.6" href="#fnr.6">6</a></sup> By default,
  `org-element-parsed-keywords` contains `CAPTION`.

<sup><a id="fn.7" href="#fnr.7">7</a></sup> A common abbreviation for S-expression

<sup><a id="fn.8" href="#fnr.8">8</a></sup> By default,
`org-element-affiliated-keywords` contains `CAPTION`, `DATA`, `HEADER`,
`NAME`, `PLOT`, and `RESULTS`.

<sup><a id="fn.9" href="#fnr.9">9</a></sup> By default,
`org-element-dual-keywords` contains `CAPTION` and `RESULTS`.

<sup><a id="fn.10" href="#fnr.10">10</a></sup> See the [appendix](#Entities_List) for a list of entities.

<sup><a id="fn.11" href="#fnr.11">11</a></sup> By default, `org-link-parameters` defines
links of type `shell`, `news`, `mailto`, `https`, `http`, `ftp`, `help`, `file`, and
`elisp`.

<sup><a id="fn.12" href="#fnr.12">12</a></sup> This overall pattern
may be matched with the following regexp: `(?:[^
  \t\n\[\]<>()]|\((?:[^ \t\n\[\]<>()]|\([^
  \t\n\[\]<>()]*\))*\))+(?:[^[:punct:] \t\n]|\/|\((?:[^
  \t\n\[\]<>()]|\([^ \t\n\[\]<>()]*\))*\))`

<sup><a id="fn.13" href="#fnr.13">13</a></sup> This is not compatible with RFC 3986, which
requires to ignore them altogether.  However, doing so would require
users to encode spaces on the fly when writing links (e.g., insert
`[[shell:ls%20*.org]]` instead of <shell:ls *.org>, which defeats Org&rsquo;s
focus on simplicity.)

<sup><a id="fn.14" href="#fnr.14">14</a></sup> In `org-element.el` plain text objects are
abstracted away to strings for performance reasons.
