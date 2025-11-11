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
      prec(3, $.text_markup),
      prec(3, $.statistics_cookie),
      prec(3, $.export_snippet),
      prec(3, $.target),
      prec(3, $.angle_link),
      prec(2, ':'),  // Allow colons in title (lower precedence than TAGS)
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

    // Plain text - any characters except markup delimiters, brackets, @, angle brackets, colon, newline
    // Lower precedence so markup, cookies, snippets, targets, and explicit colons are preferred
    // Colons are handled separately to allow external scanner to recognize tags
    // Square brackets are excluded so statistics cookies can be recognized
    // @ is excluded so export snippets can be recognized
    // Angle brackets are excluded so targets can be recognized
    plain_text: $ => prec(1, /[^*\/~=_+:@\[\]<>\n]+/),
  }
});
