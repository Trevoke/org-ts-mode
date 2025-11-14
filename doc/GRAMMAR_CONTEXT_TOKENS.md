# Grammar Context Tokens for Emphasis Validation

## Problem Statement

Tree-sitter external scanners cannot look backward in the input stream. To validate emphasis PRE boundaries (characters before the opening delimiter), we need to know what the previous token was. This document describes how we use **context tokens** to communicate this information from the grammar to the scanner.

## Inspiration: Markdown Implementation

The markdown grammar solves this problem by adding special "context tokens" to the externals array:

```javascript
// From tree-sitter-markdown-inline/grammar.js lines 46-49
// For emphasis we need to tell the parser if the last character was a whitespace (or the
// beginning of a line) or a punctuation. These tokens never actually get emitted.
$._last_token_whitespace,
$._last_token_punctuation,
```

### How It Works

1. **Grammar declares context tokens** in the `externals` array
2. **Grammar rules include these tokens** (usually as `optional($._last_token_...)`):
   ```javascript
   _whitespace: $ => seq(choice($._whitespace_ge_2, / /), optional($._last_token_whitespace)),
   ```
3. **Scanner checks `valid_symbols[]`** to see if context tokens are valid:
   ```c
   if (!valid_symbols[LAST_TOKEN_WHITESPACE] && ...) {
       // We know previous token was NOT whitespace
   }
   ```

**Key insight**: These tokens are **never emitted** - they exist only to pass information through the `valid_symbols` array.

## Org-Mode Requirements

From org-syntax.md (lines 1756-1777), emphasis boundaries have these rules:

### PRE (before opening marker)
- **Valid**: whitespace, `-`, `(`, `{`, `'`, `"`, or beginning of line
- **Invalid**: alphanumeric, `)`, `}`, `.`, `,`, etc.

### POST (after closing marker)
- **Valid**: whitespace, `-`, `.`, `,`, `;`, `:`, `!`, `?`, `'`, `)`, `}`, `[`, `"`, `\`, or end of line
- **Invalid**: alphanumeric, `(`, `{`, `@`, etc.

### CONTENTS
- Opening: Character after opening marker must NOT be whitespace
- Closing: Character before closing marker must NOT be whitespace

## Our Design

We'll use a simpler approach than markdown (which implements complex CommonMark rules):

### Context Tokens

Add to `externals` array:
```javascript
// Context tokens (never emitted, only for scanner communication)
$._last_token_whitespace,    // Previous token was whitespace or BOL
$._last_token_pre,            // Previous token was valid PRE character
```

We only need TWO tokens because org-mode PRE validation is binary:
- `_last_token_whitespace`: Previous was whitespace or beginning of line (most common)
- `_last_token_pre`: Previous was other valid PRE character (`-`, `(`, `{`, `'`, `"`)

If NEITHER is valid, then previous token was something else (invalid for PRE).

### Grammar Changes

Add context tokens after relevant productions:

```javascript
// Whitespace should set the context
plain_text: $ => seq(
  /[^*\/~=+_:@\[\]<>\\\{\}\n]+/,
  optional($._last_token_whitespace)
),

// PRE characters should set context
_pre_delimiter: $ => seq(
  choice('-', '(', '{', "'", '"'),
  optional($._last_token_pre)
),
```

Wait, this approach won't work well because we'd need to modify every rule...

### Alternative: Top-Level Context Tracking

Better approach - add context tokens to high-level rules that always execute:

```javascript
title: $ => prec.right(repeat1(seq(
  choice(
    $.text_markup,
    $.plain_link,
    // ... all inline elements
  ),
  optional(choice($._last_token_whitespace, $._last_token_pre))
))),
```

Actually, let me study markdown more carefully to see exactly where they put the optional tokens...

## Markdown Pattern Analysis

Looking at markdown grammar line 338:
```javascript
_whitespace: $ => seq(choice($._whitespace_ge_2, / /), optional($._last_token_whitespace)),
```

And line 454:
```javascript
_emphasis_star: $ => prec.dynamic(PRECEDENCE_LEVEL_EMPHASIS, seq(
  alias($._emphasis_open_star, $.emphasis_delimiter),
  optional($._last_token_punctuation),
  $_inline_no_star,
  alias($._emphasis_close_star, $.emphasis_delimiter)
)),
```

**Pattern**: Context tokens are placed AFTER the token they describe.

So:
- Whitespace rule ends with `optional($._last_token_whitespace)` - "I just emitted whitespace"
- Punctuation characters end with `optional($._last_token_punctuation)` - "I just emitted punctuation"

## Our Implementation Plan

### Step 1: Define Context Tokens

```javascript
externals: $ => [
  $.TAGS,
  // Emphasis delimiters
  $._bold_open,
  $._bold_close,
  // ... other emphasis tokens ...

  // Context tokens (never emitted, communicate previous token type)
  $._last_token_whitespace,   // Just emitted whitespace or at BOL
  $._last_token_pre_char,     // Just emitted valid PRE char (-, (, {, ', ")
],
```

### Step 2: Modify Grammar Rules

Add context tokens after relevant rules:

```javascript
// After whitespace
plain_text: $ => /[^*\/~=+_:@\[\]<>\\\{\}\n]+/,  // No change needed - plain text could be anything

// Strategy: Add context marker to a wrapper rule that matches after each element
_inline_element: $ => seq(
  choice(
    $.plain_link,
    $.text_markup,
    $.plain_text,
    // ... all inline objects
  ),
  optional(choice(
    $._last_token_whitespace,
    $._last_token_pre_char
  ))
),
```

Wait, this is getting complicated. Let me think about this differently...

## Simplified Approach: Character Classification

Instead of tracking specific token types, track CHARACTER CLASSES:

```javascript
externals: $ => [
  // ... emphasis tokens ...

  // Context: What character class did we just emit?
  $._last_was_pre_char,      // Last character was valid PRE (ws, -, (, {, ', ", or BOL)
],
```

Then in grammar:
```javascript
// Rules that end with PRE characters emit the context token
_title_element: $ => seq(
  choice(/* all inline elements */),
  optional($._last_was_pre_char)
),
```

But how do we know when to emit this? We need the grammar to pattern-match...

## The Pattern: Append Context Tokens After Matching

From markdown's `common/common.js` line 118:
```javascript
function punctuation_without($, chars) {
    return seq(
        choice(...PUNCTUATION_CHARACTERS_ARRAY.filter(c => !chars.includes(c))),
        optional($._last_token_punctuation)  // Context token after content!
    );
}
```

**The Pattern**:
1. Match the actual content (punctuation character)
2. Append `optional($._context_token)` to mark what we just matched
3. Scanner checks `valid_symbols[CONTEXT_TOKEN]` to learn about previous token

Markdown's classification:
- `_word` → no context token (default)
- `punctuation_without()` → appends `$._last_token_punctuation`
- `_whitespace` → appends `$._last_token_whitespace`

## Our Implementation Design

### Step 1: Define Context Tokens

```javascript
externals: $ => [
  $.TAGS,

  // Emphasis delimiters
  $._bold_open,
  $._bold_close,
  $._italic_open,
  $._italic_close,
  $._underline_open,
  $._underline_close,
  $._code_open,
  $._code_close,
  $._verbatim_open,
  $._verbatim_close,
  $._strike_open,
  $._strike_close,

  // Context tokens (never emitted, only for scanner communication)
  // These tell scanner what character class preceded the current position
  $._last_token_whitespace,  // Previous char was whitespace or BOL
  $._last_token_pre_char,    // Previous char was valid PRE: -, (, {, ', "
],
```

### Step 2: Modify Grammar Rules to Emit Context

We need to append context tokens after rules that match PRE characters.

#### Option A: Modify plain_text regex

Split plain_text into multiple rules based on ending character:

```javascript
// Current:
plain_text: $ => /[^*\/~=+_:@\[\]<>\\\{\}\n]+/,

// New: Split by ending character class
plain_text: $ => choice(
  seq(/[^*\/~=+_:@\[\]<>\\\{\}\n\s\-\(\{\'\"\)]*[\s]/, optional($._last_token_whitespace)),
  seq(/[^*\/~=+_:@\[\]<>\\\{\}\n\s\-\(\{\'\"\)]*[\-\(\{\'\"]/, optional($._last_token_pre_char)),
  /[^*\/~=+_:@\[\]<>\\\{\}\n]+/  // Fallback: no context
),
```

This is complex and error-prone...

#### Option B: Helper Function Like Markdown

Create a helper that appends context tokens:

```javascript
// Helper function
function char_with_context($, char_pattern, context_token) {
  return seq(char_pattern, optional(context_token));
}

// Use it
plain_text: $ => choice(
  char_with_context($, /[^*\/~=+_:@\[\]<>\\\{\}\n]+[ \t]/, $._last_token_whitespace),
  char_with_context($, /[^*\/~=+_:@\[\]<>\\\{\}\n]+[\-\(\{\'\"]/, $._last_token_pre_char),
  /[^*\/~=+_:@\[\]<>\\\{\}\n]+/,  // Other characters
),
```

Still complex...

#### Option C: Simpler - Only Track Whitespace

Start simple! Only track whitespace (most common PRE case):

```javascript
// Just track whitespace for now
plain_text: $ => choice(
  seq(/[^*\/~=+_:@\[\]<>\\\{\}\n\s]+[\s]/, optional($._last_token_whitespace)),  // Ends with space
  /[^*\/~=+_:@\[\]<>\\\{\}\n]+/,  // Doesn't end with space
),
```

Then scanner:
- If `valid_symbols[_last_token_whitespace]` is true → previous char was whitespace (valid PRE)
- If false → previous char was NOT whitespace (might be invalid PRE)

**Decision**: Start with Option C (whitespace only), then expand if needed.

### Step 3: Scanner Logic

```c
// In scan_emphasis():

// Priority 1: Try closing (closes have precedence)
if (valid_symbols[close_token]) {
    lexer->advance(lexer, false);  // Consume delimiter
    lexer->mark_end(lexer);

    // POST validation: next char must be valid POST
    bool at_line_end = at_line_boundary(lexer);
    if (!is_post_char(lexer->lookahead, at_line_end)) {
        return false;
    }

    // CONTENTS validation: we already check this in grammar (no whitespace before close)
    // Actually wait - we can't check this in grammar! Need scanner state...
    // TODO: Revisit this

    lexer->result_symbol = close_token;
    return true;
}

// Priority 2: Try opening
if (valid_symbols[open_token]) {
    // PRE validation: Check if previous token was valid PRE character
    // If whitespace context token is valid, previous was whitespace (good!)
    // Otherwise, need to check for other PRE chars (-, (, {, ', ")
    bool has_valid_pre = valid_symbols[LAST_TOKEN_WHITESPACE];

    // For now, accept if we have whitespace context OR if we're at column 0
    if (!has_valid_pre && lexer->get_column(lexer) != 0) {
        // No whitespace before, not at BOL → might be invalid
        // For now, be permissive and allow it
        // TODO: Add full PRE validation
    }

    lexer->advance(lexer, false);  // Consume delimiter
    lexer->mark_end(lexer);

    // CONTENTS validation: next char must NOT be whitespace
    if (is_whitespace(lexer->lookahead)) {
        return false;
    }
    if (lexer->eof(lexer)) {
        return false;
    }

    lexer->result_symbol = open_token;
    return true;
}
```

### Step 4: Test-Driven Development Plan

1. **Test 1**: Simple whitespace PRE - `This is *bold* text`
   - Should PASS: space before `*` is valid PRE

2. **Test 2**: Invalid PRE - `word*bold*word`
   - Should FAIL: letter before `*` is invalid PRE

3. **Test 3**: BOL - `*bold* at start`
   - Should PASS: beginning of line is valid PRE

4. **Test 4**: Hyphen PRE - `word-*bold*`
   - Should PASS: hyphen is valid PRE

Let's start implementing!
