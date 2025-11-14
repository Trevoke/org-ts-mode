# Scanner Architecture Design

**Phase**: Phase 2 - Scanner Rearchitecture
**Date**: 2025-11-13
**Status**: Design Document
**Purpose**: Complete technical design for org-mode inline scanner

---

## Executive Summary

This document defines the architecture for the org-mode inline scanner that will validate emphasis boundaries according to org-syntax.md rules. The design prioritizes **clarity, correctness, and maintainability** over performance optimization (which comes later).

**Key Design Principles**:
1. **Correctness first**: Implement org-syntax.md rules exactly
2. **Clear code**: Obvious is better than clever
3. **Minimal state**: Only track what's necessary
4. **Bounded resources**: Fixed limits, no dynamic allocation in hot paths
5. **Testable**: Each function has clear inputs/outputs

---

## Table of Contents

1. [Data Structures](#data-structures)
2. [Token Types](#token-types)
3. [Character Classification](#character-classification)
4. [Boundary Validation](#boundary-validation)
5. [Lookahead Scanning](#lookahead-scanning)
6. [State Management](#state-management)
7. [Serialization](#serialization)
8. [Main Scan Function](#main-scan-function)
9. [State Machine](#state-machine)
10. [Error Handling](#error-handling)
11. [Performance Considerations](#performance-considerations)

---

## 1. Data Structures

### 1.1 Scanner State

```c
/**
 * Scanner state structure
 *
 * Design rationale:
 * - Keep state minimal (only what's needed for incremental parsing)
 * - Use fixed-size arrays (no dynamic allocation)
 * - Preserve existing tag scanning (currently stateless)
 */
typedef struct {
    // Delimiter stack for nesting prevention
    // Stores which delimiters are currently open
    // Example: ['*', '/', '_'] means bold contains italic contains underline
    char delimiter_stack[MAX_EMPHASIS_DEPTH];

    // Current depth of delimiter stack
    // Valid range: 0 to MAX_EMPHASIS_DEPTH
    uint8_t stack_depth;

    // State flags (for future extensions)
    // Currently unused, but reserved for:
    // - Tracking multi-character sequences
    // - Caching boundary validation results
    uint8_t state_flags;

    // Padding to align to 4-byte boundary (optional, for performance)
    uint8_t padding;

} Scanner;

// Maximum nesting depth for emphasis
// Rationale: 16 levels is more than enough for any realistic document
// org-syntax.md doesn't specify a limit, but we need bounded state
#define MAX_EMPHASIS_DEPTH 16

// State flags (currently unused, but defined for future)
#define STATE_FLAG_NONE 0x00
// Reserved for future use:
// #define STATE_FLAG_IN_CODE 0x01
// #define STATE_FLAG_IN_VERBATIM 0x02
```

**Design decisions**:
- **Fixed-size array** instead of dynamic allocation (performance, simplicity)
- **Small footprint** (20 bytes) for efficient serialization
- **No pointers** to avoid serialization complexity
- **Preserve existing tag state** (currently none, but structure allows extension)

### 1.2 Context Structure (Temporary, Not Serialized)

```c
/**
 * Scanning context (stack-allocated, not serialized)
 *
 * Passed to helper functions to avoid global state
 */
typedef struct {
    Scanner *scanner;           // Pointer to scanner state
    TSLexer *lexer;            // Tree-sitter lexer
    const bool *valid_symbols;  // What grammar expects
} ScanContext;
```

**Rationale**: Group related data to reduce function parameter count and make code cleaner.

---

## 2. Token Types

### 2.1 Current Token (Preserve)

```c
enum TokenType {
    TAGS,  // Existing: :tag1:tag2:
    // Future tokens will be added here
};
```

### 2.2 Future Tokens (Phase 2 Decision Needed)

**Option A**: Keep current approach (scanner validates, grammar parses)
```c
enum TokenType {
    TAGS,
    // No additional tokens needed
    // Grammar handles emphasis structure entirely
};
```

**Option B**: Add explicit emphasis tokens (like markdown)
```c
enum TokenType {
    TAGS,
    EMPHASIS_OPEN,   // Valid opening delimiter
    EMPHASIS_CLOSE,  // Valid closing delimiter
};
```

**Decision**: **Start with Option A** (simpler). The scanner will validate boundaries in-place rather than emitting separate tokens. If this proves insufficient, we can migrate to Option B.

**Rationale**:
- Simpler integration with existing grammar
- Less coordination between scanner and grammar
- Easier to test (validate, don't emit)
- Can always add tokens later if needed

---

## 3. Character Classification

### 3.1 Character Classification Functions

```c
/**
 * Check if character is valid PRE (before opening marker)
 *
 * PRE: whitespace, -, (, {, ', ", or beginning of line
 * Source: org-syntax.md lines 1756-1757
 *
 * @param c Character to check (int32_t for unicode support)
 * @param at_line_start true if at beginning of line
 * @return true if valid PRE character
 */
static inline bool is_pre_char(int32_t c, bool at_line_start) {
    if (at_line_start) {
        return true;
    }

    return c == ' '  || c == '\t' || c == '\n' ||
           c == '-'  || c == '('  || c == '{' ||
           c == '\'' || c == '"';
}

/**
 * Check if character is valid POST (after closing marker)
 *
 * POST: whitespace, -, ., ,, ;, :, !, ?, ', ), }, [, ", \, or end of line
 * Source: org-syntax.md lines 1768-1769
 *
 * @param c Character to check
 * @param at_line_end true if at end of line
 * @return true if valid POST character
 */
static inline bool is_post_char(int32_t c, bool at_line_end) {
    if (at_line_end) {
        return true;
    }

    return c == ' '  || c == '\t' || c == '\n' ||
           c == '-'  || c == '.'  || c == ',' ||
           c == ';'  || c == ':'  || c == '!' ||
           c == '?'  || c == '\'' || c == ')' ||
           c == '}'  || c == '['  || c == '"' ||
           c == '\\';
}

/**
 * Check if character is whitespace
 *
 * @param c Character to check
 * @return true if whitespace (space, tab, newline)
 */
static inline bool is_whitespace(int32_t c) {
    return c == ' ' || c == '\t' || c == '\n';
}

/**
 * Check if character is an emphasis marker
 *
 * @param c Character to check
 * @return true if *, /, _, +, ~, or =
 */
static inline bool is_emphasis_marker(int32_t c) {
    return c == '*' || c == '/' || c == '_' ||
           c == '+' || c == '~' || c == '=';
}

/**
 * Check if at line boundary
 *
 * @param lexer Tree-sitter lexer
 * @return true if at beginning or end of line, or EOF
 */
static inline bool at_line_boundary(TSLexer *lexer) {
    return lexer->lookahead == '\n' ||
           lexer->lookahead == '\r' ||
           lexer->eof(lexer);
}
```

**Design decisions**:
- **inline** for performance (these are called frequently)
- **Explicit line boundary handling** (clearer than implicit checks)
- **Unicode support** via int32_t (tree-sitter standard)
- **Source attribution** in comments (traceability to spec)

### 3.2 Character Classification Tests

```c
// Unit tests to add (in test corpus)
// Test is_pre_char() with each valid PRE character
// Test is_post_char() with each valid POST character
// Test is_whitespace() with space, tab, newline
// Test is_emphasis_marker() with all 6 markers
// Test at_line_boundary() with newline, CR, EOF
```

---

## 4. Boundary Validation

### 4.1 Opening Boundary Validation

```c
/**
 * Validate opening boundary for emphasis
 *
 * Rules (org-syntax.md):
 * 1. Character before marker must be valid PRE
 * 2. Character after marker must NOT be whitespace (CONTENTS boundary)
 * 3. Marker must not be at EOF
 *
 * Precondition: lexer is positioned BEFORE the opening marker
 * Postcondition: lexer position unchanged
 *
 * @param ctx Scanning context
 * @param marker The emphasis marker character (*, /, _, +, ~, =)
 * @param prev_char Character immediately before marker (pass from caller)
 * @param at_line_start true if marker is at beginning of line
 * @return true if valid opening boundary
 */
static bool validate_opening_boundary(
    ScanContext *ctx,
    char marker,
    int32_t prev_char,
    bool at_line_start
) {
    // Save lexer position for restoration
    TSLexer *lexer = ctx->lexer;

    // Rule 1: Check PRE character
    if (!is_pre_char(prev_char, at_line_start)) {
        return false;
    }

    // Rule 2: Look at character after marker (need to peek ahead)
    // We'll need to advance past marker temporarily
    // (This will be called from a lookahead context, so position is restored)
    lexer->advance(lexer, false);  // Move past marker

    if (lexer->eof(lexer)) {
        return false;  // Marker at EOF is invalid
    }

    // Character immediately after marker must not be whitespace
    if (is_whitespace(lexer->lookahead)) {
        return false;  // Invalid: whitespace after opening marker
    }

    // Valid opening boundary
    return true;
}
```

### 4.2 Closing Boundary Validation

```c
/**
 * Validate closing boundary for emphasis
 *
 * Rules (org-syntax.md):
 * 1. Character before marker must NOT be whitespace (CONTENTS boundary)
 * 2. Character after marker must be valid POST
 *
 * Precondition: lexer is positioned AT the closing marker candidate
 * Postcondition: lexer position unchanged (caller handles advance)
 *
 * @param ctx Scanning context
 * @param marker The emphasis marker character
 * @param prev_char Character immediately before marker
 * @return true if valid closing boundary
 */
static bool validate_closing_boundary(
    ScanContext *ctx,
    char marker,
    int32_t prev_char
) {
    TSLexer *lexer = ctx->lexer;

    // Rule 1: Character before marker must not be whitespace
    if (is_whitespace(prev_char)) {
        return false;  // Invalid: whitespace before closing marker
    }

    // Rule 2: Look at character after marker
    lexer->advance(lexer, false);  // Move past marker

    bool at_line_end = at_line_boundary(lexer);

    if (!is_post_char(lexer->lookahead, at_line_end)) {
        return false;  // Invalid POST character
    }

    // Valid closing boundary
    return true;
}
```

**Design decisions**:
- **Explicit preconditions/postconditions** (clear contracts)
- **Pass prev_char** to avoid repeated lookbehind
- **Temporary lexer advance** (caller restores position)
- **Clear failure reasons** via early returns

---

## 5. Lookahead Scanning

### 5.1 Find Closing Delimiter

```c
/**
 * Look ahead to find valid closing delimiter
 *
 * Scans forward to find a matching marker with valid closing boundary.
 * Stops at line end (org emphasis cannot span lines).
 *
 * Precondition: lexer positioned AFTER opening marker
 * Postcondition: if successful, lexer at closing marker; else, position undefined
 *
 * @param ctx Scanning context
 * @param marker Delimiter to find
 * @return true if valid closing delimiter found
 */
static bool find_closing_delimiter(ScanContext *ctx, char marker) {
    TSLexer *lexer = ctx->lexer;
    int32_t prev_char = 0;
    bool found = false;

    // Track previous character for boundary validation
    // Start with whatever came after opening marker
    if (!lexer->eof(lexer)) {
        prev_char = lexer->lookahead;
    }

    // Scan forward looking for closing marker
    while (!lexer->eof(lexer)) {
        int32_t current = lexer->lookahead;

        // Stop at line end (emphasis cannot span lines)
        if (current == '\n' || current == '\r') {
            break;
        }

        // Found potential closing marker
        if (current == marker) {
            // Validate closing boundary
            if (validate_closing_boundary(ctx, marker, prev_char)) {
                found = true;
                break;
            }
            // Invalid closing boundary, keep looking
        }

        // Track previous character for next iteration
        prev_char = current;
        lexer->advance(lexer, false);
    }

    return found;
}
```

**Design decisions**:
- **Track prev_char** to avoid lookbehind
- **Line-scoped** (stop at newline)
- **Early termination** on first valid closing
- **Clear success/failure** return value

### 5.2 Lookahead Pattern (for grammar integration)

```c
/**
 * Check if emphasis is valid (used by grammar)
 *
 * This function is called when the grammar encounters a potential
 * emphasis marker. It validates that:
 * 1. Opening boundary is valid
 * 2. Closing delimiter exists with valid boundary
 * 3. Delimiter is not already on stack (no same-marker nesting)
 *
 * This is a "pure" validation function - it doesn't modify scanner state
 * or emit tokens. It just answers: "Is this valid emphasis?"
 *
 * @param ctx Scanning context
 * @param marker The potential emphasis marker
 * @param prev_char Character before marker
 * @param at_line_start true if at beginning of line
 * @return true if valid emphasis pattern
 */
static bool is_valid_emphasis(
    ScanContext *ctx,
    char marker,
    int32_t prev_char,
    bool at_line_start
) {
    // Save current position
    uint32_t saved_pos = ctx->lexer->lookahead;

    // Check 1: Valid opening boundary
    if (!validate_opening_boundary(ctx, marker, prev_char, at_line_start)) {
        return false;
    }

    // Check 2: Delimiter not already on stack (no same-marker nesting)
    if (is_delimiter_on_stack(ctx->scanner, marker)) {
        return false;
    }

    // Check 3: Valid closing delimiter exists
    bool has_closing = find_closing_delimiter(ctx, marker);

    // Note: lexer position is now at closing marker (or EOF/newline)
    // Caller will handle restoring position if needed

    return has_closing;
}
```

**Usage**: The grammar can call this during parsing to validate emphasis markers before committing to the emphasis rule.

---

## 6. State Management

### 6.1 Delimiter Stack Operations

```c
/**
 * Check if delimiter is on the stack
 *
 * @param scanner Scanner state
 * @param delimiter Delimiter to check
 * @return true if delimiter is currently open
 */
static bool is_delimiter_on_stack(Scanner *scanner, char delimiter) {
    for (uint8_t i = 0; i < scanner->stack_depth; i++) {
        if (scanner->delimiter_stack[i] == delimiter) {
            return true;
        }
    }
    return false;
}

/**
 * Push delimiter onto stack
 *
 * @param scanner Scanner state
 * @param delimiter Delimiter to push
 * @return true if successful, false if stack full
 */
static bool push_delimiter(Scanner *scanner, char delimiter) {
    if (scanner->stack_depth >= MAX_EMPHASIS_DEPTH) {
        return false;  // Stack overflow
    }

    scanner->delimiter_stack[scanner->stack_depth] = delimiter;
    scanner->stack_depth++;
    return true;
}

/**
 * Pop delimiter from stack
 *
 * @param scanner Scanner state
 * @param delimiter Expected delimiter (for validation)
 * @return true if successful and matches, false otherwise
 */
static bool pop_delimiter(Scanner *scanner, char delimiter) {
    if (scanner->stack_depth == 0) {
        return false;  // Stack underflow
    }

    // Check that top of stack matches expected delimiter
    uint8_t top_idx = scanner->stack_depth - 1;
    if (scanner->delimiter_stack[top_idx] != delimiter) {
        return false;  // Mismatch (shouldn't happen with correct grammar)
    }

    scanner->stack_depth--;
    return true;
}

/**
 * Clear delimiter stack
 *
 * @param scanner Scanner state
 */
static void clear_delimiter_stack(Scanner *scanner) {
    scanner->stack_depth = 0;
    memset(scanner->delimiter_stack, 0, MAX_EMPHASIS_DEPTH);
}
```

**Design decisions**:
- **Simple linear search** (stack is small, <16 elements)
- **Validation in pop** (sanity check)
- **Bounds checking** (prevent overflow/underflow)
- **Clear on initialization** (defensive programming)

---

## 7. Serialization

### 7.1 Serialization Format

```c
/**
 * Serialization format (version 1)
 *
 * Byte layout:
 * [0]: Version (0x01)
 * [1]: Stack depth (0-MAX_EMPHASIS_DEPTH)
 * [2]: State flags
 * [3]: Padding (reserved)
 * [4-19]: Delimiter stack (16 bytes)
 *
 * Total: 20 bytes (fixed size for all states)
 */
#define SERIALIZATION_VERSION 0x01
#define SERIALIZATION_SIZE 20

/**
 * Serialize scanner state to buffer
 *
 * @param scanner Scanner state
 * @param buffer Output buffer (must be at least SERIALIZATION_SIZE bytes)
 * @return Number of bytes written
 */
static unsigned serialize(Scanner *scanner, char *buffer) {
    unsigned size = 0;

    // Byte 0: Version
    buffer[size++] = SERIALIZATION_VERSION;

    // Byte 1: Stack depth
    buffer[size++] = scanner->stack_depth;

    // Byte 2: State flags
    buffer[size++] = scanner->state_flags;

    // Byte 3: Padding
    buffer[size++] = 0;

    // Bytes 4-19: Delimiter stack (copy all 16 bytes)
    memcpy(buffer + size, scanner->delimiter_stack, MAX_EMPHASIS_DEPTH);
    size += MAX_EMPHASIS_DEPTH;

    return size;
}

/**
 * Deserialize scanner state from buffer
 *
 * @param scanner Scanner state to populate
 * @param buffer Input buffer
 * @param length Buffer length
 */
static void deserialize(Scanner *scanner, const char *buffer, unsigned length) {
    // Initialize to clean state
    scanner->stack_depth = 0;
    scanner->state_flags = STATE_FLAG_NONE;
    memset(scanner->delimiter_stack, 0, MAX_EMPHASIS_DEPTH);

    // Check minimum length and version
    if (length < 4) {
        return;  // Invalid buffer
    }

    uint8_t version = (uint8_t)buffer[0];
    if (version != SERIALIZATION_VERSION) {
        return;  // Version mismatch
    }

    // Read stack depth
    scanner->stack_depth = (uint8_t)buffer[1];
    if (scanner->stack_depth > MAX_EMPHASIS_DEPTH) {
        scanner->stack_depth = 0;  // Corrupted data
        return;
    }

    // Read state flags
    scanner->state_flags = (uint8_t)buffer[2];

    // Read delimiter stack
    if (length >= SERIALIZATION_SIZE) {
        memcpy(scanner->delimiter_stack, buffer + 4, MAX_EMPHASIS_DEPTH);
    }
}
```

**Design decisions**:
- **Fixed size** (20 bytes) for predictable memory usage
- **Version byte** for future compatibility
- **Validation** on deserialize (defensive)
- **Graceful degradation** on corruption (reset to clean state)

---

## 8. Main Scan Function

### 8.1 Entry Point

```c
/**
 * Main external scanner function
 *
 * Called by tree-sitter during parsing. Decides what to scan based on
 * what tokens the grammar marks as valid (valid_symbols array).
 *
 * Strategy:
 * 1. Check if TAGS token is valid -> scan for tags
 * 2. In future: check for emphasis tokens -> validate emphasis
 * 3. Return false if nothing to scan
 *
 * @param payload Scanner state (opaque pointer)
 * @param lexer Tree-sitter lexer
 * @param valid_symbols Array indicating which tokens grammar expects
 * @return true if token emitted, false otherwise
 */
bool tree_sitter_org_inline_external_scanner_scan(
    void *payload,
    TSLexer *lexer,
    const bool *valid_symbols
) {
    Scanner *scanner = (Scanner *)payload;

    // Create scanning context
    ScanContext ctx = {
        .scanner = scanner,
        .lexer = lexer,
        .valid_symbols = valid_symbols
    };

    // Priority 1: Tag scanning (preserve existing functionality)
    if (valid_symbols[TAGS]) {
        return scan_tags(&ctx);
    }

    // Future: Priority 2: Emphasis scanning
    // if (valid_symbols[EMPHASIS_OPEN] || valid_symbols[EMPHASIS_CLOSE]) {
    //     return scan_emphasis(&ctx);
    // }

    return false;
}
```

### 8.2 Tag Scanning (Preserved)

```c
/**
 * Scan tags (preserve existing functionality)
 *
 * Format: :tag1:tag2:tag3:
 * Tags contain only alphanumeric, _, @, #, %
 *
 * @param ctx Scanning context
 * @return true if tags found and emitted
 */
static bool scan_tags(ScanContext *ctx) {
    // (Existing implementation from current scanner.c)
    // ... keep current code ...
}
```

---

## 9. State Machine

### 9.1 Scanner State Machine Diagram

```
┌─────────────┐
│   START     │
│  (no state) │
└──────┬──────┘
       │
       ├──[encounter potential emphasis marker]──┐
       │                                          │
       ▼                                          ▼
┌──────────────────┐                    ┌─────────────────┐
│  VALIDATE        │                    │  SCAN TAGS      │
│  OPENING         │                    │  (existing)     │
│  BOUNDARY        │                    └────────┬────────┘
└────┬─────────────┘                             │
     │                                            │
     ├─[valid]─┐                                 │
     │         │                                  │
     │         ▼                                  ▼
     │    ┌────────────────┐                ┌─────────┐
     │    │  CHECK STACK   │                │  EMIT   │
     │    │  (no dup)      │                │  TAGS   │
     │    └───┬────────────┘                └────┬────┘
     │        │                                   │
     │        ├─[not on stack]─┐                 │
     │        │                 │                 │
     │        │                 ▼                 │
     │        │         ┌──────────────┐         │
     │        │         │  LOOKAHEAD   │         │
     │        │         │  FOR CLOSING │         │
     │        │         └──┬───────────┘         │
     │        │            │                      │
     │        │            ├─[found valid]─┐     │
     │        │            │               │     │
     │        │            │               ▼     │
     │        │            │       ┌──────────┐  │
     │        │            │       │  PUSH    │  │
     │        │            │       │  STACK   │  │
     │        │            │       └────┬─────┘  │
     │        │            │            │        │
     │        │            │            ▼        │
     │        │            │     ┌─────────────┐ │
     │        │            │     │  CONTINUE   │ │
     │        │            │     │  PARSING    │ │
     │        │            │     └──────┬──────┘ │
     │        │            │            │        │
     │        ├─[invalid]──┴────────────┴────────┴───────┐
     │        │                                           │
     ▼        ▼                                           ▼
┌──────────────────────────────────────────────────────────┐
│                   RETURN FALSE                           │
│             (let grammar handle as plain text)           │
└──────────────────────────────────────────────────────────┘
```

### 9.2 State Transitions

| State | Condition | Next State | Action |
|-------|-----------|------------|--------|
| START | TAGS valid | SCAN_TAGS | Scan tags |
| START | At emphasis marker | VALIDATE_OPEN | Check opening boundary |
| VALIDATE_OPEN | Invalid boundary | RETURN_FALSE | Let grammar handle |
| VALIDATE_OPEN | Valid boundary | CHECK_STACK | Check delimiter stack |
| CHECK_STACK | Already on stack | RETURN_FALSE | Prevent same-marker nesting |
| CHECK_STACK | Not on stack | LOOKAHEAD | Search for closing |
| LOOKAHEAD | Closing not found | RETURN_FALSE | Not valid emphasis |
| LOOKAHEAD | Closing found | PUSH_STACK | Add to delimiter stack |
| PUSH_STACK | Success | CONTINUE | Continue parsing |

---

## 10. Error Handling

### 10.1 Error Conditions

| Error | Detection | Handling | Recovery |
|-------|-----------|----------|----------|
| Stack overflow | `stack_depth >= MAX_EMPHASIS_DEPTH` | Return false from push | Grammar treats as plain text |
| Stack underflow | `stack_depth == 0` in pop | Return false from pop | Should never happen (grammar bug) |
| Invalid boundary | PRE/POST check fails | Return false from validate | Grammar treats as plain text |
| No closing delimiter | Lookahead reaches line end | Return false | Grammar treats as plain text |
| Serialization corruption | Version mismatch or invalid length | Reset to clean state | Parse from scratch for this chunk |

**Philosophy**: **Fail gracefully**. When in doubt, let the grammar treat it as plain text.

### 10.2 Defensive Programming

```c
// Example defensive checks
static bool push_delimiter(Scanner *scanner, char delimiter) {
    // Check preconditions
    if (scanner == NULL) return false;           // NULL guard
    if (scanner->stack_depth >= MAX_EMPHASIS_DEPTH) return false;  // Overflow guard
    if (!is_emphasis_marker(delimiter)) return false;  // Invalid delimiter guard

    // Perform operation
    scanner->delimiter_stack[scanner->stack_depth] = delimiter;
    scanner->stack_depth++;

    // Verify postconditions (in debug builds)
    assert(scanner->stack_depth <= MAX_EMPHASIS_DEPTH);

    return true;
}
```

---

## 11. Performance Considerations

### 11.1 Hot Paths

**Most frequently called functions**:
1. `is_pre_char()` - Called for every potential emphasis marker
2. `is_post_char()` - Called for every potential emphasis marker
3. `is_whitespace()` - Called multiple times per boundary validation
4. `find_closing_delimiter()` - Called for every opening delimiter candidate

**Optimization strategy**:
- Mark hot functions as `static inline`
- Keep hot functions simple (branch prediction friendly)
- Avoid function calls in hot paths where possible
- Use early returns to minimize work

### 11.2 Memory Usage

```
Scanner state: 20 bytes
- delimiter_stack: 16 bytes
- stack_depth: 1 byte
- state_flags: 1 byte
- padding: 2 bytes

Serialization: 20 bytes (fixed)

Per-document overhead: 20 bytes (excellent)
```

### 11.3 Time Complexity

| Operation | Best Case | Worst Case | Average |
|-----------|-----------|------------|---------|
| Boundary validation | O(1) | O(1) | O(1) |
| Stack operations | O(n) | O(n) | O(n) |
| Lookahead | O(1) | O(m) | O(m/2) |

Where:
- n = stack depth (max 16, typically 1-3)
- m = distance to line end (typically <80 characters)

**Expected**: O(m) per emphasis marker, where m is line length. For typical documents with emphasis every 50-100 characters, this is very fast.

### 11.4 Optimization Opportunities (Future)

**Phase 2**: Correctness first, don't optimize yet
**Phase 7**: Consider these optimizations:
1. Cache boundary validation results
2. Pre-compute character class lookup tables
3. Use SIMD for character classification (if needed)
4. Profile and optimize hot paths

---

## 12. Testing Strategy

### 12.1 Unit Testing

Test each function independently:

```c
// Character classification
test_is_pre_char_with_whitespace()
test_is_pre_char_with_punctuation()
test_is_pre_char_at_line_start()
test_is_pre_char_with_invalid()

test_is_post_char_with_whitespace()
test_is_post_char_with_punctuation()
test_is_post_char_at_line_end()
test_is_post_char_with_invalid()

// Boundary validation
test_validate_opening_valid()
test_validate_opening_invalid_pre()
test_validate_opening_invalid_whitespace()

test_validate_closing_valid()
test_validate_closing_invalid_pre()
test_validate_closing_invalid_post()

// Lookahead
test_find_closing_delimiter_found()
test_find_closing_delimiter_not_found()
test_find_closing_delimiter_line_end()

// Stack operations
test_push_pop_delimiter()
test_stack_overflow()
test_stack_underflow()
test_is_delimiter_on_stack()

// Serialization
test_serialize_deserialize_round_trip()
test_deserialize_corrupted_data()
test_deserialize_wrong_version()
```

### 12.2 Integration Testing

Test via tree-sitter test corpus (Step 4):
- Basic emphasis patterns
- Boundary validation (all PRE/POST characters)
- Nesting prevention
- Line boundary cases
- Invalid patterns

---

## 13. Implementation Checklist

### Phase 2 Step 3: Implement Core Scanner

- [ ] 3.1: Character classification functions
  - [ ] `is_pre_char()`
  - [ ] `is_post_char()`
  - [ ] `is_whitespace()`
  - [ ] `is_emphasis_marker()`
  - [ ] `at_line_boundary()`

- [ ] 3.2: Boundary validation functions
  - [ ] `validate_opening_boundary()`
  - [ ] `validate_closing_boundary()`

- [ ] 3.3: Lookahead scanning
  - [ ] `find_closing_delimiter()`
  - [ ] `is_valid_emphasis()` (wrapper)

- [ ] 3.4: State management
  - [ ] `is_delimiter_on_stack()`
  - [ ] `push_delimiter()`
  - [ ] `pop_delimiter()`
  - [ ] `clear_delimiter_stack()`

- [ ] 3.5: Serialization
  - [ ] `serialize()`
  - [ ] `deserialize()`

- [ ] 3.6: Main scan function
  - [ ] Update `tree_sitter_org_inline_external_scanner_scan()`
  - [ ] Preserve existing `scan_tags()`

- [ ] 3.7: Scanner lifecycle
  - [ ] Update `create()`
  - [ ] Update `destroy()`
  - [ ] Wire `serialize()`/`deserialize()`

---

## 14. Open Questions

### Q1: Should scanner emit tokens or just validate?

**Decision**: Start with validation-only (Option A). Scanner validates boundaries in-place, grammar handles structure. Can migrate to token emission (Option B) if needed.

**Rationale**: Simpler, less coordination, easier to test.

### Q2: How to handle emphasis inside links?

**Decision**: Grammar handles this via context-specific rules (from Phase 1). Scanner doesn't need to know about link context.

### Q3: Performance target?

**Decision**: Phase 2 focuses on correctness. Maintain existing speed (~7000+ bytes/ms). Optimize in Phase 7 if needed.

### Q4: What about superscript/subscript?

**Decision**: Deferred to Phase 5. Focus on 6 emphasis markers first.

---

## 15. Success Criteria

Phase 2 Step 2 (Design) is complete when:

✅ All data structures defined
✅ All function signatures documented
✅ All algorithms specified with pseudocode
✅ State machine documented
✅ Serialization format defined
✅ Testing strategy documented
✅ Implementation checklist created
✅ Design reviewed for completeness

---

## References

- **org-syntax.md**: Lines 1744-1777 (emphasis specification)
- **EMPHASIS_RULES_REFERENCE.md**: Detailed rules reference
- **MARKDOWN_SCANNER_PATTERNS.md**: Patterns from markdown
- **Current scanner.c**: Existing tag scanning implementation
- **Tree-sitter scanner API**: https://tree-sitter.github.io/tree-sitter/creating-parsers#external-scanners

---

## Revision History

| Version | Date | Author | Changes |
|---------|------|--------|---------|
| 1.0 | 2025-11-13 | Claude | Initial design |

---

**Status**: Design Complete ✅
**Next Step**: Step 3 - Implement Core Scanner
