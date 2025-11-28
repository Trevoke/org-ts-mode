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

  // LaTeX (after entity - entities like \alpha take priority over \commands)
  LATEX_FRAGMENT: 22,

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

  // Inside emphasis: restricted to emphasis, code, entity only
  // (handled per-emphasis-type in generate_emphasis_rules)
  EMPHASIS: {
    allow_links: false,         // no links in emphasis
    allow_emphasis: true,        // but filtered per delimiter
    allow_code: true,            // code/verbatim allowed
    allow_all_objects: false,    // we'll handle entity specially
    allow_entity_only: true,     // entity is the only object allowed
  },
};

// ============================================================================
// RULE GENERATION HELPERS
// ============================================================================

/**
 * Build choice array for a context
 * @param {object} context - CONTEXTS entry defining allowed elements
 * @param {string|null} exclude_emphasis - Emphasis type to exclude
 * @returns {Array<string>} Array of rule name strings
 */
function build_choices_array(context, exclude_emphasis = null) {
  const choices = [];

  // Links (if allowed)
  if (context.allow_links) {
    choices.push('plain_link', 'angle_link', 'regular_link');
  }

  // Emphasis (if allowed, excluding specified type)
  if (context.allow_emphasis) {
    const all_emphasis = ['bold', 'italic', 'underline', 'strike_through'];

    // Filter out excluded emphasis type if specified
    const allowed_emphasis = exclude_emphasis
      ? all_emphasis.filter(e => e !== exclude_emphasis)
      : all_emphasis;

    choices.push(...allowed_emphasis);
  }

  // Code (if allowed)
  if (context.allow_code) {
    choices.push('code', 'verbatim');
  }

  // Standard objects (if allowed)
  if (context.allow_all_objects) {
    choices.push(
      'entity',
      'latex_fragment',
      'target',
      'radio_target',
      'macro',
      'export_snippet',
      'timestamp',
      'statistics_cookie',
      'footnote_reference'
    );
  }

  // Special case: entity is allowed in emphasis context
  if (context.allow_entity_only) {
    choices.push('entity');
  }

  // Plain text always allowed
  choices.push('plain_text');

  return choices;
}

/**
 * Create an inline element variant from a context
 * @param {object} $ - Grammar rule references
 * @param {string} name - Variant name (for debugging)
 * @param {object} context - CONTEXTS entry defining allowed elements
 * @param {string|null} exclude_emphasis - Emphasis type to exclude (for same-delimiter prevention)
 * @returns {object} Tree-sitter choice() rule
 */
function create_inline_variant($, name, context, exclude_emphasis = null) {
  // Get array of allowed rule names
  const choices_array = build_choices_array(context, exclude_emphasis);

  // Convert string names to $ rule references
  const choices_refs = choices_array.map(choice_name => $[choice_name]);

  // Return choice() rule
  return choice(...choices_refs);
}

/**
 * Generate all 7 inline element variants
 * @returns {object} Map of variant name → grammar rule function
 */
function generate_all_inline_variants() {
  return {
    // 1. NORMAL - Everything allowed (default context)
    _inline_element: $ =>
      create_inline_variant($, 'normal', CONTEXTS.NORMAL),

    // 2. NO_LINK - Inside link descriptions (prevent nesting)
    _inline_element_no_link: $ =>
      create_inline_variant($, 'no_link', CONTEXTS.LINK_DESCRIPTION),

    // 3. NO_MARKUP - Inside code/verbatim (plain text only)
    _inline_element_no_markup: $ =>
      create_inline_variant($, 'no_markup', CONTEXTS.CODE_CONTENT),

    // 4-7. NO_EMPHASIS - Inside each emphasis type (prevent same-delimiter nesting)
    _inline_element_no_bold: $ =>
      create_inline_variant($, 'no_bold', CONTEXTS.EMPHASIS, 'bold'),

    _inline_element_no_italic: $ =>
      create_inline_variant($, 'no_italic', CONTEXTS.EMPHASIS, 'italic'),

    _inline_element_no_underline: $ =>
      create_inline_variant($, 'no_underline', CONTEXTS.EMPHASIS, 'underline'),

    _inline_element_no_strike: $ =>
      create_inline_variant($, 'no_strike', CONTEXTS.EMPHASIS, 'strike_through'),
  };
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

    // Delimiter fallback - for when scanner rejects invalid emphasis
    // Allows invalid emphasis delimiters to be treated as plain text
    $._delimiter_char,
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

    // ========================================================================
    // INLINE ELEMENT VARIANTS (Generated)
    // ========================================================================
    // 7 variants for different nesting contexts:
    // - _inline_element: All elements allowed (normal context)
    // - _inline_element_no_link: No links (inside link descriptions)
    // - _inline_element_no_markup: Plain text only (inside code/verbatim)
    // - _inline_element_no_bold/italic/underline/strike: Exclude same delimiter

    ...generate_all_inline_variants(),

    // ========================================================================
    // TITLE RULES
    // ========================================================================

    // Title with tags
    title_with_tags: $ => seq(
      field('title', optional($.title)),
      field('tags', alias($.TAGS, $.tags))
    ),

    // Title without tags
    title_only: $ => field('title', $.title),

    // Title: sequence of inline objects
    // Right-associative to greedily consume all content
    title: $ => prec.right(repeat1($._inline_element)),  // Uses normal variant

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

    // Unified emphasis implementation
    // Scanner determines type via delimiter and validates boundaries
    // Grammar prevents same-delimiter nesting via _inline_element_no_* variants
    // Grammar allows different-delimiter nesting via recursive inline elements

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

    // ========================================================================
    // LINKS
    // ========================================================================

    // Regular link: [[path]] or [[path][description]]
    regular_link: $ => prec.dynamic(PRECEDENCE.REGULAR_LINK, seq(
      '[[',
      field('path', /[^\]]+/),
      optional(seq(
        '][',
        field('description', repeat1($._inline_element_no_link))
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

    // LaTeX fragment: $$content$$, \(...\), \[...\], $...$
    // Note: Entity takes precedence for known entities like \alpha
    latex_fragment: $ => prec.dynamic(PRECEDENCE.LATEX_FRAGMENT, choice(
      // $$CONTENTS$$ - TeX display math (must come before single $)
      seq(token('$$'), /[^$]+/, token('$$')),
      // \(CONTENTS\) - Inline math
      // Content: anything except \) sequence
      seq(token('\\('), repeat(choice(/[^\\)]+/, /\\[^)]/)), token('\\)')),
      // \[CONTENTS\] - Display math
      // Content: anything except \] sequence
      seq(token('\\['), repeat(choice(/[^\\\]]+/, /\\[^\]]/)), token('\\]')),
      // $CHAR$ or $BORDER1 BODY BORDER2$ - TeX inline math
      // CHAR: non-whitespace, not . , ? ; " and not digits
      // BORDER1: non-whitespace, not . , ; $
      // BORDER2: non-whitespace, not . , $
      token(seq(
        '$',
        choice(
          seq(/[^\s.,?;"0-9\n$]/, '$'),  // Single CHAR followed by $
          seq(
            /[^\s.,;$\n]/,    // BORDER1
            /[^$\n]*/,        // BODY (can be empty per spec)
            /[^\s.,$\n]/,     // BORDER2
            '$'
          )
        )
      )),
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
    // Includes DELIMITER_CHAR for invalid emphasis delimiters (e.g., * in "* text*")
    // Excludes: brackets, special chars for objects (links, entities, macros, etc.)
    plain_text: $ => prec.right(PRECEDENCE.PLAIN_TEXT, repeat1(choice(
      /[^*\/~=+_:@\[\]<>\\\{\}\$^\n]+/,  // Regular text (exclude $ and ^ for LaTeX/sub/super)
      $._delimiter_char                 // Invalid emphasis delimiter
    )))
  }
});
