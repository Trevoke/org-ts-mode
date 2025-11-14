#include <assert.h>
#include <stdio.h>
#include "../src/scanner.c"

void test_pre_boundary_bol() {
    Scanner s = {.at_line_start = true, .last_char = 0};
    // Simulated lexer at BOL
    assert(is_valid_pre_char(s.last_char, s.at_line_start) == true);
    printf("✓ PRE: BOL is valid\n");
}

void test_pre_boundary_space() {
    Scanner s = {.at_line_start = false, .last_char = ' '};
    assert(is_valid_pre_char(s.last_char, s.at_line_start) == true);
    printf("✓ PRE: Space is valid\n");
}

void test_pre_boundary_tab() {
    Scanner s = {.at_line_start = false, .last_char = '\t'};
    assert(is_valid_pre_char(s.last_char, s.at_line_start) == true);
    printf("✓ PRE: Tab is valid\n");
}

void test_pre_boundary_newline() {
    Scanner s = {.at_line_start = false, .last_char = '\n'};
    assert(is_valid_pre_char(s.last_char, s.at_line_start) == true);
    printf("✓ PRE: Newline is valid\n");
}

void test_pre_boundary_hyphen() {
    Scanner s = {.at_line_start = false, .last_char = '-'};
    assert(is_valid_pre_char(s.last_char, s.at_line_start) == true);
    printf("✓ PRE: Hyphen is valid\n");
}

void test_pre_boundary_open_paren() {
    Scanner s = {.at_line_start = false, .last_char = '('};
    assert(is_valid_pre_char(s.last_char, s.at_line_start) == true);
    printf("✓ PRE: Open paren is valid\n");
}

void test_pre_boundary_open_brace() {
    Scanner s = {.at_line_start = false, .last_char = '{'};
    assert(is_valid_pre_char(s.last_char, s.at_line_start) == true);
    printf("✓ PRE: Open brace is valid\n");
}

void test_pre_boundary_single_quote() {
    Scanner s = {.at_line_start = false, .last_char = '\''};
    assert(is_valid_pre_char(s.last_char, s.at_line_start) == true);
    printf("✓ PRE: Single quote is valid\n");
}

void test_pre_boundary_double_quote() {
    Scanner s = {.at_line_start = false, .last_char = '"'};
    assert(is_valid_pre_char(s.last_char, s.at_line_start) == true);
    printf("✓ PRE: Double quote is valid\n");
}

void test_pre_boundary_invalid_letter() {
    Scanner s = {.at_line_start = false, .last_char = 'a'};
    assert(is_valid_pre_char(s.last_char, s.at_line_start) == false);
    printf("✓ PRE: Letter is invalid\n");
}

void test_pre_boundary_invalid_digit() {
    Scanner s = {.at_line_start = false, .last_char = '5'};
    assert(is_valid_pre_char(s.last_char, s.at_line_start) == false);
    printf("✓ PRE: Digit is invalid\n");
}

void test_pre_boundary_invalid_close_paren() {
    Scanner s = {.at_line_start = false, .last_char = ')'};
    assert(is_valid_pre_char(s.last_char, s.at_line_start) == false);
    printf("✓ PRE: Close paren is invalid\n");
}

void test_post_boundary_eol() {
    assert(is_valid_post_char(0) == true);
    printf("✓ POST: EOL (null) is valid\n");
}

void test_post_boundary_newline() {
    assert(is_valid_post_char('\n') == true);
    printf("✓ POST: Newline is valid\n");
}

void test_post_boundary_space() {
    assert(is_valid_post_char(' ') == true);
    printf("✓ POST: Space is valid\n");
}

void test_post_boundary_tab() {
    assert(is_valid_post_char('\t') == true);
    printf("✓ POST: Tab is valid\n");
}

void test_post_boundary_hyphen() {
    assert(is_valid_post_char('-') == true);
    printf("✓ POST: Hyphen is valid\n");
}

void test_post_boundary_period() {
    assert(is_valid_post_char('.') == true);
    printf("✓ POST: Period is valid\n");
}

void test_post_boundary_comma() {
    assert(is_valid_post_char(',') == true);
    printf("✓ POST: Comma is valid\n");
}

void test_post_boundary_semicolon() {
    assert(is_valid_post_char(';') == true);
    printf("✓ POST: Semicolon is valid\n");
}

void test_post_boundary_colon() {
    assert(is_valid_post_char(':') == true);
    printf("✓ POST: Colon is valid\n");
}

void test_post_boundary_exclamation() {
    assert(is_valid_post_char('!') == true);
    printf("✓ POST: Exclamation is valid\n");
}

void test_post_boundary_question() {
    assert(is_valid_post_char('?') == true);
    printf("✓ POST: Question mark is valid\n");
}

void test_post_boundary_single_quote() {
    assert(is_valid_post_char('\'') == true);
    printf("✓ POST: Single quote is valid\n");
}

void test_post_boundary_close_paren() {
    assert(is_valid_post_char(')') == true);
    printf("✓ POST: Close paren is valid\n");
}

void test_post_boundary_close_brace() {
    assert(is_valid_post_char('}') == true);
    printf("✓ POST: Close brace is valid\n");
}

void test_post_boundary_open_bracket() {
    assert(is_valid_post_char('[') == true);
    printf("✓ POST: Open bracket is valid\n");
}

void test_post_boundary_double_quote() {
    assert(is_valid_post_char('"') == true);
    printf("✓ POST: Double quote is valid\n");
}

void test_post_boundary_backslash() {
    assert(is_valid_post_char('\\') == true);
    printf("✓ POST: Backslash is valid\n");
}

void test_post_boundary_invalid_letter() {
    assert(is_valid_post_char('a') == false);
    printf("✓ POST: Letter is invalid\n");
}

void test_post_boundary_invalid_digit() {
    assert(is_valid_post_char('5') == false);
    printf("✓ POST: Digit is invalid\n");
}

void test_post_boundary_invalid_open_paren() {
    assert(is_valid_post_char('(') == false);
    printf("✓ POST: Open paren is invalid\n");
}

int main() {
    // PRE boundary tests
    test_pre_boundary_bol();
    test_pre_boundary_space();
    test_pre_boundary_tab();
    test_pre_boundary_newline();
    test_pre_boundary_hyphen();
    test_pre_boundary_open_paren();
    test_pre_boundary_open_brace();
    test_pre_boundary_single_quote();
    test_pre_boundary_double_quote();
    test_pre_boundary_invalid_letter();
    test_pre_boundary_invalid_digit();
    test_pre_boundary_invalid_close_paren();

    // POST boundary tests
    test_post_boundary_eol();
    test_post_boundary_newline();
    test_post_boundary_space();
    test_post_boundary_tab();
    test_post_boundary_hyphen();
    test_post_boundary_period();
    test_post_boundary_comma();
    test_post_boundary_semicolon();
    test_post_boundary_colon();
    test_post_boundary_exclamation();
    test_post_boundary_question();
    test_post_boundary_single_quote();
    test_post_boundary_close_paren();
    test_post_boundary_close_brace();
    test_post_boundary_open_bracket();
    test_post_boundary_double_quote();
    test_post_boundary_backslash();
    test_post_boundary_invalid_letter();
    test_post_boundary_invalid_digit();
    test_post_boundary_invalid_open_paren();

    printf("\n✓ All boundary validation tests passed (%d total)\n", 32);
    return 0;
}
