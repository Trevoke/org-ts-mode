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
      prec(2, $.clock),
      prec(2, $.diary_sexp),
      $.link,
      prec(2, $.footnote_reference),
      $.timestamp,
      $.macro,
      $.latex_fragment,
      prec(2, $.latex_environment),
      $.entity,
      prec(-1, $.subscript),
      prec(-1, $.superscript),
      prec(2, $.horizontal_rule),
      prec(1, $.list),
      $.block,
      $.dynamic_block,
      $.directive,
      $.comment,
      $.property_drawer,
      prec(2, $.fixed_width),
      $.drawer,
      prec(1, $.table),
      $.paragraph
    ),

    // Headline: STARS KEYWORD PRIORITY COMMENT TITLE
    // Restructured as choice to handle COMMENT keyword token conflict
    // The title regex /[^\n]+/ would greedily consume "COMMENT ..." before
    // the COMMENT token could match, so we use two alternative structures:
    // 1. With COMMENT keyword (higher precedence)
    // 2. Without COMMENT keyword (lower precedence)
    // Note: Tags are currently absorbed into title. This is a known limitation
    // that will be addressed via inline grammar injection (see tree-sitter-org-inline)
    headline: $ => choice(
      // Variant 1: Headline WITH COMMENT keyword (preferred)
      // Dynamic precedence + conflicts declaration enables GLR disambiguation
      prec.dynamic(2, seq(
        $._headline_prefix,
        field('comment', $.comment_keyword),
        optional(seq(' ', field('title', $.title))),
        '\n'
      )),
      // Variant 2: Headline WITHOUT COMMENT keyword
      prec.dynamic(1, seq(
        $._headline_prefix,
        optional(field('title', $.title)),
        '\n'
      ))
    ),

    // Helper: Common headline prefix (stars, optional keyword, optional priority)
    // Underscore prefix means this is an internal/hidden rule
    _headline_prefix: $ => seq(
      $.stars,
      ' ',
      optional(seq(
        field('keyword', $.keyword),
        ' '
      )),
      optional(seq(
        field('priority', $.priority),
        ' '
      ))
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

    // COMMENT keyword: marks entire headline (and subtree) as commented
    // Must be exact string "COMMENT" (case-sensitive)
    // Appears after TODO/priority but before title
    // High token precedence ensures it's matched before title can consume it
    // Note: Like TODO/DONE keywords, this will match as a prefix (e.g., "COMMENTED" will match "COMMENT")
    // This is a known limitation - proper word boundary checking requires external scanner
    comment_keyword: $ => token(prec(10, 'COMMENT')),

    // Title: headline text (currently absorbs tags)
    // This will be replaced by inline grammar injection in tree-sitter-org-inline
    // which will properly separate title from tags using external scanner
    title: $ => /[^\n]+/,

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

    // Clock: CLOCK: timestamp or CLOCK: timestamp--timestamp => duration
    // Match entire line as atomic token to avoid conflicts
    // Case-insensitive keyword
    clock: $ => token(seq(
      optional(/[ \t]+/),  // Optional leading whitespace
      /[Cc][Ll][Oo][Cc][Kk]/,  // Case-insensitive CLOCK
      ':',
      /[ \t]+/,
      choice(
        // Format 1: CLOCK: [timestamp]--[timestamp] => HH:MM
        seq(
          seq('[', /\d[^\]\n]*/, ']'),  // First inactive timestamp
          '--',
          seq('[', /\d[^\]\n]*/, ']'),  // Second inactive timestamp
          /[ \t]+/,
          '=>',
          /[ \t]+/,
          /\d+:\d{2}/  // Duration HH:MM
        ),
        // Format 2: CLOCK: [timestamp]
        seq('[', /\d[^\]\n]*/, ']'),
        // Format 3: CLOCK: => HH:MM
        seq(
          '=>',
          /[ \t]+/,
          /\d+:\d{2}/
        )
      ),
      '\n'
    )),

    // Diary sexp: %%(lisp-expression)
    // Must be unindented and single-line only per org-mode spec
    // Content: Lisp expression with balanced parentheses
    // Simplified pattern: matches ( followed by any content followed by )
    // Does not validate paren balancing - relies on users writing valid Lisp
    diary_sexp: $ => token(seq(
      '%%',
      '(',
      /[^\n)]*(?:\([^)]*\)[^\n)]*)*/,  // Content with optional nested parens (simplified)
      ')',
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

    // LaTeX Environment: \begin{name} ... \end{name}
    // Used for equations, align, matrix, proof, etc.
    latex_environment: $ => seq(
      $.latex_env_begin,
      optional($.latex_env_content),
      $.latex_env_end
    ),

    // LaTeX environment begin: \begin{name} or \begin{name*}
    latex_env_begin: $ => seq(
      '\\begin{',
      field('name', /[a-zA-Z]+\*?/),  // Environment name, optional asterisk
      '}',
      '\n'
    ),

    // LaTeX environment content: everything until \end{
    // Stops before \end{ to allow parser to match environment terminator
    // Note: Nested environments are partially supported (known limitation)
    latex_env_content: $ => /([^\\]|\\[^eE]|\\[eE][^nN]|\\[eE][nN][^dD]|\\[eE][nN][dD][^{])+/,

    // LaTeX environment end: \end{name} or \end{name*}
    latex_env_end: $ => seq(
      '\\end{',
      optional(field('name', /[a-zA-Z]+\*?/)),  // Optional for flexibility
      '}',
      '\n'
    ),

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

    // Dynamic Block: #+begin: NAME ... #+end:
    // Used for dynamically generated content (clocktable, columnview, etc.)
    dynamic_block: $ => seq(
      $.dynamic_block_begin,
      optional($.dynamic_block_content),
      $.dynamic_block_end
    ),

    // Dynamic block begin: #+begin: NAME [PARAMETERS]
    // Note: colon after "begin" distinguishes from regular blocks
    dynamic_block_begin: $ => seq(
      token(seq('#', '+', /begin/i, ':')),
      /[ \t]+/,
      field('name', /[a-zA-Z0-9_-]+/),
      optional(/[^\n]*/),  // Optional parameters
      '\n'
    ),

    // Dynamic block content: everything until #+end:
    // Match any content (parser will stop at dynamic_block_end)
    // Pattern stops before #+end: (matches #+end followed by non-colon/non-newline)
    dynamic_block_content: $ => /([^#]|#[^+]|#\+[^eE]|#\+[eE][^nN]|#\+[eE][nN][^dD]|#\+[eE][nN][dD][^:\n])+/,

    // Dynamic block end: #+end:
    // Note: colon after "end" (no block name unlike regular blocks)
    dynamic_block_end: $ => seq(
      token(seq('#', '+', /end/i, ':')),
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

    // Fixed-width area: lines starting with : followed by space or EOL
    // Used for examples, code output, etc.
    // Right-associative to group consecutive lines into single block
    fixed_width: $ => prec.right(repeat1(seq(
      token(seq(':', optional(' '))),
      /[^\n]*/,
      '\n'
    ))),

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
    // Excludes: *, #, |, [, -, +, :, {, digits, lowercase letters, backslash
    paragraph: $ => seq(
      /[^*#|\[\-+:{0-9a-z\\\n][^\n]*/,
      /\n/
    ),
  }
});
