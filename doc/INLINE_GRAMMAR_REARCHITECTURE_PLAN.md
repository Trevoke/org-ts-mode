# Org-Mode Inline Grammar Rearchitecture Plan

**Status**: Planning Document
**Created**: 2025-11-13
**Author**: Analysis based on markdown dual-grammar patterns
**Scope**: Complete rearchitecture of inline grammar and scanner integration

---

## Executive Summary

This document outlines a comprehensive plan to rearchitect the org-mode tree-sitter grammar's inline parsing system. The current implementation has a working dual-grammar foundation but is incomplete and architecturally limited. This plan leverages proven patterns from tree-sitter-markdown to create a robust, complete inline parsing system.

**Key Goals**:
1. Complete inline grammar implementation (17 object types from org syntax spec)
2. Expand injection points beyond titles to all inline contexts
3. Implement context-specific inline rules to prevent nesting conflicts
4. Rearchitect scanners to handle complex validation patterns
5. Add proper precedence and disambiguation for ambiguous patterns
6. Implement all missing inline objects (line breaks, citations, inline babel calls, etc.)

**Impact**: This will transform the grammar from handling ~35% of inline syntax to ~90%+ coverage.

---

## Table of Contents

1. [Current State Analysis](#current-state-analysis)
2. [Critical Issues Identified](#critical-issues-identified)
3. [Architectural Patterns from Markdown](#architectural-patterns-from-markdown)
4. [Proposed Architecture](#proposed-architecture)
5. [Implementation Phases](#implementation-phases)
6. [Technical Specifications](#technical-specifications)
7. [Migration Strategy](#migration-strategy)
8. [Testing Strategy](#testing-strategy)
9. [Risk Assessment](#risk-assessment)
10. [Success Metrics](#success-metrics)

---

## Current State Analysis

### What Works
- ✅ Dual-grammar architecture in place (block + inline)
- ✅ Inline grammar for title/tag separation (121/121 tests passing)
- ✅ Basic text markup (bold, italic, underline, code, verbatim, strike)
- ✅ Links (regular, angle, plain)
- ✅ Basic inline objects (entities, macros, targets, footnotes, timestamps, subscript/superscript)
- ✅ Statistics cookies and export snippets
- ✅ Block grammar complete (186/186 tests passing)

### What's Broken/Missing

#### 1. Limited Injection Points (CRITICAL)
**Current**: Only injected into `title` nodes
**Problem**: Inline objects in paragraphs, table cells, list items not parsed
**Impact**: Users don't get proper syntax highlighting/navigation in most contexts

```scheme
# Current (queries/injections.scm)
((title) @injection.content
 (#set! injection.language "org_inline"))

# Missing:
# - paragraph
# - table_cell
# - list_item_content
# - verse_block content
# - item tags
```

#### 2. Duplicate/Conflicting Implementations (MAJOR)
**Problem**: Some inline objects exist in BOTH block and inline grammars
**Examples**:
- LaTeX fragments (block grammar lines 295-340)
- Timestamps (block grammar lines 440-500)
- Subscript/superscript (block grammar lines 225-240)
- Footnote references (block grammar lines 400-430)

**Impact**: Ambiguous parsing, precedence conflicts, maintenance burden

#### 3. Scanner Architecture Limitations (MAJOR)

From `/home/user/org-ts-mode.el/src/scanner.c:184`:
```c
// This is a problem with the current approach
// scan_tags_from_end() advances lexer to EOL while detecting tags,
// making it impossible to properly mark the title boundary
```

**Problems**:
- Can't retroactively mark boundaries after lookahead
- Keyword detection incomplete (lines 348-377) - TSLexer has no reset
- List item indentation uses heuristic instead of proper column tracking

#### 4. Missing Inline Objects (HIGH PRIORITY)

From org syntax spec, not yet implemented:
- ❌ Line breaks (`\\` at end of line)
- ❌ Inline babel calls (`call_NAME(ARGS)`)
- ❌ Inline source blocks (`src_LANG{BODY}`)
- ❌ Citations (`[cite:@key]`) - Org 9.5+
- ❌ Citation references (component of citations)
- ❌ Radio links (automatic links to radio targets)

#### 5. No Context-Specific Rules (ARCHITECTURAL)
**Problem**: All inline elements allowed everywhere
**Should**: Prevent invalid nesting (links in links, markup in code, etc.)

Example conflicts:
```org
# Valid
[[https://example.com][This is *bold* text]]

# Invalid (link in link - should be prevented at grammar level)
[[outer][[[inner][text]]]]

# Invalid (markup in code - should be prevented)
~this is *not bold* code~
```

**Current approach**: Grammar allows these, rely on precedence resolution
**Better approach**: Context-specific rules prevent conflicts entirely

#### 6. Precedence Not Systematic (MODERATE)
**Current**: Ad-hoc precedence values (prec(2), prec.dynamic(3), prec.dynamic(4))
**Problem**: No systematic hierarchy, hard to extend

From `tree-sitter-org-inline/grammar.js:60-61`:
```javascript
prec.dynamic(4, $.statistics_cookie),  // Higher than timestamp
prec.dynamic(3, $.timestamp),          // Lower - fallback
```

**Needed**: Systematic precedence levels like markdown:
```javascript
const PRECEDENCE_EMPHASIS = 1;
const PRECEDENCE_LINK = 10;
const PRECEDENCE_CODE = 15;
const PRECEDENCE_CITATION = 20;
```

---

## Critical Issues Identified

### Issue 1: Scanner Can't Validate Stateful Patterns
**File**: `src/scanner.c:348-377`

```c
static bool starts_with_keyword(TSLexer *lexer, const char *keyword, size_t len) {
    // PROBLEM: Can't reset lexer after checking
    // Current implementation: Only checks first character (heuristic)
    // Needed: Full keyword validation
    // Limitation: TSLexer API doesn't support reset/mark
}
```

**Impact**: False positives in keyword detection (e.g., "TODO" vs "TODOX")

**Root cause**: External scanner API limitation - can't lookahead without consuming

**Solution approaches**:
1. **Buffer-based lookahead**: Copy relevant portion of input to buffer, validate, then advance
2. **Grammar-level validation**: Move validation to grammar rules with character-by-character matching
3. **State machine approach**: Track partial matches in scanner state
4. **Accept limitation**: Document that "TODOx" might be matched as "TODO" + "x"

### Issue 2: Title/Tag Boundary Detection
**File**: `src/scanner.c:180-188`

```c
// scan_tags_from_end() advances lexer to EOL during tag detection
// Problem: Can't mark title boundary after advancing
// Current workaround: Mark entire line, rely on inline grammar to separate
```

**Impact**: Potential misalignment between title content and tag detection

**Solution**: Let inline grammar handle ALL title parsing, including tag detection
- Block grammar: Capture entire title line as opaque token
- Inline grammar: Parse title content AND separate tags
- Scanner: Only validate tag format when inline grammar requests it

### Issue 3: Single Injection Point
**Current architecture**:
```
Block Grammar → title node → Inline Grammar
                             ↓
                    Parse title + tags only

Paragraph content → NOT PARSED by inline grammar
Table cells → NOT PARSED by inline grammar
List items → NOT PARSED by inline grammar
```

**Impact**: 80% of inline content not parsed properly

**Solution**: Expand injection queries to all inline contexts

---

## Architectural Patterns from Markdown

### Pattern 1: Context-Specific Rule Generation

**Markdown approach** (from `tree-sitter-markdown-inline/grammar.js`):
```javascript
// Generate 8 variants:
// - _inline_element
// - _inline_element_no_star
// - _inline_element_no_underscore
// - _inline_element_no_link
// - ... combinations

for (let link of [true, false]) {
    for (let delimiter of [false, "star", "underscore", "tilde"]) {
        let suffix = "";
        if (!link) suffix += "_no_link";
        if (delimiter) suffix += "_no_" + delimiter;

        grammar.rules["_inline_element" + suffix] = $ => choice(
            ...(link ? [$.link] : []),
            ...(delimiter !== "star" ? [$._star_emphasis] : []),
            ...(delimiter !== "underscore" ? [$._underscore_emphasis] : []),
            // etc.
        );
    }
}
```

**Benefit**: Eliminates conflicts by preventing invalid parse trees at grammar level

### Pattern 2: External Scanner with State Management

**Markdown block scanner** (from `tree-sitter-markdown/src/scanner.c`):
```c
typedef struct {
    // Block nesting
    Block open_blocks[20];
    size_t open_blocks_count;

    // Line state
    uint8_t indentation;
    uint8_t column;

    // Delimiter tracking
    uint8_t fence_delimiter_length;

    // Context flags
    bool is_paragraph_continuation;
} Scanner;

// Stateful token emission based on context
scan() {
    // At each newline, decide which blocks continue/close
    for (int i = 0; i < scanner->open_blocks_count; i++) {
        if (can_block_continue(...)) {
            emit(BLOCK_CONTINUATION);
        } else {
            emit(BLOCK_CLOSE);
            pop_block();
        }
    }
}
```

**Org-mode needs similar patterns for**:
- Headline hierarchy tracking
- Drawer/block nesting
- List indentation levels
- Table state

### Pattern 3: Lookahead Before Committing

**Markdown inline scanner** (from `tree-sitter-markdown-inline/src/scanner.c`):
```c
// Before emitting CODE_SPAN_START, look for matching close
static bool scan_code_span(Scanner *s, TSLexer *lexer) {
    size_t level = count_backticks(lexer);

    // Lookahead: find matching closing backticks
    while (!lexer->eof(lexer)) {
        if (lexer->lookahead == '`') {
            size_t close_level = count_backticks(lexer);
            if (close_level == level) {
                // Found match! Emit opening token
                lexer->result_symbol = CODE_SPAN_START;
                return true;
            }
        }
        advance(lexer);
    }

    return false;  // No match, not a code span
}
```

**Org-mode needs this for**:
- Emphasis markers (`*bold*`, `/italic/`, etc.)
- Code spans (`~code~`, `=verbatim=`)
- Link brackets (`[[...]]`)
- Timestamps (`<...>`, `[...]`)

### Pattern 4: Error Token Branch Killing

**Markdown approach**:
```javascript
// In grammar, allow ambiguous parse paths
// Scanner emits ERROR token to kill invalid branches

seq(
    $._soft_line_break,
    optional(seq(
        $._soft_line_break,
        $._trigger_error  // Two consecutive breaks invalid in link title
    ))
)
```

**Org-mode applications**:
- Invalid keyword combinations (TODO + DONE)
- Malformed headlines (missing title after keywords)
- Mixed list types (ordered + unordered at same level)
- Invalid drawer structure (nested drawers)

### Pattern 5: Systematic Precedence Levels

**Markdown precedence hierarchy**:
```javascript
const PRECEDENCE_EMPHASIS = 1;
const PRECEDENCE_LINK = 10;
const PRECEDENCE_HTML = 100;

// Higher precedence wins in conflicts
emphasis: $ => prec.dynamic(PRECEDENCE_EMPHASIS, ...),
link: $ => prec.dynamic(PRECEDENCE_LINK, ...),
html_tag: $ => prec.dynamic(PRECEDENCE_HTML, ...),
```

---

## Proposed Architecture

### Architecture Overview

```
┌─────────────────────────────────────────────────────────────────┐
│                    Org Document Input                           │
└─────────────────────────────────────────────────────────────────┘
                              ↓
┌─────────────────────────────────────────────────────────────────┐
│              PASS 1: Block Grammar (org-structure)              │
├─────────────────────────────────────────────────────────────────┤
│ Scanner:                                                        │
│  - Track headline levels (1-9+)                                 │
│  - Maintain block stack (drawers, lists, tables, code blocks)   │
│  - Emit block structure tokens                                  │
│                                                                 │
│ Grammar:                                                        │
│  - Parse headlines (opaque titles)                              │
│  - Parse blocks, drawers, lists, tables                         │
│  - Create injection nodes:                                      │
│    • headline_title (for inline parsing)                        │
│    • paragraph_content (for inline parsing)                     │
│    • table_cell_content (for inline parsing)                    │
│    • list_item_content (for inline parsing)                     │
│    • verse_block_content (for inline parsing)                   │
└─────────────────────────────────────────────────────────────────┘
                              ↓
                    Block Parse Tree
                              ↓
┌─────────────────────────────────────────────────────────────────┐
│           PASS 2: Inline Grammar (org-inline) - NEW             │
├─────────────────────────────────────────────────────────────────┤
│ Scanner:                                                        │
│  - Delimiter matching (emphasis, code, links)                   │
│  - Lookahead for closing delimiters                             │
│  - Context tracking (inside link? inside code?)                 │
│  - Tag validation (for headlines)                               │
│                                                                 │
│ Grammar (Context-Specific Rules):                               │
│  - _inline_element (all objects allowed)                        │
│  - _inline_element_no_link (inside links)                       │
│  - _inline_element_no_markup (inside code/verbatim)             │
│  - _inline_element_in_link_description (restricted)             │
│  - ... 6-8 total variants                                       │
│                                                                 │
│ Objects (17 types from org syntax):                             │
│  ✓ Text markup (bold, italic, underline, code, verbatim, strike)│
│  ✓ Links (regular, angle, plain, radio)                         │
│  ✓ Entities (\alpha, \nbsp)                                     │
│  ✓ LaTeX fragments (\(...\), $...$, $$...$$)                    │
│  ✓ Export snippets (@@html:...@@)                               │
│  ✓ Footnote references ([fn:label])                             │
│  ✓ Citations ([cite:@key])                                      │
│  ✓ Citation references (@key within citations)                  │
│  ✓ Inline babel calls (call_NAME(ARGS))                         │
│  ✓ Inline source blocks (src_LANG{BODY})                        │
│  ✓ Line breaks (\\)                                             │
│  ✓ Macros ({{{name}}})                                          │
│  ✓ Targets (<<target>>)                                         │
│  ✓ Radio targets (<<<radio>>>)                                  │
│  ✓ Statistics cookies ([50%], [1/2])                            │
│  ✓ Subscript/superscript (H_2O, x^2)                            │
│  ✓ Timestamps (<2024-01-01>, [2024-01-01])                      │
│  ✓ Plain text (fallback)                                        │
└─────────────────────────────────────────────────────────────────┘
                              ↓
              Inline Parse Trees (one per injection node)
                              ↓
┌─────────────────────────────────────────────────────────────────┐
│                   Combined AST (Final Output)                   │
├─────────────────────────────────────────────────────────────────┤
│ - Block structure from Pass 1                                   │
│ - Inline content from Pass 2 (nested within injection nodes)    │
│ - Full semantic representation of org document                  │
└─────────────────────────────────────────────────────────────────┘
```

### Key Architectural Decisions

#### Decision 1: Move ALL Inline Objects to Inline Grammar

**Rationale**: Clean separation of concerns
- Block grammar: Structure only (what contains what)
- Inline grammar: Content parsing (what's inside paragraphs/titles/cells)

**Migration**:
```javascript
// REMOVE from block grammar (grammar.js):
- latex_fragment
- timestamp (when in paragraph/title context)
- footnote_reference
- subscript/superscript (when in paragraph/title context)

// MOVE to inline grammar (tree-sitter-org-inline/grammar.js):
+ latex_fragment (all variants)
+ timestamp (inline context only)
+ footnote_reference (inline context only)
+ subscript/superscript (inline context only)
+ NEW: line_break
+ NEW: citation
+ NEW: citation_reference
+ NEW: inline_babel_call
+ NEW: inline_source_block
+ NEW: radio_link
```

**Impact**:
- ✅ Eliminates duplicate implementations
- ✅ Clear ownership of each syntax element
- ✅ Easier to add new inline objects
- ⚠️ Breaking change - requires migration

#### Decision 2: Expand Injection Points to All Inline Contexts

**New injection query** (`queries/injections.scm`):
```scheme
; Headlines
((headline_title) @injection.content
 (#set! injection.language "org_inline"))

; Paragraphs
((paragraph_content) @injection.content
 (#set! injection.language "org_inline"))

; Table cells
((table_cell_content) @injection.content
 (#set! injection.language "org_inline"))

; List items
((list_item_content) @injection.content
 (#set! injection.language "org_inline"))

; Verse blocks
((verse_block_content) @injection.content
 (#set! injection.language "org_inline"))

; Item tags (description lists)
((item_tag) @injection.content
 (#set! injection.language "org_inline"))
```

**Block grammar changes** (create injection nodes):
```javascript
// OLD (opaque)
paragraph: $ => /[^\n]+/,

// NEW (injection node)
paragraph: $ => seq(
    alias($._paragraph_content, $.paragraph_content)
),
_paragraph_content: $ => /[^\n]+/,

// Similar pattern for table_cell, list_item, etc.
```

#### Decision 3: Implement 6-8 Context-Specific Inline Rules

**Context matrix**:
| Context | Links? | Markup? | Code? | All Objects? |
|---------|--------|---------|-------|--------------|
| Normal (title, paragraph) | ✓ | ✓ | ✓ | ✓ |
| Inside link description | ✗ | ✓ | ✓ | Partial |
| Inside code/verbatim | ✗ | ✗ | ✗ | ✗ (plain text only) |
| Inside emphasis | ✓ | Partial* | ✓ | ✓ |
| Inside citation | Partial | ✓ | ✓ | Partial |

\* Can't nest same delimiter: `*this *is* valid*` but `*this *is not* valid*` depends on interpretation

**Implementation** (generate rules programmatically):
```javascript
// In tree-sitter-org-inline/grammar.js

function generate_inline_rules(base_rules) {
    const contexts = {
        normal: {
            allow_links: true,
            allow_markup: true,
            allow_all_objects: true
        },
        no_link: {
            allow_links: false,
            allow_markup: true,
            allow_all_objects: true
        },
        no_markup: {
            allow_links: false,
            allow_markup: false,
            allow_all_objects: false
        },
        in_link_description: {
            allow_links: false,  // No nested links
            allow_markup: true,
            allow_all_objects: true,
            // Special: Allow minimal set + export snippets + macros + statistics cookies
        },
        in_emphasis: {
            allow_links: true,
            allow_markup: true,  // Except same delimiter
            allow_all_objects: true
        },
        in_citation: {
            allow_links: false,  // No links in citation global prefix/suffix
            allow_markup: true,  // Only minimal set
            allow_all_objects: false  // Only minimal set
        }
    };

    let rules = {};
    for (let [context_name, restrictions] of Object.entries(contexts)) {
        let suffix = context_name === 'normal' ? '' : `_${context_name}`;

        let elements = [];

        if (restrictions.allow_links) {
            elements.push(
                $.org_link,
                $.angle_link,
                $.plain_link,
                $.radio_link
            );
        }

        if (restrictions.allow_markup) {
            elements.push(
                $.bold,
                $.italic,
                $.underline,
                $.strike_through,
                // ... (conditionally exclude matching delimiter in emphasis)
            );
        }

        // Always allow:
        elements.push(
            $.entity,
            $.code,  // Unless in no_markup context
            $.verbatim,
            // ...
        );

        if (restrictions.allow_all_objects) {
            elements.push(
                $.citation,
                $.inline_babel_call,
                $.inline_source_block,
                // ...
            );
        }

        // Minimal set always allowed (except in no_markup)
        elements.push(
            $.latex_fragment,
            $.subscript,
            $.superscript,
            $.plain_text
        );

        rules[`_inline_element${suffix}`] = $ => choice(...elements);
    }

    return rules;
}
```

#### Decision 4: Rearchitect Scanner for Proper Validation

**New scanner architecture**:

```c
// tree-sitter-org-inline/src/scanner.c

typedef struct {
    // Delimiter tracking
    struct {
        char delimiter;           // Current delimiter being parsed
        uint8_t count;            // Number of consecutive delimiters
        bool is_opening;          // Is this an opening delimiter?
    } emphasis_state;

    // Lookahead buffer (for validation)
    struct {
        char *buffer;
        size_t capacity;
        size_t length;
    } lookahead_buffer;

    // Context tracking
    struct {
        bool inside_link;
        bool inside_code;
        uint8_t nesting_level;
    } context;

    // Tag validation state (for headlines)
    struct {
        bool has_tags;
        uint16_t tag_count;
    } tag_state;

} InlineScanner;

// Key functions:

// 1. Lookahead-based emphasis matching
static bool scan_emphasis_delimiter(InlineScanner *s, TSLexer *lexer) {
    char delimiter = lexer->lookahead;  // *, /, _, +, ~, =

    // Mark position
    lexer->mark_end(lexer);

    // Count consecutive delimiters (usually 1 for org-mode)
    uint8_t count = 1;
    advance(lexer);

    // Look ahead for matching closing delimiter
    bool found_closing = false;
    while (!eof(lexer) && !is_newline(lexer)) {
        if (lexer->lookahead == delimiter) {
            // Validate: not part of another emphasis
            // Validate: proper boundary (whitespace/punctuation rules)
            if (is_valid_closing(lexer, delimiter)) {
                found_closing = true;
                break;
            }
        }
        advance(lexer);
    }

    if (found_closing) {
        // Emit opening token
        lexer->result_symbol = get_opening_token(delimiter);
        return true;
    }

    return false;  // No closing found, not emphasis
}

// 2. Link bracket matching
static bool scan_link_start(InlineScanner *s, TSLexer *lexer) {
    // Must see [[
    if (lexer->lookahead != '[') return false;
    advance(lexer);
    if (lexer->lookahead != '[') return false;

    // Lookahead: find matching ]]
    uint8_t bracket_depth = 2;
    bool found_close = false;

    while (!eof(lexer)) {
        if (lexer->lookahead == '[') {
            bracket_depth++;
        } else if (lexer->lookahead == ']') {
            bracket_depth--;
            if (bracket_depth == 0) {
                found_close = true;
                break;
            }
        } else if (lexer->lookahead == '\\') {
            // Skip escaped characters
            advance(lexer);
            advance(lexer);
            continue;
        }
        advance(lexer);
    }

    if (found_close) {
        lexer->result_symbol = LINK_START;
        return true;
    }

    return false;
}

// 3. Tag validation (for headlines)
static bool scan_tags(InlineScanner *s, TSLexer *lexer) {
    // Tags: space followed by :tag1:tag2: at end of line

    // Skip to end of line (from current position)
    size_t line_length = 0;
    while (!eof(lexer) && !is_newline(lexer)) {
        advance(lexer);
        line_length++;
    }

    // Scan backward for tag pattern
    // (Implementation similar to current scanner, but cleaner)

    // Validate tag format:
    // - Must start with space + ':'
    // - Tags contain only: letters, digits, _, @, #, %
    // - Must end with ':'
    // - Must be at end of line

    if (is_valid_tag_format(...)) {
        s->tag_state.has_tags = true;
        lexer->result_symbol = TAGS;
        return true;
    }

    return false;
}

// 4. State serialization (for incremental parsing)
unsigned serialize(InlineScanner *s, char *buffer) {
    size_t offset = 0;

    // Serialize emphasis state
    buffer[offset++] = s->emphasis_state.delimiter;
    buffer[offset++] = s->emphasis_state.count;
    buffer[offset++] = s->emphasis_state.is_opening;

    // Serialize context
    buffer[offset++] = s->context.inside_link ? 1 : 0;
    buffer[offset++] = s->context.inside_code ? 1 : 0;
    buffer[offset++] = s->context.nesting_level;

    // Serialize tag state
    buffer[offset++] = s->tag_state.has_tags ? 1 : 0;
    buffer[offset++] = (s->tag_state.tag_count >> 8) & 0xFF;
    buffer[offset++] = s->tag_state.tag_count & 0xFF;

    return offset;
}

void deserialize(InlineScanner *s, const char *buffer, unsigned length) {
    if (length == 0) {
        // Initialize default state
        memset(s, 0, sizeof(InlineScanner));
        return;
    }

    size_t offset = 0;

    s->emphasis_state.delimiter = buffer[offset++];
    s->emphasis_state.count = buffer[offset++];
    s->emphasis_state.is_opening = buffer[offset++];

    s->context.inside_link = buffer[offset++] == 1;
    s->context.inside_code = buffer[offset++] == 1;
    s->context.nesting_level = buffer[offset++];

    s->tag_state.has_tags = buffer[offset++] == 1;
    s->tag_state.tag_count = ((uint16_t)buffer[offset++] << 8) | buffer[offset++];
}
```

#### Decision 5: Systematic Precedence Hierarchy

**Define precedence levels**:
```javascript
// tree-sitter-org-inline/grammar.js

const PRECEDENCE = {
    // Plain text (lowest - fallback)
    PLAIN_TEXT: 0,

    // Basic formatting
    EMPHASIS: 1,
    CODE: 2,
    VERBATIM: 2,

    // Minimal set
    ENTITY: 5,
    LATEX_FRAGMENT: 5,
    SUBSCRIPT: 5,
    SUPERSCRIPT: 5,

    // Objects
    TIMESTAMP: 10,
    STATISTICS_COOKIE: 11,  // Higher than timestamp ([1/2] vs timestamp)
    FOOTNOTE_REFERENCE: 12,
    MACRO: 13,
    EXPORT_SNIPPET: 14,
    TARGET: 15,
    RADIO_TARGET: 16,

    // Links
    PLAIN_LINK: 20,
    ANGLE_LINK: 21,
    REGULAR_LINK: 22,
    RADIO_LINK: 23,  // Highest link precedence

    // Advanced objects
    INLINE_BABEL_CALL: 30,
    INLINE_SOURCE_BLOCK: 31,
    CITATION: 32,

    // Special
    LINE_BREAK: 40,  // Very high - explicit syntax
};

// Usage:
module.exports = grammar({
    rules: {
        bold: $ => prec.dynamic(PRECEDENCE.EMPHASIS,
            seq('*', $._inline_element_no_bold, '*')
        ),

        timestamp: $ => prec.dynamic(PRECEDENCE.TIMESTAMP,
            choice(
                seq('<', $._timestamp_content, '>'),
                seq('[', $._timestamp_content, ']')
            )
        ),

        statistics_cookie: $ => prec.dynamic(PRECEDENCE.STATISTICS_COOKIE,
            choice(
                seq('[', /\d+/, '%', ']'),
                seq('[', /\d+/, '/', /\d+/, ']')
            )
        ),

        // ... etc
    }
});
```

#### Decision 6: Implement Missing Inline Objects

**Priority 1 - High Impact**:

1. **Line breaks** (`\\` at end of line):
```javascript
line_break: $ => prec.dynamic(PRECEDENCE.LINE_BREAK,
    seq(
        /[^\\]/,  // PRE: not backslash
        '\\\\',
        /[ \t]*/,  // Optional trailing spaces
        choice('\n', '\r\n', alias($.eof, ''))
    )
),
```

2. **Citations** (`[cite:@key]`, `[cite/style:@key]`):
```javascript
citation: $ => prec.dynamic(PRECEDENCE.CITATION,
    seq(
        '[cite',
        optional($.citation_style),  // /style or /style/variant
        ':',
        optional(seq(
            $.citation_global_prefix,
            ';'
        )),
        sepBy1(';', $.citation_reference),
        optional(seq(
            ';',
            $.citation_global_suffix
        )),
        ']'
    )
),

citation_reference: $ => seq(
    optional($.citation_key_prefix),
    '@',
    $.citation_key,
    optional($.citation_key_suffix)
),

citation_key: $ => /[a-zA-Z0-9_\-.:'`+|(){}@#%$&*/<>?!]+/,
```

3. **Radio links** (automatic links to radio targets):
```javascript
radio_link: $ => prec.dynamic(PRECEDENCE.RADIO_LINK,
    // This requires cross-referencing with radio_target definitions
    // Markdown handles this by maintaining a registry of radio targets
    // Scanner needs to track radio targets and emit RADIO_LINK token
    // when text matches a known radio target
    alias($._radio_link_text, $.radio_link_text)
),
```

**Priority 2 - Specialized Features**:

4. **Inline babel calls** (`call_NAME(ARGS)`):
```javascript
inline_babel_call: $ => prec.dynamic(PRECEDENCE.INLINE_BABEL_CALL,
    seq(
        'call_',
        $.babel_call_name,
        optional(seq('[', $.babel_header1, ']')),
        '(',
        optional($.babel_arguments),
        ')',
        optional(seq('[', $.babel_header2, ']'))
    )
),

babel_call_name: $ => /[^\s\[\]()]+/,
babel_arguments: $ => /[^)\n]*/,  // Balanced parens handled by scanner
babel_header1: $ => /[^\]\n]*/,   // Balanced brackets handled by scanner
babel_header2: $ => /[^\]\n]*/,
```

5. **Inline source blocks** (`src_LANG{BODY}`):
```javascript
inline_source_block: $ => prec.dynamic(PRECEDENCE.INLINE_SOURCE_BLOCK,
    seq(
        'src_',
        $.source_language,
        optional(seq('[', $.source_headers, ']')),
        '{',
        $.source_body,
        '}'
    )
),

source_language: $ => /[^\s\[{]+/,
source_headers: $ => /[^\]\n]*/,  // Balanced brackets
source_body: $ => /[^}\n]*/,      // Balanced braces handled by scanner
```

---

## Implementation Phases

### Phase 0: Preparation (Week 1)
**Goal**: Set up infrastructure and document current state

**Tasks**:
- [x] ~~Document current state~~ (this document)
- [ ] Create feature branch: `rearchitect-inline-grammar`
- [ ] Audit current test suite
  - [ ] Identify tests that will break
  - [ ] Create migration plan for breaking changes
- [ ] Set up benchmarking for performance comparison
- [ ] Create tracking issue for community feedback

**Deliverables**:
- Architecture document (this file)
- Test migration plan
- Benchmark baseline

---

### Phase 1: Foundation - Context-Specific Rules (Weeks 2-3)
**Goal**: Implement context-specific inline rule generation

**Tasks**:
1. [ ] Implement rule generation helper functions
   ```javascript
   // tree-sitter-org-inline/grammar.js
   function generate_inline_rules() { ... }
   function generate_emphasis_rules(delimiter, restrictions) { ... }
   function generate_link_rules(restrictions) { ... }
   ```

2. [ ] Define 6-8 context variants:
   - [ ] `_inline_element` (normal - all allowed)
   - [ ] `_inline_element_no_link` (inside links)
   - [ ] `_inline_element_no_markup` (inside code/verbatim)
   - [ ] `_inline_element_in_link_description` (links allow minimal set in description)
   - [ ] `_inline_element_in_emphasis_*` (for each emphasis type)
   - [ ] `_inline_element_in_citation` (citations allow minimal set)

3. [ ] Update existing rules to use context-specific variants
   - [ ] Bold: `seq('*', $_inline_element_no_bold, '*')`
   - [ ] Code: `seq('~', $_inline_element_no_markup, '~')`
   - [ ] Links: `seq('[[', $._link_path, optional(seq('][', $_inline_element_in_link_description, ']')), ']]')`

4. [ ] Write tests for nesting restrictions
   - [ ] Test: Links can't contain links
   - [ ] Test: Code can't contain markup
   - [ ] Test: Emphasis can't nest same delimiter

**Success Criteria**:
- All nesting restriction tests pass
- No grammar conflicts related to nesting
- Existing 121 tests still pass

---

### Phase 2: Scanner Rearchitecture (Weeks 4-5)
**Goal**: Implement lookahead-based delimiter matching

**Tasks**:
1. [ ] Design new scanner structure
   ```c
   typedef struct {
       DelimiterState emphasis_state;
       LookaheadBuffer lookahead;
       ContextState context;
       TagState tag_state;
   } InlineScanner;
   ```

2. [ ] Implement lookahead-based emphasis scanning
   - [ ] `scan_emphasis_delimiter()` - Find matching closing delimiter
   - [ ] `is_valid_opening()` - Check PRE/POST boundaries
   - [ ] `is_valid_closing()` - Check PRE/POST boundaries

3. [ ] Implement link bracket matching
   - [ ] `scan_link_start()` - Look for matching `]]`
   - [ ] Handle escaped brackets `\]`
   - [ ] Handle nested brackets (balanced)

4. [ ] Refactor tag validation
   - [ ] Clean up current `scan_tags()` implementation
   - [ ] Fix boundary detection issue (line 184 in current scanner)
   - [ ] Add proper validation for tag characters

5. [ ] Implement state serialization
   - [ ] `serialize()` - Save scanner state
   - [ ] `deserialize()` - Restore scanner state

**Success Criteria**:
- Scanner correctly matches emphasis delimiters
- Scanner correctly handles link brackets
- Tag validation works without boundary issues
- State serialization enables incremental parsing

---

### Phase 3: Move Inline Objects from Block Grammar (Week 6)
**Goal**: Eliminate duplicate implementations

**Tasks**:
1. [ ] Audit objects in both grammars
   - [x] LaTeX fragments
   - [x] Timestamps
   - [x] Footnote references
   - [x] Subscript/superscript

2. [ ] Move objects to inline grammar
   - [ ] Copy rules from `grammar.js` to `tree-sitter-org-inline/grammar.js`
   - [ ] Adapt rules for inline context
   - [ ] Add to appropriate context variants

3. [ ] Remove objects from block grammar
   - [ ] Delete rules from `grammar.js`
   - [ ] Update tests to expect inline nodes

4. [ ] Handle edge cases
   - [ ] LaTeX environments (block-level) stay in block grammar
   - [ ] Planning timestamps (block-level) stay in block grammar
   - [ ] Footnote definitions (block-level) stay in block grammar

**Success Criteria**:
- No duplicate implementations
- All existing tests for moved objects still pass
- Clear ownership of each syntax element

---

### Phase 4: Expand Injection Points (Week 7)
**Goal**: Parse inline content in all contexts

**Tasks**:
1. [ ] Update block grammar to create injection nodes
   ```javascript
   // OLD
   paragraph: $ => /[^\n]+/,

   // NEW
   paragraph: $ => seq(
       alias($._paragraph_content, $.paragraph_content)
   ),
   _paragraph_content: $ => /[^\n]+/,
   ```

2. [ ] Create injection nodes for:
   - [ ] `headline_title`
   - [ ] `paragraph_content`
   - [ ] `table_cell_content`
   - [ ] `list_item_content`
   - [ ] `verse_block_content`
   - [ ] `item_tag`

3. [ ] Update injection queries
   ```scheme
   ; queries/injections.scm
   ((headline_title) @injection.content
    (#set! injection.language "org_inline"))

   ((paragraph_content) @injection.content
    (#set! injection.language "org_inline"))

   ; ... etc
   ```

4. [ ] Test two-pass parsing
   - [ ] Verify block tree is created correctly
   - [ ] Verify inline trees are created for each injection node
   - [ ] Verify combined AST is correct

**Success Criteria**:
- Inline grammar parses content in all inline contexts
- Block + inline integration works seamlessly
- Performance is acceptable (< 2x slower than single-pass)

---

### Phase 5: Implement Missing Inline Objects (Weeks 8-9)
**Goal**: Complete org syntax coverage

**Priority 1 (Week 8)**:
1. [ ] Line breaks (`\\`)
   - [ ] Grammar rule
   - [ ] Tests (10+ cases)

2. [ ] Citations (`[cite:@key]`)
   - [ ] Citation structure
   - [ ] Citation references
   - [ ] Citation styles/variants
   - [ ] Global prefix/suffix
   - [ ] Tests (20+ cases)

3. [ ] Radio links
   - [ ] Scanner: Track radio targets
   - [ ] Scanner: Emit radio link tokens
   - [ ] Grammar rule
   - [ ] Tests (15+ cases)

**Priority 2 (Week 9)**:
4. [ ] Inline babel calls (`call_NAME(ARGS)`)
   - [ ] Grammar rule
   - [ ] Scanner: Balanced parentheses/brackets
   - [ ] Tests (10+ cases)

5. [ ] Inline source blocks (`src_LANG{BODY}`)
   - [ ] Grammar rule
   - [ ] Scanner: Balanced braces
   - [ ] Tests (10+ cases)

**Success Criteria**:
- All 17 inline object types implemented
- Comprehensive test coverage (200+ total inline tests)
- Org syntax specification coverage: 90%+

---

### Phase 6: Systematic Precedence (Week 10)
**Goal**: Resolve all ambiguities with precedence hierarchy

**Tasks**:
1. [ ] Define precedence constants
   ```javascript
   const PRECEDENCE = {
       PLAIN_TEXT: 0,
       EMPHASIS: 1,
       // ... (as defined above)
       LINE_BREAK: 40,
   };
   ```

2. [ ] Apply precedence to all rules
   - [ ] Update existing rules with `prec.dynamic(PRECEDENCE.XXX, ...)`
   - [ ] Ensure higher values for more specific patterns

3. [ ] Test precedence resolution
   - [ ] Timestamp vs statistics cookie: `[1/2]` → statistics cookie wins
   - [ ] Link vs plain text: `https://...` → plain link wins
   - [ ] Entity vs LaTeX fragment: `\alpha` → entity wins (has explicit POST rule)

4. [ ] Document precedence decisions
   - [ ] Add comments explaining why each precedence level chosen
   - [ ] Create test cases demonstrating precedence

**Success Criteria**:
- No grammar conflicts
- All ambiguous patterns resolved correctly
- Precedence decisions documented

---

### Phase 7: Performance Optimization (Week 11)
**Goal**: Ensure acceptable performance

**Tasks**:
1. [ ] Benchmark current implementation
   - [ ] Small files (< 1KB): Parse time
   - [ ] Medium files (10-100KB): Parse time
   - [ ] Large files (> 1MB): Parse time
   - [ ] Incremental parsing: Re-parse time after edit

2. [ ] Profile bottlenecks
   - [ ] Scanner performance
   - [ ] Grammar parsing performance
   - [ ] Injection overhead

3. [ ] Optimize hot paths
   - [ ] Scanner: Reduce lookahead distance
   - [ ] Scanner: Use bit flags instead of booleans
   - [ ] Scanner: Optimize delimiter counting
   - [ ] Grammar: Simplify regex patterns

4. [ ] Optimize state serialization
   - [ ] Minimize serialized state size
   - [ ] Optimize serialize/deserialize functions

**Success Criteria**:
- Parse time < 2x single-pass baseline
- Incremental parsing < 50ms for typical edits
- Memory usage < 2x baseline

---

### Phase 8: Testing & Documentation (Week 12)
**Goal**: Comprehensive testing and documentation

**Tasks**:
1. [ ] Expand test suite
   - [ ] Edge cases (200+ tests)
   - [ ] Error cases (50+ tests)
   - [ ] Integration tests (30+ tests)
   - [ ] Performance tests (10+ benchmarks)

2. [ ] Update documentation
   - [ ] README: Update feature list
   - [ ] SYNTAX_COVERAGE.md: Update coverage matrix
   - [ ] Add INLINE_GRAMMAR.md: Explain architecture
   - [ ] Add MIGRATION_GUIDE.md: Breaking changes

3. [ ] Create migration tools
   - [ ] Script to help users update their queries
   - [ ] Script to update node types in downstream tools

4. [ ] Community review
   - [ ] Post RFC on org-mode mailing list
   - [ ] Gather feedback on breaking changes
   - [ ] Address concerns

**Success Criteria**:
- 300+ total inline tests
- Documentation complete and accurate
- Community feedback addressed

---

## Technical Specifications

### New Token Types (Inline Scanner)

```c
typedef enum {
    // Emphasis delimiters (with lookahead validation)
    EMPHASIS_OPEN_STAR,      // * (validated closing exists)
    EMPHASIS_CLOSE_STAR,     // *
    EMPHASIS_OPEN_SLASH,     // /
    EMPHASIS_CLOSE_SLASH,    // /
    EMPHASIS_OPEN_UNDERSCORE, // _
    EMPHASIS_CLOSE_UNDERSCORE, // _
    EMPHASIS_OPEN_PLUS,      // +
    EMPHASIS_CLOSE_PLUS,     // +

    // Code/verbatim delimiters
    CODE_OPEN,               // ~
    CODE_CLOSE,              // ~
    VERBATIM_OPEN,           // =
    VERBATIM_CLOSE,          // =

    // Link delimiters
    LINK_START,              // [[ (validated closing exists)
    LINK_MIDDLE,             // ][ (between path and description)
    LINK_END,                // ]]

    // Angle link
    ANGLE_LINK_START,        // <protocol:
    ANGLE_LINK_END,          // >

    // Tags (for headlines)
    TAGS,                    // :tag1:tag2: at end of line

    // Context tokens (meta-tokens for context passing)
    LAST_TOKEN_WHITESPACE,   // Dummy token to signal whitespace context
    LAST_TOKEN_PUNCTUATION,  // Dummy token to signal punctuation context
    AT_LINE_START,           // Dummy token to signal line start
    AFTER_SPACE,             // Dummy token to signal space context

    // Error tokens (branch killing)
    ERROR,                   // Generic error
    TRIGGER_ERROR,           // Force error branch
    UNCLOSED_DELIMITER,      // No matching closing delimiter

    // Special
    LINE_BREAK_MARKER,       // \\ at end of line (validated)

} InlineTokenType;
```

### Scanner State Structure

```c
typedef struct {
    // Delimiter tracking for emphasis/code/verbatim
    struct {
        char delimiter;         // Current delimiter: *, /, _, +, ~, =
        uint8_t count;          // Number of consecutive delimiters (usually 1)
        bool is_opening;        // Is this an opening or closing delimiter?
        uint16_t position;      // Position of delimiter in line
    } delimiter_state;

    // Link bracket tracking
    struct {
        uint8_t bracket_depth;  // Nesting depth of [ ]
        bool in_link;           // Are we inside a link?
        bool in_description;    // Are we in link description (after ][)?
    } link_state;

    // Tag validation (for headlines)
    struct {
        bool has_tags;          // Does this headline have tags?
        uint8_t tag_count;      // Number of tags found
        uint16_t tags_start;    // Position where tags start
    } tag_state;

    // Radio link tracking
    struct {
        // Array of known radio targets (from radio_target definitions)
        // When parsing text, check if it matches any known radio target
        RadioTarget *targets;   // Array of radio targets
        uint16_t target_count;  // Number of radio targets
    } radio_state;

    // Context tracking (for context-specific rules)
    struct {
        bool inside_link;       // Are we inside a link?
        bool inside_code;       // Are we inside code/verbatim?
        bool inside_citation;   // Are we inside a citation?
        uint8_t emphasis_depth; // Nesting depth of emphasis
    } context;

    // Lookahead buffer (for delimiter matching)
    struct {
        char *buffer;           // Buffer for lookahead
        size_t capacity;        // Buffer capacity
        size_t length;          // Current length
    } lookahead;

} InlineScanner;

// Radio target structure
typedef struct {
    char *text;                 // Text of radio target
    size_t length;              // Length of text
    // Note: Minimal set of objects allowed in radio target
    // This might require recursive parsing
} RadioTarget;
```

### Grammar Structure (Inline Grammar)

```javascript
// tree-sitter-org-inline/grammar.js

const PRECEDENCE = {
    PLAIN_TEXT: 0,
    EMPHASIS: 1,
    CODE: 2,
    VERBATIM: 2,
    ENTITY: 5,
    LATEX_FRAGMENT: 5,
    SUBSCRIPT: 5,
    SUPERSCRIPT: 5,
    TIMESTAMP: 10,
    STATISTICS_COOKIE: 11,
    FOOTNOTE_REFERENCE: 12,
    MACRO: 13,
    EXPORT_SNIPPET: 14,
    TARGET: 15,
    RADIO_TARGET: 16,
    PLAIN_LINK: 20,
    ANGLE_LINK: 21,
    REGULAR_LINK: 22,
    RADIO_LINK: 23,
    INLINE_BABEL_CALL: 30,
    INLINE_SOURCE_BLOCK: 31,
    CITATION: 32,
    LINE_BREAK: 40,
};

module.exports = grammar({
    name: 'org_inline',

    externals: $ => [
        // Emphasis delimiters
        $.emphasis_open_star,
        $.emphasis_close_star,
        $.emphasis_open_slash,
        $.emphasis_close_slash,
        $.emphasis_open_underscore,
        $.emphasis_close_underscore,
        $.emphasis_open_plus,
        $.emphasis_close_plus,

        // Code/verbatim delimiters
        $.code_open,
        $.code_close,
        $.verbatim_open,
        $.verbatim_close,

        // Link delimiters
        $.link_start,
        $.link_middle,
        $.link_end,

        // Tags
        $.tags,

        // Context tokens
        $.last_token_whitespace,
        $.last_token_punctuation,
        $.at_line_start,
        $.after_space,

        // Error tokens
        $._error,
        $._trigger_error,
        $.unclosed_delimiter,

        // Special
        $.line_break_marker,
    ],

    rules: {
        // Entry point (injected content)
        inline: $ => repeat1($._inline_element),

        // Context-specific inline elements (generated)
        ...generate_inline_rules($),

        // Title with tags (special case for headlines)
        title_with_tags: $ => seq(
            alias($._inline_element, $.title_content),
            $.tags
        ),

        // Text markup (emphasis)
        bold: $ => prec.dynamic(PRECEDENCE.EMPHASIS,
            seq(
                $.emphasis_open_star,
                repeat1($._inline_element_no_bold),
                $.emphasis_close_star
            )
        ),

        italic: $ => prec.dynamic(PRECEDENCE.EMPHASIS,
            seq(
                $.emphasis_open_slash,
                repeat1($._inline_element_no_italic),
                $.emphasis_close_slash
            )
        ),

        // ... similar for underline, strike_through

        code: $ => prec.dynamic(PRECEDENCE.CODE,
            seq(
                $.code_open,
                alias(/[^~\n]+/, $.code_content),  // No markup allowed
                $.code_close
            )
        ),

        verbatim: $ => prec.dynamic(PRECEDENCE.VERBATIM,
            seq(
                $.verbatim_open,
                alias(/[^=\n]+/, $.verbatim_content),  // No markup allowed
                $.verbatim_close
            )
        ),

        // Links
        regular_link: $ => prec.dynamic(PRECEDENCE.REGULAR_LINK,
            seq(
                $.link_start,
                alias($._link_path, $.link_path),
                optional(seq(
                    $.link_middle,
                    alias(repeat1($._inline_element_in_link_description), $.link_description)
                )),
                $.link_end
            )
        ),

        _link_path: $ => /[^\]]+/,  // Simplified - actual implementation more complex

        angle_link: $ => prec.dynamic(PRECEDENCE.ANGLE_LINK,
            seq(
                '<',
                alias($._link_type, $.link_type),
                ':',
                alias($._angle_link_path, $.link_path),
                '>'
            )
        ),

        plain_link: $ => prec.dynamic(PRECEDENCE.PLAIN_LINK,
            seq(
                alias($._link_type, $.link_type),
                ':',
                alias($._plain_link_path, $.link_path)
            )
        ),

        radio_link: $ => prec.dynamic(PRECEDENCE.RADIO_LINK,
            // Scanner validates this matches a known radio target
            alias(repeat1($._inline_element_minimal), $.radio_link_text)
        ),

        // Minimal set objects
        entity: $ => prec.dynamic(PRECEDENCE.ENTITY,
            seq(
                '\\',
                alias($._entity_name, $.entity_name),
                optional('{}')
            )
        ),

        latex_fragment: $ => prec.dynamic(PRECEDENCE.LATEX_FRAGMENT,
            choice(
                seq('\\(', alias(/[^\\]+/, $.latex_content), '\\)'),
                seq('\\[', alias(/[^\\]+/, $.latex_content), '\\]'),
                seq('$', alias(/[^$\n]+/, $.latex_content), '$'),
                seq('$$', alias(/[^$]+/, $.latex_content), '$$'),
                // ... other variants
            )
        ),

        subscript: $ => prec.dynamic(PRECEDENCE.SUBSCRIPT,
            seq(
                alias(/[^\s]/, $.base),
                '_',
                alias($._script_content, $.subscript_content)
            )
        ),

        superscript: $ => prec.dynamic(PRECEDENCE.SUPERSCRIPT,
            seq(
                alias(/[^\s]/, $.base),
                '^',
                alias($._script_content, $.superscript_content)
            )
        ),

        _script_content: $ => choice(
            '*',
            seq('{', repeat($._inline_element), '}'),
            seq('(', repeat($._inline_element), ')'),
            /[+-]?[a-zA-Z0-9,\\\.]+[a-zA-Z0-9]/
        ),

        // Other objects
        timestamp: $ => prec.dynamic(PRECEDENCE.TIMESTAMP,
            choice(
                seq('<', $._timestamp_content, '>'),  // Active
                seq('[', $._timestamp_content, ']'),  // Inactive
                // ... ranges, etc.
            )
        ),

        statistics_cookie: $ => prec.dynamic(PRECEDENCE.STATISTICS_COOKIE,
            choice(
                seq('[', /\d+/, '%', ']'),
                seq('[', /\d+/, '/', /\d+/, ']')
            )
        ),

        footnote_reference: $ => prec.dynamic(PRECEDENCE.FOOTNOTE_REFERENCE,
            seq(
                '[fn:',
                optional(alias(/[\w-_]+/, $.label)),
                optional(seq(':', repeat1($._inline_element))),  // Definition
                ']'
            )
        ),

        macro: $ => prec.dynamic(PRECEDENCE.MACRO,
            seq(
                '{{{',
                alias(/[a-zA-Z][\w-_]*/, $.macro_name),
                optional(seq('(', alias(/[^}]+/, $.macro_arguments), ')')),
                '}}}'
            )
        ),

        export_snippet: $ => prec.dynamic(PRECEDENCE.EXPORT_SNIPPET,
            seq(
                '@@',
                alias(/[\w-]+/, $.backend),
                ':',
                optional(alias(/[^@]+/, $.value)),
                '@@'
            )
        ),

        target: $ => prec.dynamic(PRECEDENCE.TARGET,
            seq(
                '<<',
                alias(/[^<>\n]+/, $.target_name),
                '>>'
            )
        ),

        radio_target: $ => prec.dynamic(PRECEDENCE.RADIO_TARGET,
            seq(
                '<<<',
                alias(repeat1($._inline_element_minimal), $.radio_target_content),
                '>>>'
            )
        ),

        // NEW: Missing inline objects

        line_break: $ => prec.dynamic(PRECEDENCE.LINE_BREAK,
            seq(
                $.line_break_marker,  // \\ validated by scanner
                /[ \t]*/,
                choice('\n', '\r\n')
            )
        ),

        citation: $ => prec.dynamic(PRECEDENCE.CITATION,
            seq(
                '[cite',
                optional(alias($._citation_style, $.citation_style)),
                ':',
                optional(seq(
                    alias(repeat1($._inline_element_minimal), $.global_prefix),
                    ';'
                )),
                sepBy1(';', $.citation_reference),
                optional(seq(
                    ';',
                    alias(repeat1($._inline_element_minimal), $.global_suffix)
                )),
                ']'
            )
        ),

        _citation_style: $ => seq(
            '/',
            alias(/[\w-]+/, $.style),
            optional(seq('/', alias(/[\w\/-]+/, $.variant)))
        ),

        citation_reference: $ => seq(
            optional(alias(repeat1($._inline_element_minimal), $.key_prefix)),
            '@',
            alias($._citation_key, $.citation_key),
            optional(alias(repeat1($._inline_element_minimal), $.key_suffix))
        ),

        _citation_key: $ => /[\w\-.:?!'`\/\*@+|()\[\]{}<>&_^$#%~]+/,

        inline_babel_call: $ => prec.dynamic(PRECEDENCE.INLINE_BABEL_CALL,
            seq(
                'call_',
                alias(/[^\s\[\]()]+/, $.call_name),
                optional(seq('[', alias(/[^\]]+/, $.header1), ']')),
                '(',
                optional(alias(/[^)]+/, $.arguments)),
                ')',
                optional(seq('[', alias(/[^\]]+/, $.header2), ']'))
            )
        ),

        inline_source_block: $ => prec.dynamic(PRECEDENCE.INLINE_SOURCE_BLOCK,
            seq(
                'src_',
                alias(/[^\s\[{]+/, $.language),
                optional(seq('[', alias(/[^\]]+/, $.headers), ']')),
                '{',
                alias(/[^}]+/, $.body),
                '}'
            )
        ),

        // Plain text (fallback)
        plain_text: $ => prec(PRECEDENCE.PLAIN_TEXT,
            /[^\s*\/\_+~=\[<\\{@]+|\s+/
        ),
    }
});

// Helper: Generate context-specific inline rules
function generate_inline_rules($) {
    const rules = {};

    // Normal context (all allowed)
    rules._inline_element = $ => choice(
        $.bold,
        $.italic,
        $.underline,
        $.strike_through,
        $.code,
        $.verbatim,
        $.regular_link,
        $.angle_link,
        $.plain_link,
        $.radio_link,
        $.entity,
        $.latex_fragment,
        $.subscript,
        $.superscript,
        $.timestamp,
        $.statistics_cookie,
        $.footnote_reference,
        $.macro,
        $.export_snippet,
        $.target,
        $.radio_target,
        $.citation,
        $.inline_babel_call,
        $.inline_source_block,
        $.line_break,
        $.plain_text
    );

    // Inside link description (no links)
    rules._inline_element_in_link_description = $ => choice(
        $.bold,
        $.italic,
        $.underline,
        $.strike_through,
        $.code,
        $.verbatim,
        // NO LINKS
        $.entity,
        $.latex_fragment,
        $.subscript,
        $.superscript,
        $.export_snippet,
        $.inline_babel_call,
        $.inline_source_block,
        $.macro,
        $.statistics_cookie,
        $.plain_text
    );

    // Inside code/verbatim (plain text only)
    rules._inline_element_no_markup = $ => $.plain_text;

    // Minimal set (for radio targets, citation prefix/suffix)
    rules._inline_element_minimal = $ => choice(
        $.bold,
        $.italic,
        $.underline,
        $.strike_through,
        $.code,
        $.verbatim,
        $.entity,
        $.latex_fragment,
        $.subscript,
        $.superscript,
        $.plain_text
    );

    // Inside emphasis (no same delimiter)
    rules._inline_element_no_bold = $ => choice(
        // NO BOLD
        $.italic,
        $.underline,
        $.strike_through,
        $.code,
        $.verbatim,
        $.regular_link,
        $.angle_link,
        $.plain_link,
        $.radio_link,
        $.entity,
        $.latex_fragment,
        $.subscript,
        $.superscript,
        $.timestamp,
        $.statistics_cookie,
        $.footnote_reference,
        $.macro,
        $.export_snippet,
        $.target,
        $.radio_target,
        $.citation,
        $.inline_babel_call,
        $.inline_source_block,
        $.line_break,
        $.plain_text
    );

    // ... similar for _no_italic, _no_underline, etc.

    return rules;
}

// Helper: sepBy1
function sepBy1(sep, rule) {
    return seq(rule, repeat(seq(sep, rule)));
}
```

---

## Migration Strategy

### Breaking Changes

1. **Node structure changes**:
   - `title` → `headline_title` (to distinguish from other title contexts)
   - Some inline objects move from block tree to inline tree
   - New injection nodes in block tree

2. **Query changes**:
   - Downstream tools need to update tree-sitter queries
   - New injection queries required

3. **API changes**:
   - Node types change (node-types.json)
   - Some node paths change (e.g., `(headline (title))` → `(headline (headline_title (inline ...)))`)

### Migration Steps

**For users**:
1. Update to new version
2. Run migration script (if provided)
3. Update custom queries (if any)

**For downstream tools** (editors, exporters, etc.):
1. Update tree-sitter queries to use new node names
2. Update node type expectations
3. Test with migration examples

**Migration script** (pseudo-code):
```bash
#!/bin/bash
# migrate-queries.sh

# Replace old node types with new ones
sed -i 's/(title)/(headline_title)/g' queries/*.scm
sed -i 's/(paragraph)/(paragraph (inline ...))/g' queries/*.scm

# Add new injection queries
cat >> queries/injections.scm << EOF
((headline_title) @injection.content
 (#set! injection.language "org_inline"))
((paragraph_content) @injection.content
 (#set! injection.language "org_inline"))
EOF
```

### Compatibility Period

**Option 1: Hard cutover** (recommended)
- New major version (2.0.0)
- Breaking changes documented
- Migration guide provided
- No backward compatibility

**Option 2: Compatibility shim** (if needed)
- Keep old node names as aliases for 1 version
- Deprecation warnings
- Remove in next major version

**Recommendation**: Hard cutover with comprehensive migration guide

---

## Testing Strategy

### Test Categories

1. **Unit tests** (grammar rules):
   - Each inline object type (20+ tests each)
   - Context-specific rules (10+ tests each)
   - Precedence resolution (30+ tests)
   - Error cases (50+ tests)

2. **Integration tests** (end-to-end):
   - Block + inline parsing (20+ tests)
   - Two-pass parsing (10+ tests)
   - Incremental parsing (10+ tests)

3. **Performance tests**:
   - Small files (< 1KB)
   - Medium files (10-100KB)
   - Large files (> 1MB)
   - Incremental edits

4. **Regression tests**:
   - All existing 121 inline tests must pass
   - All existing 186 block tests must pass
   - No regressions from current behavior

### Test Organization

```
test/
├── corpus/
│   ├── inline/
│   │   ├── emphasis.txt (bold, italic, underline, etc.)
│   │   ├── links.txt (all 4 link types)
│   │   ├── citations.txt (NEW)
│   │   ├── inline-babel.txt (NEW)
│   │   ├── line-breaks.txt (NEW)
│   │   ├── radio-links.txt (NEW)
│   │   ├── ...
│   ├── context-specific/
│   │   ├── links-no-nesting.txt (links can't contain links)
│   │   ├── code-no-markup.txt (code can't contain markup)
│   │   ├── emphasis-nesting.txt (emphasis nesting rules)
│   │   ├── ...
│   ├── precedence/
│   │   ├── timestamp-vs-cookie.txt ([1/2] precedence)
│   │   ├── entity-vs-latex.txt (\alpha precedence)
│   │   ├── ...
│   ├── integration/
│   │   ├── headline-with-inline.txt (title parsing)
│   │   ├── paragraph-with-inline.txt (paragraph parsing)
│   │   ├── table-cell-inline.txt (table cell parsing)
│   │   ├── ...
│   ├── errors/
│   │   ├── unclosed-emphasis.txt
│   │   ├── unclosed-link.txt
│   │   ├── invalid-nesting.txt
│   │   ├── ...
├── benchmark/
│   ├── small.org (< 1KB)
│   ├── medium.org (10-100KB)
│   ├── large.org (> 1MB)
│   └── incremental/
│       ├── insert-char.org
│       ├── delete-line.org
│       ├── ...
```

### Test Metrics

**Coverage goals**:
- Line coverage: > 90%
- Branch coverage: > 85%
- Function coverage: > 95%

**Performance goals**:
- Small files (< 1KB): < 10ms
- Medium files (10-100KB): < 100ms
- Large files (> 1MB): < 1s
- Incremental edits: < 50ms

---

## Risk Assessment

### High Risk

**Risk 1: Performance degradation**
- **Likelihood**: Medium
- **Impact**: High
- **Mitigation**:
  - Benchmark continuously during development
  - Optimize hot paths (scanner lookahead)
  - Consider lazy inline parsing (parse on demand)
  - Cache inline parse trees

**Risk 2: Breaking changes too disruptive**
- **Likelihood**: High
- **Impact**: Medium
- **Mitigation**:
  - Provide comprehensive migration guide
  - Create migration scripts
  - Beta period for community feedback
  - Clear communication of breaking changes

**Risk 3: Scanner complexity leads to bugs**
- **Likelihood**: Medium
- **Impact**: Medium
- **Mitigation**:
  - Comprehensive scanner tests
  - Fuzzing (random inputs)
  - Review scanner code carefully
  - Document scanner state machine

### Medium Risk

**Risk 4: Context-specific rules too complex**
- **Likelihood**: Low
- **Impact**: Medium
- **Mitigation**:
  - Start with 4-6 contexts, expand if needed
  - Document each context clearly
  - Test each context thoroughly

**Risk 5: Two-pass parsing has integration issues**
- **Likelihood**: Low
- **Impact**: Medium
- **Mitigation**:
  - Test integration thoroughly
  - Follow markdown's proven approach
  - Handle edge cases (empty nodes, etc.)

### Low Risk

**Risk 6: Missing edge cases in new objects**
- **Likelihood**: Medium
- **Impact**: Low
- **Mitigation**:
  - Reference org syntax spec closely
  - Test with real-world org files
  - Community beta testing

---

## Success Metrics

### Quantitative Metrics

1. **Syntax coverage**: > 90% of org syntax spec
   - Current: ~35% inline objects
   - Target: 17/17 inline object types implemented

2. **Test coverage**: > 300 inline tests
   - Current: 121 tests
   - Target: 300+ tests (including new objects)

3. **Performance**: < 2x current parse time
   - Baseline: TBD (benchmark current implementation)
   - Target: < 2x baseline for typical files

4. **Error rate**: < 1% parsing errors on real-world files
   - Test corpus: 100+ real-world org files
   - Target: > 99% parse success rate

### Qualitative Metrics

1. **Code quality**:
   - Well-documented scanner
   - Clear grammar rules
   - Systematic precedence

2. **Maintainability**:
   - Clear separation of concerns (block vs inline)
   - Easy to add new inline objects
   - No duplicate implementations

3. **Community feedback**:
   - Positive reception
   - Manageable migration burden
   - Few bug reports after release

---

## Conclusion

This rearchitecture plan provides a comprehensive roadmap to transform the org-mode tree-sitter grammar's inline parsing from a partial implementation to a complete, robust system. By leveraging proven patterns from tree-sitter-markdown and systematically addressing current limitations, we will achieve:

- **Complete syntax coverage**: All 17 inline object types
- **Clean architecture**: Clear separation, no duplication
- **Robust parsing**: Context-specific rules, proper precedence
- **Maintainable code**: Well-documented, systematic

**Timeline**: 12 weeks
**Effort**: ~300-400 hours
**Impact**: Transforms grammar from 35% → 90%+ inline coverage

**Next steps**:
1. Review and refine this plan
2. Get community feedback
3. Create tracking issue
4. Begin Phase 0 (Preparation)

---

**End of Rearchitecture Plan**
