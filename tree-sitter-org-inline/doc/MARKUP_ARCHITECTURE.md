# Text Markup Architecture Analysis

## Current State: 145/165 tests (87.9%)

### What We Implemented

**External Scanner with PRE/POST Validation:**
- All 6 markup types in external scanner (bold, italic, code, verbatim, underline, strike-through)
- POST character validation working correctly
- Scanner state tracking (CONTEXT_START, CONTEXT_AFTER_SPACE, CONTEXT_AFTER_ALNUM)
- State cleanup on scanner return

### The Challenge

**Context tracking across plain_text parses:**
- Scanner tracks context accurately
- But `plain_text` is a token rule (not external), so scanner doesn't get called during plain_text parsing
- After `*bold* and /italic/`, scanner loses context during " and " parse
- Next markup delimiter seen, but scanner has stale context

### Solutions Explored

#### 1. Token-based (Current - 145/165 tests)
**Pros:** Simple, matches test structure, POST validation works
**Cons:** Can't track context across plain_text

#### 2. External plain_text
**Attempted:** Make plain_text external so scanner controls all text
**Result:** Broke grammar structure (77/165 tests)
**Issue:** Grammar expects plain_text as regular rule in choice()

#### 3. Markdown OPEN/CLOSE approach  
**Structure:**
```javascript
emphasis: $ => seq(
  $.emphasis_open,   // External - validates PRE
  $.text,           // Content
  $.emphasis_close   // External - validates POST
)
```
**Pros:** Grammar explicitly tracks context, no state needed, architecturally superior
**Cons:** Requires complete refactor, all tests need updating, more complex

### Recommendation

**For production use:**  
Adopt markdown's OPEN/CLOSE token approach. It's the correct architecture for this problem.

**Key insight from markdown:**
- Don't try to do everything in one token
- Split into open/close so grammar tracks state
- Use sentinel tokens (_last_token_whitespace) for context hints
- External scanner only validates local conditions

**Implementation path:**
1. Add separate open/close tokens to externals
2. Update grammar to use seq(open, content, close)
3. Update all test expectations
4. Scanner validates PRE on open, POST on close
5. Grammar naturally tracks context between them

**Estimated effort:** 2-3 hours, 100+ test changes

### What We Learned

1. **POST validation alone solves most problems** - Test 5 worked when we had it!
2. **State serialization works** - Context tracking proven viable
3. **External scanners can't look backward** - Need grammar cooperation
4. **Making tokens external is non-trivial** - Grammar structure matters
5. **Markdown solved this correctly** - Learn from prior art

### Current Limitations

With current architecture (145/165):
- ✅ POST validation working
- ✅ Single markup instances work  
- ✅ Markup with other objects works
- ❌ Multiple markup in sequence (context loss)
- ❌ Some cross-feature interactions

This is acceptable for 87.9% coverage but not ideal for production.
