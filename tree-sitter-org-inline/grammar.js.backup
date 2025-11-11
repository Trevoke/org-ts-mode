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
    $.TAGS,        // Tags portion (:tag1:tag2:) - detected by scanner
    $.SUBSCRIPT,   // Subscript pattern (BASE_SCRIPT) - validated by scanner
    $.SUPERSCRIPT, // Superscript pattern (BASE^SCRIPT) - validated by scanner
    $.WORD,        // Alphanumeric word NOT followed by _/^ - prevents plain_text from consuming subscript bases
  ],

  // Only skip newlines (they delimit inline content) - not spaces (they're part of plain_text)
  extras: $ => ['\n'],

  rules: {
    // Root: Inline content is objects with optional tags at end
    // Use dynamic precedence to prefer title_with_tags when tags are present
    inline: $ => choice(
      prec.dynamic(2, $.title_with_tags),
      prec.dynamic(1, $.title_only)
    ),

    // Title with tags: title followed by tags (scanner validates space before tags)
    title_with_tags: $ => seq(
      field('title', optional($.title)),
      field('tags', alias($.TAGS, $.tags))
    ),

    // Title without tags: just title
    title_only: $ => field('title', $.title),

    // Title: sequence of inline objects, including colons
    // Use repeat1 to ensure at least one object
    // Colons are explicit tokens so external scanner can intercept for tags
    // Higher precedence for inline objects (markup/cookies/snippets/targets/links), then colon, then plain text
    // Right-associative to greedily consume all content
    // Dynamic precedence hierarchy: text_markup > subscript/superscript > plain_text
    // - text_markup (underline) beats subscript when both valid (org-mode spec: "underline takes priority")
    // - subscript/superscript beat plain_text to prevent plain_text from consuming the base character
    title: $ => prec.right(repeat1(choice(
      prec(4, $.plain_link),              // FIRST: contains ':' - must override standalone ':'
      prec.dynamic(10, $.text_markup),    // HIGHEST: underline takes priority over subscript (org-mode spec)
      prec.dynamic(5, $.subscript),       // MEDIUM: beats plain_text but yields to underline
      prec.dynamic(5, $.superscript),     // MEDIUM: beats plain_text but yields to other markup
      prec(3, $.regular_link),       // BEFORE footnote_reference (longer match: [[ vs [fn:)
      prec(3, $.angle_link),         // BEFORE timestamp (both use <>, but angle_link has protocol)
      prec(3, $.footnote_reference), // BEFORE statistics_cookie (both start with [, but [fn: is more specific)
      prec.dynamic(4, $.statistics_cookie),  // Higher dynamic precedence than timestamp
      prec.dynamic(3, $.timestamp),          // Lower dynamic precedence - fallback for [\d...] patterns
      prec(3, $.export_snippet),
      prec(3, $.radio_target),       // Triple angle brackets <<<>>>
      prec(3, $.target),             // Double angle brackets <<>>
      prec(3, $.entity),             // LaTeX entities: \alpha, \nbsp, etc.
      prec(3, $.macro),              // Org macros: {{{name}}} or {{{name(args)}}}
      prec(2, ':'),  // Allow colons in title (lower precedence than TAGS and plain_link)
      prec(1, $.plain_text)          // LOWEST: fallback for all other text
    ))),

    // Text markup: bold, italic, underline, code, verbatim, strike-through
    text_markup: $ => choice(
      $.bold,
      $.italic,
      $.underline,
      $.code,
      $.verbatim,
      $.strike_through
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

    // Underline: _text_
    underline: $ => seq(
      '_',
      /[^\s_][^_\n]*[^\s_]|[^\s_\n]/,
      '_'
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

    // Strike-through: +text+
    strike_through: $ => seq(
      '+',
      /[^\s+][^+\n]*[^\s+]|[^\s+\n]/,
      '+'
    ),

    // Statistics cookie: [N%] or [N/M] where N and M are optional digits
    // Used for progress tracking in headlines and lists
    statistics_cookie: $ => choice(
      // Percentage format: [N%] where N is zero or more digits
      seq('[', /\d*/, '%', ']'),
      // Fraction format: [N/M] where N and M are zero or more digits
      seq('[', /\d*/, '/', /\d*/, ']')
    ),

    // Export snippet: @@backend:content@@
    // Used for backend-specific export formatting
    // Backend: alphanumeric and hyphens
    // Content: anything except @ or newline (simplified from spec)
    export_snippet: $ => seq(
      '@@',
      /[a-zA-Z0-9-]+/,  // Backend name
      ':',
      /[^@\n]*/,        // Content (excludes @ to avoid closing delimiter issues)
      '@@'
    ),

    // Target: <<TARGET>>
    // Used as anchors for internal links and references
    // Target name can contain any characters except < > and newline
    // Can include spaces, hyphens, underscores, dots, etc.
    target: $ => seq(
      '<<',
      /[^<>\n]+/,  // Target name: any characters except angle brackets and newline
      '>>'
    ),

    // Radio target: <<<TARGET>>>
    // Creates a target that automatically links all matching text in the document
    // Target name can contain any characters except < > and newline
    // Per spec: should start/end with non-whitespace and contain inline objects
    // Simplified implementation: match content, let validation happen elsewhere
    radio_target: $ => seq(
      '<<<',
      /[^<>\n]+/,  // Target name: any characters except angle brackets and newline
      '>>>'
    ),

    // Regular link: [[URL]] or [[URL][DESCRIPTION]]
    // The standard org-mode link format with double square brackets
    // URL can be: protocol:path, file:path, id:uuid, #heading, fuzzy text, etc.
    // DESCRIPTION is optional human-readable text
    // Note: No newline at end (unlike block grammar) - allows inline usage
    regular_link: $ => seq(
      '[[',
      // URL/path: any characters except ] and newline
      /[^\]\n]+/,
      // Optional description after ][
      optional(seq(
        '][',
        // Description: any characters except ] and newline
        // Future: could parse description as inline objects (recursive)
        /[^\]\n]+/
      )),
      ']]'
    ),

    // Plain link: PROTOCOL://PATH or mailto:EMAIL (bare URL without brackets)
    // Recognized for well-defined protocols (http, https, ftp, mailto, etc.)
    // Cannot contain whitespace (unlike angle links)
    // Smart termination: excludes trailing sentence punctuation
    // Per org-mode spec: must end with non-punct char, /, or balanced parens
    // Simplified implementation: requires last char to be alphanumeric, /, -, _, ), or @
    // Must have :// OR must contain @ (to distinguish from :tags:)
    plain_link: $ => /[a-zA-Z][a-zA-Z0-9+.-]*:(\/\/[^\s]*[a-zA-Z0-9\/\-_)]|[^\s:]*@[^\s]*[a-zA-Z0-9])/,

    // Angle link: <PROTOCOL:PATH>
    // More permissive than plain links (allows whitespace, parentheses)
    // Protocol required to distinguish from plain angle brackets in text
    // Common protocols: http, https, file, ftp, mailto, news, etc.
    // PATH can contain any character except > (newlines/indentation ignored per spec)
    angle_link: $ => seq(
      '<',
      // Protocol: alphanumeric + optional plus/dot/hyphen, followed by colon
      /[a-zA-Z][a-zA-Z0-9+.-]*:/,
      // Path: any characters except > and newline
      /[^>\n]+/,
      '>'
    ),

    // Entity: \NAME or \NAME{} (LaTeX-style entities)
    // Examples: \alpha, \beta, \nbsp, \tilde, etc.
    // Used for special characters, Greek letters, math symbols
    // Name must be letters only (per org-mode spec)
    // Optional {} can follow for explicit termination
    // Unlike block version, no newline required (for inline usage)
    entity: $ => seq(
      '\\',
      /[a-zA-Z]+/,     // Entity name: letters only
      optional('{}')    // Optional explicit braces
    ),

    // Macro: {{{name}}} or {{{name(args)}}}
    // Used for text replacement and templating in org-mode
    // Name: letter followed by letters/digits/underscores/hyphens
    // Args: any characters except } and ) (simplified from spec)
    // Unlike block version, no newline required (for inline usage)
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

    // Footnote reference: [fn:label], [fn:label:def], or [fn::def]
    // Used to reference or define footnotes inline
    // Three formats:
    //   1. Named reference: [fn:label] - references a footnote defined elsewhere
    //   2. Inline with definition: [fn:label:definition text] - defines footnote inline
    //   3. Anonymous: [fn::definition text] - anonymous inline footnote
    // Label: alphanumeric, hyphens, underscores (no spaces)
    // Definition: any text except ] and newline
    // Unlike block version, no newline required (for inline usage)
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
    // - Active: Must NOT contain ':/' early (to avoid matching <protocol://url> angle links)
    // - Inactive: Must start with digit and contain '-' or space (date format, not [50%] cookie)
    // Unlike block version, no newline required (for inline usage)
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

    // Subscript: BASE_SCRIPT (e.g., H_2O, A_i,j)
    // Atomic token validated by external scanner
    // Scanner validates:
    //   - BASE: alphanumeric characters
    //   - _: underscore marker
    //   - SCRIPT: asterisk, braced expr, or SIGN CHARS FINAL pattern
    //   - "Underline takes priority" rule (per org-mode spec)
    // External scanner solves lookahead problem where plain_text would consume BASE
    subscript: $ => $.SUBSCRIPT,

    // Superscript: BASE^SCRIPT (e.g., x^2, x^{y^{z}})
    // Atomic token validated by external scanner
    // Scanner validates same pattern as subscript but with ^ marker
    superscript: $ => $.SUPERSCRIPT,

    // Plain text - matches text that's not part of other inline elements
    // Uses repeat1 to merge consecutive non-alphanumeric text and WORD tokens
    // Non-alphanumeric: spaces, punctuation, etc (matched by regex)
    // Alphanumeric: handled by WORD external token (scanner validates not subscript/superscript)
    // Lower precedence so markup, cookies, snippets, targets, links, entities, macros, subscript, superscript are preferred
    // Colons are excluded to allow external scanner to detect TAGS (:tag1:tag2:)
    // Square brackets are excluded so statistics cookies and regular_link can be recognized
    // @ is excluded so export snippets can be recognized
    // Angle brackets are excluded so targets can be recognized
    // Backslash is excluded so entities can be recognized
    // Braces are excluded so macros can be recognized
    // Underscore and caret excluded so subscript/superscript can be recognized
    plain_text: $ => prec.right(repeat1(choice(
      /[^*\/~=_+:@\[\]<>\\\{\}\^\na-zA-Z0-9]+/,  // Non-alphanumeric text
      alias($.WORD, $.plain_text)                 // Words validated by scanner
    ))),
  }
});
