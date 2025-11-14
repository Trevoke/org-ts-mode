# Phase 1: Context-Specific Rules - Design Document

**Date**: 2025-11-13
**Status**: Design Validated
**Phase**: Rearchitecture Phase 1 (Foundation)
**Effort**: 2-3 weeks

---

## Executive Summary

Implement context-specific inline element variants to prevent invalid nesting at grammar level, following markdown's proven Pattern 3 architecture. This removes nesting validation burden from the scanner and makes restrictions explicit in the grammar structure.

**Impact**: Prevents links in links, same-delimiter emphasis nesting, and markup in code—all enforced by parser structure rather than runtime validation.

---

## Current State Analysis

### What We Have ✅

**Foundation is solid:**
```javascript
// PRECEDENCE hierarchy - well-defined
const PRECEDENCE = {
  PLAIN_TEXT: 0,
  EMPHASIS: 10,
  CODE: 15,
  // ... systematic levels
};

// CONTEXTS structure - good model
const CONTEXTS = {
  NORMAL: { allow_links: true, allow_emphasis: true, ... },
  LINK_DESCRIPTION: { allow_links: false, ... },
  CODE_CONTENT: { allow_links: false, allow_emphasis: false, ... },
  EMPHASIS: { allow_links: true, allow_emphasis: true, ... },
};

// Helper function - correct approach
function build_choices_array(context, exclude_emphasis = null) {
  const choices = [];
  if (context.allow_links) {
    choices.push('plain_link', 'angle_link', 'regular_link');
  }
  // ... builds array correctly
  return choices;
}
```

### What's Missing ❌

**Rules don't use the foundation:**
```javascript
// ❌ Hardcoded content (ignores CONTEXTS)
_emphasis_content: $ => choice(
  $.bold, $.italic, $.underline, $.strike_through,
  $.plain_text, $.entity, $.code, $.verbatim
),

// ❌ Scanner prevents same-delimiter nesting (should be grammar's job)
// From scanner.c:850
bool is_open = is_delimiter_on_stack(scanner, delimiter);
if (is_open && same_delimiter) {
  return false; // Block same-delimiter nesting
}

// ❌ Links use regex for description (can't enforce no-link restriction)
regular_link: $ => seq(
  '[[',
  field('path', /[^\]]+/),
  optional(seq('][', field('description', /[^\]]+/))),
  ']]'
),
```

---

## Design: Hybrid Approach (Validate Current Against Markdown)

### Markdown's Pattern 3 (Proven)

Creates 8 named variants to handle restrictions:
- `_inline_element` - All elements allowed
- `_inline_element_no_star` - Exclude * delimiters
- `_inline_element_no_underscore` - Exclude _ delimiters
- `_inline_element_no_link` - Exclude links
- ... and combinations

**Why this works:**
1. Conflicts eliminated at grammar level (not runtime)
2. Parse errors are more specific ("expected X, got Y")
3. Simpler scanner (no nesting state tracking)
4. Easy to extend (add new restriction = new variant)

### Our 7 Variants (Org-Mode Adaptation)

```javascript
// 1. NORMAL - Everything allowed
_inline_element: $ => choice(
  $.plain_link, $.angle_link, $.regular_link,
  $.bold, $.italic, $.underline, $.strike_through,
  $.code, $.verbatim,
  $.entity, $.target, $.radio_target, $.macro,
  $.export_snippet, $.timestamp, $.statistics_cookie,
  $.footnote_reference,
  $.plain_text
),

// 2. NO_LINK - Inside link descriptions
_inline_element_no_link: $ => choice(
  // All except links
  $.bold, $.italic, $.underline, $.strike_through,
  $.code, $.verbatim,
  // ... all objects ...
  $.plain_text
),

// 3. NO_MARKUP - Inside code/verbatim
_inline_element_no_markup: $ => choice(
  $.plain_text  // ONLY plain text
),

// 4-7. NO_[EMPHASIS] - Inside each emphasis type
_inline_element_no_bold: $ => choice(
  $.plain_link, $.angle_link, $.regular_link,
  $.italic, $.underline, $.strike_through,  // NO bold
  $.code, $.verbatim,
  // ... all objects ...
  $.plain_text
),

_inline_element_no_italic: $ => choice(/* similar */),
_inline_element_no_underline: $ => choice(/* similar */),
_inline_element_no_strike: $ => choice(/* similar */),
```

---

## Implementation Strategy

### Step 1: Enhance Current Helper (Keep What Works)

**Current helper is good - just enhance it:**

```javascript
// KEEP: build_choices_array (working correctly)
function build_choices_array(context, exclude_emphasis = null) {
  const choices = [];

  if (context.allow_links) {
    choices.push('plain_link', 'angle_link', 'regular_link');
  }

  if (context.allow_emphasis) {
    // Add all emphasis types
    const all_emphasis = ['bold', 'italic', 'underline', 'strike_through'];

    // Exclude specific type if requested
    const allowed_emphasis = exclude_emphasis
      ? all_emphasis.filter(e => e !== exclude_emphasis)
      : all_emphasis;

    choices.push(...allowed_emphasis);
  }

  if (context.allow_code) {
    choices.push('code', 'verbatim');
  }

  if (context.allow_all_objects) {
    choices.push(
      'entity', 'target', 'radio_target', 'macro',
      'export_snippet', 'timestamp', 'statistics_cookie',
      'footnote_reference'
    );
  }

  choices.push('plain_text');
  return choices;
}

// ADD: Convert array to grammar rule
function create_inline_variant($, name, context, exclude_emphasis = null) {
  const choices_array = build_choices_array(context, exclude_emphasis);
  const choices_refs = choices_array.map(choice => $[choice]);
  return choice(...choices_refs);
}

// ADD: Generate all variants at once
function generate_all_inline_variants($) {
  return {
    _inline_element:
      create_inline_variant($, 'normal', CONTEXTS.NORMAL),

    _inline_element_no_link:
      create_inline_variant($, 'no_link', CONTEXTS.LINK_DESCRIPTION),

    _inline_element_no_markup:
      create_inline_variant($, 'no_markup', CONTEXTS.CODE_CONTENT),

    _inline_element_no_bold:
      create_inline_variant($, 'no_bold', CONTEXTS.EMPHASIS, 'bold'),

    _inline_element_no_italic:
      create_inline_variant($, 'no_italic', CONTEXTS.EMPHASIS, 'italic'),

    _inline_element_no_underline:
      create_inline_variant($, 'no_underline', CONTEXTS.EMPHASIS, 'underline'),

    _inline_element_no_strike:
      create_inline_variant($, 'no_strike', CONTEXTS.EMPHASIS, 'strike_through'),
  };
}
```

### Step 2: Update Grammar Rules

```javascript
module.exports = grammar({
  name: 'org_inline',

  externals: $ => [
    $.TAGS,
    // ... emphasis tokens ...
    $._delimiter_char,
  ],

  rules: {
    // Root rules
    inline: $ => choice(
      prec.dynamic(PRECEDENCE.TITLE_WITH_TAGS, $.title_with_tags),
      prec.dynamic(PRECEDENCE.TITLE_ONLY, $.title_only)
    ),

    title: $ => prec.right(repeat1($._inline_element)),  // Use variant!

    // INJECT: All 7 variants generated here
    ...generate_all_inline_variants($),

    // === REFACTORED RULES ===

    // Emphasis: Use variant to exclude same delimiter
    bold: $ => prec.dynamic(PRECEDENCE.EMPHASIS,
      seq($._bold_open, repeat1($._inline_element_no_bold), $._bold_close)
    ),

    italic: $ => prec.dynamic(PRECEDENCE.EMPHASIS,
      seq($._italic_open, repeat1($._inline_element_no_italic), $._italic_close)
    ),

    underline: $ => prec.dynamic(PRECEDENCE.EMPHASIS,
      seq($._underline_open, repeat1($._inline_element_no_underline), $._underline_close)
    ),

    strike_through: $ => prec.dynamic(PRECEDENCE.EMPHASIS,
      seq($._strike_open, repeat1($._inline_element_no_strike), $._strike_close)
    ),

    // Links: Use no_link variant in description
    regular_link: $ => prec.dynamic(PRECEDENCE.REGULAR_LINK, seq(
      '[[',
      field('path', /[^\]]+/),
      optional(seq('][', field('description', repeat1($._inline_element_no_link)))),
      ']]'
    )),

    // Code/Verbatim: Use no_markup variant
    code: $ => prec.dynamic(PRECEDENCE.CODE, seq(
      $._code_open,
      repeat1($._inline_element_no_markup),
      $._code_close
    )),

    verbatim: $ => prec.dynamic(PRECEDENCE.CODE, seq(
      $._verbatim_open,
      repeat1($._inline_element_no_markup),
      $._verbatim_close
    )),

    // DELETE: _emphasis_content (replaced by variants)

    // ... rest of rules unchanged ...
  }
});
```

### Step 3: Simplify Scanner

**Remove same-delimiter nesting logic** (grammar handles it now):

```c
// DELETE from scanner.c:
// - is_delimiter_on_stack() usage for nesting prevention
// - Stack tracking for same-delimiter nesting
// - Nesting validation in scan_emphasis()

// KEEP in scanner:
// - Delimiter stack for OPEN/CLOSE matching
// - PRE/POST/CONTENTS boundary validation
// - Empty content detection
```

---

## Testing Strategy

### New Tests (Nesting Restrictions)

```org
==================
Test: Links cannot nest
==================

[[outer [[inner]] outer]]

---

(inline
  (title_only
    (title
      (plain_text))))  # Should be plain text, not nested links

==================
Test: Same delimiter cannot nest
==================

*outer *inner* outer*

---

(inline
  (title_only
    (title
      (plain_text))))  # Should be plain text

==================
Test: Code cannot contain markup
==================

~code *bold* code~

---

(inline
  (title_only
    (title
      (code
        (plain_text)))))  # *bold* becomes plain text inside code

==================
Test: Different delimiters CAN nest
==================

*bold /italic/ bold*

---

(inline
  (title_only
    (title
      (text_markup
        (bold
          (plain_text)
          (text_markup
            (italic
              (plain_text)))
          (plain_text))))))  # Valid nesting
```

### Regression Tests

**All existing 494 passing tests must continue to pass.**

Run after each step:
```bash
tree-sitter test
# Expected: 494/557 passing (same as before)
# New tests will increase total
```

---

## Migration Impact

### Breaking Changes: NONE ✅

**This is purely internal refactoring:**
- External API unchanged (parse tree structure identical)
- Scanner serialization unchanged (state structure same)
- Test expectations unchanged for existing tests

### Performance Impact: NEUTRAL to POSITIVE

**Expected:**
- Parsing speed: Same (variant lookup is compile-time)
- Scanner complexity: Reduced (less state tracking)
- Grammar size: +50 lines (but clearer structure)

---

## Success Criteria

### Phase 1 Complete When:

1. ✅ All 7 variants generated programmatically
2. ✅ All emphasis rules use appropriate variants
3. ✅ Links use no_link variant in description
4. ✅ Code/verbatim use no_markup variant
5. ✅ Scanner simplified (nesting logic removed)
6. ✅ New nesting restriction tests pass (4+ tests)
7. ✅ All existing tests still pass (494/557)
8. ✅ Grammar generates without conflicts

### Definition of Done:

```bash
# 1. Grammar builds
tree-sitter generate
# ✅ No errors

# 2. Tests pass
tree-sitter test
# ✅ 498+ / 561+ passing (494 existing + 4 new)

# 3. Manual validation
echo "*bold /italic/ bold*" | tree-sitter parse
# ✅ Nested structure

echo "*bold *invalid* bold*" | tree-sitter parse
# ✅ Plain text (rejected)

echo "[[link [[nested]] link]]" | tree-sitter parse
# ✅ Plain text (rejected)
```

---

## Next Steps (After This Design)

1. **Create git worktree** (using superpowers:using-git-worktrees)
2. **Write detailed implementation plan** (using superpowers:writing-plans)
3. **Implement with TDD** (using superpowers:test-driven-development)
4. **Request code review** (using superpowers:requesting-code-review)

---

## References

- Markdown Pattern 3: `../doc/MARKDOWN_PATTERNS_FOR_ORG_MODE.md#pattern-3`
- Current grammar: `tree-sitter-org-inline/grammar.js`
- Scanner code: `tree-sitter-org-inline/src/scanner.c`
- Rearchitecture plan: `../doc/INLINE_GRAMMAR_REARCHITECTURE_PLAN.md`

---

**Design Status**: ✅ Validated
**Ready for Implementation**: Yes
**Estimated Effort**: 2-3 weeks
**Risk Level**: Low (internal refactoring, no API changes)
