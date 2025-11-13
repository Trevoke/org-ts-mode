# Tree-Sitter Markdown Dual-Grammar Analysis - Complete Documentation

This directory contains a comprehensive analysis of the tree-sitter-markdown dual-grammar implementation, with detailed guidance on applying these architectural patterns to org-mode grammar design.

## Documents

### 1. MARKDOWN_ARCHITECTURE_QUICK_REFERENCE.md
**Length**: ~333 lines | **Read time**: 10-15 minutes

A **concise, high-level overview** of the dual-grammar architecture. Start here if you want a quick understanding.

**Contains**:
- Core architecture decision (dual vs single grammar)
- Two-pass parsing flow with diagram
- External scanner purpose and complexity
- Key token types (~40 block, ~15 inline)
- Inline rule generation pattern
- Emphasis disambiguation algorithm
- Ten critical insights
- Implementation checklist for org-mode

**Best for**: Quick reference, presentations, onboarding

---

### 2. MARKDOWN_DUAL_GRAMMAR_ANALYSIS.md
**Length**: ~1,172 lines | **Read time**: 60-90 minutes

An **exhaustive, detailed technical analysis** of every aspect of the markdown parser.

**Sections**:
1. **Block Grammar Structure** - Document structure, block categories, external scanner tokens, design patterns
2. **Inline Grammar Structure** - Context-specific rules, emphasis rules, link types, image handling, HTML parsing
3. **Integration & Injection Points** - Two-pass parsing strategy, boundary handling, range extraction
4. **External Scanners** - Why they're necessary, block grammar scanner, inline grammar scanner, scanner state, token emission
5. **Precedence and Ambiguity** - Precedence levels, conflict resolution strategies, disambiguation examples
6. **Clever Architectural Patterns** - Two-stage tokenization, state serialization, simulation mode, bit-flag management, lazy branch creation, grammar-driven decisions, context tracking, overlapping ranges
7. **Handling Complex Inline Elements** - Code spans, emphasis, links, images, hard line breaks, HTML tags, autolinks

**Contains**:
- Complete code examples from the source
- Detailed explanations of design choices
- Architectural patterns with pros/cons
- Algorithm descriptions (emphasis, code spans, bracket matching)
- Comparison of alternatives
- Performance considerations

**Best for**: Deep technical understanding, implementation reference, pattern library

---

### 3. MARKDOWN_PATTERNS_FOR_ORG_MODE.md
**Length**: ~576 lines | **Read time**: 40-60 minutes

**Focused analysis** of which markdown patterns are applicable to org-mode, with concrete implementation suggestions.

**Sections**:
1. **Pattern 1: Dual-Grammar Architecture** - HIGHLY APPLICABLE
2. **Pattern 2: External Scanner** - HIGHLY APPLICABLE
3. **Pattern 3: Context-Specific Rules** - HIGHLY APPLICABLE
4. **Pattern 4: State Serialization** - APPLICABLE
5. **Pattern 5: Error Tokens** - HIGHLY APPLICABLE
6. **Pattern 6: Lookahead Matching** - HIGHLY APPLICABLE
7. **Pattern 7: Block Stack** - VERY HIGHLY APPLICABLE
8. **Pattern 8: Dynamic Precedence** - APPLICABLE
9. **Pattern 9: Meta-Tokens** - APPLICABLE
10. **Implementation Roadmap** - 5-phase implementation plan

**Contains**:
- Org-mode specific code examples
- Implementation strategies
- Org-specific complexity considerations
- Concrete token types for org-mode
- Phased implementation roadmap

**Best for**: Org-mode grammar design, implementation planning, decision-making

---

## Quick Navigation

### If you have 10 minutes:
→ Read **MARKDOWN_ARCHITECTURE_QUICK_REFERENCE.md**

### If you have 1 hour:
→ Read **MARKDOWN_PATTERNS_FOR_ORG_MODE.md** (focused on applicability)

### If you have 2+ hours:
→ Read **MARKDOWN_DUAL_GRAMMAR_ANALYSIS.md** (comprehensive)

### If you're implementing org-mode grammar:
→ Start with **QUICK_REFERENCE** (orientation)
→ Then **PATTERNS_FOR_ORG_MODE** (architecture decisions)
→ Reference **DUAL_GRAMMAR_ANALYSIS** (implementation details)

---

## Key Takeaways

### The Core Insight
Markdown (and org-mode) can't be parsed with a single context-free grammar because:
1. Block structure and inline content need completely different tokenization rules
2. Parsing is inherently stateful (tracking nesting, indentation, delimiter matching)
3. Lookahead is necessary for delimiter disambiguation

**Solution**: Two independent grammars with external C scanner for state management

### The Five Critical Patterns for Org-Mode

1. **Dual-Grammar Architecture**
   - Separate block and inline parsing
   - Two-pass approach with `set_included_ranges()`
   - Complete separation of concerns

2. **External C Scanner**
   - Block grammar scanner: headline/section tracking, nested structures
   - Inline grammar scanner: emphasis/code span matching
   - Stateful token emission

3. **Context-Specific Grammar Rules**
   - Generate rule variants (8 combinations for markdown, likely 4-6 for org)
   - Prevent nesting violations at grammar level
   - Eliminate parser conflicts

4. **Block Stack Management**
   - Track open structures (headlines, lists, tables, etc.)
   - Automatic closure on level change
   - O(n) processing for arbitrary nesting

5. **Error Token Branch Killing**
   - Use `$._error` for invalid parse states
   - Efficiently resolve ambiguity
   - Grammar-driven pruning

---

## Source Code References

The analysis covers:
- `/tree-sitter-markdown/grammar.js` (25KB block grammar)
- `/tree-sitter-markdown-inline/grammar.js` (21KB inline grammar)
- `/tree-sitter-markdown/src/scanner.c` (60KB block scanner)
- `/tree-sitter-markdown-inline/src/scanner.c` (16KB inline scanner)
- `/common/common.js` (6KB shared rules)
- `/bindings/rust/lib.rs` and `parser.rs` (parsing integration)

All files located in `/doc/tree-sitter-markdown-split_parser/`

---

## Applicability Assessment

### Highly Applicable (Should Implement)
- Dual-grammar architecture
- External scanner with state management
- Block stack for nested structures
- Context-specific inline rules
- Error tokens for disambiguation

### Applicable (Should Consider)
- State serialization for incremental parsing
- Lookahead for delimiter matching
- Dynamic precedence for type disambiguation

### Partially Applicable (Adapt as Needed)
- Meta-tokens for context passing
- Specific token types (adapt org-mode semantics)
- Emphasis algorithm (org-mode has different rules)

---

## Implementation Roadmap

### Phase 1: Foundation (1-2 weeks)
- [ ] Create `tree-sitter-org` repository structure
- [ ] Write block grammar skeleton
- [ ] Implement basic C scanner for headline markers

### Phase 2: Block Grammar (2-3 weeks)
- [ ] Headline level tracking
- [ ] Drawer/section state management
- [ ] Section hierarchy
- [ ] List structure with proper nesting

### Phase 3: Inline Grammar (2-3 weeks)
- [ ] Write inline grammar
- [ ] Generate context-specific rule variants
- [ ] Implement inline scanner
- [ ] Emphasis and code span matching

### Phase 4: Integration (1-2 weeks)
- [ ] Two-pass parsing implementation
- [ ] Range extraction and included_ranges
- [ ] Test with real org files

### Phase 5: Polish (1-2 weeks)
- [ ] State serialization
- [ ] Performance optimization
- [ ] Node types generation

**Total estimate**: 8-12 weeks for complete implementation

---

## Further Resources

### Official Documentation
- [Tree-Sitter Documentation](https://tree-sitter.github.io/tree-sitter/)
- [CommonMark Specification](https://spec.commonmark.org/)
- [GitHub Flavored Markdown Spec](https://github.github.com/gfm/)

### Reference Implementations
- [tree-sitter-markdown on GitHub](https://github.com/tree-sitter-grammars/tree-sitter-markdown)
- [MDeiml's markdown parser](https://github.com/MDeiml/tree-sitter-markdown)

### Related Org-Mode Resources
- [Org-Mode Manual](https://orgmode.org/manual/)
- [Org Syntax Specification](https://orgmode.org/worg/dev/org-syntax.html)

---

## Document Metadata

**Created**: 2025-11-13
**Analysis Based On**: tree-sitter-markdown split_parser branch
**Target Implementation**: org-mode tree-sitter grammar
**Total Documentation**: ~2,081 lines across 3 documents

**Key Statistics**:
- Block grammar: 25,336 bytes (612 rules)
- Inline grammar: 21,622 bytes (500+ rules)
- Block scanner: 59,240 bytes C code
- Inline scanner: 15,883 bytes C code
- ~40 block tokens, ~15 inline tokens
- 8 context-specific inline rule variants
- 3 precedence levels

---

## Questions?

If you have questions about:
- **Architecture decisions**: See DUAL_GRAMMAR_ANALYSIS section 6 (Architectural Patterns)
- **Org-mode applicability**: See PATTERNS_FOR_ORG_MODE (all sections)
- **Implementation details**: See DUAL_GRAMMAR_ANALYSIS sections 1-4
- **Quick overview**: See QUICK_REFERENCE

---

## License

This analysis is derived from the tree-sitter-markdown project, which is available under the MIT license.

The original tree-sitter-markdown project: https://github.com/tree-sitter-grammars/tree-sitter-markdown

