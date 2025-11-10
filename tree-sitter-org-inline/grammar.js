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
    // Use repeat1 to ensure at least one object
    // Higher precedence for markup so *bold* is preferred over plain text with asterisks
    // Right-associative to greedily consume all content
    title: $ => prec.right(repeat1(choice(
      prec(2, $.text_markup),
      prec(1, $.plain_text)
    ))),

    // Text markup: bold, italic, code, verbatim
    text_markup: $ => choice(
      $.bold,
      $.italic,
      $.code,
      $.verbatim
    ),

    // Bold: *text*
    // Content must not start/end with whitespace, and can't contain newlines or *
    // Simple pattern for now - PRE/POST validation can be added later via scanner
    bold: $ => seq(
      '*',
      /[^\s*][^*\n]*[^\s*]|[^\s*\n]/,  // content: non-ws + optional(any-except-*-newline) + non-ws, OR single non-ws
      '*'
    ),

    // Italic: /text/
    italic: $ => seq(
      '/',
      /[^\s\/][^\/\n]*[^\s\/]|[^\s\/\n]/,
      '/'
    ),

    // Code: ~text~
    code: $ => seq(
      '~',
      /[^\s~][^~\n]*[^\s~]|[^\s~\n]/,
      '~'
    ),

    // Verbatim: =text=
    verbatim: $ => seq(
      '=',
      /[^\s=][^=\n]*[^\s=]|[^\s=\n]/,
      '='
    ),

    // Plain text - any characters except markup delimiters and tags
    // Lower precedence so markup is preferred
    plain_text: $ => prec(1, /[^*\/~=:\n]+/),
  }
});
