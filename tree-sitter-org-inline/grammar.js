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
    $.TAGS,  // Tags portion (:tag1:tag2:) - detected by scanner
    $.BOLD_START,     // * with valid PRE char
    $.BOLD_END,       // * with valid POST char
    $.ITALIC_START,   // / with valid PRE char
    $.ITALIC_END,     // / with valid POST char
    $.CODE_START,     // ~ with valid PRE char
    $.CODE_END,       // ~ with valid POST char
    $.VERBATIM_START, // = with valid PRE char
    $.VERBATIM_END,   // = with valid POST char
  ],

  rules: {
    // Root: Inline content is objects with optional tags at end
    inline: $ => choice(
      prec(2, $.content_with_tags),
      prec(2, $.content_only)
    ),

    // Content with tags: objects followed by tags
    content_with_tags: $ => seq(
      field('title', $.title),
      ' ',
      field('tags', alias($.TAGS, $.tags))
    ),

    // Content without tags: just objects
    content_only: $ => field('title', $.title),

    // Title: sequence of inline objects
    title: $ => repeat1(choice(
      $.bold,
      $.italic,
      $.code,
      $.verbatim,
      $.plain_text
    )),

    // Text markup types
    bold: $ => seq($.BOLD_START, $.markup_content, $.BOLD_END),
    italic: $ => seq($.ITALIC_START, $.markup_content, $.ITALIC_END),
    code: $ => seq($.CODE_START, $.markup_content, $.CODE_END),
    verbatim: $ => seq($.VERBATIM_START, $.markup_content, $.VERBATIM_END),

    // Content within markup - no leading/trailing whitespace
    markup_content: $ => /[^\s*\/~=][^\*\/~=]*[^\s*\/~=]|[^\s*\/~=]/,

    // Plain text - any characters except markup delimiters
    plain_text: $ => /[^*\/~=:\n]+/,
  }
});
