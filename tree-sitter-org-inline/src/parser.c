#include "tree_sitter/parser.h"

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 58
#define LARGE_STATE_COUNT 4
#define SYMBOL_COUNT 56
#define ALIAS_COUNT 0
#define TOKEN_COUNT 37
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
  anon_sym_LT_LT_LT = 24,
  anon_sym_GT_GT_GT = 25,
  anon_sym_LBRACK_LBRACK = 26,
  aux_sym_regular_link_token1 = 27,
  anon_sym_RBRACK_LBRACK = 28,
  anon_sym_RBRACK_RBRACK = 29,
  sym_plain_link = 30,
  anon_sym_LT = 31,
  aux_sym_angle_link_token1 = 32,
  aux_sym_angle_link_token2 = 33,
  anon_sym_GT = 34,
  aux_sym_plain_text_token1 = 35,
  sym_TAGS = 36,
  sym_inline = 37,
  sym_title_with_tags = 38,
  sym_title_only = 39,
  sym_title = 40,
  sym_text_markup = 41,
  sym_bold = 42,
  sym_italic = 43,
  sym_underline = 44,
  sym_code = 45,
  sym_verbatim = 46,
  sym_strike_through = 47,
  sym_statistics_cookie = 48,
  sym_export_snippet = 49,
  sym_target = 50,
  sym_radio_target = 51,
  sym_regular_link = 52,
  sym_angle_link = 53,
  sym_plain_text = 54,
  aux_sym_title_repeat1 = 55,
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
  [anon_sym_LT_LT_LT] = "<<<",
  [anon_sym_GT_GT_GT] = ">>>",
  [anon_sym_LBRACK_LBRACK] = "[[",
  [aux_sym_regular_link_token1] = "regular_link_token1",
  [anon_sym_RBRACK_LBRACK] = "][",
  [anon_sym_RBRACK_RBRACK] = "]]",
  [sym_plain_link] = "plain_link",
  [anon_sym_LT] = "<",
  [aux_sym_angle_link_token1] = "angle_link_token1",
  [aux_sym_angle_link_token2] = "angle_link_token2",
  [anon_sym_GT] = ">",
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
  [sym_radio_target] = "radio_target",
  [sym_regular_link] = "regular_link",
  [sym_angle_link] = "angle_link",
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
  [anon_sym_LT_LT_LT] = anon_sym_LT_LT_LT,
  [anon_sym_GT_GT_GT] = anon_sym_GT_GT_GT,
  [anon_sym_LBRACK_LBRACK] = anon_sym_LBRACK_LBRACK,
  [aux_sym_regular_link_token1] = aux_sym_regular_link_token1,
  [anon_sym_RBRACK_LBRACK] = anon_sym_RBRACK_LBRACK,
  [anon_sym_RBRACK_RBRACK] = anon_sym_RBRACK_RBRACK,
  [sym_plain_link] = sym_plain_link,
  [anon_sym_LT] = anon_sym_LT,
  [aux_sym_angle_link_token1] = aux_sym_angle_link_token1,
  [aux_sym_angle_link_token2] = aux_sym_angle_link_token2,
  [anon_sym_GT] = anon_sym_GT,
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
  [sym_radio_target] = sym_radio_target,
  [sym_regular_link] = sym_regular_link,
  [sym_angle_link] = sym_angle_link,
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
  [anon_sym_LT_LT_LT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_GT_GT_GT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LBRACK_LBRACK] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_regular_link_token1] = {
    .visible = false,
    .named = false,
  },
  [anon_sym_RBRACK_LBRACK] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RBRACK_RBRACK] = {
    .visible = true,
    .named = false,
  },
  [sym_plain_link] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_LT] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_angle_link_token1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_angle_link_token2] = {
    .visible = false,
    .named = false,
  },
  [anon_sym_GT] = {
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
  [sym_radio_target] = {
    .visible = true,
    .named = true,
  },
  [sym_regular_link] = {
    .visible = true,
    .named = true,
  },
  [sym_angle_link] = {
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
  [45] = 45,
  [46] = 46,
  [47] = 47,
  [48] = 48,
  [49] = 49,
  [50] = 50,
  [51] = 51,
  [52] = 52,
  [53] = 53,
  [54] = 54,
  [55] = 55,
  [56] = 56,
  [57] = 57,
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
      if (eof) ADVANCE(33);
      if (lookahead == '\n') SKIP(0);
      if (lookahead == '%') ADVANCE(50);
      if (lookahead == '*') ADVANCE(35);
      if (lookahead == '+') ADVANCE(45);
      if (lookahead == '/') ADVANCE(37);
      if (lookahead == ':') ADVANCE(34);
      if (lookahead == '<') ADVANCE(71);
      if (lookahead == '=') ADVANCE(43);
      if (lookahead == '>') ADVANCE(75);
      if (lookahead == '@') ADVANCE(21);
      if (lookahead == '[') ADVANCE(47);
      if (lookahead == ']') ADVANCE(52);
      if (lookahead == '_') ADVANCE(39);
      if (lookahead == '~') ADVANCE(41);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(54);
      if (lookahead != 0) ADVANCE(77);
      END_STATE();
    case 1:
      if (lookahead == '\n') SKIP(1);
      if (lookahead == '%') ADVANCE(49);
      if (lookahead == '/') ADVANCE(37);
      if (lookahead == '>') ADVANCE(20);
      if (lookahead == ']') ADVANCE(51);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(17);
      END_STATE();
    case 2:
      if (lookahead == '\n') SKIP(2);
      if (lookahead == '>') ADVANCE(74);
      if (lookahead != 0 &&
          lookahead != '<') ADVANCE(58);
      END_STATE();
    case 3:
      if (lookahead == '\n') SKIP(3);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(73);
      END_STATE();
    case 4:
      if (lookahead == '\n') SKIP(4);
      if (lookahead != 0 &&
          lookahead != ']') ADVANCE(64);
      END_STATE();
    case 5:
      if (lookahead == '\n') SKIP(5);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(55);
      END_STATE();
    case 6:
      if (lookahead == '\n') SKIP(6);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '+') ADVANCE(46);
      END_STATE();
    case 7:
      if (lookahead == '\n') SKIP(7);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '=') ADVANCE(44);
      END_STATE();
    case 8:
      if (lookahead == '\n') SKIP(8);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '~') ADVANCE(42);
      END_STATE();
    case 9:
      if (lookahead == '\n') SKIP(9);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '_') ADVANCE(40);
      END_STATE();
    case 10:
      if (lookahead == '\n') SKIP(10);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '/') ADVANCE(38);
      END_STATE();
    case 11:
      if (lookahead == '\n') SKIP(11);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '*') ADVANCE(36);
      END_STATE();
    case 12:
      if (lookahead == '/') ADVANCE(16);
      if (lookahead == '@') ADVANCE(15);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != ':') ADVANCE(22);
      END_STATE();
    case 13:
      if (lookahead == '/') ADVANCE(12);
      if (lookahead == '@') ADVANCE(15);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != ':') ADVANCE(22);
      END_STATE();
    case 14:
      if (lookahead == ':') ADVANCE(13);
      if (lookahead == '+' ||
          lookahead == '-' ||
          lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(14);
      END_STATE();
    case 15:
      if (lookahead == ':') ADVANCE(30);
      if (lookahead == '@') ADVANCE(15);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(67);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ') ADVANCE(15);
      END_STATE();
    case 16:
      if (lookahead == ':') ADVANCE(31);
      if (lookahead == '@') ADVANCE(16);
      if (lookahead == ')' ||
          lookahead == '-' ||
          ('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(68);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ') ADVANCE(16);
      END_STATE();
    case 17:
      if (lookahead == ':') ADVANCE(72);
      if (lookahead == '+' ||
          lookahead == '-' ||
          lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(17);
      END_STATE();
    case 18:
      if (lookahead == '>') ADVANCE(62);
      END_STATE();
    case 19:
      if (lookahead == '>') ADVANCE(59);
      END_STATE();
    case 20:
      if (lookahead == '>') ADVANCE(18);
      END_STATE();
    case 21:
      if (lookahead == '@') ADVANCE(53);
      END_STATE();
    case 22:
      if (lookahead == '@') ADVANCE(15);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != ':') ADVANCE(22);
      END_STATE();
    case 23:
      if (lookahead == '[') ADVANCE(65);
      if (lookahead == ']') ADVANCE(66);
      END_STATE();
    case 24:
      if (lookahead == '\t' ||
          (0x0b <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(24);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != '+') ADVANCE(46);
      END_STATE();
    case 25:
      if (lookahead == '\t' ||
          (0x0b <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(25);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != '=') ADVANCE(44);
      END_STATE();
    case 26:
      if (lookahead == '\t' ||
          (0x0b <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(26);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != '~') ADVANCE(42);
      END_STATE();
    case 27:
      if (lookahead == '\t' ||
          (0x0b <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(27);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != '_') ADVANCE(40);
      END_STATE();
    case 28:
      if (lookahead == '\t' ||
          (0x0b <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(28);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != '/') ADVANCE(38);
      END_STATE();
    case 29:
      if (lookahead == '\t' ||
          (0x0b <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(29);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != '*') ADVANCE(36);
      END_STATE();
    case 30:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(69);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ') ADVANCE(30);
      END_STATE();
    case 31:
      if (lookahead == ')' ||
          lookahead == '-' ||
          ('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(70);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ') ADVANCE(31);
      END_STATE();
    case 32:
      if (eof) ADVANCE(33);
      if (lookahead == '\n') SKIP(32);
      if (lookahead == '*') ADVANCE(35);
      if (lookahead == '+') ADVANCE(45);
      if (lookahead == '/') ADVANCE(37);
      if (lookahead == ':') ADVANCE(34);
      if (lookahead == '<') ADVANCE(71);
      if (lookahead == '=') ADVANCE(43);
      if (lookahead == '>') ADVANCE(19);
      if (lookahead == '@') ADVANCE(21);
      if (lookahead == '[') ADVANCE(47);
      if (lookahead == ']') ADVANCE(23);
      if (lookahead == '_') ADVANCE(39);
      if (lookahead == '~') ADVANCE(41);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(76);
      if (lookahead != 0) ADVANCE(77);
      END_STATE();
    case 33:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 34:
      ACCEPT_TOKEN(anon_sym_COLON);
      END_STATE();
    case 35:
      ACCEPT_TOKEN(anon_sym_STAR);
      END_STATE();
    case 36:
      ACCEPT_TOKEN(aux_sym_bold_token1);
      if (lookahead == '\t' ||
          (0x0b <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(29);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != '*') ADVANCE(36);
      END_STATE();
    case 37:
      ACCEPT_TOKEN(anon_sym_SLASH);
      END_STATE();
    case 38:
      ACCEPT_TOKEN(aux_sym_italic_token1);
      if (lookahead == '\t' ||
          (0x0b <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(28);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != '/') ADVANCE(38);
      END_STATE();
    case 39:
      ACCEPT_TOKEN(anon_sym__);
      END_STATE();
    case 40:
      ACCEPT_TOKEN(aux_sym_underline_token1);
      if (lookahead == '\t' ||
          (0x0b <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(27);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != '_') ADVANCE(40);
      END_STATE();
    case 41:
      ACCEPT_TOKEN(anon_sym_TILDE);
      END_STATE();
    case 42:
      ACCEPT_TOKEN(aux_sym_code_token1);
      if (lookahead == '\t' ||
          (0x0b <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(26);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != '~') ADVANCE(42);
      END_STATE();
    case 43:
      ACCEPT_TOKEN(anon_sym_EQ);
      END_STATE();
    case 44:
      ACCEPT_TOKEN(aux_sym_verbatim_token1);
      if (lookahead == '\t' ||
          (0x0b <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(25);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != '=') ADVANCE(44);
      END_STATE();
    case 45:
      ACCEPT_TOKEN(anon_sym_PLUS);
      END_STATE();
    case 46:
      ACCEPT_TOKEN(aux_sym_strike_through_token1);
      if (lookahead == '\t' ||
          (0x0b <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(24);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != '+') ADVANCE(46);
      END_STATE();
    case 47:
      ACCEPT_TOKEN(anon_sym_LBRACK);
      if (lookahead == '[') ADVANCE(63);
      END_STATE();
    case 48:
      ACCEPT_TOKEN(aux_sym_statistics_cookie_token1);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(48);
      END_STATE();
    case 49:
      ACCEPT_TOKEN(anon_sym_PERCENT);
      END_STATE();
    case 50:
      ACCEPT_TOKEN(anon_sym_PERCENT);
      if ((!eof && set_contains(aux_sym_plain_text_token1_character_set_1, 11, lookahead))) ADVANCE(77);
      END_STATE();
    case 51:
      ACCEPT_TOKEN(anon_sym_RBRACK);
      END_STATE();
    case 52:
      ACCEPT_TOKEN(anon_sym_RBRACK);
      if (lookahead == ']') ADVANCE(66);
      END_STATE();
    case 53:
      ACCEPT_TOKEN(anon_sym_AT_AT);
      END_STATE();
    case 54:
      ACCEPT_TOKEN(aux_sym_export_snippet_token1);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(54);
      if ((!eof && set_contains(aux_sym_plain_text_token1_character_set_1, 11, lookahead))) ADVANCE(77);
      END_STATE();
    case 55:
      ACCEPT_TOKEN(aux_sym_export_snippet_token1);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(55);
      END_STATE();
    case 56:
      ACCEPT_TOKEN(aux_sym_export_snippet_token2);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '@') ADVANCE(56);
      END_STATE();
    case 57:
      ACCEPT_TOKEN(anon_sym_LT_LT);
      if (lookahead == '<') ADVANCE(61);
      END_STATE();
    case 58:
      ACCEPT_TOKEN(aux_sym_target_token1);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '<' &&
          lookahead != '>') ADVANCE(58);
      END_STATE();
    case 59:
      ACCEPT_TOKEN(anon_sym_GT_GT);
      END_STATE();
    case 60:
      ACCEPT_TOKEN(anon_sym_GT_GT);
      if (lookahead == '>') ADVANCE(62);
      END_STATE();
    case 61:
      ACCEPT_TOKEN(anon_sym_LT_LT_LT);
      END_STATE();
    case 62:
      ACCEPT_TOKEN(anon_sym_GT_GT_GT);
      END_STATE();
    case 63:
      ACCEPT_TOKEN(anon_sym_LBRACK_LBRACK);
      END_STATE();
    case 64:
      ACCEPT_TOKEN(aux_sym_regular_link_token1);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != ']') ADVANCE(64);
      END_STATE();
    case 65:
      ACCEPT_TOKEN(anon_sym_RBRACK_LBRACK);
      END_STATE();
    case 66:
      ACCEPT_TOKEN(anon_sym_RBRACK_RBRACK);
      END_STATE();
    case 67:
      ACCEPT_TOKEN(sym_plain_link);
      if (lookahead == ':') ADVANCE(30);
      if (lookahead == '@') ADVANCE(15);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(67);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ') ADVANCE(15);
      END_STATE();
    case 68:
      ACCEPT_TOKEN(sym_plain_link);
      if (lookahead == ':') ADVANCE(31);
      if (lookahead == '@') ADVANCE(16);
      if (lookahead == ')' ||
          lookahead == '-' ||
          ('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(68);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ') ADVANCE(16);
      END_STATE();
    case 69:
      ACCEPT_TOKEN(sym_plain_link);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(69);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ') ADVANCE(30);
      END_STATE();
    case 70:
      ACCEPT_TOKEN(sym_plain_link);
      if (lookahead == ')' ||
          lookahead == '-' ||
          ('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(70);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ') ADVANCE(31);
      END_STATE();
    case 71:
      ACCEPT_TOKEN(anon_sym_LT);
      if (lookahead == '<') ADVANCE(57);
      END_STATE();
    case 72:
      ACCEPT_TOKEN(aux_sym_angle_link_token1);
      END_STATE();
    case 73:
      ACCEPT_TOKEN(aux_sym_angle_link_token2);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '>') ADVANCE(73);
      END_STATE();
    case 74:
      ACCEPT_TOKEN(anon_sym_GT);
      END_STATE();
    case 75:
      ACCEPT_TOKEN(anon_sym_GT);
      if (lookahead == '>') ADVANCE(60);
      END_STATE();
    case 76:
      ACCEPT_TOKEN(aux_sym_plain_text_token1);
      if (lookahead == '+') ADVANCE(14);
      if (lookahead == ':') ADVANCE(13);
      if (lookahead == '-' ||
          lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(76);
      if ((!eof && set_contains(aux_sym_plain_text_token1_character_set_1, 11, lookahead))) ADVANCE(77);
      END_STATE();
    case 77:
      ACCEPT_TOKEN(aux_sym_plain_text_token1);
      if ((!eof && set_contains(aux_sym_plain_text_token1_character_set_1, 11, lookahead))) ADVANCE(77);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0, .external_lex_state = 1},
  [1] = {.lex_state = 32, .external_lex_state = 1},
  [2] = {.lex_state = 32, .external_lex_state = 1},
  [3] = {.lex_state = 32, .external_lex_state = 1},
  [4] = {.lex_state = 32, .external_lex_state = 1},
  [5] = {.lex_state = 32, .external_lex_state = 1},
  [6] = {.lex_state = 32, .external_lex_state = 1},
  [7] = {.lex_state = 32, .external_lex_state = 1},
  [8] = {.lex_state = 32, .external_lex_state = 1},
  [9] = {.lex_state = 32, .external_lex_state = 1},
  [10] = {.lex_state = 32, .external_lex_state = 1},
  [11] = {.lex_state = 32, .external_lex_state = 1},
  [12] = {.lex_state = 32, .external_lex_state = 1},
  [13] = {.lex_state = 32, .external_lex_state = 1},
  [14] = {.lex_state = 32, .external_lex_state = 1},
  [15] = {.lex_state = 32, .external_lex_state = 1},
  [16] = {.lex_state = 32, .external_lex_state = 1},
  [17] = {.lex_state = 32, .external_lex_state = 1},
  [18] = {.lex_state = 32, .external_lex_state = 1},
  [19] = {.lex_state = 32, .external_lex_state = 1},
  [20] = {.lex_state = 32},
  [21] = {.lex_state = 0, .external_lex_state = 1},
  [22] = {.lex_state = 1},
  [23] = {.lex_state = 0},
  [24] = {.lex_state = 2},
  [25] = {.lex_state = 0},
  [26] = {.lex_state = 0},
  [27] = {.lex_state = 0},
  [28] = {.lex_state = 0},
  [29] = {.lex_state = 0},
  [30] = {.lex_state = 32},
  [31] = {.lex_state = 1},
  [32] = {.lex_state = 0},
  [33] = {.lex_state = 3},
  [34] = {.lex_state = 0},
  [35] = {.lex_state = 0},
  [36] = {.lex_state = 0},
  [37] = {.lex_state = 0},
  [38] = {.lex_state = 1},
  [39] = {.lex_state = 4},
  [40] = {.lex_state = 0},
  [41] = {.lex_state = 2},
  [42] = {.lex_state = 48},
  [43] = {.lex_state = 1},
  [44] = {.lex_state = 56},
  [45] = {.lex_state = 5},
  [46] = {.lex_state = 48},
  [47] = {.lex_state = 4},
  [48] = {.lex_state = 6},
  [49] = {.lex_state = 2},
  [50] = {.lex_state = 1},
  [51] = {.lex_state = 7},
  [52] = {.lex_state = 0},
  [53] = {.lex_state = 32},
  [54] = {.lex_state = 8},
  [55] = {.lex_state = 9},
  [56] = {.lex_state = 10},
  [57] = {.lex_state = 11},
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
    [anon_sym_LT_LT_LT] = ACTIONS(1),
    [anon_sym_GT_GT_GT] = ACTIONS(1),
    [anon_sym_LBRACK_LBRACK] = ACTIONS(1),
    [anon_sym_RBRACK_RBRACK] = ACTIONS(1),
    [anon_sym_LT] = ACTIONS(1),
    [anon_sym_GT] = ACTIONS(1),
    [aux_sym_plain_text_token1] = ACTIONS(1),
    [sym_TAGS] = ACTIONS(1),
  },
  [1] = {
    [sym_inline] = STATE(37),
    [sym_title_with_tags] = STATE(36),
    [sym_title_only] = STATE(35),
    [sym_title] = STATE(21),
    [sym_text_markup] = STATE(2),
    [sym_bold] = STATE(18),
    [sym_italic] = STATE(18),
    [sym_underline] = STATE(18),
    [sym_code] = STATE(18),
    [sym_verbatim] = STATE(18),
    [sym_strike_through] = STATE(18),
    [sym_statistics_cookie] = STATE(2),
    [sym_export_snippet] = STATE(2),
    [sym_target] = STATE(2),
    [sym_radio_target] = STATE(2),
    [sym_regular_link] = STATE(2),
    [sym_angle_link] = STATE(2),
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
    [anon_sym_LT_LT_LT] = ACTIONS(23),
    [anon_sym_LBRACK_LBRACK] = ACTIONS(25),
    [sym_plain_link] = ACTIONS(3),
    [anon_sym_LT] = ACTIONS(27),
    [aux_sym_plain_text_token1] = ACTIONS(29),
    [sym_TAGS] = ACTIONS(31),
  },
  [2] = {
    [sym_text_markup] = STATE(3),
    [sym_bold] = STATE(18),
    [sym_italic] = STATE(18),
    [sym_underline] = STATE(18),
    [sym_code] = STATE(18),
    [sym_verbatim] = STATE(18),
    [sym_strike_through] = STATE(18),
    [sym_statistics_cookie] = STATE(3),
    [sym_export_snippet] = STATE(3),
    [sym_target] = STATE(3),
    [sym_radio_target] = STATE(3),
    [sym_regular_link] = STATE(3),
    [sym_angle_link] = STATE(3),
    [sym_plain_text] = STATE(3),
    [aux_sym_title_repeat1] = STATE(3),
    [ts_builtin_sym_end] = ACTIONS(33),
    [anon_sym_COLON] = ACTIONS(35),
    [anon_sym_STAR] = ACTIONS(5),
    [anon_sym_SLASH] = ACTIONS(7),
    [anon_sym__] = ACTIONS(9),
    [anon_sym_TILDE] = ACTIONS(11),
    [anon_sym_EQ] = ACTIONS(13),
    [anon_sym_PLUS] = ACTIONS(15),
    [anon_sym_LBRACK] = ACTIONS(17),
    [anon_sym_AT_AT] = ACTIONS(19),
    [anon_sym_LT_LT] = ACTIONS(21),
    [anon_sym_LT_LT_LT] = ACTIONS(23),
    [anon_sym_LBRACK_LBRACK] = ACTIONS(25),
    [sym_plain_link] = ACTIONS(35),
    [anon_sym_LT] = ACTIONS(27),
    [aux_sym_plain_text_token1] = ACTIONS(29),
    [sym_TAGS] = ACTIONS(33),
  },
  [3] = {
    [sym_text_markup] = STATE(3),
    [sym_bold] = STATE(18),
    [sym_italic] = STATE(18),
    [sym_underline] = STATE(18),
    [sym_code] = STATE(18),
    [sym_verbatim] = STATE(18),
    [sym_strike_through] = STATE(18),
    [sym_statistics_cookie] = STATE(3),
    [sym_export_snippet] = STATE(3),
    [sym_target] = STATE(3),
    [sym_radio_target] = STATE(3),
    [sym_regular_link] = STATE(3),
    [sym_angle_link] = STATE(3),
    [sym_plain_text] = STATE(3),
    [aux_sym_title_repeat1] = STATE(3),
    [ts_builtin_sym_end] = ACTIONS(37),
    [anon_sym_COLON] = ACTIONS(39),
    [anon_sym_STAR] = ACTIONS(42),
    [anon_sym_SLASH] = ACTIONS(45),
    [anon_sym__] = ACTIONS(48),
    [anon_sym_TILDE] = ACTIONS(51),
    [anon_sym_EQ] = ACTIONS(54),
    [anon_sym_PLUS] = ACTIONS(57),
    [anon_sym_LBRACK] = ACTIONS(60),
    [anon_sym_AT_AT] = ACTIONS(63),
    [anon_sym_LT_LT] = ACTIONS(66),
    [anon_sym_LT_LT_LT] = ACTIONS(69),
    [anon_sym_LBRACK_LBRACK] = ACTIONS(72),
    [sym_plain_link] = ACTIONS(39),
    [anon_sym_LT] = ACTIONS(75),
    [aux_sym_plain_text_token1] = ACTIONS(78),
    [sym_TAGS] = ACTIONS(37),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 2,
    ACTIONS(83), 4,
      anon_sym_LBRACK,
      anon_sym_LT_LT,
      anon_sym_LT,
      aux_sym_plain_text_token1,
    ACTIONS(81), 13,
      sym_TAGS,
      ts_builtin_sym_end,
      anon_sym_COLON,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym__,
      anon_sym_TILDE,
      anon_sym_EQ,
      anon_sym_PLUS,
      anon_sym_AT_AT,
      anon_sym_LT_LT_LT,
      anon_sym_LBRACK_LBRACK,
      sym_plain_link,
  [22] = 2,
    ACTIONS(87), 4,
      anon_sym_LBRACK,
      anon_sym_LT_LT,
      anon_sym_LT,
      aux_sym_plain_text_token1,
    ACTIONS(85), 13,
      sym_TAGS,
      ts_builtin_sym_end,
      anon_sym_COLON,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym__,
      anon_sym_TILDE,
      anon_sym_EQ,
      anon_sym_PLUS,
      anon_sym_AT_AT,
      anon_sym_LT_LT_LT,
      anon_sym_LBRACK_LBRACK,
      sym_plain_link,
  [44] = 2,
    ACTIONS(91), 4,
      anon_sym_LBRACK,
      anon_sym_LT_LT,
      anon_sym_LT,
      aux_sym_plain_text_token1,
    ACTIONS(89), 13,
      sym_TAGS,
      ts_builtin_sym_end,
      anon_sym_COLON,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym__,
      anon_sym_TILDE,
      anon_sym_EQ,
      anon_sym_PLUS,
      anon_sym_AT_AT,
      anon_sym_LT_LT_LT,
      anon_sym_LBRACK_LBRACK,
      sym_plain_link,
  [66] = 2,
    ACTIONS(95), 4,
      anon_sym_LBRACK,
      anon_sym_LT_LT,
      anon_sym_LT,
      aux_sym_plain_text_token1,
    ACTIONS(93), 13,
      sym_TAGS,
      ts_builtin_sym_end,
      anon_sym_COLON,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym__,
      anon_sym_TILDE,
      anon_sym_EQ,
      anon_sym_PLUS,
      anon_sym_AT_AT,
      anon_sym_LT_LT_LT,
      anon_sym_LBRACK_LBRACK,
      sym_plain_link,
  [88] = 2,
    ACTIONS(99), 4,
      anon_sym_LBRACK,
      anon_sym_LT_LT,
      anon_sym_LT,
      aux_sym_plain_text_token1,
    ACTIONS(97), 13,
      sym_TAGS,
      ts_builtin_sym_end,
      anon_sym_COLON,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym__,
      anon_sym_TILDE,
      anon_sym_EQ,
      anon_sym_PLUS,
      anon_sym_AT_AT,
      anon_sym_LT_LT_LT,
      anon_sym_LBRACK_LBRACK,
      sym_plain_link,
  [110] = 2,
    ACTIONS(103), 4,
      anon_sym_LBRACK,
      anon_sym_LT_LT,
      anon_sym_LT,
      aux_sym_plain_text_token1,
    ACTIONS(101), 13,
      sym_TAGS,
      ts_builtin_sym_end,
      anon_sym_COLON,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym__,
      anon_sym_TILDE,
      anon_sym_EQ,
      anon_sym_PLUS,
      anon_sym_AT_AT,
      anon_sym_LT_LT_LT,
      anon_sym_LBRACK_LBRACK,
      sym_plain_link,
  [132] = 2,
    ACTIONS(107), 4,
      anon_sym_LBRACK,
      anon_sym_LT_LT,
      anon_sym_LT,
      aux_sym_plain_text_token1,
    ACTIONS(105), 13,
      sym_TAGS,
      ts_builtin_sym_end,
      anon_sym_COLON,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym__,
      anon_sym_TILDE,
      anon_sym_EQ,
      anon_sym_PLUS,
      anon_sym_AT_AT,
      anon_sym_LT_LT_LT,
      anon_sym_LBRACK_LBRACK,
      sym_plain_link,
  [154] = 2,
    ACTIONS(111), 4,
      anon_sym_LBRACK,
      anon_sym_LT_LT,
      anon_sym_LT,
      aux_sym_plain_text_token1,
    ACTIONS(109), 13,
      sym_TAGS,
      ts_builtin_sym_end,
      anon_sym_COLON,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym__,
      anon_sym_TILDE,
      anon_sym_EQ,
      anon_sym_PLUS,
      anon_sym_AT_AT,
      anon_sym_LT_LT_LT,
      anon_sym_LBRACK_LBRACK,
      sym_plain_link,
  [176] = 2,
    ACTIONS(115), 4,
      anon_sym_LBRACK,
      anon_sym_LT_LT,
      anon_sym_LT,
      aux_sym_plain_text_token1,
    ACTIONS(113), 13,
      sym_TAGS,
      ts_builtin_sym_end,
      anon_sym_COLON,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym__,
      anon_sym_TILDE,
      anon_sym_EQ,
      anon_sym_PLUS,
      anon_sym_AT_AT,
      anon_sym_LT_LT_LT,
      anon_sym_LBRACK_LBRACK,
      sym_plain_link,
  [198] = 2,
    ACTIONS(119), 4,
      anon_sym_LBRACK,
      anon_sym_LT_LT,
      anon_sym_LT,
      aux_sym_plain_text_token1,
    ACTIONS(117), 13,
      sym_TAGS,
      ts_builtin_sym_end,
      anon_sym_COLON,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym__,
      anon_sym_TILDE,
      anon_sym_EQ,
      anon_sym_PLUS,
      anon_sym_AT_AT,
      anon_sym_LT_LT_LT,
      anon_sym_LBRACK_LBRACK,
      sym_plain_link,
  [220] = 2,
    ACTIONS(123), 4,
      anon_sym_LBRACK,
      anon_sym_LT_LT,
      anon_sym_LT,
      aux_sym_plain_text_token1,
    ACTIONS(121), 13,
      sym_TAGS,
      ts_builtin_sym_end,
      anon_sym_COLON,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym__,
      anon_sym_TILDE,
      anon_sym_EQ,
      anon_sym_PLUS,
      anon_sym_AT_AT,
      anon_sym_LT_LT_LT,
      anon_sym_LBRACK_LBRACK,
      sym_plain_link,
  [242] = 2,
    ACTIONS(127), 4,
      anon_sym_LBRACK,
      anon_sym_LT_LT,
      anon_sym_LT,
      aux_sym_plain_text_token1,
    ACTIONS(125), 13,
      sym_TAGS,
      ts_builtin_sym_end,
      anon_sym_COLON,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym__,
      anon_sym_TILDE,
      anon_sym_EQ,
      anon_sym_PLUS,
      anon_sym_AT_AT,
      anon_sym_LT_LT_LT,
      anon_sym_LBRACK_LBRACK,
      sym_plain_link,
  [264] = 2,
    ACTIONS(131), 4,
      anon_sym_LBRACK,
      anon_sym_LT_LT,
      anon_sym_LT,
      aux_sym_plain_text_token1,
    ACTIONS(129), 13,
      sym_TAGS,
      ts_builtin_sym_end,
      anon_sym_COLON,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym__,
      anon_sym_TILDE,
      anon_sym_EQ,
      anon_sym_PLUS,
      anon_sym_AT_AT,
      anon_sym_LT_LT_LT,
      anon_sym_LBRACK_LBRACK,
      sym_plain_link,
  [286] = 2,
    ACTIONS(135), 4,
      anon_sym_LBRACK,
      anon_sym_LT_LT,
      anon_sym_LT,
      aux_sym_plain_text_token1,
    ACTIONS(133), 13,
      sym_TAGS,
      ts_builtin_sym_end,
      anon_sym_COLON,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym__,
      anon_sym_TILDE,
      anon_sym_EQ,
      anon_sym_PLUS,
      anon_sym_AT_AT,
      anon_sym_LT_LT_LT,
      anon_sym_LBRACK_LBRACK,
      sym_plain_link,
  [308] = 2,
    ACTIONS(139), 4,
      anon_sym_LBRACK,
      anon_sym_LT_LT,
      anon_sym_LT,
      aux_sym_plain_text_token1,
    ACTIONS(137), 13,
      sym_TAGS,
      ts_builtin_sym_end,
      anon_sym_COLON,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym__,
      anon_sym_TILDE,
      anon_sym_EQ,
      anon_sym_PLUS,
      anon_sym_AT_AT,
      anon_sym_LT_LT_LT,
      anon_sym_LBRACK_LBRACK,
      sym_plain_link,
  [330] = 2,
    ACTIONS(143), 4,
      anon_sym_LBRACK,
      anon_sym_LT_LT,
      anon_sym_LT,
      aux_sym_plain_text_token1,
    ACTIONS(141), 13,
      sym_TAGS,
      ts_builtin_sym_end,
      anon_sym_COLON,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym__,
      anon_sym_TILDE,
      anon_sym_EQ,
      anon_sym_PLUS,
      anon_sym_AT_AT,
      anon_sym_LT_LT_LT,
      anon_sym_LBRACK_LBRACK,
      sym_plain_link,
  [352] = 2,
    ACTIONS(145), 1,
      anon_sym_RBRACK_LBRACK,
    ACTIONS(147), 1,
      anon_sym_RBRACK_RBRACK,
  [359] = 2,
    ACTIONS(149), 1,
      ts_builtin_sym_end,
    ACTIONS(151), 1,
      sym_TAGS,
  [366] = 2,
    ACTIONS(153), 1,
      anon_sym_SLASH,
    ACTIONS(155), 1,
      anon_sym_PERCENT,
  [373] = 1,
    ACTIONS(157), 1,
      anon_sym_PLUS,
  [377] = 1,
    ACTIONS(159), 1,
      aux_sym_target_token1,
  [381] = 1,
    ACTIONS(161), 1,
      anon_sym_SLASH,
  [385] = 1,
    ACTIONS(163), 1,
      anon_sym__,
  [389] = 1,
    ACTIONS(165), 1,
      anon_sym_TILDE,
  [393] = 1,
    ACTIONS(167), 1,
      anon_sym_EQ,
  [397] = 1,
    ACTIONS(169), 1,
      anon_sym_COLON,
  [401] = 1,
    ACTIONS(171), 1,
      anon_sym_GT_GT,
  [405] = 1,
    ACTIONS(173), 1,
      anon_sym_GT_GT_GT,
  [409] = 1,
    ACTIONS(175), 1,
      ts_builtin_sym_end,
  [413] = 1,
    ACTIONS(177), 1,
      aux_sym_angle_link_token2,
  [417] = 1,
    ACTIONS(179), 1,
      ts_builtin_sym_end,
  [421] = 1,
    ACTIONS(181), 1,
      ts_builtin_sym_end,
  [425] = 1,
    ACTIONS(183), 1,
      ts_builtin_sym_end,
  [429] = 1,
    ACTIONS(185), 1,
      ts_builtin_sym_end,
  [433] = 1,
    ACTIONS(187), 1,
      aux_sym_angle_link_token1,
  [437] = 1,
    ACTIONS(189), 1,
      aux_sym_regular_link_token1,
  [441] = 1,
    ACTIONS(191), 1,
      anon_sym_STAR,
  [445] = 1,
    ACTIONS(193), 1,
      aux_sym_target_token1,
  [449] = 1,
    ACTIONS(195), 1,
      aux_sym_statistics_cookie_token1,
  [453] = 1,
    ACTIONS(197), 1,
      anon_sym_RBRACK,
  [457] = 1,
    ACTIONS(199), 1,
      aux_sym_export_snippet_token2,
  [461] = 1,
    ACTIONS(201), 1,
      aux_sym_export_snippet_token1,
  [465] = 1,
    ACTIONS(203), 1,
      aux_sym_statistics_cookie_token1,
  [469] = 1,
    ACTIONS(205), 1,
      aux_sym_regular_link_token1,
  [473] = 1,
    ACTIONS(207), 1,
      aux_sym_strike_through_token1,
  [477] = 1,
    ACTIONS(209), 1,
      anon_sym_GT,
  [481] = 1,
    ACTIONS(211), 1,
      anon_sym_RBRACK,
  [485] = 1,
    ACTIONS(213), 1,
      aux_sym_verbatim_token1,
  [489] = 1,
    ACTIONS(215), 1,
      anon_sym_AT_AT,
  [493] = 1,
    ACTIONS(217), 1,
      anon_sym_RBRACK_RBRACK,
  [497] = 1,
    ACTIONS(219), 1,
      aux_sym_code_token1,
  [501] = 1,
    ACTIONS(221), 1,
      aux_sym_underline_token1,
  [505] = 1,
    ACTIONS(223), 1,
      aux_sym_italic_token1,
  [509] = 1,
    ACTIONS(225), 1,
      aux_sym_bold_token1,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(4)] = 0,
  [SMALL_STATE(5)] = 22,
  [SMALL_STATE(6)] = 44,
  [SMALL_STATE(7)] = 66,
  [SMALL_STATE(8)] = 88,
  [SMALL_STATE(9)] = 110,
  [SMALL_STATE(10)] = 132,
  [SMALL_STATE(11)] = 154,
  [SMALL_STATE(12)] = 176,
  [SMALL_STATE(13)] = 198,
  [SMALL_STATE(14)] = 220,
  [SMALL_STATE(15)] = 242,
  [SMALL_STATE(16)] = 264,
  [SMALL_STATE(17)] = 286,
  [SMALL_STATE(18)] = 308,
  [SMALL_STATE(19)] = 330,
  [SMALL_STATE(20)] = 352,
  [SMALL_STATE(21)] = 359,
  [SMALL_STATE(22)] = 366,
  [SMALL_STATE(23)] = 373,
  [SMALL_STATE(24)] = 377,
  [SMALL_STATE(25)] = 381,
  [SMALL_STATE(26)] = 385,
  [SMALL_STATE(27)] = 389,
  [SMALL_STATE(28)] = 393,
  [SMALL_STATE(29)] = 397,
  [SMALL_STATE(30)] = 401,
  [SMALL_STATE(31)] = 405,
  [SMALL_STATE(32)] = 409,
  [SMALL_STATE(33)] = 413,
  [SMALL_STATE(34)] = 417,
  [SMALL_STATE(35)] = 421,
  [SMALL_STATE(36)] = 425,
  [SMALL_STATE(37)] = 429,
  [SMALL_STATE(38)] = 433,
  [SMALL_STATE(39)] = 437,
  [SMALL_STATE(40)] = 441,
  [SMALL_STATE(41)] = 445,
  [SMALL_STATE(42)] = 449,
  [SMALL_STATE(43)] = 453,
  [SMALL_STATE(44)] = 457,
  [SMALL_STATE(45)] = 461,
  [SMALL_STATE(46)] = 465,
  [SMALL_STATE(47)] = 469,
  [SMALL_STATE(48)] = 473,
  [SMALL_STATE(49)] = 477,
  [SMALL_STATE(50)] = 481,
  [SMALL_STATE(51)] = 485,
  [SMALL_STATE(52)] = 489,
  [SMALL_STATE(53)] = 493,
  [SMALL_STATE(54)] = 497,
  [SMALL_STATE(55)] = 501,
  [SMALL_STATE(56)] = 505,
  [SMALL_STATE(57)] = 509,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, SHIFT(2),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(57),
  [7] = {.entry = {.count = 1, .reusable = true}}, SHIFT(56),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(55),
  [11] = {.entry = {.count = 1, .reusable = true}}, SHIFT(54),
  [13] = {.entry = {.count = 1, .reusable = true}}, SHIFT(51),
  [15] = {.entry = {.count = 1, .reusable = true}}, SHIFT(48),
  [17] = {.entry = {.count = 1, .reusable = false}}, SHIFT(46),
  [19] = {.entry = {.count = 1, .reusable = true}}, SHIFT(45),
  [21] = {.entry = {.count = 1, .reusable = false}}, SHIFT(41),
  [23] = {.entry = {.count = 1, .reusable = true}}, SHIFT(24),
  [25] = {.entry = {.count = 1, .reusable = true}}, SHIFT(39),
  [27] = {.entry = {.count = 1, .reusable = false}}, SHIFT(38),
  [29] = {.entry = {.count = 1, .reusable = false}}, SHIFT(15),
  [31] = {.entry = {.count = 1, .reusable = true}}, SHIFT(32),
  [33] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_title, 1, 0, 0),
  [35] = {.entry = {.count = 1, .reusable = true}}, SHIFT(3),
  [37] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_title_repeat1, 2, 0, 0),
  [39] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_title_repeat1, 2, 0, 0), SHIFT_REPEAT(3),
  [42] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_title_repeat1, 2, 0, 0), SHIFT_REPEAT(57),
  [45] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_title_repeat1, 2, 0, 0), SHIFT_REPEAT(56),
  [48] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_title_repeat1, 2, 0, 0), SHIFT_REPEAT(55),
  [51] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_title_repeat1, 2, 0, 0), SHIFT_REPEAT(54),
  [54] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_title_repeat1, 2, 0, 0), SHIFT_REPEAT(51),
  [57] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_title_repeat1, 2, 0, 0), SHIFT_REPEAT(48),
  [60] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_title_repeat1, 2, 0, 0), SHIFT_REPEAT(46),
  [63] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_title_repeat1, 2, 0, 0), SHIFT_REPEAT(45),
  [66] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_title_repeat1, 2, 0, 0), SHIFT_REPEAT(41),
  [69] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_title_repeat1, 2, 0, 0), SHIFT_REPEAT(24),
  [72] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_title_repeat1, 2, 0, 0), SHIFT_REPEAT(39),
  [75] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_title_repeat1, 2, 0, 0), SHIFT_REPEAT(38),
  [78] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_title_repeat1, 2, 0, 0), SHIFT_REPEAT(15),
  [81] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_strike_through, 3, 0, 0),
  [83] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_strike_through, 3, 0, 0),
  [85] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_statistics_cookie, 5, 0, 0),
  [87] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_statistics_cookie, 5, 0, 0),
  [89] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_angle_link, 4, 0, 0),
  [91] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_angle_link, 4, 0, 0),
  [93] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_statistics_cookie, 4, 0, 0),
  [95] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_statistics_cookie, 4, 0, 0),
  [97] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_regular_link, 3, 0, 0),
  [99] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_regular_link, 3, 0, 0),
  [101] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_radio_target, 3, 0, 0),
  [103] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_radio_target, 3, 0, 0),
  [105] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_target, 3, 0, 0),
  [107] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_target, 3, 0, 0),
  [109] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_verbatim, 3, 0, 0),
  [111] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_verbatim, 3, 0, 0),
  [113] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_code, 3, 0, 0),
  [115] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_code, 3, 0, 0),
  [117] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_underline, 3, 0, 0),
  [119] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_underline, 3, 0, 0),
  [121] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_italic, 3, 0, 0),
  [123] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_italic, 3, 0, 0),
  [125] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_plain_text, 1, 0, 0),
  [127] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_plain_text, 1, 0, 0),
  [129] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_bold, 3, 0, 0),
  [131] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_bold, 3, 0, 0),
  [133] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_regular_link, 5, 0, 0),
  [135] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_regular_link, 5, 0, 0),
  [137] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_text_markup, 1, 0, 0),
  [139] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_text_markup, 1, 0, 0),
  [141] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_export_snippet, 5, 0, 0),
  [143] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_export_snippet, 5, 0, 0),
  [145] = {.entry = {.count = 1, .reusable = true}}, SHIFT(47),
  [147] = {.entry = {.count = 1, .reusable = true}}, SHIFT(8),
  [149] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_title_only, 1, 0, 2),
  [151] = {.entry = {.count = 1, .reusable = true}}, SHIFT(34),
  [153] = {.entry = {.count = 1, .reusable = true}}, SHIFT(42),
  [155] = {.entry = {.count = 1, .reusable = true}}, SHIFT(43),
  [157] = {.entry = {.count = 1, .reusable = true}}, SHIFT(4),
  [159] = {.entry = {.count = 1, .reusable = true}}, SHIFT(31),
  [161] = {.entry = {.count = 1, .reusable = true}}, SHIFT(14),
  [163] = {.entry = {.count = 1, .reusable = true}}, SHIFT(13),
  [165] = {.entry = {.count = 1, .reusable = true}}, SHIFT(12),
  [167] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
  [169] = {.entry = {.count = 1, .reusable = true}}, SHIFT(44),
  [171] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
  [173] = {.entry = {.count = 1, .reusable = true}}, SHIFT(9),
  [175] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_title_with_tags, 1, 0, 1),
  [177] = {.entry = {.count = 1, .reusable = true}}, SHIFT(49),
  [179] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_title_with_tags, 2, 0, 3),
  [181] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_inline, 1, 1, 0),
  [183] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_inline, 1, 2, 0),
  [185] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [187] = {.entry = {.count = 1, .reusable = true}}, SHIFT(33),
  [189] = {.entry = {.count = 1, .reusable = true}}, SHIFT(20),
  [191] = {.entry = {.count = 1, .reusable = true}}, SHIFT(16),
  [193] = {.entry = {.count = 1, .reusable = true}}, SHIFT(30),
  [195] = {.entry = {.count = 1, .reusable = true}}, SHIFT(50),
  [197] = {.entry = {.count = 1, .reusable = true}}, SHIFT(7),
  [199] = {.entry = {.count = 1, .reusable = true}}, SHIFT(52),
  [201] = {.entry = {.count = 1, .reusable = true}}, SHIFT(29),
  [203] = {.entry = {.count = 1, .reusable = true}}, SHIFT(22),
  [205] = {.entry = {.count = 1, .reusable = true}}, SHIFT(53),
  [207] = {.entry = {.count = 1, .reusable = true}}, SHIFT(23),
  [209] = {.entry = {.count = 1, .reusable = true}}, SHIFT(6),
  [211] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
  [213] = {.entry = {.count = 1, .reusable = true}}, SHIFT(28),
  [215] = {.entry = {.count = 1, .reusable = true}}, SHIFT(19),
  [217] = {.entry = {.count = 1, .reusable = true}}, SHIFT(17),
  [219] = {.entry = {.count = 1, .reusable = true}}, SHIFT(27),
  [221] = {.entry = {.count = 1, .reusable = true}}, SHIFT(26),
  [223] = {.entry = {.count = 1, .reusable = true}}, SHIFT(25),
  [225] = {.entry = {.count = 1, .reusable = true}}, SHIFT(40),
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
