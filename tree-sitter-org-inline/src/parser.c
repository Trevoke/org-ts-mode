#include "tree_sitter/parser.h"

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 24
#define LARGE_STATE_COUNT 4
#define SYMBOL_COUNT 23
#define ALIAS_COUNT 0
#define TOKEN_COUNT 12
#define EXTERNAL_TOKEN_COUNT 1
#define FIELD_COUNT 2
#define MAX_ALIAS_SEQUENCE_LENGTH 3
#define PRODUCTION_ID_COUNT 4

enum ts_symbol_identifiers {
  anon_sym_COLON = 1,
  anon_sym_STAR = 2,
  aux_sym_bold_token1 = 3,
  anon_sym_SLASH = 4,
  aux_sym_italic_token1 = 5,
  anon_sym_TILDE = 6,
  aux_sym_code_token1 = 7,
  anon_sym_EQ = 8,
  aux_sym_verbatim_token1 = 9,
  aux_sym_plain_text_token1 = 10,
  sym_TAGS = 11,
  sym_inline = 12,
  sym_title_with_tags = 13,
  sym_title_only = 14,
  sym_title = 15,
  sym_text_markup = 16,
  sym_bold = 17,
  sym_italic = 18,
  sym_code = 19,
  sym_verbatim = 20,
  sym_plain_text = 21,
  aux_sym_title_repeat1 = 22,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [anon_sym_COLON] = ":",
  [anon_sym_STAR] = "*",
  [aux_sym_bold_token1] = "bold_token1",
  [anon_sym_SLASH] = "/",
  [aux_sym_italic_token1] = "italic_token1",
  [anon_sym_TILDE] = "~",
  [aux_sym_code_token1] = "code_token1",
  [anon_sym_EQ] = "=",
  [aux_sym_verbatim_token1] = "verbatim_token1",
  [aux_sym_plain_text_token1] = "plain_text_token1",
  [sym_TAGS] = "tags",
  [sym_inline] = "inline",
  [sym_title_with_tags] = "title_with_tags",
  [sym_title_only] = "title_only",
  [sym_title] = "title",
  [sym_text_markup] = "text_markup",
  [sym_bold] = "bold",
  [sym_italic] = "italic",
  [sym_code] = "code",
  [sym_verbatim] = "verbatim",
  [sym_plain_text] = "plain_text",
  [aux_sym_title_repeat1] = "title_repeat1",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [anon_sym_COLON] = anon_sym_COLON,
  [anon_sym_STAR] = anon_sym_STAR,
  [aux_sym_bold_token1] = aux_sym_bold_token1,
  [anon_sym_SLASH] = anon_sym_SLASH,
  [aux_sym_italic_token1] = aux_sym_italic_token1,
  [anon_sym_TILDE] = anon_sym_TILDE,
  [aux_sym_code_token1] = aux_sym_code_token1,
  [anon_sym_EQ] = anon_sym_EQ,
  [aux_sym_verbatim_token1] = aux_sym_verbatim_token1,
  [aux_sym_plain_text_token1] = aux_sym_plain_text_token1,
  [sym_TAGS] = sym_TAGS,
  [sym_inline] = sym_inline,
  [sym_title_with_tags] = sym_title_with_tags,
  [sym_title_only] = sym_title_only,
  [sym_title] = sym_title,
  [sym_text_markup] = sym_text_markup,
  [sym_bold] = sym_bold,
  [sym_italic] = sym_italic,
  [sym_code] = sym_code,
  [sym_verbatim] = sym_verbatim,
  [sym_plain_text] = sym_plain_text,
  [aux_sym_title_repeat1] = aux_sym_title_repeat1,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [anon_sym_COLON] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_STAR] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_bold_token1] = {
    .visible = false,
    .named = false,
  },
  [anon_sym_SLASH] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_italic_token1] = {
    .visible = false,
    .named = false,
  },
  [anon_sym_TILDE] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_code_token1] = {
    .visible = false,
    .named = false,
  },
  [anon_sym_EQ] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_verbatim_token1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_plain_text_token1] = {
    .visible = false,
    .named = false,
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
  [sym_title] = {
    .visible = true,
    .named = true,
  },
  [sym_text_markup] = {
    .visible = true,
    .named = true,
  },
  [sym_bold] = {
    .visible = true,
    .named = true,
  },
  [sym_italic] = {
    .visible = true,
    .named = true,
  },
  [sym_code] = {
    .visible = true,
    .named = true,
  },
  [sym_verbatim] = {
    .visible = true,
    .named = true,
  },
  [sym_plain_text] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_title_repeat1] = {
    .visible = false,
    .named = false,
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
  [2] = {.index = 1, .length = 1},
  [3] = {.index = 2, .length = 2},
};

static const TSFieldMapEntry ts_field_map_entries[] = {
  [0] =
    {field_tags, 0},
  [1] =
    {field_title, 0},
  [2] =
    {field_tags, 1},
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
  [7] = 7,
  [8] = 8,
  [9] = 9,
  [10] = 10,
  [11] = 11,
  [12] = 12,
  [13] = 13,
  [14] = 14,
  [15] = 15,
  [16] = 16,
  [17] = 17,
  [18] = 18,
  [19] = 19,
  [20] = 20,
  [21] = 21,
  [22] = 22,
  [23] = 23,
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(9);
      if (lookahead == '\n') SKIP(0);
      if (lookahead == '*') ADVANCE(11);
      if (lookahead == '/') ADVANCE(13);
      if (lookahead == ':') ADVANCE(10);
      if (lookahead == '=') ADVANCE(17);
      if (lookahead == '~') ADVANCE(15);
      if (lookahead != 0) ADVANCE(19);
      END_STATE();
    case 1:
      if (lookahead == '\n') SKIP(1);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '=') ADVANCE(18);
      END_STATE();
    case 2:
      if (lookahead == '\n') SKIP(2);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '~') ADVANCE(16);
      END_STATE();
    case 3:
      if (lookahead == '\n') SKIP(3);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '/') ADVANCE(14);
      END_STATE();
    case 4:
      if (lookahead == '\n') SKIP(4);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '*') ADVANCE(12);
      END_STATE();
    case 5:
      if (lookahead == '\t' ||
          (0x0b <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(5);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != '=') ADVANCE(18);
      END_STATE();
    case 6:
      if (lookahead == '\t' ||
          (0x0b <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(6);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != '~') ADVANCE(16);
      END_STATE();
    case 7:
      if (lookahead == '\t' ||
          (0x0b <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(7);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != '/') ADVANCE(14);
      END_STATE();
    case 8:
      if (lookahead == '\t' ||
          (0x0b <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(8);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != '*') ADVANCE(12);
      END_STATE();
    case 9:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 10:
      ACCEPT_TOKEN(anon_sym_COLON);
      END_STATE();
    case 11:
      ACCEPT_TOKEN(anon_sym_STAR);
      END_STATE();
    case 12:
      ACCEPT_TOKEN(aux_sym_bold_token1);
      if (lookahead == '\t' ||
          (0x0b <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(8);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != '*') ADVANCE(12);
      END_STATE();
    case 13:
      ACCEPT_TOKEN(anon_sym_SLASH);
      END_STATE();
    case 14:
      ACCEPT_TOKEN(aux_sym_italic_token1);
      if (lookahead == '\t' ||
          (0x0b <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(7);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != '/') ADVANCE(14);
      END_STATE();
    case 15:
      ACCEPT_TOKEN(anon_sym_TILDE);
      END_STATE();
    case 16:
      ACCEPT_TOKEN(aux_sym_code_token1);
      if (lookahead == '\t' ||
          (0x0b <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(6);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != '~') ADVANCE(16);
      END_STATE();
    case 17:
      ACCEPT_TOKEN(anon_sym_EQ);
      END_STATE();
    case 18:
      ACCEPT_TOKEN(aux_sym_verbatim_token1);
      if (lookahead == '\t' ||
          (0x0b <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(5);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != '=') ADVANCE(18);
      END_STATE();
    case 19:
      ACCEPT_TOKEN(aux_sym_plain_text_token1);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '*' &&
          lookahead != '/' &&
          lookahead != ':' &&
          lookahead != '=' &&
          lookahead != '~') ADVANCE(19);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0, .external_lex_state = 1},
  [1] = {.lex_state = 0, .external_lex_state = 1},
  [2] = {.lex_state = 0, .external_lex_state = 1},
  [3] = {.lex_state = 0, .external_lex_state = 1},
  [4] = {.lex_state = 0, .external_lex_state = 1},
  [5] = {.lex_state = 0, .external_lex_state = 1},
  [6] = {.lex_state = 0, .external_lex_state = 1},
  [7] = {.lex_state = 0, .external_lex_state = 1},
  [8] = {.lex_state = 0, .external_lex_state = 1},
  [9] = {.lex_state = 0, .external_lex_state = 1},
  [10] = {.lex_state = 0, .external_lex_state = 1},
  [11] = {.lex_state = 1},
  [12] = {.lex_state = 0},
  [13] = {.lex_state = 0},
  [14] = {.lex_state = 0},
  [15] = {.lex_state = 0},
  [16] = {.lex_state = 0},
  [17] = {.lex_state = 0},
  [18] = {.lex_state = 0},
  [19] = {.lex_state = 0},
  [20] = {.lex_state = 0},
  [21] = {.lex_state = 2},
  [22] = {.lex_state = 3},
  [23] = {.lex_state = 4},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [anon_sym_COLON] = ACTIONS(1),
    [anon_sym_STAR] = ACTIONS(1),
    [anon_sym_SLASH] = ACTIONS(1),
    [anon_sym_TILDE] = ACTIONS(1),
    [anon_sym_EQ] = ACTIONS(1),
    [aux_sym_plain_text_token1] = ACTIONS(1),
    [sym_TAGS] = ACTIONS(1),
  },
  [1] = {
    [sym_inline] = STATE(20),
    [sym_title_with_tags] = STATE(19),
    [sym_title_only] = STATE(12),
    [sym_title] = STATE(10),
    [sym_text_markup] = STATE(3),
    [sym_bold] = STATE(9),
    [sym_italic] = STATE(9),
    [sym_code] = STATE(9),
    [sym_verbatim] = STATE(9),
    [sym_plain_text] = STATE(3),
    [aux_sym_title_repeat1] = STATE(3),
    [anon_sym_COLON] = ACTIONS(3),
    [anon_sym_STAR] = ACTIONS(5),
    [anon_sym_SLASH] = ACTIONS(7),
    [anon_sym_TILDE] = ACTIONS(9),
    [anon_sym_EQ] = ACTIONS(11),
    [aux_sym_plain_text_token1] = ACTIONS(13),
    [sym_TAGS] = ACTIONS(15),
  },
  [2] = {
    [sym_text_markup] = STATE(2),
    [sym_bold] = STATE(9),
    [sym_italic] = STATE(9),
    [sym_code] = STATE(9),
    [sym_verbatim] = STATE(9),
    [sym_plain_text] = STATE(2),
    [aux_sym_title_repeat1] = STATE(2),
    [ts_builtin_sym_end] = ACTIONS(17),
    [anon_sym_COLON] = ACTIONS(19),
    [anon_sym_STAR] = ACTIONS(22),
    [anon_sym_SLASH] = ACTIONS(25),
    [anon_sym_TILDE] = ACTIONS(28),
    [anon_sym_EQ] = ACTIONS(31),
    [aux_sym_plain_text_token1] = ACTIONS(34),
    [sym_TAGS] = ACTIONS(17),
  },
  [3] = {
    [sym_text_markup] = STATE(2),
    [sym_bold] = STATE(9),
    [sym_italic] = STATE(9),
    [sym_code] = STATE(9),
    [sym_verbatim] = STATE(9),
    [sym_plain_text] = STATE(2),
    [aux_sym_title_repeat1] = STATE(2),
    [ts_builtin_sym_end] = ACTIONS(37),
    [anon_sym_COLON] = ACTIONS(39),
    [anon_sym_STAR] = ACTIONS(5),
    [anon_sym_SLASH] = ACTIONS(7),
    [anon_sym_TILDE] = ACTIONS(9),
    [anon_sym_EQ] = ACTIONS(11),
    [aux_sym_plain_text_token1] = ACTIONS(13),
    [sym_TAGS] = ACTIONS(37),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 1,
    ACTIONS(41), 8,
      sym_TAGS,
      ts_builtin_sym_end,
      anon_sym_COLON,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_TILDE,
      anon_sym_EQ,
      aux_sym_plain_text_token1,
  [11] = 1,
    ACTIONS(43), 8,
      sym_TAGS,
      ts_builtin_sym_end,
      anon_sym_COLON,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_TILDE,
      anon_sym_EQ,
      aux_sym_plain_text_token1,
  [22] = 1,
    ACTIONS(45), 8,
      sym_TAGS,
      ts_builtin_sym_end,
      anon_sym_COLON,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_TILDE,
      anon_sym_EQ,
      aux_sym_plain_text_token1,
  [33] = 1,
    ACTIONS(47), 8,
      sym_TAGS,
      ts_builtin_sym_end,
      anon_sym_COLON,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_TILDE,
      anon_sym_EQ,
      aux_sym_plain_text_token1,
  [44] = 1,
    ACTIONS(49), 8,
      sym_TAGS,
      ts_builtin_sym_end,
      anon_sym_COLON,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_TILDE,
      anon_sym_EQ,
      aux_sym_plain_text_token1,
  [55] = 1,
    ACTIONS(51), 8,
      sym_TAGS,
      ts_builtin_sym_end,
      anon_sym_COLON,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_TILDE,
      anon_sym_EQ,
      aux_sym_plain_text_token1,
  [66] = 2,
    ACTIONS(53), 1,
      ts_builtin_sym_end,
    ACTIONS(55), 1,
      sym_TAGS,
  [73] = 1,
    ACTIONS(57), 1,
      aux_sym_verbatim_token1,
  [77] = 1,
    ACTIONS(59), 1,
      ts_builtin_sym_end,
  [81] = 1,
    ACTIONS(61), 1,
      ts_builtin_sym_end,
  [85] = 1,
    ACTIONS(63), 1,
      anon_sym_STAR,
  [89] = 1,
    ACTIONS(65), 1,
      anon_sym_SLASH,
  [93] = 1,
    ACTIONS(67), 1,
      anon_sym_TILDE,
  [97] = 1,
    ACTIONS(69), 1,
      anon_sym_EQ,
  [101] = 1,
    ACTIONS(71), 1,
      ts_builtin_sym_end,
  [105] = 1,
    ACTIONS(73), 1,
      ts_builtin_sym_end,
  [109] = 1,
    ACTIONS(75), 1,
      ts_builtin_sym_end,
  [113] = 1,
    ACTIONS(77), 1,
      aux_sym_code_token1,
  [117] = 1,
    ACTIONS(79), 1,
      aux_sym_italic_token1,
  [121] = 1,
    ACTIONS(81), 1,
      aux_sym_bold_token1,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(4)] = 0,
  [SMALL_STATE(5)] = 11,
  [SMALL_STATE(6)] = 22,
  [SMALL_STATE(7)] = 33,
  [SMALL_STATE(8)] = 44,
  [SMALL_STATE(9)] = 55,
  [SMALL_STATE(10)] = 66,
  [SMALL_STATE(11)] = 73,
  [SMALL_STATE(12)] = 77,
  [SMALL_STATE(13)] = 81,
  [SMALL_STATE(14)] = 85,
  [SMALL_STATE(15)] = 89,
  [SMALL_STATE(16)] = 93,
  [SMALL_STATE(17)] = 97,
  [SMALL_STATE(18)] = 101,
  [SMALL_STATE(19)] = 105,
  [SMALL_STATE(20)] = 109,
  [SMALL_STATE(21)] = 113,
  [SMALL_STATE(22)] = 117,
  [SMALL_STATE(23)] = 121,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, SHIFT(3),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(23),
  [7] = {.entry = {.count = 1, .reusable = true}}, SHIFT(22),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(21),
  [11] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
  [13] = {.entry = {.count = 1, .reusable = true}}, SHIFT(8),
  [15] = {.entry = {.count = 1, .reusable = true}}, SHIFT(13),
  [17] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_title_repeat1, 2, 0, 0),
  [19] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_title_repeat1, 2, 0, 0), SHIFT_REPEAT(2),
  [22] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_title_repeat1, 2, 0, 0), SHIFT_REPEAT(23),
  [25] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_title_repeat1, 2, 0, 0), SHIFT_REPEAT(22),
  [28] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_title_repeat1, 2, 0, 0), SHIFT_REPEAT(21),
  [31] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_title_repeat1, 2, 0, 0), SHIFT_REPEAT(11),
  [34] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_title_repeat1, 2, 0, 0), SHIFT_REPEAT(8),
  [37] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_title, 1, 0, 0),
  [39] = {.entry = {.count = 1, .reusable = true}}, SHIFT(2),
  [41] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_verbatim, 3, 0, 0),
  [43] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_code, 3, 0, 0),
  [45] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_italic, 3, 0, 0),
  [47] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_bold, 3, 0, 0),
  [49] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_plain_text, 1, 0, 0),
  [51] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_text_markup, 1, 0, 0),
  [53] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_title_only, 1, 0, 2),
  [55] = {.entry = {.count = 1, .reusable = true}}, SHIFT(18),
  [57] = {.entry = {.count = 1, .reusable = true}}, SHIFT(17),
  [59] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_inline, 1, 1, 0),
  [61] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_title_with_tags, 1, 0, 1),
  [63] = {.entry = {.count = 1, .reusable = true}}, SHIFT(7),
  [65] = {.entry = {.count = 1, .reusable = true}}, SHIFT(6),
  [67] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
  [69] = {.entry = {.count = 1, .reusable = true}}, SHIFT(4),
  [71] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_title_with_tags, 2, 0, 3),
  [73] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_inline, 1, 2, 0),
  [75] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [77] = {.entry = {.count = 1, .reusable = true}}, SHIFT(16),
  [79] = {.entry = {.count = 1, .reusable = true}}, SHIFT(15),
  [81] = {.entry = {.count = 1, .reusable = true}}, SHIFT(14),
};

enum ts_external_scanner_symbol_identifiers {
  ts_external_token_TAGS = 0,
};

static const TSSymbol ts_external_scanner_symbol_map[EXTERNAL_TOKEN_COUNT] = {
  [ts_external_token_TAGS] = sym_TAGS,
};

static const bool ts_external_scanner_states[2][EXTERNAL_TOKEN_COUNT] = {
  [1] = {
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
