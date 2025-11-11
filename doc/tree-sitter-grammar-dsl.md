# Tree-sitter Grammar DSL Reference

**Sources:**
- https://tree-sitter.github.io/tree-sitter/creating-parsers/2-the-grammar-dsl.html
- https://tree-sitter.github.io/tree-sitter/creating-parsers/3-writing-the-grammar.html

## Core Principles

Tree-sitter grammars require two essential properties:

1. **Intuitive Structure**: The syntax tree should directly map to recognizable language constructs. Each node corresponds directly to a terminal or non-terminal symbol in the grammar.

2. **LR(1) Adherence**: Tree-sitter uses GLR parsing and functions most efficiently with LR(1)-compatible grammars, making them similar to Yacc/Bison but distinct from ANTLR or PEG approaches.

## Grammar Structure

A tree-sitter grammar is defined in `grammar.js` and exports an object with:

```javascript
module.exports = grammar({
  name: 'language_name',

  rules: {
    // Your grammar rules
  },

  // Optional configuration
  extras: $ => [/* ... */],
  inline: $ => [/* ... */],
  conflicts: $ => [/* ... */],
  externals: $ => [/* ... */],
  precedences: $ => [/* ... */],
  word: $ => /* ... */,
  supertypes: $ => [/* ... */],
  reserved: $ => [/* ... */]
});
```

## Core DSL Functions

### Symbols and References

**`$` Object**: References grammar symbols
- Example: `$.identifier`, `$.expression`

**Terminal Symbols**:
- JavaScript strings: `"if"`, `"function"`
- Regular expressions: `/[a-z]+/`, `/\d+/`
- Rust regex syntax via `RustRegex` class for advanced patterns

### Sequence

**`seq(rule1, rule2, ...)`**

Matches rules one after another (like concatenation in EBNF).

```javascript
function_call: $ => seq(
  $.identifier,
  '(',
  $.arguments,
  ')'
)
```

### Alternatives

**`choice(rule1, rule2, ...)`**

Matches one rule from a set (like `|` in EBNF). Order is irrelevant.

```javascript
expression: $ => choice(
  $.number,
  $.string,
  $.identifier,
  $.binary_expression
)
```

### Repetition

**`repeat(rule)`**

Matches zero or more occurrences.

```javascript
statements: $ => repeat($.statement)
```

**`repeat1(rule)`**

Matches one or more occurrences.

```javascript
arguments: $ => repeat1($.argument)
```

### Optional

**`optional(rule)`**

Matches zero or one occurrence.

```javascript
function_definition: $ => seq(
  'function',
  $.identifier,
  optional($.type_annotation),
  $.block
)
```

## Precedence and Associativity

### Basic Precedence

**`prec(number, rule)`**

Marks the rule with numerical precedence to resolve LR(1) conflicts. Higher numbers bind tighter.

```javascript
binary_expression: $ => choice(
  prec(2, seq($.expression, '*', $.expression)),
  prec(1, seq($.expression, '+', $.expression))
)
```

### Left Associativity

**`prec.left([number], rule)`**

Marks rule as left-associative (prefers matching rules ending earlier).

```javascript
binary_expression: $ => choice(
  prec.left(2, seq($.expression, '*', $.expression)),
  prec.left(1, seq($.expression, '+', $.expression))
)
```

For `a + b + c`, this produces `(a + b) + c`.

### Right Associativity

**`prec.right([number], rule)`**

Marks rule as right-associative (prefers matching rules ending later).

```javascript
assignment: $ => prec.right(seq(
  $.identifier,
  '=',
  $.expression
))
```

For `a = b = c`, this produces `a = (b = c)`.

### Dynamic Precedence

**`prec.dynamic(number, rule)`**

Applied at runtime rather than generation time. Useful for resolving ambiguities that can't be determined statically.

```javascript
expression: $ => choice(
  prec.dynamic(1, $.array_access),
  prec.dynamic(0, $.array_literal)
)
```

## Token Functions

### Tokens

**`token(rule)`**

Treats complex rules as a single token without whitespace separation.

```javascript
string: $ => token(seq(
  '"',
  repeat(/[^"]/),
  '"'
))
```

### Immediate Tokens

**`token.immediate(rule)`**

Matches only when no preceding whitespace exists.

```javascript
property_access: $ => seq(
  $.expression,
  token.immediate('.'),
  $.property_name
)
```

## Tree Modification

### Aliases

**`alias(rule, name)`**

Makes rules appear with alternative names in the syntax tree.

```javascript
statement: $ => choice(
  alias($.expression_statement, 'expression'),
  $.if_statement,
  $.return_statement
)
```

### Field Names

**`field(name, rule)`**

Assigns field names for accessing specific child nodes programmatically.

```javascript
function_definition: $ => seq(
  'func',
  field('name', $.identifier),
  field('parameters', $.parameter_list),
  field('body', $.block)
)
```

### Reserved Keywords

**`reserved(wordset, rule)`**

Overrides global reserved word sets for contextual keywords.

## Grammar Configuration Options

### `extras`

Tokens that can appear anywhere in the grammar (typically whitespace and comments).

```javascript
extras: $ => [
  /\s/,
  $.comment
]
```

**Best practice**: Define complicated extras as rules rather than inline tokens to reduce parser size.

### `inline`

Rules removed by replacing usages with their definitions. Use for wrapper rules that add no semantic value.

```javascript
inline: $ => [
  '_expression',
  '_statement'
]
```

### `conflicts`

Explicitly declares acceptable ambiguities that will use GLR parsing.

```javascript
conflicts: $ => [
  [$.array_literal, $.array_pattern]
]
```

### `externals`

Tokens provided by external scanners (C code) for complex lexical analysis.

```javascript
externals: $ => [
  $.indent,
  $.dedent,
  $.newline
]
```

### `precedences`

Named precedence levels for documentation and maintainability.

```javascript
precedences: $ => [
  ['member', 'call', 'unary', 'binary', 'ternary']
]
```

### `word`

Token used to identify keywords. Tree-sitter extracts keywords matching this pattern.

```javascript
word: $ => $.identifier
```

**Critical**: This enables proper keyword handling, preventing issues where `instanceof` followed by letters incorrectly tokenizes as a single identifier.

### `supertypes`

Abstract node categories without generating visible nodes, but remain queryable.

```javascript
supertypes: $ => [
  '_expression',
  '_statement',
  '_declaration'
]
```

### `reserved`

Contextual keyword sets for different parsing contexts.

```javascript
reserved: {
  javascript: ['if', 'else', 'function'],
  typescript: ['interface', 'type', 'namespace']
}
```

## Grammar Development Strategy

### Start with a Skeleton

Begin with a breadth-first skeleton covering major categories:
- Declarations
- Definitions
- Statements
- Expressions
- Types
- Patterns

The first rule in your `rules` object becomes the grammar's start rule.

### Structuring Best Practices

**Avoid direct specification translation**: Language specifications often use many intermediate precedence levels that create unnecessarily deep trees. Instead, use flatter structures with precedence rules to manage ambiguity.

**Standard rule names**:
- `source_file`: Root node
- `expression`/`statement`: Choice between subtypes
- `block`: Block scope container
- `identifier`: Variable/function names
- `comment`: Typically marked as an extra

### Rule Hiding

Prefix rules with underscores (`_expression`) to hide them from the syntax tree, reducing noise from wrapper rules.

```javascript
_expression: $ => choice(
  $.binary_expression,
  $.unary_expression,
  $.primary_expression
),

primary_expression: $ => choice(
  $.identifier,
  $.number,
  $.string
)
```

## Lexical Analysis

### Token Conflict Resolution

Tree-sitter uses this hierarchy:

1. **Context-aware lexing**: Only valid tokens at current position
2. **Explicit lexical precedence**: `token(prec(N, ...))`
3. **Match length**: Longest sequence wins
4. **Match specificity**: Strings preferred over regexes
5. **Rule order**: First match in grammar

**Critical distinction**: Lexical precedence (token selection) differs from parse precedence (rule interpretation).

### Keyword Handling

Specify a `word` token to enable keyword extraction. Tree-sitter identifies keywords matching the word pattern and processes them as a two-step sequence.

```javascript
module.exports = grammar({
  name: 'my_language',

  word: $ => $.identifier,

  rules: {
    identifier: $ => /[a-z]+/,

    keyword_statement: $ => seq(
      choice('if', 'while', 'for'),
      $.expression
    )
  }
});
```

## Testing

Always add tests for new rules in your `test/corpus` folder:

```
==================
Function definition
==================

func add(a, b) {
  return a + b
}

---

(source_file
  (function_definition
    name: (identifier)
    parameters: (parameter_list
      (parameter (identifier))
      (parameter (identifier)))
    body: (block
      (return_statement
        (binary_expression
          left: (identifier)
          right: (identifier))))))
```

Validate progress using:
```bash
tree-sitter test
tree-sitter parse examples/sample.code
```

## Common Patterns

### List with Separators

```javascript
arguments: $ => seq(
  $.expression,
  repeat(seq(',', $.expression))
)

// Or with optional trailing comma
arguments: $ => seq(
  $.expression,
  repeat(seq(',', $.expression)),
  optional(',')
)
```

### List with Delimiters

```javascript
array: $ => seq(
  '[',
  optional(seq(
    $.expression,
    repeat(seq(',', $.expression))
  )),
  ']'
)
```

### Operator Precedence

```javascript
_expression: $ => choice(
  $.binary_expression,
  $.unary_expression,
  $.primary_expression
),

binary_expression: $ => choice(
  prec.left(10, seq($.expression, '*', $.expression)),
  prec.left(10, seq($.expression, '/', $.expression)),
  prec.left(9, seq($.expression, '+', $.expression)),
  prec.left(9, seq($.expression, '-', $.expression)),
  prec.left(4, seq($.expression, '==', $.expression)),
  prec.left(3, seq($.expression, '&&', $.expression)),
  prec.left(2, seq($.expression, '||', $.expression))
),

unary_expression: $ => choice(
  prec(11, seq('-', $.expression)),
  prec(11, seq('!', $.expression))
)
```

## Tips and Tricks

1. **Keep it simple**: Start with the simplest grammar that parses correctly, then refine
2. **Test frequently**: Add corpus tests as you develop
3. **Use real code**: Test with actual code samples from the wild
4. **Profile performance**: Use `tree-sitter parse --debug` to understand parsing behavior
5. **Minimize conflicts**: Each conflict in the `conflicts` array increases parser complexity
6. **Hide intermediate rules**: Use `_` prefix for structural rules that don't need visibility
7. **Name fields**: Field names make queries much easier to write
8. **Document precedence**: Use comments to explain precedence decisions

## Example Complete Grammar

```javascript
module.exports = grammar({
  name: 'simple_lang',

  word: $ => $.identifier,

  extras: $ => [
    /\s/,
    $.comment
  ],

  rules: {
    source_file: $ => repeat($._statement),

    _statement: $ => choice(
      $.expression_statement,
      $.if_statement,
      $.return_statement
    ),

    expression_statement: $ => seq(
      $._expression,
      ';'
    ),

    if_statement: $ => seq(
      'if',
      field('condition', $._expression),
      field('consequence', $.block),
      optional(seq('else', field('alternative', $.block)))
    ),

    return_statement: $ => seq(
      'return',
      optional($._expression),
      ';'
    ),

    block: $ => seq(
      '{',
      repeat($._statement),
      '}'
    ),

    _expression: $ => choice(
      $.identifier,
      $.number,
      $.string,
      $.binary_expression,
      $.call_expression
    ),

    binary_expression: $ => choice(
      prec.left(2, seq($._expression, '*', $._expression)),
      prec.left(1, seq($._expression, '+', $._expression))
    ),

    call_expression: $ => prec('call', seq(
      field('function', $._expression),
      '(',
      optional(field('arguments', $.arguments)),
      ')'
    )),

    arguments: $ => seq(
      $._expression,
      repeat(seq(',', $._expression))
    ),

    identifier: $ => /[a-zA-Z_][a-zA-Z0-9_]*/,

    number: $ => /\d+/,

    string: $ => seq(
      '"',
      repeat(/[^"]/),
      '"'
    ),

    comment: $ => token(seq(
      '//',
      /.*/
    ))
  }
});
```
