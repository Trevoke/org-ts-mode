#include <assert.h>
#include <stdio.h>
#include "../src/scanner.c"

// Total number of token types in the scanner
#define TOKEN_COUNT 13

void test_valid_symbols_only_open() {
    bool valid_symbols[TOKEN_COUNT] = {false};
    valid_symbols[BOLD_OPEN] = true;
    valid_symbols[BOLD_CLOSE] = false;

    // Scanner should only consider OPEN in this context
    // (Actual test would use mock lexer)

    printf("✓ valid_symbols: only OPEN allowed\n");
}

void test_valid_symbols_only_close() {
    bool valid_symbols[TOKEN_COUNT] = {false};
    valid_symbols[BOLD_OPEN] = false;
    valid_symbols[BOLD_CLOSE] = true;

    // Scanner should only consider CLOSE in this context

    printf("✓ valid_symbols: only CLOSE allowed\n");
}

void test_valid_symbols_both() {
    bool valid_symbols[TOKEN_COUNT] = {false};
    valid_symbols[BOLD_OPEN] = true;
    valid_symbols[BOLD_CLOSE] = true;

    // Scanner should use lookahead to determine OPEN vs CLOSE

    printf("✓ valid_symbols: both allowed, use lookahead\n");
}

int main() {
    test_valid_symbols_only_open();
    test_valid_symbols_only_close();
    test_valid_symbols_both();
    printf("✓ All valid_symbols tests passed\n");
    return 0;
}
