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

    // Title: Plain text only for Phase 1
    // In later phases, this will be repeat1(choice($.plain_text, ...objects...))
    title: $ => $.plain_text,

    // Plain text: Any characters except newline
    // In later phases, we'll exclude markup delimiters
    plain_text: $ => /[^\n]+/,
  }
});
