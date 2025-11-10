/**
 * @file Org-mode grammar for tree-sitter
 * @author Your Name
 * @license MIT
 */

/// <reference types="tree-sitter-cli/dsl" />
// @ts-check

module.exports = grammar({
  name: 'org',

  rules: {
    document: $ => repeat($._element),

    _element: $ => choice(
      $.headline,
      $.paragraph
    ),

    // Headline: STARS KEYWORD PRIORITY COMMENT TITLE TAGS
    headline: $ => seq(
      $.stars,
      ' ',
      optional(seq(
        field('keyword', $.keyword),
        ' '
      )),
      optional(seq(
        field('priority', $.priority),
        ' '
      )),
      optional(field('title', $.title)),
      optional(field('tags', $.tags)),
      '\n'
    ),

    // Stars: one or more asterisks at the start of a line
    stars: $ => /\*+/,

    // Keywords: TODO, DONE, etc.
    keyword: $ => token(prec(1, choice(
      'TODO',
      'DONE',
      'NEXT',
      'WAITING',
      'CANCELED'
    ))),

    // Priority: [#A], [#B], [#C]
    priority: $ => token(prec(1, /\[#[A-Z]\]/)),

    // Title: matches headline text
    // TODO: Improve to stop before tags (tags currently absorbed into title)
    title: $ => prec(-1, /[^\n]+/),

    // Tags: match tag sequence
    // TODO: Implement proper tag parsing with external scanner or improved lexing
    tags: $ => seq(
      repeat1($.tag),
      ':'
    ),

    tag: $ => /:[a-zA-Z0-9_@#%]+/,

    // Paragraph: any line that doesn't start with a special character
    paragraph: $ => seq(
      /[^*\n][^\n]*/,
      /\n/
    ),
  }
});
