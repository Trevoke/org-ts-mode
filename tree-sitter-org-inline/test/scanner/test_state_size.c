#include <assert.h>
#include <stdio.h>
#include "../../src/scanner.c"  // Include scanner implementation

int main() {
    Scanner s;
    size_t size = sizeof(Scanner);

    printf("Current scanner state size: %zu bytes\n", size);

    // Baseline: should be ~20 bytes with delimiter_stack
    assert(size >= 18 && size <= 24);

    printf("✓ Scanner state size within expected range\n");
    return 0;
}
