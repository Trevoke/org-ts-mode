#include "tree_sitter/parser.h"

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#ifdef _MSC_VER
#pragma optimize("", off)
#elif defined(__clang__)
#pragma clang optimize off
#elif defined(__GNUC__)
#pragma GCC optimize ("O0")
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 123
#define LARGE_STATE_COUNT 4
#define SYMBOL_COUNT 75
#define ALIAS_COUNT 1
#define TOKEN_COUNT 48
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 5
#define MAX_ALIAS_SEQUENCE_LENGTH 9
#define PRODUCTION_ID_COUNT 13

enum ts_symbol_identifiers {
  anon_sym_SPACE = 1,
  anon_sym_LF = 2,
  sym_stars = 3,
  sym_keyword = 4,
  sym_priority = 5,
  aux_sym_title_token1 = 6,
  sym_planning_line = 7,
  sym_timestamp = 8,
  anon_sym_LBRACE_LBRACE_LBRACE = 9,
  aux_sym_macro_token1 = 10,
  anon_sym_LPAREN = 11,
  aux_sym_macro_token2 = 12,
  anon_sym_RPAREN = 13,
  anon_sym_RBRACE_RBRACE_RBRACE = 14,
  sym_footnote_reference = 15,
  sym_latex_fragment = 16,
  sym_entity = 17,
  sym_subscript = 18,
  sym_superscript = 19,
  anon_sym_LBRACK_LBRACK = 20,
  aux_sym_link_token1 = 21,
  anon_sym_RBRACK_LBRACK = 22,
  anon_sym_RBRACK_RBRACK = 23,
  aux_sym_list_item_token1 = 24,
  aux_sym_list_item_token2 = 25,
  sym_bullet = 26,
  aux_sym_block_begin_token1 = 27,
  sym_block_type = 28,
  sym_language = 29,
  sym_block_content = 30,
  aux_sym_block_end_token1 = 31,
  anon_sym_PIPE = 32,
  sym_table_cell = 33,
  sym_table_separator = 34,
  aux_sym_directive_token1 = 35,
  anon_sym_COLON = 36,
  sym_name = 37,
  aux_sym_comment_token1 = 38,
  anon_sym_COLONPROPERTIES_COLON = 39,
  aux_sym_property_drawer_token1 = 40,
  anon_sym_COLONEND_COLON = 41,
  aux_sym_key_token1 = 42,
  anon_sym_COLONend_COLON = 43,
  sym_drawer_content = 44,
  sym_horizontal_rule = 45,
  aux_sym_paragraph_token1 = 46,
  aux_sym_paragraph_token2 = 47,
  sym_document = 48,
  sym__element = 49,
  sym_headline = 50,
  sym_title = 51,
  sym_macro = 52,
  sym_link = 53,
  sym_list = 54,
  sym_list_item = 55,
  sym_block = 56,
  sym_block_begin = 57,
  sym_block_end = 58,
  sym_table = 59,
  sym_table_row = 60,
  sym_directive = 61,
  sym_comment = 62,
  sym_property_drawer = 63,
  sym_property = 64,
  sym_key = 65,
  sym_value = 66,
  sym_drawer = 67,
  sym_drawer_name = 68,
  sym_paragraph = 69,
  aux_sym_document_repeat1 = 70,
  aux_sym_list_repeat1 = 71,
  aux_sym_table_repeat1 = 72,
  aux_sym_table_row_repeat1 = 73,
  aux_sym_property_drawer_repeat1 = 74,
  alias_sym_link_description = 75,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [anon_sym_SPACE] = " ",
  [anon_sym_LF] = "\n",
  [sym_stars] = "stars",
  [sym_keyword] = "keyword",
  [sym_priority] = "priority",
  [aux_sym_title_token1] = "title_token1",
  [sym_planning_line] = "planning_line",
  [sym_timestamp] = "timestamp",
  [anon_sym_LBRACE_LBRACE_LBRACE] = "{{{",
  [aux_sym_macro_token1] = "macro_name",
  [anon_sym_LPAREN] = "(",
  [aux_sym_macro_token2] = "macro_args",
  [anon_sym_RPAREN] = ")",
  [anon_sym_RBRACE_RBRACE_RBRACE] = "}}}",
  [sym_footnote_reference] = "footnote_reference",
  [sym_latex_fragment] = "latex_fragment",
  [sym_entity] = "entity",
  [sym_subscript] = "subscript",
  [sym_superscript] = "superscript",
  [anon_sym_LBRACK_LBRACK] = "[[",
  [aux_sym_link_token1] = "link_target",
  [anon_sym_RBRACK_LBRACK] = "][",
  [anon_sym_RBRACK_RBRACK] = "]]",
  [aux_sym_list_item_token1] = "list_item_token1",
  [aux_sym_list_item_token2] = "list_item_token2",
  [sym_bullet] = "bullet",
  [aux_sym_block_begin_token1] = "block_begin_token1",
  [sym_block_type] = "block_type",
  [sym_language] = "language",
  [sym_block_content] = "block_content",
  [aux_sym_block_end_token1] = "block_end_token1",
  [anon_sym_PIPE] = "|",
  [sym_table_cell] = "table_cell",
  [sym_table_separator] = "table_separator",
  [aux_sym_directive_token1] = "directive_token1",
  [anon_sym_COLON] = ":",
  [sym_name] = "name",
  [aux_sym_comment_token1] = "comment_token1",
  [anon_sym_COLONPROPERTIES_COLON] = ":PROPERTIES:",
  [aux_sym_property_drawer_token1] = "property_drawer_token1",
  [anon_sym_COLONEND_COLON] = ":END:",
  [aux_sym_key_token1] = "key_token1",
  [anon_sym_COLONend_COLON] = ":end:",
  [sym_drawer_content] = "drawer_content",
  [sym_horizontal_rule] = "horizontal_rule",
  [aux_sym_paragraph_token1] = "paragraph_token1",
  [aux_sym_paragraph_token2] = "paragraph_token2",
  [sym_document] = "document",
  [sym__element] = "_element",
  [sym_headline] = "headline",
  [sym_title] = "title",
  [sym_macro] = "macro",
  [sym_link] = "link",
  [sym_list] = "list",
  [sym_list_item] = "list_item",
  [sym_block] = "block",
  [sym_block_begin] = "block_begin",
  [sym_block_end] = "block_end",
  [sym_table] = "table",
  [sym_table_row] = "table_row",
  [sym_directive] = "directive",
  [sym_comment] = "comment",
  [sym_property_drawer] = "property_drawer",
  [sym_property] = "property",
  [sym_key] = "key",
  [sym_value] = "value",
  [sym_drawer] = "drawer",
  [sym_drawer_name] = "drawer_name",
  [sym_paragraph] = "paragraph",
  [aux_sym_document_repeat1] = "document_repeat1",
  [aux_sym_list_repeat1] = "list_repeat1",
  [aux_sym_table_repeat1] = "table_repeat1",
  [aux_sym_table_row_repeat1] = "table_row_repeat1",
  [aux_sym_property_drawer_repeat1] = "property_drawer_repeat1",
  [alias_sym_link_description] = "link_description",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [anon_sym_SPACE] = anon_sym_SPACE,
  [anon_sym_LF] = anon_sym_LF,
  [sym_stars] = sym_stars,
  [sym_keyword] = sym_keyword,
  [sym_priority] = sym_priority,
  [aux_sym_title_token1] = aux_sym_title_token1,
  [sym_planning_line] = sym_planning_line,
  [sym_timestamp] = sym_timestamp,
  [anon_sym_LBRACE_LBRACE_LBRACE] = anon_sym_LBRACE_LBRACE_LBRACE,
  [aux_sym_macro_token1] = aux_sym_macro_token1,
  [anon_sym_LPAREN] = anon_sym_LPAREN,
  [aux_sym_macro_token2] = aux_sym_macro_token2,
  [anon_sym_RPAREN] = anon_sym_RPAREN,
  [anon_sym_RBRACE_RBRACE_RBRACE] = anon_sym_RBRACE_RBRACE_RBRACE,
  [sym_footnote_reference] = sym_footnote_reference,
  [sym_latex_fragment] = sym_latex_fragment,
  [sym_entity] = sym_entity,
  [sym_subscript] = sym_subscript,
  [sym_superscript] = sym_superscript,
  [anon_sym_LBRACK_LBRACK] = anon_sym_LBRACK_LBRACK,
  [aux_sym_link_token1] = aux_sym_link_token1,
  [anon_sym_RBRACK_LBRACK] = anon_sym_RBRACK_LBRACK,
  [anon_sym_RBRACK_RBRACK] = anon_sym_RBRACK_RBRACK,
  [aux_sym_list_item_token1] = aux_sym_list_item_token1,
  [aux_sym_list_item_token2] = aux_sym_list_item_token2,
  [sym_bullet] = sym_bullet,
  [aux_sym_block_begin_token1] = aux_sym_block_begin_token1,
  [sym_block_type] = sym_block_type,
  [sym_language] = sym_language,
  [sym_block_content] = sym_block_content,
  [aux_sym_block_end_token1] = aux_sym_block_end_token1,
  [anon_sym_PIPE] = anon_sym_PIPE,
  [sym_table_cell] = sym_table_cell,
  [sym_table_separator] = sym_table_separator,
  [aux_sym_directive_token1] = aux_sym_directive_token1,
  [anon_sym_COLON] = anon_sym_COLON,
  [sym_name] = sym_name,
  [aux_sym_comment_token1] = aux_sym_comment_token1,
  [anon_sym_COLONPROPERTIES_COLON] = anon_sym_COLONPROPERTIES_COLON,
  [aux_sym_property_drawer_token1] = aux_sym_property_drawer_token1,
  [anon_sym_COLONEND_COLON] = anon_sym_COLONEND_COLON,
  [aux_sym_key_token1] = aux_sym_key_token1,
  [anon_sym_COLONend_COLON] = anon_sym_COLONend_COLON,
  [sym_drawer_content] = sym_drawer_content,
  [sym_horizontal_rule] = sym_horizontal_rule,
  [aux_sym_paragraph_token1] = aux_sym_paragraph_token1,
  [aux_sym_paragraph_token2] = aux_sym_paragraph_token2,
  [sym_document] = sym_document,
  [sym__element] = sym__element,
  [sym_headline] = sym_headline,
  [sym_title] = sym_title,
  [sym_macro] = sym_macro,
  [sym_link] = sym_link,
  [sym_list] = sym_list,
  [sym_list_item] = sym_list_item,
  [sym_block] = sym_block,
  [sym_block_begin] = sym_block_begin,
  [sym_block_end] = sym_block_end,
  [sym_table] = sym_table,
  [sym_table_row] = sym_table_row,
  [sym_directive] = sym_directive,
  [sym_comment] = sym_comment,
  [sym_property_drawer] = sym_property_drawer,
  [sym_property] = sym_property,
  [sym_key] = sym_key,
  [sym_value] = sym_value,
  [sym_drawer] = sym_drawer,
  [sym_drawer_name] = sym_drawer_name,
  [sym_paragraph] = sym_paragraph,
  [aux_sym_document_repeat1] = aux_sym_document_repeat1,
  [aux_sym_list_repeat1] = aux_sym_list_repeat1,
  [aux_sym_table_repeat1] = aux_sym_table_repeat1,
  [aux_sym_table_row_repeat1] = aux_sym_table_row_repeat1,
  [aux_sym_property_drawer_repeat1] = aux_sym_property_drawer_repeat1,
  [alias_sym_link_description] = alias_sym_link_description,
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
  [anon_sym_LF] = {
    .visible = true,
    .named = false,
  },
  [sym_stars] = {
    .visible = true,
    .named = true,
  },
  [sym_keyword] = {
    .visible = true,
    .named = true,
  },
  [sym_priority] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_title_token1] = {
    .visible = false,
    .named = false,
  },
  [sym_planning_line] = {
    .visible = true,
    .named = true,
  },
  [sym_timestamp] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_LBRACE_LBRACE_LBRACE] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_macro_token1] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_LPAREN] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_macro_token2] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_RPAREN] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RBRACE_RBRACE_RBRACE] = {
    .visible = true,
    .named = false,
  },
  [sym_footnote_reference] = {
    .visible = true,
    .named = true,
  },
  [sym_latex_fragment] = {
    .visible = true,
    .named = true,
  },
  [sym_entity] = {
    .visible = true,
    .named = true,
  },
  [sym_subscript] = {
    .visible = true,
    .named = true,
  },
  [sym_superscript] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_LBRACK_LBRACK] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_link_token1] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_RBRACK_LBRACK] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RBRACK_RBRACK] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_list_item_token1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_list_item_token2] = {
    .visible = false,
    .named = false,
  },
  [sym_bullet] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_block_begin_token1] = {
    .visible = false,
    .named = false,
  },
  [sym_block_type] = {
    .visible = true,
    .named = true,
  },
  [sym_language] = {
    .visible = true,
    .named = true,
  },
  [sym_block_content] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_block_end_token1] = {
    .visible = false,
    .named = false,
  },
  [anon_sym_PIPE] = {
    .visible = true,
    .named = false,
  },
  [sym_table_cell] = {
    .visible = true,
    .named = true,
  },
  [sym_table_separator] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_directive_token1] = {
    .visible = false,
    .named = false,
  },
  [anon_sym_COLON] = {
    .visible = true,
    .named = false,
  },
  [sym_name] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_comment_token1] = {
    .visible = false,
    .named = false,
  },
  [anon_sym_COLONPROPERTIES_COLON] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_property_drawer_token1] = {
    .visible = false,
    .named = false,
  },
  [anon_sym_COLONEND_COLON] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_key_token1] = {
    .visible = false,
    .named = false,
  },
  [anon_sym_COLONend_COLON] = {
    .visible = true,
    .named = false,
  },
  [sym_drawer_content] = {
    .visible = true,
    .named = true,
  },
  [sym_horizontal_rule] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_paragraph_token1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_paragraph_token2] = {
    .visible = false,
    .named = false,
  },
  [sym_document] = {
    .visible = true,
    .named = true,
  },
  [sym__element] = {
    .visible = false,
    .named = true,
  },
  [sym_headline] = {
    .visible = true,
    .named = true,
  },
  [sym_title] = {
    .visible = true,
    .named = true,
  },
  [sym_macro] = {
    .visible = true,
    .named = true,
  },
  [sym_link] = {
    .visible = true,
    .named = true,
  },
  [sym_list] = {
    .visible = true,
    .named = true,
  },
  [sym_list_item] = {
    .visible = true,
    .named = true,
  },
  [sym_block] = {
    .visible = true,
    .named = true,
  },
  [sym_block_begin] = {
    .visible = true,
    .named = true,
  },
  [sym_block_end] = {
    .visible = true,
    .named = true,
  },
  [sym_table] = {
    .visible = true,
    .named = true,
  },
  [sym_table_row] = {
    .visible = true,
    .named = true,
  },
  [sym_directive] = {
    .visible = true,
    .named = true,
  },
  [sym_comment] = {
    .visible = true,
    .named = true,
  },
  [sym_property_drawer] = {
    .visible = true,
    .named = true,
  },
  [sym_property] = {
    .visible = true,
    .named = true,
  },
  [sym_key] = {
    .visible = true,
    .named = true,
  },
  [sym_value] = {
    .visible = true,
    .named = true,
  },
  [sym_drawer] = {
    .visible = true,
    .named = true,
  },
  [sym_drawer_name] = {
    .visible = true,
    .named = true,
  },
  [sym_paragraph] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_document_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_list_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_table_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_table_row_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_property_drawer_repeat1] = {
    .visible = false,
    .named = false,
  },
  [alias_sym_link_description] = {
    .visible = true,
    .named = true,
  },
};

enum ts_field_identifiers {
  field_keyword = 1,
  field_language = 2,
  field_priority = 3,
  field_title = 4,
  field_type = 5,
};

static const char * const ts_field_names[] = {
  [0] = NULL,
  [field_keyword] = "keyword",
  [field_language] = "language",
  [field_priority] = "priority",
  [field_title] = "title",
  [field_type] = "type",
};

static const TSFieldMapSlice ts_field_map_slices[PRODUCTION_ID_COUNT] = {
  [1] = {.index = 0, .length = 1},
  [2] = {.index = 1, .length = 1},
  [3] = {.index = 2, .length = 1},
  [4] = {.index = 3, .length = 1},
  [5] = {.index = 4, .length = 2},
  [7] = {.index = 6, .length = 2},
  [8] = {.index = 8, .length = 2},
  [11] = {.index = 10, .length = 2},
  [12] = {.index = 12, .length = 3},
};

static const TSFieldMapEntry ts_field_map_entries[] = {
  [0] =
    {field_type, 1},
  [1] =
    {field_title, 2},
  [2] =
    {field_keyword, 2},
  [3] =
    {field_priority, 2},
  [4] =
    {field_language, 3},
    {field_type, 1},
  [6] =
    {field_keyword, 2},
    {field_title, 4},
  [8] =
    {field_priority, 2},
    {field_title, 4},
  [10] =
    {field_keyword, 2},
    {field_priority, 4},
  [12] =
    {field_keyword, 2},
    {field_priority, 4},
    {field_title, 6},
};

static const TSSymbol ts_alias_sequences[PRODUCTION_ID_COUNT][MAX_ALIAS_SEQUENCE_LENGTH] = {
  [0] = {0},
  [6] = {
    [3] = sym_value,
  },
  [9] = {
    [3] = alias_sym_link_description,
  },
  [10] = {
    [4] = sym_value,
  },
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
  [58] = 58,
  [59] = 59,
  [60] = 60,
  [61] = 61,
  [62] = 62,
  [63] = 63,
  [64] = 64,
  [65] = 65,
  [66] = 66,
  [67] = 67,
  [68] = 68,
  [69] = 69,
  [70] = 70,
  [71] = 71,
  [72] = 72,
  [73] = 73,
  [74] = 74,
  [75] = 75,
  [76] = 76,
  [77] = 77,
  [78] = 78,
  [79] = 79,
  [80] = 80,
  [81] = 81,
  [82] = 82,
  [83] = 83,
  [84] = 84,
  [85] = 85,
  [86] = 86,
  [87] = 87,
  [88] = 88,
  [89] = 89,
  [90] = 90,
  [91] = 91,
  [92] = 92,
  [93] = 93,
  [94] = 94,
  [95] = 95,
  [96] = 96,
  [97] = 97,
  [98] = 98,
  [99] = 99,
  [100] = 100,
  [101] = 101,
  [102] = 102,
  [103] = 103,
  [104] = 104,
  [105] = 105,
  [106] = 106,
  [107] = 107,
  [108] = 108,
  [109] = 109,
  [110] = 110,
  [111] = 111,
  [112] = 112,
  [113] = 113,
  [114] = 114,
  [115] = 115,
  [116] = 116,
  [117] = 117,
  [118] = 118,
  [119] = 119,
  [120] = 120,
  [121] = 121,
  [122] = 122,
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(115);
      ADVANCE_MAP(
        '#', 21,
        '$', 26,
        '(', 189,
        ')', 192,
        '*', 125,
        '-', 37,
        ':', 232,
        '<', 107,
        'C', 164,
        'D', 182,
        'N', 169,
        'T', 180,
        'W', 165,
        '[', 23,
        '\\', 106,
        ']', 64,
        '_', 216,
        '{', 79,
        '|', 223,
        '}', 81,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(0);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(186);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(187);
      END_STATE();
    case 1:
      if (lookahead == '\n') ADVANCE(196);
      END_STATE();
    case 2:
      if (lookahead == '\n') ADVANCE(196);
      if (lookahead == '{') ADVANCE(82);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(2);
      END_STATE();
    case 3:
      if (lookahead == '\n') ADVANCE(227);
      if (lookahead == '+') ADVANCE(33);
      if (lookahead == '-') ADVANCE(3);
      if (lookahead == '|') ADVANCE(4);
      END_STATE();
    case 4:
      if (lookahead == '\n') ADVANCE(227);
      if (lookahead == '-') ADVANCE(3);
      END_STATE();
    case 5:
      if (lookahead == '\n') ADVANCE(195);
      END_STATE();
    case 6:
      if (lookahead == '\n') ADVANCE(161);
      END_STATE();
    case 7:
      if (lookahead == '\n') ADVANCE(246);
      if (lookahead == '-') ADVANCE(7);
      END_STATE();
    case 8:
      if (lookahead == '\n') ADVANCE(194);
      END_STATE();
    case 9:
      if (lookahead == '\n') ADVANCE(198);
      if (lookahead != 0) ADVANCE(9);
      END_STATE();
    case 10:
      if (lookahead == '\n') ADVANCE(197);
      if (lookahead != 0) ADVANCE(10);
      END_STATE();
    case 11:
      if (lookahead == '\n') ADVANCE(118);
      if (lookahead == 'C') ADVANCE(133);
      if (lookahead == 'D') ADVANCE(151);
      if (lookahead == 'N') ADVANCE(139);
      if (lookahead == 'T') ADVANCE(150);
      if (lookahead == 'W') ADVANCE(134);
      if (lookahead == '[') ADVANCE(132);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(129);
      if (lookahead != 0) ADVANCE(159);
      END_STATE();
    case 12:
      if (lookahead == '\n') ADVANCE(119);
      if (lookahead == '|') ADVANCE(222);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(225);
      if (lookahead != 0) ADVANCE(226);
      END_STATE();
    case 13:
      if (lookahead == '\n') ADVANCE(120);
      if (lookahead == '[') ADVANCE(132);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(130);
      if (lookahead != 0) ADVANCE(159);
      END_STATE();
    case 14:
      if (lookahead == '\n') SKIP(14);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(157);
      if (lookahead != 0) ADVANCE(159);
      END_STATE();
    case 15:
      if (lookahead == '\n') SKIP(15);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(156);
      if ((0x0b <= lookahead && lookahead <= '\r')) ADVANCE(156);
      if (lookahead != 0) ADVANCE(159);
      END_STATE();
    case 16:
      if (lookahead == '\n') ADVANCE(121);
      if (lookahead == ' ') ADVANCE(116);
      if (('\t' <= lookahead && lookahead <= '\r')) SKIP(16);
      END_STATE();
    case 17:
      if (lookahead == '\n') ADVANCE(122);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(17);
      END_STATE();
    case 18:
      if (lookahead == '\n') SKIP(18);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(201);
      if (lookahead != 0 &&
          lookahead != ']') ADVANCE(202);
      END_STATE();
    case 19:
      if (lookahead == '\n') ADVANCE(329);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(19);
      END_STATE();
    case 20:
      if (lookahead == '\n') ADVANCE(123);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(131);
      if (lookahead != 0) ADVANCE(159);
      END_STATE();
    case 21:
      if (lookahead == ' ') ADVANCE(236);
      if (lookahead == '+') ADVANCE(228);
      END_STATE();
    case 22:
      if (lookahead == ' ') ADVANCE(117);
      if (('\t' <= lookahead && lookahead <= '\r')) SKIP(22);
      END_STATE();
    case 23:
      if (lookahead == '#') ADVANCE(105);
      if (lookahead == '[') ADVANCE(199);
      if (lookahead == 'f') ADVANCE(76);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(66);
      END_STATE();
    case 24:
      if (lookahead == '#') ADVANCE(31);
      if (lookahead == ':') ADVANCE(231);
      if (lookahead == '|') ADVANCE(222);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(24);
      if (lookahead == '-' ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(242);
      END_STATE();
    case 25:
      if (lookahead == '#') ADVANCE(30);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(219);
      if (lookahead != 0) ADVANCE(220);
      END_STATE();
    case 26:
      if (lookahead == '$') ADVANCE(110);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(28);
      END_STATE();
    case 27:
      if (lookahead == '$') ADVANCE(5);
      END_STATE();
    case 28:
      if (lookahead == '$') ADVANCE(5);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(28);
      END_STATE();
    case 29:
      if (lookahead == '$') ADVANCE(27);
      if (lookahead != 0) ADVANCE(29);
      END_STATE();
    case 30:
      if (lookahead == '+') ADVANCE(91);
      if (lookahead != 0) ADVANCE(220);
      END_STATE();
    case 31:
      if (lookahead == '+') ADVANCE(92);
      END_STATE();
    case 32:
      if (lookahead == '+') ADVANCE(94);
      if (lookahead != 0) ADVANCE(220);
      END_STATE();
    case 33:
      if (lookahead == '-') ADVANCE(3);
      END_STATE();
    case 34:
      if (lookahead == '-') ADVANCE(7);
      END_STATE();
    case 35:
      if (lookahead == '-') ADVANCE(34);
      END_STATE();
    case 36:
      if (lookahead == '-') ADVANCE(35);
      END_STATE();
    case 37:
      if (lookahead == '-') ADVANCE(36);
      END_STATE();
    case 38:
      if (lookahead == ':') ADVANCE(41);
      END_STATE();
    case 39:
      if (lookahead == ':') ADVANCE(241);
      END_STATE();
    case 40:
      if (lookahead == ':') ADVANCE(112);
      if (lookahead == ']') ADVANCE(8);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(40);
      END_STATE();
    case 41:
      if (lookahead == ':') ADVANCE(112);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(40);
      END_STATE();
    case 42:
      if (lookahead == ':') ADVANCE(238);
      END_STATE();
    case 43:
      if (lookahead == ':') ADVANCE(230);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(43);
      if (lookahead == '+' ||
          lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(218);
      END_STATE();
    case 44:
      if (lookahead == ':') ADVANCE(53);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(244);
      if (lookahead != 0) ADVANCE(245);
      END_STATE();
    case 45:
      if (lookahead == ':') ADVANCE(243);
      END_STATE();
    case 46:
      if (lookahead == ':') ADVANCE(243);
      if (lookahead != 0) ADVANCE(245);
      END_STATE();
    case 47:
      if (lookahead == ':') ADVANCE(75);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(47);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(235);
      END_STATE();
    case 48:
      if (lookahead == '>') ADVANCE(6);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(48);
      END_STATE();
    case 49:
      if (lookahead == 'D') ADVANCE(111);
      if (lookahead == 'd') ADVANCE(46);
      if (lookahead != 0) ADVANCE(245);
      END_STATE();
    case 50:
      if (lookahead == 'D') ADVANCE(39);
      END_STATE();
    case 51:
      if (lookahead == 'E') ADVANCE(61);
      END_STATE();
    case 52:
      if (lookahead == 'E') ADVANCE(60);
      END_STATE();
    case 53:
      if (lookahead == 'E') ADVANCE(101);
      if (lookahead == 'e') ADVANCE(56);
      if (lookahead != 0) ADVANCE(245);
      END_STATE();
    case 54:
      if (lookahead == 'I') ADVANCE(51);
      END_STATE();
    case 55:
      if (lookahead == 'N') ADVANCE(50);
      END_STATE();
    case 56:
      if (lookahead == 'N') ADVANCE(88);
      if (lookahead == 'n') ADVANCE(49);
      if (lookahead != 0) ADVANCE(245);
      END_STATE();
    case 57:
      if (lookahead == 'O') ADVANCE(58);
      END_STATE();
    case 58:
      if (lookahead == 'P') ADVANCE(52);
      END_STATE();
    case 59:
      if (lookahead == 'R') ADVANCE(57);
      END_STATE();
    case 60:
      if (lookahead == 'R') ADVANCE(62);
      END_STATE();
    case 61:
      if (lookahead == 'S') ADVANCE(42);
      END_STATE();
    case 62:
      if (lookahead == 'T') ADVANCE(54);
      END_STATE();
    case 63:
      if (lookahead == '[') ADVANCE(199);
      if (lookahead == 'f') ADVANCE(76);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(66);
      END_STATE();
    case 64:
      if (lookahead == '[') ADVANCE(203);
      if (lookahead == ']') ADVANCE(204);
      END_STATE();
    case 65:
      if (lookahead == ']') ADVANCE(128);
      END_STATE();
    case 66:
      if (lookahead == ']') ADVANCE(6);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(66);
      END_STATE();
    case 67:
      if (lookahead == ']') ADVANCE(8);
      if (lookahead != 0) ADVANCE(67);
      END_STATE();
    case 68:
      if (lookahead == '^') ADVANCE(108);
      if (lookahead == '_') ADVANCE(109);
      if (lookahead == ')' ||
          lookahead == '.') ADVANCE(210);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(68);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(70);
      END_STATE();
    case 69:
      if (lookahead == '^') ADVANCE(108);
      if (lookahead == '_') ADVANCE(109);
      if (lookahead == ')' ||
          lookahead == '.') ADVANCE(210);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(70);
      END_STATE();
    case 70:
      if (lookahead == '^') ADVANCE(108);
      if (lookahead == '_') ADVANCE(109);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(70);
      END_STATE();
    case 71:
      if (lookahead == '_') ADVANCE(214);
      END_STATE();
    case 72:
      if (lookahead == '_') ADVANCE(221);
      END_STATE();
    case 73:
      if (lookahead == '_') ADVANCE(221);
      if (lookahead != 0) ADVANCE(220);
      END_STATE();
    case 74:
      if (lookahead == 'd') ADVANCE(45);
      END_STATE();
    case 75:
      if (lookahead == 'e') ADVANCE(77);
      END_STATE();
    case 76:
      if (lookahead == 'n') ADVANCE(38);
      END_STATE();
    case 77:
      if (lookahead == 'n') ADVANCE(74);
      END_STATE();
    case 78:
      if (lookahead == '{') ADVANCE(162);
      END_STATE();
    case 79:
      if (lookahead == '{') ADVANCE(78);
      END_STATE();
    case 80:
      if (lookahead == '}') ADVANCE(193);
      END_STATE();
    case 81:
      if (lookahead == '}') ADVANCE(80);
      END_STATE();
    case 82:
      if (lookahead == '}') ADVANCE(1);
      END_STATE();
    case 83:
      if (lookahead == ')' ||
          lookahead == '.') ADVANCE(210);
      END_STATE();
    case 84:
      if (lookahead == ')' ||
          lookahead == '.') ADVANCE(210);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(84);
      END_STATE();
    case 85:
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(210);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(85);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(84);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(83);
      END_STATE();
    case 86:
      if (lookahead == 'D' ||
          lookahead == 'd') ADVANCE(73);
      if (lookahead != 0) ADVANCE(220);
      END_STATE();
    case 87:
      if (lookahead == 'D' ||
          lookahead == 'd') ADVANCE(113);
      if (lookahead != 0) ADVANCE(220);
      END_STATE();
    case 88:
      if (lookahead == 'D' ||
          lookahead == 'd') ADVANCE(111);
      if (lookahead != 0) ADVANCE(245);
      END_STATE();
    case 89:
      if (lookahead == 'D' ||
          lookahead == 'd') ADVANCE(72);
      END_STATE();
    case 90:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(95);
      END_STATE();
    case 91:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(99);
      if (lookahead != 0) ADVANCE(220);
      END_STATE();
    case 92:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(98);
      END_STATE();
    case 93:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(101);
      if (lookahead != 0) ADVANCE(245);
      END_STATE();
    case 94:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(100);
      if (lookahead != 0) ADVANCE(220);
      END_STATE();
    case 95:
      if (lookahead == 'G' ||
          lookahead == 'g') ADVANCE(96);
      END_STATE();
    case 96:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(97);
      END_STATE();
    case 97:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(71);
      END_STATE();
    case 98:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(89);
      END_STATE();
    case 99:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(86);
      if (lookahead != 0) ADVANCE(220);
      END_STATE();
    case 100:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(87);
      if (lookahead != 0) ADVANCE(220);
      END_STATE();
    case 101:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(88);
      if (lookahead != 0) ADVANCE(245);
      END_STATE();
    case 102:
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(190);
      if (lookahead != 0 &&
          lookahead != ')' &&
          lookahead != '}') ADVANCE(191);
      END_STATE();
    case 103:
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(103);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(217);
      END_STATE();
    case 104:
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(104);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(188);
      END_STATE();
    case 105:
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(65);
      END_STATE();
    case 106:
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(2);
      END_STATE();
    case 107:
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '>') ADVANCE(48);
      END_STATE();
    case 108:
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(9);
      END_STATE();
    case 109:
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(10);
      END_STATE();
    case 110:
      if (lookahead != 0 &&
          lookahead != '$') ADVANCE(29);
      END_STATE();
    case 111:
      if (lookahead != 0 &&
          lookahead != ':') ADVANCE(245);
      END_STATE();
    case 112:
      if (lookahead != 0 &&
          lookahead != ']') ADVANCE(67);
      END_STATE();
    case 113:
      if (lookahead != 0 &&
          lookahead != '_') ADVANCE(220);
      END_STATE();
    case 114:
      if (eof) ADVANCE(115);
      if (lookahead == '\n') SKIP(114);
      if (lookahead == '#') ADVANCE(21);
      if (lookahead == '$') ADVANCE(264);
      if (lookahead == '*') ADVANCE(125);
      if (lookahead == '+') ADVANCE(210);
      if (lookahead == '-') ADVANCE(212);
      if (lookahead == ':') ADVANCE(233);
      if (lookahead == '<') ADVANCE(277);
      if (lookahead == 'C') ADVANCE(295);
      if (lookahead == 'D') ADVANCE(286);
      if (lookahead == 'S') ADVANCE(282);
      if (lookahead == '[') ADVANCE(63);
      if (lookahead == '\\') ADVANCE(325);
      if (lookahead == '{') ADVANCE(79);
      if (lookahead == '|') ADVANCE(223);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(205);
      if ((0x0b <= lookahead && lookahead <= '\r')) ADVANCE(263);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(68);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(313);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(69);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 115:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 116:
      ACCEPT_TOKEN(anon_sym_SPACE);
      if (lookahead == '\n') ADVANCE(121);
      if (lookahead == ' ') ADVANCE(116);
      END_STATE();
    case 117:
      ACCEPT_TOKEN(anon_sym_SPACE);
      if (lookahead == ' ') ADVANCE(117);
      END_STATE();
    case 118:
      ACCEPT_TOKEN(anon_sym_LF);
      if (lookahead == '\n') ADVANCE(118);
      if (lookahead == 'C') ADVANCE(133);
      if (lookahead == 'D') ADVANCE(151);
      if (lookahead == 'N') ADVANCE(139);
      if (lookahead == 'T') ADVANCE(150);
      if (lookahead == 'W') ADVANCE(134);
      if (lookahead == '[') ADVANCE(132);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(129);
      END_STATE();
    case 119:
      ACCEPT_TOKEN(anon_sym_LF);
      if (lookahead == '\n') ADVANCE(119);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(225);
      END_STATE();
    case 120:
      ACCEPT_TOKEN(anon_sym_LF);
      if (lookahead == '\n') ADVANCE(120);
      if (lookahead == '[') ADVANCE(132);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(130);
      END_STATE();
    case 121:
      ACCEPT_TOKEN(anon_sym_LF);
      if (lookahead == '\n') ADVANCE(121);
      if (lookahead == ' ') ADVANCE(116);
      END_STATE();
    case 122:
      ACCEPT_TOKEN(anon_sym_LF);
      if (lookahead == '\n') ADVANCE(122);
      END_STATE();
    case 123:
      ACCEPT_TOKEN(anon_sym_LF);
      if (lookahead == '\n') ADVANCE(123);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(131);
      END_STATE();
    case 124:
      ACCEPT_TOKEN(anon_sym_LF);
      if (lookahead == '\n') ADVANCE(124);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(206);
      END_STATE();
    case 125:
      ACCEPT_TOKEN(sym_stars);
      if (lookahead == '*') ADVANCE(125);
      END_STATE();
    case 126:
      ACCEPT_TOKEN(sym_stars);
      if (lookahead == '*') ADVANCE(126);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(326);
      END_STATE();
    case 127:
      ACCEPT_TOKEN(sym_keyword);
      END_STATE();
    case 128:
      ACCEPT_TOKEN(sym_priority);
      END_STATE();
    case 129:
      ACCEPT_TOKEN(aux_sym_title_token1);
      if (lookahead == '\n') ADVANCE(118);
      if (lookahead == 'C') ADVANCE(133);
      if (lookahead == 'D') ADVANCE(151);
      if (lookahead == 'N') ADVANCE(139);
      if (lookahead == 'T') ADVANCE(150);
      if (lookahead == 'W') ADVANCE(134);
      if (lookahead == '[') ADVANCE(132);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(129);
      if (lookahead != 0) ADVANCE(159);
      END_STATE();
    case 130:
      ACCEPT_TOKEN(aux_sym_title_token1);
      if (lookahead == '\n') ADVANCE(120);
      if (lookahead == '[') ADVANCE(132);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(130);
      if (lookahead != 0) ADVANCE(159);
      END_STATE();
    case 131:
      ACCEPT_TOKEN(aux_sym_title_token1);
      if (lookahead == '\n') ADVANCE(123);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(131);
      if (lookahead != 0) ADVANCE(159);
      END_STATE();
    case 132:
      ACCEPT_TOKEN(aux_sym_title_token1);
      if (lookahead == '#') ADVANCE(158);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(159);
      END_STATE();
    case 133:
      ACCEPT_TOKEN(aux_sym_title_token1);
      if (lookahead == 'A') ADVANCE(146);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(159);
      END_STATE();
    case 134:
      ACCEPT_TOKEN(aux_sym_title_token1);
      if (lookahead == 'A') ADVANCE(143);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(159);
      END_STATE();
    case 135:
      ACCEPT_TOKEN(aux_sym_title_token1);
      if (lookahead == 'C') ADVANCE(140);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(159);
      END_STATE();
    case 136:
      ACCEPT_TOKEN(aux_sym_title_token1);
      if (lookahead == 'D') ADVANCE(127);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(159);
      END_STATE();
    case 137:
      ACCEPT_TOKEN(aux_sym_title_token1);
      if (lookahead == 'D') ADVANCE(149);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(159);
      END_STATE();
    case 138:
      ACCEPT_TOKEN(aux_sym_title_token1);
      if (lookahead == 'E') ADVANCE(127);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(159);
      END_STATE();
    case 139:
      ACCEPT_TOKEN(aux_sym_title_token1);
      if (lookahead == 'E') ADVANCE(154);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(159);
      END_STATE();
    case 140:
      ACCEPT_TOKEN(aux_sym_title_token1);
      if (lookahead == 'E') ADVANCE(145);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(159);
      END_STATE();
    case 141:
      ACCEPT_TOKEN(aux_sym_title_token1);
      if (lookahead == 'E') ADVANCE(136);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(159);
      END_STATE();
    case 142:
      ACCEPT_TOKEN(aux_sym_title_token1);
      if (lookahead == 'G') ADVANCE(127);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(159);
      END_STATE();
    case 143:
      ACCEPT_TOKEN(aux_sym_title_token1);
      if (lookahead == 'I') ADVANCE(153);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(159);
      END_STATE();
    case 144:
      ACCEPT_TOKEN(aux_sym_title_token1);
      if (lookahead == 'I') ADVANCE(147);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(159);
      END_STATE();
    case 145:
      ACCEPT_TOKEN(aux_sym_title_token1);
      if (lookahead == 'L') ADVANCE(141);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(159);
      END_STATE();
    case 146:
      ACCEPT_TOKEN(aux_sym_title_token1);
      if (lookahead == 'N') ADVANCE(135);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(159);
      END_STATE();
    case 147:
      ACCEPT_TOKEN(aux_sym_title_token1);
      if (lookahead == 'N') ADVANCE(142);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(159);
      END_STATE();
    case 148:
      ACCEPT_TOKEN(aux_sym_title_token1);
      if (lookahead == 'N') ADVANCE(138);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(159);
      END_STATE();
    case 149:
      ACCEPT_TOKEN(aux_sym_title_token1);
      if (lookahead == 'O') ADVANCE(127);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(159);
      END_STATE();
    case 150:
      ACCEPT_TOKEN(aux_sym_title_token1);
      if (lookahead == 'O') ADVANCE(137);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(159);
      END_STATE();
    case 151:
      ACCEPT_TOKEN(aux_sym_title_token1);
      if (lookahead == 'O') ADVANCE(148);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(159);
      END_STATE();
    case 152:
      ACCEPT_TOKEN(aux_sym_title_token1);
      if (lookahead == 'T') ADVANCE(127);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(159);
      END_STATE();
    case 153:
      ACCEPT_TOKEN(aux_sym_title_token1);
      if (lookahead == 'T') ADVANCE(144);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(159);
      END_STATE();
    case 154:
      ACCEPT_TOKEN(aux_sym_title_token1);
      if (lookahead == 'X') ADVANCE(152);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(159);
      END_STATE();
    case 155:
      ACCEPT_TOKEN(aux_sym_title_token1);
      if (lookahead == ']') ADVANCE(128);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(159);
      END_STATE();
    case 156:
      ACCEPT_TOKEN(aux_sym_title_token1);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(156);
      if ((0x0b <= lookahead && lookahead <= '\r')) ADVANCE(156);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead)) ADVANCE(159);
      END_STATE();
    case 157:
      ACCEPT_TOKEN(aux_sym_title_token1);
      if (lookahead == '\t' ||
          (0x0b <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(157);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead)) ADVANCE(159);
      END_STATE();
    case 158:
      ACCEPT_TOKEN(aux_sym_title_token1);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(155);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(159);
      END_STATE();
    case 159:
      ACCEPT_TOKEN(aux_sym_title_token1);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(159);
      END_STATE();
    case 160:
      ACCEPT_TOKEN(sym_planning_line);
      END_STATE();
    case 161:
      ACCEPT_TOKEN(sym_timestamp);
      END_STATE();
    case 162:
      ACCEPT_TOKEN(anon_sym_LBRACE_LBRACE_LBRACE);
      END_STATE();
    case 163:
      ACCEPT_TOKEN(anon_sym_LBRACE_LBRACE_LBRACE);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(326);
      END_STATE();
    case 164:
      ACCEPT_TOKEN(aux_sym_macro_token1);
      if (lookahead == 'A') ADVANCE(177);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(188);
      if (('B' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(186);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(187);
      END_STATE();
    case 165:
      ACCEPT_TOKEN(aux_sym_macro_token1);
      if (lookahead == 'A') ADVANCE(174);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(188);
      if (('B' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(186);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(187);
      END_STATE();
    case 166:
      ACCEPT_TOKEN(aux_sym_macro_token1);
      if (lookahead == 'C') ADVANCE(171);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(188);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(186);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(187);
      END_STATE();
    case 167:
      ACCEPT_TOKEN(aux_sym_macro_token1);
      if (lookahead == 'D') ADVANCE(127);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(188);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(186);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(187);
      END_STATE();
    case 168:
      ACCEPT_TOKEN(aux_sym_macro_token1);
      if (lookahead == 'D') ADVANCE(181);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(188);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(186);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(187);
      END_STATE();
    case 169:
      ACCEPT_TOKEN(aux_sym_macro_token1);
      if (lookahead == 'E') ADVANCE(185);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(188);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(186);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(187);
      END_STATE();
    case 170:
      ACCEPT_TOKEN(aux_sym_macro_token1);
      if (lookahead == 'E') ADVANCE(127);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(188);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(186);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(187);
      END_STATE();
    case 171:
      ACCEPT_TOKEN(aux_sym_macro_token1);
      if (lookahead == 'E') ADVANCE(176);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(188);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(186);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(187);
      END_STATE();
    case 172:
      ACCEPT_TOKEN(aux_sym_macro_token1);
      if (lookahead == 'E') ADVANCE(167);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(188);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(186);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(187);
      END_STATE();
    case 173:
      ACCEPT_TOKEN(aux_sym_macro_token1);
      if (lookahead == 'G') ADVANCE(127);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(188);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(186);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(187);
      END_STATE();
    case 174:
      ACCEPT_TOKEN(aux_sym_macro_token1);
      if (lookahead == 'I') ADVANCE(184);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(188);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(186);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(187);
      END_STATE();
    case 175:
      ACCEPT_TOKEN(aux_sym_macro_token1);
      if (lookahead == 'I') ADVANCE(178);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(188);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(186);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(187);
      END_STATE();
    case 176:
      ACCEPT_TOKEN(aux_sym_macro_token1);
      if (lookahead == 'L') ADVANCE(172);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(188);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(186);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(187);
      END_STATE();
    case 177:
      ACCEPT_TOKEN(aux_sym_macro_token1);
      if (lookahead == 'N') ADVANCE(166);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(188);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(186);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(187);
      END_STATE();
    case 178:
      ACCEPT_TOKEN(aux_sym_macro_token1);
      if (lookahead == 'N') ADVANCE(173);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(188);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(186);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(187);
      END_STATE();
    case 179:
      ACCEPT_TOKEN(aux_sym_macro_token1);
      if (lookahead == 'N') ADVANCE(170);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(188);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(186);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(187);
      END_STATE();
    case 180:
      ACCEPT_TOKEN(aux_sym_macro_token1);
      if (lookahead == 'O') ADVANCE(168);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(188);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(186);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(187);
      END_STATE();
    case 181:
      ACCEPT_TOKEN(aux_sym_macro_token1);
      if (lookahead == 'O') ADVANCE(127);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(188);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(186);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(187);
      END_STATE();
    case 182:
      ACCEPT_TOKEN(aux_sym_macro_token1);
      if (lookahead == 'O') ADVANCE(179);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(188);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(186);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(187);
      END_STATE();
    case 183:
      ACCEPT_TOKEN(aux_sym_macro_token1);
      if (lookahead == 'T') ADVANCE(127);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(188);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(186);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(187);
      END_STATE();
    case 184:
      ACCEPT_TOKEN(aux_sym_macro_token1);
      if (lookahead == 'T') ADVANCE(175);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(188);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(186);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(187);
      END_STATE();
    case 185:
      ACCEPT_TOKEN(aux_sym_macro_token1);
      if (lookahead == 'X') ADVANCE(183);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(188);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(186);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(187);
      END_STATE();
    case 186:
      ACCEPT_TOKEN(aux_sym_macro_token1);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(188);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(187);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(186);
      END_STATE();
    case 187:
      ACCEPT_TOKEN(aux_sym_macro_token1);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(188);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(187);
      END_STATE();
    case 188:
      ACCEPT_TOKEN(aux_sym_macro_token1);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(188);
      END_STATE();
    case 189:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      END_STATE();
    case 190:
      ACCEPT_TOKEN(aux_sym_macro_token2);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(190);
      if (lookahead != 0 &&
          lookahead != ')' &&
          lookahead != '}') ADVANCE(191);
      END_STATE();
    case 191:
      ACCEPT_TOKEN(aux_sym_macro_token2);
      if (lookahead != 0 &&
          lookahead != ')' &&
          lookahead != '}') ADVANCE(191);
      END_STATE();
    case 192:
      ACCEPT_TOKEN(anon_sym_RPAREN);
      END_STATE();
    case 193:
      ACCEPT_TOKEN(anon_sym_RBRACE_RBRACE_RBRACE);
      END_STATE();
    case 194:
      ACCEPT_TOKEN(sym_footnote_reference);
      END_STATE();
    case 195:
      ACCEPT_TOKEN(sym_latex_fragment);
      END_STATE();
    case 196:
      ACCEPT_TOKEN(sym_entity);
      END_STATE();
    case 197:
      ACCEPT_TOKEN(sym_subscript);
      END_STATE();
    case 198:
      ACCEPT_TOKEN(sym_superscript);
      END_STATE();
    case 199:
      ACCEPT_TOKEN(anon_sym_LBRACK_LBRACK);
      END_STATE();
    case 200:
      ACCEPT_TOKEN(anon_sym_LBRACK_LBRACK);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(326);
      END_STATE();
    case 201:
      ACCEPT_TOKEN(aux_sym_link_token1);
      if (lookahead == '\t' ||
          (0x0b <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(201);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ']') ADVANCE(202);
      END_STATE();
    case 202:
      ACCEPT_TOKEN(aux_sym_link_token1);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != ']') ADVANCE(202);
      END_STATE();
    case 203:
      ACCEPT_TOKEN(anon_sym_RBRACK_LBRACK);
      END_STATE();
    case 204:
      ACCEPT_TOKEN(anon_sym_RBRACK_RBRACK);
      END_STATE();
    case 205:
      ACCEPT_TOKEN(aux_sym_list_item_token1);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(205);
      if ((0x0b <= lookahead && lookahead <= '\r')) ADVANCE(263);
      END_STATE();
    case 206:
      ACCEPT_TOKEN(aux_sym_list_item_token2);
      if (lookahead == '\n') ADVANCE(124);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(206);
      if (lookahead != 0) ADVANCE(209);
      END_STATE();
    case 207:
      ACCEPT_TOKEN(aux_sym_list_item_token2);
      if (lookahead == '\t' ||
          (0x0b <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(207);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(208);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead)) ADVANCE(209);
      END_STATE();
    case 208:
      ACCEPT_TOKEN(aux_sym_list_item_token2);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(208);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(209);
      END_STATE();
    case 209:
      ACCEPT_TOKEN(aux_sym_list_item_token2);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(209);
      END_STATE();
    case 210:
      ACCEPT_TOKEN(sym_bullet);
      END_STATE();
    case 211:
      ACCEPT_TOKEN(sym_bullet);
      if (lookahead == '-') ADVANCE(270);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(326);
      END_STATE();
    case 212:
      ACCEPT_TOKEN(sym_bullet);
      if (lookahead == '-') ADVANCE(36);
      END_STATE();
    case 213:
      ACCEPT_TOKEN(sym_bullet);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(326);
      END_STATE();
    case 214:
      ACCEPT_TOKEN(aux_sym_block_begin_token1);
      END_STATE();
    case 215:
      ACCEPT_TOKEN(aux_sym_block_begin_token1);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(326);
      END_STATE();
    case 216:
      ACCEPT_TOKEN(sym_block_type);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(217);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(216);
      END_STATE();
    case 217:
      ACCEPT_TOKEN(sym_block_type);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(217);
      END_STATE();
    case 218:
      ACCEPT_TOKEN(sym_language);
      if (lookahead == '+' ||
          lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(218);
      END_STATE();
    case 219:
      ACCEPT_TOKEN(sym_block_content);
      if (lookahead == '#') ADVANCE(30);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(219);
      if (lookahead != 0) ADVANCE(220);
      END_STATE();
    case 220:
      ACCEPT_TOKEN(sym_block_content);
      if (lookahead == '#') ADVANCE(32);
      if (lookahead != 0) ADVANCE(220);
      END_STATE();
    case 221:
      ACCEPT_TOKEN(aux_sym_block_end_token1);
      END_STATE();
    case 222:
      ACCEPT_TOKEN(anon_sym_PIPE);
      END_STATE();
    case 223:
      ACCEPT_TOKEN(anon_sym_PIPE);
      if (lookahead == '-') ADVANCE(3);
      END_STATE();
    case 224:
      ACCEPT_TOKEN(anon_sym_PIPE);
      if (lookahead == '-') ADVANCE(251);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(326);
      END_STATE();
    case 225:
      ACCEPT_TOKEN(sym_table_cell);
      if (lookahead == '\n') ADVANCE(119);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(225);
      if (lookahead != 0 &&
          lookahead != '|') ADVANCE(226);
      END_STATE();
    case 226:
      ACCEPT_TOKEN(sym_table_cell);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '|') ADVANCE(226);
      END_STATE();
    case 227:
      ACCEPT_TOKEN(sym_table_separator);
      END_STATE();
    case 228:
      ACCEPT_TOKEN(aux_sym_directive_token1);
      if (lookahead == 'B' ||
          lookahead == 'b') ADVANCE(90);
      END_STATE();
    case 229:
      ACCEPT_TOKEN(aux_sym_directive_token1);
      if (lookahead == 'B' ||
          lookahead == 'b') ADVANCE(321);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(326);
      END_STATE();
    case 230:
      ACCEPT_TOKEN(anon_sym_COLON);
      END_STATE();
    case 231:
      ACCEPT_TOKEN(anon_sym_COLON);
      if (lookahead == 'E') ADVANCE(55);
      END_STATE();
    case 232:
      ACCEPT_TOKEN(anon_sym_COLON);
      if (lookahead == 'E') ADVANCE(55);
      if (lookahead == 'P') ADVANCE(59);
      END_STATE();
    case 233:
      ACCEPT_TOKEN(anon_sym_COLON);
      if (lookahead == 'P') ADVANCE(59);
      END_STATE();
    case 234:
      ACCEPT_TOKEN(anon_sym_COLON);
      if (lookahead == 'P') ADVANCE(302);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(326);
      END_STATE();
    case 235:
      ACCEPT_TOKEN(sym_name);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(235);
      END_STATE();
    case 236:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      END_STATE();
    case 237:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(326);
      END_STATE();
    case 238:
      ACCEPT_TOKEN(anon_sym_COLONPROPERTIES_COLON);
      END_STATE();
    case 239:
      ACCEPT_TOKEN(anon_sym_COLONPROPERTIES_COLON);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(326);
      END_STATE();
    case 240:
      ACCEPT_TOKEN(aux_sym_property_drawer_token1);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(240);
      END_STATE();
    case 241:
      ACCEPT_TOKEN(anon_sym_COLONEND_COLON);
      END_STATE();
    case 242:
      ACCEPT_TOKEN(aux_sym_key_token1);
      if (lookahead == '-' ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(242);
      END_STATE();
    case 243:
      ACCEPT_TOKEN(anon_sym_COLONend_COLON);
      END_STATE();
    case 244:
      ACCEPT_TOKEN(sym_drawer_content);
      if (lookahead == ':') ADVANCE(53);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(244);
      if (lookahead != 0) ADVANCE(245);
      END_STATE();
    case 245:
      ACCEPT_TOKEN(sym_drawer_content);
      if (lookahead == ':') ADVANCE(93);
      if (lookahead != 0) ADVANCE(245);
      END_STATE();
    case 246:
      ACCEPT_TOKEN(sym_horizontal_rule);
      END_STATE();
    case 247:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '\n') ADVANCE(29);
      if (lookahead == '$') ADVANCE(326);
      if (lookahead != 0) ADVANCE(248);
      END_STATE();
    case 248:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '\n') ADVANCE(29);
      if (lookahead == '$') ADVANCE(265);
      if (lookahead != 0) ADVANCE(248);
      END_STATE();
    case 249:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '\n') ADVANCE(196);
      if (lookahead == '{') ADVANCE(319);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(249);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 250:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '\n') ADVANCE(196);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 251:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '\n') ADVANCE(227);
      if (lookahead == '+') ADVANCE(267);
      if (lookahead == '-') ADVANCE(251);
      if (lookahead == '|') ADVANCE(252);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 252:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '\n') ADVANCE(227);
      if (lookahead == '-') ADVANCE(251);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 253:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '\n') ADVANCE(195);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 254:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '\n') ADVANCE(161);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 255:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '\n') ADVANCE(246);
      if (lookahead == '-') ADVANCE(255);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 256:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '\n') ADVANCE(67);
      if (lookahead == ']') ADVANCE(326);
      if (lookahead != 0) ADVANCE(257);
      END_STATE();
    case 257:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '\n') ADVANCE(67);
      if (lookahead == ']') ADVANCE(258);
      if (lookahead != 0) ADVANCE(257);
      END_STATE();
    case 258:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '\n') ADVANCE(194);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 259:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '\n') ADVANCE(198);
      if (lookahead != 0) ADVANCE(259);
      END_STATE();
    case 260:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '\n') ADVANCE(197);
      if (lookahead != 0) ADVANCE(260);
      END_STATE();
    case 261:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '\n') ADVANCE(160);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 262:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == ' ') ADVANCE(237);
      if (lookahead == '+') ADVANCE(229);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(326);
      END_STATE();
    case 263:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      ADVANCE_MAP(
        '#', 262,
        '$', 264,
        '*', 126,
        '+', 213,
        '-', 211,
        ':', 234,
        '<', 277,
        'C', 295,
        'D', 286,
        'S', 282,
        '[', 308,
        '\\', 325,
        '{', 318,
        '|', 224,
        '\t', 205,
        ' ', 205,
      );
      if ((0x0b <= lookahead && lookahead <= '\r')) ADVANCE(263);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(312);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(313);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(313);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead)) ADVANCE(326);
      END_STATE();
    case 264:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '$') ADVANCE(247);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(266);
      END_STATE();
    case 265:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '$') ADVANCE(253);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(326);
      END_STATE();
    case 266:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '$') ADVANCE(253);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(266);
      END_STATE();
    case 267:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '-') ADVANCE(251);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(326);
      END_STATE();
    case 268:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '-') ADVANCE(255);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(326);
      END_STATE();
    case 269:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '-') ADVANCE(268);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(326);
      END_STATE();
    case 270:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '-') ADVANCE(269);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(326);
      END_STATE();
    case 271:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == ':') ADVANCE(273);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(326);
      END_STATE();
    case 272:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == ':') ADVANCE(256);
      if (lookahead == ']') ADVANCE(258);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(272);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(326);
      END_STATE();
    case 273:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == ':') ADVANCE(256);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(272);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(326);
      END_STATE();
    case 274:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == ':') ADVANCE(320);
      if (lookahead == '^') ADVANCE(327);
      if (lookahead == '_') ADVANCE(328);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(314);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(326);
      END_STATE();
    case 275:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == ':') ADVANCE(239);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(326);
      END_STATE();
    case 276:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '<') ADVANCE(278);
      if (lookahead == '[') ADVANCE(309);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(276);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n') ADVANCE(326);
      END_STATE();
    case 277:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '>') ADVANCE(326);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(279);
      END_STATE();
    case 278:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '>') ADVANCE(326);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(280);
      END_STATE();
    case 279:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '>') ADVANCE(254);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(279);
      END_STATE();
    case 280:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '>') ADVANCE(261);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(280);
      END_STATE();
    case 281:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == 'A') ADVANCE(283);
      if (lookahead == '^') ADVANCE(327);
      if (lookahead == '_') ADVANCE(328);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('B' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(314);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(326);
      END_STATE();
    case 282:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == 'C') ADVANCE(292);
      if (lookahead == '^') ADVANCE(327);
      if (lookahead == '_') ADVANCE(328);
      if (lookahead == ')' ||
          lookahead == '.') ADVANCE(213);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(314);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(326);
      END_STATE();
    case 283:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == 'D') ADVANCE(296);
      if (lookahead == '^') ADVANCE(327);
      if (lookahead == '_') ADVANCE(328);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(314);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(326);
      END_STATE();
    case 284:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == 'D') ADVANCE(307);
      if (lookahead == '^') ADVANCE(327);
      if (lookahead == '_') ADVANCE(328);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(314);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(326);
      END_STATE();
    case 285:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == 'D') ADVANCE(274);
      if (lookahead == '^') ADVANCE(327);
      if (lookahead == '_') ADVANCE(328);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(314);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(326);
      END_STATE();
    case 286:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == 'E') ADVANCE(281);
      if (lookahead == '^') ADVANCE(327);
      if (lookahead == '_') ADVANCE(328);
      if (lookahead == ')' ||
          lookahead == '.') ADVANCE(213);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(314);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(326);
      END_STATE();
    case 287:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == 'E') ADVANCE(274);
      if (lookahead == '^') ADVANCE(327);
      if (lookahead == '_') ADVANCE(328);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(314);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(326);
      END_STATE();
    case 288:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == 'E') ADVANCE(304);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(326);
      END_STATE();
    case 289:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == 'E') ADVANCE(284);
      if (lookahead == '^') ADVANCE(327);
      if (lookahead == '_') ADVANCE(328);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(314);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(326);
      END_STATE();
    case 290:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == 'E') ADVANCE(303);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(326);
      END_STATE();
    case 291:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == 'E') ADVANCE(285);
      if (lookahead == '^') ADVANCE(327);
      if (lookahead == '_') ADVANCE(328);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(314);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(326);
      END_STATE();
    case 292:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == 'H') ADVANCE(289);
      if (lookahead == '^') ADVANCE(327);
      if (lookahead == '_') ADVANCE(328);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(314);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(326);
      END_STATE();
    case 293:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == 'I') ADVANCE(298);
      if (lookahead == '^') ADVANCE(327);
      if (lookahead == '_') ADVANCE(328);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(314);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(326);
      END_STATE();
    case 294:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == 'I') ADVANCE(288);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(326);
      END_STATE();
    case 295:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == 'L') ADVANCE(299);
      if (lookahead == '^') ADVANCE(327);
      if (lookahead == '_') ADVANCE(328);
      if (lookahead == ')' ||
          lookahead == '.') ADVANCE(213);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(314);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(326);
      END_STATE();
    case 296:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == 'L') ADVANCE(293);
      if (lookahead == '^') ADVANCE(327);
      if (lookahead == '_') ADVANCE(328);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(314);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(326);
      END_STATE();
    case 297:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == 'L') ADVANCE(291);
      if (lookahead == '^') ADVANCE(327);
      if (lookahead == '_') ADVANCE(328);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(314);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(326);
      END_STATE();
    case 298:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == 'N') ADVANCE(287);
      if (lookahead == '^') ADVANCE(327);
      if (lookahead == '_') ADVANCE(328);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(314);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(326);
      END_STATE();
    case 299:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == 'O') ADVANCE(305);
      if (lookahead == '^') ADVANCE(327);
      if (lookahead == '_') ADVANCE(328);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(314);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(326);
      END_STATE();
    case 300:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == 'O') ADVANCE(301);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(326);
      END_STATE();
    case 301:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == 'P') ADVANCE(290);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(326);
      END_STATE();
    case 302:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == 'R') ADVANCE(300);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(326);
      END_STATE();
    case 303:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == 'R') ADVANCE(306);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(326);
      END_STATE();
    case 304:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == 'S') ADVANCE(275);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(326);
      END_STATE();
    case 305:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == 'S') ADVANCE(291);
      if (lookahead == '^') ADVANCE(327);
      if (lookahead == '_') ADVANCE(328);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(314);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(326);
      END_STATE();
    case 306:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == 'T') ADVANCE(294);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(326);
      END_STATE();
    case 307:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == 'U') ADVANCE(297);
      if (lookahead == '^') ADVANCE(327);
      if (lookahead == '_') ADVANCE(328);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(314);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(326);
      END_STATE();
    case 308:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '[') ADVANCE(200);
      if (lookahead == 'f') ADVANCE(316);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(310);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(326);
      END_STATE();
    case 309:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == ']') ADVANCE(326);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(311);
      END_STATE();
    case 310:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == ']') ADVANCE(254);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(310);
      END_STATE();
    case 311:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == ']') ADVANCE(261);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(311);
      END_STATE();
    case 312:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '^') ADVANCE(327);
      if (lookahead == '_') ADVANCE(328);
      if (lookahead == ')' ||
          lookahead == '.') ADVANCE(213);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(312);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(314);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(326);
      END_STATE();
    case 313:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '^') ADVANCE(327);
      if (lookahead == '_') ADVANCE(328);
      if (lookahead == ')' ||
          lookahead == '.') ADVANCE(213);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(314);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(326);
      END_STATE();
    case 314:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '^') ADVANCE(327);
      if (lookahead == '_') ADVANCE(328);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(314);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(326);
      END_STATE();
    case 315:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '_') ADVANCE(215);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(326);
      END_STATE();
    case 316:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == 'n') ADVANCE(271);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(326);
      END_STATE();
    case 317:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '{') ADVANCE(163);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(326);
      END_STATE();
    case 318:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '{') ADVANCE(317);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(326);
      END_STATE();
    case 319:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '}') ADVANCE(250);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(326);
      END_STATE();
    case 320:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(276);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n') ADVANCE(326);
      END_STATE();
    case 321:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(322);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(326);
      END_STATE();
    case 322:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == 'G' ||
          lookahead == 'g') ADVANCE(323);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(326);
      END_STATE();
    case 323:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(324);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(326);
      END_STATE();
    case 324:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(315);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(326);
      END_STATE();
    case 325:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(249);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(326);
      END_STATE();
    case 326:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(326);
      END_STATE();
    case 327:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(259);
      END_STATE();
    case 328:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(260);
      END_STATE();
    case 329:
      ACCEPT_TOKEN(aux_sym_paragraph_token2);
      if (lookahead == '\n') ADVANCE(329);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 114},
  [2] = {.lex_state = 114},
  [3] = {.lex_state = 114},
  [4] = {.lex_state = 114},
  [5] = {.lex_state = 114},
  [6] = {.lex_state = 114},
  [7] = {.lex_state = 114},
  [8] = {.lex_state = 114},
  [9] = {.lex_state = 114},
  [10] = {.lex_state = 114},
  [11] = {.lex_state = 114},
  [12] = {.lex_state = 114},
  [13] = {.lex_state = 114},
  [14] = {.lex_state = 114},
  [15] = {.lex_state = 114},
  [16] = {.lex_state = 114},
  [17] = {.lex_state = 114},
  [18] = {.lex_state = 114},
  [19] = {.lex_state = 114},
  [20] = {.lex_state = 114},
  [21] = {.lex_state = 114},
  [22] = {.lex_state = 114},
  [23] = {.lex_state = 114},
  [24] = {.lex_state = 114},
  [25] = {.lex_state = 114},
  [26] = {.lex_state = 114},
  [27] = {.lex_state = 114},
  [28] = {.lex_state = 114},
  [29] = {.lex_state = 114},
  [30] = {.lex_state = 114},
  [31] = {.lex_state = 114},
  [32] = {.lex_state = 114},
  [33] = {.lex_state = 114},
  [34] = {.lex_state = 114},
  [35] = {.lex_state = 11},
  [36] = {.lex_state = 12},
  [37] = {.lex_state = 24},
  [38] = {.lex_state = 12},
  [39] = {.lex_state = 13},
  [40] = {.lex_state = 24},
  [41] = {.lex_state = 12},
  [42] = {.lex_state = 12},
  [43] = {.lex_state = 20},
  [44] = {.lex_state = 20},
  [45] = {.lex_state = 25},
  [46] = {.lex_state = 43},
  [47] = {.lex_state = 24},
  [48] = {.lex_state = 206},
  [49] = {.lex_state = 25},
  [50] = {.lex_state = 24},
  [51] = {.lex_state = 14},
  [52] = {.lex_state = 25},
  [53] = {.lex_state = 207},
  [54] = {.lex_state = 44},
  [55] = {.lex_state = 24},
  [56] = {.lex_state = 15},
  [57] = {.lex_state = 16},
  [58] = {.lex_state = 0},
  [59] = {.lex_state = 0},
  [60] = {.lex_state = 25},
  [61] = {.lex_state = 24},
  [62] = {.lex_state = 43},
  [63] = {.lex_state = 207},
  [64] = {.lex_state = 22},
  [65] = {.lex_state = 17},
  [66] = {.lex_state = 0},
  [67] = {.lex_state = 240},
  [68] = {.lex_state = 0},
  [69] = {.lex_state = 43},
  [70] = {.lex_state = 17},
  [71] = {.lex_state = 17},
  [72] = {.lex_state = 207},
  [73] = {.lex_state = 17},
  [74] = {.lex_state = 14},
  [75] = {.lex_state = 17},
  [76] = {.lex_state = 17},
  [77] = {.lex_state = 18},
  [78] = {.lex_state = 17},
  [79] = {.lex_state = 17},
  [80] = {.lex_state = 102},
  [81] = {.lex_state = 22},
  [82] = {.lex_state = 17},
  [83] = {.lex_state = 17},
  [84] = {.lex_state = 17},
  [85] = {.lex_state = 0},
  [86] = {.lex_state = 17},
  [87] = {.lex_state = 17},
  [88] = {.lex_state = 22},
  [89] = {.lex_state = 17},
  [90] = {.lex_state = 22},
  [91] = {.lex_state = 17},
  [92] = {.lex_state = 17},
  [93] = {.lex_state = 43},
  [94] = {.lex_state = 43},
  [95] = {.lex_state = 240},
  [96] = {.lex_state = 17},
  [97] = {.lex_state = 43},
  [98] = {.lex_state = 43},
  [99] = {.lex_state = 24},
  [100] = {.lex_state = 207},
  [101] = {.lex_state = 17},
  [102] = {.lex_state = 22},
  [103] = {.lex_state = 0},
  [104] = {.lex_state = 19},
  [105] = {.lex_state = 240},
  [106] = {.lex_state = 47},
  [107] = {.lex_state = 240},
  [108] = {.lex_state = 17},
  [109] = {.lex_state = 240},
  [110] = {.lex_state = 17},
  [111] = {.lex_state = 207},
  [112] = {.lex_state = 17},
  [113] = {.lex_state = 240},
  [114] = {.lex_state = 47},
  [115] = {.lex_state = 103},
  [116] = {.lex_state = 22},
  [117] = {.lex_state = 85},
  [118] = {.lex_state = 17},
  [119] = {.lex_state = 17},
  [120] = {.lex_state = 17},
  [121] = {.lex_state = 18},
  [122] = {.lex_state = 104},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [sym_stars] = ACTIONS(1),
    [sym_keyword] = ACTIONS(1),
    [sym_priority] = ACTIONS(1),
    [sym_timestamp] = ACTIONS(1),
    [anon_sym_LBRACE_LBRACE_LBRACE] = ACTIONS(1),
    [aux_sym_macro_token1] = ACTIONS(1),
    [anon_sym_LPAREN] = ACTIONS(1),
    [anon_sym_RPAREN] = ACTIONS(1),
    [anon_sym_RBRACE_RBRACE_RBRACE] = ACTIONS(1),
    [sym_footnote_reference] = ACTIONS(1),
    [sym_latex_fragment] = ACTIONS(1),
    [sym_entity] = ACTIONS(1),
    [anon_sym_LBRACK_LBRACK] = ACTIONS(1),
    [anon_sym_RBRACK_LBRACK] = ACTIONS(1),
    [anon_sym_RBRACK_RBRACK] = ACTIONS(1),
    [aux_sym_block_begin_token1] = ACTIONS(1),
    [sym_block_type] = ACTIONS(1),
    [anon_sym_PIPE] = ACTIONS(1),
    [sym_table_separator] = ACTIONS(1),
    [aux_sym_directive_token1] = ACTIONS(1),
    [anon_sym_COLON] = ACTIONS(1),
    [sym_name] = ACTIONS(1),
    [aux_sym_comment_token1] = ACTIONS(1),
    [anon_sym_COLONPROPERTIES_COLON] = ACTIONS(1),
    [anon_sym_COLONEND_COLON] = ACTIONS(1),
    [sym_horizontal_rule] = ACTIONS(1),
  },
  [1] = {
    [sym_document] = STATE(103),
    [sym__element] = STATE(3),
    [sym_headline] = STATE(3),
    [sym_macro] = STATE(3),
    [sym_link] = STATE(3),
    [sym_list] = STATE(3),
    [sym_list_item] = STATE(4),
    [sym_block] = STATE(3),
    [sym_block_begin] = STATE(45),
    [sym_table] = STATE(3),
    [sym_table_row] = STATE(7),
    [sym_directive] = STATE(3),
    [sym_comment] = STATE(3),
    [sym_property_drawer] = STATE(3),
    [sym_drawer] = STATE(3),
    [sym_paragraph] = STATE(3),
    [aux_sym_document_repeat1] = STATE(3),
    [aux_sym_list_repeat1] = STATE(4),
    [aux_sym_table_repeat1] = STATE(7),
    [ts_builtin_sym_end] = ACTIONS(3),
    [sym_stars] = ACTIONS(5),
    [sym_planning_line] = ACTIONS(7),
    [sym_timestamp] = ACTIONS(7),
    [anon_sym_LBRACE_LBRACE_LBRACE] = ACTIONS(9),
    [sym_footnote_reference] = ACTIONS(7),
    [sym_latex_fragment] = ACTIONS(7),
    [sym_entity] = ACTIONS(7),
    [sym_subscript] = ACTIONS(7),
    [sym_superscript] = ACTIONS(7),
    [anon_sym_LBRACK_LBRACK] = ACTIONS(11),
    [aux_sym_list_item_token1] = ACTIONS(13),
    [sym_bullet] = ACTIONS(15),
    [aux_sym_block_begin_token1] = ACTIONS(17),
    [anon_sym_PIPE] = ACTIONS(19),
    [sym_table_separator] = ACTIONS(21),
    [aux_sym_directive_token1] = ACTIONS(23),
    [anon_sym_COLON] = ACTIONS(25),
    [aux_sym_comment_token1] = ACTIONS(27),
    [anon_sym_COLONPROPERTIES_COLON] = ACTIONS(29),
    [sym_horizontal_rule] = ACTIONS(7),
    [aux_sym_paragraph_token1] = ACTIONS(31),
  },
  [2] = {
    [sym__element] = STATE(2),
    [sym_headline] = STATE(2),
    [sym_macro] = STATE(2),
    [sym_link] = STATE(2),
    [sym_list] = STATE(2),
    [sym_list_item] = STATE(4),
    [sym_block] = STATE(2),
    [sym_block_begin] = STATE(45),
    [sym_table] = STATE(2),
    [sym_table_row] = STATE(7),
    [sym_directive] = STATE(2),
    [sym_comment] = STATE(2),
    [sym_property_drawer] = STATE(2),
    [sym_drawer] = STATE(2),
    [sym_paragraph] = STATE(2),
    [aux_sym_document_repeat1] = STATE(2),
    [aux_sym_list_repeat1] = STATE(4),
    [aux_sym_table_repeat1] = STATE(7),
    [ts_builtin_sym_end] = ACTIONS(33),
    [sym_stars] = ACTIONS(35),
    [sym_planning_line] = ACTIONS(38),
    [sym_timestamp] = ACTIONS(38),
    [anon_sym_LBRACE_LBRACE_LBRACE] = ACTIONS(41),
    [sym_footnote_reference] = ACTIONS(38),
    [sym_latex_fragment] = ACTIONS(38),
    [sym_entity] = ACTIONS(38),
    [sym_subscript] = ACTIONS(38),
    [sym_superscript] = ACTIONS(38),
    [anon_sym_LBRACK_LBRACK] = ACTIONS(44),
    [aux_sym_list_item_token1] = ACTIONS(47),
    [sym_bullet] = ACTIONS(50),
    [aux_sym_block_begin_token1] = ACTIONS(53),
    [anon_sym_PIPE] = ACTIONS(56),
    [sym_table_separator] = ACTIONS(59),
    [aux_sym_directive_token1] = ACTIONS(62),
    [anon_sym_COLON] = ACTIONS(65),
    [aux_sym_comment_token1] = ACTIONS(68),
    [anon_sym_COLONPROPERTIES_COLON] = ACTIONS(71),
    [sym_horizontal_rule] = ACTIONS(38),
    [aux_sym_paragraph_token1] = ACTIONS(74),
  },
  [3] = {
    [sym__element] = STATE(2),
    [sym_headline] = STATE(2),
    [sym_macro] = STATE(2),
    [sym_link] = STATE(2),
    [sym_list] = STATE(2),
    [sym_list_item] = STATE(4),
    [sym_block] = STATE(2),
    [sym_block_begin] = STATE(45),
    [sym_table] = STATE(2),
    [sym_table_row] = STATE(7),
    [sym_directive] = STATE(2),
    [sym_comment] = STATE(2),
    [sym_property_drawer] = STATE(2),
    [sym_drawer] = STATE(2),
    [sym_paragraph] = STATE(2),
    [aux_sym_document_repeat1] = STATE(2),
    [aux_sym_list_repeat1] = STATE(4),
    [aux_sym_table_repeat1] = STATE(7),
    [ts_builtin_sym_end] = ACTIONS(77),
    [sym_stars] = ACTIONS(5),
    [sym_planning_line] = ACTIONS(79),
    [sym_timestamp] = ACTIONS(79),
    [anon_sym_LBRACE_LBRACE_LBRACE] = ACTIONS(9),
    [sym_footnote_reference] = ACTIONS(79),
    [sym_latex_fragment] = ACTIONS(79),
    [sym_entity] = ACTIONS(79),
    [sym_subscript] = ACTIONS(79),
    [sym_superscript] = ACTIONS(79),
    [anon_sym_LBRACK_LBRACK] = ACTIONS(11),
    [aux_sym_list_item_token1] = ACTIONS(13),
    [sym_bullet] = ACTIONS(15),
    [aux_sym_block_begin_token1] = ACTIONS(17),
    [anon_sym_PIPE] = ACTIONS(19),
    [sym_table_separator] = ACTIONS(21),
    [aux_sym_directive_token1] = ACTIONS(23),
    [anon_sym_COLON] = ACTIONS(25),
    [aux_sym_comment_token1] = ACTIONS(27),
    [anon_sym_COLONPROPERTIES_COLON] = ACTIONS(29),
    [sym_horizontal_rule] = ACTIONS(79),
    [aux_sym_paragraph_token1] = ACTIONS(31),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 5,
    ACTIONS(13), 1,
      aux_sym_list_item_token1,
    ACTIONS(15), 1,
      sym_bullet,
    ACTIONS(81), 1,
      ts_builtin_sym_end,
    STATE(6), 2,
      sym_list_item,
      aux_sym_list_repeat1,
    ACTIONS(83), 19,
      sym_stars,
      sym_planning_line,
      sym_timestamp,
      anon_sym_LBRACE_LBRACE_LBRACE,
      sym_footnote_reference,
      sym_latex_fragment,
      sym_entity,
      sym_subscript,
      sym_superscript,
      anon_sym_LBRACK_LBRACK,
      aux_sym_block_begin_token1,
      anon_sym_PIPE,
      sym_table_separator,
      aux_sym_directive_token1,
      anon_sym_COLON,
      aux_sym_comment_token1,
      anon_sym_COLONPROPERTIES_COLON,
      sym_horizontal_rule,
      aux_sym_paragraph_token1,
  [35] = 5,
    ACTIONS(85), 1,
      ts_builtin_sym_end,
    ACTIONS(89), 1,
      anon_sym_PIPE,
    ACTIONS(92), 1,
      sym_table_separator,
    STATE(5), 2,
      sym_table_row,
      aux_sym_table_repeat1,
    ACTIONS(87), 19,
      sym_stars,
      sym_planning_line,
      sym_timestamp,
      anon_sym_LBRACE_LBRACE_LBRACE,
      sym_footnote_reference,
      sym_latex_fragment,
      sym_entity,
      sym_subscript,
      sym_superscript,
      anon_sym_LBRACK_LBRACK,
      aux_sym_list_item_token1,
      sym_bullet,
      aux_sym_block_begin_token1,
      aux_sym_directive_token1,
      anon_sym_COLON,
      aux_sym_comment_token1,
      anon_sym_COLONPROPERTIES_COLON,
      sym_horizontal_rule,
      aux_sym_paragraph_token1,
  [70] = 5,
    ACTIONS(95), 1,
      ts_builtin_sym_end,
    ACTIONS(99), 1,
      aux_sym_list_item_token1,
    ACTIONS(102), 1,
      sym_bullet,
    STATE(6), 2,
      sym_list_item,
      aux_sym_list_repeat1,
    ACTIONS(97), 19,
      sym_stars,
      sym_planning_line,
      sym_timestamp,
      anon_sym_LBRACE_LBRACE_LBRACE,
      sym_footnote_reference,
      sym_latex_fragment,
      sym_entity,
      sym_subscript,
      sym_superscript,
      anon_sym_LBRACK_LBRACK,
      aux_sym_block_begin_token1,
      anon_sym_PIPE,
      sym_table_separator,
      aux_sym_directive_token1,
      anon_sym_COLON,
      aux_sym_comment_token1,
      anon_sym_COLONPROPERTIES_COLON,
      sym_horizontal_rule,
      aux_sym_paragraph_token1,
  [105] = 5,
    ACTIONS(19), 1,
      anon_sym_PIPE,
    ACTIONS(105), 1,
      ts_builtin_sym_end,
    ACTIONS(109), 1,
      sym_table_separator,
    STATE(5), 2,
      sym_table_row,
      aux_sym_table_repeat1,
    ACTIONS(107), 19,
      sym_stars,
      sym_planning_line,
      sym_timestamp,
      anon_sym_LBRACE_LBRACE_LBRACE,
      sym_footnote_reference,
      sym_latex_fragment,
      sym_entity,
      sym_subscript,
      sym_superscript,
      anon_sym_LBRACK_LBRACK,
      aux_sym_list_item_token1,
      sym_bullet,
      aux_sym_block_begin_token1,
      aux_sym_directive_token1,
      anon_sym_COLON,
      aux_sym_comment_token1,
      anon_sym_COLONPROPERTIES_COLON,
      sym_horizontal_rule,
      aux_sym_paragraph_token1,
  [140] = 2,
    ACTIONS(111), 1,
      ts_builtin_sym_end,
    ACTIONS(113), 21,
      sym_stars,
      sym_planning_line,
      sym_timestamp,
      anon_sym_LBRACE_LBRACE_LBRACE,
      sym_footnote_reference,
      sym_latex_fragment,
      sym_entity,
      sym_subscript,
      sym_superscript,
      anon_sym_LBRACK_LBRACK,
      aux_sym_list_item_token1,
      sym_bullet,
      aux_sym_block_begin_token1,
      anon_sym_PIPE,
      sym_table_separator,
      aux_sym_directive_token1,
      anon_sym_COLON,
      aux_sym_comment_token1,
      anon_sym_COLONPROPERTIES_COLON,
      sym_horizontal_rule,
      aux_sym_paragraph_token1,
  [167] = 2,
    ACTIONS(115), 1,
      ts_builtin_sym_end,
    ACTIONS(117), 21,
      sym_stars,
      sym_planning_line,
      sym_timestamp,
      anon_sym_LBRACE_LBRACE_LBRACE,
      sym_footnote_reference,
      sym_latex_fragment,
      sym_entity,
      sym_subscript,
      sym_superscript,
      anon_sym_LBRACK_LBRACK,
      aux_sym_list_item_token1,
      sym_bullet,
      aux_sym_block_begin_token1,
      anon_sym_PIPE,
      sym_table_separator,
      aux_sym_directive_token1,
      anon_sym_COLON,
      aux_sym_comment_token1,
      anon_sym_COLONPROPERTIES_COLON,
      sym_horizontal_rule,
      aux_sym_paragraph_token1,
  [194] = 2,
    ACTIONS(119), 1,
      ts_builtin_sym_end,
    ACTIONS(121), 21,
      sym_stars,
      sym_planning_line,
      sym_timestamp,
      anon_sym_LBRACE_LBRACE_LBRACE,
      sym_footnote_reference,
      sym_latex_fragment,
      sym_entity,
      sym_subscript,
      sym_superscript,
      anon_sym_LBRACK_LBRACK,
      aux_sym_list_item_token1,
      sym_bullet,
      aux_sym_block_begin_token1,
      anon_sym_PIPE,
      sym_table_separator,
      aux_sym_directive_token1,
      anon_sym_COLON,
      aux_sym_comment_token1,
      anon_sym_COLONPROPERTIES_COLON,
      sym_horizontal_rule,
      aux_sym_paragraph_token1,
  [221] = 2,
    ACTIONS(123), 1,
      ts_builtin_sym_end,
    ACTIONS(125), 21,
      sym_stars,
      sym_planning_line,
      sym_timestamp,
      anon_sym_LBRACE_LBRACE_LBRACE,
      sym_footnote_reference,
      sym_latex_fragment,
      sym_entity,
      sym_subscript,
      sym_superscript,
      anon_sym_LBRACK_LBRACK,
      aux_sym_list_item_token1,
      sym_bullet,
      aux_sym_block_begin_token1,
      anon_sym_PIPE,
      sym_table_separator,
      aux_sym_directive_token1,
      anon_sym_COLON,
      aux_sym_comment_token1,
      anon_sym_COLONPROPERTIES_COLON,
      sym_horizontal_rule,
      aux_sym_paragraph_token1,
  [248] = 2,
    ACTIONS(127), 1,
      ts_builtin_sym_end,
    ACTIONS(129), 21,
      sym_stars,
      sym_planning_line,
      sym_timestamp,
      anon_sym_LBRACE_LBRACE_LBRACE,
      sym_footnote_reference,
      sym_latex_fragment,
      sym_entity,
      sym_subscript,
      sym_superscript,
      anon_sym_LBRACK_LBRACK,
      aux_sym_list_item_token1,
      sym_bullet,
      aux_sym_block_begin_token1,
      anon_sym_PIPE,
      sym_table_separator,
      aux_sym_directive_token1,
      anon_sym_COLON,
      aux_sym_comment_token1,
      anon_sym_COLONPROPERTIES_COLON,
      sym_horizontal_rule,
      aux_sym_paragraph_token1,
  [275] = 2,
    ACTIONS(131), 1,
      ts_builtin_sym_end,
    ACTIONS(133), 21,
      sym_stars,
      sym_planning_line,
      sym_timestamp,
      anon_sym_LBRACE_LBRACE_LBRACE,
      sym_footnote_reference,
      sym_latex_fragment,
      sym_entity,
      sym_subscript,
      sym_superscript,
      anon_sym_LBRACK_LBRACK,
      aux_sym_list_item_token1,
      sym_bullet,
      aux_sym_block_begin_token1,
      anon_sym_PIPE,
      sym_table_separator,
      aux_sym_directive_token1,
      anon_sym_COLON,
      aux_sym_comment_token1,
      anon_sym_COLONPROPERTIES_COLON,
      sym_horizontal_rule,
      aux_sym_paragraph_token1,
  [302] = 2,
    ACTIONS(135), 1,
      ts_builtin_sym_end,
    ACTIONS(137), 21,
      sym_stars,
      sym_planning_line,
      sym_timestamp,
      anon_sym_LBRACE_LBRACE_LBRACE,
      sym_footnote_reference,
      sym_latex_fragment,
      sym_entity,
      sym_subscript,
      sym_superscript,
      anon_sym_LBRACK_LBRACK,
      aux_sym_list_item_token1,
      sym_bullet,
      aux_sym_block_begin_token1,
      anon_sym_PIPE,
      sym_table_separator,
      aux_sym_directive_token1,
      anon_sym_COLON,
      aux_sym_comment_token1,
      anon_sym_COLONPROPERTIES_COLON,
      sym_horizontal_rule,
      aux_sym_paragraph_token1,
  [329] = 2,
    ACTIONS(139), 1,
      ts_builtin_sym_end,
    ACTIONS(141), 21,
      sym_stars,
      sym_planning_line,
      sym_timestamp,
      anon_sym_LBRACE_LBRACE_LBRACE,
      sym_footnote_reference,
      sym_latex_fragment,
      sym_entity,
      sym_subscript,
      sym_superscript,
      anon_sym_LBRACK_LBRACK,
      aux_sym_list_item_token1,
      sym_bullet,
      aux_sym_block_begin_token1,
      anon_sym_PIPE,
      sym_table_separator,
      aux_sym_directive_token1,
      anon_sym_COLON,
      aux_sym_comment_token1,
      anon_sym_COLONPROPERTIES_COLON,
      sym_horizontal_rule,
      aux_sym_paragraph_token1,
  [356] = 2,
    ACTIONS(143), 1,
      ts_builtin_sym_end,
    ACTIONS(145), 21,
      sym_stars,
      sym_planning_line,
      sym_timestamp,
      anon_sym_LBRACE_LBRACE_LBRACE,
      sym_footnote_reference,
      sym_latex_fragment,
      sym_entity,
      sym_subscript,
      sym_superscript,
      anon_sym_LBRACK_LBRACK,
      aux_sym_list_item_token1,
      sym_bullet,
      aux_sym_block_begin_token1,
      anon_sym_PIPE,
      sym_table_separator,
      aux_sym_directive_token1,
      anon_sym_COLON,
      aux_sym_comment_token1,
      anon_sym_COLONPROPERTIES_COLON,
      sym_horizontal_rule,
      aux_sym_paragraph_token1,
  [383] = 2,
    ACTIONS(147), 1,
      ts_builtin_sym_end,
    ACTIONS(149), 21,
      sym_stars,
      sym_planning_line,
      sym_timestamp,
      anon_sym_LBRACE_LBRACE_LBRACE,
      sym_footnote_reference,
      sym_latex_fragment,
      sym_entity,
      sym_subscript,
      sym_superscript,
      anon_sym_LBRACK_LBRACK,
      aux_sym_list_item_token1,
      sym_bullet,
      aux_sym_block_begin_token1,
      anon_sym_PIPE,
      sym_table_separator,
      aux_sym_directive_token1,
      anon_sym_COLON,
      aux_sym_comment_token1,
      anon_sym_COLONPROPERTIES_COLON,
      sym_horizontal_rule,
      aux_sym_paragraph_token1,
  [410] = 2,
    ACTIONS(151), 1,
      ts_builtin_sym_end,
    ACTIONS(153), 21,
      sym_stars,
      sym_planning_line,
      sym_timestamp,
      anon_sym_LBRACE_LBRACE_LBRACE,
      sym_footnote_reference,
      sym_latex_fragment,
      sym_entity,
      sym_subscript,
      sym_superscript,
      anon_sym_LBRACK_LBRACK,
      aux_sym_list_item_token1,
      sym_bullet,
      aux_sym_block_begin_token1,
      anon_sym_PIPE,
      sym_table_separator,
      aux_sym_directive_token1,
      anon_sym_COLON,
      aux_sym_comment_token1,
      anon_sym_COLONPROPERTIES_COLON,
      sym_horizontal_rule,
      aux_sym_paragraph_token1,
  [437] = 2,
    ACTIONS(155), 1,
      ts_builtin_sym_end,
    ACTIONS(157), 21,
      sym_stars,
      sym_planning_line,
      sym_timestamp,
      anon_sym_LBRACE_LBRACE_LBRACE,
      sym_footnote_reference,
      sym_latex_fragment,
      sym_entity,
      sym_subscript,
      sym_superscript,
      anon_sym_LBRACK_LBRACK,
      aux_sym_list_item_token1,
      sym_bullet,
      aux_sym_block_begin_token1,
      anon_sym_PIPE,
      sym_table_separator,
      aux_sym_directive_token1,
      anon_sym_COLON,
      aux_sym_comment_token1,
      anon_sym_COLONPROPERTIES_COLON,
      sym_horizontal_rule,
      aux_sym_paragraph_token1,
  [464] = 2,
    ACTIONS(159), 1,
      ts_builtin_sym_end,
    ACTIONS(161), 21,
      sym_stars,
      sym_planning_line,
      sym_timestamp,
      anon_sym_LBRACE_LBRACE_LBRACE,
      sym_footnote_reference,
      sym_latex_fragment,
      sym_entity,
      sym_subscript,
      sym_superscript,
      anon_sym_LBRACK_LBRACK,
      aux_sym_list_item_token1,
      sym_bullet,
      aux_sym_block_begin_token1,
      anon_sym_PIPE,
      sym_table_separator,
      aux_sym_directive_token1,
      anon_sym_COLON,
      aux_sym_comment_token1,
      anon_sym_COLONPROPERTIES_COLON,
      sym_horizontal_rule,
      aux_sym_paragraph_token1,
  [491] = 2,
    ACTIONS(163), 1,
      ts_builtin_sym_end,
    ACTIONS(165), 21,
      sym_stars,
      sym_planning_line,
      sym_timestamp,
      anon_sym_LBRACE_LBRACE_LBRACE,
      sym_footnote_reference,
      sym_latex_fragment,
      sym_entity,
      sym_subscript,
      sym_superscript,
      anon_sym_LBRACK_LBRACK,
      aux_sym_list_item_token1,
      sym_bullet,
      aux_sym_block_begin_token1,
      anon_sym_PIPE,
      sym_table_separator,
      aux_sym_directive_token1,
      anon_sym_COLON,
      aux_sym_comment_token1,
      anon_sym_COLONPROPERTIES_COLON,
      sym_horizontal_rule,
      aux_sym_paragraph_token1,
  [518] = 2,
    ACTIONS(167), 1,
      ts_builtin_sym_end,
    ACTIONS(169), 21,
      sym_stars,
      sym_planning_line,
      sym_timestamp,
      anon_sym_LBRACE_LBRACE_LBRACE,
      sym_footnote_reference,
      sym_latex_fragment,
      sym_entity,
      sym_subscript,
      sym_superscript,
      anon_sym_LBRACK_LBRACK,
      aux_sym_list_item_token1,
      sym_bullet,
      aux_sym_block_begin_token1,
      anon_sym_PIPE,
      sym_table_separator,
      aux_sym_directive_token1,
      anon_sym_COLON,
      aux_sym_comment_token1,
      anon_sym_COLONPROPERTIES_COLON,
      sym_horizontal_rule,
      aux_sym_paragraph_token1,
  [545] = 2,
    ACTIONS(171), 1,
      ts_builtin_sym_end,
    ACTIONS(173), 21,
      sym_stars,
      sym_planning_line,
      sym_timestamp,
      anon_sym_LBRACE_LBRACE_LBRACE,
      sym_footnote_reference,
      sym_latex_fragment,
      sym_entity,
      sym_subscript,
      sym_superscript,
      anon_sym_LBRACK_LBRACK,
      aux_sym_list_item_token1,
      sym_bullet,
      aux_sym_block_begin_token1,
      anon_sym_PIPE,
      sym_table_separator,
      aux_sym_directive_token1,
      anon_sym_COLON,
      aux_sym_comment_token1,
      anon_sym_COLONPROPERTIES_COLON,
      sym_horizontal_rule,
      aux_sym_paragraph_token1,
  [572] = 2,
    ACTIONS(175), 1,
      ts_builtin_sym_end,
    ACTIONS(177), 21,
      sym_stars,
      sym_planning_line,
      sym_timestamp,
      anon_sym_LBRACE_LBRACE_LBRACE,
      sym_footnote_reference,
      sym_latex_fragment,
      sym_entity,
      sym_subscript,
      sym_superscript,
      anon_sym_LBRACK_LBRACK,
      aux_sym_list_item_token1,
      sym_bullet,
      aux_sym_block_begin_token1,
      anon_sym_PIPE,
      sym_table_separator,
      aux_sym_directive_token1,
      anon_sym_COLON,
      aux_sym_comment_token1,
      anon_sym_COLONPROPERTIES_COLON,
      sym_horizontal_rule,
      aux_sym_paragraph_token1,
  [599] = 2,
    ACTIONS(179), 1,
      ts_builtin_sym_end,
    ACTIONS(181), 21,
      sym_stars,
      sym_planning_line,
      sym_timestamp,
      anon_sym_LBRACE_LBRACE_LBRACE,
      sym_footnote_reference,
      sym_latex_fragment,
      sym_entity,
      sym_subscript,
      sym_superscript,
      anon_sym_LBRACK_LBRACK,
      aux_sym_list_item_token1,
      sym_bullet,
      aux_sym_block_begin_token1,
      anon_sym_PIPE,
      sym_table_separator,
      aux_sym_directive_token1,
      anon_sym_COLON,
      aux_sym_comment_token1,
      anon_sym_COLONPROPERTIES_COLON,
      sym_horizontal_rule,
      aux_sym_paragraph_token1,
  [626] = 2,
    ACTIONS(183), 1,
      ts_builtin_sym_end,
    ACTIONS(185), 21,
      sym_stars,
      sym_planning_line,
      sym_timestamp,
      anon_sym_LBRACE_LBRACE_LBRACE,
      sym_footnote_reference,
      sym_latex_fragment,
      sym_entity,
      sym_subscript,
      sym_superscript,
      anon_sym_LBRACK_LBRACK,
      aux_sym_list_item_token1,
      sym_bullet,
      aux_sym_block_begin_token1,
      anon_sym_PIPE,
      sym_table_separator,
      aux_sym_directive_token1,
      anon_sym_COLON,
      aux_sym_comment_token1,
      anon_sym_COLONPROPERTIES_COLON,
      sym_horizontal_rule,
      aux_sym_paragraph_token1,
  [653] = 2,
    ACTIONS(187), 1,
      ts_builtin_sym_end,
    ACTIONS(189), 21,
      sym_stars,
      sym_planning_line,
      sym_timestamp,
      anon_sym_LBRACE_LBRACE_LBRACE,
      sym_footnote_reference,
      sym_latex_fragment,
      sym_entity,
      sym_subscript,
      sym_superscript,
      anon_sym_LBRACK_LBRACK,
      aux_sym_list_item_token1,
      sym_bullet,
      aux_sym_block_begin_token1,
      anon_sym_PIPE,
      sym_table_separator,
      aux_sym_directive_token1,
      anon_sym_COLON,
      aux_sym_comment_token1,
      anon_sym_COLONPROPERTIES_COLON,
      sym_horizontal_rule,
      aux_sym_paragraph_token1,
  [680] = 2,
    ACTIONS(191), 1,
      ts_builtin_sym_end,
    ACTIONS(193), 21,
      sym_stars,
      sym_planning_line,
      sym_timestamp,
      anon_sym_LBRACE_LBRACE_LBRACE,
      sym_footnote_reference,
      sym_latex_fragment,
      sym_entity,
      sym_subscript,
      sym_superscript,
      anon_sym_LBRACK_LBRACK,
      aux_sym_list_item_token1,
      sym_bullet,
      aux_sym_block_begin_token1,
      anon_sym_PIPE,
      sym_table_separator,
      aux_sym_directive_token1,
      anon_sym_COLON,
      aux_sym_comment_token1,
      anon_sym_COLONPROPERTIES_COLON,
      sym_horizontal_rule,
      aux_sym_paragraph_token1,
  [707] = 2,
    ACTIONS(195), 1,
      ts_builtin_sym_end,
    ACTIONS(197), 21,
      sym_stars,
      sym_planning_line,
      sym_timestamp,
      anon_sym_LBRACE_LBRACE_LBRACE,
      sym_footnote_reference,
      sym_latex_fragment,
      sym_entity,
      sym_subscript,
      sym_superscript,
      anon_sym_LBRACK_LBRACK,
      aux_sym_list_item_token1,
      sym_bullet,
      aux_sym_block_begin_token1,
      anon_sym_PIPE,
      sym_table_separator,
      aux_sym_directive_token1,
      anon_sym_COLON,
      aux_sym_comment_token1,
      anon_sym_COLONPROPERTIES_COLON,
      sym_horizontal_rule,
      aux_sym_paragraph_token1,
  [734] = 2,
    ACTIONS(199), 1,
      ts_builtin_sym_end,
    ACTIONS(201), 21,
      sym_stars,
      sym_planning_line,
      sym_timestamp,
      anon_sym_LBRACE_LBRACE_LBRACE,
      sym_footnote_reference,
      sym_latex_fragment,
      sym_entity,
      sym_subscript,
      sym_superscript,
      anon_sym_LBRACK_LBRACK,
      aux_sym_list_item_token1,
      sym_bullet,
      aux_sym_block_begin_token1,
      anon_sym_PIPE,
      sym_table_separator,
      aux_sym_directive_token1,
      anon_sym_COLON,
      aux_sym_comment_token1,
      anon_sym_COLONPROPERTIES_COLON,
      sym_horizontal_rule,
      aux_sym_paragraph_token1,
  [761] = 2,
    ACTIONS(203), 1,
      ts_builtin_sym_end,
    ACTIONS(205), 21,
      sym_stars,
      sym_planning_line,
      sym_timestamp,
      anon_sym_LBRACE_LBRACE_LBRACE,
      sym_footnote_reference,
      sym_latex_fragment,
      sym_entity,
      sym_subscript,
      sym_superscript,
      anon_sym_LBRACK_LBRACK,
      aux_sym_list_item_token1,
      sym_bullet,
      aux_sym_block_begin_token1,
      anon_sym_PIPE,
      sym_table_separator,
      aux_sym_directive_token1,
      anon_sym_COLON,
      aux_sym_comment_token1,
      anon_sym_COLONPROPERTIES_COLON,
      sym_horizontal_rule,
      aux_sym_paragraph_token1,
  [788] = 2,
    ACTIONS(207), 1,
      ts_builtin_sym_end,
    ACTIONS(209), 21,
      sym_stars,
      sym_planning_line,
      sym_timestamp,
      anon_sym_LBRACE_LBRACE_LBRACE,
      sym_footnote_reference,
      sym_latex_fragment,
      sym_entity,
      sym_subscript,
      sym_superscript,
      anon_sym_LBRACK_LBRACK,
      aux_sym_list_item_token1,
      sym_bullet,
      aux_sym_block_begin_token1,
      anon_sym_PIPE,
      sym_table_separator,
      aux_sym_directive_token1,
      anon_sym_COLON,
      aux_sym_comment_token1,
      anon_sym_COLONPROPERTIES_COLON,
      sym_horizontal_rule,
      aux_sym_paragraph_token1,
  [815] = 2,
    ACTIONS(211), 1,
      ts_builtin_sym_end,
    ACTIONS(213), 21,
      sym_stars,
      sym_planning_line,
      sym_timestamp,
      anon_sym_LBRACE_LBRACE_LBRACE,
      sym_footnote_reference,
      sym_latex_fragment,
      sym_entity,
      sym_subscript,
      sym_superscript,
      anon_sym_LBRACK_LBRACK,
      aux_sym_list_item_token1,
      sym_bullet,
      aux_sym_block_begin_token1,
      anon_sym_PIPE,
      sym_table_separator,
      aux_sym_directive_token1,
      anon_sym_COLON,
      aux_sym_comment_token1,
      anon_sym_COLONPROPERTIES_COLON,
      sym_horizontal_rule,
      aux_sym_paragraph_token1,
  [842] = 2,
    ACTIONS(215), 1,
      ts_builtin_sym_end,
    ACTIONS(217), 21,
      sym_stars,
      sym_planning_line,
      sym_timestamp,
      anon_sym_LBRACE_LBRACE_LBRACE,
      sym_footnote_reference,
      sym_latex_fragment,
      sym_entity,
      sym_subscript,
      sym_superscript,
      anon_sym_LBRACK_LBRACK,
      aux_sym_list_item_token1,
      sym_bullet,
      aux_sym_block_begin_token1,
      anon_sym_PIPE,
      sym_table_separator,
      aux_sym_directive_token1,
      anon_sym_COLON,
      aux_sym_comment_token1,
      anon_sym_COLONPROPERTIES_COLON,
      sym_horizontal_rule,
      aux_sym_paragraph_token1,
  [869] = 5,
    ACTIONS(219), 1,
      anon_sym_LF,
    ACTIONS(221), 1,
      sym_keyword,
    ACTIONS(223), 1,
      sym_priority,
    ACTIONS(225), 1,
      aux_sym_title_token1,
    STATE(83), 1,
      sym_title,
  [885] = 4,
    ACTIONS(227), 1,
      anon_sym_LF,
    ACTIONS(229), 1,
      anon_sym_PIPE,
    ACTIONS(231), 1,
      sym_table_cell,
    STATE(38), 1,
      aux_sym_table_row_repeat1,
  [898] = 3,
    ACTIONS(233), 1,
      anon_sym_COLON,
    ACTIONS(236), 1,
      anon_sym_COLONEND_COLON,
    STATE(37), 2,
      sym_property,
      aux_sym_property_drawer_repeat1,
  [909] = 4,
    ACTIONS(238), 1,
      anon_sym_LF,
    ACTIONS(240), 1,
      anon_sym_PIPE,
    ACTIONS(243), 1,
      sym_table_cell,
    STATE(38), 1,
      aux_sym_table_row_repeat1,
  [922] = 4,
    ACTIONS(225), 1,
      aux_sym_title_token1,
    ACTIONS(246), 1,
      anon_sym_LF,
    ACTIONS(248), 1,
      sym_priority,
    STATE(82), 1,
      sym_title,
  [935] = 3,
    ACTIONS(250), 1,
      anon_sym_COLON,
    ACTIONS(252), 1,
      anon_sym_COLONEND_COLON,
    STATE(37), 2,
      sym_property,
      aux_sym_property_drawer_repeat1,
  [946] = 4,
    ACTIONS(231), 1,
      sym_table_cell,
    ACTIONS(254), 1,
      anon_sym_LF,
    ACTIONS(256), 1,
      anon_sym_PIPE,
    STATE(36), 1,
      aux_sym_table_row_repeat1,
  [959] = 1,
    ACTIONS(238), 3,
      anon_sym_LF,
      anon_sym_PIPE,
      sym_table_cell,
  [965] = 3,
    ACTIONS(225), 1,
      aux_sym_title_token1,
    ACTIONS(258), 1,
      anon_sym_LF,
    STATE(84), 1,
      sym_title,
  [975] = 3,
    ACTIONS(225), 1,
      aux_sym_title_token1,
    ACTIONS(260), 1,
      anon_sym_LF,
    STATE(110), 1,
      sym_title,
  [985] = 3,
    ACTIONS(262), 1,
      sym_block_content,
    ACTIONS(264), 1,
      aux_sym_block_end_token1,
    STATE(34), 1,
      sym_block_end,
  [995] = 2,
    ACTIONS(266), 1,
      anon_sym_COLON,
    STATE(40), 2,
      sym_property,
      aux_sym_property_drawer_repeat1,
  [1003] = 2,
    ACTIONS(268), 1,
      aux_sym_block_end_token1,
    STATE(13), 1,
      sym_block_end,
  [1010] = 2,
    ACTIONS(270), 1,
      anon_sym_LF,
    ACTIONS(272), 1,
      aux_sym_list_item_token2,
  [1017] = 2,
    ACTIONS(274), 1,
      sym_block_content,
    ACTIONS(276), 1,
      aux_sym_block_end_token1,
  [1024] = 2,
    ACTIONS(278), 1,
      aux_sym_key_token1,
    STATE(94), 1,
      sym_key,
  [1031] = 2,
    ACTIONS(280), 1,
      aux_sym_title_token1,
    STATE(120), 1,
      sym_value,
  [1038] = 2,
    ACTIONS(282), 1,
      sym_block_content,
    ACTIONS(284), 1,
      aux_sym_block_end_token1,
  [1045] = 2,
    ACTIONS(286), 1,
      aux_sym_list_item_token2,
    ACTIONS(288), 1,
      sym_block_type,
  [1052] = 2,
    ACTIONS(290), 1,
      anon_sym_COLONend_COLON,
    ACTIONS(292), 1,
      sym_drawer_content,
  [1059] = 2,
    ACTIONS(294), 1,
      anon_sym_COLON,
    ACTIONS(296), 1,
      anon_sym_COLONEND_COLON,
  [1066] = 2,
    ACTIONS(298), 1,
      aux_sym_title_token1,
    ACTIONS(300), 1,
      aux_sym_list_item_token1,
  [1073] = 2,
    ACTIONS(302), 1,
      anon_sym_SPACE,
    ACTIONS(304), 1,
      anon_sym_LF,
  [1080] = 2,
    ACTIONS(306), 1,
      anon_sym_RBRACK_LBRACK,
    ACTIONS(308), 1,
      anon_sym_RBRACK_RBRACK,
  [1087] = 2,
    ACTIONS(310), 1,
      anon_sym_LPAREN,
    ACTIONS(312), 1,
      anon_sym_RBRACE_RBRACE_RBRACE,
  [1094] = 2,
    ACTIONS(314), 1,
      sym_block_content,
    ACTIONS(316), 1,
      aux_sym_block_end_token1,
  [1101] = 2,
    ACTIONS(318), 1,
      aux_sym_key_token1,
    STATE(62), 1,
      sym_drawer_name,
  [1108] = 1,
    ACTIONS(320), 1,
      anon_sym_COLON,
  [1112] = 1,
    ACTIONS(322), 1,
      aux_sym_list_item_token2,
  [1116] = 1,
    ACTIONS(324), 1,
      anon_sym_SPACE,
  [1120] = 1,
    ACTIONS(326), 1,
      anon_sym_LF,
  [1124] = 1,
    ACTIONS(328), 1,
      anon_sym_RPAREN,
  [1128] = 1,
    ACTIONS(330), 1,
      aux_sym_property_drawer_token1,
  [1132] = 1,
    ACTIONS(332), 1,
      anon_sym_RBRACK_RBRACK,
  [1136] = 1,
    ACTIONS(334), 1,
      sym_language,
  [1140] = 1,
    ACTIONS(336), 1,
      anon_sym_LF,
  [1144] = 1,
    ACTIONS(338), 1,
      anon_sym_LF,
  [1148] = 1,
    ACTIONS(340), 1,
      aux_sym_list_item_token2,
  [1152] = 1,
    ACTIONS(342), 1,
      anon_sym_LF,
  [1156] = 1,
    ACTIONS(344), 1,
      aux_sym_title_token1,
  [1160] = 1,
    ACTIONS(346), 1,
      anon_sym_LF,
  [1164] = 1,
    ACTIONS(348), 1,
      anon_sym_LF,
  [1168] = 1,
    ACTIONS(350), 1,
      aux_sym_link_token1,
  [1172] = 1,
    ACTIONS(352), 1,
      anon_sym_LF,
  [1176] = 1,
    ACTIONS(354), 1,
      anon_sym_LF,
  [1180] = 1,
    ACTIONS(356), 1,
      aux_sym_macro_token2,
  [1184] = 1,
    ACTIONS(358), 1,
      anon_sym_SPACE,
  [1188] = 1,
    ACTIONS(360), 1,
      anon_sym_LF,
  [1192] = 1,
    ACTIONS(362), 1,
      anon_sym_LF,
  [1196] = 1,
    ACTIONS(364), 1,
      anon_sym_LF,
  [1200] = 1,
    ACTIONS(366), 1,
      anon_sym_RBRACE_RBRACE_RBRACE,
  [1204] = 1,
    ACTIONS(368), 1,
      anon_sym_LF,
  [1208] = 1,
    ACTIONS(370), 1,
      anon_sym_LF,
  [1212] = 1,
    ACTIONS(372), 1,
      anon_sym_SPACE,
  [1216] = 1,
    ACTIONS(374), 1,
      anon_sym_LF,
  [1220] = 1,
    ACTIONS(376), 1,
      anon_sym_SPACE,
  [1224] = 1,
    ACTIONS(378), 1,
      anon_sym_LF,
  [1228] = 1,
    ACTIONS(380), 1,
      anon_sym_LF,
  [1232] = 1,
    ACTIONS(382), 1,
      anon_sym_COLON,
  [1236] = 1,
    ACTIONS(384), 1,
      anon_sym_COLON,
  [1240] = 1,
    ACTIONS(386), 1,
      aux_sym_property_drawer_token1,
  [1244] = 1,
    ACTIONS(388), 1,
      anon_sym_LF,
  [1248] = 1,
    ACTIONS(390), 1,
      anon_sym_COLON,
  [1252] = 1,
    ACTIONS(392), 1,
      anon_sym_COLON,
  [1256] = 1,
    ACTIONS(394), 1,
      anon_sym_PIPE,
  [1260] = 1,
    ACTIONS(396), 1,
      aux_sym_list_item_token2,
  [1264] = 1,
    ACTIONS(398), 1,
      anon_sym_LF,
  [1268] = 1,
    ACTIONS(400), 1,
      anon_sym_SPACE,
  [1272] = 1,
    ACTIONS(402), 1,
      ts_builtin_sym_end,
  [1276] = 1,
    ACTIONS(404), 1,
      aux_sym_paragraph_token2,
  [1280] = 1,
    ACTIONS(406), 1,
      aux_sym_property_drawer_token1,
  [1284] = 1,
    ACTIONS(408), 1,
      anon_sym_COLONend_COLON,
  [1288] = 1,
    ACTIONS(410), 1,
      aux_sym_property_drawer_token1,
  [1292] = 1,
    ACTIONS(412), 1,
      anon_sym_LF,
  [1296] = 1,
    ACTIONS(414), 1,
      aux_sym_property_drawer_token1,
  [1300] = 1,
    ACTIONS(416), 1,
      anon_sym_LF,
  [1304] = 1,
    ACTIONS(418), 1,
      aux_sym_list_item_token2,
  [1308] = 1,
    ACTIONS(420), 1,
      anon_sym_LF,
  [1312] = 1,
    ACTIONS(422), 1,
      aux_sym_property_drawer_token1,
  [1316] = 1,
    ACTIONS(424), 1,
      sym_name,
  [1320] = 1,
    ACTIONS(426), 1,
      sym_block_type,
  [1324] = 1,
    ACTIONS(428), 1,
      anon_sym_SPACE,
  [1328] = 1,
    ACTIONS(430), 1,
      sym_bullet,
  [1332] = 1,
    ACTIONS(432), 1,
      anon_sym_LF,
  [1336] = 1,
    ACTIONS(434), 1,
      anon_sym_LF,
  [1340] = 1,
    ACTIONS(436), 1,
      anon_sym_LF,
  [1344] = 1,
    ACTIONS(438), 1,
      aux_sym_link_token1,
  [1348] = 1,
    ACTIONS(440), 1,
      aux_sym_macro_token1,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(4)] = 0,
  [SMALL_STATE(5)] = 35,
  [SMALL_STATE(6)] = 70,
  [SMALL_STATE(7)] = 105,
  [SMALL_STATE(8)] = 140,
  [SMALL_STATE(9)] = 167,
  [SMALL_STATE(10)] = 194,
  [SMALL_STATE(11)] = 221,
  [SMALL_STATE(12)] = 248,
  [SMALL_STATE(13)] = 275,
  [SMALL_STATE(14)] = 302,
  [SMALL_STATE(15)] = 329,
  [SMALL_STATE(16)] = 356,
  [SMALL_STATE(17)] = 383,
  [SMALL_STATE(18)] = 410,
  [SMALL_STATE(19)] = 437,
  [SMALL_STATE(20)] = 464,
  [SMALL_STATE(21)] = 491,
  [SMALL_STATE(22)] = 518,
  [SMALL_STATE(23)] = 545,
  [SMALL_STATE(24)] = 572,
  [SMALL_STATE(25)] = 599,
  [SMALL_STATE(26)] = 626,
  [SMALL_STATE(27)] = 653,
  [SMALL_STATE(28)] = 680,
  [SMALL_STATE(29)] = 707,
  [SMALL_STATE(30)] = 734,
  [SMALL_STATE(31)] = 761,
  [SMALL_STATE(32)] = 788,
  [SMALL_STATE(33)] = 815,
  [SMALL_STATE(34)] = 842,
  [SMALL_STATE(35)] = 869,
  [SMALL_STATE(36)] = 885,
  [SMALL_STATE(37)] = 898,
  [SMALL_STATE(38)] = 909,
  [SMALL_STATE(39)] = 922,
  [SMALL_STATE(40)] = 935,
  [SMALL_STATE(41)] = 946,
  [SMALL_STATE(42)] = 959,
  [SMALL_STATE(43)] = 965,
  [SMALL_STATE(44)] = 975,
  [SMALL_STATE(45)] = 985,
  [SMALL_STATE(46)] = 995,
  [SMALL_STATE(47)] = 1003,
  [SMALL_STATE(48)] = 1010,
  [SMALL_STATE(49)] = 1017,
  [SMALL_STATE(50)] = 1024,
  [SMALL_STATE(51)] = 1031,
  [SMALL_STATE(52)] = 1038,
  [SMALL_STATE(53)] = 1045,
  [SMALL_STATE(54)] = 1052,
  [SMALL_STATE(55)] = 1059,
  [SMALL_STATE(56)] = 1066,
  [SMALL_STATE(57)] = 1073,
  [SMALL_STATE(58)] = 1080,
  [SMALL_STATE(59)] = 1087,
  [SMALL_STATE(60)] = 1094,
  [SMALL_STATE(61)] = 1101,
  [SMALL_STATE(62)] = 1108,
  [SMALL_STATE(63)] = 1112,
  [SMALL_STATE(64)] = 1116,
  [SMALL_STATE(65)] = 1120,
  [SMALL_STATE(66)] = 1124,
  [SMALL_STATE(67)] = 1128,
  [SMALL_STATE(68)] = 1132,
  [SMALL_STATE(69)] = 1136,
  [SMALL_STATE(70)] = 1140,
  [SMALL_STATE(71)] = 1144,
  [SMALL_STATE(72)] = 1148,
  [SMALL_STATE(73)] = 1152,
  [SMALL_STATE(74)] = 1156,
  [SMALL_STATE(75)] = 1160,
  [SMALL_STATE(76)] = 1164,
  [SMALL_STATE(77)] = 1168,
  [SMALL_STATE(78)] = 1172,
  [SMALL_STATE(79)] = 1176,
  [SMALL_STATE(80)] = 1180,
  [SMALL_STATE(81)] = 1184,
  [SMALL_STATE(82)] = 1188,
  [SMALL_STATE(83)] = 1192,
  [SMALL_STATE(84)] = 1196,
  [SMALL_STATE(85)] = 1200,
  [SMALL_STATE(86)] = 1204,
  [SMALL_STATE(87)] = 1208,
  [SMALL_STATE(88)] = 1212,
  [SMALL_STATE(89)] = 1216,
  [SMALL_STATE(90)] = 1220,
  [SMALL_STATE(91)] = 1224,
  [SMALL_STATE(92)] = 1228,
  [SMALL_STATE(93)] = 1232,
  [SMALL_STATE(94)] = 1236,
  [SMALL_STATE(95)] = 1240,
  [SMALL_STATE(96)] = 1244,
  [SMALL_STATE(97)] = 1248,
  [SMALL_STATE(98)] = 1252,
  [SMALL_STATE(99)] = 1256,
  [SMALL_STATE(100)] = 1260,
  [SMALL_STATE(101)] = 1264,
  [SMALL_STATE(102)] = 1268,
  [SMALL_STATE(103)] = 1272,
  [SMALL_STATE(104)] = 1276,
  [SMALL_STATE(105)] = 1280,
  [SMALL_STATE(106)] = 1284,
  [SMALL_STATE(107)] = 1288,
  [SMALL_STATE(108)] = 1292,
  [SMALL_STATE(109)] = 1296,
  [SMALL_STATE(110)] = 1300,
  [SMALL_STATE(111)] = 1304,
  [SMALL_STATE(112)] = 1308,
  [SMALL_STATE(113)] = 1312,
  [SMALL_STATE(114)] = 1316,
  [SMALL_STATE(115)] = 1320,
  [SMALL_STATE(116)] = 1324,
  [SMALL_STATE(117)] = 1328,
  [SMALL_STATE(118)] = 1332,
  [SMALL_STATE(119)] = 1336,
  [SMALL_STATE(120)] = 1340,
  [SMALL_STATE(121)] = 1344,
  [SMALL_STATE(122)] = 1348,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_document, 0, 0, 0),
  [5] = {.entry = {.count = 1, .reusable = false}}, SHIFT(64),
  [7] = {.entry = {.count = 1, .reusable = false}}, SHIFT(3),
  [9] = {.entry = {.count = 1, .reusable = false}}, SHIFT(122),
  [11] = {.entry = {.count = 1, .reusable = false}}, SHIFT(121),
  [13] = {.entry = {.count = 1, .reusable = false}}, SHIFT(117),
  [15] = {.entry = {.count = 1, .reusable = false}}, SHIFT(116),
  [17] = {.entry = {.count = 1, .reusable = false}}, SHIFT(115),
  [19] = {.entry = {.count = 1, .reusable = false}}, SHIFT(41),
  [21] = {.entry = {.count = 1, .reusable = false}}, SHIFT(7),
  [23] = {.entry = {.count = 1, .reusable = false}}, SHIFT(114),
  [25] = {.entry = {.count = 1, .reusable = false}}, SHIFT(61),
  [27] = {.entry = {.count = 1, .reusable = false}}, SHIFT(111),
  [29] = {.entry = {.count = 1, .reusable = false}}, SHIFT(109),
  [31] = {.entry = {.count = 1, .reusable = false}}, SHIFT(104),
  [33] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0),
  [35] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(64),
  [38] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(2),
  [41] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(122),
  [44] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(121),
  [47] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(117),
  [50] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(116),
  [53] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(115),
  [56] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(41),
  [59] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(7),
  [62] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(114),
  [65] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(61),
  [68] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(111),
  [71] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(109),
  [74] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(104),
  [77] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_document, 1, 0, 0),
  [79] = {.entry = {.count = 1, .reusable = false}}, SHIFT(2),
  [81] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_list, 1, 0, 0),
  [83] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_list, 1, 0, 0),
  [85] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_table_repeat1, 2, 0, 0),
  [87] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_table_repeat1, 2, 0, 0),
  [89] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_table_repeat1, 2, 0, 0), SHIFT_REPEAT(41),
  [92] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_table_repeat1, 2, 0, 0), SHIFT_REPEAT(5),
  [95] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_list_repeat1, 2, 0, 0),
  [97] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_list_repeat1, 2, 0, 0),
  [99] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_list_repeat1, 2, 0, 0), SHIFT_REPEAT(117),
  [102] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_list_repeat1, 2, 0, 0), SHIFT_REPEAT(116),
  [105] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_table, 1, 0, 0),
  [107] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_table, 1, 0, 0),
  [109] = {.entry = {.count = 1, .reusable = false}}, SHIFT(5),
  [111] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_block_end, 3, 0, 0),
  [113] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_block_end, 3, 0, 0),
  [115] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_headline, 4, 0, 2),
  [117] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_headline, 4, 0, 2),
  [119] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_list_item, 4, 0, 0),
  [121] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_list_item, 4, 0, 0),
  [123] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_headline, 5, 0, 3),
  [125] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_headline, 5, 0, 3),
  [127] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_macro, 7, 0, 0),
  [129] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_macro, 7, 0, 0),
  [131] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_block, 3, 0, 0),
  [133] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_block, 3, 0, 0),
  [135] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_headline, 7, 0, 11),
  [137] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_headline, 7, 0, 11),
  [139] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_directive, 6, 0, 10),
  [141] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_directive, 6, 0, 10),
  [143] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_headline, 5, 0, 4),
  [145] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_headline, 5, 0, 4),
  [147] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_link, 6, 0, 9),
  [149] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_link, 6, 0, 9),
  [151] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_list_item, 5, 0, 0),
  [153] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_list_item, 5, 0, 0),
  [155] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_headline, 8, 0, 12),
  [157] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_headline, 8, 0, 12),
  [159] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_comment, 3, 0, 0),
  [161] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_comment, 3, 0, 0),
  [163] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_drawer, 8, 0, 0),
  [165] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_drawer, 8, 0, 0),
  [167] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_headline, 6, 0, 8),
  [169] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_headline, 6, 0, 8),
  [171] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_headline, 6, 0, 7),
  [173] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_headline, 6, 0, 7),
  [175] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_headline, 3, 0, 0),
  [177] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_headline, 3, 0, 0),
  [179] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_table_row, 2, 0, 0),
  [181] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_table_row, 2, 0, 0),
  [183] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_drawer, 9, 0, 0),
  [185] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_drawer, 9, 0, 0),
  [187] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_link, 4, 0, 0),
  [189] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_link, 4, 0, 0),
  [191] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_block_end, 4, 0, 0),
  [193] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_block_end, 4, 0, 0),
  [195] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_table_row, 3, 0, 0),
  [197] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_table_row, 3, 0, 0),
  [199] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_directive, 5, 0, 6),
  [201] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_directive, 5, 0, 6),
  [203] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_paragraph, 2, 0, 0),
  [205] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_paragraph, 2, 0, 0),
  [207] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_property_drawer, 7, 0, 0),
  [209] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_property_drawer, 7, 0, 0),
  [211] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_macro, 4, 0, 0),
  [213] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_macro, 4, 0, 0),
  [215] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_block, 2, 0, 0),
  [217] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_block, 2, 0, 0),
  [219] = {.entry = {.count = 1, .reusable = false}}, SHIFT(24),
  [221] = {.entry = {.count = 1, .reusable = false}}, SHIFT(90),
  [223] = {.entry = {.count = 1, .reusable = false}}, SHIFT(88),
  [225] = {.entry = {.count = 1, .reusable = false}}, SHIFT(87),
  [227] = {.entry = {.count = 1, .reusable = false}}, SHIFT(29),
  [229] = {.entry = {.count = 1, .reusable = false}}, SHIFT(38),
  [231] = {.entry = {.count = 1, .reusable = false}}, SHIFT(99),
  [233] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_property_drawer_repeat1, 2, 0, 0), SHIFT_REPEAT(50),
  [236] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_property_drawer_repeat1, 2, 0, 0),
  [238] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_table_row_repeat1, 2, 0, 0),
  [240] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_table_row_repeat1, 2, 0, 0), SHIFT_REPEAT(38),
  [243] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_table_row_repeat1, 2, 0, 0), SHIFT_REPEAT(99),
  [246] = {.entry = {.count = 1, .reusable = false}}, SHIFT(11),
  [248] = {.entry = {.count = 1, .reusable = false}}, SHIFT(81),
  [250] = {.entry = {.count = 1, .reusable = false}}, SHIFT(50),
  [252] = {.entry = {.count = 1, .reusable = true}}, SHIFT(95),
  [254] = {.entry = {.count = 1, .reusable = false}}, SHIFT(25),
  [256] = {.entry = {.count = 1, .reusable = false}}, SHIFT(36),
  [258] = {.entry = {.count = 1, .reusable = false}}, SHIFT(16),
  [260] = {.entry = {.count = 1, .reusable = false}}, SHIFT(14),
  [262] = {.entry = {.count = 1, .reusable = true}}, SHIFT(47),
  [264] = {.entry = {.count = 1, .reusable = false}}, SHIFT(53),
  [266] = {.entry = {.count = 1, .reusable = true}}, SHIFT(50),
  [268] = {.entry = {.count = 1, .reusable = true}}, SHIFT(53),
  [270] = {.entry = {.count = 1, .reusable = false}}, SHIFT(49),
  [272] = {.entry = {.count = 1, .reusable = false}}, SHIFT(89),
  [274] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_block_begin, 5, 0, 5),
  [276] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_block_begin, 5, 0, 5),
  [278] = {.entry = {.count = 1, .reusable = true}}, SHIFT(93),
  [280] = {.entry = {.count = 1, .reusable = true}}, SHIFT(119),
  [282] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_block_begin, 3, 0, 1),
  [284] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_block_begin, 3, 0, 1),
  [286] = {.entry = {.count = 1, .reusable = true}}, SHIFT(65),
  [288] = {.entry = {.count = 1, .reusable = false}}, SHIFT(63),
  [290] = {.entry = {.count = 1, .reusable = false}}, SHIFT(105),
  [292] = {.entry = {.count = 1, .reusable = true}}, SHIFT(106),
  [294] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_property, 6, 0, 0),
  [296] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_property, 6, 0, 0),
  [298] = {.entry = {.count = 1, .reusable = false}}, SHIFT(73),
  [300] = {.entry = {.count = 1, .reusable = false}}, SHIFT(74),
  [302] = {.entry = {.count = 1, .reusable = false}}, SHIFT(69),
  [304] = {.entry = {.count = 1, .reusable = false}}, SHIFT(52),
  [306] = {.entry = {.count = 1, .reusable = true}}, SHIFT(77),
  [308] = {.entry = {.count = 1, .reusable = true}}, SHIFT(76),
  [310] = {.entry = {.count = 1, .reusable = true}}, SHIFT(80),
  [312] = {.entry = {.count = 1, .reusable = true}}, SHIFT(78),
  [314] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_block_begin, 6, 0, 5),
  [316] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_block_begin, 6, 0, 5),
  [318] = {.entry = {.count = 1, .reusable = true}}, SHIFT(97),
  [320] = {.entry = {.count = 1, .reusable = true}}, SHIFT(67),
  [322] = {.entry = {.count = 1, .reusable = true}}, SHIFT(79),
  [324] = {.entry = {.count = 1, .reusable = true}}, SHIFT(35),
  [326] = {.entry = {.count = 1, .reusable = true}}, SHIFT(8),
  [328] = {.entry = {.count = 1, .reusable = true}}, SHIFT(85),
  [330] = {.entry = {.count = 1, .reusable = true}}, SHIFT(75),
  [332] = {.entry = {.count = 1, .reusable = true}}, SHIFT(86),
  [334] = {.entry = {.count = 1, .reusable = true}}, SHIFT(48),
  [336] = {.entry = {.count = 1, .reusable = true}}, SHIFT(18),
  [338] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
  [340] = {.entry = {.count = 1, .reusable = true}}, SHIFT(70),
  [342] = {.entry = {.count = 1, .reusable = true}}, SHIFT(30),
  [344] = {.entry = {.count = 1, .reusable = true}}, SHIFT(91),
  [346] = {.entry = {.count = 1, .reusable = true}}, SHIFT(54),
  [348] = {.entry = {.count = 1, .reusable = true}}, SHIFT(27),
  [350] = {.entry = {.count = 1, .reusable = true}}, SHIFT(68),
  [352] = {.entry = {.count = 1, .reusable = true}}, SHIFT(33),
  [354] = {.entry = {.count = 1, .reusable = true}}, SHIFT(28),
  [356] = {.entry = {.count = 1, .reusable = true}}, SHIFT(66),
  [358] = {.entry = {.count = 1, .reusable = true}}, SHIFT(44),
  [360] = {.entry = {.count = 1, .reusable = true}}, SHIFT(23),
  [362] = {.entry = {.count = 1, .reusable = true}}, SHIFT(9),
  [364] = {.entry = {.count = 1, .reusable = true}}, SHIFT(22),
  [366] = {.entry = {.count = 1, .reusable = true}}, SHIFT(101),
  [368] = {.entry = {.count = 1, .reusable = true}}, SHIFT(17),
  [370] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_title, 1, 0, 0),
  [372] = {.entry = {.count = 1, .reusable = true}}, SHIFT(43),
  [374] = {.entry = {.count = 1, .reusable = true}}, SHIFT(60),
  [376] = {.entry = {.count = 1, .reusable = true}}, SHIFT(39),
  [378] = {.entry = {.count = 1, .reusable = true}}, SHIFT(15),
  [380] = {.entry = {.count = 1, .reusable = true}}, SHIFT(46),
  [382] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_key, 1, 0, 0),
  [384] = {.entry = {.count = 1, .reusable = true}}, SHIFT(107),
  [386] = {.entry = {.count = 1, .reusable = true}}, SHIFT(108),
  [388] = {.entry = {.count = 1, .reusable = true}}, SHIFT(20),
  [390] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_drawer_name, 1, 0, 0),
  [392] = {.entry = {.count = 1, .reusable = true}}, SHIFT(56),
  [394] = {.entry = {.count = 1, .reusable = true}}, SHIFT(42),
  [396] = {.entry = {.count = 1, .reusable = true}}, SHIFT(71),
  [398] = {.entry = {.count = 1, .reusable = true}}, SHIFT(12),
  [400] = {.entry = {.count = 1, .reusable = true}}, SHIFT(72),
  [402] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [404] = {.entry = {.count = 1, .reusable = true}}, SHIFT(31),
  [406] = {.entry = {.count = 1, .reusable = true}}, SHIFT(112),
  [408] = {.entry = {.count = 1, .reusable = true}}, SHIFT(113),
  [410] = {.entry = {.count = 1, .reusable = true}}, SHIFT(51),
  [412] = {.entry = {.count = 1, .reusable = true}}, SHIFT(32),
  [414] = {.entry = {.count = 1, .reusable = true}}, SHIFT(92),
  [416] = {.entry = {.count = 1, .reusable = true}}, SHIFT(19),
  [418] = {.entry = {.count = 1, .reusable = true}}, SHIFT(96),
  [420] = {.entry = {.count = 1, .reusable = true}}, SHIFT(21),
  [422] = {.entry = {.count = 1, .reusable = true}}, SHIFT(118),
  [424] = {.entry = {.count = 1, .reusable = true}}, SHIFT(98),
  [426] = {.entry = {.count = 1, .reusable = true}}, SHIFT(57),
  [428] = {.entry = {.count = 1, .reusable = true}}, SHIFT(100),
  [430] = {.entry = {.count = 1, .reusable = true}}, SHIFT(102),
  [432] = {.entry = {.count = 1, .reusable = true}}, SHIFT(26),
  [434] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_value, 1, 0, 0),
  [436] = {.entry = {.count = 1, .reusable = true}}, SHIFT(55),
  [438] = {.entry = {.count = 1, .reusable = true}}, SHIFT(58),
  [440] = {.entry = {.count = 1, .reusable = true}}, SHIFT(59),
};

#ifdef __cplusplus
extern "C" {
#endif
#ifdef TREE_SITTER_HIDE_SYMBOLS
#define TS_PUBLIC
#elif defined(_WIN32)
#define TS_PUBLIC __declspec(dllexport)
#else
#define TS_PUBLIC __attribute__((visibility("default")))
#endif

TS_PUBLIC const TSLanguage *tree_sitter_org(void) {
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
    .primary_state_ids = ts_primary_state_ids,
  };
  return &language;
}
#ifdef __cplusplus
}
#endif
