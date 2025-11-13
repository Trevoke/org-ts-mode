# Tree-Sitter Markdown Dual-Grammar Implementation Analysis

## Executive Summary

The tree-sitter-markdown parser implements a sophisticated **dual-grammar architecture** that separates block structure parsing from inline content parsing. This separation allows each grammar to optimize for its specific domain while maintaining clean integration through a two-pass parsing strategy using `ts_parser_set_included_ranges`.

---

## 1. Block Grammar Structure (Main Grammar)

### Overview
Located in: `/tree-sitter-markdown/grammar.js`

The block grammar focuses exclusively on document **block structure** following the CommonMark specification. It uses an **external C scanner** (`src/scanner.c`) to manage stateful parsing that cannot be expressed purely in the tree-sitter grammar DSL.

### Key Architectural Components

#### A. Document Structure (Top-level)
```javascript
document: $ => seq(
    optional(choice(
        common.EXTENSION_MINUS_METADATA ? $.minus_metadata : choice(),
        common.EXTENSION_PLUS_METADATA ? $.plus_metadata : choice(),
    )),
    alias(prec.right(repeat($._block_not_section)), $.section),
    repeat($.section),
)
```

**Key insight**: Sections are explicitly hierarchical (h1-h6 levels), allowing the grammar to maintain proper document structure without external processing.

#### B. Block Categories
The grammar distinguishes between:

1. **Leaf blocks** (single-line or self-contained):
   - Thematic breaks
   - ATX headings (# ## ### etc.)
   - Indented code blocks
   - HTML blocks
   - Link reference definitions

2. **Container blocks** (can contain other blocks):
   - Block quotes
   - Lists (5 types: +, -, *, ., )

3. **Paragraph blocks**:
   - Standard paragraphs
   - Setext headings (underlined with === or ---)

#### C. External Scanner Tokens
The scanner emits ~40 different token types for complex stateful parsing:

**Block-opening tokens**:
- `ATX_H1_MARKER` through `ATX_H6_MARKER` - Heading markers
- `LIST_MARKER_MINUS`, `PLUS`, `STAR`, `PARENTHESIS`, `DOT` - List markers with interrupt rules
- `BLOCK_QUOTE_START` - Block quote marker
- `FENCED_CODE_BLOCK_START_BACKTICK`, `START_TILDE` - Code fence delimiters

**Block-closing tokens**:
- `BLOCK_CLOSE` - Emitted when a block must be closed
- `FENCED_CODE_BLOCK_END_BACKTICK`, `END_TILDE` - Code fence closing
- `SETEXT_H1_UNDERLINE`, `SETEXT_H2_UNDERLINE` - Setext heading underlines

**Line-level tokens**:
- `LINE_ENDING` - Triggers matching process for open blocks
- `SOFT_LINE_ENDING` - Soft breaks within paragraphs
- `SOFT_LINE_BREAK_MARKER` - For lazy continuation

**Context-specific tokens**:
- `BLANK_LINE_START` - Empty lines (important for list/blockquote handling)
- `NO_INDENTED_CHUNK` - Prevents indented code blocks in link reference definitions
- `ERROR` / `TRIGGER_ERROR` - Branch killing tokens for ambiguity resolution

### Smart Design Patterns

#### Pattern 1: Block Stack Management
```c
typedef struct {
    size_t size;
    size_t capacity;
    Block *items;  // Stack of open blocks
} BlockStack;
```

The scanner maintains a **stack of open blocks** representing nested container structures. At each newline:
1. Scanner tries to match indentation/markers for each open block
2. If a block doesn't match, it's closed
3. New blocks can be opened if markers are detected

**Why this is brilliant**: Handles arbitrary nesting depth and lazy continuation lines with O(n) complexity.

#### Pattern 2: Interrupt Rules for Lists
```c
static const bool paragraph_interrupt_symbols[] = {
    false, // INDENTED_CHUNK_START - can't interrupt paragraphs
    true,  // ATX_H1_MARKER - can interrupt
    true,  // FENCED_CODE_BLOCK_START_BACKTICK - can interrupt
    false, // LIST_MARKER_DOT_DONT_INTERRUPT - numbered lists can't interrupt
    // ...
};
```

Different block types have different "interrupt" capabilities:
- Numbered lists cannot interrupt paragraphs
- ATX headings can interrupt
- Indented code blocks cannot interrupt

This is tracked per token by the scanner, allowing **fine-grained control** over what can start a new block.

#### Pattern 3: Paragraph Lazy Continuation
The grammar uses a **branching strategy** at newlines within paragraphs:

```javascript
paragraph: $ => seq(
    alias(repeat1(choice($._line, $._soft_line_break)), $.inline), 
    choice($._newline, $._eof)
),
```

At each newline, the parser creates TWO branches:
1. **Continuation branch**: Tries to continue the paragraph with `$._soft_line_break_marker`
2. **End branch**: Tries to close the paragraph

The scanner emits `$._error` tokens to kill invalid branches. This elegantly handles "lazy continuation lines" where block markers don't appear on every line.

#### Pattern 4: Setext Heading Detection
```javascript
_setext_heading1: $ => seq(
    field('heading_content', $.paragraph),
    $.setext_h1_underline,
    choice($._newline, $._eof),
),
```

Setext headings use a clever approach:
- A paragraph is parsed first
- The scanner looks ahead on the next line for underline characters
- If found, the preceding paragraph becomes a heading

This requires the scanner to **predict** underline patterns without consuming them.

#### Pattern 5: Fenced Code Block Delimiter Matching
```c
static bool parse_fenced_code_block(Scanner *s, const char delimiter,
                                    TSLexer *lexer, const bool *valid_symbols) {
    uint8_t level = 0;
    while (lexer->lookahead == delimiter) {
        advance(s, lexer);
        level++;  // Count delimiter length
    }
    // Later: match closing with same length
    if (level >= s->fenced_code_block_delimiter_length) {
        // Can close this block
    }
}
```

The scanner **remembers the opening delimiter count** and only closes when finding an equal-length closing sequence. This handles nested backticks in code block content.

---

## 2. Inline Grammar Structure

### Overview
Located in: `/tree-sitter-markdown-inline/grammar.js`

The inline grammar handles content within block-level elements (paragraphs, headings, etc.). It focuses on:
- Emphasis (bold/italic with `*` and `_`)
- Code spans (backticks)
- Links and images
- HTML tags
- Hard line breaks
- Autolinks

### Key Architectural Components

#### A. Context-Specific Inline Rules
The grammar uses a sophisticated **code generation pattern** (`add_inline_rules` function) to create context-specific rules:

```javascript
for (let link of [true, false]) {
    for (let delimiter of [false, "star", "underscore", "tilde"]) {
        let suffix = ...;
        grammar.rules["_inline_element" + suffix] = $ => {
            // Generated rules for:
            // _inline_element (allow all)
            // _inline_element_no_star (exclude * delimiters)
            // _inline_element_no_underscore (exclude _ delimiters)
            // _inline_element_no_tilde (exclude ~ delimiters)
            // _inline_element_no_link (prevent nested links)
            // _inline_element_no_star_no_link (combined)
            // ... 8 total combinations
        };
    }
}
```

**Why this is necessary**: Inside a link's text (`[...]`), you cannot have another link. Inside emphasis started with `*`, you cannot have another `*`-based emphasis at the same level. The grammar generates **8 different inline element rules** to enforce these constraints.

#### B. Emphasis Delimiter Rules
```javascript
grammar.rules['_emphasis_star_no_link'] = $ => 
    prec.dynamic(PRECEDENCE_LEVEL_EMPHASIS, seq(
        alias($._emphasis_open_star, $.emphasis_delimiter),
        optional($._last_token_punctuation),  // Track previous char context
        $['_inline_no_star_no_link'],
        alias($._emphasis_close_star, $.emphasis_delimiter)
    ));
```

Emphasis rules include:
- **Regular emphasis** (`*text*` or `_text_`)
- **Strong emphasis** (`**text**` or `__text__`)
- **Strikethrough** (`~~text~~`) - extension
- **Context tracking**: `_last_token_whitespace` and `_last_token_punctuation` tokens

#### C. Link Types
The grammar handles multiple link syntax variants:

```javascript
shortcut_link: $ => prec.dynamic(PRECEDENCE_LEVEL_LINK, $._link_text_non_empty),
full_reference_link: $ => prec.dynamic(2 * PRECEDENCE_LEVEL_LINK, seq($._link_text, $.link_label)),
collapsed_reference_link: $ => prec.dynamic(PRECEDENCE_LEVEL_LINK, seq($._link_text, '[]')),
inline_link: $ => prec.dynamic(PRECEDENCE_LEVEL_LINK, seq($._link_text, '(', ...)),
```

Higher precedence on `full_reference_link` (2x) ensures it's preferred when both patterns could match.

#### D. Image Handling
Images follow the same structure as links with a `!` prefix:

```javascript
_image_description: $ => prec.dynamic(3 * PRECEDENCE_LEVEL_LINK, choice(
    $._image_description_non_empty, 
    seq('!', '[', prec(1, ']'))  // Empty image description
)),
```

Images can have 4 forms (inline, shortcut, full reference, collapsed reference).

#### E. HTML Tag Parsing
```javascript
_open_tag: $ => prec.dynamic(PRECEDENCE_LEVEL_HTML, seq(
    '<', $._tag_name, repeat($._attribute), 
    repeat(choice($._whitespace, $._soft_line_break)), optional('/'), '>'
)),
_attribute: $ => seq(
    repeat1(choice($._whitespace, $._soft_line_break)), 
    $._attribute_name, ..., $._attribute_value
),
```

Handles:
- Opening/closing tags with attributes
- HTML comments
- Processing instructions (`<?...?>`)
- CDATA sections
- Declarations

### Emphasis Resolution: The Delimiter-Matching Algorithm

The inline scanner implements a sophisticated **delimiter-matching strategy**:

```c
static bool parse_star(Scanner *s, TSLexer *lexer, const bool *valid_symbols) {
    // State: Are we continuing a delimiter run from before?
    if (s->num_emphasis_delimiters_left > 0) {
        // Emit individual delimiters from the run
        if ((s->state & STATE_EMPHASIS_DELIMITER_IS_OPEN) &&
            valid_symbols[EMPHASIS_OPEN_STAR]) {
            lexer->result_symbol = EMPHASIS_OPEN_STAR;
            s->num_emphasis_delimiters_left--;
            return true;
        }
        if (valid_symbols[EMPHASIS_CLOSE_STAR]) {
            lexer->result_symbol = EMPHASIS_CLOSE_STAR;
            s->num_emphasis_delimiters_left--;
            return true;
        }
    }
    
    // First delimiter in a run: count and determine direction
    uint8_t star_count = 1;
    while (lexer->lookahead == '*') {
        star_count++;
        lexer->advance(lexer, false);
    }
    
    // Look ahead to next character's context
    bool next_symbol_whitespace = ...; // space, tab, or line end
    bool next_symbol_punctuation = is_punctuation(lexer->lookahead);
    
    // Apply CommonMark emphasis rules
    if (valid_symbols[EMPHASIS_CLOSE_STAR] &&
        !valid_symbols[LAST_TOKEN_WHITESPACE] &&
        (!valid_symbols[LAST_TOKEN_PUNCTUATION] || 
         next_symbol_punctuation || next_symbol_whitespace)) {
        // This is a closing delimiter
        s->state &= ~STATE_EMPHASIS_DELIMITER_IS_OPEN;
        lexer->result_symbol = EMPHASIS_CLOSE_STAR;
        return true;
    }
}
```

**The algorithm**:
1. Count consecutive delimiters
2. Remember how many to emit individually
3. Look ahead at next character
4. Use **context information from grammar** (via `valid_symbols`):
   - `LAST_TOKEN_WHITESPACE`: Previous token was whitespace
   - `LAST_TOKEN_PUNCTUATION`: Previous token was punctuation
5. Apply **CommonMark rules**:
   - Closing delimiters take precedence when not preceded by whitespace
   - Opening delimiters require non-whitespace after them
   - Punctuation context affects interpretation

This elegantly encodes the CommonMark specification's complex emphasis rules.

### Code Span Delimiter Matching

```c
static bool parse_leaf_delimiter(TSLexer *lexer, uint8_t *delimiter_length,
                                 const bool *valid_symbols,
                                 const char delimiter,
                                 const TokenType open_token,
                                 const TokenType close_token) {
    uint8_t level = 0;
    while (lexer->lookahead == delimiter) {
        lexer->advance(lexer, false);
        level++;
    }
    lexer->mark_end(lexer);
    
    // Check if this closes an open code span
    if (level == *delimiter_length && valid_symbols[close_token]) {
        *delimiter_length = 0;
        lexer->result_symbol = close_token;
        return true;
    }
    
    // Check if this opens a new code span
    if (valid_symbols[open_token]) {
        // Lookahead to find potential closing delimiter
        size_t close_level = 0;
        while (!lexer->eof(lexer)) {
            if (lexer->lookahead == delimiter) {
                close_level++;
            } else {
                if (close_level == level) {
                    break;  // Found matching delimiter
                }
                close_level = 0;
            }
            lexer->advance(lexer, false);
        }
        if (close_level == level) {
            *delimiter_length = level;
            lexer->result_symbol = open_token;
            return true;
        }
    }
    return false;
}
```

**Clever aspect**: The scanner **looks ahead** to verify there's a matching closing delimiter before committing to opening a code span. This prevents false positives.

---

## 3. Integration & Injection Points

### Architecture: Two-Pass Parsing Strategy

The **fundamental insight** is that block and inline parsing are **completely separated**:

1. **First pass - Block parsing**:
   - Parse entire document with block grammar
   - Produces tree with `inline` nodes (leaf blocks containing text)

2. **Second pass - Inline parsing**:
   - For each `inline` node, extract byte ranges
   - Use `ts_parser_set_included_ranges()` to restrict parser to those ranges
   - Parse with inline grammar

### Implementation (Rust Binding)

```rust
pub fn parse_with<T: AsRef<[u8]>, F: FnMut(usize, Point) -> T>(
    &mut self,
    callback: &mut F,
    old_tree: Option<&MarkdownTree>,
) -> Option<MarkdownTree> {
    // Step 1: Parse block structure with entire document range
    parser.set_included_ranges(&[])
        .expect("Can not set included ranges to whole document");
    parser.set_language(block_language)
        .expect("Could not load block grammar");
    let block_tree = parser.parse_with(callback, old_tree.map(|tree| &tree.block_tree))?;
    
    // Step 2: Identify inline nodes and parse them individually
    parser.set_language(inline_language)
        .expect("Could not load inline grammar");
    let mut tree_cursor = block_tree.walk();
    
    // Walk the block tree looking for inline nodes
    'outer: loop {
        let node = loop {
            let kind = tree_cursor.node().kind();
            if kind == "inline" || kind == "pipe_table_cell" || !tree_cursor.goto_first_child() {
                while !tree_cursor.goto_next_sibling() {
                    if !tree_cursor.goto_parent() {
                        break 'outer;
                    }
                }
            }
            let kind = tree_cursor.node().kind();
            if kind == "inline" || kind == "pipe_table_cell" {
                break tree_cursor.node();
            }
        };
        
        // Step 3: Extract ranges for inline content
        let mut range = node.range();
        let mut ranges = Vec::new();
        
        if tree_cursor.goto_first_child() {
            // Skip child blocks (e.g., nested lists in paragraphs)
            // Calculate the text ranges BETWEEN children
            while tree_cursor.goto_next_sibling() {
                if !tree_cursor.node().is_named() {
                    continue;
                }
                let child_range = tree_cursor.node().range();
                ranges.push(Range {
                    start_byte: range.start_byte,
                    start_point: range.start_point,
                    end_byte: child_range.start_byte,
                    end_point: child_range.start_point,
                });
                range.start_byte = child_range.end_byte;
                range.start_point = child_range.end_point;
            }
            tree_cursor.goto_parent();
        }
        ranges.push(range);  // Final range
        
        // Step 4: Parse inline content with restricted ranges
        parser.set_included_ranges(&ranges).ok()?;
        let inline_tree = parser.parse_with(callback, old_tree.and_then(...))?;
        inline_trees.push(inline_tree);
        inline_indices.insert(node.id(), i);
    }
}
```

### Boundary Handling: Key Details

#### Block-Inline Boundary Definition
An `inline` node is created by the **block grammar** wherever inline content can appear:

```javascript
// In block grammar
_atx_heading_content: $ => prec(1, seq(
    optional($._whitespace),
    field('heading_content', alias($._line, $.inline))  // <- Creates inline node
)),

paragraph: $ => seq(
    alias(repeat1(choice($._line, $._soft_line_break)), $.inline),  // <- Creates inline node
    choice($._newline, $._eof)
),
```

The block grammar creates `inline` nodes but **does not parse their content**. It just marks where inline content exists.

#### Range Extraction for Inline Parsing
The Rust binding extracts the **exact byte ranges** of inline content:

```rust
// Example: paragraph with embedded code block
// "text [link](url)\n\n- list item"
//
// Block tree: paragraph(inline) + list
// Inline ranges: 0-20 (just the paragraph text, not the list)
```

This is **crucial** because:
1. Avoids reparsing block structure
2. Prevents inline grammar from trying to parse list markers
3. Handles mixed content correctly

#### Lazy Evaluation
Inline trees are only created when needed:
- If an inline node is empty, no inline tree is created
- Old inline trees are reused if ranges haven't changed

---

## 4. External Scanners: Why and How

### Why External Scanners Are Necessary

Tree-sitter's grammar DSL is **limited by design** - it cannot express:
1. **Stateful tokenization** - Remembering context across tokens
2. **Lookahead predictions** - Looking ahead to decide token type
3. **Delimiter matching** - Matching pairs where count matters
4. **Context-dependent rules** - Different rules based on parser state
5. **Stack-based parsing** - Tracking nested structures

The markdown spec requires all of these, so external scanners are essential.

### Block Grammar Scanner (`scanner.c` - 60KB)

#### Scanner State
```c
typedef struct {
    struct {
        size_t size;
        size_t capacity;
        Block *items;  // Stack of open blocks
    } open_blocks;
    
    uint8_t state;  // Bitflags: MATCHING, WAS_SOFT_LINE_BREAK, CLOSE_BLOCK
    uint8_t matched;  // Number of blocks matched on this line
    uint8_t indentation;  // Spaces/tabs consumed but not used
    uint8_t column;  // Current column for tab expansion
    uint8_t fenced_code_block_delimiter_length;  // For matching closing fence
    
    bool simulate;  // For lookahead without consuming
} Scanner;
```

#### Token Emission Strategy
**At each newline** (`LINE_ENDING` trigger):

1. **Match phase**: Try to match each open block
   ```c
   // For block quotes: look for '>'
   // For lists: look for marker + space
   // For indented code: look for 4+ spaces
   if (lexer->lookahead == '>') {
       // Emit BLOCK_CONTINUATION
   }
   ```

2. **Close phase**: Close blocks that don't match
   ```c
   if (!matched_all_blocks) {
       emit_block_close();
   }
   ```

3. **New block phase**: Detect opening markers
   ```c
   if (lexer->lookahead == '#') {
       emit_atx_heading_marker();  // ATX_H1_MARKER, etc.
   }
   ```

#### Key Tokens and Their Purposes

| Token | Purpose | When Emitted |
|-------|---------|--------------|
| `LINE_ENDING` | Triggers end-of-line processing | After `\n` or `\r\n` |
| `BLOCK_CONTINUATION` | Extends current block | When parent block's marker matched |
| `BLOCK_CLOSE` | Ends a block | When block's conditions no longer met |
| `ATX_H*_MARKER` | Starts heading | When line starts with `#`-`######` |
| `LIST_MARKER_*` | Starts list item | When line has marker + space |
| `LIST_MARKER_*_DONT_INTERRUPT` | Can't interrupt paragraph | Numbered lists after paragraph |
| `FENCED_CODE_BLOCK_START_*` | Opens code fence | When `\`\`\`` or `~~~` with 3+ |
| `FENCED_CODE_BLOCK_END_*` | Closes code fence | When matching delimiter found |
| `BLANK_LINE_START` | Marks empty line | For whitespace-only lines |
| `ERROR` | Kills parse branch | When ambiguity resolved |

#### Paragraph Ambiguity Resolution
Paragraphs have **complex ending rules** - they can be interrupted by:
- Headings
- Thematic breaks
- Lists
- Block quotes
- But NOT by indented code blocks

The scanner uses **error tokens** to kill invalid branches:

```c
// If we're in a paragraph and see:
// 1. A potential block start marker
// 2. But haven't confirmed it's not indented code

// Emit ERROR to kill this branch if it turns out to be indented code
```

### Inline Grammar Scanner (`scanner.c` - 16KB)

#### Scanner State
```c
typedef struct {
    uint8_t state;  // Only one flag: EMPHASIS_DELIMITER_IS_OPEN
    uint8_t code_span_delimiter_length;  // For matching backticks
    uint8_t latex_span_delimiter_length;  // For matching dollars
    uint8_t num_emphasis_delimiters_left;  // From current run
} Scanner;
```

Simpler because inline structure is **less stateful** than block structure.

#### Token Emission Strategy
**At each delimiter character** (`*`, `_`, `~`, `` ` ``, `$`):

1. **Delimiter count**: How many consecutive delimiters?
2. **Context lookup**: Is this open or close?
   - Use `valid_symbols` from grammar to check:
     - Can `EMPHASIS_OPEN_STAR` be emitted?
     - Can `EMPHASIS_CLOSE_STAR` be emitted?
   - Also check:
     - `LAST_TOKEN_WHITESPACE`: Previous char was space/tab
     - `LAST_TOKEN_PUNCTUATION`: Previous char was punctuation

3. **CommonMark rules**: Apply disambiguation
   ```
   If (!prev_is_whitespace && next_is_not_whitespace) => Can be opening
   If (prev_is_not_whitespace && next_is_not_whitespace) => Can be closing
   ```

4. **Lookahead for code spans**:
   ```c
   // If we see backticks, scan ahead to find closing
   while (!eof()) {
       if (current == '`' && count == level) {
           return OPEN_CODE_SPAN;
       }
   }
   // If no match found, return UNCLOSED_SPAN
   ```

#### Critical Scanner Feature: `valid_symbols` Parameter

The scanner receives `valid_symbols` - a boolean array indicating which tokens are valid in the current parser state:

```c
bool tree_sitter_markdown_inline_external_scanner_scan(
    void *payload, 
    TSLexer *lexer, 
    const bool *valid_symbols  // <- Grammar tells scanner what's allowed
) {
    // Use valid_symbols[CODE_SPAN_OPEN] to decide whether to emit it
}
```

This creates a **feedback loop**:
- Grammar constrains what scanner can emit
- Scanner emits tokens that make those constraints meaningful
- E.g., "inside links, don't emit `[` or `]` as text"

---

## 5. Precedence and Ambiguity Handling

### Precedence Strategy: Layered Approach

#### Global Precedence Levels
```javascript
const PRECEDENCE_LEVEL_EMPHASIS = 1;
const PRECEDENCE_LEVEL_LINK = 10;
const PRECEDENCE_LEVEL_HTML = 100;
```

HTML tags have **higher precedence** than links, which have higher precedence than emphasis. This reflects CommonMark semantics.

#### Dynamic Precedence
```javascript
full_reference_link: $ => prec.dynamic(2 * PRECEDENCE_LEVEL_LINK, seq(...)),
inline_link: $ => prec.dynamic(PRECEDENCE_LEVEL_LINK, seq(...)),
```

Full reference links (`[text][ref]`) have **2x higher precedence** than inline links (`[text](url)`). This helps the parser prefer the more specific pattern.

### Conflict Resolution Strategies

#### Strategy 1: Context-Specific Rules
Instead of having conflicts, create **multiple specialized rules**:

```javascript
// Don't allow '*' inside star-based emphasis
_inline_element_no_star = [images, links, underscore-emphasis, text, ...]
_inline_element = [images, links, all-emphasis, text, ...]
```

This **eliminates conflicts** by preventing them at the grammar level.

#### Strategy 2: Precedence Tiebreaking
```javascript
[$._strong_emphasis_star_no_link, $._inline_element_no_star_no_link],
// Strong emphasis preferred over other inline elements
```

#### Strategy 3: Error Tokens for Branch Killing
The grammar uses `$._error` tokens to kill invalid parse branches:

```javascript
// In link title parsing
seq($._soft_line_break, optional(seq($._soft_line_break, $._trigger_error)))
```

Two consecutive line breaks in a link title trigger error, preventing that parse path.

#### Strategy 4: Prioritized Matching
The scanner uses the **order of checks** to implement priority:

```c
switch (lexer->lookahead) {
    case '`':  // Code spans checked first
        return parse_backtick(s, lexer, valid_symbols);
    case '*':  // Then emphasis
        return parse_star(s, lexer, valid_symbols);
    case '_':
        return parse_underscore(s, lexer, valid_symbols);
}
```

### Emphasis Ambiguity Example

Consider: `*text_with_underscore*`

Is this:
1. `*text_with_underscore*` - Single star emphasis?
2. `*text` `_with_underscore` `*` - Mixed delimiters?

**Solution: Context rules**
```javascript
_inline_no_star = [
    $.image,
    $.code_span,
    $._emphasis_underscore_no_link,  // Only underscore emphasis
    $._text_base,
    ...
    // Notably MISSING: emphasis with stars
]

_emphasis_star = seq(
    $.emphasis_open_star,
    optional($._last_token_punctuation),
    $_inline_no_star,  // Content can't have star emphasis
    $.emphasis_close_star
)
```

**Result**: Can't nest same-delimiter emphasis, preventing ambiguity.

### Link Nesting Ambiguity

Consider: `[[link1](url1)](url2)`

Is this:
1. A link containing a link? (Invalid)
2. Something else?

**Solution: Link context rule**
```javascript
_inline_no_link = [
    $.image,
    $.code_span,
    all_emphasis,
    $.html_tag,
    $._text_base,
    // Notably MISSING: any link type
]

// Links can only contain _inline_no_link
_link_text_non_empty: $ => seq(
    '[', 
    alias($_inline_no_link, $.link_text),  // No nested links!
    ']'
),
```

**Result**: Nested links are grammatically impossible.

### HTML Tag vs Text Conflict

Consider: `<incomplete`

Is this:
1. Start of an HTML tag?
2. Just text?

**Solution: Lookahead in scanner**
```c
// When scanner sees '<', it doesn't immediately emit TAG_START
// Instead, it looks ahead to see if there's a valid tag name
// If not, returns false, letting grammar treat it as text
```

---

## 6. Clever Architectural Patterns

### Pattern 1: Two-Stage Tokenization

**Stage 1 - Block Scanner**: Emits block structure tokens
**Stage 2 - Inline Scanner**: Emits inline structure tokens

This **separation of concerns** allows each scanner to be simpler:
- Block scanner: 1000+ lines of delimiter/indentation logic
- Inline scanner: 400 lines of emphasis/code span logic

Neither has to understand the other's domain.

### Pattern 2: State Serialization for Incremental Parsing

```c
unsigned serialize(Scanner *s, char *buffer) {
    buffer[size++] = (char)s->state;
    buffer[size++] = (char)s->matched;
    buffer[size++] = (char)s->indentation;
    // ... serialize stack ...
    return size;
}
```

Tree-sitter can **pause and resume** parsing by saving/restoring scanner state. This enables:
- Efficient incremental parsing for editors
- Resumable long-running parses

### Pattern 3: Simulation Mode for Lookahead

```c
typedef struct {
    // ...
    bool simulate;  // Lookahead flag
} Scanner;

static void mark_end(Scanner *s, TSLexer *lexer) {
    if (!s->simulate) {  // Only mark if not simulating
        lexer->mark_end(lexer);
    }
}
```

When `simulate=true`, the scanner can look ahead without actually consuming tokens. This is used for:
- Finding matching delimiters
- Detecting paragraph interruption
- Disambiguating block types

### Pattern 4: Bit-Flag State Management

```c
static const uint8_t STATE_MATCHING = 0x1 << 0;  // Bit 0
static const uint8_t STATE_WAS_SOFT_LINE_BREAK = 0x1 << 1;  // Bit 1
static const uint8_t STATE_CLOSE_BLOCK = 0x1 << 4;  // Bit 4

// Usage
if (s->state & STATE_MATCHING) { ... }
s->state |= STATE_MATCHING;
s->state &= ~STATE_MATCHING;
```

Packs multiple boolean flags into one byte, reducing memory usage and improving cache locality. Critical for performance since scanner state is copied on every parse attempt.

### Pattern 5: Lazy Branch Creation

The grammar uses tree-sitter's **conflict resolution** to create branches lazily:

```javascript
paragraph: $ => seq(
    alias(repeat1(choice($._line, $._soft_line_break)), $.inline),
    choice($._newline, $._eof)
),

// At each newline inside a paragraph, tree-sitter creates two parse states:
// 1. Continue paragraph (with soft line break)
// 2. End paragraph (with line ending)
```

Tree-sitter **only materializes** the two branches at newlines, not at every character. This keeps the parsing DFA manageable.

### Pattern 6: Grammar-Driven Scanner Decisions

The `valid_symbols` parameter creates a **bidirectional constraint**:

```c
// Inline scanner, when seeing '*':
if (valid_symbols[EMPHASIS_CLOSE_STAR]) {
    // Grammar says this could be a closing delimiter
    // So check if it looks like one
}
```

The **grammar tells the scanner** what's possible, and the scanner only emits tokens that make sense grammatically. This prevents the scanner from being a standalone lexer.

### Pattern 7: Context Tracking via Tokens

The grammar uses special tokens to pass context to the scanner:

```javascript
_whitespace: $ => seq(
    choice($._whitespace_ge_2, / /), 
    optional($._last_token_whitespace)  // <- Meta-token
),
```

The `$._last_token_whitespace` and `$._last_token_punctuation` tokens don't match anything - they're signals to the **next** token about what the **previous** token was:

```c
// Inline scanner checks:
if (valid_symbols[LAST_TOKEN_WHITESPACE]) {
    // Previous character was whitespace
    // So this delimiter can't be closing
}
```

This clever encoding allows the scanner to understand context without explicit state.

### Pattern 8: Overlapping vs Non-Overlapping Ranges for Inline Parsing

```rust
// When extracting ranges for inline parsing:
if tree_cursor.goto_first_child() {
    while tree_cursor.goto_next_sibling() {
        if !tree_cursor.node().is_named() { continue; }
        
        // Calculate text between children
        let child_range = tree_cursor.node().range();
        ranges.push(Range {
            start_byte: range.start_byte,
            end_byte: child_range.start_byte,  // <- BEFORE child
        });
        range.start_byte = child_range.end_byte;  // <- AFTER child
    }
    tree_cursor.goto_parent();
}
ranges.push(range);  // <- Remainder
```

This calculates **non-overlapping ranges** of text that should be parsed as inline content, skipping over any nested block structures. This is crucial for correctness.

---

## 7. Handling Complex Inline Elements

### Code Spans - Backtick Matching

**CommonMark rule**: A code span must start and end with the same number of backticks.

```
`code` - 1 backtick
``code`` - 2 backticks
```

**Implementation**:
```c
// Scanner at first backtick
uint8_t level = 0;
while (lexer->lookahead == '`') {
    level++;
    lexer->advance(lexer, false);
}
// Lookahead to find potential closing
size_t close_level = 0;
while (!lexer->eof(lexer)) {
    if (lexer->lookahead == '`') {
        close_level++;
    } else if (close_level == level) {
        break;  // Found match!
    } else {
        close_level = 0;
    }
    lexer->advance(lexer, false);
}
```

**Key insight**: The scanner **stores the opening count** and only closes when finding an exact match. Handles edge cases:
- Backticks inside code span: `` `backtick inside` `` becomes one code span
- Multiple code spans: `` `a` `b` `` are separate

### Emphasis - Multi-Level Resolution

**CommonMark rules for emphasis** (simplified):
1. Count consecutive delimiters
2. Previous character context: whitespace or punctuation?
3. Next character context: whitespace or punctuation?
4. Apply heuristics to determine open vs close

**Grammar encoding**:
```javascript
// 8 versions of inline rules to handle all contexts
// _inline (normal)
// _inline_no_star (inside star emphasis)
// _inline_no_underscore (inside underscore emphasis)  
// _inline_no_tilde (inside strikethrough)
// _inline_no_link (inside link text)
// _inline_no_star_no_link (inside both)
// ... etc
```

**Scanner disambiguation**:
```c
bool next_symbol_whitespace = line_end || lexer->lookahead == ' ' || ...;
bool next_symbol_punctuation = is_punctuation(lexer->lookahead);

if (valid_symbols[EMPHASIS_CLOSE_STAR] &&
    !valid_symbols[LAST_TOKEN_WHITESPACE] &&
    (!valid_symbols[LAST_TOKEN_PUNCTUATION] || 
     next_symbol_punctuation || next_symbol_whitespace)) {
    // This is definitely closing
    lexer->result_symbol = EMPHASIS_CLOSE_STAR;
    return true;
}
```

The scanner uses **CommonMark rules directly** in the code, implementing:
- Precedence (closing > opening)
- Context-dependent behavior
- Character class matching (whitespace, punctuation, other)

### Links - Reference vs Inline

**Variants**:
1. `[text](url)` - Inline link
2. `[text][ref]` - Full reference link
3. `[text]` - Shortcut reference link (implicit reference = text)
4. `[text][]` - Collapsed reference link (explicit reference = text)

**Grammar solution**:
```javascript
shortcut_link: $ => prec.dynamic(PRECEDENCE_LEVEL_LINK, $._link_text_non_empty),
full_reference_link: $ => prec.dynamic(2 * PRECEDENCE_LEVEL_LINK, seq(...)),
collapsed_reference_link: $ => prec.dynamic(PRECEDENCE_LEVEL_LINK, seq(...)),
inline_link: $ => prec.dynamic(PRECEDENCE_LEVEL_LINK, seq(...)),
```

**Precedence**:
- Full reference (2x): `[text][ref]` - most specific, highest priority
- Others (1x): All other forms compete equally

This allows the parser to prefer the most informative form.

### Link Text Constraint

**Problem**: Links can't be nested - `[[text]]` is invalid.

**Solution**: The grammar enforces this:
```javascript
_link_text_non_empty: $ => seq(
    '[',
    alias($_inline_no_link, $.link_text),  // <- No links allowed!
    ']'
),

_inline_no_link = [
    images (which can't have nested images),
    code_spans,
    emphasis,
    html_tags,
    plain_text,
    // NOT: links
]
```

The rule **prevents** nested links at the grammar level, eliminating the need for scanner-level disambiguation.

### Images - Description Parsing

Images need special handling for their **description text** (alt text):

```javascript
_image_description_non_empty: $ => seq(
    '!', '[',
    alias($._inline, $.image_description),  // <- Full inline parsing
    prec(1, ']')
),
```

**Key difference**: Image descriptions can contain all inline elements (emphasis, links, etc.) EXCEPT... nested images! This is handled by context:

```javascript
_image_shortcut_link: $ => prec.dynamic(3 * PRECEDENCE_LEVEL_LINK, $._image_description_non_empty),
// Shortcut images have higher precedence to prevent `![image]` from being
// interpreted as text `!` + shortcut link `[image]`
```

### Hard Line Breaks

**Two syntaxes**:
1. `\` at end of line
2. 2+ trailing spaces at end of line

**Grammar**:
```javascript
hard_line_break: $ => seq(
    choice(
        '\\',  // Backslash
        $._whitespace_ge_2  // 2+ spaces
    ),
    $._soft_line_break
),
```

**Distinction**: `_whitespace_ge_2` matches specifically "2 or more spaces or a tab":
```javascript
_whitespace_ge_2: $ => /\t| [ \t]+/,  // Tab or 2+ spaces
_whitespace: $ => seq(choice($._whitespace_ge_2, / /), ...),  // May be single space
```

This allows the grammar to distinguish between:
- `text ` (single space - not a hard break)
- `text  ` (two spaces - hard break)
- `text\` (backslash - hard break)

### HTML Tags - Attribute Parsing

**Complex rules** for attributes:
```javascript
_attribute: $ => seq(
    repeat1(choice($._whitespace, $._soft_line_break)),  // Spaces/newlines
    $._attribute_name,  // Name
    repeat(choice($._whitespace, $._soft_line_break)),  // Spaces/newlines
    '=',  // Equals sign
    repeat(choice($._whitespace, $._soft_line_break)),  // Spaces/newlines
    $._attribute_value  // Value
),
_attribute_value: $ => choice(
    /[^ \t\r\n"'=<>`]+/,  // Unquoted
    seq("'", repeat(...), "'"),  // Single quoted
    seq('"', repeat(...), '"'),  // Double quoted
),
```

The grammar handles:
- Whitespace between attribute parts
- Line breaks in attributes
- Different quoting styles
- Unquoted attribute values

This mirrors HTML5 spec complexity within tree-sitter's DSL.

### Autolinks - Email and URI

```javascript
uri_autolink: $ => /<[a-zA-Z][a-zA-Z0-9+\.\-][a-zA-Z0-9+\.\-]*:[^ \t\r\n<>]*>/,
email_autolink: $ => /<[a-zA-Z0-9.!#$%&'*+/=?^_`{|}~-]+@[a-zA-Z0-9](?:[...]*>/,
```

These are **pure regex** matching in the grammar (no scanner involvement). The CommonMark spec defines them precisely enough that regex suffices.

Note: The URI regex is simpler than the spec allows to avoid binary bloat (as mentioned in code comment).

---

## Summary: Key Takeaways for Org-Mode Grammar Design

1. **Separate Block and Inline Parsing**: Use two grammars and two-pass parsing. This is the key architectural decision that makes everything manageable.

2. **Use External Scanners Strategically**: Not for every token, but for stateful, context-dependent parsing. Block scanner tracks a stack, inline scanner tracks delimiter runs.

3. **Context-Specific Grammar Rules**: Instead of resolving conflicts in the scanner, create multiple grammar rules for different contexts (no-star, no-link, etc.).

4. **Leverage `valid_symbols`**: Let the grammar guide the scanner's decisions via this feedback loop.

5. **Binary Flags for Scanner State**: Use bit fields to minimize state serialization (critical for incremental parsing).

6. **Precedence Over Conflicts**: Use dynamic precedence to disambiguate, rather than allowing conflicts.

7. **Error Tokens as Branch Killers**: Use `$._error` tokens to eliminate invalid parse paths.

8. **Two-Pass Inline Parsing**: Extract ranges from block tree, parse inline content independently with included_ranges.

9. **Lookahead for Delimiter Matching**: When scanner sees a delimiter, look ahead to see if there's a matching closing delimiter before committing.

10. **Encode Specification Directly**: As much as possible, encode the markdown spec's rules directly in the code (emphasis rules, paragraph interruption rules, etc.).

