#include <assert.h>
#include <stdio.h>
#include "../src/scanner.c"

int main() {
    // Test scanner creation
    void *scanner = tree_sitter_org_inline_external_scanner_create();
    assert(scanner != NULL);

    Scanner *s = (Scanner *)scanner;
    assert(s->last_char == 0);
    assert(s->at_line_start == true);  // Should start at BOL
    assert(s->state_flags == 0);

    tree_sitter_org_inline_external_scanner_destroy(scanner);

    printf("✓ Scanner creation initializes state correctly\n");
    return 0;
}
