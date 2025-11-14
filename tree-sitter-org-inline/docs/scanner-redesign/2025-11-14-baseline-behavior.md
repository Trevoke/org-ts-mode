# Scanner Baseline Behavior (Pre-Phase 2)

## State Structure

```c
typedef struct {
    char delimiter_stack[MAX_EMPHASIS_DEPTH];  // Tracks open delimiters
    uint8_t stack_depth;                        // Current nesting depth
    uint8_t state_flags;                        // State flags (currently unused)
    uint8_t padding[2];                         // Alignment
} Scanner;  // 20 bytes total
```

## Nesting Control Mechanism

- Scanner maintains `delimiter_stack` array (16 bytes, max 16 delimiters)
- When scanning delimiter, checks if same delimiter on stack via `is_delimiter_on_stack()`
- If on stack: only allows CLOSE token
- If not on stack: only allows OPEN token
- Result: Same-delimiter nesting prevented at scanner level

### Stack Functions

- `is_delimiter_on_stack()` - Check if delimiter is in stack
- `push_delimiter()` - Add delimiter to stack when OPEN emitted
- `pop_delimiter()` - Remove delimiter from stack when CLOSE emitted

## Boundary Validation

### PRE Boundary (before opening marker)

Valid: `whitespace | - | ( | { | ' | " | BOL`

```c
static inline bool is_pre_char(int32_t c, bool at_line_start) {
    if (at_line_start) return true;
    return c == ' '  || c == '\t' || c == '\n' ||
           c == '-'  || c == '('  || c == '{' ||
           c == '\'' || c == '"';
}
```

### POST Boundary (after closing marker)

Valid: `whitespace | - | . | , | ; | : | ! | ? | ' | ) | } | [ | " | \ | EOL`

```c
static inline bool is_post_char(int32_t c, bool at_line_end) {
    if (at_line_end) return true;
    return c == ' '  || c == '\t' || c == '\n' ||
           c == '-'  || c == '.'  || c == ',' ||
           c == ';'  || c == ':'  || c == '!' ||
           c == '?'  || c == '\'' || c == ')' ||
           c == '}'  || c == '['  || c == '"' ||
           c == '\\';
}
```

### CONTENTS Boundary

- No leading whitespace allowed after opening marker
- No trailing whitespace allowed before closing marker

## Serialization

The scanner state is serialized to support incremental parsing:

- **Version**: 1 byte (0x01)
- **Stack depth**: 1 byte (0-16)
- **State flags**: 1 byte (currently unused)
- **Padding**: 1 byte
- **Delimiter stack**: 16 bytes
- **Total**: 20 bytes

## Test Baseline

- **349 total tests**
- **284 passing** (81.4%)
- **65 failing** (18.6%)

Failures are due to:
- Known tree-sitter test framework limitations
- Spec ambiguities in org-syntax.md
- Edge cases in boundary validation

## Current Scanner Workflow

1. **Check PRE boundary**: Validate character before delimiter
2. **Check delimiter on stack**: Determine if this could be OPEN or CLOSE
3. **Consume delimiter**: Advance lexer past delimiter character
4. **Check POST boundary**: Validate character after delimiter
5. **Emit token**: OPEN (push to stack) or CLOSE (pop from stack)
6. **Serialize state**: Save delimiter stack for incremental parsing

## Limitations of Current Design

### Same-Delimiter Nesting

The delimiter stack prevents same-delimiter nesting:
- `*bold *nested* bold*` - The inner `*` delimiters are prevented by scanner
- Scanner makes this decision, grammar cannot override
- This is hardcoded in scanner logic

### Grammar Control

The grammar cannot control nesting because:
- Scanner decides OPEN vs CLOSE based on stack state
- Grammar only sees the final token (OPEN or CLOSE)
- No mechanism for grammar to override scanner decisions

### State Size

20 bytes of state must be serialized for every parse state:
- 16 bytes for delimiter stack (mostly unused in practice)
- Most documents use 1-3 levels of nesting, not 16
- Inefficient for incremental parsing

## Debug Output

The scanner includes extensive debug logging (enabled in current build):
- `DEBUG DESERIALIZE`: State deserialization messages
- `MAIN_SCAN`: Main scanner entry point
- `DEBUG: scan_emphasis`: Emphasis scanning details
- `DEBUG SERIALIZE`: State serialization messages

This produces verbose output during test runs but helps understand scanner behavior.

## References

- **org-syntax.md lines 1744-1777**: Emphasis specification
- **src/scanner.c lines 113-143**: Scanner struct definition
- **src/scanner.c lines 287-375**: Stack management functions
- **src/scanner.c lines 204-239**: Boundary validation functions
