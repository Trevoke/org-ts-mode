#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

// Minimal Scanner struct definition (matches src/scanner.c)
typedef struct {
    int32_t last_char;      // Last character seen (for PRE boundary)
    bool at_line_start;     // Are we at beginning of line?
    uint8_t state_flags;    // Bit flags for tags state
} Scanner;

// Minimal scanner_create implementation (from src/scanner.c lines 1102-1110)
void *tree_sitter_org_inline_external_scanner_create() {
    Scanner *scanner = calloc(1, sizeof(Scanner));
    if (scanner) {
        scanner->last_char = 0;
        scanner->at_line_start = true;
        scanner->state_flags = 0;
    }
    return scanner;
}

int main() {
    // Test scanner creation
    void *scanner = tree_sitter_org_inline_external_scanner_create();
    assert(scanner != NULL);

    Scanner *s = (Scanner *)scanner;
    assert(s->last_char == 0);
    assert(s->at_line_start == true);  // Should start at BOL
    assert(s->state_flags == 0);

    free(scanner);

    printf("✓ Scanner creation initializes state correctly\n");
    return 0;
}
