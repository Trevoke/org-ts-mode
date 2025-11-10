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
      $.block,
      $.directive,
      $.comment,
      $.property_drawer,
      prec(1, $.table),
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

    // Block: #+begin_NAME ... #+end_NAME
    block: $ => seq(
      $.block_begin,
      optional($.block_content),
      $.block_end
    ),

    // Block begin: #+begin_NAME [PARAMETERS]
    block_begin: $ => seq(
      token(seq('#', '+', /begin_/i)),
      field('type', $.block_type),
      optional(seq(
        ' ',
        field('language', $.language),
        optional(/[^\n]*/)  // Additional parameters
      )),
      '\n'
    ),

    block_type: $ => /[a-zA-Z_]+/,

    language: $ => /[a-zA-Z0-9_+-]+/,

    // Block content: everything until #+end_
    // Match any content (parser will stop at block_end)
    block_content: $ => /([^#]|#[^+]|#\+[^eE]|#\+[eE][^nN]|#\+[eE][nN][^dD]|#\+[eE][nN][dD][^_])+/,

    // Block end: #+end_NAME
    block_end: $ => seq(
      token(seq('#', '+', /end_/i)),
      optional($.block_type),
      /[^\n]*/,
      '\n'
    ),

    // Table: consecutive rows starting with |
    table: $ => prec.right(repeat1(choice(
      prec(1, $.table_separator),  // Prefer separator over row
      $.table_row
    ))),

    // Table row: | cell | cell |
    table_row: $ => seq(
      '|',
      repeat(seq(
        optional($.table_cell),
        '|'
      )),
      '\n'
    ),

    // Table cell: content between | separators
    table_cell: $ => /[^|\n]+/,

    // Table separator: |---+---|  (only dashes, pluses, and pipes)
    table_separator: $ => token(seq(
      '|',
      repeat1(/-+/),
      repeat(seq(
        choice('|', '+'),
        repeat1(/-+/)
      )),
      optional('|'),
      '\n'
    )),

    // Directive: #+KEYWORD: value (in-buffer settings)
    directive: $ => seq(
      token(seq('#', '+')),
      $.name,
      ':',
      optional(/[ \t]+/),
      alias(/[^\n]+/, $.value),
      '\n'
    ),

    name: $ => /[A-Z_]+/,

    // Comment: # followed by text (but not #+)
    comment: $ => seq(
      token(seq('#', ' ')),
      /[^\n]*/,
      '\n'
    ),

    // Property drawer: :PROPERTIES: ... :END:
    property_drawer: $ => seq(
      ':PROPERTIES:',
      /[ \t]*/,
      '\n',
      repeat1($.property),
      ':END:',
      /[ \t]*/,
      '\n'
    ),

    // Property: :KEY: value
    property: $ => seq(
      ':',
      $.key,
      ':',
      /[ \t]*/,
      $.value,
      '\n'
    ),

    key: $ => /[A-Z_-]+/,

    value: $ => /[^\n]+/,

    // Paragraph: any line that doesn't start with special characters
    paragraph: $ => seq(
      /[^*#|\n][^\n]*/,
      /\n/
    ),
  }
});
