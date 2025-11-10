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
 * - Timestamps, entities, subscript/superscript
 *
 * This grammar is injected into nodes from the block-level grammar
 * (tree-sitter-org) via injection queries.
 */

/// <reference types="tree-sitter-cli/dsl" />
// @ts-check

module.exports = grammar({
  name: 'org_inline',

  externals: $ => [
    $.TITLE_TEXT,   // Title portion (before tags)
    $.TAGS,         // Tags portion (:tag1:tag2:)
  ],

  rules: {
    // Root: Inline content can be title with tags, or just text
    inline: $ => choice(
      $.title_with_tags,
      $.title_only,
      $.text
    ),

    // Title with tags: "Some title :tag1:tag2:"
    title_with_tags: $ => seq(
      field('title', alias($.TITLE_TEXT, $.title)),
      ' ',
      field('tags', alias($.TAGS, $.tags))
    ),

    // Title only: "Some title" (no tags)
    title_only: $ => field('title', alias($.TITLE_TEXT, $.title)),

    // Plain text (fallback)
    text: $ => /[^\n]+/,
  }
});
