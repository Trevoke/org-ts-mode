# Org-Mode Emphasis Rules Reference

**Source**: `/home/user/org-ts-mode.el/doc/org-syntax.md` (lines 1744-1777)
**Date**: 2025-11-13
**Phase**: Phase 2 - Scanner Rearchitecture

---

## Overview

Org-mode text markup (emphasis) follows a strict pattern that must be validated by the scanner to ensure correct parsing.

---

## The Pattern

```
PRE MARKER CONTENTS MARKER POST
```

**Critical constraint**: PRE, MARKER, CONTENTS, MARKER, and POST are **not separated by whitespace characters**.

---

## Component Definitions

### PRE (Pre-Character)

**Definition**: Character that can appear immediately before the opening MARKER.

**Valid PRE characters**:
- Whitespace (space, tab)
- `-` (hyphen)
- `(` (left parenthesis)
- `{` (left brace)
- `'` (single quote/apostrophe)
- `"` (double quote)
- **Beginning of line**

**Examples**:
```org
This is *bold* text.          ✅ (space before *)
Starting *bold* here.         ✅ (space before *)
Text-*bold* here.             ✅ (hyphen before *)
Open(*bold* here.             ✅ (left paren before *)
Brace{*bold* here.            ✅ (left brace before *)
Quote'*bold* here.            ✅ (single quote before *)
Quote"*bold* here.            ✅ (double quote before *)
*bold* at start of line.      ✅ (beginning of line)
x*bold* here.                 ❌ (letter x is invalid PRE)
```

### MARKER (Delimiter Character)

**Definition**: Character that identifies the emphasis type.

**Valid MARKERs**:
| Marker | Type | Object |
|--------|------|--------|
| `*` | Bold | `*text*` |
| `/` | Italic | `/text/` |
| `_` | Underline | `_text_` |
| `=` | Verbatim | `=text=` |
| `~` | Code | `~text~` |
| `+` | Strike-through | `+text+` |

### CONTENTS

**Definition**: The text between the opening and closing MARKERs.

**Rules**:
1. **Cannot begin with whitespace**
2. **Cannot end with whitespace**
3. **For code (`~`) and verbatim (`=`)**: CONTENTS is a plain string (no parsing)
4. **For other markers**: CONTENTS can contain other inline objects (entities, links, etc.)

**Examples**:
```org
*valid*          ✅ (no leading/trailing whitespace)
*also valid*     ✅ (no leading/trailing whitespace)
* invalid*       ❌ (leading whitespace after opening *)
*invalid *       ❌ (trailing whitespace before closing *)
* invalid *      ❌ (both leading and trailing whitespace)
```

### POST (Post-Character)

**Definition**: Character that can appear immediately after the closing MARKER.

**Valid POST characters**:
- Whitespace (space, tab)
- `-` (hyphen)
- `.` (period)
- `,` (comma)
- `;` (semicolon)
- `:` (colon)
- `!` (exclamation mark)
- `?` (question mark)
- `'` (single quote/apostrophe)
- `)` (right parenthesis)
- `}` (right brace)
- `[` (left bracket)
- `"` (double quote)
- `\` (backslash)
- **End of line**

**Examples**:
```org
This is *bold* text.          ✅ (space after *)
This is *bold*.               ✅ (period after *)
This is *bold*,               ✅ (comma after *)
This is *bold*;               ✅ (semicolon after *)
This is *bold*:               ✅ (colon after *)
This is *bold*!               ✅ (exclamation after *)
This is *bold*?               ✅ (question mark after *)
This is *bold*'s              ✅ (apostrophe after *)
This is (*bold*)              ✅ (right paren after *)
This is {*bold*}              ✅ (right brace after *)
This is *bold*[1]             ✅ (left bracket after *)
This is "*bold*"              ✅ (double quote after *)
This is *bold*\n              ✅ (backslash after *)
*bold* at end of line.        ✅ (end of line)
This is *bold*x               ❌ (letter x is invalid POST)
```

---

## Validation Algorithm

To validate emphasis, the scanner must:

### 1. Check PRE Character
```
When we encounter a potential opening MARKER:
1. Look at the character immediately before MARKER
2. If it's one of: whitespace, -, (, {, ', ", or beginning of line → valid PRE
3. Otherwise → not valid emphasis, treat as plain text
```

### 2. Check CONTENTS Boundaries
```
After opening MARKER:
1. Check next character is not whitespace → valid opening boundary
2. Look ahead to find closing MARKER
3. Check character before closing MARKER is not whitespace → valid closing boundary
```

### 3. Check POST Character
```
After closing MARKER:
1. Look at the character immediately after MARKER
2. If it's one of: whitespace, -, ., ,, ;, :, !, ?, ', ), }, [, ", \, or end of line → valid POST
3. Otherwise → not valid emphasis, continue looking for valid closing
```

### 4. No Whitespace Between Components
```
PRE MARKER CONTENTS MARKER POST
    ↑     ↑         ↑      ↑
    No whitespace between these components
```

---

## Examples from org-syntax.md

From the official specification (line 1773):

```org
Org is a /plaintext markup syntax/ developed with *Emacs* in 2003.
The canonical parser is =org-element.el=, which provides a number of
functions starting with ~org-element-~.
```

**Analysis**:
- `/plaintext markup syntax/`:
  - PRE: space (✅)
  - MARKER: `/`
  - CONTENTS: `plaintext markup syntax` (no leading/trailing whitespace ✅)
  - MARKER: `/`
  - POST: space (✅)

- `*Emacs*`:
  - PRE: space (✅)
  - MARKER: `*`
  - CONTENTS: `Emacs` (no leading/trailing whitespace ✅)
  - MARKER: `*`
  - POST: space (✅)

- `=org-element.el=`:
  - PRE: space (✅)
  - MARKER: `=`
  - CONTENTS: `org-element.el` (no leading/trailing whitespace ✅)
  - MARKER: `=`
  - POST: `,` (✅)

- `~org-element-~`:
  - PRE: space (✅)
  - MARKER: `~`
  - CONTENTS: `org-element-` (no leading/trailing whitespace ✅)
  - MARKER: `~`
  - POST: `.` (✅)

---

## Edge Cases

### Case 1: Emphasis at Line Boundaries

**Start of line**:
```org
*bold* at start
  ✅ PRE = beginning of line
```

**End of line**:
```org
text *bold*
  ✅ POST = end of line
```

### Case 2: Adjacent Emphasis

```org
*bold*/italic*
  ❌ Middle `*` has PRE=`/` (not valid)
  ❌ Middle `/` has POST=`*` (not valid)
```

**Correct**:
```org
*bold* /italic/
  ✅ Separated by space
```

### Case 3: Nested Emphasis

**Allowed (different markers)**:
```org
*bold with /italic/ inside*
  ✅ Bold contains italic
```

**Not allowed (same marker)**:
```org
*bold with *nested* bold*
  ❌ Cannot nest same marker
  Result: Three separate tokens: *bold with *, *nested*, * bold*
```

### Case 4: Invalid Whitespace

```org
* bold*          ❌ Leading whitespace in CONTENTS
*bold *          ❌ Trailing whitespace in CONTENTS
* bold *         ❌ Both leading and trailing whitespace
```

### Case 5: Punctuation Boundaries

```org
The *bold* text.     ✅ POST=space
The *bold*.          ✅ POST=period
(*bold*)             ✅ PRE=(, POST=)
"*bold*"             ✅ PRE=", POST="
```

---

## Scanner Implementation Requirements

Based on these rules, the scanner must implement:

### 1. Character Classification Functions

```c
bool is_pre_char(char c) {
    // Check if c is valid PRE: whitespace, -, (, {, ', "
    return c == ' ' || c == '\t' || c == '\n' ||
           c == '-' || c == '(' || c == '{' ||
           c == '\'' || c == '"';
}

bool is_post_char(char c) {
    // Check if c is valid POST: whitespace, -, ., ,, ;, :, !, ?, ', ), }, [, ", \
    return c == ' ' || c == '\t' || c == '\n' ||
           c == '-' || c == '.' || c == ',' ||
           c == ';' || c == ':' || c == '!' ||
           c == '?' || c == '\'' || c == ')' ||
           c == '}' || c == '[' || c == '"' ||
           c == '\\';
}

bool is_whitespace(char c) {
    return c == ' ' || c == '\t' || c == '\n';
}
```

### 2. Boundary Validation

```c
bool validate_opening_boundary(TSLexer *lexer, char marker) {
    // 1. Check PRE (character before marker)
    // 2. Advance past marker
    // 3. Check next character is not whitespace (CONTENTS boundary)
    // 4. Return true if valid
}

bool validate_closing_boundary(TSLexer *lexer, char marker) {
    // 1. Check character before marker is not whitespace (CONTENTS boundary)
    // 2. Advance past marker
    // 3. Check POST (character after marker)
    // 4. Return true if valid
}
```

### 3. Lookahead Scanning

```c
bool find_closing_delimiter(TSLexer *lexer, char marker) {
    // 1. Scan ahead to find matching marker
    // 2. Validate closing boundary at each candidate
    // 3. Stop at line end (emphasis cannot span lines)
    // 4. Return true if valid closing found
}
```

### 4. State Management

```c
typedef struct {
    // Track which delimiters are currently open
    uint8_t delimiter_stack[MAX_DEPTH];
    uint8_t stack_depth;

    // Track if we're scanning for specific delimiter
    char active_delimiter;
} ScannerState;
```

---

## Differences from Markdown

Org-mode emphasis rules are **simpler and more explicit** than Markdown:

### Markdown (Complex)
- Uses "left-flanking" and "right-flanking" delimiter runs
- Complex precedence based on punctuation context
- Can have multiple delimiters (`**bold**`, `***bold-italic***`)
- Different rules for `*` vs `_`

### Org-mode (Simple)
- Explicit PRE/POST character sets
- No delimiter runs (single marker only)
- Same rules for all markers
- Clear boundary validation (no whitespace at CONTENTS edges)

**Implication**: We can implement a **simpler scanner** than markdown's, but we still need lookahead to validate boundaries.

---

## Testing Requirements

The scanner must handle:

1. **Basic emphasis**: `*bold*`, `/italic/`, etc.
2. **PRE character validation**: All 8 valid PRE chars + beginning of line
3. **POST character validation**: All 14 valid POST chars + end of line
4. **CONTENTS boundary validation**: No leading/trailing whitespace
5. **Invalid cases**: Wrong PRE/POST chars, whitespace boundaries
6. **Line boundaries**: Emphasis at start/end of line
7. **Adjacent markers**: Multiple emphasis types together
8. **Nested emphasis**: Different markers (allowed), same marker (not allowed)

---

## References

- **org-syntax.md**: Lines 1744-1777
- **Emacs org-mode**: Reference implementation (`org-element.el`)
- **This document**: Authoritative reference for scanner implementation

---

**Next Steps**: Create MARKDOWN_SCANNER_PATTERNS.md to document patterns we'll adopt from the markdown scanner implementation.
