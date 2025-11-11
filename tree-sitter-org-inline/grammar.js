/**
 * @file Phase 2: Adding simple markup with distinctive delimiters
 * @author Org-TS-Mode Contributors
 * @license MIT
 *
 * STRATEGY REFINED:
 * - Bold uses token() for atomic all-or-nothing matching
 * - plain_text stops at * (and other markup delimiters in future)
 * - This gives bold a chance to match at each *
 * - If bold fails to match, * becomes part of plain_text on next iteration
 *
 * Bounding achieved: invalid bold degrades to plain_text naturally.
 *
 * Phase 2 Progress:
 * - [x] Bold: *text*
 * - [ ] Italic: /text/
 * - [ ] Code: ~text~
 * - [ ] Verbatim: =text=
 * - [ ] Strike: +text+
 */

/// <reference types="tree-sitter-cli/dsl" />
// @ts-check

module.exports = grammar({
  name: 'org_inline',

  // Only skip newlines - spaces are significant!
  extras: $ => ['\n'],

  rules: {
    inline: $ => $.title,

    // Title can contain bold or plain text
    title: $ => repeat1(choice(
      prec(2, $.bold),      // Try markup first
      prec(1, $.plain_text), // Fall back to plain text
    )),

    // Bold: *content* (atomic via token())
    // token() makes this all-or-nothing - if pattern doesn't fully match,
    // returns nothing and parser tries plain_text
    bold: $ => token(seq(
      '*',
      /[^\s*][^*\n]*[^\s*]|[^\s*\n]/,  // non-ws + middle + non-ws, OR single non-ws
      '*'
    )),

    // Plain text: match text up to next * (or newline)
    // When parser hits *, it tries bold first (higher precedence)
    // If bold fails, * gets included in next plain_text match
    // This achieves the bounding we want
    plain_text: $ => choice(
      /[^*\n]+/,  // Text without asterisk
      '*',        // Single asterisk (when not part of bold)
    ),
  }
});
