/**
 * @file Inline (Object-level) grammar for Org-mode
 * @author Org-TS-Mode Contributors
 * @license MIT
 *
 * This grammar handles "Objects" in org-mode terminology - inline elements
 * that appear within block-level structures:
 * - Title/tags separation in headlines
 * - Text markup (bold, italic, code, etc.)
 * - Links, macros, footnotes
 * - Timestamps, entities
 *
 * This grammar is injected into nodes from the block-level grammar
 * (tree-sitter-org) via injection queries.
 *
 * ARCHITECTURE:
 * - Systematic precedence hierarchy (PRECEDENCE constants)
 * - Context-specific rules prevent invalid nesting
 * - Clean separation of concerns
 */

/// <reference types="tree-sitter-cli/dsl" />
// @ts-check

// ============================================================================
// PRECEDENCE HIERARCHY
// ============================================================================
// Systematic precedence levels for disambiguation.
// Higher values win in conflicts.

const PRECEDENCE = {
  // Plain text (lowest - fallback)
  PLAIN_TEXT: 0,

  // Structural tokens
  COLON: 2,

  // Basic formatting
  EMPHASIS: 10,        // bold, italic, underline, strike
  CODE: 15,            // code, verbatim

  // Minimal set objects
  ENTITY: 20,          // \alpha, \nbsp

  // Standard objects
  TARGET: 30,          // <<target>>
  RADIO_TARGET: 31,    // <<<radio>>>
  MACRO: 32,           // {{{name}}}
  EXPORT_SNIPPET: 33,  // @@backend:value@@

  // Time and counting
  TIMESTAMP: 40,       // <2024-01-15>, [2024-01-15]
  STATISTICS_COOKIE: 41,  // [50%], [1/2] - higher than timestamp

  // References
  FOOTNOTE_REFERENCE: 50,  // [fn:label]

  // Links (high precedence)
  PLAIN_LINK: 60,      // http://example.com
  ANGLE_LINK: 61,      // <http://example.com>
  REGULAR_LINK: 62,    // [[link][desc]]

  // Special (root-level disambiguation)
  TITLE_WITH_TAGS: 100,
  TITLE_ONLY: 90,
};

// ============================================================================
// CONTEXT DEFINITIONS
// ============================================================================
// Define which objects are allowed in which contexts

const CONTEXTS = {
  // Normal context: all objects allowed
  NORMAL: {
    allow_links: true,
    allow_emphasis: true,
    allow_code: true,
    allow_all_objects: true,
  },

  // Inside link description: no nested links
  LINK_DESCRIPTION: {
    allow_links: false,
    allow_emphasis: true,
    allow_code: true,
    allow_all_objects: true,
  },

  // Inside code/verbatim: no markup at all
  CODE_CONTENT: {
    allow_links: false,
    allow_emphasis: false,
    allow_code: false,
    allow_all_objects: false,
  },

  // Inside emphasis: all except same delimiter
  // (handled per-emphasis-type in generate_emphasis_rules)
  EMPHASIS: {
    allow_links: true,
    allow_emphasis: true,  // but filtered per delimiter
    allow_code: true,
    allow_all_objects: true,
  },
};

// ============================================================================
// RULE GENERATION HELPERS
// ============================================================================

/**
 * Build choice array for a context
 * This returns an array of rule references, not a choice() call
 */
function build_choices_array(context, exclude_emphasis = null) {
  // Return array of rule name strings
  // These will be converted to $.rule in the grammar rules section
  const choices = [];

  // Links (if allowed)
  if (context.allow_links) {
    choices.push('plain_link', 'angle_link', 'regular_link');
  }

  // Emphasis (if allowed)
  if (context.allow_emphasis) {
    if (exclude_emphasis !== 'bold') choices.push('bold');
    if (exclude_emphasis !== 'italic') choices.push('italic');
    if (exclude_emphasis !== 'underline') choices.push('underline');
    if (exclude_emphasis !== 'strike') choices.push('strike_through');
  }

  // Code (if allowed)
  if (context.allow_code) {
    choices.push('code', 'verbatim');
  }

  // Standard objects (if allowed)
  if (context.allow_all_objects) {
    choices.push(
      'entity',
      'target',
      'radio_target',
      'macro',
      'export_snippet',
      'timestamp',
      'statistics_cookie',
      'footnote_reference'
    );
  }

  // Plain text and whitespace always allowed
  choices.push('plain_text');
  choices.push('_whitespace');  // Emits context token for PRE validation

  return choices;
}

// ============================================================================
// GRAMMAR DEFINITION
// ============================================================================

module.exports = grammar({
  name: 'org_inline',

  externals: $ => [
    $.TAGS,  // Tags portion (:tag1:tag2:) - detected by scanner

    // Emphasis markers - scanner validates PRE/POST/CONTENTS boundaries
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

    // Context tokens (never emitted, communicate previous character class to scanner)
    // Pattern from tree-sitter-markdown: append optional($._context_token) after matching content
    $._last_token_whitespace,  // Previous character was whitespace
  ],

  extras: $ => ['\n'],

  rules: {
    // ========================================================================
    // ROOT RULES
    // ========================================================================

    // Root: Inline content with optional tags at end
    inline: $ => choice(
      prec.dynamic(PRECEDENCE.TITLE_WITH_TAGS, $.title_with_tags),
      prec.dynamic(PRECEDENCE.TITLE_ONLY, $.title_only)
    ),

    // Title with tags
    title_with_tags: $ => seq(
      field('title', optional($.title)),
      field('tags', alias($.TAGS, $.tags))
    ),

    // Title without tags
    title_only: $ => field('title', $.title),

    // Title: sequence of inline objects
    // Right-associative to greedily consume all content
    title: $ => prec.right(repeat1(choice(
      // Links (highest precedence - contain special chars)
      prec.dynamic(PRECEDENCE.PLAIN_LINK, $.plain_link),
      prec.dynamic(PRECEDENCE.ANGLE_LINK, $.angle_link),
      prec.dynamic(PRECEDENCE.REGULAR_LINK, $.regular_link),

      // References
      prec.dynamic(PRECEDENCE.FOOTNOTE_REFERENCE, $.footnote_reference),

      // Time and counting
      prec.dynamic(PRECEDENCE.STATISTICS_COOKIE, $.statistics_cookie),
      prec.dynamic(PRECEDENCE.TIMESTAMP, $.timestamp),

      // Standard objects
      prec.dynamic(PRECEDENCE.EXPORT_SNIPPET, $.export_snippet),
      prec.dynamic(PRECEDENCE.RADIO_TARGET, $.radio_target),
      prec.dynamic(PRECEDENCE.TARGET, $.target),
      prec.dynamic(PRECEDENCE.MACRO, $.macro),
      prec.dynamic(PRECEDENCE.ENTITY, $.entity),

      // Formatting
      prec.dynamic(PRECEDENCE.CODE, $.text_markup),

      // Structural
      prec.dynamic(PRECEDENCE.COLON, ':'),

      // Fallback
      prec.dynamic(PRECEDENCE.PLAIN_TEXT, $.plain_text)
    ))),

    // ========================================================================
    // TEXT MARKUP (Emphasis)
    // ========================================================================

    text_markup: $ => choice(
      $.bold,
      $.italic,
      $.underline,
      $.code,
      $.verbatim,
      $.strike_through
    ),

    // Bold: *text*
    // Scanner validates PRE/POST/CONTENTS boundaries
    bold: $ => prec.dynamic(PRECEDENCE.EMPHASIS, seq(
      $._bold_open,
      repeat1($._inline_element_no_bold),
      $._bold_close
    )),

    // Italic: /text/
    // Scanner validates PRE/POST/CONTENTS boundaries
    italic: $ => prec.dynamic(PRECEDENCE.EMPHASIS, seq(
      $._italic_open,
      repeat1($._inline_element_no_italic),
      $._italic_close
    )),

    // Underline: _text_
    // Scanner validates PRE/POST/CONTENTS boundaries
    underline: $ => prec.dynamic(PRECEDENCE.EMPHASIS, seq(
      $._underline_open,
      repeat1($._inline_element_no_underline),
      $._underline_close
    )),

    // Code: ~text~
    // Content is opaque - no parsing inside
    // Scanner validates PRE/POST/CONTENTS boundaries
    code: $ => prec.dynamic(PRECEDENCE.CODE, seq(
      $._code_open,
      /[^\s~][^~\n]*[^\s~]|[^\s~\n]/,  // Scanner validates, but regex ensures no leading/trailing ws
      $._code_close
    )),

    // Verbatim: =text=
    // Content is opaque - no parsing inside
    // Scanner validates PRE/POST/CONTENTS boundaries
    verbatim: $ => prec.dynamic(PRECEDENCE.CODE, seq(
      $._verbatim_open,
      /[^\s=][^=\n]*[^\s=]|[^\s=\n]/,  // Scanner validates, but regex ensures no leading/trailing ws
      $._verbatim_close
    )),

    // Strike-through: +text+
    // Scanner validates PRE/POST/CONTENTS boundaries
    strike_through: $ => prec.dynamic(PRECEDENCE.EMPHASIS, seq(
      $._strike_open,
      repeat1($._inline_element_no_strike),
      $._strike_close
    )),

    // ========================================================================
    // LINKS
    // ========================================================================

    // Regular link: [[path]] or [[path][description]]
    regular_link: $ => prec.dynamic(PRECEDENCE.REGULAR_LINK, seq(
      '[[',
      field('path', /[^\]]+/),
      optional(seq(
        '][',
        field('description', /[^\]]+/)
      )),
      ']]'
    )),

    // Angle link: <protocol:path>
    angle_link: $ => prec.dynamic(PRECEDENCE.ANGLE_LINK, seq(
      '<',
      /[a-zA-Z][a-zA-Z0-9+.-]*/,  // protocol
      ':',
      /[^>\n]+/,  // path
      '>'
    )),

    // Plain link: protocol:path
    plain_link: $ => prec.dynamic(PRECEDENCE.PLAIN_LINK, seq(
      /[a-zA-Z][a-zA-Z0-9+.-]*/,  // protocol
      ':',
      /\/\/[^\s\[\]<>()]+|[^\s\[\]<>()]+/  // path with or without //
    )),

    // ========================================================================
    // OBJECTS
    // ========================================================================

    // Entity: \alpha, \nbsp, etc.
    entity: $ => prec.dynamic(PRECEDENCE.ENTITY, seq(
      '\\',
      /[a-zA-Z]+/,
      optional('{}')  // Optional braces for explicit termination
    )),

    // Target: <<target>>
    target: $ => prec.dynamic(PRECEDENCE.TARGET, seq(
      '<<',
      /[^<>\n]+/,
      '>>'
    )),

    // Radio target: <<<content>>>
    radio_target: $ => prec.dynamic(PRECEDENCE.RADIO_TARGET, seq(
      '<<<',
      /[^<>\n]+/,
      '>>>'
    )),

    // Macro: {{{name}}} or {{{name(args)}}}
    macro: $ => prec.dynamic(PRECEDENCE.MACRO, seq(
      '{{{',
      $.macro_name,
      optional(seq(
        '(',
        $.macro_args,
        ')'
      )),
      '}}}'
    )),

    macro_name: $ => /[a-zA-Z][a-zA-Z0-9_-]*/,
    macro_args: $ => /[^)]+/,

    // Export snippet: @@backend:value@@
    export_snippet: $ => prec.dynamic(PRECEDENCE.EXPORT_SNIPPET, seq(
      '@@',
      /[a-zA-Z][a-zA-Z0-9-]*/,  // backend
      ':',
      optional(/[^@]+/),  // value
      '@@'
    )),

    // Footnote reference: [fn:label], [fn:label:definition], [fn::definition]
    footnote_reference: $ => prec.dynamic(PRECEDENCE.FOOTNOTE_REFERENCE, seq(
      '[fn:',
      optional(/[a-zA-Z0-9_-]+/),  // label
      optional(seq(':', /[^\]]+/)),  // definition
      ']'
    )),

    // Timestamp: <2024-01-15>, [2024-01-15], with optional time/repeater
    timestamp: $ => prec.dynamic(PRECEDENCE.TIMESTAMP, choice(
      // Active: <date>
      seq(
        '<',
        /\d{4}-\d{2}-\d{2}[^>\]\n]*/,
        '>'
      ),
      // Inactive: [date]
      seq(
        '[',
        /\d{4}-\d{2}-\d{2}[^>\]\n]*/,
        ']'
      )
    )),

    // Statistics cookie: [50%] or [1/2]
    statistics_cookie: $ => prec.dynamic(PRECEDENCE.STATISTICS_COOKIE, choice(
      // Percentage: [50%] or [%]
      seq('[', /\d*/, '%', ']'),
      // Fraction: [1/2], [3/], or [/5]
      seq('[', /\d*/, '/', /\d*/, ']')
    )),

    // ========================================================================
    // PLAIN TEXT
    // ========================================================================

    // Plain text: fallback for any characters not matched by other rules
    // Excludes: markup delimiters, brackets, special chars, underscore (for underline), whitespace
    // NOTE: Changed to exclude whitespace so _whitespace can emit context token
    plain_text: $ => prec(PRECEDENCE.PLAIN_TEXT, /[^*\/~=+_:@\[\]<>\\\{\}\n\s]+/),

    // Whitespace token with context emission (pattern from tree-sitter-markdown)
    // This allows scanner to know when previous token was whitespace (valid PRE for emphasis)
    _whitespace: $ => seq(/[ \t]+/, optional($._last_token_whitespace)),

    // ========================================================================
    // CONTEXT-SPECIFIC RULES
    // ========================================================================
    // These rules define what objects are allowed in different contexts
    // to prevent invalid nesting (e.g., links inside links)

    // Normal context: all objects allowed
    _inline_element: $ => choice(
      ...build_choices_array(CONTEXTS.NORMAL).map(name => $[name])
    ),

    // Link description context: no nested links
    _inline_element_no_link: $ => choice(
      ...build_choices_array(CONTEXTS.LINK_DESCRIPTION).map(name => $[name])
    ),

    // Code content context: only plain text (no parsing)
    _inline_element_code_content: $ => $.plain_text,

    // Emphasis contexts: prevent nesting same delimiter
    _inline_element_no_bold: $ => choice(
      ...build_choices_array(CONTEXTS.EMPHASIS, 'bold').map(name => $[name])
    ),

    _inline_element_no_italic: $ => choice(
      ...build_choices_array(CONTEXTS.EMPHASIS, 'italic').map(name => $[name])
    ),

    _inline_element_no_underline: $ => choice(
      ...build_choices_array(CONTEXTS.EMPHASIS, 'underline').map(name => $[name])
    ),

    _inline_element_no_strike: $ => choice(
      ...build_choices_array(CONTEXTS.EMPHASIS, 'strike').map(name => $[name])
    ),
  }
});
