# Tree-Sitter Markdown Dual-Grammar: Quick Reference

## Core Architecture Decision
```
SINGLE GRAMMAR (naive) ❌
    Problem: Block and inline have fundamentally different parsing needs
    
DUAL GRAMMAR (markdown approach) ✅
    1. Block grammar: Parses document structure (headings, lists, blocks)
    2. Inline grammar: Parses text content (emphasis, links, code)
    3. Two-pass: Parse blocks first, then inline content independently
```

## Why Two Grammars?

### Problem 1: Conflicting Rules
- In block mode: `*` is a list marker or thematic break
- In inline mode: `*` is emphasis delimiter
- Single grammar can't express both naturally

**Solution**: Two separate grammars, each with appropriate tokens

### Problem 2: Nesting Restrictions
- Links can't contain links: `[[link1](url1)](url2)` is invalid
- Code can't contain markup: backtick code spans
- Emphasis has context rules

**Solution**: Context-specific grammar rules with 8 variants:
```
_inline_element_no_star
_inline_element_no_underscore
_inline_element_no_link
_inline_element_no_star_no_link
... (all combinations)
```

### Problem 3: Stateful Tokenization
- Headline levels must be tracked for setext heading detection
- Code fence delimiters must match in length
- Block nesting must be tracked
- Can't express with pure grammar

**Solution**: External C scanner maintains state and emits contextual tokens

## Two-Pass Parsing: How It Works

```
Input: "# Title\n\nParagraph with *emphasis*"
                    ↓
        ┌─────────────────────────┐
        │ Pass 1: Block Grammar   │
        ├─────────────────────────┤
        │ • Parse headlines       │
        │ • Parse paragraphs      │
        │ • Identify inline nodes │
        │ • No inline parsing     │
        └─────────────────────────┘
                    ↓
        Block Tree:
        ├── section
        │   ├── atx_heading (content="# Title")
        │   └── paragraph
        │       └── inline (="Paragraph with *emphasis*")
                    ↓
        ┌─────────────────────────────┐
        │ Pass 2: Inline Grammar      │
        ├─────────────────────────────┤
        │ For each inline node:       │
        │ • Extract byte range        │
        │ • set_included_ranges()     │
        │ • Parse with inline grammar │
        └─────────────────────────────┘
                    ↓
        Inline Tree (for the inline node):
        ├── text "Paragraph with "
        └── emphasis
            └── text "emphasis"
                    ↓
        Combined: Block tree + Inline trees
```

## External Scanner: What and Why

### What It Does
```c
// Maintains state
Scanner state = {
    open_blocks = [BLOCK_QUOTE, LIST_ITEM],  // Stack
    headline_level = 2,
    indentation = 4,
    column = 5,
    ...
};

// At each trigger (e.g., newline), emits tokens
emit(LINE_ENDING);
emit(BLOCK_CONTINUATION);  // For BLOCK_QUOTE
emit(BLOCK_CLOSE);         // For LIST_ITEM
emit(ATX_H2_MARKER);       // For new headline
```

### Why It's Necessary
```
Tree-sitter grammar = Pure declarative rules (context-free)
Markdown = Complex stateful rules (context-sensitive)

Examples:
1. "Count delimiter length and match it later" → Need state
2. "Close all open blocks at this level" → Need stack
3. "Look ahead to see if there's a matching close" → Need lookahead
4. "Is this an opening or closing delimiter?" → Need context
```

### Scanner Complexity

**Block Scanner** (~1000 lines of C):
- Tracks headline level
- Maintains block stack (nested containers)
- Handles indentation (tabs, spaces)
- Detects paragraph interruption
- Matches fenced code block delimiters
- Detects HTML block patterns
- Handles list marker variants

**Inline Scanner** (~400 lines of C):
- Counts consecutive emphasis delimiters
- Looks ahead for matching delimiters (code spans)
- Checks context (punctuation, whitespace)
- Emits emphasis open/close tokens

## Key Token Types

### Block Scanner Outputs ~40 Tokens

**Structural**:
- `LINE_ENDING` - Triggers processing at line end
- `BLOCK_CONTINUATION` - Block continues to next line
- `BLOCK_CLOSE` - Block ends
- `SECTION_CLOSE` - Section ends (markdown-specific)

**Markers**:
- `ATX_H1_MARKER` through `ATX_H6_MARKER` - Heading markers
- `LIST_MARKER_MINUS`, `PLUS`, `STAR`, `DOT`, `PARENTHESIS` - List markers
- `LIST_MARKER_*_DONT_INTERRUPT` - Can't interrupt paragraphs
- `BLOCK_QUOTE_START` - Block quote marker

**Delimiters**:
- `FENCED_CODE_BLOCK_START_BACKTICK`, `START_TILDE` - Fence open
- `FENCED_CODE_BLOCK_END_BACKTICK`, `END_TILDE` - Fence close
- `SETEXT_H1_UNDERLINE`, `SETEXT_H2_UNDERLINE` - Heading underlines

**Special**:
- `ERROR` / `TRIGGER_ERROR` - Kill invalid parse branches
- `BLANK_LINE_START` - Empty line detected
- `NO_INDENTED_CHUNK` - Prevent indented code in certain contexts

### Inline Scanner Outputs ~15 Tokens

**Delimiters**:
- `EMPHASIS_OPEN_STAR`, `EMPHASIS_CLOSE_STAR` - `*` emphasis
- `EMPHASIS_OPEN_UNDERSCORE`, `EMPHASIS_CLOSE_UNDERSCORE` - `_` emphasis
- `STRIKETHROUGH_OPEN`, `STRIKETHROUGH_CLOSE` - `~~` strikethrough
- `CODE_SPAN_START`, `CODE_SPAN_CLOSE` - Backtick code spans
- `LATEX_SPAN_START`, `LATEX_SPAN_CLOSE` - `$` LaTeX

**Context**:
- `LAST_TOKEN_WHITESPACE` - Dummy token (for grammar signal)
- `LAST_TOKEN_PUNCTUATION` - Dummy token (for grammar signal)
- `UNCLOSED_SPAN` - Delimiter without matching close
- `ERROR`, `TRIGGER_ERROR` - Branch killing

## Inline Rule Generation Pattern

Instead of defining inline rules manually, generate them:

```javascript
// For each combination of:
// - With/without links (link context)
// - No star / no underscore / no tilde (emphasis context)

for (let link of [true, false]) {                    // 2 options
    for (let delimiter of [false, "star", "underscore", "tilde"]) {
        // 4 options
        grammar.rules["_inline_element" + suffix] = $ => {
            // Generate rule
        };
    }
}

// Result: 2 × 4 = 8 rule variants
// _inline_element (all allowed)
// _inline_element_no_star (inside *emphasis*)
// _inline_element_no_underscore (inside _emphasis_)
// _inline_element_no_tilde (inside ~~strikethrough~~)
// _inline_element_no_link (inside [[link]])
// _inline_element_no_star_no_link
// _inline_element_no_underscore_no_link
// _inline_element_no_tilde_no_link
```

**Benefit**: Eliminates conflicts by preventing invalid grammar trees

## Emphasis Disambiguation Algorithm

```
Input: "*text*"

Scanner sees '*':
  1. Count consecutive: 1 star
  2. Look ahead: text follows
  3. Check context:
     - is_previous_whitespace? (e.g., after space)
     - is_next_whitespace? (newline follows?)
     - is_previous_punctuation?
     - is_next_punctuation?
  4. Apply CommonMark rules:
     - If prev is not whitespace AND
     - If (next is not whitespace OR prev is punctuation):
       → Can be opening
     - If next is not whitespace AND
     - If (prev is not whitespace OR next is punctuation):
       → Can be closing

  5. When context says both open and close are possible:
     Prefer CLOSING (closing delimiters take precedence)

Result: Correct interpretation of emphasis
```

## Range Extraction for Inline Parsing

```javascript
// Block tree contains paragraph with children:
paragraph(inline)
  ├── child1: code_block
  ├── child2: image
  └── inline content

// Extract ranges between/around children:
Range 1: [start of inline ... start of code_block)
Range 2: [end of code_block ... start of image)
Range 3: [end of image ... end of inline)

// Ranges don't overlap children - inline grammar
// only sees text, not block elements

// Set included_ranges for inline parser:
parser.set_included_ranges([range1, range2, range3]);
inline_tree = parser.parse(...);
```

## State Serialization for Incremental Parsing

```c
struct Scanner {
    Block open_blocks[20];      // 20 bytes
    uint8_t state;              // 1 byte (bitflags)
    uint8_t matched;            // 1 byte
    uint8_t indentation;        // 1 byte
    uint8_t column;             // 1 byte
    uint8_t fence_delim_len;    // 1 byte
    bool simulate;              // 1 byte
};

// Serialize to byte buffer:
unsigned serialize(Scanner *s, char *buffer) {
    buffer[0] = s->state;       // 1 byte
    buffer[1] = s->matched;     // 1 byte
    buffer[2] = s->indentation; // 1 byte
    // ... more fields
    memcpy(&buffer[5], s->open_blocks, ...);  // Stack data
    return size;
}

// Later: deserialize to resume from exact state
// Tree-sitter handles this automatically for incremental edits
```

## Precedence Levels

```javascript
// CommonMark precedence hierarchy:
// (Higher number = higher precedence, wins in conflicts)

const PRECEDENCE_LEVEL_EMPHASIS = 1;
const PRECEDENCE_LEVEL_LINK = 10;
const PRECEDENCE_LEVEL_HTML = 100;

// Usage:
_emphasis_star: $ => prec.dynamic(1, seq(...)),
shortcut_link: $ => prec.dynamic(10, seq(...)),
_open_tag: $ => prec.dynamic(100, seq(...)),

// Example conflict:
// Text: "<tag> and *emphasis*"
// <tag> matches both EMPHASIS (as * in <tag>?) and HTML
// Precedence 100 > Precedence 1 → HTML wins
```

## Ten Critical Insights

1. **Block-inline split is fundamental** - Not a hack, but architectural necessity
2. **External scanner is unavoidable** - Grammar DSL too limited for markdown
3. **State matters** - Need to track context that grammar can't express
4. **Lookahead before committing** - Scanner checks for matching delimiters first
5. **Error tokens kill branches** - Efficient way to resolve ambiguity
6. **Context-specific rules eliminate conflicts** - Don't resolve, prevent
7. **Precedence is declarative** - Higher number wins
8. **Ranges for inline parsing are crucial** - Separates concerns completely
9. **State serialization enables incremental parsing** - Critical for editors
10. **Meta-tokens pass context** - Dummy tokens signal parser state to scanner

## For Org-Mode Implementation

### Critical (Copy from Markdown)
1. ✅ Dual-grammar architecture
2. ✅ External C scanner with state
3. ✅ Block stack for nesting
4. ✅ Context-specific inline rules
5. ✅ Error tokens for branch killing

### Adapt for Org
1. ⚡ Headline level tracking (1-9+)
2. ⚡ Drawer/property block structure
3. ⚡ Tags on headlines
4. ⚡ Keyword states (TODO, DONE, etc.)
5. ⚡ Special block types (#+BEGIN_QUOTE, etc.)

### Nice-to-Have
1. 💎 State serialization
2. 💎 Lookahead for emphasis matching
3. 💎 Meta-tokens for context

