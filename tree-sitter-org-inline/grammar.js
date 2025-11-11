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
    title: $ => prec.right(repeat1(choice(
      prec(4, $.plain_link),         // FIRST: contains ':' - must override standalone ':'
      prec(3, $.text_markup),
      prec(3, $.regular_link),       // BEFORE statistics_cookie (longer match: [[ vs [)
      prec(3, $.statistics_cookie),
      prec(3, $.export_snippet),
      prec(3, $.radio_target),       // Triple angle brackets <<<>>>
      prec(3, $.target),             // Double angle brackets <<>>
      prec(3, $.angle_link),         // Single angle brackets <>
      prec(3, $.entity),             // LaTeX entities: \alpha, \nbsp, etc.
      prec(3, $.macro),              // Org macros: {{{name}}} or {{{name(args)}}}
      prec(2, ':'),  // Allow colons in title (lower precedence than TAGS and plain_link)
      prec(1, $.plain_text)
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

    // Plain text - any characters except markup delimiters, brackets, @, angle brackets, colon, backslash, braces, newline
    // Lower precedence so markup, cookies, snippets, targets, links, entities, macros are preferred
    // Colons are excluded to allow external scanner to detect TAGS (:tag1:tag2:)
    // Square brackets are excluded so statistics cookies and regular_link can be recognized
    // @ is excluded so export snippets can be recognized
    // Angle brackets are excluded so targets can be recognized
    // Backslash is excluded so entities can be recognized
    // Braces are excluded so macros can be recognized
    plain_text: $ => prec(1, /[^*\/~=_+:@\[\]<>\\\{\}\n]+/),
  }
});
