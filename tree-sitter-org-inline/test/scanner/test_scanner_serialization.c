#include <assert.h>
#include <stdio.h>
#include <string.h>
#include "../../src/scanner.c"

int main() {
    Scanner s = {
        .last_char = 'a',
        .at_line_start = false,
        .state_flags = FLAG_IN_TAGS
    };

    char buffer[32];
    unsigned result = tree_sitter_org_inline_external_scanner_serialize(&s, buffer);

    // Should serialize 6 bytes: 4 (last_char) + 1 (at_line_start) + 1 (state_flags)
    assert(result == 6);

    // Verify buffer contents
    int32_t *last_char_ptr = (int32_t *)buffer;
    assert(*last_char_ptr == 'a');
    assert(buffer[4] == 0);  // false
    assert(buffer[5] == FLAG_IN_TAGS);

    printf("✓ Scanner serialization works correctly\n");

    // Test deserialization roundtrip
    Scanner s2;
    tree_sitter_org_inline_external_scanner_deserialize(&s2, buffer, 6);

    assert(s2.last_char == 'a');
    assert(s2.at_line_start == false);
    assert(s2.state_flags == FLAG_IN_TAGS);

    printf("✓ Scanner serialization roundtrip works\n");
    return 0;
}
