#include "tree_sitter/parser.h"

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 7
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 8
#define ALIAS_COUNT 0
#define TOKEN_COUNT 5
#define EXTERNAL_TOKEN_COUNT 2
#define FIELD_COUNT 2
#define MAX_ALIAS_SEQUENCE_LENGTH 3
#define PRODUCTION_ID_COUNT 3

enum ts_symbol_identifiers {
  anon_sym_SPACE = 1,
  sym_text = 2,
  sym_TITLE_TEXT = 3,
  sym_TAGS = 4,
  sym_inline = 5,
  sym_title_with_tags = 6,
  sym_title_only = 7,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [anon_sym_SPACE] = " ",
  [sym_text] = "text",
  [sym_TITLE_TEXT] = "title",
  [sym_TAGS] = "tags",
  [sym_inline] = "inline",
  [sym_title_with_tags] = "title_with_tags",
  [sym_title_only] = "title_only",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [anon_sym_SPACE] = anon_sym_SPACE,
  [sym_text] = sym_text,
  [sym_TITLE_TEXT] = sym_TITLE_TEXT,
  [sym_TAGS] = sym_TAGS,
  [sym_inline] = sym_inline,
  [sym_title_with_tags] = sym_title_with_tags,
  [sym_title_only] = sym_title_only,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [anon_sym_SPACE] = {
    .visible = true,
    .named = false,
  },
  [sym_text] = {
    .visible = true,
    .named = true,
  },
  [sym_TITLE_TEXT] = {
    .visible = true,
    .named = true,
  },
  [sym_TAGS] = {
    .visible = true,
    .named = true,
  },
  [sym_inline] = {
    .visible = true,
    .named = true,
  },
  [sym_title_with_tags] = {
    .visible = true,
    .named = true,
  },
  [sym_title_only] = {
    .visible = true,
    .named = true,
  },
};

enum ts_field_identifiers {
  field_tags = 1,
  field_title = 2,
};

static const char * const ts_field_names[] = {
  [0] = NULL,
  [field_tags] = "tags",
  [field_title] = "title",
};

static const TSFieldMapSlice ts_field_map_slices[PRODUCTION_ID_COUNT] = {
  [1] = {.index = 0, .length = 1},
  [2] = {.index = 1, .length = 2},
};

static const TSFieldMapEntry ts_field_map_entries[] = {
  [0] =
    {field_title, 0},
  [1] =
    {field_tags, 2},
    {field_title, 0},
};

static const TSSymbol ts_alias_sequences[PRODUCTION_ID_COUNT][MAX_ALIAS_SEQUENCE_LENGTH] = {
  [0] = {0},
};

static const uint16_t ts_non_terminal_alias_map[] = {
  0,
};

static const TSStateId ts_primary_state_ids[STATE_COUNT] = {
  [0] = 0,
  [1] = 1,
  [2] = 2,
  [3] = 3,
  [4] = 4,
  [5] = 5,
  [6] = 6,
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(3);
      if (lookahead == '\n') SKIP(0);
      if (lookahead == ' ') ADVANCE(4);
      if (('\t' <= lookahead && lookahead <= '\r')) ADVANCE(6);
      if (lookahead != 0) ADVANCE(8);
      END_STATE();
    case 1:
      if (lookahead == '\n') SKIP(1);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(7);
      if (lookahead != 0) ADVANCE(8);
      END_STATE();
    case 2:
      if (eof) ADVANCE(3);
      if (lookahead == ' ') ADVANCE(5);
      if (('\t' <= lookahead && lookahead <= '\r')) SKIP(2);
      END_STATE();
    case 3:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 4:
      ACCEPT_TOKEN(anon_sym_SPACE);
      if (lookahead == ' ') ADVANCE(4);
      if (lookahead == '\t' ||
          (0x0b <= lookahead && lookahead <= '\r')) ADVANCE(6);
      END_STATE();
    case 5:
      ACCEPT_TOKEN(anon_sym_SPACE);
      if (lookahead == ' ') ADVANCE(5);
      END_STATE();
    case 6:
      ACCEPT_TOKEN(sym_text);
      if (lookahead == ' ') ADVANCE(4);
      if (lookahead == '\t' ||
          (0x0b <= lookahead && lookahead <= '\r')) ADVANCE(6);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead)) ADVANCE(8);
      END_STATE();
    case 7:
      ACCEPT_TOKEN(sym_text);
      if (lookahead == '\t' ||
          (0x0b <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(7);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead)) ADVANCE(8);
      END_STATE();
    case 8:
      ACCEPT_TOKEN(sym_text);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(8);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0, .external_lex_state = 1},
  [1] = {.lex_state = 1, .external_lex_state = 2},
  [2] = {.lex_state = 2},
  [3] = {.lex_state = 0},
  [4] = {.lex_state = 0},
  [5] = {.lex_state = 0, .external_lex_state = 3},
  [6] = {.lex_state = 0},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [anon_sym_SPACE] = ACTIONS(1),
    [sym_text] = ACTIONS(1),
    [sym_TITLE_TEXT] = ACTIONS(1),
    [sym_TAGS] = ACTIONS(1),
  },
  [1] = {
    [sym_inline] = STATE(4),
    [sym_title_with_tags] = STATE(3),
    [sym_title_only] = STATE(3),
    [sym_text] = ACTIONS(3),
    [sym_TITLE_TEXT] = ACTIONS(5),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 2,
    ACTIONS(7), 1,
      ts_builtin_sym_end,
    ACTIONS(9), 1,
      anon_sym_SPACE,
  [7] = 1,
    ACTIONS(11), 1,
      ts_builtin_sym_end,
  [11] = 1,
    ACTIONS(13), 1,
      ts_builtin_sym_end,
  [15] = 1,
    ACTIONS(15), 1,
      sym_TAGS,
  [19] = 1,
    ACTIONS(17), 1,
      ts_builtin_sym_end,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 7,
  [SMALL_STATE(4)] = 11,
  [SMALL_STATE(5)] = 15,
  [SMALL_STATE(6)] = 19,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, SHIFT(3),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(2),
  [7] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_title_only, 1, 0, 1),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
  [11] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_inline, 1, 0, 0),
  [13] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [15] = {.entry = {.count = 1, .reusable = true}}, SHIFT(6),
  [17] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_title_with_tags, 3, 0, 2),
};

enum ts_external_scanner_symbol_identifiers {
  ts_external_token_TITLE_TEXT = 0,
  ts_external_token_TAGS = 1,
};

static const TSSymbol ts_external_scanner_symbol_map[EXTERNAL_TOKEN_COUNT] = {
  [ts_external_token_TITLE_TEXT] = sym_TITLE_TEXT,
  [ts_external_token_TAGS] = sym_TAGS,
};

static const bool ts_external_scanner_states[4][EXTERNAL_TOKEN_COUNT] = {
  [1] = {
    [ts_external_token_TITLE_TEXT] = true,
    [ts_external_token_TAGS] = true,
  },
  [2] = {
    [ts_external_token_TITLE_TEXT] = true,
  },
  [3] = {
    [ts_external_token_TAGS] = true,
  },
};

#ifdef __cplusplus
extern "C" {
#endif
void *tree_sitter_org_inline_external_scanner_create(void);
void tree_sitter_org_inline_external_scanner_destroy(void *);
bool tree_sitter_org_inline_external_scanner_scan(void *, TSLexer *, const bool *);
unsigned tree_sitter_org_inline_external_scanner_serialize(void *, char *);
void tree_sitter_org_inline_external_scanner_deserialize(void *, const char *, unsigned);

#ifdef TREE_SITTER_HIDE_SYMBOLS
#define TS_PUBLIC
#elif defined(_WIN32)
#define TS_PUBLIC __declspec(dllexport)
#else
#define TS_PUBLIC __attribute__((visibility("default")))
#endif

TS_PUBLIC const TSLanguage *tree_sitter_org_inline(void) {
  static const TSLanguage language = {
    .version = LANGUAGE_VERSION,
    .symbol_count = SYMBOL_COUNT,
    .alias_count = ALIAS_COUNT,
    .token_count = TOKEN_COUNT,
    .external_token_count = EXTERNAL_TOKEN_COUNT,
    .state_count = STATE_COUNT,
    .large_state_count = LARGE_STATE_COUNT,
    .production_id_count = PRODUCTION_ID_COUNT,
    .field_count = FIELD_COUNT,
    .max_alias_sequence_length = MAX_ALIAS_SEQUENCE_LENGTH,
    .parse_table = &ts_parse_table[0][0],
    .small_parse_table = ts_small_parse_table,
    .small_parse_table_map = ts_small_parse_table_map,
    .parse_actions = ts_parse_actions,
    .symbol_names = ts_symbol_names,
    .field_names = ts_field_names,
    .field_map_slices = ts_field_map_slices,
    .field_map_entries = ts_field_map_entries,
    .symbol_metadata = ts_symbol_metadata,
    .public_symbol_map = ts_symbol_map,
    .alias_map = ts_non_terminal_alias_map,
    .alias_sequences = &ts_alias_sequences[0][0],
    .lex_modes = ts_lex_modes,
    .lex_fn = ts_lex,
    .external_scanner = {
      &ts_external_scanner_states[0][0],
      ts_external_scanner_symbol_map,
      tree_sitter_org_inline_external_scanner_create,
      tree_sitter_org_inline_external_scanner_destroy,
      tree_sitter_org_inline_external_scanner_scan,
      tree_sitter_org_inline_external_scanner_serialize,
      tree_sitter_org_inline_external_scanner_deserialize,
    },
    .primary_state_ids = ts_primary_state_ids,
  };
  return &language;
}
#ifdef __cplusplus
}
#endif
