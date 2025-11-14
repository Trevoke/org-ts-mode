#include <assert.h>
#include <stdio.h>
#include "../../src/scanner.c"  // Include scanner implementation

int main() {
    Scanner s;
    size_t size = sizeof(Scanner);

    printf("Scanner state size: %zu bytes\n", size);

    // After Phase 2.1: should be ~6 bytes (no delimiter_stack)
    // last_char (4) + at_line_start (1) + state_flags (1) = 6 bytes
    assert(size >= 4 && size <= 8);

    printf("✓ Scanner state size reduced successfully\n");
    return 0;
}
