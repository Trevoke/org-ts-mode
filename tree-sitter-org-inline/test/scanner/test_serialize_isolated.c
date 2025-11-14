#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

// State flag bits
#define FLAG_IN_TAGS 0x01

// Minimal Scanner definition (matching the new structure)
typedef struct {
    int32_t last_char;      // Last character seen (for PRE boundary)
    bool at_line_start;     // Are we at beginning of line?
    uint8_t state_flags;    // Bit flags for tags state
} Scanner;

// New serialize function (copy of implementation)
static unsigned serialize(Scanner *scanner, char *buffer) {
    if (!scanner) return 0;

    // Serialize: last_char (4) + at_line_start (1) + state_flags (1) = 6 bytes
    memcpy(buffer, &scanner->last_char, sizeof(int32_t));
    buffer[4] = scanner->at_line_start ? 1 : 0;
    buffer[5] = scanner->state_flags;

    return 6;
}

int main() {
    Scanner s = {
        .last_char = 'a',
        .at_line_start = false,
        .state_flags = FLAG_IN_TAGS
    };

    char buffer[32];
    unsigned result = serialize(&s, buffer);

    // Should serialize 6 bytes: 4 (last_char) + 1 (at_line_start) + 1 (state_flags)
    assert(result == 6);

    // Verify buffer contents
    int32_t *last_char_ptr = (int32_t *)buffer;
    assert(*last_char_ptr == 'a');
    assert(buffer[4] == 0);  // false
    assert(buffer[5] == FLAG_IN_TAGS);

    printf("✓ Scanner serialization works correctly\n");
    return 0;
}
