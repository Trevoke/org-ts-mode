# Inline Grammar Rearchitecture: Executive Summary

**Date**: 2025-11-13
**Status**: Planning
**Estimated Timeline**: 12 weeks
**Estimated Effort**: 300-400 hours

---

## The Problem

Your current inline grammar implementation has a **solid foundation** but is **fundamentally incomplete and architecturally limited**:

### What's Working ✅
- Dual-grammar architecture in place
- 121/121 tests passing for implemented features
- Title/tag separation working
- Basic text markup (bold, italic, underline, code, verbatim, strike)
- Links (regular, angle, plain)
- Basic inline objects (entities, macros, targets, footnotes, timestamps, subscript/superscript)

### What's Broken ❌

**1. Limited Injection Points** (CRITICAL)
- Inline grammar only injected into `title` nodes
- **80% of inline content NOT PARSED**: paragraphs, table cells, list items all ignored
- Users don't get syntax highlighting/navigation in most contexts

**2. Duplicate Implementations** (MAJOR)
- LaTeX fragments exist in BOTH block and inline grammars
- Timestamps in both grammars
- Subscript/superscript in both grammars
- Creates conflicts, maintenance burden

**3. Scanner Architecture Flaws** (MAJOR)
- Scanner can't validate stateful patterns (TSLexer API limitation)
- Can't mark boundaries after lookahead (line 184 comment: "This is a problem")
- Keyword detection incomplete (lines 348-377) - uses heuristics instead of validation
- List indentation uses heuristics instead of proper tracking

**4. Missing 6 Critical Inline Objects** (HIGH)
- ❌ Line breaks (`\\`)
- ❌ Citations (`[cite:@key]`) - Org 9.5+
- ❌ Citation references
- ❌ Inline babel calls (`call_NAME(ARGS)`)
- ❌ Inline source blocks (`src_LANG{BODY}`)
- ❌ Radio links (automatic links to radio targets)

**5. No Context-Specific Rules** (ARCHITECTURAL)
- Grammar allows invalid nesting (links in links, markup in code)
- Relies on precedence resolution instead of prevention
- Leads to ambiguity, conflicts, bugs

**6. Ad-Hoc Precedence** (MODERATE)
- No systematic hierarchy
- Hard to extend
- Conflicts not well-defined

---

## The Solution: Learn from Markdown

Tree-sitter-markdown has **solved all these problems**. We analyzed their implementation and identified **9 critical patterns**:

### Pattern 1: Context-Specific Rules (CRITICAL)
**Markdown approach**: Generate 8 variants of inline rules to prevent invalid nesting at grammar level

```javascript
// Instead of allowing everything everywhere:
_inline_element = [$.link, $.emphasis, $.code, ...]

// Generate context-specific variants:
_inline_element_no_link = [$.emphasis, $.code, ...]  // Inside links
_inline_element_no_markup = [$.text]                 // Inside code
_inline_element_in_link = [restricted set]           // Inside link description
```

**Benefit**: Eliminates conflicts by preventing them, not resolving them

### Pattern 2: Scanner with Lookahead (CRITICAL)
**Markdown approach**: Before emitting opening delimiter, scanner looks ahead for matching closing

```c
// Before emitting CODE_SPAN_START:
scan_code_span(scanner, lexer) {
    size_t level = count_backticks(lexer);

    // Look ahead for matching closing backticks
    while (!eof) {
        if (found_matching_closing(lexer, level)) {
            emit(CODE_SPAN_START);
            return true;
        }
    }

    return false;  // No match, not a code span
}
```

**Benefit**: Only parse valid constructs, avoid backtracking

### Pattern 3: Block Stack for Nesting (CRITICAL)
**Markdown approach**: Maintain stack of open blocks, close when no longer valid

```c
typedef struct {
    Block open_blocks[20];  // Stack of nested containers
    size_t count;
} Scanner;

// At each newline:
for (int i = 0; i < scanner->count; i++) {
    if (!can_continue_block(scanner->blocks[i], lexer)) {
        emit(BLOCK_CLOSE);
        pop_block(scanner);
    }
}
```

**Benefit**: Handles nested structures cleanly

### Pattern 4: Error Tokens for Branch Killing (IMPORTANT)
**Markdown approach**: Emit ERROR token to kill invalid parse branches

```javascript
seq(
    $._soft_line_break,
    optional(seq($._soft_line_break, $._trigger_error))  // Kill invalid branch
)
```

**Benefit**: Efficient disambiguation

### Pattern 5: Systematic Precedence (IMPORTANT)
**Markdown approach**: Define precedence hierarchy with constants

```javascript
const PRECEDENCE_EMPHASIS = 1;
const PRECEDENCE_LINK = 10;
const PRECEDENCE_HTML = 100;

emphasis: $ => prec.dynamic(PRECEDENCE_EMPHASIS, ...),
link: $ => prec.dynamic(PRECEDENCE_LINK, ...),
```

**Benefit**: Clear, extensible precedence system

---

## Proposed Architecture

```
┌─────────────────────────────────────────────┐
│         Org Document Input                  │
└─────────────────────────────────────────────┘
                    ↓
┌─────────────────────────────────────────────┐
│  PASS 1: Block Grammar (org-structure)      │
│  - Parse headlines (opaque titles)          │
│  - Parse blocks, lists, tables              │
│  - Create injection nodes:                  │
│    • headline_title                         │
│    • paragraph_content                      │
│    • table_cell_content                     │
│    • list_item_content                      │
└─────────────────────────────────────────────┘
                    ↓
              Block Parse Tree
                    ↓
┌─────────────────────────────────────────────┐
│  PASS 2: Inline Grammar (org-inline) - NEW │
│  - Context-specific rules (6-8 variants)    │
│  - Lookahead-based delimiter matching       │
│  - All 17 inline object types:              │
│    ✓ Text markup (6 types)                  │
│    ✓ Links (4 types)                        │
│    ✓ Citations (NEW)                        │
│    ✓ Line breaks (NEW)                      │
│    ✓ Inline babel calls (NEW)               │
│    ✓ Inline source blocks (NEW)             │
│    ✓ Radio links (NEW)                      │
│    ✓ ... and 12 existing types              │
└─────────────────────────────────────────────┘
                    ↓
        Inline Parse Trees (one per injection)
                    ↓
┌─────────────────────────────────────────────┐
│      Combined AST (Final Output)            │
│  - Block structure + inline content         │
│  - Full semantic representation             │
└─────────────────────────────────────────────┘
```

---

## Key Architectural Decisions

### Decision 1: Move ALL Inline Objects to Inline Grammar
**What**: Remove LaTeX fragments, timestamps, footnote references, subscript/superscript from block grammar
**Why**: Clean separation of concerns, no duplication
**Impact**: Breaking change, but cleaner architecture

### Decision 2: Expand Injection Points to All Contexts
**What**: Inject inline grammar into paragraphs, table cells, list items, not just titles
**Why**: Parse inline content everywhere, not just headlines
**Impact**: 80% of content will now be properly parsed

### Decision 3: Implement 6-8 Context-Specific Rules
**What**: Generate variants like `_inline_element_no_link`, `_inline_element_no_markup`
**Why**: Prevent invalid nesting at grammar level
**Impact**: Eliminates conflicts, cleaner parse trees

### Decision 4: Rearchitect Scanner with Lookahead
**What**: Scanner validates matching delimiters before emitting opening tokens
**Why**: Only parse valid constructs, avoid backtracking
**Impact**: More robust parsing, fewer errors

### Decision 5: Systematic Precedence Hierarchy
**What**: Define precedence constants (EMPHASIS=1, LINK=10, CITATION=20, etc.)
**Why**: Clear, extensible precedence system
**Impact**: Easy to add new objects, well-defined conflicts

### Decision 6: Implement 6 Missing Objects
**What**: Add line breaks, citations, citation references, inline babel calls, inline source blocks, radio links
**Why**: Complete org syntax coverage
**Impact**: 35% → 90%+ inline coverage

---

## Implementation Plan: 8 Phases, 12 Weeks

### Phase 0: Preparation (Week 1)
- Document current state ✅ (done - this plan)
- Create feature branch
- Audit test suite
- Set up benchmarking

### Phase 1: Context-Specific Rules (Weeks 2-3)
- Implement rule generation helpers
- Define 6-8 context variants
- Update existing rules
- Test nesting restrictions

### Phase 2: Scanner Rearchitecture (Weeks 4-5)
- Implement lookahead-based delimiter matching
- Implement link bracket matching
- Refactor tag validation
- Implement state serialization

### Phase 3: Move Inline Objects (Week 6)
- Audit duplicate objects
- Move to inline grammar
- Remove from block grammar
- Update tests

### Phase 4: Expand Injection Points (Week 7)
- Update block grammar (create injection nodes)
- Update injection queries
- Test two-pass parsing

### Phase 5: Implement Missing Objects (Weeks 8-9)
- Line breaks, citations, radio links (Week 8)
- Inline babel calls, inline source blocks (Week 9)

### Phase 6: Systematic Precedence (Week 10)
- Define precedence constants
- Apply to all rules
- Test precedence resolution

### Phase 7: Performance Optimization (Week 11)
- Benchmark
- Profile bottlenecks
- Optimize hot paths

### Phase 8: Testing & Documentation (Week 12)
- Expand test suite (300+ tests)
- Update documentation
- Community review

---

## Success Metrics

**Quantitative**:
- ✅ Syntax coverage: 35% → 90%+ (17/17 inline object types)
- ✅ Test coverage: 121 → 300+ tests
- ✅ Performance: < 2x current parse time
- ✅ Error rate: < 1% on real-world files

**Qualitative**:
- ✅ Clean architecture (no duplication)
- ✅ Maintainable code (easy to extend)
- ✅ Community feedback (positive reception)

---

## Risks & Mitigation

### High Risk: Performance degradation
- **Mitigation**: Benchmark continuously, optimize hot paths, consider lazy parsing

### High Risk: Breaking changes too disruptive
- **Mitigation**: Migration guide, migration scripts, beta period, clear communication

### Medium Risk: Scanner complexity leads to bugs
- **Mitigation**: Comprehensive tests, fuzzing, careful code review, documentation

---

## Recommendation

**Proceed with rearchitecture**:
1. The current architecture has fundamental limitations that can't be fixed incrementally
2. Markdown's patterns are proven and directly applicable
3. The migration path is clear and manageable
4. The benefits (90%+ coverage, clean architecture) far outweigh the costs (12 weeks, breaking changes)

**Alternative**: Don't rearchitect
- ❌ Stuck at 35% inline coverage
- ❌ Duplicate implementations remain
- ❌ Scanner limitations persist
- ❌ Can't add missing objects cleanly

**Next Steps**:
1. Review this plan with stakeholders
2. Get community feedback
3. Create tracking issue
4. Begin Phase 0 (create branch, audit tests)

---

## Questions to Consider

1. **Breaking changes**: Are you willing to make breaking changes for a better architecture?
   - **Recommendation**: Yes - provide migration guide and clear communication

2. **Timeline**: Is 12 weeks acceptable?
   - **Alternative**: Can be done faster with more focused effort, or slower with part-time work

3. **Third subgrammar**: Do we need a third grammar for specific contexts?
   - **Current assessment**: No - 6-8 context variants in inline grammar should suffice
   - **Revisit**: If we find edge cases that need separate grammar

4. **Scanner complexity**: Should we simplify scanner or embrace complexity?
   - **Recommendation**: Embrace complexity - it's necessary for robust parsing
   - **Markdown has 1000+ line scanner** - this is normal for complex markup

5. **Integration testing**: How do we ensure block + inline integration works?
   - **Recommendation**: Follow markdown's approach - they've solved this
   - **Test with real-world org files** (100+ files)

---

## Conclusion

The inline grammar needs a **comprehensive rearchitecture**, not incremental fixes. The current architecture has fundamental limitations:
- Limited injection points (80% of content not parsed)
- Duplicate implementations
- Scanner architecture flaws
- Missing critical objects

Markdown has solved all these problems with proven patterns. We should adopt their approach:
- Context-specific rules (prevent conflicts)
- Lookahead-based scanning (validate before parsing)
- Systematic precedence (clear hierarchy)
- Expand injection points (parse all inline content)

**Timeline**: 12 weeks
**Effort**: 300-400 hours
**Impact**: 35% → 90%+ inline coverage, clean architecture, maintainable code

**Recommendation**: Proceed with rearchitecture.

---

**For detailed technical specifications, see**: [INLINE_GRAMMAR_REARCHITECTURE_PLAN.md](INLINE_GRAMMAR_REARCHITECTURE_PLAN.md)
