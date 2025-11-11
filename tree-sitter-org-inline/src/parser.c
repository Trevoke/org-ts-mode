#include "tree_sitter/parser.h"

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 45
#define LARGE_STATE_COUNT 4
#define SYMBOL_COUNT 42
#define ALIAS_COUNT 0
#define TOKEN_COUNT 26
#define EXTERNAL_TOKEN_COUNT 1
#define FIELD_COUNT 2
#define MAX_ALIAS_SEQUENCE_LENGTH 5
#define PRODUCTION_ID_COUNT 4

enum ts_symbol_identifiers {
  anon_sym_COLON = 1,
  anon_sym_STAR = 2,
  aux_sym_bold_token1 = 3,
  anon_sym_SLASH = 4,
  aux_sym_italic_token1 = 5,
  anon_sym__ = 6,
  aux_sym_underline_token1 = 7,
  anon_sym_TILDE = 8,
  aux_sym_code_token1 = 9,
  anon_sym_EQ = 10,
  aux_sym_verbatim_token1 = 11,
  anon_sym_PLUS = 12,
  aux_sym_strike_through_token1 = 13,
  anon_sym_LBRACK = 14,
  aux_sym_statistics_cookie_token1 = 15,
  anon_sym_PERCENT = 16,
  anon_sym_RBRACK = 17,
  anon_sym_AT_AT = 18,
  aux_sym_export_snippet_token1 = 19,
  aux_sym_export_snippet_token2 = 20,
  anon_sym_LT_LT = 21,
  aux_sym_target_token1 = 22,
  anon_sym_GT_GT = 23,
  aux_sym_plain_text_token1 = 24,
  sym_TAGS = 25,
  sym_inline = 26,
  sym_title_with_tags = 27,
  sym_title_only = 28,
  sym_title = 29,
  sym_text_markup = 30,
  sym_bold = 31,
  sym_italic = 32,
  sym_underline = 33,
  sym_code = 34,
  sym_verbatim = 35,
  sym_strike_through = 36,
  sym_statistics_cookie = 37,
  sym_export_snippet = 38,
  sym_target = 39,
  sym_plain_text = 40,
  aux_sym_title_repeat1 = 41,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [anon_sym_COLON] = ":",
  [anon_sym_STAR] = "*",
  [aux_sym_bold_token1] = "bold_token1",
  [anon_sym_SLASH] = "/",
  [aux_sym_italic_token1] = "italic_token1",
  [anon_sym__] = "_",
  [aux_sym_underline_token1] = "underline_token1",
  [anon_sym_TILDE] = "~",
  [aux_sym_code_token1] = "code_token1",
  [anon_sym_EQ] = "=",
  [aux_sym_verbatim_token1] = "verbatim_token1",
  [anon_sym_PLUS] = "+",
  [aux_sym_strike_through_token1] = "strike_through_token1",
  [anon_sym_LBRACK] = "[",
  [aux_sym_statistics_cookie_token1] = "statistics_cookie_token1",
  [anon_sym_PERCENT] = "%",
  [anon_sym_RBRACK] = "]",
  [anon_sym_AT_AT] = "@@",
  [aux_sym_export_snippet_token1] = "export_snippet_token1",
  [aux_sym_export_snippet_token2] = "export_snippet_token2",
  [anon_sym_LT_LT] = "<<",
  [aux_sym_target_token1] = "target_token1",
  [anon_sym_GT_GT] = ">>",
  [aux_sym_plain_text_token1] = "plain_text_token1",
  [sym_TAGS] = "tags",
  [sym_inline] = "inline",
  [sym_title_with_tags] = "title_with_tags",
  [sym_title_only] = "title_only",
  [sym_title] = "title",
  [sym_text_markup] = "text_markup",
  [sym_bold] = "bold",
  [sym_italic] = "italic",
  [sym_underline] = "underline",
  [sym_code] = "code",
  [sym_verbatim] = "verbatim",
  [sym_strike_through] = "strike_through",
  [sym_statistics_cookie] = "statistics_cookie",
  [sym_export_snippet] = "export_snippet",
  [sym_target] = "target",
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
  [anon_sym__] = anon_sym__,
  [aux_sym_underline_token1] = aux_sym_underline_token1,
  [anon_sym_TILDE] = anon_sym_TILDE,
  [aux_sym_code_token1] = aux_sym_code_token1,
  [anon_sym_EQ] = anon_sym_EQ,
  [aux_sym_verbatim_token1] = aux_sym_verbatim_token1,
  [anon_sym_PLUS] = anon_sym_PLUS,
  [aux_sym_strike_through_token1] = aux_sym_strike_through_token1,
  [anon_sym_LBRACK] = anon_sym_LBRACK,
  [aux_sym_statistics_cookie_token1] = aux_sym_statistics_cookie_token1,
  [anon_sym_PERCENT] = anon_sym_PERCENT,
  [anon_sym_RBRACK] = anon_sym_RBRACK,
  [anon_sym_AT_AT] = anon_sym_AT_AT,
  [aux_sym_export_snippet_token1] = aux_sym_export_snippet_token1,
  [aux_sym_export_snippet_token2] = aux_sym_export_snippet_token2,
  [anon_sym_LT_LT] = anon_sym_LT_LT,
  [aux_sym_target_token1] = aux_sym_target_token1,
  [anon_sym_GT_GT] = anon_sym_GT_GT,
  [aux_sym_plain_text_token1] = aux_sym_plain_text_token1,
  [sym_TAGS] = sym_TAGS,
  [sym_inline] = sym_inline,
  [sym_title_with_tags] = sym_title_with_tags,
  [sym_title_only] = sym_title_only,
  [sym_title] = sym_title,
  [sym_text_markup] = sym_text_markup,
  [sym_bold] = sym_bold,
  [sym_italic] = sym_italic,
  [sym_underline] = sym_underline,
  [sym_code] = sym_code,
  [sym_verbatim] = sym_verbatim,
  [sym_strike_through] = sym_strike_through,
  [sym_statistics_cookie] = sym_statistics_cookie,
  [sym_export_snippet] = sym_export_snippet,
  [sym_target] = sym_target,
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
  [anon_sym__] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_underline_token1] = {
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
  [anon_sym_PLUS] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_strike_through_token1] = {
    .visible = false,
    .named = false,
  },
  [anon_sym_LBRACK] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_statistics_cookie_token1] = {
    .visible = false,
    .named = false,
  },
  [anon_sym_PERCENT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RBRACK] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_AT_AT] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_export_snippet_token1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_export_snippet_token2] = {
    .visible = false,
    .named = false,
  },
  [anon_sym_LT_LT] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_target_token1] = {
    .visible = false,
    .named = false,
  },
  [anon_sym_GT_GT] = {
    .visible = true,
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
  [sym_underline] = {
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
  [sym_strike_through] = {
    .visible = true,
    .named = true,
  },
  [sym_statistics_cookie] = {
    .visible = true,
    .named = true,
  },
  [sym_export_snippet] = {
    .visible = true,
    .named = true,
  },
  [sym_target] = {
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
  [24] = 24,
  [25] = 25,
  [26] = 26,
  [27] = 27,
  [28] = 28,
  [29] = 29,
  [30] = 30,
  [31] = 31,
  [32] = 32,
  [33] = 33,
  [34] = 34,
  [35] = 35,
  [36] = 36,
  [37] = 37,
  [38] = 38,
  [39] = 39,
  [40] = 40,
  [41] = 41,
  [42] = 42,
  [43] = 43,
  [44] = 44,
};

static TSCharacterRange aux_sym_plain_text_token1_character_set_1[] = {
  {0, '\t'}, {0x0b, ')'}, {',', '.'}, {'0', '9'}, {';', ';'}, {'?', '?'}, {'A', 'Z'}, {'\\', '\\'},
  {'^', '^'}, {'`', '}'}, {0x7f, 0x10ffff},
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(19);
      if (lookahead == '\n') SKIP(0);
      if (lookahead == '%') ADVANCE(36);
      if (lookahead == '*') ADVANCE(21);
      if (lookahead == '+') ADVANCE(31);
      if (lookahead == '/') ADVANCE(23);
      if (lookahead == ':') ADVANCE(20);
      if (lookahead == '<') ADVANCE(9);
      if (lookahead == '=') ADVANCE(29);
      if (lookahead == '>') ADVANCE(10);
      if (lookahead == '@') ADVANCE(11);
      if (lookahead == '[') ADVANCE(33);
      if (lookahead == ']') ADVANCE(37);
      if (lookahead == '_') ADVANCE(25);
      if (lookahead == '~') ADVANCE(27);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(39);
      if (lookahead != 0) ADVANCE(45);
      END_STATE();
    case 1:
      if (lookahead == '\n') SKIP(1);
      if (lookahead == '%') ADVANCE(35);
      if (lookahead == '/') ADVANCE(23);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(40);
      END_STATE();
    case 2:
      if (lookahead == '\n') SKIP(2);
      if (lookahead != 0 &&
          lookahead != '<' &&
          lookahead != '>') ADVANCE(43);
      END_STATE();
    case 3:
      if (lookahead == '\n') SKIP(3);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '+') ADVANCE(32);
      END_STATE();
    case 4:
      if (lookahead == '\n') SKIP(4);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '=') ADVANCE(30);
      END_STATE();
    case 5:
      if (lookahead == '\n') SKIP(5);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '~') ADVANCE(28);
      END_STATE();
    case 6:
      if (lookahead == '\n') SKIP(6);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '_') ADVANCE(26);
      END_STATE();
    case 7:
      if (lookahead == '\n') SKIP(7);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '/') ADVANCE(24);
      END_STATE();
    case 8:
      if (lookahead == '\n') SKIP(8);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '*') ADVANCE(22);
      END_STATE();
    case 9:
      if (lookahead == '<') ADVANCE(42);
      END_STATE();
    case 10:
      if (lookahead == '>') ADVANCE(44);
      END_STATE();
    case 11:
      if (lookahead == '@') ADVANCE(38);
      END_STATE();
    case 12:
      if (lookahead == '\t' ||
          (0x0b <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(12);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != '+') ADVANCE(32);
      END_STATE();
    case 13:
      if (lookahead == '\t' ||
          (0x0b <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(13);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != '=') ADVANCE(30);
      END_STATE();
    case 14:
      if (lookahead == '\t' ||
          (0x0b <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(14);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != '~') ADVANCE(28);
      END_STATE();
    case 15:
      if (lookahead == '\t' ||
          (0x0b <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(15);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != '_') ADVANCE(26);
      END_STATE();
    case 16:
      if (lookahead == '\t' ||
          (0x0b <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(16);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != '/') ADVANCE(24);
      END_STATE();
    case 17:
      if (lookahead == '\t' ||
          (0x0b <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(17);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != '*') ADVANCE(22);
      END_STATE();
    case 18:
      if (eof) ADVANCE(19);
      if (lookahead == '\n') SKIP(18);
      if (lookahead == '*') ADVANCE(21);
      if (lookahead == '+') ADVANCE(31);
      if (lookahead == '/') ADVANCE(23);
      if (lookahead == ':') ADVANCE(20);
      if (lookahead == '<') ADVANCE(9);
      if (lookahead == '=') ADVANCE(29);
      if (lookahead == '@') ADVANCE(11);
      if (lookahead == '[') ADVANCE(33);
      if (lookahead == '_') ADVANCE(25);
      if (lookahead == '~') ADVANCE(27);
      if (lookahead != 0 &&
          (lookahead < '<' || '>' < lookahead) &&
          lookahead != ']') ADVANCE(45);
      END_STATE();
    case 19:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 20:
      ACCEPT_TOKEN(anon_sym_COLON);
      END_STATE();
    case 21:
      ACCEPT_TOKEN(anon_sym_STAR);
      END_STATE();
    case 22:
      ACCEPT_TOKEN(aux_sym_bold_token1);
      if (lookahead == '\t' ||
          (0x0b <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(17);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != '*') ADVANCE(22);
      END_STATE();
    case 23:
      ACCEPT_TOKEN(anon_sym_SLASH);
      END_STATE();
    case 24:
      ACCEPT_TOKEN(aux_sym_italic_token1);
      if (lookahead == '\t' ||
          (0x0b <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(16);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != '/') ADVANCE(24);
      END_STATE();
    case 25:
      ACCEPT_TOKEN(anon_sym__);
      END_STATE();
    case 26:
      ACCEPT_TOKEN(aux_sym_underline_token1);
      if (lookahead == '\t' ||
          (0x0b <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(15);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != '_') ADVANCE(26);
      END_STATE();
    case 27:
      ACCEPT_TOKEN(anon_sym_TILDE);
      END_STATE();
    case 28:
      ACCEPT_TOKEN(aux_sym_code_token1);
      if (lookahead == '\t' ||
          (0x0b <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(14);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != '~') ADVANCE(28);
      END_STATE();
    case 29:
      ACCEPT_TOKEN(anon_sym_EQ);
      END_STATE();
    case 30:
      ACCEPT_TOKEN(aux_sym_verbatim_token1);
      if (lookahead == '\t' ||
          (0x0b <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(13);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != '=') ADVANCE(30);
      END_STATE();
    case 31:
      ACCEPT_TOKEN(anon_sym_PLUS);
      END_STATE();
    case 32:
      ACCEPT_TOKEN(aux_sym_strike_through_token1);
      if (lookahead == '\t' ||
          (0x0b <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(12);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != '+') ADVANCE(32);
      END_STATE();
    case 33:
      ACCEPT_TOKEN(anon_sym_LBRACK);
      END_STATE();
    case 34:
      ACCEPT_TOKEN(aux_sym_statistics_cookie_token1);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(34);
      END_STATE();
    case 35:
      ACCEPT_TOKEN(anon_sym_PERCENT);
      END_STATE();
    case 36:
      ACCEPT_TOKEN(anon_sym_PERCENT);
      if ((!eof && set_contains(aux_sym_plain_text_token1_character_set_1, 11, lookahead))) ADVANCE(45);
      END_STATE();
    case 37:
      ACCEPT_TOKEN(anon_sym_RBRACK);
      END_STATE();
    case 38:
      ACCEPT_TOKEN(anon_sym_AT_AT);
      END_STATE();
    case 39:
      ACCEPT_TOKEN(aux_sym_export_snippet_token1);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(39);
      if ((!eof && set_contains(aux_sym_plain_text_token1_character_set_1, 11, lookahead))) ADVANCE(45);
      END_STATE();
    case 40:
      ACCEPT_TOKEN(aux_sym_export_snippet_token1);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(40);
      END_STATE();
    case 41:
      ACCEPT_TOKEN(aux_sym_export_snippet_token2);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '@') ADVANCE(41);
      END_STATE();
    case 42:
      ACCEPT_TOKEN(anon_sym_LT_LT);
      END_STATE();
    case 43:
      ACCEPT_TOKEN(aux_sym_target_token1);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '<' &&
          lookahead != '>') ADVANCE(43);
      END_STATE();
    case 44:
      ACCEPT_TOKEN(anon_sym_GT_GT);
      END_STATE();
    case 45:
      ACCEPT_TOKEN(aux_sym_plain_text_token1);
      if ((!eof && set_contains(aux_sym_plain_text_token1_character_set_1, 11, lookahead))) ADVANCE(45);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0, .external_lex_state = 1},
  [1] = {.lex_state = 18, .external_lex_state = 1},
  [2] = {.lex_state = 18, .external_lex_state = 1},
  [3] = {.lex_state = 18, .external_lex_state = 1},
  [4] = {.lex_state = 18, .external_lex_state = 1},
  [5] = {.lex_state = 18, .external_lex_state = 1},
  [6] = {.lex_state = 18, .external_lex_state = 1},
  [7] = {.lex_state = 18, .external_lex_state = 1},
  [8] = {.lex_state = 18, .external_lex_state = 1},
  [9] = {.lex_state = 18, .external_lex_state = 1},
  [10] = {.lex_state = 18, .external_lex_state = 1},
  [11] = {.lex_state = 18, .external_lex_state = 1},
  [12] = {.lex_state = 18, .external_lex_state = 1},
  [13] = {.lex_state = 18, .external_lex_state = 1},
  [14] = {.lex_state = 18, .external_lex_state = 1},
  [15] = {.lex_state = 18, .external_lex_state = 1},
  [16] = {.lex_state = 1},
  [17] = {.lex_state = 0, .external_lex_state = 1},
  [18] = {.lex_state = 2},
  [19] = {.lex_state = 0},
  [20] = {.lex_state = 0},
  [21] = {.lex_state = 0},
  [22] = {.lex_state = 0},
  [23] = {.lex_state = 0},
  [24] = {.lex_state = 0},
  [25] = {.lex_state = 0},
  [26] = {.lex_state = 0},
  [27] = {.lex_state = 0},
  [28] = {.lex_state = 0},
  [29] = {.lex_state = 0},
  [30] = {.lex_state = 0},
  [31] = {.lex_state = 0},
  [32] = {.lex_state = 1},
  [33] = {.lex_state = 34},
  [34] = {.lex_state = 3},
  [35] = {.lex_state = 4},
  [36] = {.lex_state = 34},
  [37] = {.lex_state = 0},
  [38] = {.lex_state = 41},
  [39] = {.lex_state = 5},
  [40] = {.lex_state = 0},
  [41] = {.lex_state = 6},
  [42] = {.lex_state = 0},
  [43] = {.lex_state = 7},
  [44] = {.lex_state = 8},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [anon_sym_COLON] = ACTIONS(1),
    [anon_sym_STAR] = ACTIONS(1),
    [anon_sym_SLASH] = ACTIONS(1),
    [anon_sym__] = ACTIONS(1),
    [anon_sym_TILDE] = ACTIONS(1),
    [anon_sym_EQ] = ACTIONS(1),
    [anon_sym_PLUS] = ACTIONS(1),
    [anon_sym_LBRACK] = ACTIONS(1),
    [anon_sym_PERCENT] = ACTIONS(1),
    [anon_sym_RBRACK] = ACTIONS(1),
    [anon_sym_AT_AT] = ACTIONS(1),
    [aux_sym_export_snippet_token1] = ACTIONS(1),
    [anon_sym_LT_LT] = ACTIONS(1),
    [anon_sym_GT_GT] = ACTIONS(1),
    [aux_sym_plain_text_token1] = ACTIONS(1),
    [sym_TAGS] = ACTIONS(1),
  },
  [1] = {
    [sym_inline] = STATE(19),
    [sym_title_with_tags] = STATE(30),
    [sym_title_only] = STATE(29),
    [sym_title] = STATE(17),
    [sym_text_markup] = STATE(2),
    [sym_bold] = STATE(15),
    [sym_italic] = STATE(15),
    [sym_underline] = STATE(15),
    [sym_code] = STATE(15),
    [sym_verbatim] = STATE(15),
    [sym_strike_through] = STATE(15),
    [sym_statistics_cookie] = STATE(2),
    [sym_export_snippet] = STATE(2),
    [sym_target] = STATE(2),
    [sym_plain_text] = STATE(2),
    [aux_sym_title_repeat1] = STATE(2),
    [anon_sym_COLON] = ACTIONS(3),
    [anon_sym_STAR] = ACTIONS(5),
    [anon_sym_SLASH] = ACTIONS(7),
    [anon_sym__] = ACTIONS(9),
    [anon_sym_TILDE] = ACTIONS(11),
    [anon_sym_EQ] = ACTIONS(13),
    [anon_sym_PLUS] = ACTIONS(15),
    [anon_sym_LBRACK] = ACTIONS(17),
    [anon_sym_AT_AT] = ACTIONS(19),
    [anon_sym_LT_LT] = ACTIONS(21),
    [aux_sym_plain_text_token1] = ACTIONS(23),
    [sym_TAGS] = ACTIONS(25),
  },
  [2] = {
    [sym_text_markup] = STATE(3),
    [sym_bold] = STATE(15),
    [sym_italic] = STATE(15),
    [sym_underline] = STATE(15),
    [sym_code] = STATE(15),
    [sym_verbatim] = STATE(15),
    [sym_strike_through] = STATE(15),
    [sym_statistics_cookie] = STATE(3),
    [sym_export_snippet] = STATE(3),
    [sym_target] = STATE(3),
    [sym_plain_text] = STATE(3),
    [aux_sym_title_repeat1] = STATE(3),
    [ts_builtin_sym_end] = ACTIONS(27),
    [anon_sym_COLON] = ACTIONS(29),
    [anon_sym_STAR] = ACTIONS(5),
    [anon_sym_SLASH] = ACTIONS(7),
    [anon_sym__] = ACTIONS(9),
    [anon_sym_TILDE] = ACTIONS(11),
    [anon_sym_EQ] = ACTIONS(13),
    [anon_sym_PLUS] = ACTIONS(15),
    [anon_sym_LBRACK] = ACTIONS(17),
    [anon_sym_AT_AT] = ACTIONS(19),
    [anon_sym_LT_LT] = ACTIONS(21),
    [aux_sym_plain_text_token1] = ACTIONS(23),
    [sym_TAGS] = ACTIONS(27),
  },
  [3] = {
    [sym_text_markup] = STATE(3),
    [sym_bold] = STATE(15),
    [sym_italic] = STATE(15),
    [sym_underline] = STATE(15),
    [sym_code] = STATE(15),
    [sym_verbatim] = STATE(15),
    [sym_strike_through] = STATE(15),
    [sym_statistics_cookie] = STATE(3),
    [sym_export_snippet] = STATE(3),
    [sym_target] = STATE(3),
    [sym_plain_text] = STATE(3),
    [aux_sym_title_repeat1] = STATE(3),
    [ts_builtin_sym_end] = ACTIONS(31),
    [anon_sym_COLON] = ACTIONS(33),
    [anon_sym_STAR] = ACTIONS(36),
    [anon_sym_SLASH] = ACTIONS(39),
    [anon_sym__] = ACTIONS(42),
    [anon_sym_TILDE] = ACTIONS(45),
    [anon_sym_EQ] = ACTIONS(48),
    [anon_sym_PLUS] = ACTIONS(51),
    [anon_sym_LBRACK] = ACTIONS(54),
    [anon_sym_AT_AT] = ACTIONS(57),
    [anon_sym_LT_LT] = ACTIONS(60),
    [aux_sym_plain_text_token1] = ACTIONS(63),
    [sym_TAGS] = ACTIONS(31),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 1,
    ACTIONS(66), 13,
      sym_TAGS,
      ts_builtin_sym_end,
      anon_sym_COLON,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym__,
      anon_sym_TILDE,
      anon_sym_EQ,
      anon_sym_PLUS,
      anon_sym_LBRACK,
      anon_sym_AT_AT,
      anon_sym_LT_LT,
      aux_sym_plain_text_token1,
  [16] = 1,
    ACTIONS(68), 13,
      sym_TAGS,
      ts_builtin_sym_end,
      anon_sym_COLON,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym__,
      anon_sym_TILDE,
      anon_sym_EQ,
      anon_sym_PLUS,
      anon_sym_LBRACK,
      anon_sym_AT_AT,
      anon_sym_LT_LT,
      aux_sym_plain_text_token1,
  [32] = 1,
    ACTIONS(70), 13,
      sym_TAGS,
      ts_builtin_sym_end,
      anon_sym_COLON,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym__,
      anon_sym_TILDE,
      anon_sym_EQ,
      anon_sym_PLUS,
      anon_sym_LBRACK,
      anon_sym_AT_AT,
      anon_sym_LT_LT,
      aux_sym_plain_text_token1,
  [48] = 1,
    ACTIONS(72), 13,
      sym_TAGS,
      ts_builtin_sym_end,
      anon_sym_COLON,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym__,
      anon_sym_TILDE,
      anon_sym_EQ,
      anon_sym_PLUS,
      anon_sym_LBRACK,
      anon_sym_AT_AT,
      anon_sym_LT_LT,
      aux_sym_plain_text_token1,
  [64] = 1,
    ACTIONS(74), 13,
      sym_TAGS,
      ts_builtin_sym_end,
      anon_sym_COLON,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym__,
      anon_sym_TILDE,
      anon_sym_EQ,
      anon_sym_PLUS,
      anon_sym_LBRACK,
      anon_sym_AT_AT,
      anon_sym_LT_LT,
      aux_sym_plain_text_token1,
  [80] = 1,
    ACTIONS(76), 13,
      sym_TAGS,
      ts_builtin_sym_end,
      anon_sym_COLON,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym__,
      anon_sym_TILDE,
      anon_sym_EQ,
      anon_sym_PLUS,
      anon_sym_LBRACK,
      anon_sym_AT_AT,
      anon_sym_LT_LT,
      aux_sym_plain_text_token1,
  [96] = 1,
    ACTIONS(78), 13,
      sym_TAGS,
      ts_builtin_sym_end,
      anon_sym_COLON,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym__,
      anon_sym_TILDE,
      anon_sym_EQ,
      anon_sym_PLUS,
      anon_sym_LBRACK,
      anon_sym_AT_AT,
      anon_sym_LT_LT,
      aux_sym_plain_text_token1,
  [112] = 1,
    ACTIONS(80), 13,
      sym_TAGS,
      ts_builtin_sym_end,
      anon_sym_COLON,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym__,
      anon_sym_TILDE,
      anon_sym_EQ,
      anon_sym_PLUS,
      anon_sym_LBRACK,
      anon_sym_AT_AT,
      anon_sym_LT_LT,
      aux_sym_plain_text_token1,
  [128] = 1,
    ACTIONS(82), 13,
      sym_TAGS,
      ts_builtin_sym_end,
      anon_sym_COLON,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym__,
      anon_sym_TILDE,
      anon_sym_EQ,
      anon_sym_PLUS,
      anon_sym_LBRACK,
      anon_sym_AT_AT,
      anon_sym_LT_LT,
      aux_sym_plain_text_token1,
  [144] = 1,
    ACTIONS(84), 13,
      sym_TAGS,
      ts_builtin_sym_end,
      anon_sym_COLON,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym__,
      anon_sym_TILDE,
      anon_sym_EQ,
      anon_sym_PLUS,
      anon_sym_LBRACK,
      anon_sym_AT_AT,
      anon_sym_LT_LT,
      aux_sym_plain_text_token1,
  [160] = 1,
    ACTIONS(86), 13,
      sym_TAGS,
      ts_builtin_sym_end,
      anon_sym_COLON,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym__,
      anon_sym_TILDE,
      anon_sym_EQ,
      anon_sym_PLUS,
      anon_sym_LBRACK,
      anon_sym_AT_AT,
      anon_sym_LT_LT,
      aux_sym_plain_text_token1,
  [176] = 1,
    ACTIONS(88), 13,
      sym_TAGS,
      ts_builtin_sym_end,
      anon_sym_COLON,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym__,
      anon_sym_TILDE,
      anon_sym_EQ,
      anon_sym_PLUS,
      anon_sym_LBRACK,
      anon_sym_AT_AT,
      anon_sym_LT_LT,
      aux_sym_plain_text_token1,
  [192] = 2,
    ACTIONS(90), 1,
      anon_sym_SLASH,
    ACTIONS(92), 1,
      anon_sym_PERCENT,
  [199] = 2,
    ACTIONS(94), 1,
      ts_builtin_sym_end,
    ACTIONS(96), 1,
      sym_TAGS,
  [206] = 1,
    ACTIONS(98), 1,
      aux_sym_target_token1,
  [210] = 1,
    ACTIONS(100), 1,
      ts_builtin_sym_end,
  [214] = 1,
    ACTIONS(102), 1,
      anon_sym_SLASH,
  [218] = 1,
    ACTIONS(104), 1,
      anon_sym__,
  [222] = 1,
    ACTIONS(106), 1,
      anon_sym_TILDE,
  [226] = 1,
    ACTIONS(108), 1,
      anon_sym_EQ,
  [230] = 1,
    ACTIONS(110), 1,
      anon_sym_PLUS,
  [234] = 1,
    ACTIONS(112), 1,
      ts_builtin_sym_end,
  [238] = 1,
    ACTIONS(114), 1,
      anon_sym_COLON,
  [242] = 1,
    ACTIONS(116), 1,
      anon_sym_GT_GT,
  [246] = 1,
    ACTIONS(118), 1,
      ts_builtin_sym_end,
  [250] = 1,
    ACTIONS(120), 1,
      ts_builtin_sym_end,
  [254] = 1,
    ACTIONS(122), 1,
      ts_builtin_sym_end,
  [258] = 1,
    ACTIONS(124), 1,
      anon_sym_STAR,
  [262] = 1,
    ACTIONS(126), 1,
      aux_sym_export_snippet_token1,
  [266] = 1,
    ACTIONS(128), 1,
      aux_sym_statistics_cookie_token1,
  [270] = 1,
    ACTIONS(130), 1,
      aux_sym_strike_through_token1,
  [274] = 1,
    ACTIONS(132), 1,
      aux_sym_verbatim_token1,
  [278] = 1,
    ACTIONS(134), 1,
      aux_sym_statistics_cookie_token1,
  [282] = 1,
    ACTIONS(136), 1,
      anon_sym_RBRACK,
  [286] = 1,
    ACTIONS(138), 1,
      aux_sym_export_snippet_token2,
  [290] = 1,
    ACTIONS(140), 1,
      aux_sym_code_token1,
  [294] = 1,
    ACTIONS(142), 1,
      anon_sym_RBRACK,
  [298] = 1,
    ACTIONS(144), 1,
      aux_sym_underline_token1,
  [302] = 1,
    ACTIONS(146), 1,
      anon_sym_AT_AT,
  [306] = 1,
    ACTIONS(148), 1,
      aux_sym_italic_token1,
  [310] = 1,
    ACTIONS(150), 1,
      aux_sym_bold_token1,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(4)] = 0,
  [SMALL_STATE(5)] = 16,
  [SMALL_STATE(6)] = 32,
  [SMALL_STATE(7)] = 48,
  [SMALL_STATE(8)] = 64,
  [SMALL_STATE(9)] = 80,
  [SMALL_STATE(10)] = 96,
  [SMALL_STATE(11)] = 112,
  [SMALL_STATE(12)] = 128,
  [SMALL_STATE(13)] = 144,
  [SMALL_STATE(14)] = 160,
  [SMALL_STATE(15)] = 176,
  [SMALL_STATE(16)] = 192,
  [SMALL_STATE(17)] = 199,
  [SMALL_STATE(18)] = 206,
  [SMALL_STATE(19)] = 210,
  [SMALL_STATE(20)] = 214,
  [SMALL_STATE(21)] = 218,
  [SMALL_STATE(22)] = 222,
  [SMALL_STATE(23)] = 226,
  [SMALL_STATE(24)] = 230,
  [SMALL_STATE(25)] = 234,
  [SMALL_STATE(26)] = 238,
  [SMALL_STATE(27)] = 242,
  [SMALL_STATE(28)] = 246,
  [SMALL_STATE(29)] = 250,
  [SMALL_STATE(30)] = 254,
  [SMALL_STATE(31)] = 258,
  [SMALL_STATE(32)] = 262,
  [SMALL_STATE(33)] = 266,
  [SMALL_STATE(34)] = 270,
  [SMALL_STATE(35)] = 274,
  [SMALL_STATE(36)] = 278,
  [SMALL_STATE(37)] = 282,
  [SMALL_STATE(38)] = 286,
  [SMALL_STATE(39)] = 290,
  [SMALL_STATE(40)] = 294,
  [SMALL_STATE(41)] = 298,
  [SMALL_STATE(42)] = 302,
  [SMALL_STATE(43)] = 306,
  [SMALL_STATE(44)] = 310,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, SHIFT(2),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(44),
  [7] = {.entry = {.count = 1, .reusable = true}}, SHIFT(43),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(41),
  [11] = {.entry = {.count = 1, .reusable = true}}, SHIFT(39),
  [13] = {.entry = {.count = 1, .reusable = true}}, SHIFT(35),
  [15] = {.entry = {.count = 1, .reusable = true}}, SHIFT(34),
  [17] = {.entry = {.count = 1, .reusable = true}}, SHIFT(33),
  [19] = {.entry = {.count = 1, .reusable = true}}, SHIFT(32),
  [21] = {.entry = {.count = 1, .reusable = true}}, SHIFT(18),
  [23] = {.entry = {.count = 1, .reusable = true}}, SHIFT(13),
  [25] = {.entry = {.count = 1, .reusable = true}}, SHIFT(25),
  [27] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_title, 1, 0, 0),
  [29] = {.entry = {.count = 1, .reusable = true}}, SHIFT(3),
  [31] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_title_repeat1, 2, 0, 0),
  [33] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_title_repeat1, 2, 0, 0), SHIFT_REPEAT(3),
  [36] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_title_repeat1, 2, 0, 0), SHIFT_REPEAT(44),
  [39] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_title_repeat1, 2, 0, 0), SHIFT_REPEAT(43),
  [42] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_title_repeat1, 2, 0, 0), SHIFT_REPEAT(41),
  [45] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_title_repeat1, 2, 0, 0), SHIFT_REPEAT(39),
  [48] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_title_repeat1, 2, 0, 0), SHIFT_REPEAT(35),
  [51] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_title_repeat1, 2, 0, 0), SHIFT_REPEAT(34),
  [54] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_title_repeat1, 2, 0, 0), SHIFT_REPEAT(33),
  [57] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_title_repeat1, 2, 0, 0), SHIFT_REPEAT(32),
  [60] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_title_repeat1, 2, 0, 0), SHIFT_REPEAT(18),
  [63] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_title_repeat1, 2, 0, 0), SHIFT_REPEAT(13),
  [66] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_export_snippet, 5, 0, 0),
  [68] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_statistics_cookie, 5, 0, 0),
  [70] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_statistics_cookie, 4, 0, 0),
  [72] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_target, 3, 0, 0),
  [74] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_strike_through, 3, 0, 0),
  [76] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_verbatim, 3, 0, 0),
  [78] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_code, 3, 0, 0),
  [80] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_underline, 3, 0, 0),
  [82] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_italic, 3, 0, 0),
  [84] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_plain_text, 1, 0, 0),
  [86] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_bold, 3, 0, 0),
  [88] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_text_markup, 1, 0, 0),
  [90] = {.entry = {.count = 1, .reusable = true}}, SHIFT(36),
  [92] = {.entry = {.count = 1, .reusable = true}}, SHIFT(37),
  [94] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_title_only, 1, 0, 2),
  [96] = {.entry = {.count = 1, .reusable = true}}, SHIFT(28),
  [98] = {.entry = {.count = 1, .reusable = true}}, SHIFT(27),
  [100] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [102] = {.entry = {.count = 1, .reusable = true}}, SHIFT(12),
  [104] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
  [106] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
  [108] = {.entry = {.count = 1, .reusable = true}}, SHIFT(9),
  [110] = {.entry = {.count = 1, .reusable = true}}, SHIFT(8),
  [112] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_title_with_tags, 1, 0, 1),
  [114] = {.entry = {.count = 1, .reusable = true}}, SHIFT(38),
  [116] = {.entry = {.count = 1, .reusable = true}}, SHIFT(7),
  [118] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_title_with_tags, 2, 0, 3),
  [120] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_inline, 1, 1, 0),
  [122] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_inline, 1, 2, 0),
  [124] = {.entry = {.count = 1, .reusable = true}}, SHIFT(14),
  [126] = {.entry = {.count = 1, .reusable = true}}, SHIFT(26),
  [128] = {.entry = {.count = 1, .reusable = true}}, SHIFT(16),
  [130] = {.entry = {.count = 1, .reusable = true}}, SHIFT(24),
  [132] = {.entry = {.count = 1, .reusable = true}}, SHIFT(23),
  [134] = {.entry = {.count = 1, .reusable = true}}, SHIFT(40),
  [136] = {.entry = {.count = 1, .reusable = true}}, SHIFT(6),
  [138] = {.entry = {.count = 1, .reusable = true}}, SHIFT(42),
  [140] = {.entry = {.count = 1, .reusable = true}}, SHIFT(22),
  [142] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
  [144] = {.entry = {.count = 1, .reusable = true}}, SHIFT(21),
  [146] = {.entry = {.count = 1, .reusable = true}}, SHIFT(4),
  [148] = {.entry = {.count = 1, .reusable = true}}, SHIFT(20),
  [150] = {.entry = {.count = 1, .reusable = true}}, SHIFT(31),
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
