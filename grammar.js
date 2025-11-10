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
      prec(2, $.planning_line),
      $.link,
      prec(2, $.footnote_reference),
      $.timestamp,
      $.macro,
      $.latex_fragment,
      $.entity,
      prec(-1, $.subscript),
      prec(-1, $.superscript),
      prec(2, $.horizontal_rule),
      prec(1, $.list),
      $.block,
      $.directive,
      $.comment,
      $.property_drawer,
      $.drawer,
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
    // TODO: Currently absorbs tags into title. Proper tag parsing requires:
    //   - External scanner (can scan ahead to detect tag pattern), OR
    //   - Lookahead regex (not supported: "look-around...is not supported"), OR
    //   - Restructured parsing (tags as separate pass)
    title: $ => prec(-1, /[^\n]+/),

    // Tags: match tag sequence
    // TODO: Implement proper tag parsing with external scanner or improved lexing
    tags: $ => seq(
      repeat1($.tag),
      ':'
    ),

    tag: $ => /:[a-zA-Z0-9_@#%]+/,

    // Planning line: KEYWORD: TIMESTAMP
    // Match entire line as atomic token to avoid conflicts
    planning_line: $ => token(seq(
      optional(/[ \t]+/),  // Optional leading whitespace
      choice('DEADLINE', 'SCHEDULED', 'CLOSED'),
      ':',
      /[ \t]+/,
      choice(
        // Active timestamp: <2024-01-01 Mon 14:30>
        seq('<', /[^>\n]+/, '>'),
        // Inactive timestamp: [2024-01-01 Mon 14:30]
        seq('[', /[^\]\n]+/, ']')
      ),
      '\n'
    )),

    // Standalone timestamp: <2024-01-01> or [2024-01-01]
    // Active (<>) for agenda items, inactive ([]) for reference dates
    timestamp: $ => token(seq(
      choice(
        // Active timestamp: <2024-01-01 Mon 14:30>
        seq('<', /[^>\n]+/, '>'),
        // Inactive timestamp: [2024-01-01 Mon 14:30]
        // Must start with digit to avoid matching [fn:...]
        seq('[', /\d[^\]\n]*/, ']')
      ),
      '\n'
    )),

    // Macro: {{{name}}} or {{{name(args)}}}
    macro: $ => seq(
      '{{{',
      alias(/[a-zA-Z][a-zA-Z0-9_-]*/, $.macro_name),
      optional(seq(
        '(',
        alias(/[^})]+/, $.macro_args),
        ')'
      )),
      '}}}',
      '\n'
    ),

    // Footnote reference: [fn:label], [fn:label:def], or [fn::def]
    footnote_reference: $ => token(seq(
      '[fn:',
      choice(
        // Named with definition: [fn:label:definition]
        seq(
          /[a-zA-Z0-9_-]+/,
          ':',
          /[^\]]+/
        ),
        // Named without definition: [fn:label]
        /[a-zA-Z0-9_-]+/,
        // Anonymous: [fn::definition]
        seq(
          ':',
          /[^\]]+/
        )
      ),
      ']',
      '\n'
    )),

    // LaTeX fragment: $$...$$ or $...$
    latex_fragment: $ => token(seq(
      choice(
        // Display math: $$...$$
        seq('$$', /[^$]+/, '$$'),
        // Inline math: $...$
        seq('$', /[^$\n]+/, '$')
      ),
      '\n'
    )),

    // Entity: \name or \name{}
    entity: $ => token(seq(
      '\\',
      /[a-zA-Z]+/,
      optional('{}'),
      '\n'
    )),

    // Subscript: text_script (e.g., H_2O, A_i,j)
    subscript: $ => token(seq(
      /[a-zA-Z0-9]+/,  // Base text (alphanumeric word)
      '_',
      /[^\n]+/,        // Script content (anything until newline)
      '\n'
    )),

    // Superscript: text^script (e.g., x^2, x^{y^{z}})
    superscript: $ => token(seq(
      /[a-zA-Z0-9]+/,  // Base text (alphanumeric word)
      '^',
      /[^\n]+/,        // Script content (anything until newline)
      '\n'
    )),

    // Link: [[target]] or [[target][description]]
    link: $ => seq(
      '[[',
      alias(/[^\]\n]+/, $.link_target),
      optional(seq(
        '][',
        alias(/[^\]\n]+/, $.link_description)
      )),
      ']]',
      '\n'
    ),

    // List: consecutive list items
    list: $ => prec.right(repeat1($.list_item)),

    // List item: BULLET CONTENT
    list_item: $ => seq(
      optional(/[ \t]+/),
      $.bullet,
      ' ',
      /[^\n]*/,
      '\n'
    ),

    // Bullet: -, +, 1., a), etc.
    bullet: $ => token(choice(
      '-',
      '+',
      seq(/[0-9]+/, '.'),
      seq(/[0-9]+/, ')'),
      seq(/[a-zA-Z]/, '.'),
      seq(/[a-zA-Z]/, ')')
    )),

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

    // Generic drawer: :NAME: ... :end:
    drawer: $ => seq(
      ':',
      $.drawer_name,
      ':',
      /[ \t]*/,
      '\n',
      optional($.drawer_content),
      ':end:',
      /[ \t]*/,
      '\n'
    ),

    // Drawer name: uppercase letters, hyphens, underscores
    drawer_name: $ => /[A-Z_-]+/,

    // Drawer content: any text until :end:
    // Use negative lookahead pattern to stop before :end:
    drawer_content: $ => /([^:]|:[^eE]|:[eE][^nN]|:[eE][nN][^dD]|:[eE][nN][dD][^:])+/,

    // Horizontal rule: 5 or more dashes on a line
    horizontal_rule: $ => token(seq(
      /-----+/,  // 5 or more dashes (5 fixed plus zero or more)
      '\n'
    )),

    // Paragraph: any line that doesn't start with special characters
    // Excludes: *, #, |, [, -, +, :, {, digits, lowercase letters
    paragraph: $ => seq(
      /[^*#|\[\-+:{0-9a-z\n][^\n]*/,
      /\n/
    ),
  }
});
