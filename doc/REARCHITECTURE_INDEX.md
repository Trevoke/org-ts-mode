# Inline Grammar Rearchitecture Documentation Index

Welcome! This directory contains comprehensive planning documents for rearchitecting the org-mode tree-sitter inline grammar.

---

## Quick Start: Where to Begin?

**If you want...**

### 📋 A quick overview (10 minutes)
**Start here**: [INLINE_REARCHITECTURE_EXECUTIVE_SUMMARY.md](INLINE_REARCHITECTURE_EXECUTIVE_SUMMARY.md)
- High-level overview
- Key problems and solutions
- Estimated timeline and effort
- Recommendation

### 🔍 Visual comparison (15 minutes)
**Read this**: [CURRENT_VS_PROPOSED_ARCHITECTURE.md](CURRENT_VS_PROPOSED_ARCHITECTURE.md)
- Side-by-side diagrams
- Current vs. proposed architecture
- Scanner comparison
- Grammar comparison
- Object coverage comparison

### 📖 Complete technical plan (60+ minutes)
**Deep dive**: [INLINE_GRAMMAR_REARCHITECTURE_PLAN.md](INLINE_GRAMMAR_REARCHITECTURE_PLAN.md)
- Complete technical specifications
- Implementation phases (12 weeks)
- Scanner architecture
- Grammar structure
- Testing strategy
- Risk assessment

### 🎓 Learn from markdown's approach (40 minutes)
**Background reading**:
- [MARKDOWN_ARCHITECTURE_QUICK_REFERENCE.md](MARKDOWN_ARCHITECTURE_QUICK_REFERENCE.md) - Concise overview
- [MARKDOWN_PATTERNS_FOR_ORG_MODE.md](MARKDOWN_PATTERNS_FOR_ORG_MODE.md) - Applicability assessment
- [MARKDOWN_DUAL_GRAMMAR_ANALYSIS.md](MARKDOWN_DUAL_GRAMMAR_ANALYSIS.md) - Exhaustive deep-dive

---

## Document Summaries

### 1. Executive Summary
**File**: [INLINE_REARCHITECTURE_EXECUTIVE_SUMMARY.md](INLINE_REARCHITECTURE_EXECUTIVE_SUMMARY.md)
**Length**: ~15 pages
**Read time**: 10 minutes

**Contents**:
- The Problem (6 critical issues)
- The Solution (9 proven patterns from markdown)
- Proposed Architecture (overview)
- Key Architectural Decisions
- Implementation Plan (8 phases, 12 weeks)
- Success Metrics
- Risks & Mitigation
- Recommendation

**Best for**: Decision makers, quick overview

---

### 2. Visual Comparison
**File**: [CURRENT_VS_PROPOSED_ARCHITECTURE.md](CURRENT_VS_PROPOSED_ARCHITECTURE.md)
**Length**: ~20 pages
**Read time**: 15 minutes

**Contents**:
- Architecture diagrams (current vs. proposed)
- Scanner comparison (code snippets)
- Grammar comparison (code snippets)
- Injection points comparison
- Object coverage tables
- Test coverage comparison
- Summary: Why rearchitect?

**Best for**: Visual learners, understanding changes

---

### 3. Complete Technical Plan
**File**: [INLINE_GRAMMAR_REARCHITECTURE_PLAN.md](INLINE_GRAMMAR_REARCHITECTURE_PLAN.md)
**Length**: ~60+ pages
**Read time**: 60+ minutes

**Contents**:
1. Current State Analysis
   - What works
   - What's broken/missing
2. Critical Issues Identified
   - Scanner limitations
   - Injection point issues
   - Duplicate implementations
3. Architectural Patterns from Markdown
   - 5 critical patterns
4. Proposed Architecture
   - Complete overview
   - Key architectural decisions
5. Implementation Phases
   - Phase 0: Preparation (Week 1)
   - Phase 1: Context-Specific Rules (Weeks 2-3)
   - Phase 2: Scanner Rearchitecture (Weeks 4-5)
   - Phase 3: Move Inline Objects (Week 6)
   - Phase 4: Expand Injection Points (Week 7)
   - Phase 5: Implement Missing Objects (Weeks 8-9)
   - Phase 6: Systematic Precedence (Week 10)
   - Phase 7: Performance Optimization (Week 11)
   - Phase 8: Testing & Documentation (Week 12)
6. Technical Specifications
   - Token types
   - Scanner structure
   - Grammar structure
7. Migration Strategy
   - Breaking changes
   - Migration steps
   - Compatibility period
8. Testing Strategy
   - Test categories
   - Test organization
   - Coverage goals
9. Risk Assessment
   - High/medium/low risks
   - Mitigation strategies
10. Success Metrics

**Best for**: Implementers, detailed planning

---

### 4. Markdown Architecture Analysis
**File**: [MARKDOWN_DUAL_GRAMMAR_ANALYSIS.md](MARKDOWN_DUAL_GRAMMAR_ANALYSIS.md)
**Length**: ~40 pages
**Read time**: 60-90 minutes

**Contents**:
- Complete analysis of tree-sitter-markdown
- Block grammar structure
- Inline grammar structure
- External scanners
- Precedence handling
- 8 clever architectural patterns

**Best for**: Understanding markdown's proven approach

---

### 5. Markdown Quick Reference
**File**: [MARKDOWN_ARCHITECTURE_QUICK_REFERENCE.md](MARKDOWN_ARCHITECTURE_QUICK_REFERENCE.md)
**Length**: ~10 pages
**Read time**: 15 minutes

**Contents**:
- Core architecture decision
- Why two grammars?
- Two-pass parsing flow
- External scanner overview
- Key token types
- Ten critical insights

**Best for**: Quick understanding of markdown patterns

---

### 6. Markdown Patterns for Org-Mode
**File**: [MARKDOWN_PATTERNS_FOR_ORG_MODE.md](MARKDOWN_PATTERNS_FOR_ORG_MODE.md)
**Length**: ~15 pages
**Read time**: 40 minutes

**Contents**:
- Applicability assessment of 9 patterns
- Org-mode specific implementation strategies
- Concrete token types for org-mode
- 5-phase implementation roadmap

**Best for**: Understanding how to apply markdown patterns to org-mode

---

## Key Findings Summary

### Current State
- ✅ Dual-grammar foundation in place
- ✅ 121/121 tests passing for implemented features
- ✅ Basic text markup, links, entities working
- ❌ Only ~35% of inline content parsed (titles only)
- ❌ 6 critical inline objects missing
- ❌ 4 objects duplicated in both grammars
- ❌ Scanner architectural limitations

### Proposed Solution
- ✅ Expand injection points to ALL inline contexts (paragraphs, tables, lists)
- ✅ Implement all 17 inline object types (100% coverage)
- ✅ Context-specific grammar rules (prevent invalid nesting)
- ✅ Lookahead-based scanner (validate before parsing)
- ✅ Systematic precedence hierarchy
- ✅ Move duplicates to inline grammar (clean separation)
- **Result**: 35% → 90%+ coverage

### Timeline & Effort
- **Duration**: 12 weeks (8 phases)
- **Effort**: 300-400 hours
- **Impact**: Transforms grammar from partial to complete

### Recommendation
**Proceed with rearchitecture**
- Current limitations can't be fixed incrementally
- Markdown's patterns are proven and directly applicable
- Benefits far outweigh costs

---

## Critical Issues Identified

### Issue 1: Limited Injection Points (CRITICAL)
**Current**: Only injected into `title` nodes
**Impact**: 80% of inline content NOT parsed
**Solution**: Expand to paragraphs, table cells, list items, verse blocks

### Issue 2: Duplicate Implementations (MAJOR)
**Current**: LaTeX fragments, timestamps, footnotes, subscript/superscript in BOTH grammars
**Impact**: Conflicts, maintenance burden
**Solution**: Move all to inline grammar, remove from block

### Issue 3: Scanner Limitations (MAJOR)
**Current**: Can't validate stateful patterns, no lookahead, boundary issues
**Impact**: False positives, incomplete validation
**Solution**: Rearchitect scanner with lookahead and state management

### Issue 4: Missing Objects (HIGH)
**Current**: 6 critical objects not implemented
**Impact**: Can't parse citations, line breaks, inline code, radio links
**Solution**: Implement all 17 object types

### Issue 5: No Context-Specific Rules (ARCHITECTURAL)
**Current**: Grammar allows invalid nesting
**Impact**: Links in links, markup in code
**Solution**: Generate 6-8 context variants

### Issue 6: Ad-Hoc Precedence (MODERATE)
**Current**: No systematic hierarchy
**Impact**: Hard to extend, conflicts unclear
**Solution**: Define precedence constants

---

## Next Steps

1. **Review these documents**
   - Start with Executive Summary
   - Read Visual Comparison
   - Deep dive into Technical Plan as needed

2. **Gather feedback**
   - Share with stakeholders
   - Get community input
   - Address concerns

3. **Make decision**
   - Proceed with rearchitecture?
   - Timeline acceptable?
   - Breaking changes manageable?

4. **If proceeding**:
   - Create tracking issue
   - Create feature branch: `rearchitect-inline-grammar`
   - Begin Phase 0: Preparation

---

## Questions?

If you have questions about:
- **Architecture**: See [Technical Plan](INLINE_GRAMMAR_REARCHITECTURE_PLAN.md) § Proposed Architecture
- **Timeline**: See [Executive Summary](INLINE_REARCHITECTURE_EXECUTIVE_SUMMARY.md) § Implementation Plan
- **Breaking changes**: See [Technical Plan](INLINE_GRAMMAR_REARCHITECTURE_PLAN.md) § Migration Strategy
- **Risks**: See [Executive Summary](INLINE_REARCHITECTURE_EXECUTIVE_SUMMARY.md) § Risks & Mitigation
- **Markdown patterns**: See [Markdown Quick Reference](MARKDOWN_ARCHITECTURE_QUICK_REFERENCE.md)
- **Current issues**: See [Visual Comparison](CURRENT_VS_PROPOSED_ARCHITECTURE.md) § Problems with Current Architecture

---

## Related Documentation

In this directory (`/home/user/org-ts-mode.el/doc/`):
- `org-syntax.md` - Complete org syntax specification
- `markdown-spec.md` - Markdown spec for reference
- `tree-sitter-markdown-split_parser/` - Full markdown implementation
- `SYNTAX_COVERAGE.md` - Current syntax coverage matrix
- `README.md` - Project README (in parent directory)

---

**Last Updated**: 2025-11-13
**Status**: Planning phase
**Next Review**: After stakeholder feedback
