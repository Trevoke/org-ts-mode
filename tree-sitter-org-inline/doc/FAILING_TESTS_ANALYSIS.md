# Failing Tests Analysis - Phase 9

## Category Breakdown (20 tests)

### 1. Subscript/Superscript Issues (7 tests) - PRIMARY TARGET
- ✗ 110: Simple subscript in title
- ✗ 112: Subscript with comma
- ✗ 114: Multiple subscripts and superscripts
- ✗ 116: Subscript at start of title
- ✗ 118: **Subscript vs underline distinction** ⭐ KEY TEST
- ✗ 119: Subscript with single character base
- ✗ 121: Subscript with numbers in base

### 2. Markup at Start (1 test)
- ✗ 134: Bold at start of line

### 3. Multiple/Mixed Markup (3 tests)
- ✗ 136: Multiple bold in same line
- ✗ 140: Mixed markup types
- ✗ 143: All markup types mixed

### 4. Markup Inside Other Objects (6 tests)
- ✗ 17: Angle link with markup
- ✗ 25: Entity mixed with markup
- ✗ 35: Export snippet with markup
- ✗ 56: Macro mixed with markup
- ✗ 92: Link with markup
- ✗ 107: Cookie with text markup
- ✗ 129: Target with markup

### 5. Other (3 tests)
- ✗ 5: Plain text with various characters
- ✗ 108: Cookie with tags

## Priority Order

**Phase 10: Debug Subscript + Sentinels**
- Focus on tests 110, 116, 118 - these should be fixable with sentinels!
- Test 118 (subscript vs underline) is THE key test sentinels should solve

**Later phases:**
- Markup at start (test 134)
- Multiple markup (tests 136, 140, 143)
- Markup inside objects (may not be solvable without grammar restructuring)
