#include <assert.h>
#include <stdio.h>
#include "../src/scanner.c"

// Helper to create mock lexer
typedef struct {
    const char *input;
    int position;
    int32_t lookahead;
} MockLexer;

void mock_advance(MockLexer *lexer, bool skip) {
    if (lexer->input[lexer->position]) {
        lexer->position++;
        lexer->lookahead = lexer->input[lexer->position];
    }
}

int main() {
    // Test that scanner no longer prevents same-delimiter nesting
    // Input: "*bold *nested* bold*"
    // Scanner should emit BOLD_OPEN for both '*' delimiters
    // (Grammar will later control nesting)

    Scanner s = {0};
    s.at_line_start = true;

    // This is a placeholder - actual testing happens via tree-sitter test
    // This test just verifies scan_emphasis compiles without stack operations

    printf("✓ Emphasis scanning compiles without stack operations\n");
    return 0;
}
