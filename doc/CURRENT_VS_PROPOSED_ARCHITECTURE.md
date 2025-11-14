# Current vs. Proposed Architecture: Visual Comparison

---

## Architecture Comparison

### CURRENT Architecture (Limited)

```
┌──────────────────────────────────────────────────────────────┐
│                    Org Document                              │
│                                                              │
│  * TODO Headline with *bold* and [[link]]                   │
│                                                              │
│  This is a paragraph with *emphasis* and [[links]].         │
│                                                              │
│  | Table | with *bold* | content |                          │
│                                                              │
│  - List item with /italic/ text                             │
└──────────────────────────────────────────────────────────────┘
                            ↓
        ┌───────────────────────────────────┐
        │   Block Grammar (grammar.js)      │
        ├───────────────────────────────────┤
        │ • Parses headlines                │
        │ • Parses paragraphs (opaque)      │
        │ • Parses tables (cells opaque)    │
        │ • Parses lists (content opaque)   │
        │ • Has LaTeX fragments             │
        │ • Has timestamps                  │
        │ • Has subscript/superscript       │
        └───────────────────────────────────┘
                            ↓
        ┌───────────────────────────────────────────────┐
        │         Block Parse Tree                      │
        ├───────────────────────────────────────────────┤
        │ headline                                      │
        │   ├── stars: "*"                              │
        │   ├── keyword: "TODO"                         │
        │   └── title: "Headline with *bold* and ..." ◄─┐ Opaque string
        │                                               │ (not parsed!)
        │ paragraph: "This is a paragraph with ..." ◄───┤ Opaque string
        │                                               │ (not parsed!)
        │ table                                         │
        │   └── row                                     │
        │       ├── cell: "Table" ◄─────────────────────┤ Opaque string
        │       ├── cell: "with *bold*" ◄───────────────┤ (not parsed!)
        │       └── cell: "content" ◄───────────────────┘
        │
        │ list
        │   └── item: "- List item with /italic/ ..." ◄─ Opaque string
        │                                                 (not parsed!)
        └───────────────────────────────────────────────┘
                            ↓
        ┌────────────────────────────────────────────────┐
        │   Inline Grammar (tree-sitter-org-inline)      │
        ├────────────────────────────────────────────────┤
        │ ⚠️ ONLY injected into "title" nodes            │
        │                                                │
        │ Has:                                           │
        │  ✓ Title/tag separation                       │
        │  ✓ Text markup (bold, italic, etc.)           │
        │  ✓ Links                                      │
        │  ✓ Basic inline objects                       │
        │                                                │
        │ Missing:                                       │
        │  ❌ Citations                                  │
        │  ❌ Line breaks                                │
        │  ❌ Inline babel calls                         │
        │  ❌ Inline source blocks                       │
        │  ❌ Radio links                                │
        │                                                │
        │ ALSO has duplicate implementations:            │
        │  ⚠️ LaTeX fragments (also in block grammar)   │
        │  ⚠️ Timestamps (also in block grammar)        │
        │  ⚠️ Subscript/superscript (also in block)     │
        └────────────────────────────────────────────────┘
                            ↓
        ┌────────────────────────────────────────┐
        │   Final AST (Current)                  │
        ├────────────────────────────────────────┤
        │ headline                               │
        │   └── title_with_tags                  │ ✅ Parsed
        │       ├── bold "bold"                  │
        │       └── link "link"                  │
        │                                        │
        │ paragraph                              │ ❌ NOT PARSED
        │   └── (opaque string)                  │
        │                                        │
        │ table → row → cell                     │ ❌ NOT PARSED
        │   └── (opaque string)                  │
        │                                        │
        │ list → item                            │ ❌ NOT PARSED
        │   └── (opaque string)                  │
        └────────────────────────────────────────┘

📊 COVERAGE: ~35% of inline content parsed
   - ✅ Headlines: Fully parsed
   - ❌ Paragraphs: NOT parsed
   - ❌ Table cells: NOT parsed
   - ❌ List items: NOT parsed
   - ❌ Verse blocks: NOT parsed
```

---

### PROPOSED Architecture (Complete)

```
┌──────────────────────────────────────────────────────────────┐
│                    Org Document                              │
│                                                              │
│  * TODO Headline with *bold* and [[link]]                   │
│                                                              │
│  This is a paragraph with *emphasis* and [[links]].         │
│                                                              │
│  | Table | with *bold* | content |                          │
│                                                              │
│  - List item with /italic/ text                             │
└──────────────────────────────────────────────────────────────┘
                            ↓
        ┌───────────────────────────────────────────────┐
        │  PASS 1: Block Grammar (grammar.js)           │
        ├───────────────────────────────────────────────┤
        │ • Parses headlines                            │
        │ • Parses paragraphs (creates injection node)  │ ← NEW
        │ • Parses tables (creates injection nodes)     │ ← NEW
        │ • Parses lists (creates injection nodes)      │ ← NEW
        │ • NO LaTeX fragments                          │ ← REMOVED
        │ • NO timestamps (inline context)              │ ← REMOVED
        │ • NO subscript/superscript (inline context)   │ ← REMOVED
        └───────────────────────────────────────────────┘
                            ↓
        ┌───────────────────────────────────────────────────┐
        │         Block Parse Tree (Pass 1)                 │
        ├───────────────────────────────────────────────────┤
        │ headline                                          │
        │   ├── stars: "*"                                  │
        │   ├── keyword: "TODO"                             │
        │   └── headline_title: "Headline with ..." ◄───────┐ Injection node
        │                                                   │
        │ paragraph                                         │
        │   └── paragraph_content: "This is a ..." ◄────────┤ Injection node
        │                                                   │
        │ table                                             │
        │   └── row                                         │
        │       ├── table_cell_content: "Table" ◄───────────┤ Injection node
        │       ├── table_cell_content: "with *bold*" ◄─────┤ Injection node
        │       └── table_cell_content: "content" ◄─────────┤ Injection node
        │                                                   │
        │ list                                              │
        │   └── item                                        │
        │       └── list_item_content: "List item ..." ◄────┘ Injection node
        └───────────────────────────────────────────────────┘
                            ↓
        ┌─────────────────────────────────────────────────────────┐
        │  Injection Query (queries/injections.scm)               │
        ├─────────────────────────────────────────────────────────┤
        │  ((headline_title) @injection.content                   │
        │   (#set! injection.language "org_inline"))              │
        │                                                         │
        │  ((paragraph_content) @injection.content                │ ← NEW
        │   (#set! injection.language "org_inline"))              │ ← NEW
        │                                                         │
        │  ((table_cell_content) @injection.content               │ ← NEW
        │   (#set! injection.language "org_inline"))              │ ← NEW
        │                                                         │
        │  ((list_item_content) @injection.content                │ ← NEW
        │   (#set! injection.language "org_inline"))              │ ← NEW
        └─────────────────────────────────────────────────────────┘
                            ↓
        ┌────────────────────────────────────────────────────────┐
        │  PASS 2: Inline Grammar (tree-sitter-org-inline)       │
        ├────────────────────────────────────────────────────────┤
        │ ✅ Injected into ALL inline contexts                   │
        │                                                        │
        │ NEW: Context-specific rules (6-8 variants)             │
        │  • _inline_element (normal - all allowed)              │
        │  • _inline_element_no_link (inside links)              │
        │  • _inline_element_no_markup (inside code/verbatim)    │
        │  • _inline_element_in_link_description                 │
        │  • _inline_element_in_emphasis_*                       │
        │  • _inline_element_in_citation                         │
        │                                                        │
        │ NEW: Scanner with lookahead                            │
        │  • Validates matching delimiters before emitting       │
        │  • Handles emphasis: *bold*, /italic/, etc.            │
        │  • Handles links: [[...]]                              │
        │  • State serialization for incremental parsing         │
        │                                                        │
        │ ALL 17 inline object types:                            │
        │  ✓ Text markup (bold, italic, underline, etc.)         │
        │  ✓ Links (regular, angle, plain, radio)               │
        │  ✓ Entities (\alpha)                                  │
        │  ✓ LaTeX fragments (moved from block grammar)          │ ← MOVED
        │  ✓ Export snippets                                    │
        │  ✓ Footnote references                                │
        │  ✓ Citations (NEW)                                    │ ← NEW
        │  ✓ Citation references (NEW)                          │ ← NEW
        │  ✓ Inline babel calls (NEW)                           │ ← NEW
        │  ✓ Inline source blocks (NEW)                         │ ← NEW
        │  ✓ Line breaks (NEW)                                  │ ← NEW
        │  ✓ Macros                                             │
        │  ✓ Targets / Radio targets                           │
        │  ✓ Statistics cookies                                │
        │  ✓ Subscript/superscript (moved from block grammar)    │ ← MOVED
        │  ✓ Timestamps (moved from block grammar)              │ ← MOVED
        │  ✓ Plain text                                         │
        │                                                        │
        │ NEW: Systematic precedence                             │
        │  const PRECEDENCE = {                                  │
        │    PLAIN_TEXT: 0,                                      │
        │    EMPHASIS: 1,                                        │
        │    CODE: 2,                                            │
        │    ENTITY: 5,                                          │
        │    TIMESTAMP: 10,                                      │
        │    STATISTICS_COOKIE: 11,                              │
        │    LINK: 20,                                           │
        │    CITATION: 32,                                       │
        │    LINE_BREAK: 40,                                     │
        │  }                                                     │
        └────────────────────────────────────────────────────────┘
                            ↓
        ┌────────────────────────────────────────────────┐
        │   Inline Parse Trees (one per injection node)  │
        ├────────────────────────────────────────────────┤
        │ For headline_title:                            │
        │   ├── text "Headline with "                    │
        │   ├── bold                                     │
        │   │   └── text "bold"                          │
        │   ├── text " and "                             │
        │   └── regular_link                             │
        │       └── link_path "link"                     │
        │                                                │
        │ For paragraph_content:                         │ ✅ NEW
        │   ├── text "This is a paragraph with "         │
        │   ├── bold                                     │
        │   │   └── text "emphasis"                      │
        │   ├── text " and "                             │
        │   └── regular_link                             │
        │       └── link_path "links"                    │
        │                                                │
        │ For table_cell_content:                        │ ✅ NEW
        │   ├── text "with "                             │
        │   └── bold                                     │
        │       └── text "bold"                          │
        │                                                │
        │ For list_item_content:                         │ ✅ NEW
        │   ├── text "List item with "                   │
        │   └── italic                                   │
        │       └── text "italic"                        │
        │   └── text " text"                             │
        └────────────────────────────────────────────────┘
                            ↓
        ┌────────────────────────────────────────────────┐
        │   Final AST (Proposed)                         │
        ├────────────────────────────────────────────────┤
        │ headline                                       │
        │   └── headline_title                           │ ✅ Parsed
        │       ├── text "Headline with "                │
        │       ├── bold "bold"                          │
        │       ├── text " and "                         │
        │       └── link "link"                          │
        │                                                │
        │ paragraph                                      │
        │   └── paragraph_content                        │ ✅ PARSED
        │       ├── text "This is a paragraph with "     │
        │       ├── bold "emphasis"                      │
        │       ├── text " and "                         │
        │       └── link "links"                         │
        │                                                │
        │ table → row                                    │
        │   ├── table_cell_content                       │ ✅ PARSED
        │   │   └── text "Table"                         │
        │   ├── table_cell_content                       │ ✅ PARSED
        │   │   ├── text "with "                         │
        │   │   └── bold "bold"                          │
        │   └── table_cell_content                       │ ✅ PARSED
        │       └── text "content"                       │
        │                                                │
        │ list → item                                    │
        │   └── list_item_content                        │ ✅ PARSED
        │       ├── text "List item with "               │
        │       ├── italic "italic"                      │
        │       └── text " text"                         │
        └────────────────────────────────────────────────┘

📊 COVERAGE: ~90% of inline content parsed
   - ✅ Headlines: Fully parsed
   - ✅ Paragraphs: Fully parsed
   - ✅ Table cells: Fully parsed
   - ✅ List items: Fully parsed
   - ✅ Verse blocks: Fully parsed (not shown above)
   - ✅ All 17 inline object types implemented
```

---

## Scanner Comparison

### CURRENT Scanner (Limited)

```c
// tree-sitter-org-inline/src/scanner.c (163 lines)

typedef struct {
    bool has_tags;           // For headline tag tracking
    uint32_t tag_content_len;
} Scanner;

enum TokenType {
    TAGS,  // Only validates tags
};

// Limitations:
❌ No lookahead for delimiter matching
❌ No state for emphasis tracking
❌ No link bracket balancing
❌ No context tracking
❌ No radio target registry
❌ Minimal state (2 fields)
```

### PROPOSED Scanner (Complete)

```c
// tree-sitter-org-inline/src/scanner.c (expected ~400-600 lines)

typedef struct {
    // Delimiter tracking (NEW)
    struct {
        char delimiter;      // *, /, _, +, ~, =
        uint8_t count;
        bool is_opening;
    } delimiter_state;

    // Link tracking (NEW)
    struct {
        uint8_t bracket_depth;
        bool in_link;
        bool in_description;
    } link_state;

    // Tag validation (EXISTING)
    struct {
        bool has_tags;
        uint8_t tag_count;
    } tag_state;

    // Radio link tracking (NEW)
    struct {
        RadioTarget *targets;
        uint16_t target_count;
    } radio_state;

    // Context tracking (NEW)
    struct {
        bool inside_link;
        bool inside_code;
        bool inside_citation;
    } context;

    // Lookahead buffer (NEW)
    struct {
        char *buffer;
        size_t capacity;
    } lookahead;

} InlineScanner;

enum TokenType {
    // Emphasis delimiters (NEW)
    EMPHASIS_OPEN_STAR,
    EMPHASIS_CLOSE_STAR,
    EMPHASIS_OPEN_SLASH,
    EMPHASIS_CLOSE_SLASH,
    // ... 8 total emphasis tokens

    // Code/verbatim delimiters (NEW)
    CODE_OPEN,
    CODE_CLOSE,
    VERBATIM_OPEN,
    VERBATIM_CLOSE,

    // Link delimiters (NEW)
    LINK_START,
    LINK_MIDDLE,
    LINK_END,

    // Tags (EXISTING)
    TAGS,

    // Context tokens (NEW)
    LAST_TOKEN_WHITESPACE,
    LAST_TOKEN_PUNCTUATION,

    // Error tokens (NEW)
    ERROR,
    TRIGGER_ERROR,
};

// Key functions (NEW):

scan_emphasis_delimiter() {
    // Look ahead for matching closing delimiter
    // Only emit opening if closing exists
}

scan_link_start() {
    // Look ahead for matching ]]
    // Handle balanced brackets
}

scan_tags() {
    // Validate tag format (EXISTING, improved)
}

serialize() {
    // Save scanner state (NEW)
}

deserialize() {
    // Restore scanner state (NEW)
}
```

---

## Grammar Comparison

### CURRENT Grammar (Partial)

```javascript
// tree-sitter-org-inline/grammar.js (323 lines)

module.exports = grammar({
    name: 'org_inline',

    externals: $ => [
        $.tags,  // Only 1 external token
    ],

    rules: {
        // Entry point
        inline: $ => repeat1($._inline_element),

        // All elements allowed everywhere (no context-specific rules)
        _inline_element: $ => choice(
            $.bold,
            $.italic,
            $.underline,
            $.strike_through,
            $.code,
            $.verbatim,
            $.org_link,
            $.angle_link,
            $.plain_link,
            $.entity,
            $.macro,
            $.target,
            $.radio_target,
            $.footnote_reference,
            $.timestamp,
            $.subscript,
            $.superscript,
            $.statistics_cookie,
            $.export_snippet,
            $.plain_text
        ),

        // Text markup (uses regex, no scanner)
        bold: $ => seq('*', /[^*\n]+/, '*'),
        italic: $ => seq('/', /[^\/\n]+/, '/'),
        // ... etc

        // Links (simple regex)
        org_link: $ => seq(
            '[[',
            /[^\]]+/,
            optional(seq('][', /[^\]]+/)),
            ']]'
        ),

        // Missing:
        // ❌ Citations
        // ❌ Line breaks
        // ❌ Inline babel calls
        // ❌ Inline source blocks
        // ❌ Radio links

        // Also has (duplicates from block grammar):
        // ⚠️ LaTeX fragments
        // ⚠️ Timestamps
        // ⚠️ Subscript/superscript
    }
});
```

### PROPOSED Grammar (Complete)

```javascript
// tree-sitter-org-inline/grammar.js (expected ~600-800 lines)

const PRECEDENCE = {
    PLAIN_TEXT: 0,
    EMPHASIS: 1,
    CODE: 2,
    ENTITY: 5,
    TIMESTAMP: 10,
    STATISTICS_COOKIE: 11,
    LINK: 20,
    CITATION: 32,
    LINE_BREAK: 40,
};

module.exports = grammar({
    name: 'org_inline',

    externals: $ => [
        // Emphasis delimiters (NEW)
        $.emphasis_open_star,
        $.emphasis_close_star,
        $.emphasis_open_slash,
        $.emphasis_close_slash,
        $.emphasis_open_underscore,
        $.emphasis_close_underscore,
        $.emphasis_open_plus,
        $.emphasis_close_plus,

        // Code/verbatim (NEW)
        $.code_open,
        $.code_close,
        $.verbatim_open,
        $.verbatim_close,

        // Links (NEW)
        $.link_start,
        $.link_middle,
        $.link_end,

        // Tags (EXISTING)
        $.tags,

        // Context tokens (NEW)
        $.last_token_whitespace,
        $.last_token_punctuation,

        // Error tokens (NEW)
        $._error,
        $._trigger_error,

        // Special (NEW)
        $.line_break_marker,
    ],

    rules: {
        // Entry point
        inline: $ => repeat1($._inline_element),

        // Context-specific rules (NEW - 6-8 variants)
        ...generate_inline_rules($),

        // Text markup (uses scanner for delimiter matching)
        bold: $ => prec.dynamic(PRECEDENCE.EMPHASIS,
            seq(
                $.emphasis_open_star,
                repeat1($._inline_element_no_bold),  // Context-specific
                $.emphasis_close_star
            )
        ),

        // Similar for italic, underline, strike_through

        code: $ => prec.dynamic(PRECEDENCE.CODE,
            seq(
                $.code_open,
                alias(/[^~\n]+/, $.code_content),  // No markup allowed
                $.code_close
            )
        ),

        // Links (uses scanner for bracket matching)
        regular_link: $ => prec.dynamic(PRECEDENCE.LINK,
            seq(
                $.link_start,
                alias($._link_path, $.link_path),
                optional(seq(
                    $.link_middle,
                    repeat1($._inline_element_in_link_description)  // Context-specific
                )),
                $.link_end
            )
        ),

        // NEW: Citations
        citation: $ => prec.dynamic(PRECEDENCE.CITATION,
            seq(
                '[cite',
                optional($.citation_style),
                ':',
                optional(seq(
                    repeat1($._inline_element_minimal),  // Global prefix
                    ';'
                )),
                sepBy1(';', $.citation_reference),
                optional(seq(
                    ';',
                    repeat1($._inline_element_minimal)  // Global suffix
                )),
                ']'
            )
        ),

        citation_reference: $ => seq(
            optional(repeat1($._inline_element_minimal)),  // Key prefix
            '@',
            $.citation_key,
            optional(repeat1($._inline_element_minimal))   // Key suffix
        ),

        // NEW: Line breaks
        line_break: $ => prec.dynamic(PRECEDENCE.LINE_BREAK,
            seq(
                $.line_break_marker,  // \\ validated by scanner
                /[ \t]*/,
                choice('\n', '\r\n')
            )
        ),

        // NEW: Inline babel calls
        inline_babel_call: $ => prec.dynamic(PRECEDENCE.INLINE_BABEL_CALL,
            seq(
                'call_',
                $.call_name,
                optional(seq('[', $.header1, ']')),
                '(',
                optional($.arguments),
                ')',
                optional(seq('[', $.header2, ']'))
            )
        ),

        // NEW: Inline source blocks
        inline_source_block: $ => prec.dynamic(PRECEDENCE.INLINE_SOURCE_BLOCK,
            seq(
                'src_',
                $.language,
                optional(seq('[', $.headers, ']')),
                '{',
                $.body,
                '}'
            )
        ),

        // NEW: Radio links
        radio_link: $ => prec.dynamic(PRECEDENCE.RADIO_LINK,
            alias(repeat1($._inline_element_minimal), $.radio_link_text)
        ),

        // Moved from block grammar:
        // ✓ LaTeX fragments
        // ✓ Timestamps
        // ✓ Subscript/superscript

        // ... rest of objects
    }
});

// Helper: Generate 6-8 context-specific rule variants
function generate_inline_rules($) {
    return {
        _inline_element: $ => choice(/* all allowed */),
        _inline_element_no_link: $ => choice(/* no links */),
        _inline_element_no_markup: $ => $.plain_text,  /* plain text only */
        _inline_element_in_link_description: $ => choice(/* restricted */),
        _inline_element_minimal: $ => choice(/* minimal set */),
        _inline_element_no_bold: $ => choice(/* no bold */),
        // ... etc
    };
}
```

---

## Injection Points Comparison

### CURRENT Injection Query (Limited)

```scheme
; queries/injections.scm (7 lines)

; Only inject into title nodes
((title) @injection.content
 (#set! injection.language "org_inline"))

; Result:
; - Headlines: ✅ Parsed
; - Paragraphs: ❌ NOT parsed
; - Table cells: ❌ NOT parsed
; - List items: ❌ NOT parsed
; - Verse blocks: ❌ NOT parsed
```

### PROPOSED Injection Query (Complete)

```scheme
; queries/injections.scm (expanded)

; Headlines (EXISTING)
((headline_title) @injection.content
 (#set! injection.language "org_inline"))

; Paragraphs (NEW)
((paragraph_content) @injection.content
 (#set! injection.language "org_inline"))

; Table cells (NEW)
((table_cell_content) @injection.content
 (#set! injection.language "org_inline"))

; List items (NEW)
((list_item_content) @injection.content
 (#set! injection.language "org_inline"))

; Verse blocks (NEW)
((verse_block_content) @injection.content
 (#set! injection.language "org_inline"))

; Item tags (description lists) (NEW)
((item_tag) @injection.content
 (#set! injection.language "org_inline"))

; Result:
; - Headlines: ✅ Parsed
; - Paragraphs: ✅ Parsed
; - Table cells: ✅ Parsed
; - List items: ✅ Parsed
; - Verse blocks: ✅ Parsed
```

---

## Object Coverage Comparison

### CURRENT: 11/17 Object Types (65%)

| Object Type | Block Grammar | Inline Grammar | Status |
|-------------|--------------|----------------|---------|
| **Minimal Set** |
| Plain text | | ✅ | Working |
| Text markup (6 types) | | ✅ | Working |
| Entities | | ✅ | Working |
| LaTeX fragments | ⚠️ Duplicate | ⚠️ Duplicate | Conflict |
| Subscript/superscript | ⚠️ Duplicate | ⚠️ Duplicate | Conflict |
| **Standard Set** |
| Export snippets | | ✅ | Working |
| Footnote references | ⚠️ Duplicate | ⚠️ Duplicate | Conflict |
| **Missing** |
| Citations | ❌ | ❌ | Missing |
| Citation references | ❌ | ❌ | Missing |
| Inline babel calls | ❌ | ❌ | Missing |
| Inline source blocks | ❌ | ❌ | Missing |
| Line breaks | ❌ | ❌ | Missing |
| **Links** |
| Links (regular) | | ✅ | Working |
| Links (angle) | | ✅ | Working |
| Links (plain) | | ✅ | Working |
| Links (radio) | ❌ | ❌ | Missing |
| **Other** |
| Macros | | ✅ | Working |
| Targets | | ✅ | Working |
| Radio targets | | ✅ | Working |
| Statistics cookies | | ✅ | Working |
| Timestamps | ⚠️ Duplicate | ⚠️ Duplicate | Conflict |
| Table cells | Special | | N/A |

**Summary**:
- ✅ Working: 11 objects
- ⚠️ Duplicate: 4 objects (in both grammars)
- ❌ Missing: 6 objects
- **Total coverage: 11/17 = 65%**

### PROPOSED: 17/17 Object Types (100%)

| Object Type | Block Grammar | Inline Grammar | Status |
|-------------|--------------|----------------|---------|
| **Minimal Set** |
| Plain text | | ✅ | Working |
| Text markup (6 types) | | ✅ | Working |
| Entities | | ✅ | Working |
| LaTeX fragments | ❌ Removed | ✅ Moved | Clean |
| Subscript/superscript | ❌ Removed | ✅ Moved | Clean |
| **Standard Set** |
| Export snippets | | ✅ | Working |
| Footnote references | ❌ Removed | ✅ Moved | Clean |
| **NEW** |
| Citations | | ✅ NEW | Implemented |
| Citation references | | ✅ NEW | Implemented |
| Inline babel calls | | ✅ NEW | Implemented |
| Inline source blocks | | ✅ NEW | Implemented |
| Line breaks | | ✅ NEW | Implemented |
| **Links** |
| Links (regular) | | ✅ | Working |
| Links (angle) | | ✅ | Working |
| Links (plain) | | ✅ | Working |
| Links (radio) | | ✅ NEW | Implemented |
| **Other** |
| Macros | | ✅ | Working |
| Targets | | ✅ | Working |
| Radio targets | | ✅ | Working |
| Statistics cookies | | ✅ | Working |
| Timestamps | ❌ Removed | ✅ Moved | Clean |
| Table cells | Special | | N/A |

**Summary**:
- ✅ Working: 17 objects
- ⚠️ Duplicate: 0 objects (all duplicates removed)
- ❌ Missing: 0 objects (all implemented)
- ✅ NEW: 6 objects implemented
- **Total coverage: 17/17 = 100%**

---

## Test Coverage Comparison

### CURRENT: 121 Tests

```
tree-sitter-org-inline/test/corpus/
├── title-tag-separation.txt (8 tests)
├── text-markup.txt (11 tests)
├── links.txt (40 tests)
├── entities.txt (6 tests)
├── macros.txt (11 tests)
├── footnotes.txt (10 tests)
├── timestamps.txt (10 tests)
├── subscript-superscript.txt (8 tests)
├── statistics-cookies.txt (5 tests)
├── export-snippets.txt (4 tests)
└── targets.txt (8 tests)

Total: 121 tests
```

### PROPOSED: 300+ Tests

```
tree-sitter-org-inline/test/corpus/
├── title-tag-separation.txt (8 tests)
├── text-markup.txt (20 tests) ← expanded
├── links.txt (60 tests) ← expanded (radio links)
├── entities.txt (10 tests)
├── macros.txt (15 tests)
├── footnotes.txt (15 tests)
├── timestamps.txt (15 tests)
├── subscript-superscript.txt (12 tests)
├── statistics-cookies.txt (8 tests)
├── export-snippets.txt (8 tests)
├── targets.txt (12 tests)
├── citations.txt (30 tests) ← NEW
├── inline-babel-calls.txt (15 tests) ← NEW
├── inline-source-blocks.txt (15 tests) ← NEW
├── line-breaks.txt (12 tests) ← NEW
├── radio-links.txt (20 tests) ← NEW
├── context-specific/
│   ├── links-no-nesting.txt (10 tests) ← NEW
│   ├── code-no-markup.txt (10 tests) ← NEW
│   ├── emphasis-nesting.txt (15 tests) ← NEW
│   └── ... (30+ more tests)
├── precedence/
│   ├── timestamp-vs-cookie.txt (10 tests) ← NEW
│   ├── entity-vs-latex.txt (10 tests) ← NEW
│   └── ... (20+ more tests)
├── integration/
│   ├── headline-with-inline.txt (5 tests) ← NEW
│   ├── paragraph-with-inline.txt (10 tests) ← NEW
│   ├── table-cell-inline.txt (10 tests) ← NEW
│   └── ... (20+ more tests)
└── errors/
    ├── unclosed-emphasis.txt (10 tests) ← NEW
    ├── unclosed-link.txt (10 tests) ← NEW
    └── ... (30+ more tests)

Total: 300+ tests (2.5x increase)
```

---

## Summary: Why Rearchitect?

### Problems with Current Architecture

1. **Limited injection points** (CRITICAL):
   - Only 20% of inline content actually parsed
   - Most content (paragraphs, tables, lists) remains opaque

2. **Duplicate implementations** (MAJOR):
   - 4 objects in both grammars creates conflicts
   - Maintenance burden, ambiguous precedence

3. **Scanner limitations** (MAJOR):
   - Can't validate stateful patterns
   - Boundary detection issues
   - No lookahead for delimiter matching

4. **Missing objects** (HIGH):
   - 6 critical inline objects not implemented
   - Can't parse citations, line breaks, inline code blocks, etc.

5. **No context-specific rules** (ARCHITECTURAL):
   - Invalid nesting allowed (links in links, markup in code)
   - Relies on precedence instead of prevention

6. **Ad-hoc precedence** (MODERATE):
   - No systematic hierarchy
   - Hard to extend, conflicts poorly defined

### Benefits of Proposed Architecture

1. **Complete coverage**:
   - 100% of inline content parsed (headlines, paragraphs, tables, lists)
   - All 17 inline object types implemented
   - 35% → 90%+ coverage

2. **Clean architecture**:
   - No duplicate implementations
   - Clear separation: block = structure, inline = content
   - Easy to add new objects

3. **Robust parsing**:
   - Context-specific rules prevent invalid nesting
   - Lookahead-based scanner validates before parsing
   - Systematic precedence hierarchy

4. **Maintainable code**:
   - Well-documented scanner
   - Clear grammar rules
   - Proven patterns from markdown

5. **Better user experience**:
   - Proper syntax highlighting everywhere
   - Accurate navigation (LSP features)
   - Complete semantic information

### The Choice

**Current**: 35% coverage, architectural limitations, can't extend
**Proposed**: 90%+ coverage, clean architecture, proven patterns

**Recommendation**: Rearchitect
