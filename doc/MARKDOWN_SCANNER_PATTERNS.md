# Markdown Scanner Patterns for Org-Mode

**Source**: `/home/user/org-ts-mode.el/doc/tree-sitter-markdown-split_parser/tree-sitter-markdown-inline/src/scanner.c`
**Date**: 2025-11-13
**Phase**: Phase 2 - Scanner Rearchitecture
**Purpose**: Document patterns from markdown scanner to adopt for org-mode

---

## Overview

The tree-sitter-markdown scanner provides proven patterns for implementing emphasis scanning with lookahead. While markdown's emphasis rules are more complex than org-mode's, several implementation patterns are directly applicable.

---

## Key Patterns to Adopt

### Pattern 1: Scanner State Structure

**Markdown implementation** (lines 58-67):
```c
typedef struct {
    // Parser state flags
    uint8_t state;
    uint8_t code_span_delimiter_length;
    uint8_t latex_span_delimiter_length;
    // The number of characters remaining in the current emphasis delimiter run
    uint8_t num_emphasis_delimiters_left;
} Scanner;
```

**Org-mode adaptation**:
```c
typedef struct {
    // State flags (for emphasis delimiter type tracking)
    uint8_t state;

    // Active delimiter tracking
    char active_delimiter;  // Current delimiter being scanned (*, /, _, +, ~, =)

    // Delimiter stack for nesting prevention
    uint8_t delimiter_stack[MAX_NEST_DEPTH];  // Stack of open delimiters
    uint8_t stack_depth;                      // Current stack depth

    // Preserve existing tag scanning state
    // (existing tag-related fields)
} Scanner;
```

**Why adopt**: Clean state structure that's easy to serialize/deserialize.

---

### Pattern 2: Serialization/Deserialization

**Markdown implementation** (lines 69-93):
```c
// Write the whole state of a Scanner to a byte buffer
static unsigned serialize(Scanner *s, char *buffer) {
    unsigned size = 0;
    buffer[size++] = (char)s->state;
    buffer[size++] = (char)s->code_span_delimiter_length;
    buffer[size++] = (char)s->latex_span_delimiter_length;
    buffer[size++] = (char)s->num_emphasis_delimiters_left;
    return size;
}

// Read the whole state of a Scanner from a byte buffer
static void deserialize(Scanner *s, const char *buffer, unsigned length) {
    s->state = 0;
    s->code_span_delimiter_length = 0;
    s->latex_span_delimiter_length = 0;
    s->num_emphasis_delimiters_left = 0;
    if (length > 0) {
        size_t size = 0;
        s->state = (uint8_t)buffer[size++];
        s->code_span_delimiter_length = (uint8_t)buffer[size++];
        s->latex_span_delimiter_length = (uint8_t)buffer[size++];
        s->num_emphasis_delimiters_left = (uint8_t)buffer[size++];
    }
}
```

**Org-mode adaptation**:
```c
static unsigned serialize(Scanner *s, char *buffer) {
    unsigned size = 0;
    buffer[size++] = (char)s->state;
    buffer[size++] = (char)s->active_delimiter;
    buffer[size++] = (char)s->stack_depth;
    // Serialize delimiter stack
    for (int i = 0; i < s->stack_depth && i < MAX_NEST_DEPTH; i++) {
        buffer[size++] = (char)s->delimiter_stack[i];
    }
    return size;
}

static void deserialize(Scanner *s, const char *buffer, unsigned length) {
    // Initialize to clean state
    s->state = 0;
    s->active_delimiter = 0;
    s->stack_depth = 0;
    memset(s->delimiter_stack, 0, MAX_NEST_DEPTH);

    if (length > 0) {
        size_t size = 0;
        s->state = (uint8_t)buffer[size++];
        s->active_delimiter = (char)buffer[size++];
        s->stack_depth = (uint8_t)buffer[size++];

        // Deserialize delimiter stack
        for (int i = 0; i < s->stack_depth && i < MAX_NEST_DEPTH && size < length; i++) {
            s->delimiter_stack[i] = (uint8_t)buffer[size++];
        }
    }
}
```

**Why adopt**: Simple byte-array serialization is fast and bounded. Critical for incremental parsing.

---

### Pattern 3: Lookahead Scanning for Opaque Content

**Markdown implementation** (lines 95-137):
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
    if (level == *delimiter_length && valid_symbols[close_token]) {
        *delimiter_length = 0;
        lexer->result_symbol = close_token;
        return true;
    }
    if (valid_symbols[open_token]) {
        // Parse ahead to check if there is a closing delimiter
        size_t close_level = 0;
        while (!lexer->eof(lexer)) {
            if (lexer->lookahead == delimiter) {
                close_level++;
            } else {
                if (close_level == level) {
                    // Found a matching delimiter
                    break;
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
        if (valid_symbols[UNCLOSED_SPAN]) {
            lexer->result_symbol = UNCLOSED_SPAN;
            return true;
        }
    }
    return false;
}
```

**Org-mode adaptation** (for code/verbatim):
```c
static bool scan_code_or_verbatim(Scanner *s, TSLexer *lexer,
                                   const bool *valid_symbols,
                                   char delimiter) {
    // 1. Validate opening boundary (PRE + no whitespace after)
    if (!validate_opening_boundary(lexer, delimiter)) {
        return false;
    }

    // 2. Look ahead to find closing delimiter
    lexer->mark_end(lexer);
    while (!lexer->eof(lexer) && lexer->lookahead != '\n') {
        if (lexer->lookahead == delimiter) {
            // Check closing boundary (no whitespace before + POST)
            if (validate_closing_boundary(lexer, delimiter)) {
                // Found valid closing
                lexer->result_symbol = get_token_type(delimiter);
                return true;
            }
        }
        lexer->advance(lexer, false);
    }

    // No valid closing found
    return false;
}
```

**Why adopt**: Lookahead pattern works well for org-mode's opaque content (code/verbatim). Key adaptation: org emphasis cannot span lines, so we stop at `\n`.

---

### Pattern 4: Character Classification

**Markdown implementation** (lines 28-32):
```c
// Determines if a character is punctuation as defined by the markdown spec.
static bool is_punctuation(int32_t chr) {
    return (chr >= '!' && chr <= '/') || (chr >= ':' && chr <= '@') ||
           (chr >= '[' && chr <= '`') || (chr >= '{' && chr <= '~');
}
```

**Org-mode adaptation**:
```c
// PRE characters: whitespace, -, (, {, ', ", or beginning of line
static bool is_pre_char(int32_t chr) {
    return chr == ' ' || chr == '\t' || chr == '\n' ||
           chr == '-' || chr == '(' || chr == '{' ||
           chr == '\'' || chr == '"';
}

// POST characters: whitespace, -, ., ,, ;, :, !, ?, ', ), }, [, ", \, or end of line
static bool is_post_char(int32_t chr) {
    return chr == ' ' || chr == '\t' || chr == '\n' ||
           chr == '-' || chr == '.' || chr == ',' ||
           chr == ';' || chr == ':' || chr == '!' ||
           chr == '?' || chr == '\'' || chr == ')' ||
           chr == '}' || chr == '[' || chr == '"' ||
           chr == '\\';
}

static bool is_whitespace(int32_t chr) {
    return chr == ' ' || chr == '\t' || chr == '\n';
}

static bool is_emphasis_marker(int32_t chr) {
    return chr == '*' || chr == '/' || chr == '_' ||
           chr == '+' || chr == '~' || chr == '=';
}
```

**Why adopt**: Simple, fast character classification functions are essential for boundary validation. Org-mode's character sets are explicit and well-defined.

---

### Pattern 5: Context-Aware Scanning via valid_symbols

**Markdown implementation** (lines 183-211):
```c
if (valid_symbols[EMPHASIS_OPEN_STAR] ||
    valid_symbols[EMPHASIS_CLOSE_STAR]) {
    // ... decision logic based on context ...

    // Look ahead to next symbol
    bool next_symbol_whitespace =
        line_end || lexer->lookahead == ' ' || lexer->lookahead == '\t';
    bool next_symbol_punctuation = is_punctuation(lexer->lookahead);

    // Check what came before (via valid_symbols)
    if (valid_symbols[EMPHASIS_CLOSE_STAR] &&
        !valid_symbols[LAST_TOKEN_WHITESPACE] &&
        (!valid_symbols[LAST_TOKEN_PUNCTUATION] ||
         next_symbol_punctuation || next_symbol_whitespace)) {
        // Closing delimiter
        lexer->result_symbol = EMPHASIS_CLOSE_STAR;
        return true;
    }
    if (!next_symbol_whitespace && (!next_symbol_punctuation ||
                                    valid_symbols[LAST_TOKEN_PUNCTUATION] ||
                                    valid_symbols[LAST_TOKEN_WHITESPACE])) {
        // Opening delimiter
        lexer->result_symbol = EMPHASIS_OPEN_STAR;
        return true;
    }
}
```

**Org-mode adaptation**:
```c
// Simpler for org-mode: just check PRE/POST explicitly
static bool scan_emphasis_delimiter(Scanner *s, TSLexer *lexer,
                                     const bool *valid_symbols,
                                     char delimiter) {
    // Check if we can open or close this delimiter type
    TokenType open_token = get_open_token(delimiter);
    TokenType close_token = get_close_token(delimiter);

    // Try closing first (precedence)
    if (valid_symbols[close_token]) {
        // We're potentially closing - validate closing boundary
        if (validate_closing_boundary(lexer, delimiter)) {
            lexer->result_symbol = close_token;
            pop_delimiter_stack(s, delimiter);
            return true;
        }
    }

    // Try opening
    if (valid_symbols[open_token]) {
        // Check if this delimiter is already on stack (prevent nesting same)
        if (delimiter_on_stack(s, delimiter)) {
            return false;  // Cannot nest same delimiter
        }

        // Validate opening boundary
        if (validate_opening_boundary(lexer, delimiter)) {
            // Look ahead to ensure closing delimiter exists
            if (find_closing_delimiter(lexer, delimiter)) {
                lexer->result_symbol = open_token;
                push_delimiter_stack(s, delimiter);
                return true;
            }
        }
    }

    return false;
}
```

**Why adopt**: `valid_symbols` array tells us what the grammar expects, which guides our scanning decisions. Org-mode's explicit PRE/POST rules make this simpler than markdown's complex logic.

---

## Patterns **NOT** to Adopt

### Pattern 1: Delimiter Runs

**Markdown** (lines 176-187):
```c
// Count the number of stars
uint8_t star_count = 1;
while (lexer->lookahead == '*') {
    star_count++;
    lexer->advance(lexer, false);
}
// ... handle multiple delimiters
```

**Org-mode**: **Do NOT adopt**. Org-mode uses single delimiters only: `*bold*`, not `**bold**`.

---

### Pattern 2: Complex Precedence Logic

**Markdown** (lines 195-210):
```c
// Complex logic based on whitespace, punctuation, and context
if (valid_symbols[EMPHASIS_CLOSE_STAR] &&
    !valid_symbols[LAST_TOKEN_WHITESPACE] &&
    (!valid_symbols[LAST_TOKEN_PUNCTUATION] ||
     next_symbol_punctuation || next_symbol_whitespace)) {
    // Closing takes precedence
}
```

**Org-mode**: **Simplify**. Use explicit PRE/POST character checking instead of complex precedence logic.

---

### Pattern 3: Separate Tokens for Opening/Closing

**Markdown** (lines 15-18, 153-213):
```c
EMPHASIS_OPEN_STAR,
EMPHASIS_OPEN_UNDERSCORE,
EMPHASIS_CLOSE_STAR,
EMPHASIS_CLOSE_UNDERSCORE,
```

**Org-mode**: **Consider carefully**. We might not need separate open/close tokens if we handle emphasis entirely in the grammar. Evaluate whether scanner should emit open/close tokens or just validate boundaries.

**Decision needed**: Do we want:
- **Option A**: Scanner validates boundaries, grammar handles structure (current approach)
- **Option B**: Scanner emits EMPHASIS_OPEN/CLOSE tokens, grammar uses them

**Recommendation**: Start with Option A (simpler), move to Option B if needed.

---

## Implementation Roadmap

Based on these patterns, here's the recommended implementation order:

### Phase 1: Foundation (Step 3.1)
1. Implement character classification functions:
   - `is_pre_char()`
   - `is_post_char()`
   - `is_whitespace()`
   - `is_emphasis_marker()`

2. Implement Scanner state structure:
   - Add delimiter stack
   - Add active delimiter tracking
   - Preserve existing tag state

3. Implement serialization:
   - `serialize()` - save state to buffer
   - `deserialize()` - restore state from buffer

### Phase 2: Boundary Validation (Step 3.2)
1. Implement `validate_opening_boundary()`:
   - Check PRE character
   - Check no whitespace after opening marker
   - Return true if valid

2. Implement `validate_closing_boundary()`:
   - Check no whitespace before closing marker
   - Check POST character
   - Return true if valid

### Phase 3: Lookahead Scanning (Step 3.3)
1. Implement `find_closing_delimiter()`:
   - Scan ahead to find matching delimiter
   - Stop at line end (org emphasis is line-scoped)
   - Validate closing boundary at each candidate
   - Return true if valid closing found

### Phase 4: Emphasis Scanning (Step 3.4)
1. Implement `scan_emphasis_delimiter()`:
   - Use valid_symbols to check context
   - Try closing first (precedence)
   - Try opening if closing fails
   - Check delimiter stack for same-delimiter nesting
   - Use lookahead to verify closing exists

2. Implement per-delimiter handlers:
   - `scan_bold()` - handle `*`
   - `scan_italic()` - handle `/`
   - `scan_underline()` - handle `_`
   - `scan_strike()` - handle `+`
   - `scan_code()` - handle `~` (opaque content)
   - `scan_verbatim()` - handle `=` (opaque content)

### Phase 5: Integration (Step 3.5)
1. Wire scanner to main scan function
2. Handle tag scanning (preserve existing)
3. Test with corpus

---

## Key Differences: Markdown vs Org-Mode

| Aspect | Markdown | Org-Mode |
|--------|----------|----------|
| **Delimiter runs** | `**bold**`, `***` | Single delimiter only: `*bold*` |
| **PRE/POST rules** | Complex flanking rules | Explicit character sets |
| **Whitespace** | Context-dependent | Simple: no whitespace at CONTENTS edges |
| **Line spanning** | Can span lines | Cannot span lines |
| **Nesting** | Based on delimiter count | Same marker cannot nest |
| **Complexity** | High (flanking, precedence) | Low (explicit rules) |

**Implication**: Org-mode scanner will be **simpler** than markdown's, but we still benefit from their proven patterns (state management, lookahead, serialization).

---

## Testing Strategy

Adopt markdown's testing approach:

1. **Character classification tests**: Test each PRE/POST character
2. **Boundary validation tests**: Test whitespace rules
3. **Lookahead tests**: Test finding closing delimiters
4. **Nesting tests**: Test same-delimiter prevention
5. **Integration tests**: Test complete emphasis patterns

---

## References

- **Markdown scanner**: `tree-sitter-markdown-inline/src/scanner.c`
- **Org emphasis rules**: `doc/EMPHASIS_RULES_REFERENCE.md`
- **Tree-sitter scanner API**: https://tree-sitter.github.io/tree-sitter/creating-parsers#external-scanners

---

## Next Steps

1. **Create SCANNER_ARCHITECTURE.md** - Design our scanner architecture using these patterns
2. **Implement character classification** - Start with simple functions
3. **Implement boundary validation** - Use PRE/POST character sets
4. **Implement lookahead** - Adapt markdown's pattern for org-mode
5. **Test systematically** - Create comprehensive test corpus

---

**Conclusion**: The markdown scanner provides excellent patterns for state management, serialization, and lookahead scanning. We'll adopt these patterns while simplifying the logic to match org-mode's explicit emphasis rules.
