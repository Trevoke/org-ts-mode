; Injection queries for org (block-level) grammar
; These queries tell tree-sitter when to inject the inline grammar

; Inject org_inline grammar into headline title nodes
; This allows title content to be parsed for tags, markup, links, etc.
((title) @injection.content
  (#set! injection.language "org_inline"))
