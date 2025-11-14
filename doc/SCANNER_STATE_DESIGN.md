# Scanner State Design for Org-Mode Emphasis

## Markdown Scanner State Analysis

### State Structure
```c
typedef struct {
    uint8_t state;  // Bitflags for current state
    uint8_t code_span_delimiter_length;
    uint8_t latex_span_delimiter_length;
    uint8_t num_emphasis_delimiters_left;  // Key for emphasis!
} Scanner;
```

### State Flags
- `STATE_EMPHASIS_DELIMITER_IS_OPEN` (0x04): Current delimiter run is opening
- `STATE_EMPHASIS_DELIMITER_MOD_3` (0x03): Track modulo 3 for strong emphasis

### The Algorithm (parse_star)

**First time encountering delimiter run**:
1. Count all consecutive delimiters (`star_count`)
2. Analyze context (next char, previous token via `valid_symbols`)
3. Decide OPEN or CLOSE based on CommonMark rules
4. Emit token for FIRST delimiter
5. Store `num_emphasis_delimiters_left = star_count - 1`
6. Store decision in `STATE_EMPHASIS_DELIMITER_IS_OPEN`

**Subsequent calls (same delimiter run)**:
1. Check `if (num_emphasis_delimiters_left > 0)`
2. Use stored decision from flags
3. Emit same token type
4. Decrement counter

**Example: `**bold**`**:
```
Call 1: "**" → count=2 → decide OPEN → emit OPEN → left=1, IS_OPEN=true
Call 2: "*"  → left>0 → use IS_OPEN → emit OPEN → left=0
Call 3: "**" → count=2 → decide CLOSE → emit CLOSE → left=1, IS_OPEN=false
Call 4: "*"  → left>0 → use !IS_OPEN → emit CLOSE → left=0
```

## Org-Mode Requirements

### Key Differences from Markdown

1. **No delimiter runs**: Org emphasis is always single character (`*text*`)
   - Don't need `num_emphasis_delimiters_left` tracking
   - Each `*` is independent decision

2. **No same-delimiter nesting**: Can't have `*bold *inside* bold*`
   - Need delimiter stack to prevent nesting
   - Track which delimiters are currently open

3. **Strict boundary rules** (from org-syntax.md):
   - PRE: whitespace, `-`, `(`, `{`, `'`, `"`, or BOL
   - POST: whitespace, `-`, `.`, `,`, `;`, `:`, `!`, `?`, `'`, `)`, `}`, `[`, `"`, `\`, or EOL
   - CONTENTS: No whitespace after OPEN, no whitespace before CLOSE

### What State We Need

```c
typedef struct {
    // Delimiter nesting stack (prevent *bold *inside* bold*)
    char open_delimiters[MAX_NESTING];  // Stack of open delimiters
    uint8_t nesting_depth;              // Current depth (0-MAX_NESTING)

    // Context decision caching (optional optimization)
    uint8_t last_decision;              // Last OPEN/CLOSE decision made
} Scanner;
```

**MAX_NESTING**: 8 should be sufficient (common: `*bold /italic/ inside*`)

### State Management Strategy

**When we see an emphasis marker `*`**:

1. **Check if currently open**:
   ```c
   bool is_open = false;
   for (int i = 0; i < nesting_depth; i++) {
       if (open_delimiters[i] == '*') {
           is_open = true;
           break;
       }
   }
   ```

2. **Decide OPEN or CLOSE**:
   - If `is_open && valid_symbols[BOLD_CLOSE]`: Try CLOSE
   - If `!is_open && valid_symbols[BOLD_OPEN]`: Try OPEN
   - If both conditions false: return false

3. **Validate boundaries**:
   - OPEN: Check `has_whitespace_before || at_BOL`, check no whitespace after
   - CLOSE: Check no whitespace before (via state?), check valid POST after

4. **Update state**:
   - OPEN: Push delimiter to stack, increment depth
   - CLOSE: Pop delimiter from stack, decrement depth

### Challenge: CONTENTS Validation for CLOSE

**Problem**: We need to know if there was whitespace BEFORE the closing `*`.

**Options**:
A. **Track last character matched** (complex):
   ```c
   bool last_was_whitespace;  // Updated after every token
   ```

B. **Trust grammar + scanner cooperation** (simpler):
   - Grammar ensures content between OPEN and CLOSE
   - Scanner only checks: no whitespace immediately before CLOSE
   - Use lookahead: backup 1 char, check if whitespace, restore

C. **Simplify rule** (pragmatic):
   - Only validate POST boundary for CLOSE
   - Let grammar handle content validation via `repeat1()`

**Decision**: Use Option C for MVP, can enhance later.

## Implementation Plan

### Phase 1: Basic State Structure
- [x] Define Scanner struct with delimiter stack
- [ ] Implement push/pop helpers
- [ ] Implement is_delimiter_open check
- [ ] Implement serialization

### Phase 2: Rewrite scan_emphasis
- [ ] Check if delimiter currently open
- [ ] Make OPEN/CLOSE decision
- [ ] Validate boundaries (simplified)
- [ ] Update state on success

### Phase 3: Testing
- [ ] Test 1: Simple `*bold*` - basic open/close
- [ ] Test 2: Nested different: `*bold /italic/*` - stack works
- [ ] Test 3: Invalid nesting: `*bold *inside* bold*` - should fail

### Phase 4: Refinement
- [ ] Add full boundary validation
- [ ] Handle edge cases
- [ ] Performance optimization

## Expected Behavior

### Test Case: `"This is *bold* text"`

```
Scan 1: lookahead='*' at column 8
  - Stack: []
  - is_open('*') = false
  - valid_symbols[BOLD_OPEN] = true
  - has_whitespace_before = true (from context token)
  - Decision: OPEN
  - Validate: no whitespace after → PASS
  - Emit: BOLD_OPEN
  - State: Stack=[*], depth=1

Scan 2: lookahead='*' at column 13
  - Stack: [*]
  - is_open('*') = true
  - valid_symbols[BOLD_CLOSE] = true
  - Decision: CLOSE
  - Validate: valid POST after → PASS
  - Emit: BOLD_CLOSE
  - State: Stack=[], depth=0
```

### Test Case: `"*bold *invalid* bold*"` (should fail)

```
Scan 1: '*' at column 0
  - Stack: []
  - Decision: OPEN → Stack=[*]

Scan 2: '*' at column 6
  - Stack: [*]
  - is_open('*') = true
  - valid_symbols[BOLD_OPEN] = true (grammar allows, but we shouldn't!)
  - Decision: Should reject! Already open.
  - Return: false (no token emitted)

Parser: ERROR - couldn't match BOLD_OPEN
```

## Critical Insight

The state tracking solves the "valid_symbols ambiguity" problem:
- Even if grammar says both OPEN and CLOSE are valid
- Scanner state tells us which one is ACTUALLY correct
- This makes decisions consistent across backtracking

## Next Steps

1. Implement Scanner struct and helpers (push/pop/is_open)
2. Implement serialize/deserialize
3. Rewrite scan_emphasis with state logic
4. Create 3 minimal tests
5. Debug and iterate

Let's build this systematically!
