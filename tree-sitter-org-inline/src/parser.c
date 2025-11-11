#include "tree_sitter/parser.h"

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 55
#define LARGE_STATE_COUNT 4
#define SYMBOL_COUNT 53
#define ALIAS_COUNT 0
#define TOKEN_COUNT 35
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
  anon_sym_LBRACK_LBRACK = 24,
  aux_sym_regular_link_token1 = 25,
  anon_sym_RBRACK_LBRACK = 26,
  anon_sym_RBRACK_RBRACK = 27,
  sym_plain_link = 28,
  anon_sym_LT = 29,
  aux_sym_angle_link_token1 = 30,
  aux_sym_angle_link_token2 = 31,
  anon_sym_GT = 32,
  aux_sym_plain_text_token1 = 33,
  sym_TAGS = 34,
  sym_inline = 35,
  sym_title_with_tags = 36,
  sym_title_only = 37,
  sym_title = 38,
  sym_text_markup = 39,
  sym_bold = 40,
  sym_italic = 41,
  sym_underline = 42,
  sym_code = 43,
  sym_verbatim = 44,
  sym_strike_through = 45,
  sym_statistics_cookie = 46,
  sym_export_snippet = 47,
  sym_target = 48,
  sym_regular_link = 49,
  sym_angle_link = 50,
  sym_plain_text = 51,
  aux_sym_title_repeat1 = 52,
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
      if (eof) ADVANCE(31);
      if (lookahead == '\n') SKIP(0);
      if (lookahead == '%') ADVANCE(48);
      if (lookahead == '*') ADVANCE(33);
      if (lookahead == '+') ADVANCE(43);
      if (lookahead == '/') ADVANCE(35);
      if (lookahead == ':') ADVANCE(32);
      if (lookahead == '<') ADVANCE(66);
      if (lookahead == '=') ADVANCE(41);
      if (lookahead == '>') ADVANCE(70);
      if (lookahead == '@') ADVANCE(19);
      if (lookahead == '[') ADVANCE(45);
      if (lookahead == ']') ADVANCE(50);
      if (lookahead == '_') ADVANCE(37);
      if (lookahead == '~') ADVANCE(39);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(52);
      if (lookahead != 0) ADVANCE(72);
      END_STATE();
    case 1:
      if (lookahead == '\n') SKIP(1);
      if (lookahead == '%') ADVANCE(47);
      if (lookahead == '/') ADVANCE(35);
      if (lookahead == '>') ADVANCE(69);
      if (lookahead == ']') ADVANCE(49);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(53);
      END_STATE();
    case 2:
      if (lookahead == '\n') SKIP(2);
      if (lookahead != 0 &&
          lookahead != ']') ADVANCE(59);
      END_STATE();
    case 3:
      if (lookahead == '\n') SKIP(3);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(68);
      END_STATE();
    case 4:
      if (lookahead == '\n') SKIP(4);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(17);
      END_STATE();
    case 5:
      if (lookahead == '\n') SKIP(5);
      if (lookahead != 0 &&
          lookahead != '<' &&
          lookahead != '>') ADVANCE(56);
      END_STATE();
    case 6:
      if (lookahead == '\n') SKIP(6);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '+') ADVANCE(44);
      END_STATE();
    case 7:
      if (lookahead == '\n') SKIP(7);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '=') ADVANCE(42);
      END_STATE();
    case 8:
      if (lookahead == '\n') SKIP(8);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '~') ADVANCE(40);
      END_STATE();
    case 9:
      if (lookahead == '\n') SKIP(9);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '_') ADVANCE(38);
      END_STATE();
    case 10:
      if (lookahead == '\n') SKIP(10);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '/') ADVANCE(36);
      END_STATE();
    case 11:
      if (lookahead == '\n') SKIP(11);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '*') ADVANCE(34);
      END_STATE();
    case 12:
      if (lookahead == '/') ADVANCE(16);
      if (lookahead == '@') ADVANCE(15);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != ':') ADVANCE(20);
      END_STATE();
    case 13:
      if (lookahead == '/') ADVANCE(12);
      if (lookahead == '@') ADVANCE(15);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != ':') ADVANCE(20);
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
      if (lookahead == ':') ADVANCE(28);
      if (lookahead == '@') ADVANCE(15);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(62);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ') ADVANCE(15);
      END_STATE();
    case 16:
      if (lookahead == ':') ADVANCE(29);
      if (lookahead == '@') ADVANCE(16);
      if (lookahead == ')' ||
          lookahead == '-' ||
          ('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(63);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ') ADVANCE(16);
      END_STATE();
    case 17:
      if (lookahead == ':') ADVANCE(67);
      if (lookahead == '+' ||
          lookahead == '-' ||
          lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(17);
      END_STATE();
    case 18:
      if (lookahead == '>') ADVANCE(57);
      END_STATE();
    case 19:
      if (lookahead == '@') ADVANCE(51);
      END_STATE();
    case 20:
      if (lookahead == '@') ADVANCE(15);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != ':') ADVANCE(20);
      END_STATE();
    case 21:
      if (lookahead == '[') ADVANCE(60);
      if (lookahead == ']') ADVANCE(61);
      END_STATE();
    case 22:
      if (lookahead == '\t' ||
          (0x0b <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(22);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != '+') ADVANCE(44);
      END_STATE();
    case 23:
      if (lookahead == '\t' ||
          (0x0b <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(23);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != '=') ADVANCE(42);
      END_STATE();
    case 24:
      if (lookahead == '\t' ||
          (0x0b <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(24);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != '~') ADVANCE(40);
      END_STATE();
    case 25:
      if (lookahead == '\t' ||
          (0x0b <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(25);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != '_') ADVANCE(38);
      END_STATE();
    case 26:
      if (lookahead == '\t' ||
          (0x0b <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(26);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != '/') ADVANCE(36);
      END_STATE();
    case 27:
      if (lookahead == '\t' ||
          (0x0b <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(27);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != '*') ADVANCE(34);
      END_STATE();
    case 28:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(64);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ') ADVANCE(28);
      END_STATE();
    case 29:
      if (lookahead == ')' ||
          lookahead == '-' ||
          ('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(65);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ') ADVANCE(29);
      END_STATE();
    case 30:
      if (eof) ADVANCE(31);
      if (lookahead == '\n') SKIP(30);
      if (lookahead == '*') ADVANCE(33);
      if (lookahead == '+') ADVANCE(43);
      if (lookahead == '/') ADVANCE(35);
      if (lookahead == ':') ADVANCE(32);
      if (lookahead == '<') ADVANCE(66);
      if (lookahead == '=') ADVANCE(41);
      if (lookahead == '>') ADVANCE(18);
      if (lookahead == '@') ADVANCE(19);
      if (lookahead == '[') ADVANCE(45);
      if (lookahead == ']') ADVANCE(21);
      if (lookahead == '_') ADVANCE(37);
      if (lookahead == '~') ADVANCE(39);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(71);
      if (lookahead != 0) ADVANCE(72);
      END_STATE();
    case 31:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 32:
      ACCEPT_TOKEN(anon_sym_COLON);
      END_STATE();
    case 33:
      ACCEPT_TOKEN(anon_sym_STAR);
      END_STATE();
    case 34:
      ACCEPT_TOKEN(aux_sym_bold_token1);
      if (lookahead == '\t' ||
          (0x0b <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(27);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != '*') ADVANCE(34);
      END_STATE();
    case 35:
      ACCEPT_TOKEN(anon_sym_SLASH);
      END_STATE();
    case 36:
      ACCEPT_TOKEN(aux_sym_italic_token1);
      if (lookahead == '\t' ||
          (0x0b <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(26);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != '/') ADVANCE(36);
      END_STATE();
    case 37:
      ACCEPT_TOKEN(anon_sym__);
      END_STATE();
    case 38:
      ACCEPT_TOKEN(aux_sym_underline_token1);
      if (lookahead == '\t' ||
          (0x0b <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(25);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != '_') ADVANCE(38);
      END_STATE();
    case 39:
      ACCEPT_TOKEN(anon_sym_TILDE);
      END_STATE();
    case 40:
      ACCEPT_TOKEN(aux_sym_code_token1);
      if (lookahead == '\t' ||
          (0x0b <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(24);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != '~') ADVANCE(40);
      END_STATE();
    case 41:
      ACCEPT_TOKEN(anon_sym_EQ);
      END_STATE();
    case 42:
      ACCEPT_TOKEN(aux_sym_verbatim_token1);
      if (lookahead == '\t' ||
          (0x0b <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(23);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != '=') ADVANCE(42);
      END_STATE();
    case 43:
      ACCEPT_TOKEN(anon_sym_PLUS);
      END_STATE();
    case 44:
      ACCEPT_TOKEN(aux_sym_strike_through_token1);
      if (lookahead == '\t' ||
          (0x0b <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(22);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != '+') ADVANCE(44);
      END_STATE();
    case 45:
      ACCEPT_TOKEN(anon_sym_LBRACK);
      if (lookahead == '[') ADVANCE(58);
      END_STATE();
    case 46:
      ACCEPT_TOKEN(aux_sym_statistics_cookie_token1);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(46);
      END_STATE();
    case 47:
      ACCEPT_TOKEN(anon_sym_PERCENT);
      END_STATE();
    case 48:
      ACCEPT_TOKEN(anon_sym_PERCENT);
      if ((!eof && set_contains(aux_sym_plain_text_token1_character_set_1, 11, lookahead))) ADVANCE(72);
      END_STATE();
    case 49:
      ACCEPT_TOKEN(anon_sym_RBRACK);
      END_STATE();
    case 50:
      ACCEPT_TOKEN(anon_sym_RBRACK);
      if (lookahead == ']') ADVANCE(61);
      END_STATE();
    case 51:
      ACCEPT_TOKEN(anon_sym_AT_AT);
      END_STATE();
    case 52:
      ACCEPT_TOKEN(aux_sym_export_snippet_token1);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(52);
      if ((!eof && set_contains(aux_sym_plain_text_token1_character_set_1, 11, lookahead))) ADVANCE(72);
      END_STATE();
    case 53:
      ACCEPT_TOKEN(aux_sym_export_snippet_token1);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(53);
      END_STATE();
    case 54:
      ACCEPT_TOKEN(aux_sym_export_snippet_token2);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '@') ADVANCE(54);
      END_STATE();
    case 55:
      ACCEPT_TOKEN(anon_sym_LT_LT);
      END_STATE();
    case 56:
      ACCEPT_TOKEN(aux_sym_target_token1);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '<' &&
          lookahead != '>') ADVANCE(56);
      END_STATE();
    case 57:
      ACCEPT_TOKEN(anon_sym_GT_GT);
      END_STATE();
    case 58:
      ACCEPT_TOKEN(anon_sym_LBRACK_LBRACK);
      END_STATE();
    case 59:
      ACCEPT_TOKEN(aux_sym_regular_link_token1);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != ']') ADVANCE(59);
      END_STATE();
    case 60:
      ACCEPT_TOKEN(anon_sym_RBRACK_LBRACK);
      END_STATE();
    case 61:
      ACCEPT_TOKEN(anon_sym_RBRACK_RBRACK);
      END_STATE();
    case 62:
      ACCEPT_TOKEN(sym_plain_link);
      if (lookahead == ':') ADVANCE(28);
      if (lookahead == '@') ADVANCE(15);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(62);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ') ADVANCE(15);
      END_STATE();
    case 63:
      ACCEPT_TOKEN(sym_plain_link);
      if (lookahead == ':') ADVANCE(29);
      if (lookahead == '@') ADVANCE(16);
      if (lookahead == ')' ||
          lookahead == '-' ||
          ('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(63);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ') ADVANCE(16);
      END_STATE();
    case 64:
      ACCEPT_TOKEN(sym_plain_link);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(64);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ') ADVANCE(28);
      END_STATE();
    case 65:
      ACCEPT_TOKEN(sym_plain_link);
      if (lookahead == ')' ||
          lookahead == '-' ||
          ('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(65);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ') ADVANCE(29);
      END_STATE();
    case 66:
      ACCEPT_TOKEN(anon_sym_LT);
      if (lookahead == '<') ADVANCE(55);
      END_STATE();
    case 67:
      ACCEPT_TOKEN(aux_sym_angle_link_token1);
      END_STATE();
    case 68:
      ACCEPT_TOKEN(aux_sym_angle_link_token2);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '>') ADVANCE(68);
      END_STATE();
    case 69:
      ACCEPT_TOKEN(anon_sym_GT);
      END_STATE();
    case 70:
      ACCEPT_TOKEN(anon_sym_GT);
      if (lookahead == '>') ADVANCE(57);
      END_STATE();
    case 71:
      ACCEPT_TOKEN(aux_sym_plain_text_token1);
      if (lookahead == '+') ADVANCE(14);
      if (lookahead == ':') ADVANCE(13);
      if (lookahead == '-' ||
          lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(71);
      if ((!eof && set_contains(aux_sym_plain_text_token1_character_set_1, 11, lookahead))) ADVANCE(72);
      END_STATE();
    case 72:
      ACCEPT_TOKEN(aux_sym_plain_text_token1);
      if ((!eof && set_contains(aux_sym_plain_text_token1_character_set_1, 11, lookahead))) ADVANCE(72);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0, .external_lex_state = 1},
  [1] = {.lex_state = 30, .external_lex_state = 1},
  [2] = {.lex_state = 30, .external_lex_state = 1},
  [3] = {.lex_state = 30, .external_lex_state = 1},
  [4] = {.lex_state = 30, .external_lex_state = 1},
  [5] = {.lex_state = 30, .external_lex_state = 1},
  [6] = {.lex_state = 30, .external_lex_state = 1},
  [7] = {.lex_state = 30, .external_lex_state = 1},
  [8] = {.lex_state = 30, .external_lex_state = 1},
  [9] = {.lex_state = 30, .external_lex_state = 1},
  [10] = {.lex_state = 30, .external_lex_state = 1},
  [11] = {.lex_state = 30, .external_lex_state = 1},
  [12] = {.lex_state = 30, .external_lex_state = 1},
  [13] = {.lex_state = 30, .external_lex_state = 1},
  [14] = {.lex_state = 30, .external_lex_state = 1},
  [15] = {.lex_state = 30, .external_lex_state = 1},
  [16] = {.lex_state = 30, .external_lex_state = 1},
  [17] = {.lex_state = 30, .external_lex_state = 1},
  [18] = {.lex_state = 30, .external_lex_state = 1},
  [19] = {.lex_state = 1},
  [20] = {.lex_state = 0, .external_lex_state = 1},
  [21] = {.lex_state = 30},
  [22] = {.lex_state = 2},
  [23] = {.lex_state = 1},
  [24] = {.lex_state = 0},
  [25] = {.lex_state = 0},
  [26] = {.lex_state = 0},
  [27] = {.lex_state = 0},
  [28] = {.lex_state = 0},
  [29] = {.lex_state = 30},
  [30] = {.lex_state = 0},
  [31] = {.lex_state = 3},
  [32] = {.lex_state = 0},
  [33] = {.lex_state = 0},
  [34] = {.lex_state = 0},
  [35] = {.lex_state = 0},
  [36] = {.lex_state = 0},
  [37] = {.lex_state = 4},
  [38] = {.lex_state = 5},
  [39] = {.lex_state = 0},
  [40] = {.lex_state = 46},
  [41] = {.lex_state = 1},
  [42] = {.lex_state = 54},
  [43] = {.lex_state = 46},
  [44] = {.lex_state = 2},
  [45] = {.lex_state = 6},
  [46] = {.lex_state = 1},
  [47] = {.lex_state = 1},
  [48] = {.lex_state = 7},
  [49] = {.lex_state = 0},
  [50] = {.lex_state = 30},
  [51] = {.lex_state = 8},
  [52] = {.lex_state = 9},
  [53] = {.lex_state = 10},
  [54] = {.lex_state = 11},
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
    [anon_sym_LBRACK_LBRACK] = ACTIONS(1),
    [anon_sym_RBRACK_RBRACK] = ACTIONS(1),
    [anon_sym_LT] = ACTIONS(1),
    [anon_sym_GT] = ACTIONS(1),
    [aux_sym_plain_text_token1] = ACTIONS(1),
    [sym_TAGS] = ACTIONS(1),
  },
  [1] = {
    [sym_inline] = STATE(36),
    [sym_title_with_tags] = STATE(35),
    [sym_title_only] = STATE(34),
    [sym_title] = STATE(20),
    [sym_text_markup] = STATE(2),
    [sym_bold] = STATE(17),
    [sym_italic] = STATE(17),
    [sym_underline] = STATE(17),
    [sym_code] = STATE(17),
    [sym_verbatim] = STATE(17),
    [sym_strike_through] = STATE(17),
    [sym_statistics_cookie] = STATE(2),
    [sym_export_snippet] = STATE(2),
    [sym_target] = STATE(2),
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
    [anon_sym_LBRACK_LBRACK] = ACTIONS(23),
    [sym_plain_link] = ACTIONS(3),
    [anon_sym_LT] = ACTIONS(25),
    [aux_sym_plain_text_token1] = ACTIONS(27),
    [sym_TAGS] = ACTIONS(29),
  },
  [2] = {
    [sym_text_markup] = STATE(3),
    [sym_bold] = STATE(17),
    [sym_italic] = STATE(17),
    [sym_underline] = STATE(17),
    [sym_code] = STATE(17),
    [sym_verbatim] = STATE(17),
    [sym_strike_through] = STATE(17),
    [sym_statistics_cookie] = STATE(3),
    [sym_export_snippet] = STATE(3),
    [sym_target] = STATE(3),
    [sym_regular_link] = STATE(3),
    [sym_angle_link] = STATE(3),
    [sym_plain_text] = STATE(3),
    [aux_sym_title_repeat1] = STATE(3),
    [ts_builtin_sym_end] = ACTIONS(31),
    [anon_sym_COLON] = ACTIONS(33),
    [anon_sym_STAR] = ACTIONS(5),
    [anon_sym_SLASH] = ACTIONS(7),
    [anon_sym__] = ACTIONS(9),
    [anon_sym_TILDE] = ACTIONS(11),
    [anon_sym_EQ] = ACTIONS(13),
    [anon_sym_PLUS] = ACTIONS(15),
    [anon_sym_LBRACK] = ACTIONS(17),
    [anon_sym_AT_AT] = ACTIONS(19),
    [anon_sym_LT_LT] = ACTIONS(21),
    [anon_sym_LBRACK_LBRACK] = ACTIONS(23),
    [sym_plain_link] = ACTIONS(33),
    [anon_sym_LT] = ACTIONS(25),
    [aux_sym_plain_text_token1] = ACTIONS(27),
    [sym_TAGS] = ACTIONS(31),
  },
  [3] = {
    [sym_text_markup] = STATE(3),
    [sym_bold] = STATE(17),
    [sym_italic] = STATE(17),
    [sym_underline] = STATE(17),
    [sym_code] = STATE(17),
    [sym_verbatim] = STATE(17),
    [sym_strike_through] = STATE(17),
    [sym_statistics_cookie] = STATE(3),
    [sym_export_snippet] = STATE(3),
    [sym_target] = STATE(3),
    [sym_regular_link] = STATE(3),
    [sym_angle_link] = STATE(3),
    [sym_plain_text] = STATE(3),
    [aux_sym_title_repeat1] = STATE(3),
    [ts_builtin_sym_end] = ACTIONS(35),
    [anon_sym_COLON] = ACTIONS(37),
    [anon_sym_STAR] = ACTIONS(40),
    [anon_sym_SLASH] = ACTIONS(43),
    [anon_sym__] = ACTIONS(46),
    [anon_sym_TILDE] = ACTIONS(49),
    [anon_sym_EQ] = ACTIONS(52),
    [anon_sym_PLUS] = ACTIONS(55),
    [anon_sym_LBRACK] = ACTIONS(58),
    [anon_sym_AT_AT] = ACTIONS(61),
    [anon_sym_LT_LT] = ACTIONS(64),
    [anon_sym_LBRACK_LBRACK] = ACTIONS(67),
    [sym_plain_link] = ACTIONS(37),
    [anon_sym_LT] = ACTIONS(70),
    [aux_sym_plain_text_token1] = ACTIONS(73),
    [sym_TAGS] = ACTIONS(35),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 2,
    ACTIONS(78), 3,
      anon_sym_LBRACK,
      anon_sym_LT,
      aux_sym_plain_text_token1,
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
      anon_sym_AT_AT,
      anon_sym_LT_LT,
      anon_sym_LBRACK_LBRACK,
      sym_plain_link,
  [21] = 2,
    ACTIONS(82), 3,
      anon_sym_LBRACK,
      anon_sym_LT,
      aux_sym_plain_text_token1,
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
      anon_sym_AT_AT,
      anon_sym_LT_LT,
      anon_sym_LBRACK_LBRACK,
      sym_plain_link,
  [42] = 2,
    ACTIONS(86), 3,
      anon_sym_LBRACK,
      anon_sym_LT,
      aux_sym_plain_text_token1,
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
      anon_sym_AT_AT,
      anon_sym_LT_LT,
      anon_sym_LBRACK_LBRACK,
      sym_plain_link,
  [63] = 2,
    ACTIONS(90), 3,
      anon_sym_LBRACK,
      anon_sym_LT,
      aux_sym_plain_text_token1,
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
      anon_sym_AT_AT,
      anon_sym_LT_LT,
      anon_sym_LBRACK_LBRACK,
      sym_plain_link,
  [84] = 2,
    ACTIONS(94), 3,
      anon_sym_LBRACK,
      anon_sym_LT,
      aux_sym_plain_text_token1,
    ACTIONS(92), 13,
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
      anon_sym_LT_LT,
      anon_sym_LBRACK_LBRACK,
      sym_plain_link,
  [105] = 2,
    ACTIONS(98), 3,
      anon_sym_LBRACK,
      anon_sym_LT,
      aux_sym_plain_text_token1,
    ACTIONS(96), 13,
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
      anon_sym_LT_LT,
      anon_sym_LBRACK_LBRACK,
      sym_plain_link,
  [126] = 2,
    ACTIONS(102), 3,
      anon_sym_LBRACK,
      anon_sym_LT,
      aux_sym_plain_text_token1,
    ACTIONS(100), 13,
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
      anon_sym_LT_LT,
      anon_sym_LBRACK_LBRACK,
      sym_plain_link,
  [147] = 2,
    ACTIONS(106), 3,
      anon_sym_LBRACK,
      anon_sym_LT,
      aux_sym_plain_text_token1,
    ACTIONS(104), 13,
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
      anon_sym_LT_LT,
      anon_sym_LBRACK_LBRACK,
      sym_plain_link,
  [168] = 2,
    ACTIONS(110), 3,
      anon_sym_LBRACK,
      anon_sym_LT,
      aux_sym_plain_text_token1,
    ACTIONS(108), 13,
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
      anon_sym_LT_LT,
      anon_sym_LBRACK_LBRACK,
      sym_plain_link,
  [189] = 2,
    ACTIONS(114), 3,
      anon_sym_LBRACK,
      anon_sym_LT,
      aux_sym_plain_text_token1,
    ACTIONS(112), 13,
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
      anon_sym_LT_LT,
      anon_sym_LBRACK_LBRACK,
      sym_plain_link,
  [210] = 2,
    ACTIONS(118), 3,
      anon_sym_LBRACK,
      anon_sym_LT,
      aux_sym_plain_text_token1,
    ACTIONS(116), 13,
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
      anon_sym_LT_LT,
      anon_sym_LBRACK_LBRACK,
      sym_plain_link,
  [231] = 2,
    ACTIONS(122), 3,
      anon_sym_LBRACK,
      anon_sym_LT,
      aux_sym_plain_text_token1,
    ACTIONS(120), 13,
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
      anon_sym_LT_LT,
      anon_sym_LBRACK_LBRACK,
      sym_plain_link,
  [252] = 2,
    ACTIONS(126), 3,
      anon_sym_LBRACK,
      anon_sym_LT,
      aux_sym_plain_text_token1,
    ACTIONS(124), 13,
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
      anon_sym_LT_LT,
      anon_sym_LBRACK_LBRACK,
      sym_plain_link,
  [273] = 2,
    ACTIONS(130), 3,
      anon_sym_LBRACK,
      anon_sym_LT,
      aux_sym_plain_text_token1,
    ACTIONS(128), 13,
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
      anon_sym_LT_LT,
      anon_sym_LBRACK_LBRACK,
      sym_plain_link,
  [294] = 2,
    ACTIONS(134), 3,
      anon_sym_LBRACK,
      anon_sym_LT,
      aux_sym_plain_text_token1,
    ACTIONS(132), 13,
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
      anon_sym_LT_LT,
      anon_sym_LBRACK_LBRACK,
      sym_plain_link,
  [315] = 2,
    ACTIONS(136), 1,
      anon_sym_SLASH,
    ACTIONS(138), 1,
      anon_sym_PERCENT,
  [322] = 2,
    ACTIONS(140), 1,
      ts_builtin_sym_end,
    ACTIONS(142), 1,
      sym_TAGS,
  [329] = 2,
    ACTIONS(144), 1,
      anon_sym_RBRACK_LBRACK,
    ACTIONS(146), 1,
      anon_sym_RBRACK_RBRACK,
  [336] = 1,
    ACTIONS(148), 1,
      aux_sym_regular_link_token1,
  [340] = 1,
    ACTIONS(150), 1,
      aux_sym_export_snippet_token1,
  [344] = 1,
    ACTIONS(152), 1,
      anon_sym__,
  [348] = 1,
    ACTIONS(154), 1,
      anon_sym_TILDE,
  [352] = 1,
    ACTIONS(156), 1,
      anon_sym_EQ,
  [356] = 1,
    ACTIONS(158), 1,
      anon_sym_PLUS,
  [360] = 1,
    ACTIONS(160), 1,
      anon_sym_COLON,
  [364] = 1,
    ACTIONS(162), 1,
      anon_sym_GT_GT,
  [368] = 1,
    ACTIONS(164), 1,
      ts_builtin_sym_end,
  [372] = 1,
    ACTIONS(166), 1,
      aux_sym_angle_link_token2,
  [376] = 1,
    ACTIONS(168), 1,
      ts_builtin_sym_end,
  [380] = 1,
    ACTIONS(170), 1,
      anon_sym_STAR,
  [384] = 1,
    ACTIONS(172), 1,
      ts_builtin_sym_end,
  [388] = 1,
    ACTIONS(174), 1,
      ts_builtin_sym_end,
  [392] = 1,
    ACTIONS(176), 1,
      ts_builtin_sym_end,
  [396] = 1,
    ACTIONS(178), 1,
      aux_sym_angle_link_token1,
  [400] = 1,
    ACTIONS(180), 1,
      aux_sym_target_token1,
  [404] = 1,
    ACTIONS(182), 1,
      anon_sym_SLASH,
  [408] = 1,
    ACTIONS(184), 1,
      aux_sym_statistics_cookie_token1,
  [412] = 1,
    ACTIONS(186), 1,
      anon_sym_RBRACK,
  [416] = 1,
    ACTIONS(188), 1,
      aux_sym_export_snippet_token2,
  [420] = 1,
    ACTIONS(190), 1,
      aux_sym_statistics_cookie_token1,
  [424] = 1,
    ACTIONS(192), 1,
      aux_sym_regular_link_token1,
  [428] = 1,
    ACTIONS(194), 1,
      aux_sym_strike_through_token1,
  [432] = 1,
    ACTIONS(196), 1,
      anon_sym_GT,
  [436] = 1,
    ACTIONS(198), 1,
      anon_sym_RBRACK,
  [440] = 1,
    ACTIONS(200), 1,
      aux_sym_verbatim_token1,
  [444] = 1,
    ACTIONS(202), 1,
      anon_sym_AT_AT,
  [448] = 1,
    ACTIONS(204), 1,
      anon_sym_RBRACK_RBRACK,
  [452] = 1,
    ACTIONS(206), 1,
      aux_sym_code_token1,
  [456] = 1,
    ACTIONS(208), 1,
      aux_sym_underline_token1,
  [460] = 1,
    ACTIONS(210), 1,
      aux_sym_italic_token1,
  [464] = 1,
    ACTIONS(212), 1,
      aux_sym_bold_token1,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(4)] = 0,
  [SMALL_STATE(5)] = 21,
  [SMALL_STATE(6)] = 42,
  [SMALL_STATE(7)] = 63,
  [SMALL_STATE(8)] = 84,
  [SMALL_STATE(9)] = 105,
  [SMALL_STATE(10)] = 126,
  [SMALL_STATE(11)] = 147,
  [SMALL_STATE(12)] = 168,
  [SMALL_STATE(13)] = 189,
  [SMALL_STATE(14)] = 210,
  [SMALL_STATE(15)] = 231,
  [SMALL_STATE(16)] = 252,
  [SMALL_STATE(17)] = 273,
  [SMALL_STATE(18)] = 294,
  [SMALL_STATE(19)] = 315,
  [SMALL_STATE(20)] = 322,
  [SMALL_STATE(21)] = 329,
  [SMALL_STATE(22)] = 336,
  [SMALL_STATE(23)] = 340,
  [SMALL_STATE(24)] = 344,
  [SMALL_STATE(25)] = 348,
  [SMALL_STATE(26)] = 352,
  [SMALL_STATE(27)] = 356,
  [SMALL_STATE(28)] = 360,
  [SMALL_STATE(29)] = 364,
  [SMALL_STATE(30)] = 368,
  [SMALL_STATE(31)] = 372,
  [SMALL_STATE(32)] = 376,
  [SMALL_STATE(33)] = 380,
  [SMALL_STATE(34)] = 384,
  [SMALL_STATE(35)] = 388,
  [SMALL_STATE(36)] = 392,
  [SMALL_STATE(37)] = 396,
  [SMALL_STATE(38)] = 400,
  [SMALL_STATE(39)] = 404,
  [SMALL_STATE(40)] = 408,
  [SMALL_STATE(41)] = 412,
  [SMALL_STATE(42)] = 416,
  [SMALL_STATE(43)] = 420,
  [SMALL_STATE(44)] = 424,
  [SMALL_STATE(45)] = 428,
  [SMALL_STATE(46)] = 432,
  [SMALL_STATE(47)] = 436,
  [SMALL_STATE(48)] = 440,
  [SMALL_STATE(49)] = 444,
  [SMALL_STATE(50)] = 448,
  [SMALL_STATE(51)] = 452,
  [SMALL_STATE(52)] = 456,
  [SMALL_STATE(53)] = 460,
  [SMALL_STATE(54)] = 464,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, SHIFT(2),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(54),
  [7] = {.entry = {.count = 1, .reusable = true}}, SHIFT(53),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(52),
  [11] = {.entry = {.count = 1, .reusable = true}}, SHIFT(51),
  [13] = {.entry = {.count = 1, .reusable = true}}, SHIFT(48),
  [15] = {.entry = {.count = 1, .reusable = true}}, SHIFT(45),
  [17] = {.entry = {.count = 1, .reusable = false}}, SHIFT(43),
  [19] = {.entry = {.count = 1, .reusable = true}}, SHIFT(23),
  [21] = {.entry = {.count = 1, .reusable = true}}, SHIFT(38),
  [23] = {.entry = {.count = 1, .reusable = true}}, SHIFT(22),
  [25] = {.entry = {.count = 1, .reusable = false}}, SHIFT(37),
  [27] = {.entry = {.count = 1, .reusable = false}}, SHIFT(13),
  [29] = {.entry = {.count = 1, .reusable = true}}, SHIFT(30),
  [31] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_title, 1, 0, 0),
  [33] = {.entry = {.count = 1, .reusable = true}}, SHIFT(3),
  [35] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_title_repeat1, 2, 0, 0),
  [37] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_title_repeat1, 2, 0, 0), SHIFT_REPEAT(3),
  [40] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_title_repeat1, 2, 0, 0), SHIFT_REPEAT(54),
  [43] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_title_repeat1, 2, 0, 0), SHIFT_REPEAT(53),
  [46] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_title_repeat1, 2, 0, 0), SHIFT_REPEAT(52),
  [49] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_title_repeat1, 2, 0, 0), SHIFT_REPEAT(51),
  [52] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_title_repeat1, 2, 0, 0), SHIFT_REPEAT(48),
  [55] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_title_repeat1, 2, 0, 0), SHIFT_REPEAT(45),
  [58] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_title_repeat1, 2, 0, 0), SHIFT_REPEAT(43),
  [61] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_title_repeat1, 2, 0, 0), SHIFT_REPEAT(23),
  [64] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_title_repeat1, 2, 0, 0), SHIFT_REPEAT(38),
  [67] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_title_repeat1, 2, 0, 0), SHIFT_REPEAT(22),
  [70] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_title_repeat1, 2, 0, 0), SHIFT_REPEAT(37),
  [73] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_title_repeat1, 2, 0, 0), SHIFT_REPEAT(13),
  [76] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_verbatim, 3, 0, 0),
  [78] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_verbatim, 3, 0, 0),
  [80] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_angle_link, 4, 0, 0),
  [82] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_angle_link, 4, 0, 0),
  [84] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_statistics_cookie, 4, 0, 0),
  [86] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_statistics_cookie, 4, 0, 0),
  [88] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_regular_link, 3, 0, 0),
  [90] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_regular_link, 3, 0, 0),
  [92] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_target, 3, 0, 0),
  [94] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_target, 3, 0, 0),
  [96] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_strike_through, 3, 0, 0),
  [98] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_strike_through, 3, 0, 0),
  [100] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_code, 3, 0, 0),
  [102] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_code, 3, 0, 0),
  [104] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_regular_link, 5, 0, 0),
  [106] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_regular_link, 5, 0, 0),
  [108] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_underline, 3, 0, 0),
  [110] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_underline, 3, 0, 0),
  [112] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_plain_text, 1, 0, 0),
  [114] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_plain_text, 1, 0, 0),
  [116] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_italic, 3, 0, 0),
  [118] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_italic, 3, 0, 0),
  [120] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_bold, 3, 0, 0),
  [122] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_bold, 3, 0, 0),
  [124] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_statistics_cookie, 5, 0, 0),
  [126] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_statistics_cookie, 5, 0, 0),
  [128] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_text_markup, 1, 0, 0),
  [130] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_text_markup, 1, 0, 0),
  [132] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_export_snippet, 5, 0, 0),
  [134] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_export_snippet, 5, 0, 0),
  [136] = {.entry = {.count = 1, .reusable = true}}, SHIFT(40),
  [138] = {.entry = {.count = 1, .reusable = true}}, SHIFT(41),
  [140] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_title_only, 1, 0, 2),
  [142] = {.entry = {.count = 1, .reusable = true}}, SHIFT(32),
  [144] = {.entry = {.count = 1, .reusable = true}}, SHIFT(44),
  [146] = {.entry = {.count = 1, .reusable = true}}, SHIFT(7),
  [148] = {.entry = {.count = 1, .reusable = true}}, SHIFT(21),
  [150] = {.entry = {.count = 1, .reusable = true}}, SHIFT(28),
  [152] = {.entry = {.count = 1, .reusable = true}}, SHIFT(12),
  [154] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
  [156] = {.entry = {.count = 1, .reusable = true}}, SHIFT(4),
  [158] = {.entry = {.count = 1, .reusable = true}}, SHIFT(9),
  [160] = {.entry = {.count = 1, .reusable = true}}, SHIFT(42),
  [162] = {.entry = {.count = 1, .reusable = true}}, SHIFT(8),
  [164] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_title_with_tags, 1, 0, 1),
  [166] = {.entry = {.count = 1, .reusable = true}}, SHIFT(46),
  [168] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_title_with_tags, 2, 0, 3),
  [170] = {.entry = {.count = 1, .reusable = true}}, SHIFT(15),
  [172] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_inline, 1, 1, 0),
  [174] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_inline, 1, 2, 0),
  [176] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [178] = {.entry = {.count = 1, .reusable = true}}, SHIFT(31),
  [180] = {.entry = {.count = 1, .reusable = true}}, SHIFT(29),
  [182] = {.entry = {.count = 1, .reusable = true}}, SHIFT(14),
  [184] = {.entry = {.count = 1, .reusable = true}}, SHIFT(47),
  [186] = {.entry = {.count = 1, .reusable = true}}, SHIFT(6),
  [188] = {.entry = {.count = 1, .reusable = true}}, SHIFT(49),
  [190] = {.entry = {.count = 1, .reusable = true}}, SHIFT(19),
  [192] = {.entry = {.count = 1, .reusable = true}}, SHIFT(50),
  [194] = {.entry = {.count = 1, .reusable = true}}, SHIFT(27),
  [196] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
  [198] = {.entry = {.count = 1, .reusable = true}}, SHIFT(16),
  [200] = {.entry = {.count = 1, .reusable = true}}, SHIFT(26),
  [202] = {.entry = {.count = 1, .reusable = true}}, SHIFT(18),
  [204] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
  [206] = {.entry = {.count = 1, .reusable = true}}, SHIFT(25),
  [208] = {.entry = {.count = 1, .reusable = true}}, SHIFT(24),
  [210] = {.entry = {.count = 1, .reusable = true}}, SHIFT(39),
  [212] = {.entry = {.count = 1, .reusable = true}}, SHIFT(33),
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
