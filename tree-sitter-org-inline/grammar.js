/**
 * @file Phase 3: Adding underline, subscript, superscript
 * @author Org-TS-Mode Contributors
 * @license MIT
 *
 * KEY INSIGHT: No scanner needed! These patterns have different starting chars:
 * - Bold: starts with *
 * - Underline: starts with _
 * - Subscript: starts with alphanumeric (BASE)
 * - Superscript: starts with alphanumeric (BASE)
 *
 * All use token() for atomic matching, following Phase 2 success pattern.
 *
 * "Underline takes priority" is automatically satisfied because underline
 * starts with _ while subscript starts with alphanumeric - no conflict!
 *
 * Phase 3 Progress:
 * - [x] Bold: *text*
 * - [x] Underline: _text_
 * - [x] Subscript: BASE_SCRIPT
 * - [x] Superscript: BASE^SCRIPT
 */

/// <reference types="tree-sitter-cli/dsl" />
// @ts-check

module.exports = grammar({
  name: 'org_inline',

  extras: $ => ['\n'],

  rules: {
    inline: $ => $.title,

    // Title can contain markup or plain text
    // Precedence groups by starting character:
    // - prec(3): *-patterns (bold) and _-patterns (underline)
    // - prec(2): alphanumeric-patterns (subscript, superscript)
    // - prec(1): plain_text fallback
    title: $ => repeat1(choice(
      prec(3, $.bold),
      prec(3, $.underline),
      prec(2, $.subscript),
      prec(2, $.superscript),
      prec(1, $.plain_text),
    )),

    // Bold: *content*
    bold: $ => token(seq(
      '*',
      /[^\s*][^*\n]*[^\s*]|[^\s*\n]/,
      '*'
    )),

    // Underline: _content_
    // Same pattern as bold, but with underscore delimiters
    underline: $ => token(seq(
      '_',
      /[^\s_][^_\n]*[^\s_]|[^\s_\n]/,  // non-ws + middle + non-ws, OR single non-ws
      '_'
    )),

    // Subscript: BASE_SCRIPT
    // BASE: one or more alphanumeric
    // SCRIPT: per org-mode spec (asterisk, braced, or SIGN CHARS FINAL)
    subscript: $ => token(seq(
      /[a-zA-Z0-9]+/,  // BASE
      '_',
      choice(
        '*',                                            // Single asterisk
        seq('{', /[^}\n]+/, '}'),                      // Braced expression
        seq('(', /[^)\n]+/, ')'),                      // Parenthesized expression
        /[+-]?[a-zA-Z0-9,.\\]*[a-zA-Z0-9]/             // SIGN CHARS FINAL
      )
    )),

    // Superscript: BASE^SCRIPT
    // Same pattern as subscript but with caret
    superscript: $ => token(seq(
      /[a-zA-Z0-9]+/,  // BASE
      '^',
      choice(
        '*',
        seq('{', /[^}\n]+/, '}'),
        seq('(', /[^)\n]+/, ')'),
        /[+-]?[a-zA-Z0-9,.\\]*[a-zA-Z0-9]/
      )
    )),

    // Plain text: matches everything that's not markup
    // Must stop at delimiter start positions to give markup a chance
    plain_text: $ => choice(
      /[^a-zA-Z0-9*_^\n]+/,  // Non-alphanumeric (spaces, punctuation, etc.)
      /[a-zA-Z0-9]+/,        // Alphanumeric words (when not subscript/superscript)
      '*',                   // Solo * (when not forming bold)
      '_',                   // Solo _ (when not forming underline/subscript)
      '^',                   // Solo ^ (when not forming superscript)
    ),
  }
});
