/**
 * @file Inline (Object-level) grammar for Org-mode - Phase 1: Plain Text Baseline
 * @author Org-TS-Mode Contributors
 * @license MIT
 *
 * PHASE 1: Establish baseline with plain text only
 *
 * This is a systematic rebuild following TDD principles.
 * See doc/INLINE_GRAMMAR_ANALYSIS.md for complete rebuild plan.
 *
 * Current phase: Plain text parsing only
 * Next phase: Add simple objects (targets, macros, entities)
 */

/// <reference types="tree-sitter-cli/dsl" />
// @ts-check

module.exports = grammar({
  name: 'org_inline',

  // Phase 1: No externals yet
  // externals: $ => [],

  // Only skip newlines (they delimit inline content)
  extras: $ => ['\n'],

  rules: {
    // Root: Optional title_only to handle empty inline content
    // Only start rule can match empty string in tree-sitter
    inline: $ => optional($.title_only),

    // Title without tags (tags come in Phase 5)
    title_only: $ => field('title', $.title),

    // Title: Sequence of objects and plain text
    // Phase 1: Just plain text
    // Phase 2a: Add targets and radio targets
    // Phase 2b: Add macros
    // Phase 2c: Add entities
    // Phase 2d: Add links
    // Phase 2e: Add statistics cookies
    // Phase 2f: Add footnotes
    // Phase 2g: Add timestamps
    title: $ => repeat1(choice(
      // Phase 2a: Targets (unique delimiters, no conflicts)
      prec(3, $.radio_target),  // <<<>>> - must match before target (longer delimiter)
      prec(3, $.target),         // <<>>

      // Phase 2b: Macros (unique delimiters, no conflicts)
      prec(3, $.macro),          // {{{name}}}

      // Phase 2c: Entities (unique delimiter, no conflicts)
      prec(3, $.entity),         // \alpha, \nbsp, etc.

      // Phase 2d: Links (various delimiters)
      prec(4, $.plain_link),     // protocol:// - highest precedence (contains : internally)
      prec(3, $.regular_link),   // [[...]] - unique double bracket
      prec(3, $.angle_link),     // <protocol:...> - must have protocol

      // Phase 2e: Statistics cookies (specific [ patterns)
      prec(3, $.statistics_cookie),  // [N%] or [N/M]

      // Phase 2f: Footnotes (specific [fn: pattern)
      prec(3, $.footnote_reference),  // [fn:label] or [fn:label:def] or [fn::def]

      // Phase 2g: Timestamps (date patterns in < > or [ ])
      prec(3, $.timestamp),  // <2024-01-01> or [2024-01-01]

      // Plain text (fallback)
      prec(1, $.plain_text)
    )),

    // Target: <<TARGET>>
    // Atomic token for bounding - prevents partial consumption
    // Content: any characters except angle brackets and newline
    target: $ => token(seq(
      '<<',
      /[^<>\n]+/,
      '>>'
    )),

    // Radio target: <<<TARGET>>>
    // Creates automatic links for matching text in document
    // Atomic token for bounding - prevents partial consumption
    // Content: any characters except angle brackets and newline
    radio_target: $ => token(seq(
      '<<<',
      /[^<>\n]+/,
      '>>>'
    )),

    // Macro: {{{name}}} or {{{name(args)}}}
    // Used for text replacement and templating
    // Name: letter followed by letters/digits/underscores/hyphens
    // Args: any characters except } and )
    // NOT atomic - we want internal structure (macro_name, macro_args) visible
    macro: $ => seq(
      '{{{',
      alias(/[a-zA-Z][a-zA-Z0-9_-]*/, $.macro_name),
      optional(seq(
        '(',
        alias(/[^})]+/, $.macro_args),
        ')'
      )),
      '}}}'
    ),

    // Entity: \NAME or \NAME{} (LaTeX-style entities)
    // Examples: \alpha, \beta, \nbsp, \tilde, etc.
    // Name must be letters only
    // Optional {} can follow for explicit termination
    // Atomic token for bounding - simple pattern, no internal structure needed
    entity: $ => token(seq(
      '\\',
      /[a-zA-Z]+/,
      optional('{}')
    )),

    // Regular link: [[URL]] or [[URL][DESCRIPTION]]
    // Standard org-mode link with double square brackets
    // NOT atomic - we want to potentially parse description as inline objects later
    // For now, treat as atomic token for simplicity and bounding
    regular_link: $ => token(seq(
      '[[',
      /[^\]\n]+/,  // Target/URL: anything except ] or newline
      optional(seq(
        '][',
        /[^\]\n]+/  // Description: anything except ] or newline
      )),
      ']]'
    )),

    // Angle link: <PROTOCOL:PATH>
    // More permissive than plain links (allows whitespace)
    // MUST have protocol: to distinguish from timestamps <2024-01-01>
    // Atomic token for bounding
    angle_link: $ => token(seq(
      '<',
      /[a-zA-Z][a-zA-Z0-9+.-]*:/,  // Protocol: letters, then optional +.-
      /[^>\n]+/,                     // Path: anything except > or newline
      '>'
    )),

    // Plain link: PROTOCOL://PATH or mailto:EMAIL
    // Bare URL without brackets
    // Recognized for well-defined protocols (http, https, ftp, mailto, etc.)
    // Smart termination: excludes trailing punctuation for readability
    // Atomic token for bounding
    // Pattern handles:
    // - protocol://... (http, https, ftp, file, etc.)
    // - mailto:user@example.com (special case for email)
    plain_link: $ => token(choice(
      // Protocol with :// (http://, https://, ftp://, file://, etc.)
      /[a-zA-Z][a-zA-Z0-9+.-]*:\/\/[^\s]+/,
      // mailto: protocol (doesn't use ://)
      /mailto:[^\s]+/
    )),

    // Statistics cookie: [N%] or [N/M]
    // Used for progress tracking in headlines and lists
    // N and M are optional digits
    // Atomic token for bounding - simple specific pattern
    statistics_cookie: $ => token(choice(
      // Percentage format: [N%] where N is zero or more digits
      seq('[', /\d*/, '%', ']'),
      // Fraction format: [N/M] where N and M are zero or more digits
      seq('[', /\d*/, '/', /\d*/, ']')
    )),

    // Footnote reference: [fn:label], [fn:label:def], or [fn::def]
    // Three formats:
    //   1. Named reference: [fn:label] - references a footnote defined elsewhere
    //   2. Inline with definition: [fn:label:definition text] - defines footnote inline
    //   3. Anonymous: [fn::definition text] - anonymous inline footnote
    // Label: alphanumeric, hyphens, underscores (no spaces)
    // Definition: any text except ] and newline
    // Atomic token for bounding - prevents internal components from leaking
    footnote_reference: $ => token(seq(
      '[fn:',
      choice(
        // Named with definition: [fn:label:definition]
        seq(
          /[a-zA-Z0-9_-]+/,  // Label
          ':',
          /[^\]]+/           // Definition (excludes ] to prevent greedy matching)
        ),
        // Named without definition: [fn:label]
        /[a-zA-Z0-9_-]+/,    // Label only
        // Anonymous: [fn::definition]
        seq(
          ':',
          /[^\]]+/           // Definition (excludes ] to prevent greedy matching)
        )
      ),
      ']'
    )),

    // Timestamp: <2024-01-15 Mon> or [2024-01-15 Mon]
    // Active timestamps (<>) appear in agenda, inactive ([]) are for reference
    // Can include time (14:30), ranges (09:00-17:00), repeaters (+1w), delays (-2d)
    // Pattern specificity for bounding:
    // - Active: Must start with digit and contain '-' (to avoid matching <protocol://url>)
    // - Inactive: Must start with digit and contain '-' (to avoid matching [50%] or [fn:...])
    // Atomic token for bounding - prevents internal components from leaking
    timestamp: $ => token(choice(
      // Active timestamp: <2024-01-15 Mon 14:30>
      // Must start with digit and contain dash (date separator)
      // This distinguishes from angle links which have protocol:// early on
      seq('<', /[0-9][^>]*-[^>]*/, '>'),
      // Inactive timestamp: [2024-01-15 Mon 14:30]
      // Must start with digit and contain dash (date separator)
      // This distinguishes from:
      // - [fn:...] (starts with 'f', not digit)
      // - [50%] (no dash)
      // - [1/2] (no dash)
      seq('[', /\d[^\]]*-[^\]]*/, ']')
    )),

    // Plain text: Any characters except newline or special delimiters
    // Exclude <, {, \, [, and > so targets, macros, entities, and links can be recognized
    plain_text: $ => /[^<{\\\[\n]+/,
  }
});
