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
    title: $ => repeat1(choice(
      // Phase 2a: Targets (unique delimiters, no conflicts)
      prec(3, $.radio_target),  // <<<>>> - must match before target (longer delimiter)
      prec(3, $.target),         // <<>>

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

    // Plain text: Any characters except newline or angle brackets
    // Exclude < and > so targets can be recognized
    plain_text: $ => /[^<\n]+/,
  }
});
