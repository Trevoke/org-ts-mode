# Tree-Sitter Markdown Architectural Patterns - Applicability to Org-Mode

## Overview
This document extracts the most valuable architectural patterns from the tree-sitter-markdown dual-grammar implementation and discusses their potential application to org-mode syntax parsing.

---

## Pattern 1: Dual-Grammar Architecture (HIGHLY APPLICABLE)

### What Markdown Does
Separates block structure (chapters, lists, code blocks) from inline content (emphasis, links, code spans) into two independent grammars with two-pass parsing:
1. Parse entire document with **block grammar**
2. For each `inline` node, parse content with **inline grammar** using `set_included_ranges()`

### Why It Works for Markdown
- Block and inline are fundamentally different parsing problems
- Inline content is semantically isolated from block structure
- Clean separation allows each grammar to optimize for its domain

### Applicability to Org-Mode: HIGH (Major Recommendation)

Org-mode has similar structure/content separation:
- **Block structure**: Headlines (with hierarchy), drawers, tables, lists, code blocks
- **Inline content**: Emphasis (`*bold*`, `/italic*/`), links (`[[link]]`), code (`` `code` ``), special formatting

**Implementation Strategy for Org-Mode**:
```
1. Block grammar (org-structure):
   - Headlines with hierarchical structure (*)
   - Sections containing blocks
   - Indentation-based structure (drawers, property blocks)
   - Tables (| syntax)
   - Lists (-, +, 1. markers)
   - Metadata (#+TITLE, etc.)

2. Inline grammar (org-inline):
   - Text formatting (*bold*, /italic/, _underline_, +strikethrough+)
   - Links ([[...]])
   - Code spans (~code~ or `code`)
   - Objects (timestamps, citations, etc.)
   - Radio targets

3. Two-pass parsing:
   - Parse entire file with block grammar
   - Create "inline" nodes for: headlines (title), list items (content), table cells
   - Parse inline content independently
```

### Why This Solves Org-Mode Challenges
- Org-mode headlines can be complex (with tags, priorities, keywords)
- Body text is heavily formatted with nested markup
- Tables need special handling of cell content
- Property drawers have structured format

The dual-grammar approach isolates these concerns.

---

## Pattern 2: External Scanner for Stateful Tokenization (HIGHLY APPLICABLE)

### What Markdown Does
Uses C external scanner for:
1. **Block stack management** - Tracking nested containers
2. **Context-dependent rules** - Different tokens based on state
3. **Lookahead predictions** - Looking ahead to decide token type
4. **Delimiter matching** - Remembering opening/closing pairs

### Applicability to Org-Mode: HIGH

Org-mode needs similar stateful parsing:

**Block-level state management**:
```c
// Similar to markdown's block stack, org needs to track:
- Headline depth (level 1-9, sometimes 10+)
- Drawer state (properties, logbook, etc.)
- List nesting depth
- Table state
- Code block state (with info string context)

// Org-specific complexity:
- Comments: #+COMMENT can hide entire subtrees
- Hidden text: Org uses drawer syntax for hidden content
- Tag-based filtering: Headlines have tags that affect visibility
```

**Scanner approach for org-mode**:
```c
typedef struct {
    // Headline state
    uint8_t headline_level;  // Current headline level (1-9)
    
    // Nested structures
    uint8_t list_depth;
    uint8_t table_state;
    
    // Block state
    Block *open_blocks;  // Stack of open structures
    
    // Context flags
    bool in_source_block;
    uint8_t source_block_fence_length;
    
    bool in_drawer;
    uint8_t drawer_indent;
} OrgScanner;
```

**Org-specific tokens needed**:
```c
typedef enum {
    // Headline markers
    ORG_H1_MARKER, ORG_H2_MARKER, ..., ORG_H9_MARKER,
    
    // Metadata
    ORG_METADATA_LINE,
    ORG_COMMENT_BLOCK_START,
    ORG_COMMENT_BLOCK_END,
    
    // Drawer handling
    ORG_DRAWER_START,
    ORG_DRAWER_END,
    
    // Lists
    ORG_LIST_ITEM_UNORDERED,
    ORG_LIST_ITEM_ORDERED,
    ORG_CHECKBOX_UNCHECKED,
    ORG_CHECKBOX_CHECKED,
    ORG_CHECKBOX_PARTIAL,
    
    // Code/Example blocks
    ORG_CODE_BLOCK_START,
    ORG_CODE_BLOCK_END,
    
    // Tables
    ORG_TABLE_ROW,
    ORG_TABLE_SEPARATOR,
    
    // Block closures
    BLOCK_CLOSE,
    SECTION_CLOSE,
} OrgTokenType;
```

---

## Pattern 3: Context-Specific Grammar Rules (HIGHLY APPLICABLE)

### What Markdown Does
Creates 8 variants of inline rules to handle restrictions:
- `_inline_element` - All elements allowed
- `_inline_element_no_star` - Exclude * delimiters (inside star emphasis)
- `_inline_element_no_underscore` - Exclude _ delimiters
- `_inline_element_no_link` - Exclude links (prevent nesting)
- ... and combinations

This eliminates conflicts by preventing them at grammar level.

### Applicability to Org-Mode: HIGH

Org-mode has similar nesting restrictions:

```javascript
// Plain org inline rules
_inline_element = [
    $.org_link,          // [[...]]
    $.emphasis,          // *bold*, /italic/, etc.
    $.code,             // ~code~ or `code`
    $.timestamp,        // <2024-01-01>
    $.citation,         // [cite:...]
    $.radio_target,     // <<...>>
    $._text
]

// Inside links - can't nest links
_inline_element_no_link = [
    $.emphasis,
    $.code,
    $.timestamp,
    $._text
    // NOT: $.org_link
]

// Inside code - can't have markup
_inline_element_no_markup = [
    $._text  // Only plain text
]

// Inside emphasis - might have restrictions?
// (org allows nested markup inside emphasis)
_inline_element_in_emphasis = [
    $.org_link,         // Can have links
    $.code,             // Can have code
    $.timestamp,        // Can have timestamps
    $._text
    // NOT: Same emphasis delimiter (pragmatically)
]
```

**Grammar structure**:
```javascript
module.exports = grammar(add_inline_rules({
    rules: {
        // For each markup type, create restricted variants
        // Bold: *...*
        _bold: $ => seq('*', $_inline_no_emphasis, '*'),
        
        // Links: [[...]]
        _org_link: $ => seq('[[', $_inline_no_link, ']]'),
        
        // Code: ~...~
        _code_span: $ => seq('~', $_inline_element_no_markup, '~'),
    }
}));

function add_inline_rules(grammar) {
    // Generate context-specific rules
    // Eliminates conflicts rather than trying to resolve them
    return grammar;
}
```

---

## Pattern 4: State Serialization for Incremental Parsing (APPLICABLE)

### What Markdown Does
Serializes scanner state to allow resumable parsing:
```c
unsigned serialize(Scanner *s, char *buffer) {
    size_t offset = 0;
    buffer[offset++] = s->state;
    buffer[offset++] = s->matched;
    buffer[offset++] = s->indentation;
    memcpy(&buffer[offset], s->open_blocks.items, ...);
    return offset;
}
```

### Applicability to Org-Mode: MEDIUM-HIGH

Editors need incremental parsing for large org files:

```c
unsigned org_serialize(OrgScanner *s, char *buffer) {
    size_t offset = 0;
    buffer[offset++] = s->headline_level;
    buffer[offset++] = s->list_depth;
    buffer[offset++] = s->table_state;
    buffer[offset++] = s->in_source_block;
    buffer[offset++] = s->source_block_fence_length;
    // ... serialize block stack
    return offset;
}

void org_deserialize(OrgScanner *s, const char *buffer, unsigned length) {
    // Restore scanner state to continue parsing
    if (length > 0) {
        s->headline_level = buffer[0];
        s->list_depth = buffer[1];
        // ...
    }
}
```

Benefits:
- Resume parsing after user edits in large files
- Background parsing without blocking
- Tree-sitter's own resumable parsing support

---

## Pattern 5: Error Tokens for Branch Killing (HIGHLY APPLICABLE)

### What Markdown Does
Uses `$._error` tokens to eliminate invalid parse branches:
```javascript
// Paragraph ambiguity: try both continuing and ending
// Scanner emits ERROR to kill invalid branches

// Link title: two consecutive newlines are invalid
seq($._soft_line_break, optional(seq($._soft_line_break, $._trigger_error)))
```

### Applicability to Org-Mode: HIGH

Org-mode has similar ambiguities:

```javascript
// Headline keywords: can't mix certain keywords
// DONE and TODO together? ERROR
headline: $ => seq(
    $._level,
    optional($._keyword),  // Could be TODO, DONE, etc.
    optional(seq($._priority, optional($._trigger_error_for_invalid_combo))),
    $._title
)

// List items: ordered vs unordered within same level
// If list is all ordered, new unordered item should end list (or be error)

// Table cells: newlines should close cell
// Double newlines are definitely cell boundary

// Code block: only specific languages allowed?
// Invalid language name: might want to warn
```

---

## Pattern 6: Lookahead for Delimiter Matching (HIGHLY APPLICABLE)

### What Markdown Does
Before committing to opening delimiter, scanner looks ahead for closing:
```c
// Code span opening - only if matching close exists
size_t close_level = 0;
while (!lexer->eof(lexer)) {
    if (lexer->lookahead == '`') {
        close_level++;
    } else if (close_level == level) {
        break;  // Found matching delimiter!
    } else {
        close_level = 0;
    }
    lexer->advance(lexer, false);
}
if (close_level == level) {
    lexer->result_symbol = CODE_SPAN_START;
    return true;
}
```

### Applicability to Org-Mode: HIGH

Org-mode emphasis needs same pattern:

```c
// Bold: *text* - only emit BOLD_OPEN if closing * exists
static bool parse_emphasis(OrgScanner *s, TSLexer *lexer) {
    char delimiter = lexer->lookahead;  // *, /, _, +, etc.
    
    lexer->advance(lexer, false);
    lexer->mark_end(lexer);
    
    // Lookahead: is there a matching closing delimiter?
    size_t nesting_level = 1;
    while (!lexer->eof(lexer) && lexer->lookahead != '\n') {
        if (lexer->lookahead == delimiter) {
            nesting_level--;
            if (nesting_level == 0) {
                // Found closing delimiter!
                lexer->result_symbol = EMPHASIS_OPEN;
                return true;
            }
        } else if (lexer->lookahead == delimiter) {
            // Could be ambiguous, but markdown rules apply
        }
        lexer->advance(lexer, false);
    }
    
    return false;  // No closing delimiter, not emphasis
}
```

---

## Pattern 7: Block Stack for Nested Structures (HIGHLY APPLICABLE)

### What Markdown Does
Maintains stack of open blocks:
```c
typedef struct {
    Block *items;      // Stack
    size_t size;       // Current depth
    size_t capacity;   // Allocated
} BlockStack;

// At each newline:
// 1. Try to match each open block
// 2. If match fails, pop from stack (close block)
// 3. If new marker detected, push to stack (open block)
```

### Applicability to Org-Mode: VERY HIGH

Org headlines are hierarchical:
```c
// Org block types
typedef enum {
    HEADLINE_LEVEL_1, HEADLINE_LEVEL_2, ..., HEADLINE_LEVEL_9,
    LIST_ITEM,
    TABLE,
    CODE_BLOCK,
    DRAWER,
    QUOTE_BLOCK,  // #+BEGIN_QUOTE ... #+END_QUOTE
    CENTER_BLOCK,
    EXAMPLE_BLOCK,
    SPECIAL_BLOCK,  // #+BEGIN_FOO ... #+END_FOO
    ANONYMOUS,
} OrgBlock;

// Scanner state
typedef struct {
    struct {
        OrgBlock *items;
        size_t size;
    } open_blocks;
    
    // For line-by-line processing
    uint8_t matched;  // How many blocks matched on this line
    uint8_t last_headline_level;  // For detecting new headlines
} OrgBlockScanner;

// At each newline:
for (int i = 0; i < scanner->open_blocks.size; i++) {
    OrgBlock current_block = scanner->open_blocks.items[i];
    
    if (!can_continue_block(current_block, lexer)) {
        // Block must close
        emit_BLOCK_CLOSE();
        pop_block(scanner);
    }
}

// Detect new headlines
if (starts_with_asterisks(lexer)) {
    int level = count_asterisks(lexer);
    
    // Close all higher-level sections
    while (scanner->last_headline_level >= level) {
        emit_SECTION_CLOSE();
        scanner->last_headline_level--;
    }
    
    emit_HEADLINE_MARKER(level);
    scanner->last_headline_level = level;
}
```

---

## Pattern 8: Dynamic Precedence for Disambiguation (APPLICABLE)

### What Markdown Does
Uses layered precedence levels:
```javascript
const PRECEDENCE_LEVEL_EMPHASIS = 1;
const PRECEDENCE_LEVEL_LINK = 10;
const PRECEDENCE_LEVEL_HTML = 100;

// Full reference links get higher precedence
full_reference_link: $ => prec.dynamic(2 * PRECEDENCE_LEVEL_LINK, seq(...)),
```

### Applicability to Org-Mode: MEDIUM

Org-mode could benefit for:

```javascript
const PRECEDENCE_LEVEL_TIMESTAMP = 5;
const PRECEDENCE_LEVEL_LINK = 10;
const PRECEDENCE_LEVEL_RADIO_TARGET = 15;
const PRECEDENCE_LEVEL_CITATION = 20;

// Citations are more specific than links
citation: $ => prec.dynamic(PRECEDENCE_LEVEL_CITATION, seq(...)),
org_link: $ => prec.dynamic(PRECEDENCE_LEVEL_LINK, seq(...)),

// Radio targets prevent link interpretation
radio_target: $ => prec.dynamic(PRECEDENCE_LEVEL_RADIO_TARGET, seq(...)),
```

---

## Pattern 9: Meta-Tokens for Context Passing (APPLICABLE)

### What Markdown Does
Uses dummy tokens to pass context:
```javascript
_whitespace: $ => seq(
    choice($._whitespace_ge_2, / /),
    optional($._last_token_whitespace)  // Dummy token
),

// Scanner reads:
if (valid_symbols[LAST_TOKEN_WHITESPACE]) {
    // Previous char was whitespace, so * can't be closing
}
```

### Applicability to Org-Mode: MEDIUM

Org could use for:

```javascript
// Track if we're after line start (affects list parsing)
_line_start_context: $ => optional($._at_line_start),

// Track if we're after space (affects link/code parsing)
_space_context: $ => optional($._after_space),

// In scanner:
if (valid_symbols[AT_LINE_START]) {
    // We're at line start, so * could be list marker or emphasis
}
```

---

## Summary: Top 5 Patterns to Implement for Org-Mode

### 1. Dual-Grammar Architecture (CRITICAL)
Implement two grammars:
- `org-structure.js` - Headline hierarchy, drawer structure
- `org-inline.js` - Text formatting, links, code
- Two-pass parsing with `set_included_ranges()`

### 2. External Scanner for Block State (CRITICAL)
C scanner for:
- Headline level tracking
- Drawer/block state management
- List nesting depth
- Code fence matching
- Comment block detection

### 3. Context-Specific Inline Rules (IMPORTANT)
Generate variants:
- `_inline_element` - Normal
- `_inline_element_no_link` - Inside links
- `_inline_element_no_code` - Inside code spans
- Combinations as needed

### 4. Error Tokens for Branch Killing (IMPORTANT)
Use `$._error` for:
- Invalid keyword combinations
- Mixed list types
- Malformed headlines

### 5. State Serialization (NICE-TO-HAVE)
Implement for:
- Incremental parsing in editors
- Large file support
- Background parsing

---

## Implementation Roadmap

### Phase 1: Foundation
- [ ] Create `tree-sitter-org` repository structure (mirroring markdown)
- [ ] Write `grammar.js` for org block structure
- [ ] Implement basic C scanner for headline markers

### Phase 2: Block Grammar
- [ ] Scanner: headline level tracking
- [ ] Scanner: drawer/block state
- [ ] Grammar: section hierarchy
- [ ] Grammar: list structure with interrupt rules

### Phase 3: Inline Grammar
- [ ] Write `org-inline/grammar.js`
- [ ] Implement 4-6 context variants
- [ ] Scanner: emphasis delimiter matching
- [ ] Scanner: link matching

### Phase 4: Integration
- [ ] Implement two-pass parsing
- [ ] Range extraction for inline nodes
- [ ] Test incremental parsing

### Phase 5: Polish
- [ ] Add state serialization
- [ ] Optimize scanner performance
- [ ] Generate node-types.json

