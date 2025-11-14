#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

// Minimal scanner definition for testing
typedef struct {
    int32_t last_char;
    bool at_line_start;
    uint8_t state_flags;
} Scanner;

#define FLAG_IN_TAGS 0x01

// Copy of the new deserialize function
static void deserialize(Scanner *scanner, const char *buffer, unsigned length) {
    if (!scanner) return;

    if (length == 0 || !buffer) {
        // Clean state
        scanner->last_char = 0;
        scanner->at_line_start = true;
        scanner->state_flags = 0;
        return;
    }

    if (length >= 6) {
        memcpy(&scanner->last_char, buffer, sizeof(int32_t));
        scanner->at_line_start = buffer[4] != 0;
        scanner->state_flags = buffer[5];
    } else {
        // Invalid buffer, use clean state
        scanner->last_char = 0;
        scanner->at_line_start = true;
        scanner->state_flags = 0;
    }
}

// Copy of the new serialize function
static unsigned serialize(Scanner *scanner, char *buffer) {
    if (!scanner) return 0;

    // Serialize: last_char (4) + at_line_start (1) + state_flags (1) = 6 bytes
    memcpy(buffer, &scanner->last_char, sizeof(int32_t));
    buffer[4] = scanner->at_line_start ? 1 : 0;
    buffer[5] = scanner->state_flags;

    return 6;
}

int main() {
    printf("Testing standalone deserialize implementation...\n");

    // Test 1: Full roundtrip
    Scanner s1 = {
        .last_char = 'a',
        .at_line_start = false,
        .state_flags = FLAG_IN_TAGS
    };

    char buffer[32];
    unsigned bytes_written = serialize(&s1, buffer);
    assert(bytes_written == 6);
    printf("✓ Serialized 6 bytes\n");

    Scanner s2;
    deserialize(&s2, buffer, 6);
    assert(s2.last_char == 'a');
    assert(s2.at_line_start == false);
    assert(s2.state_flags == FLAG_IN_TAGS);
    printf("✓ Deserialization roundtrip works\n");

    // Test 2: Empty buffer
    Scanner s3;
    deserialize(&s3, NULL, 0);
    assert(s3.last_char == 0);
    assert(s3.at_line_start == true);
    assert(s3.state_flags == 0);
    printf("✓ Empty buffer yields clean state\n");

    // Test 3: Invalid length
    Scanner s4;
    deserialize(&s4, buffer, 3);  // Too short
    assert(s4.last_char == 0);
    assert(s4.at_line_start == true);
    assert(s4.state_flags == 0);
    printf("✓ Invalid length yields clean state\n");

    // Test 4: Test with different values
    Scanner s5 = {
        .last_char = ' ',
        .at_line_start = true,
        .state_flags = 0
    };
    serialize(&s5, buffer);

    Scanner s6;
    deserialize(&s6, buffer, 6);
    assert(s6.last_char == ' ');
    assert(s6.at_line_start == true);
    assert(s6.state_flags == 0);
    printf("✓ Roundtrip with at_line_start=true works\n");

    printf("\n✓✓✓ All deserialize tests PASSED ✓✓✓\n");
    return 0;
}
