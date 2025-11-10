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
#define STATE_COUNT 128
#define LARGE_STATE_COUNT 4
#define SYMBOL_COUNT 79
#define ALIAS_COUNT 1
#define TOKEN_COUNT 50
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
  sym_clock = 8,
  sym_timestamp = 9,
  anon_sym_LBRACE_LBRACE_LBRACE = 10,
  aux_sym_macro_token1 = 11,
  anon_sym_LPAREN = 12,
  aux_sym_macro_token2 = 13,
  anon_sym_RPAREN = 14,
  anon_sym_RBRACE_RBRACE_RBRACE = 15,
  sym_footnote_reference = 16,
  sym_latex_fragment = 17,
  sym_entity = 18,
  sym_subscript = 19,
  sym_superscript = 20,
  anon_sym_LBRACK_LBRACK = 21,
  aux_sym_link_token1 = 22,
  anon_sym_RBRACK_LBRACK = 23,
  anon_sym_RBRACK_RBRACK = 24,
  aux_sym_list_item_token1 = 25,
  aux_sym_list_item_token2 = 26,
  sym_bullet = 27,
  aux_sym_block_begin_token1 = 28,
  sym_block_type = 29,
  sym_language = 30,
  sym_block_content = 31,
  aux_sym_block_end_token1 = 32,
  anon_sym_PIPE = 33,
  sym_table_cell = 34,
  sym_table_separator = 35,
  aux_sym_directive_token1 = 36,
  anon_sym_COLON = 37,
  sym_name = 38,
  aux_sym_comment_token1 = 39,
  aux_sym_fixed_width_token1 = 40,
  anon_sym_COLONPROPERTIES_COLON = 41,
  aux_sym_property_drawer_token1 = 42,
  anon_sym_COLONEND_COLON = 43,
  aux_sym_key_token1 = 44,
  anon_sym_COLONend_COLON = 45,
  sym_drawer_content = 46,
  sym_horizontal_rule = 47,
  aux_sym_paragraph_token1 = 48,
  aux_sym_paragraph_token2 = 49,
  sym_document = 50,
  sym__element = 51,
  sym_headline = 52,
  sym_title = 53,
  sym_macro = 54,
  sym_link = 55,
  sym_list = 56,
  sym_list_item = 57,
  sym_block = 58,
  sym_block_begin = 59,
  sym_block_end = 60,
  sym_table = 61,
  sym_table_row = 62,
  sym_directive = 63,
  sym_comment = 64,
  sym_fixed_width = 65,
  sym_property_drawer = 66,
  sym_property = 67,
  sym_key = 68,
  sym_value = 69,
  sym_drawer = 70,
  sym_drawer_name = 71,
  sym_paragraph = 72,
  aux_sym_document_repeat1 = 73,
  aux_sym_list_repeat1 = 74,
  aux_sym_table_repeat1 = 75,
  aux_sym_table_row_repeat1 = 76,
  aux_sym_fixed_width_repeat1 = 77,
  aux_sym_property_drawer_repeat1 = 78,
  alias_sym_link_description = 79,
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
  [sym_clock] = "clock",
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
  [aux_sym_fixed_width_token1] = "fixed_width_token1",
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
  [sym_fixed_width] = "fixed_width",
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
  [aux_sym_fixed_width_repeat1] = "fixed_width_repeat1",
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
  [sym_clock] = sym_clock,
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
  [aux_sym_fixed_width_token1] = aux_sym_fixed_width_token1,
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
  [sym_fixed_width] = sym_fixed_width,
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
  [aux_sym_fixed_width_repeat1] = aux_sym_fixed_width_repeat1,
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
  [sym_clock] = {
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
  [aux_sym_fixed_width_token1] = {
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
  [sym_fixed_width] = {
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
  [aux_sym_fixed_width_repeat1] = {
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
  [123] = 123,
  [124] = 124,
  [125] = 125,
  [126] = 126,
  [127] = 127,
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(138);
      ADVANCE_MAP(
        '#', 23,
        '$', 28,
        '(', 213,
        ')', 216,
        '*', 148,
        '-', 40,
        ':', 255,
        '<', 130,
        'C', 188,
        'D', 206,
        'N', 193,
        'T', 204,
        'W', 189,
        '[', 25,
        '\\', 129,
        ']', 72,
        '_', 240,
        '{', 94,
        '|', 247,
        '}', 96,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(0);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(210);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(211);
      END_STATE();
    case 1:
      if (lookahead == '\n') ADVANCE(220);
      END_STATE();
    case 2:
      if (lookahead == '\n') ADVANCE(220);
      if (lookahead == '{') ADVANCE(97);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(2);
      END_STATE();
    case 3:
      if (lookahead == '\n') ADVANCE(251);
      if (lookahead == '+') ADVANCE(35);
      if (lookahead == '-') ADVANCE(3);
      if (lookahead == '|') ADVANCE(4);
      END_STATE();
    case 4:
      if (lookahead == '\n') ADVANCE(251);
      if (lookahead == '-') ADVANCE(3);
      END_STATE();
    case 5:
      if (lookahead == '\n') ADVANCE(219);
      END_STATE();
    case 6:
      if (lookahead == '\n') ADVANCE(185);
      END_STATE();
    case 7:
      if (lookahead == '\n') ADVANCE(271);
      if (lookahead == '-') ADVANCE(7);
      END_STATE();
    case 8:
      if (lookahead == '\n') ADVANCE(218);
      END_STATE();
    case 9:
      if (lookahead == '\n') ADVANCE(222);
      if (lookahead != 0) ADVANCE(9);
      END_STATE();
    case 10:
      if (lookahead == '\n') ADVANCE(221);
      if (lookahead != 0) ADVANCE(10);
      END_STATE();
    case 11:
      if (lookahead == '\n') ADVANCE(184);
      END_STATE();
    case 12:
      if (lookahead == '\n') ADVANCE(184);
      if (lookahead == '-') ADVANCE(36);
      END_STATE();
    case 13:
      if (lookahead == '\n') ADVANCE(141);
      if (lookahead == 'C') ADVANCE(156);
      if (lookahead == 'D') ADVANCE(174);
      if (lookahead == 'N') ADVANCE(162);
      if (lookahead == 'T') ADVANCE(173);
      if (lookahead == 'W') ADVANCE(157);
      if (lookahead == '[') ADVANCE(155);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(152);
      if (lookahead != 0) ADVANCE(182);
      END_STATE();
    case 14:
      if (lookahead == '\n') ADVANCE(142);
      if (lookahead == '[') ADVANCE(155);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(153);
      if (lookahead != 0) ADVANCE(182);
      END_STATE();
    case 15:
      if (lookahead == '\n') ADVANCE(143);
      if (lookahead == '|') ADVANCE(246);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(249);
      if (lookahead != 0) ADVANCE(250);
      END_STATE();
    case 16:
      if (lookahead == '\n') SKIP(16);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(180);
      if (lookahead != 0) ADVANCE(182);
      END_STATE();
    case 17:
      if (lookahead == '\n') ADVANCE(144);
      if (lookahead == ' ') ADVANCE(139);
      if (('\t' <= lookahead && lookahead <= '\r')) SKIP(17);
      END_STATE();
    case 18:
      if (lookahead == '\n') SKIP(18);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(179);
      if ((0x0b <= lookahead && lookahead <= '\r')) ADVANCE(179);
      if (lookahead != 0) ADVANCE(182);
      END_STATE();
    case 19:
      if (lookahead == '\n') ADVANCE(145);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(19);
      END_STATE();
    case 20:
      if (lookahead == '\n') ADVANCE(377);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(20);
      END_STATE();
    case 21:
      if (lookahead == '\n') SKIP(21);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(225);
      if (lookahead != 0 &&
          lookahead != ']') ADVANCE(226);
      END_STATE();
    case 22:
      if (lookahead == '\n') ADVANCE(146);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(154);
      if (lookahead != 0) ADVANCE(182);
      END_STATE();
    case 23:
      if (lookahead == ' ') ADVANCE(259);
      if (lookahead == '+') ADVANCE(252);
      END_STATE();
    case 24:
      if (lookahead == ' ') ADVANCE(140);
      if (('\t' <= lookahead && lookahead <= '\r')) SKIP(24);
      END_STATE();
    case 25:
      if (lookahead == '#') ADVANCE(128);
      if (lookahead == '[') ADVANCE(223);
      if (lookahead == 'f') ADVANCE(91);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(75);
      END_STATE();
    case 26:
      if (lookahead == '#') ADVANCE(33);
      if (lookahead == ':') ADVANCE(257);
      if (lookahead == '|') ADVANCE(246);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(26);
      if (lookahead == '-' ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(267);
      END_STATE();
    case 27:
      if (lookahead == '#') ADVANCE(32);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(243);
      if (lookahead != 0) ADVANCE(244);
      END_STATE();
    case 28:
      if (lookahead == '$') ADVANCE(133);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(30);
      END_STATE();
    case 29:
      if (lookahead == '$') ADVANCE(5);
      END_STATE();
    case 30:
      if (lookahead == '$') ADVANCE(5);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(30);
      END_STATE();
    case 31:
      if (lookahead == '$') ADVANCE(29);
      if (lookahead != 0) ADVANCE(31);
      END_STATE();
    case 32:
      if (lookahead == '+') ADVANCE(110);
      if (lookahead != 0) ADVANCE(244);
      END_STATE();
    case 33:
      if (lookahead == '+') ADVANCE(111);
      END_STATE();
    case 34:
      if (lookahead == '+') ADVANCE(113);
      if (lookahead != 0) ADVANCE(244);
      END_STATE();
    case 35:
      if (lookahead == '-') ADVANCE(3);
      END_STATE();
    case 36:
      if (lookahead == '-') ADVANCE(73);
      END_STATE();
    case 37:
      if (lookahead == '-') ADVANCE(7);
      END_STATE();
    case 38:
      if (lookahead == '-') ADVANCE(37);
      END_STATE();
    case 39:
      if (lookahead == '-') ADVANCE(38);
      END_STATE();
    case 40:
      if (lookahead == '-') ADVANCE(39);
      END_STATE();
    case 41:
      if (lookahead == ':') ADVANCE(43);
      END_STATE();
    case 42:
      if (lookahead == ':') ADVANCE(135);
      if (lookahead == ']') ADVANCE(8);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(42);
      END_STATE();
    case 43:
      if (lookahead == ':') ADVANCE(135);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(42);
      END_STATE();
    case 44:
      if (lookahead == ':') ADVANCE(263);
      END_STATE();
    case 45:
      if (lookahead == ':') ADVANCE(98);
      if (lookahead == '^') ADVANCE(131);
      if (lookahead == '_') ADVANCE(132);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(85);
      END_STATE();
    case 46:
      if (lookahead == ':') ADVANCE(266);
      END_STATE();
    case 47:
      if (lookahead == ':') ADVANCE(254);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(47);
      if (lookahead == '+' ||
          lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(242);
      END_STATE();
    case 48:
      if (lookahead == ':') ADVANCE(61);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(269);
      if (lookahead != 0) ADVANCE(270);
      END_STATE();
    case 49:
      if (lookahead == ':') ADVANCE(268);
      END_STATE();
    case 50:
      if (lookahead == ':') ADVANCE(268);
      if (lookahead != 0) ADVANCE(270);
      END_STATE();
    case 51:
      if (lookahead == ':') ADVANCE(90);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(51);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(258);
      END_STATE();
    case 52:
      if (lookahead == ':') ADVANCE(126);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(52);
      END_STATE();
    case 53:
      if (lookahead == '=') ADVANCE(56);
      if (lookahead == '[') ADVANCE(124);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(53);
      END_STATE();
    case 54:
      if (lookahead == '=') ADVANCE(56);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(54);
      END_STATE();
    case 55:
      if (lookahead == '>') ADVANCE(6);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(55);
      END_STATE();
    case 56:
      if (lookahead == '>') ADVANCE(99);
      END_STATE();
    case 57:
      if (lookahead == 'D') ADVANCE(134);
      if (lookahead == 'd') ADVANCE(50);
      if (lookahead != 0) ADVANCE(270);
      END_STATE();
    case 58:
      if (lookahead == 'D') ADVANCE(46);
      END_STATE();
    case 59:
      if (lookahead == 'E') ADVANCE(69);
      END_STATE();
    case 60:
      if (lookahead == 'E') ADVANCE(68);
      END_STATE();
    case 61:
      if (lookahead == 'E') ADVANCE(120);
      if (lookahead == 'e') ADVANCE(64);
      if (lookahead != 0) ADVANCE(270);
      END_STATE();
    case 62:
      if (lookahead == 'I') ADVANCE(59);
      END_STATE();
    case 63:
      if (lookahead == 'N') ADVANCE(58);
      END_STATE();
    case 64:
      if (lookahead == 'N') ADVANCE(107);
      if (lookahead == 'n') ADVANCE(57);
      if (lookahead != 0) ADVANCE(270);
      END_STATE();
    case 65:
      if (lookahead == 'O') ADVANCE(66);
      END_STATE();
    case 66:
      if (lookahead == 'P') ADVANCE(60);
      END_STATE();
    case 67:
      if (lookahead == 'R') ADVANCE(65);
      END_STATE();
    case 68:
      if (lookahead == 'R') ADVANCE(70);
      END_STATE();
    case 69:
      if (lookahead == 'S') ADVANCE(44);
      END_STATE();
    case 70:
      if (lookahead == 'T') ADVANCE(62);
      END_STATE();
    case 71:
      if (lookahead == '[') ADVANCE(223);
      if (lookahead == 'f') ADVANCE(91);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(75);
      END_STATE();
    case 72:
      if (lookahead == '[') ADVANCE(227);
      if (lookahead == ']') ADVANCE(228);
      END_STATE();
    case 73:
      if (lookahead == '[') ADVANCE(125);
      END_STATE();
    case 74:
      if (lookahead == ']') ADVANCE(151);
      END_STATE();
    case 75:
      if (lookahead == ']') ADVANCE(6);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(75);
      END_STATE();
    case 76:
      if (lookahead == ']') ADVANCE(12);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(76);
      END_STATE();
    case 77:
      if (lookahead == ']') ADVANCE(101);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(77);
      END_STATE();
    case 78:
      if (lookahead == ']') ADVANCE(8);
      if (lookahead != 0) ADVANCE(78);
      END_STATE();
    case 79:
      if (lookahead == '^') ADVANCE(131);
      if (lookahead == '_') ADVANCE(132);
      if (lookahead == ')' ||
          lookahead == '.') ADVANCE(234);
      if (lookahead == 'L' ||
          lookahead == 'l') ADVANCE(84);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(85);
      END_STATE();
    case 80:
      if (lookahead == '^') ADVANCE(131);
      if (lookahead == '_') ADVANCE(132);
      if (lookahead == ')' ||
          lookahead == '.') ADVANCE(234);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(80);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(85);
      END_STATE();
    case 81:
      if (lookahead == '^') ADVANCE(131);
      if (lookahead == '_') ADVANCE(132);
      if (lookahead == ')' ||
          lookahead == '.') ADVANCE(234);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(85);
      END_STATE();
    case 82:
      if (lookahead == '^') ADVANCE(131);
      if (lookahead == '_') ADVANCE(132);
      if (lookahead == 'C' ||
          lookahead == 'c') ADVANCE(83);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(85);
      END_STATE();
    case 83:
      if (lookahead == '^') ADVANCE(131);
      if (lookahead == '_') ADVANCE(132);
      if (lookahead == 'K' ||
          lookahead == 'k') ADVANCE(45);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(85);
      END_STATE();
    case 84:
      if (lookahead == '^') ADVANCE(131);
      if (lookahead == '_') ADVANCE(132);
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(82);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(85);
      END_STATE();
    case 85:
      if (lookahead == '^') ADVANCE(131);
      if (lookahead == '_') ADVANCE(132);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(85);
      END_STATE();
    case 86:
      if (lookahead == '_') ADVANCE(238);
      END_STATE();
    case 87:
      if (lookahead == '_') ADVANCE(245);
      END_STATE();
    case 88:
      if (lookahead == '_') ADVANCE(245);
      if (lookahead != 0) ADVANCE(244);
      END_STATE();
    case 89:
      if (lookahead == 'd') ADVANCE(49);
      END_STATE();
    case 90:
      if (lookahead == 'e') ADVANCE(92);
      END_STATE();
    case 91:
      if (lookahead == 'n') ADVANCE(41);
      END_STATE();
    case 92:
      if (lookahead == 'n') ADVANCE(89);
      END_STATE();
    case 93:
      if (lookahead == '{') ADVANCE(186);
      END_STATE();
    case 94:
      if (lookahead == '{') ADVANCE(93);
      END_STATE();
    case 95:
      if (lookahead == '}') ADVANCE(217);
      END_STATE();
    case 96:
      if (lookahead == '}') ADVANCE(95);
      END_STATE();
    case 97:
      if (lookahead == '}') ADVANCE(1);
      END_STATE();
    case 98:
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(53);
      END_STATE();
    case 99:
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(100);
      END_STATE();
    case 100:
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(100);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(52);
      END_STATE();
    case 101:
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(54);
      END_STATE();
    case 102:
      if (lookahead == ')' ||
          lookahead == '.') ADVANCE(234);
      END_STATE();
    case 103:
      if (lookahead == ')' ||
          lookahead == '.') ADVANCE(234);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(103);
      END_STATE();
    case 104:
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(234);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(104);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(103);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(102);
      END_STATE();
    case 105:
      if (lookahead == 'D' ||
          lookahead == 'd') ADVANCE(88);
      if (lookahead != 0) ADVANCE(244);
      END_STATE();
    case 106:
      if (lookahead == 'D' ||
          lookahead == 'd') ADVANCE(136);
      if (lookahead != 0) ADVANCE(244);
      END_STATE();
    case 107:
      if (lookahead == 'D' ||
          lookahead == 'd') ADVANCE(134);
      if (lookahead != 0) ADVANCE(270);
      END_STATE();
    case 108:
      if (lookahead == 'D' ||
          lookahead == 'd') ADVANCE(87);
      END_STATE();
    case 109:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(114);
      END_STATE();
    case 110:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(118);
      if (lookahead != 0) ADVANCE(244);
      END_STATE();
    case 111:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(117);
      END_STATE();
    case 112:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(120);
      if (lookahead != 0) ADVANCE(270);
      END_STATE();
    case 113:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(119);
      if (lookahead != 0) ADVANCE(244);
      END_STATE();
    case 114:
      if (lookahead == 'G' ||
          lookahead == 'g') ADVANCE(115);
      END_STATE();
    case 115:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(116);
      END_STATE();
    case 116:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(86);
      END_STATE();
    case 117:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(108);
      END_STATE();
    case 118:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(105);
      if (lookahead != 0) ADVANCE(244);
      END_STATE();
    case 119:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(106);
      if (lookahead != 0) ADVANCE(244);
      END_STATE();
    case 120:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(107);
      if (lookahead != 0) ADVANCE(270);
      END_STATE();
    case 121:
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(121);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(241);
      END_STATE();
    case 122:
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(214);
      if (lookahead != 0 &&
          lookahead != ')' &&
          lookahead != '}') ADVANCE(215);
      END_STATE();
    case 123:
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(123);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(212);
      END_STATE();
    case 124:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(76);
      END_STATE();
    case 125:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(77);
      END_STATE();
    case 126:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(127);
      END_STATE();
    case 127:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(11);
      END_STATE();
    case 128:
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(74);
      END_STATE();
    case 129:
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(2);
      END_STATE();
    case 130:
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '>') ADVANCE(55);
      END_STATE();
    case 131:
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(9);
      END_STATE();
    case 132:
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(10);
      END_STATE();
    case 133:
      if (lookahead != 0 &&
          lookahead != '$') ADVANCE(31);
      END_STATE();
    case 134:
      if (lookahead != 0 &&
          lookahead != ':') ADVANCE(270);
      END_STATE();
    case 135:
      if (lookahead != 0 &&
          lookahead != ']') ADVANCE(78);
      END_STATE();
    case 136:
      if (lookahead != 0 &&
          lookahead != '_') ADVANCE(244);
      END_STATE();
    case 137:
      if (eof) ADVANCE(138);
      if (lookahead == '\n') SKIP(137);
      if (lookahead == '#') ADVANCE(23);
      if (lookahead == '$') ADVANCE(291);
      if (lookahead == '*') ADVANCE(148);
      if (lookahead == '+') ADVANCE(234);
      if (lookahead == '-') ADVANCE(236);
      if (lookahead == ':') ADVANCE(255);
      if (lookahead == '<') ADVANCE(309);
      if (lookahead == 'C') ADVANCE(328);
      if (lookahead == 'D') ADVANCE(319);
      if (lookahead == 'S') ADVANCE(315);
      if (lookahead == '[') ADVANCE(71);
      if (lookahead == '\\') ADVANCE(373);
      if (lookahead == 'c') ADVANCE(79);
      if (lookahead == '{') ADVANCE(94);
      if (lookahead == '|') ADVANCE(247);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(229);
      if ((0x0b <= lookahead && lookahead <= '\r')) ADVANCE(290);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(80);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(350);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(81);
      if (lookahead != 0) ADVANCE(374);
      END_STATE();
    case 138:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 139:
      ACCEPT_TOKEN(anon_sym_SPACE);
      if (lookahead == '\n') ADVANCE(144);
      if (lookahead == ' ') ADVANCE(139);
      END_STATE();
    case 140:
      ACCEPT_TOKEN(anon_sym_SPACE);
      if (lookahead == ' ') ADVANCE(140);
      END_STATE();
    case 141:
      ACCEPT_TOKEN(anon_sym_LF);
      if (lookahead == '\n') ADVANCE(141);
      if (lookahead == 'C') ADVANCE(156);
      if (lookahead == 'D') ADVANCE(174);
      if (lookahead == 'N') ADVANCE(162);
      if (lookahead == 'T') ADVANCE(173);
      if (lookahead == 'W') ADVANCE(157);
      if (lookahead == '[') ADVANCE(155);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(152);
      END_STATE();
    case 142:
      ACCEPT_TOKEN(anon_sym_LF);
      if (lookahead == '\n') ADVANCE(142);
      if (lookahead == '[') ADVANCE(155);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(153);
      END_STATE();
    case 143:
      ACCEPT_TOKEN(anon_sym_LF);
      if (lookahead == '\n') ADVANCE(143);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(249);
      END_STATE();
    case 144:
      ACCEPT_TOKEN(anon_sym_LF);
      if (lookahead == '\n') ADVANCE(144);
      if (lookahead == ' ') ADVANCE(139);
      END_STATE();
    case 145:
      ACCEPT_TOKEN(anon_sym_LF);
      if (lookahead == '\n') ADVANCE(145);
      END_STATE();
    case 146:
      ACCEPT_TOKEN(anon_sym_LF);
      if (lookahead == '\n') ADVANCE(146);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(154);
      END_STATE();
    case 147:
      ACCEPT_TOKEN(anon_sym_LF);
      if (lookahead == '\n') ADVANCE(147);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(230);
      END_STATE();
    case 148:
      ACCEPT_TOKEN(sym_stars);
      if (lookahead == '*') ADVANCE(148);
      END_STATE();
    case 149:
      ACCEPT_TOKEN(sym_stars);
      if (lookahead == '*') ADVANCE(149);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(374);
      END_STATE();
    case 150:
      ACCEPT_TOKEN(sym_keyword);
      END_STATE();
    case 151:
      ACCEPT_TOKEN(sym_priority);
      END_STATE();
    case 152:
      ACCEPT_TOKEN(aux_sym_title_token1);
      if (lookahead == '\n') ADVANCE(141);
      if (lookahead == 'C') ADVANCE(156);
      if (lookahead == 'D') ADVANCE(174);
      if (lookahead == 'N') ADVANCE(162);
      if (lookahead == 'T') ADVANCE(173);
      if (lookahead == 'W') ADVANCE(157);
      if (lookahead == '[') ADVANCE(155);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(152);
      if (lookahead != 0) ADVANCE(182);
      END_STATE();
    case 153:
      ACCEPT_TOKEN(aux_sym_title_token1);
      if (lookahead == '\n') ADVANCE(142);
      if (lookahead == '[') ADVANCE(155);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(153);
      if (lookahead != 0) ADVANCE(182);
      END_STATE();
    case 154:
      ACCEPT_TOKEN(aux_sym_title_token1);
      if (lookahead == '\n') ADVANCE(146);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(154);
      if (lookahead != 0) ADVANCE(182);
      END_STATE();
    case 155:
      ACCEPT_TOKEN(aux_sym_title_token1);
      if (lookahead == '#') ADVANCE(181);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(182);
      END_STATE();
    case 156:
      ACCEPT_TOKEN(aux_sym_title_token1);
      if (lookahead == 'A') ADVANCE(169);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(182);
      END_STATE();
    case 157:
      ACCEPT_TOKEN(aux_sym_title_token1);
      if (lookahead == 'A') ADVANCE(166);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(182);
      END_STATE();
    case 158:
      ACCEPT_TOKEN(aux_sym_title_token1);
      if (lookahead == 'C') ADVANCE(163);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(182);
      END_STATE();
    case 159:
      ACCEPT_TOKEN(aux_sym_title_token1);
      if (lookahead == 'D') ADVANCE(150);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(182);
      END_STATE();
    case 160:
      ACCEPT_TOKEN(aux_sym_title_token1);
      if (lookahead == 'D') ADVANCE(172);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(182);
      END_STATE();
    case 161:
      ACCEPT_TOKEN(aux_sym_title_token1);
      if (lookahead == 'E') ADVANCE(150);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(182);
      END_STATE();
    case 162:
      ACCEPT_TOKEN(aux_sym_title_token1);
      if (lookahead == 'E') ADVANCE(177);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(182);
      END_STATE();
    case 163:
      ACCEPT_TOKEN(aux_sym_title_token1);
      if (lookahead == 'E') ADVANCE(168);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(182);
      END_STATE();
    case 164:
      ACCEPT_TOKEN(aux_sym_title_token1);
      if (lookahead == 'E') ADVANCE(159);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(182);
      END_STATE();
    case 165:
      ACCEPT_TOKEN(aux_sym_title_token1);
      if (lookahead == 'G') ADVANCE(150);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(182);
      END_STATE();
    case 166:
      ACCEPT_TOKEN(aux_sym_title_token1);
      if (lookahead == 'I') ADVANCE(176);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(182);
      END_STATE();
    case 167:
      ACCEPT_TOKEN(aux_sym_title_token1);
      if (lookahead == 'I') ADVANCE(170);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(182);
      END_STATE();
    case 168:
      ACCEPT_TOKEN(aux_sym_title_token1);
      if (lookahead == 'L') ADVANCE(164);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(182);
      END_STATE();
    case 169:
      ACCEPT_TOKEN(aux_sym_title_token1);
      if (lookahead == 'N') ADVANCE(158);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(182);
      END_STATE();
    case 170:
      ACCEPT_TOKEN(aux_sym_title_token1);
      if (lookahead == 'N') ADVANCE(165);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(182);
      END_STATE();
    case 171:
      ACCEPT_TOKEN(aux_sym_title_token1);
      if (lookahead == 'N') ADVANCE(161);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(182);
      END_STATE();
    case 172:
      ACCEPT_TOKEN(aux_sym_title_token1);
      if (lookahead == 'O') ADVANCE(150);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(182);
      END_STATE();
    case 173:
      ACCEPT_TOKEN(aux_sym_title_token1);
      if (lookahead == 'O') ADVANCE(160);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(182);
      END_STATE();
    case 174:
      ACCEPT_TOKEN(aux_sym_title_token1);
      if (lookahead == 'O') ADVANCE(171);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(182);
      END_STATE();
    case 175:
      ACCEPT_TOKEN(aux_sym_title_token1);
      if (lookahead == 'T') ADVANCE(150);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(182);
      END_STATE();
    case 176:
      ACCEPT_TOKEN(aux_sym_title_token1);
      if (lookahead == 'T') ADVANCE(167);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(182);
      END_STATE();
    case 177:
      ACCEPT_TOKEN(aux_sym_title_token1);
      if (lookahead == 'X') ADVANCE(175);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(182);
      END_STATE();
    case 178:
      ACCEPT_TOKEN(aux_sym_title_token1);
      if (lookahead == ']') ADVANCE(151);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(182);
      END_STATE();
    case 179:
      ACCEPT_TOKEN(aux_sym_title_token1);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(179);
      if ((0x0b <= lookahead && lookahead <= '\r')) ADVANCE(179);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead)) ADVANCE(182);
      END_STATE();
    case 180:
      ACCEPT_TOKEN(aux_sym_title_token1);
      if (lookahead == '\t' ||
          (0x0b <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(180);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead)) ADVANCE(182);
      END_STATE();
    case 181:
      ACCEPT_TOKEN(aux_sym_title_token1);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(178);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(182);
      END_STATE();
    case 182:
      ACCEPT_TOKEN(aux_sym_title_token1);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(182);
      END_STATE();
    case 183:
      ACCEPT_TOKEN(sym_planning_line);
      END_STATE();
    case 184:
      ACCEPT_TOKEN(sym_clock);
      END_STATE();
    case 185:
      ACCEPT_TOKEN(sym_timestamp);
      END_STATE();
    case 186:
      ACCEPT_TOKEN(anon_sym_LBRACE_LBRACE_LBRACE);
      END_STATE();
    case 187:
      ACCEPT_TOKEN(anon_sym_LBRACE_LBRACE_LBRACE);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(374);
      END_STATE();
    case 188:
      ACCEPT_TOKEN(aux_sym_macro_token1);
      if (lookahead == 'A') ADVANCE(201);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(212);
      if (('B' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(210);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(211);
      END_STATE();
    case 189:
      ACCEPT_TOKEN(aux_sym_macro_token1);
      if (lookahead == 'A') ADVANCE(198);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(212);
      if (('B' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(210);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(211);
      END_STATE();
    case 190:
      ACCEPT_TOKEN(aux_sym_macro_token1);
      if (lookahead == 'C') ADVANCE(195);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(212);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(210);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(211);
      END_STATE();
    case 191:
      ACCEPT_TOKEN(aux_sym_macro_token1);
      if (lookahead == 'D') ADVANCE(150);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(212);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(210);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(211);
      END_STATE();
    case 192:
      ACCEPT_TOKEN(aux_sym_macro_token1);
      if (lookahead == 'D') ADVANCE(205);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(212);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(210);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(211);
      END_STATE();
    case 193:
      ACCEPT_TOKEN(aux_sym_macro_token1);
      if (lookahead == 'E') ADVANCE(209);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(212);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(210);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(211);
      END_STATE();
    case 194:
      ACCEPT_TOKEN(aux_sym_macro_token1);
      if (lookahead == 'E') ADVANCE(150);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(212);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(210);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(211);
      END_STATE();
    case 195:
      ACCEPT_TOKEN(aux_sym_macro_token1);
      if (lookahead == 'E') ADVANCE(200);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(212);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(210);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(211);
      END_STATE();
    case 196:
      ACCEPT_TOKEN(aux_sym_macro_token1);
      if (lookahead == 'E') ADVANCE(191);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(212);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(210);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(211);
      END_STATE();
    case 197:
      ACCEPT_TOKEN(aux_sym_macro_token1);
      if (lookahead == 'G') ADVANCE(150);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(212);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(210);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(211);
      END_STATE();
    case 198:
      ACCEPT_TOKEN(aux_sym_macro_token1);
      if (lookahead == 'I') ADVANCE(208);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(212);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(210);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(211);
      END_STATE();
    case 199:
      ACCEPT_TOKEN(aux_sym_macro_token1);
      if (lookahead == 'I') ADVANCE(202);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(212);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(210);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(211);
      END_STATE();
    case 200:
      ACCEPT_TOKEN(aux_sym_macro_token1);
      if (lookahead == 'L') ADVANCE(196);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(212);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(210);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(211);
      END_STATE();
    case 201:
      ACCEPT_TOKEN(aux_sym_macro_token1);
      if (lookahead == 'N') ADVANCE(190);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(212);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(210);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(211);
      END_STATE();
    case 202:
      ACCEPT_TOKEN(aux_sym_macro_token1);
      if (lookahead == 'N') ADVANCE(197);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(212);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(210);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(211);
      END_STATE();
    case 203:
      ACCEPT_TOKEN(aux_sym_macro_token1);
      if (lookahead == 'N') ADVANCE(194);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(212);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(210);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(211);
      END_STATE();
    case 204:
      ACCEPT_TOKEN(aux_sym_macro_token1);
      if (lookahead == 'O') ADVANCE(192);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(212);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(210);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(211);
      END_STATE();
    case 205:
      ACCEPT_TOKEN(aux_sym_macro_token1);
      if (lookahead == 'O') ADVANCE(150);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(212);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(210);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(211);
      END_STATE();
    case 206:
      ACCEPT_TOKEN(aux_sym_macro_token1);
      if (lookahead == 'O') ADVANCE(203);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(212);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(210);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(211);
      END_STATE();
    case 207:
      ACCEPT_TOKEN(aux_sym_macro_token1);
      if (lookahead == 'T') ADVANCE(150);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(212);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(210);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(211);
      END_STATE();
    case 208:
      ACCEPT_TOKEN(aux_sym_macro_token1);
      if (lookahead == 'T') ADVANCE(199);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(212);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(210);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(211);
      END_STATE();
    case 209:
      ACCEPT_TOKEN(aux_sym_macro_token1);
      if (lookahead == 'X') ADVANCE(207);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(212);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(210);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(211);
      END_STATE();
    case 210:
      ACCEPT_TOKEN(aux_sym_macro_token1);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(212);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(211);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(210);
      END_STATE();
    case 211:
      ACCEPT_TOKEN(aux_sym_macro_token1);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(212);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(211);
      END_STATE();
    case 212:
      ACCEPT_TOKEN(aux_sym_macro_token1);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(212);
      END_STATE();
    case 213:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      END_STATE();
    case 214:
      ACCEPT_TOKEN(aux_sym_macro_token2);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(214);
      if (lookahead != 0 &&
          lookahead != ')' &&
          lookahead != '}') ADVANCE(215);
      END_STATE();
    case 215:
      ACCEPT_TOKEN(aux_sym_macro_token2);
      if (lookahead != 0 &&
          lookahead != ')' &&
          lookahead != '}') ADVANCE(215);
      END_STATE();
    case 216:
      ACCEPT_TOKEN(anon_sym_RPAREN);
      END_STATE();
    case 217:
      ACCEPT_TOKEN(anon_sym_RBRACE_RBRACE_RBRACE);
      END_STATE();
    case 218:
      ACCEPT_TOKEN(sym_footnote_reference);
      END_STATE();
    case 219:
      ACCEPT_TOKEN(sym_latex_fragment);
      END_STATE();
    case 220:
      ACCEPT_TOKEN(sym_entity);
      END_STATE();
    case 221:
      ACCEPT_TOKEN(sym_subscript);
      END_STATE();
    case 222:
      ACCEPT_TOKEN(sym_superscript);
      END_STATE();
    case 223:
      ACCEPT_TOKEN(anon_sym_LBRACK_LBRACK);
      END_STATE();
    case 224:
      ACCEPT_TOKEN(anon_sym_LBRACK_LBRACK);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(374);
      END_STATE();
    case 225:
      ACCEPT_TOKEN(aux_sym_link_token1);
      if (lookahead == '\t' ||
          (0x0b <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(225);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ']') ADVANCE(226);
      END_STATE();
    case 226:
      ACCEPT_TOKEN(aux_sym_link_token1);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != ']') ADVANCE(226);
      END_STATE();
    case 227:
      ACCEPT_TOKEN(anon_sym_RBRACK_LBRACK);
      END_STATE();
    case 228:
      ACCEPT_TOKEN(anon_sym_RBRACK_RBRACK);
      END_STATE();
    case 229:
      ACCEPT_TOKEN(aux_sym_list_item_token1);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(229);
      if ((0x0b <= lookahead && lookahead <= '\r')) ADVANCE(290);
      END_STATE();
    case 230:
      ACCEPT_TOKEN(aux_sym_list_item_token2);
      if (lookahead == '\n') ADVANCE(147);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(230);
      if (lookahead != 0) ADVANCE(233);
      END_STATE();
    case 231:
      ACCEPT_TOKEN(aux_sym_list_item_token2);
      if (lookahead == '\t' ||
          (0x0b <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(231);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(232);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead)) ADVANCE(233);
      END_STATE();
    case 232:
      ACCEPT_TOKEN(aux_sym_list_item_token2);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(232);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(233);
      END_STATE();
    case 233:
      ACCEPT_TOKEN(aux_sym_list_item_token2);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(233);
      END_STATE();
    case 234:
      ACCEPT_TOKEN(sym_bullet);
      END_STATE();
    case 235:
      ACCEPT_TOKEN(sym_bullet);
      if (lookahead == '-') ADVANCE(298);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(374);
      END_STATE();
    case 236:
      ACCEPT_TOKEN(sym_bullet);
      if (lookahead == '-') ADVANCE(39);
      END_STATE();
    case 237:
      ACCEPT_TOKEN(sym_bullet);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(374);
      END_STATE();
    case 238:
      ACCEPT_TOKEN(aux_sym_block_begin_token1);
      END_STATE();
    case 239:
      ACCEPT_TOKEN(aux_sym_block_begin_token1);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(374);
      END_STATE();
    case 240:
      ACCEPT_TOKEN(sym_block_type);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(241);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(240);
      END_STATE();
    case 241:
      ACCEPT_TOKEN(sym_block_type);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(241);
      END_STATE();
    case 242:
      ACCEPT_TOKEN(sym_language);
      if (lookahead == '+' ||
          lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(242);
      END_STATE();
    case 243:
      ACCEPT_TOKEN(sym_block_content);
      if (lookahead == '#') ADVANCE(32);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(243);
      if (lookahead != 0) ADVANCE(244);
      END_STATE();
    case 244:
      ACCEPT_TOKEN(sym_block_content);
      if (lookahead == '#') ADVANCE(34);
      if (lookahead != 0) ADVANCE(244);
      END_STATE();
    case 245:
      ACCEPT_TOKEN(aux_sym_block_end_token1);
      END_STATE();
    case 246:
      ACCEPT_TOKEN(anon_sym_PIPE);
      END_STATE();
    case 247:
      ACCEPT_TOKEN(anon_sym_PIPE);
      if (lookahead == '-') ADVANCE(3);
      END_STATE();
    case 248:
      ACCEPT_TOKEN(anon_sym_PIPE);
      if (lookahead == '-') ADVANCE(276);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(374);
      END_STATE();
    case 249:
      ACCEPT_TOKEN(sym_table_cell);
      if (lookahead == '\n') ADVANCE(143);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(249);
      if (lookahead != 0 &&
          lookahead != '|') ADVANCE(250);
      END_STATE();
    case 250:
      ACCEPT_TOKEN(sym_table_cell);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '|') ADVANCE(250);
      END_STATE();
    case 251:
      ACCEPT_TOKEN(sym_table_separator);
      END_STATE();
    case 252:
      ACCEPT_TOKEN(aux_sym_directive_token1);
      if (lookahead == 'B' ||
          lookahead == 'b') ADVANCE(109);
      END_STATE();
    case 253:
      ACCEPT_TOKEN(aux_sym_directive_token1);
      if (lookahead == 'B' ||
          lookahead == 'b') ADVANCE(365);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(374);
      END_STATE();
    case 254:
      ACCEPT_TOKEN(anon_sym_COLON);
      END_STATE();
    case 255:
      ACCEPT_TOKEN(anon_sym_COLON);
      if (lookahead == ' ') ADVANCE(261);
      if (lookahead == 'P') ADVANCE(67);
      END_STATE();
    case 256:
      ACCEPT_TOKEN(anon_sym_COLON);
      if (lookahead == ' ') ADVANCE(262);
      if (lookahead == 'P') ADVANCE(335);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(374);
      END_STATE();
    case 257:
      ACCEPT_TOKEN(anon_sym_COLON);
      if (lookahead == 'E') ADVANCE(63);
      END_STATE();
    case 258:
      ACCEPT_TOKEN(sym_name);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(258);
      END_STATE();
    case 259:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      END_STATE();
    case 260:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(374);
      END_STATE();
    case 261:
      ACCEPT_TOKEN(aux_sym_fixed_width_token1);
      END_STATE();
    case 262:
      ACCEPT_TOKEN(aux_sym_fixed_width_token1);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(374);
      END_STATE();
    case 263:
      ACCEPT_TOKEN(anon_sym_COLONPROPERTIES_COLON);
      END_STATE();
    case 264:
      ACCEPT_TOKEN(anon_sym_COLONPROPERTIES_COLON);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(374);
      END_STATE();
    case 265:
      ACCEPT_TOKEN(aux_sym_property_drawer_token1);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(265);
      END_STATE();
    case 266:
      ACCEPT_TOKEN(anon_sym_COLONEND_COLON);
      END_STATE();
    case 267:
      ACCEPT_TOKEN(aux_sym_key_token1);
      if (lookahead == '-' ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(267);
      END_STATE();
    case 268:
      ACCEPT_TOKEN(anon_sym_COLONend_COLON);
      END_STATE();
    case 269:
      ACCEPT_TOKEN(sym_drawer_content);
      if (lookahead == ':') ADVANCE(61);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(269);
      if (lookahead != 0) ADVANCE(270);
      END_STATE();
    case 270:
      ACCEPT_TOKEN(sym_drawer_content);
      if (lookahead == ':') ADVANCE(112);
      if (lookahead != 0) ADVANCE(270);
      END_STATE();
    case 271:
      ACCEPT_TOKEN(sym_horizontal_rule);
      END_STATE();
    case 272:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '\n') ADVANCE(31);
      if (lookahead == '$') ADVANCE(374);
      if (lookahead != 0) ADVANCE(273);
      END_STATE();
    case 273:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '\n') ADVANCE(31);
      if (lookahead == '$') ADVANCE(292);
      if (lookahead != 0) ADVANCE(273);
      END_STATE();
    case 274:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '\n') ADVANCE(220);
      if (lookahead == '{') ADVANCE(359);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(274);
      if (lookahead != 0) ADVANCE(374);
      END_STATE();
    case 275:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '\n') ADVANCE(220);
      if (lookahead != 0) ADVANCE(374);
      END_STATE();
    case 276:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '\n') ADVANCE(251);
      if (lookahead == '+') ADVANCE(294);
      if (lookahead == '-') ADVANCE(276);
      if (lookahead == '|') ADVANCE(277);
      if (lookahead != 0) ADVANCE(374);
      END_STATE();
    case 277:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '\n') ADVANCE(251);
      if (lookahead == '-') ADVANCE(276);
      if (lookahead != 0) ADVANCE(374);
      END_STATE();
    case 278:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '\n') ADVANCE(219);
      if (lookahead != 0) ADVANCE(374);
      END_STATE();
    case 279:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '\n') ADVANCE(185);
      if (lookahead != 0) ADVANCE(374);
      END_STATE();
    case 280:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '\n') ADVANCE(271);
      if (lookahead == '-') ADVANCE(280);
      if (lookahead != 0) ADVANCE(374);
      END_STATE();
    case 281:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '\n') ADVANCE(78);
      if (lookahead == ']') ADVANCE(374);
      if (lookahead != 0) ADVANCE(282);
      END_STATE();
    case 282:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '\n') ADVANCE(78);
      if (lookahead == ']') ADVANCE(283);
      if (lookahead != 0) ADVANCE(282);
      END_STATE();
    case 283:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '\n') ADVANCE(218);
      if (lookahead != 0) ADVANCE(374);
      END_STATE();
    case 284:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '\n') ADVANCE(222);
      if (lookahead != 0) ADVANCE(284);
      END_STATE();
    case 285:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '\n') ADVANCE(221);
      if (lookahead != 0) ADVANCE(285);
      END_STATE();
    case 286:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '\n') ADVANCE(184);
      if (lookahead == '-') ADVANCE(295);
      if (lookahead != 0) ADVANCE(374);
      END_STATE();
    case 287:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '\n') ADVANCE(184);
      if (lookahead != 0) ADVANCE(374);
      END_STATE();
    case 288:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '\n') ADVANCE(183);
      if (lookahead != 0) ADVANCE(374);
      END_STATE();
    case 289:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == ' ') ADVANCE(260);
      if (lookahead == '+') ADVANCE(253);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(374);
      END_STATE();
    case 290:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      ADVANCE_MAP(
        '#', 289,
        '$', 291,
        '*', 149,
        '+', 237,
        '-', 235,
        ':', 256,
        '<', 309,
        'C', 328,
        'D', 319,
        'S', 315,
        '[', 341,
        '\\', 373,
        'c', 348,
        '{', 358,
        '|', 248,
        '\t', 229,
        ' ', 229,
      );
      if ((0x0b <= lookahead && lookahead <= '\r')) ADVANCE(290);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(349);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(350);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(350);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead)) ADVANCE(374);
      END_STATE();
    case 291:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '$') ADVANCE(272);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(293);
      END_STATE();
    case 292:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '$') ADVANCE(278);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(374);
      END_STATE();
    case 293:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '$') ADVANCE(278);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(293);
      END_STATE();
    case 294:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '-') ADVANCE(276);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(374);
      END_STATE();
    case 295:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '-') ADVANCE(342);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(374);
      END_STATE();
    case 296:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '-') ADVANCE(280);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(374);
      END_STATE();
    case 297:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '-') ADVANCE(296);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(374);
      END_STATE();
    case 298:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '-') ADVANCE(297);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(374);
      END_STATE();
    case 299:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == ':') ADVANCE(302);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(374);
      END_STATE();
    case 300:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == ':') ADVANCE(360);
      if (lookahead == '^') ADVANCE(375);
      if (lookahead == '_') ADVANCE(376);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(354);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(374);
      END_STATE();
    case 301:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == ':') ADVANCE(281);
      if (lookahead == ']') ADVANCE(283);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(301);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(374);
      END_STATE();
    case 302:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == ':') ADVANCE(281);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(301);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(374);
      END_STATE();
    case 303:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == ':') ADVANCE(264);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(374);
      END_STATE();
    case 304:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == ':') ADVANCE(361);
      if (lookahead == '^') ADVANCE(375);
      if (lookahead == '_') ADVANCE(376);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(354);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(374);
      END_STATE();
    case 305:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == ':') ADVANCE(370);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(305);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(374);
      END_STATE();
    case 306:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '<') ADVANCE(310);
      if (lookahead == '[') ADVANCE(343);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(306);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n') ADVANCE(374);
      END_STATE();
    case 307:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '=') ADVANCE(312);
      if (lookahead == '[') ADVANCE(369);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(307);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n') ADVANCE(374);
      END_STATE();
    case 308:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '=') ADVANCE(312);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(308);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n') ADVANCE(374);
      END_STATE();
    case 309:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '>') ADVANCE(374);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(311);
      END_STATE();
    case 310:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '>') ADVANCE(374);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(313);
      END_STATE();
    case 311:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '>') ADVANCE(279);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(311);
      END_STATE();
    case 312:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '>') ADVANCE(363);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(374);
      END_STATE();
    case 313:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '>') ADVANCE(288);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(313);
      END_STATE();
    case 314:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == 'A') ADVANCE(316);
      if (lookahead == '^') ADVANCE(375);
      if (lookahead == '_') ADVANCE(376);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('B' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(354);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(374);
      END_STATE();
    case 315:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == 'C') ADVANCE(325);
      if (lookahead == '^') ADVANCE(375);
      if (lookahead == '_') ADVANCE(376);
      if (lookahead == ')' ||
          lookahead == '.') ADVANCE(237);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(354);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(374);
      END_STATE();
    case 316:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == 'D') ADVANCE(329);
      if (lookahead == '^') ADVANCE(375);
      if (lookahead == '_') ADVANCE(376);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(354);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(374);
      END_STATE();
    case 317:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == 'D') ADVANCE(340);
      if (lookahead == '^') ADVANCE(375);
      if (lookahead == '_') ADVANCE(376);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(354);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(374);
      END_STATE();
    case 318:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == 'D') ADVANCE(304);
      if (lookahead == '^') ADVANCE(375);
      if (lookahead == '_') ADVANCE(376);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(354);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(374);
      END_STATE();
    case 319:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == 'E') ADVANCE(314);
      if (lookahead == '^') ADVANCE(375);
      if (lookahead == '_') ADVANCE(376);
      if (lookahead == ')' ||
          lookahead == '.') ADVANCE(237);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(354);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(374);
      END_STATE();
    case 320:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == 'E') ADVANCE(337);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(374);
      END_STATE();
    case 321:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == 'E') ADVANCE(317);
      if (lookahead == '^') ADVANCE(375);
      if (lookahead == '_') ADVANCE(376);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(354);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(374);
      END_STATE();
    case 322:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == 'E') ADVANCE(336);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(374);
      END_STATE();
    case 323:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == 'E') ADVANCE(318);
      if (lookahead == '^') ADVANCE(375);
      if (lookahead == '_') ADVANCE(376);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(354);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(374);
      END_STATE();
    case 324:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == 'E') ADVANCE(304);
      if (lookahead == '^') ADVANCE(375);
      if (lookahead == '_') ADVANCE(376);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(354);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(374);
      END_STATE();
    case 325:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == 'H') ADVANCE(321);
      if (lookahead == '^') ADVANCE(375);
      if (lookahead == '_') ADVANCE(376);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(354);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(374);
      END_STATE();
    case 326:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == 'I') ADVANCE(331);
      if (lookahead == '^') ADVANCE(375);
      if (lookahead == '_') ADVANCE(376);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(354);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(374);
      END_STATE();
    case 327:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == 'I') ADVANCE(320);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(374);
      END_STATE();
    case 328:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == 'L') ADVANCE(332);
      if (lookahead == '^') ADVANCE(375);
      if (lookahead == '_') ADVANCE(376);
      if (lookahead == 'l') ADVANCE(353);
      if (lookahead == ')' ||
          lookahead == '.') ADVANCE(237);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(354);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(374);
      END_STATE();
    case 329:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == 'L') ADVANCE(326);
      if (lookahead == '^') ADVANCE(375);
      if (lookahead == '_') ADVANCE(376);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(354);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(374);
      END_STATE();
    case 330:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == 'L') ADVANCE(323);
      if (lookahead == '^') ADVANCE(375);
      if (lookahead == '_') ADVANCE(376);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(354);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(374);
      END_STATE();
    case 331:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == 'N') ADVANCE(324);
      if (lookahead == '^') ADVANCE(375);
      if (lookahead == '_') ADVANCE(376);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(354);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(374);
      END_STATE();
    case 332:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == 'O') ADVANCE(338);
      if (lookahead == '^') ADVANCE(375);
      if (lookahead == '_') ADVANCE(376);
      if (lookahead == 'o') ADVANCE(351);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(354);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(374);
      END_STATE();
    case 333:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == 'O') ADVANCE(334);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(374);
      END_STATE();
    case 334:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == 'P') ADVANCE(322);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(374);
      END_STATE();
    case 335:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == 'R') ADVANCE(333);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(374);
      END_STATE();
    case 336:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == 'R') ADVANCE(339);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(374);
      END_STATE();
    case 337:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == 'S') ADVANCE(303);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(374);
      END_STATE();
    case 338:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == 'S') ADVANCE(323);
      if (lookahead == '^') ADVANCE(375);
      if (lookahead == '_') ADVANCE(376);
      if (lookahead == 'C' ||
          lookahead == 'c') ADVANCE(352);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(354);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(374);
      END_STATE();
    case 339:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == 'T') ADVANCE(327);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(374);
      END_STATE();
    case 340:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == 'U') ADVANCE(330);
      if (lookahead == '^') ADVANCE(375);
      if (lookahead == '_') ADVANCE(376);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(354);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(374);
      END_STATE();
    case 341:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '[') ADVANCE(224);
      if (lookahead == 'f') ADVANCE(356);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(344);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(374);
      END_STATE();
    case 342:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '[') ADVANCE(371);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(374);
      END_STATE();
    case 343:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == ']') ADVANCE(374);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(347);
      END_STATE();
    case 344:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == ']') ADVANCE(279);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(344);
      END_STATE();
    case 345:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == ']') ADVANCE(286);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(345);
      END_STATE();
    case 346:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == ']') ADVANCE(364);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(346);
      END_STATE();
    case 347:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == ']') ADVANCE(288);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(347);
      END_STATE();
    case 348:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '^') ADVANCE(375);
      if (lookahead == '_') ADVANCE(376);
      if (lookahead == ')' ||
          lookahead == '.') ADVANCE(237);
      if (lookahead == 'L' ||
          lookahead == 'l') ADVANCE(353);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(354);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(374);
      END_STATE();
    case 349:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '^') ADVANCE(375);
      if (lookahead == '_') ADVANCE(376);
      if (lookahead == ')' ||
          lookahead == '.') ADVANCE(237);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(349);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(354);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(374);
      END_STATE();
    case 350:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '^') ADVANCE(375);
      if (lookahead == '_') ADVANCE(376);
      if (lookahead == ')' ||
          lookahead == '.') ADVANCE(237);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(354);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(374);
      END_STATE();
    case 351:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '^') ADVANCE(375);
      if (lookahead == '_') ADVANCE(376);
      if (lookahead == 'C' ||
          lookahead == 'c') ADVANCE(352);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(354);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(374);
      END_STATE();
    case 352:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '^') ADVANCE(375);
      if (lookahead == '_') ADVANCE(376);
      if (lookahead == 'K' ||
          lookahead == 'k') ADVANCE(300);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(354);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(374);
      END_STATE();
    case 353:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '^') ADVANCE(375);
      if (lookahead == '_') ADVANCE(376);
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(351);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(354);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(374);
      END_STATE();
    case 354:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '^') ADVANCE(375);
      if (lookahead == '_') ADVANCE(376);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(354);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(374);
      END_STATE();
    case 355:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '_') ADVANCE(239);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(374);
      END_STATE();
    case 356:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == 'n') ADVANCE(299);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(374);
      END_STATE();
    case 357:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '{') ADVANCE(187);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(374);
      END_STATE();
    case 358:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '{') ADVANCE(357);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(374);
      END_STATE();
    case 359:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '}') ADVANCE(275);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(374);
      END_STATE();
    case 360:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(307);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n') ADVANCE(374);
      END_STATE();
    case 361:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(306);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n') ADVANCE(374);
      END_STATE();
    case 362:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(362);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(305);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n') ADVANCE(374);
      END_STATE();
    case 363:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(362);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n') ADVANCE(374);
      END_STATE();
    case 364:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(308);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n') ADVANCE(374);
      END_STATE();
    case 365:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(366);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(374);
      END_STATE();
    case 366:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == 'G' ||
          lookahead == 'g') ADVANCE(367);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(374);
      END_STATE();
    case 367:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(368);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(374);
      END_STATE();
    case 368:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(355);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(374);
      END_STATE();
    case 369:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(345);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(374);
      END_STATE();
    case 370:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(372);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(374);
      END_STATE();
    case 371:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(346);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(374);
      END_STATE();
    case 372:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(287);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(374);
      END_STATE();
    case 373:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(274);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(374);
      END_STATE();
    case 374:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(374);
      END_STATE();
    case 375:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(284);
      END_STATE();
    case 376:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(285);
      END_STATE();
    case 377:
      ACCEPT_TOKEN(aux_sym_paragraph_token2);
      if (lookahead == '\n') ADVANCE(377);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 137},
  [2] = {.lex_state = 137},
  [3] = {.lex_state = 137},
  [4] = {.lex_state = 137},
  [5] = {.lex_state = 137},
  [6] = {.lex_state = 137},
  [7] = {.lex_state = 137},
  [8] = {.lex_state = 137},
  [9] = {.lex_state = 137},
  [10] = {.lex_state = 137},
  [11] = {.lex_state = 137},
  [12] = {.lex_state = 137},
  [13] = {.lex_state = 137},
  [14] = {.lex_state = 137},
  [15] = {.lex_state = 137},
  [16] = {.lex_state = 137},
  [17] = {.lex_state = 137},
  [18] = {.lex_state = 137},
  [19] = {.lex_state = 137},
  [20] = {.lex_state = 137},
  [21] = {.lex_state = 137},
  [22] = {.lex_state = 137},
  [23] = {.lex_state = 137},
  [24] = {.lex_state = 137},
  [25] = {.lex_state = 137},
  [26] = {.lex_state = 137},
  [27] = {.lex_state = 137},
  [28] = {.lex_state = 137},
  [29] = {.lex_state = 137},
  [30] = {.lex_state = 137},
  [31] = {.lex_state = 137},
  [32] = {.lex_state = 137},
  [33] = {.lex_state = 137},
  [34] = {.lex_state = 137},
  [35] = {.lex_state = 137},
  [36] = {.lex_state = 137},
  [37] = {.lex_state = 137},
  [38] = {.lex_state = 13},
  [39] = {.lex_state = 26},
  [40] = {.lex_state = 14},
  [41] = {.lex_state = 15},
  [42] = {.lex_state = 26},
  [43] = {.lex_state = 15},
  [44] = {.lex_state = 15},
  [45] = {.lex_state = 22},
  [46] = {.lex_state = 47},
  [47] = {.lex_state = 27},
  [48] = {.lex_state = 15},
  [49] = {.lex_state = 22},
  [50] = {.lex_state = 48},
  [51] = {.lex_state = 26},
  [52] = {.lex_state = 26},
  [53] = {.lex_state = 16},
  [54] = {.lex_state = 26},
  [55] = {.lex_state = 27},
  [56] = {.lex_state = 0},
  [57] = {.lex_state = 0},
  [58] = {.lex_state = 27},
  [59] = {.lex_state = 230},
  [60] = {.lex_state = 17},
  [61] = {.lex_state = 27},
  [62] = {.lex_state = 18},
  [63] = {.lex_state = 231},
  [64] = {.lex_state = 26},
  [65] = {.lex_state = 19},
  [66] = {.lex_state = 19},
  [67] = {.lex_state = 47},
  [68] = {.lex_state = 265},
  [69] = {.lex_state = 24},
  [70] = {.lex_state = 24},
  [71] = {.lex_state = 19},
  [72] = {.lex_state = 231},
  [73] = {.lex_state = 24},
  [74] = {.lex_state = 0},
  [75] = {.lex_state = 19},
  [76] = {.lex_state = 0},
  [77] = {.lex_state = 19},
  [78] = {.lex_state = 19},
  [79] = {.lex_state = 47},
  [80] = {.lex_state = 19},
  [81] = {.lex_state = 16},
  [82] = {.lex_state = 19},
  [83] = {.lex_state = 47},
  [84] = {.lex_state = 47},
  [85] = {.lex_state = 19},
  [86] = {.lex_state = 26},
  [87] = {.lex_state = 24},
  [88] = {.lex_state = 19},
  [89] = {.lex_state = 19},
  [90] = {.lex_state = 0},
  [91] = {.lex_state = 19},
  [92] = {.lex_state = 231},
  [93] = {.lex_state = 19},
  [94] = {.lex_state = 19},
  [95] = {.lex_state = 24},
  [96] = {.lex_state = 19},
  [97] = {.lex_state = 231},
  [98] = {.lex_state = 47},
  [99] = {.lex_state = 47},
  [100] = {.lex_state = 265},
  [101] = {.lex_state = 19},
  [102] = {.lex_state = 0},
  [103] = {.lex_state = 20},
  [104] = {.lex_state = 265},
  [105] = {.lex_state = 231},
  [106] = {.lex_state = 19},
  [107] = {.lex_state = 231},
  [108] = {.lex_state = 21},
  [109] = {.lex_state = 19},
  [110] = {.lex_state = 265},
  [111] = {.lex_state = 51},
  [112] = {.lex_state = 265},
  [113] = {.lex_state = 19},
  [114] = {.lex_state = 51},
  [115] = {.lex_state = 19},
  [116] = {.lex_state = 121},
  [117] = {.lex_state = 19},
  [118] = {.lex_state = 265},
  [119] = {.lex_state = 122},
  [120] = {.lex_state = 24},
  [121] = {.lex_state = 104},
  [122] = {.lex_state = 21},
  [123] = {.lex_state = 19},
  [124] = {.lex_state = 19},
  [125] = {.lex_state = 19},
  [126] = {.lex_state = 123},
  [127] = {.lex_state = 19},
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
    [aux_sym_fixed_width_token1] = ACTIONS(1),
    [anon_sym_COLONPROPERTIES_COLON] = ACTIONS(1),
    [sym_horizontal_rule] = ACTIONS(1),
  },
  [1] = {
    [sym_document] = STATE(102),
    [sym__element] = STATE(3),
    [sym_headline] = STATE(3),
    [sym_macro] = STATE(3),
    [sym_link] = STATE(3),
    [sym_list] = STATE(3),
    [sym_list_item] = STATE(6),
    [sym_block] = STATE(3),
    [sym_block_begin] = STATE(47),
    [sym_table] = STATE(3),
    [sym_table_row] = STATE(7),
    [sym_directive] = STATE(3),
    [sym_comment] = STATE(3),
    [sym_fixed_width] = STATE(3),
    [sym_property_drawer] = STATE(3),
    [sym_drawer] = STATE(3),
    [sym_paragraph] = STATE(3),
    [aux_sym_document_repeat1] = STATE(3),
    [aux_sym_list_repeat1] = STATE(6),
    [aux_sym_table_repeat1] = STATE(7),
    [aux_sym_fixed_width_repeat1] = STATE(8),
    [ts_builtin_sym_end] = ACTIONS(3),
    [sym_stars] = ACTIONS(5),
    [sym_planning_line] = ACTIONS(7),
    [sym_clock] = ACTIONS(7),
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
    [aux_sym_fixed_width_token1] = ACTIONS(29),
    [anon_sym_COLONPROPERTIES_COLON] = ACTIONS(31),
    [sym_horizontal_rule] = ACTIONS(7),
    [aux_sym_paragraph_token1] = ACTIONS(33),
  },
  [2] = {
    [sym__element] = STATE(2),
    [sym_headline] = STATE(2),
    [sym_macro] = STATE(2),
    [sym_link] = STATE(2),
    [sym_list] = STATE(2),
    [sym_list_item] = STATE(6),
    [sym_block] = STATE(2),
    [sym_block_begin] = STATE(47),
    [sym_table] = STATE(2),
    [sym_table_row] = STATE(7),
    [sym_directive] = STATE(2),
    [sym_comment] = STATE(2),
    [sym_fixed_width] = STATE(2),
    [sym_property_drawer] = STATE(2),
    [sym_drawer] = STATE(2),
    [sym_paragraph] = STATE(2),
    [aux_sym_document_repeat1] = STATE(2),
    [aux_sym_list_repeat1] = STATE(6),
    [aux_sym_table_repeat1] = STATE(7),
    [aux_sym_fixed_width_repeat1] = STATE(8),
    [ts_builtin_sym_end] = ACTIONS(35),
    [sym_stars] = ACTIONS(37),
    [sym_planning_line] = ACTIONS(40),
    [sym_clock] = ACTIONS(40),
    [sym_timestamp] = ACTIONS(40),
    [anon_sym_LBRACE_LBRACE_LBRACE] = ACTIONS(43),
    [sym_footnote_reference] = ACTIONS(40),
    [sym_latex_fragment] = ACTIONS(40),
    [sym_entity] = ACTIONS(40),
    [sym_subscript] = ACTIONS(40),
    [sym_superscript] = ACTIONS(40),
    [anon_sym_LBRACK_LBRACK] = ACTIONS(46),
    [aux_sym_list_item_token1] = ACTIONS(49),
    [sym_bullet] = ACTIONS(52),
    [aux_sym_block_begin_token1] = ACTIONS(55),
    [anon_sym_PIPE] = ACTIONS(58),
    [sym_table_separator] = ACTIONS(61),
    [aux_sym_directive_token1] = ACTIONS(64),
    [anon_sym_COLON] = ACTIONS(67),
    [aux_sym_comment_token1] = ACTIONS(70),
    [aux_sym_fixed_width_token1] = ACTIONS(73),
    [anon_sym_COLONPROPERTIES_COLON] = ACTIONS(76),
    [sym_horizontal_rule] = ACTIONS(40),
    [aux_sym_paragraph_token1] = ACTIONS(79),
  },
  [3] = {
    [sym__element] = STATE(2),
    [sym_headline] = STATE(2),
    [sym_macro] = STATE(2),
    [sym_link] = STATE(2),
    [sym_list] = STATE(2),
    [sym_list_item] = STATE(6),
    [sym_block] = STATE(2),
    [sym_block_begin] = STATE(47),
    [sym_table] = STATE(2),
    [sym_table_row] = STATE(7),
    [sym_directive] = STATE(2),
    [sym_comment] = STATE(2),
    [sym_fixed_width] = STATE(2),
    [sym_property_drawer] = STATE(2),
    [sym_drawer] = STATE(2),
    [sym_paragraph] = STATE(2),
    [aux_sym_document_repeat1] = STATE(2),
    [aux_sym_list_repeat1] = STATE(6),
    [aux_sym_table_repeat1] = STATE(7),
    [aux_sym_fixed_width_repeat1] = STATE(8),
    [ts_builtin_sym_end] = ACTIONS(82),
    [sym_stars] = ACTIONS(5),
    [sym_planning_line] = ACTIONS(84),
    [sym_clock] = ACTIONS(84),
    [sym_timestamp] = ACTIONS(84),
    [anon_sym_LBRACE_LBRACE_LBRACE] = ACTIONS(9),
    [sym_footnote_reference] = ACTIONS(84),
    [sym_latex_fragment] = ACTIONS(84),
    [sym_entity] = ACTIONS(84),
    [sym_subscript] = ACTIONS(84),
    [sym_superscript] = ACTIONS(84),
    [anon_sym_LBRACK_LBRACK] = ACTIONS(11),
    [aux_sym_list_item_token1] = ACTIONS(13),
    [sym_bullet] = ACTIONS(15),
    [aux_sym_block_begin_token1] = ACTIONS(17),
    [anon_sym_PIPE] = ACTIONS(19),
    [sym_table_separator] = ACTIONS(21),
    [aux_sym_directive_token1] = ACTIONS(23),
    [anon_sym_COLON] = ACTIONS(25),
    [aux_sym_comment_token1] = ACTIONS(27),
    [aux_sym_fixed_width_token1] = ACTIONS(29),
    [anon_sym_COLONPROPERTIES_COLON] = ACTIONS(31),
    [sym_horizontal_rule] = ACTIONS(84),
    [aux_sym_paragraph_token1] = ACTIONS(33),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 5,
    ACTIONS(86), 1,
      ts_builtin_sym_end,
    ACTIONS(90), 1,
      anon_sym_PIPE,
    ACTIONS(93), 1,
      sym_table_separator,
    STATE(4), 2,
      sym_table_row,
      aux_sym_table_repeat1,
    ACTIONS(88), 21,
      sym_stars,
      sym_planning_line,
      sym_clock,
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
      aux_sym_fixed_width_token1,
      anon_sym_COLONPROPERTIES_COLON,
      sym_horizontal_rule,
      aux_sym_paragraph_token1,
  [37] = 5,
    ACTIONS(96), 1,
      ts_builtin_sym_end,
    ACTIONS(100), 1,
      aux_sym_list_item_token1,
    ACTIONS(103), 1,
      sym_bullet,
    STATE(5), 2,
      sym_list_item,
      aux_sym_list_repeat1,
    ACTIONS(98), 21,
      sym_stars,
      sym_planning_line,
      sym_clock,
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
      aux_sym_fixed_width_token1,
      anon_sym_COLONPROPERTIES_COLON,
      sym_horizontal_rule,
      aux_sym_paragraph_token1,
  [74] = 5,
    ACTIONS(13), 1,
      aux_sym_list_item_token1,
    ACTIONS(15), 1,
      sym_bullet,
    ACTIONS(106), 1,
      ts_builtin_sym_end,
    STATE(5), 2,
      sym_list_item,
      aux_sym_list_repeat1,
    ACTIONS(108), 21,
      sym_stars,
      sym_planning_line,
      sym_clock,
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
      aux_sym_fixed_width_token1,
      anon_sym_COLONPROPERTIES_COLON,
      sym_horizontal_rule,
      aux_sym_paragraph_token1,
  [111] = 5,
    ACTIONS(19), 1,
      anon_sym_PIPE,
    ACTIONS(110), 1,
      ts_builtin_sym_end,
    ACTIONS(114), 1,
      sym_table_separator,
    STATE(4), 2,
      sym_table_row,
      aux_sym_table_repeat1,
    ACTIONS(112), 21,
      sym_stars,
      sym_planning_line,
      sym_clock,
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
      aux_sym_fixed_width_token1,
      anon_sym_COLONPROPERTIES_COLON,
      sym_horizontal_rule,
      aux_sym_paragraph_token1,
  [148] = 4,
    ACTIONS(29), 1,
      aux_sym_fixed_width_token1,
    ACTIONS(116), 1,
      ts_builtin_sym_end,
    STATE(9), 1,
      aux_sym_fixed_width_repeat1,
    ACTIONS(118), 22,
      sym_stars,
      sym_planning_line,
      sym_clock,
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
  [182] = 4,
    ACTIONS(120), 1,
      ts_builtin_sym_end,
    ACTIONS(124), 1,
      aux_sym_fixed_width_token1,
    STATE(9), 1,
      aux_sym_fixed_width_repeat1,
    ACTIONS(122), 22,
      sym_stars,
      sym_planning_line,
      sym_clock,
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
  [216] = 2,
    ACTIONS(127), 1,
      ts_builtin_sym_end,
    ACTIONS(129), 23,
      sym_stars,
      sym_planning_line,
      sym_clock,
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
      aux_sym_fixed_width_token1,
      anon_sym_COLONPROPERTIES_COLON,
      sym_horizontal_rule,
      aux_sym_paragraph_token1,
  [245] = 2,
    ACTIONS(131), 1,
      ts_builtin_sym_end,
    ACTIONS(133), 23,
      sym_stars,
      sym_planning_line,
      sym_clock,
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
      aux_sym_fixed_width_token1,
      anon_sym_COLONPROPERTIES_COLON,
      sym_horizontal_rule,
      aux_sym_paragraph_token1,
  [274] = 2,
    ACTIONS(135), 1,
      ts_builtin_sym_end,
    ACTIONS(137), 23,
      sym_stars,
      sym_planning_line,
      sym_clock,
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
      aux_sym_fixed_width_token1,
      anon_sym_COLONPROPERTIES_COLON,
      sym_horizontal_rule,
      aux_sym_paragraph_token1,
  [303] = 2,
    ACTIONS(139), 1,
      ts_builtin_sym_end,
    ACTIONS(141), 23,
      sym_stars,
      sym_planning_line,
      sym_clock,
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
      aux_sym_fixed_width_token1,
      anon_sym_COLONPROPERTIES_COLON,
      sym_horizontal_rule,
      aux_sym_paragraph_token1,
  [332] = 2,
    ACTIONS(143), 1,
      ts_builtin_sym_end,
    ACTIONS(145), 23,
      sym_stars,
      sym_planning_line,
      sym_clock,
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
      aux_sym_fixed_width_token1,
      anon_sym_COLONPROPERTIES_COLON,
      sym_horizontal_rule,
      aux_sym_paragraph_token1,
  [361] = 2,
    ACTIONS(147), 1,
      ts_builtin_sym_end,
    ACTIONS(149), 23,
      sym_stars,
      sym_planning_line,
      sym_clock,
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
      aux_sym_fixed_width_token1,
      anon_sym_COLONPROPERTIES_COLON,
      sym_horizontal_rule,
      aux_sym_paragraph_token1,
  [390] = 2,
    ACTIONS(151), 1,
      ts_builtin_sym_end,
    ACTIONS(153), 23,
      sym_stars,
      sym_planning_line,
      sym_clock,
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
      aux_sym_fixed_width_token1,
      anon_sym_COLONPROPERTIES_COLON,
      sym_horizontal_rule,
      aux_sym_paragraph_token1,
  [419] = 2,
    ACTIONS(155), 1,
      ts_builtin_sym_end,
    ACTIONS(157), 23,
      sym_stars,
      sym_planning_line,
      sym_clock,
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
      aux_sym_fixed_width_token1,
      anon_sym_COLONPROPERTIES_COLON,
      sym_horizontal_rule,
      aux_sym_paragraph_token1,
  [448] = 2,
    ACTIONS(159), 1,
      ts_builtin_sym_end,
    ACTIONS(161), 23,
      sym_stars,
      sym_planning_line,
      sym_clock,
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
      aux_sym_fixed_width_token1,
      anon_sym_COLONPROPERTIES_COLON,
      sym_horizontal_rule,
      aux_sym_paragraph_token1,
  [477] = 2,
    ACTIONS(163), 1,
      ts_builtin_sym_end,
    ACTIONS(165), 23,
      sym_stars,
      sym_planning_line,
      sym_clock,
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
      aux_sym_fixed_width_token1,
      anon_sym_COLONPROPERTIES_COLON,
      sym_horizontal_rule,
      aux_sym_paragraph_token1,
  [506] = 2,
    ACTIONS(167), 1,
      ts_builtin_sym_end,
    ACTIONS(169), 23,
      sym_stars,
      sym_planning_line,
      sym_clock,
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
      aux_sym_fixed_width_token1,
      anon_sym_COLONPROPERTIES_COLON,
      sym_horizontal_rule,
      aux_sym_paragraph_token1,
  [535] = 2,
    ACTIONS(171), 1,
      ts_builtin_sym_end,
    ACTIONS(173), 23,
      sym_stars,
      sym_planning_line,
      sym_clock,
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
      aux_sym_fixed_width_token1,
      anon_sym_COLONPROPERTIES_COLON,
      sym_horizontal_rule,
      aux_sym_paragraph_token1,
  [564] = 2,
    ACTIONS(175), 1,
      ts_builtin_sym_end,
    ACTIONS(177), 23,
      sym_stars,
      sym_planning_line,
      sym_clock,
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
      aux_sym_fixed_width_token1,
      anon_sym_COLONPROPERTIES_COLON,
      sym_horizontal_rule,
      aux_sym_paragraph_token1,
  [593] = 2,
    ACTIONS(179), 1,
      ts_builtin_sym_end,
    ACTIONS(181), 23,
      sym_stars,
      sym_planning_line,
      sym_clock,
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
      aux_sym_fixed_width_token1,
      anon_sym_COLONPROPERTIES_COLON,
      sym_horizontal_rule,
      aux_sym_paragraph_token1,
  [622] = 2,
    ACTIONS(183), 1,
      ts_builtin_sym_end,
    ACTIONS(185), 23,
      sym_stars,
      sym_planning_line,
      sym_clock,
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
      aux_sym_fixed_width_token1,
      anon_sym_COLONPROPERTIES_COLON,
      sym_horizontal_rule,
      aux_sym_paragraph_token1,
  [651] = 2,
    ACTIONS(187), 1,
      ts_builtin_sym_end,
    ACTIONS(189), 23,
      sym_stars,
      sym_planning_line,
      sym_clock,
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
      aux_sym_fixed_width_token1,
      anon_sym_COLONPROPERTIES_COLON,
      sym_horizontal_rule,
      aux_sym_paragraph_token1,
  [680] = 2,
    ACTIONS(191), 1,
      ts_builtin_sym_end,
    ACTIONS(193), 23,
      sym_stars,
      sym_planning_line,
      sym_clock,
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
      aux_sym_fixed_width_token1,
      anon_sym_COLONPROPERTIES_COLON,
      sym_horizontal_rule,
      aux_sym_paragraph_token1,
  [709] = 2,
    ACTIONS(195), 1,
      ts_builtin_sym_end,
    ACTIONS(197), 23,
      sym_stars,
      sym_planning_line,
      sym_clock,
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
      aux_sym_fixed_width_token1,
      anon_sym_COLONPROPERTIES_COLON,
      sym_horizontal_rule,
      aux_sym_paragraph_token1,
  [738] = 2,
    ACTIONS(199), 1,
      ts_builtin_sym_end,
    ACTIONS(201), 23,
      sym_stars,
      sym_planning_line,
      sym_clock,
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
      aux_sym_fixed_width_token1,
      anon_sym_COLONPROPERTIES_COLON,
      sym_horizontal_rule,
      aux_sym_paragraph_token1,
  [767] = 2,
    ACTIONS(203), 1,
      ts_builtin_sym_end,
    ACTIONS(205), 23,
      sym_stars,
      sym_planning_line,
      sym_clock,
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
      aux_sym_fixed_width_token1,
      anon_sym_COLONPROPERTIES_COLON,
      sym_horizontal_rule,
      aux_sym_paragraph_token1,
  [796] = 2,
    ACTIONS(207), 1,
      ts_builtin_sym_end,
    ACTIONS(209), 23,
      sym_stars,
      sym_planning_line,
      sym_clock,
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
      aux_sym_fixed_width_token1,
      anon_sym_COLONPROPERTIES_COLON,
      sym_horizontal_rule,
      aux_sym_paragraph_token1,
  [825] = 2,
    ACTIONS(211), 1,
      ts_builtin_sym_end,
    ACTIONS(213), 23,
      sym_stars,
      sym_planning_line,
      sym_clock,
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
      aux_sym_fixed_width_token1,
      anon_sym_COLONPROPERTIES_COLON,
      sym_horizontal_rule,
      aux_sym_paragraph_token1,
  [854] = 2,
    ACTIONS(215), 1,
      ts_builtin_sym_end,
    ACTIONS(217), 23,
      sym_stars,
      sym_planning_line,
      sym_clock,
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
      aux_sym_fixed_width_token1,
      anon_sym_COLONPROPERTIES_COLON,
      sym_horizontal_rule,
      aux_sym_paragraph_token1,
  [883] = 2,
    ACTIONS(219), 1,
      ts_builtin_sym_end,
    ACTIONS(221), 23,
      sym_stars,
      sym_planning_line,
      sym_clock,
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
      aux_sym_fixed_width_token1,
      anon_sym_COLONPROPERTIES_COLON,
      sym_horizontal_rule,
      aux_sym_paragraph_token1,
  [912] = 2,
    ACTIONS(223), 1,
      ts_builtin_sym_end,
    ACTIONS(225), 23,
      sym_stars,
      sym_planning_line,
      sym_clock,
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
      aux_sym_fixed_width_token1,
      anon_sym_COLONPROPERTIES_COLON,
      sym_horizontal_rule,
      aux_sym_paragraph_token1,
  [941] = 2,
    ACTIONS(227), 1,
      ts_builtin_sym_end,
    ACTIONS(229), 23,
      sym_stars,
      sym_planning_line,
      sym_clock,
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
      aux_sym_fixed_width_token1,
      anon_sym_COLONPROPERTIES_COLON,
      sym_horizontal_rule,
      aux_sym_paragraph_token1,
  [970] = 2,
    ACTIONS(231), 1,
      ts_builtin_sym_end,
    ACTIONS(233), 23,
      sym_stars,
      sym_planning_line,
      sym_clock,
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
      aux_sym_fixed_width_token1,
      anon_sym_COLONPROPERTIES_COLON,
      sym_horizontal_rule,
      aux_sym_paragraph_token1,
  [999] = 2,
    ACTIONS(235), 1,
      ts_builtin_sym_end,
    ACTIONS(237), 23,
      sym_stars,
      sym_planning_line,
      sym_clock,
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
      aux_sym_fixed_width_token1,
      anon_sym_COLONPROPERTIES_COLON,
      sym_horizontal_rule,
      aux_sym_paragraph_token1,
  [1028] = 5,
    ACTIONS(239), 1,
      anon_sym_LF,
    ACTIONS(241), 1,
      sym_keyword,
    ACTIONS(243), 1,
      sym_priority,
    ACTIONS(245), 1,
      aux_sym_title_token1,
    STATE(127), 1,
      sym_title,
  [1044] = 3,
    ACTIONS(247), 1,
      anon_sym_COLON,
    ACTIONS(250), 1,
      anon_sym_COLONEND_COLON,
    STATE(39), 2,
      sym_property,
      aux_sym_property_drawer_repeat1,
  [1055] = 4,
    ACTIONS(245), 1,
      aux_sym_title_token1,
    ACTIONS(252), 1,
      anon_sym_LF,
    ACTIONS(254), 1,
      sym_priority,
    STATE(88), 1,
      sym_title,
  [1068] = 4,
    ACTIONS(256), 1,
      anon_sym_LF,
    ACTIONS(258), 1,
      anon_sym_PIPE,
    ACTIONS(260), 1,
      sym_table_cell,
    STATE(43), 1,
      aux_sym_table_row_repeat1,
  [1081] = 3,
    ACTIONS(262), 1,
      anon_sym_COLON,
    ACTIONS(264), 1,
      anon_sym_COLONEND_COLON,
    STATE(39), 2,
      sym_property,
      aux_sym_property_drawer_repeat1,
  [1092] = 4,
    ACTIONS(260), 1,
      sym_table_cell,
    ACTIONS(266), 1,
      anon_sym_LF,
    ACTIONS(268), 1,
      anon_sym_PIPE,
    STATE(44), 1,
      aux_sym_table_row_repeat1,
  [1105] = 4,
    ACTIONS(270), 1,
      anon_sym_LF,
    ACTIONS(272), 1,
      anon_sym_PIPE,
    ACTIONS(275), 1,
      sym_table_cell,
    STATE(44), 1,
      aux_sym_table_row_repeat1,
  [1118] = 3,
    ACTIONS(245), 1,
      aux_sym_title_token1,
    ACTIONS(278), 1,
      anon_sym_LF,
    STATE(89), 1,
      sym_title,
  [1128] = 2,
    ACTIONS(280), 1,
      anon_sym_COLON,
    STATE(42), 2,
      sym_property,
      aux_sym_property_drawer_repeat1,
  [1136] = 3,
    ACTIONS(282), 1,
      sym_block_content,
    ACTIONS(284), 1,
      aux_sym_block_end_token1,
    STATE(37), 1,
      sym_block_end,
  [1146] = 1,
    ACTIONS(270), 3,
      anon_sym_LF,
      anon_sym_PIPE,
      sym_table_cell,
  [1152] = 3,
    ACTIONS(245), 1,
      aux_sym_title_token1,
    ACTIONS(286), 1,
      anon_sym_LF,
    STATE(115), 1,
      sym_title,
  [1162] = 2,
    ACTIONS(288), 1,
      anon_sym_COLONend_COLON,
    ACTIONS(290), 1,
      sym_drawer_content,
  [1169] = 2,
    ACTIONS(292), 1,
      aux_sym_key_token1,
    STATE(99), 1,
      sym_key,
  [1176] = 2,
    ACTIONS(294), 1,
      anon_sym_COLON,
    ACTIONS(296), 1,
      anon_sym_COLONEND_COLON,
  [1183] = 2,
    ACTIONS(298), 1,
      aux_sym_title_token1,
    STATE(125), 1,
      sym_value,
  [1190] = 2,
    ACTIONS(300), 1,
      aux_sym_key_token1,
    STATE(79), 1,
      sym_drawer_name,
  [1197] = 2,
    ACTIONS(302), 1,
      sym_block_content,
    ACTIONS(304), 1,
      aux_sym_block_end_token1,
  [1204] = 2,
    ACTIONS(306), 1,
      anon_sym_LPAREN,
    ACTIONS(308), 1,
      anon_sym_RBRACE_RBRACE_RBRACE,
  [1211] = 2,
    ACTIONS(310), 1,
      anon_sym_RBRACK_LBRACK,
    ACTIONS(312), 1,
      anon_sym_RBRACK_RBRACK,
  [1218] = 2,
    ACTIONS(314), 1,
      sym_block_content,
    ACTIONS(316), 1,
      aux_sym_block_end_token1,
  [1225] = 2,
    ACTIONS(318), 1,
      anon_sym_LF,
    ACTIONS(320), 1,
      aux_sym_list_item_token2,
  [1232] = 2,
    ACTIONS(322), 1,
      anon_sym_SPACE,
    ACTIONS(324), 1,
      anon_sym_LF,
  [1239] = 2,
    ACTIONS(326), 1,
      sym_block_content,
    ACTIONS(328), 1,
      aux_sym_block_end_token1,
  [1246] = 2,
    ACTIONS(330), 1,
      aux_sym_title_token1,
    ACTIONS(332), 1,
      aux_sym_list_item_token1,
  [1253] = 2,
    ACTIONS(334), 1,
      aux_sym_list_item_token2,
    ACTIONS(336), 1,
      sym_block_type,
  [1260] = 2,
    ACTIONS(338), 1,
      aux_sym_block_end_token1,
    STATE(36), 1,
      sym_block_end,
  [1267] = 1,
    ACTIONS(340), 1,
      anon_sym_LF,
  [1271] = 1,
    ACTIONS(342), 1,
      anon_sym_LF,
  [1275] = 1,
    ACTIONS(344), 1,
      sym_language,
  [1279] = 1,
    ACTIONS(346), 1,
      aux_sym_property_drawer_token1,
  [1283] = 1,
    ACTIONS(348), 1,
      anon_sym_SPACE,
  [1287] = 1,
    ACTIONS(350), 1,
      anon_sym_SPACE,
  [1291] = 1,
    ACTIONS(352), 1,
      anon_sym_LF,
  [1295] = 1,
    ACTIONS(354), 1,
      aux_sym_list_item_token2,
  [1299] = 1,
    ACTIONS(356), 1,
      anon_sym_SPACE,
  [1303] = 1,
    ACTIONS(358), 1,
      anon_sym_RPAREN,
  [1307] = 1,
    ACTIONS(360), 1,
      anon_sym_LF,
  [1311] = 1,
    ACTIONS(362), 1,
      anon_sym_RBRACK_RBRACK,
  [1315] = 1,
    ACTIONS(364), 1,
      anon_sym_LF,
  [1319] = 1,
    ACTIONS(366), 1,
      anon_sym_LF,
  [1323] = 1,
    ACTIONS(368), 1,
      anon_sym_COLON,
  [1327] = 1,
    ACTIONS(370), 1,
      anon_sym_LF,
  [1331] = 1,
    ACTIONS(372), 1,
      aux_sym_title_token1,
  [1335] = 1,
    ACTIONS(374), 1,
      anon_sym_LF,
  [1339] = 1,
    ACTIONS(376), 1,
      anon_sym_COLON,
  [1343] = 1,
    ACTIONS(378), 1,
      anon_sym_COLON,
  [1347] = 1,
    ACTIONS(380), 1,
      anon_sym_LF,
  [1351] = 1,
    ACTIONS(382), 1,
      anon_sym_PIPE,
  [1355] = 1,
    ACTIONS(384), 1,
      anon_sym_SPACE,
  [1359] = 1,
    ACTIONS(386), 1,
      anon_sym_LF,
  [1363] = 1,
    ACTIONS(388), 1,
      anon_sym_LF,
  [1367] = 1,
    ACTIONS(390), 1,
      anon_sym_RBRACE_RBRACE_RBRACE,
  [1371] = 1,
    ACTIONS(392), 1,
      anon_sym_LF,
  [1375] = 1,
    ACTIONS(394), 1,
      aux_sym_list_item_token2,
  [1379] = 1,
    ACTIONS(396), 1,
      anon_sym_LF,
  [1383] = 1,
    ACTIONS(398), 1,
      anon_sym_LF,
  [1387] = 1,
    ACTIONS(400), 1,
      anon_sym_SPACE,
  [1391] = 1,
    ACTIONS(402), 1,
      anon_sym_LF,
  [1395] = 1,
    ACTIONS(404), 1,
      aux_sym_list_item_token2,
  [1399] = 1,
    ACTIONS(406), 1,
      anon_sym_COLON,
  [1403] = 1,
    ACTIONS(408), 1,
      anon_sym_COLON,
  [1407] = 1,
    ACTIONS(410), 1,
      aux_sym_property_drawer_token1,
  [1411] = 1,
    ACTIONS(412), 1,
      anon_sym_LF,
  [1415] = 1,
    ACTIONS(414), 1,
      ts_builtin_sym_end,
  [1419] = 1,
    ACTIONS(416), 1,
      aux_sym_paragraph_token2,
  [1423] = 1,
    ACTIONS(418), 1,
      aux_sym_property_drawer_token1,
  [1427] = 1,
    ACTIONS(420), 1,
      aux_sym_list_item_token2,
  [1431] = 1,
    ACTIONS(422), 1,
      anon_sym_LF,
  [1435] = 1,
    ACTIONS(424), 1,
      aux_sym_list_item_token2,
  [1439] = 1,
    ACTIONS(426), 1,
      aux_sym_link_token1,
  [1443] = 1,
    ACTIONS(428), 1,
      anon_sym_LF,
  [1447] = 1,
    ACTIONS(430), 1,
      aux_sym_property_drawer_token1,
  [1451] = 1,
    ACTIONS(432), 1,
      anon_sym_COLONend_COLON,
  [1455] = 1,
    ACTIONS(434), 1,
      aux_sym_property_drawer_token1,
  [1459] = 1,
    ACTIONS(436), 1,
      anon_sym_LF,
  [1463] = 1,
    ACTIONS(438), 1,
      sym_name,
  [1467] = 1,
    ACTIONS(440), 1,
      anon_sym_LF,
  [1471] = 1,
    ACTIONS(442), 1,
      sym_block_type,
  [1475] = 1,
    ACTIONS(444), 1,
      anon_sym_LF,
  [1479] = 1,
    ACTIONS(446), 1,
      aux_sym_property_drawer_token1,
  [1483] = 1,
    ACTIONS(448), 1,
      aux_sym_macro_token2,
  [1487] = 1,
    ACTIONS(450), 1,
      anon_sym_SPACE,
  [1491] = 1,
    ACTIONS(452), 1,
      sym_bullet,
  [1495] = 1,
    ACTIONS(454), 1,
      aux_sym_link_token1,
  [1499] = 1,
    ACTIONS(456), 1,
      anon_sym_LF,
  [1503] = 1,
    ACTIONS(458), 1,
      anon_sym_LF,
  [1507] = 1,
    ACTIONS(460), 1,
      anon_sym_LF,
  [1511] = 1,
    ACTIONS(462), 1,
      aux_sym_macro_token1,
  [1515] = 1,
    ACTIONS(464), 1,
      anon_sym_LF,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(4)] = 0,
  [SMALL_STATE(5)] = 37,
  [SMALL_STATE(6)] = 74,
  [SMALL_STATE(7)] = 111,
  [SMALL_STATE(8)] = 148,
  [SMALL_STATE(9)] = 182,
  [SMALL_STATE(10)] = 216,
  [SMALL_STATE(11)] = 245,
  [SMALL_STATE(12)] = 274,
  [SMALL_STATE(13)] = 303,
  [SMALL_STATE(14)] = 332,
  [SMALL_STATE(15)] = 361,
  [SMALL_STATE(16)] = 390,
  [SMALL_STATE(17)] = 419,
  [SMALL_STATE(18)] = 448,
  [SMALL_STATE(19)] = 477,
  [SMALL_STATE(20)] = 506,
  [SMALL_STATE(21)] = 535,
  [SMALL_STATE(22)] = 564,
  [SMALL_STATE(23)] = 593,
  [SMALL_STATE(24)] = 622,
  [SMALL_STATE(25)] = 651,
  [SMALL_STATE(26)] = 680,
  [SMALL_STATE(27)] = 709,
  [SMALL_STATE(28)] = 738,
  [SMALL_STATE(29)] = 767,
  [SMALL_STATE(30)] = 796,
  [SMALL_STATE(31)] = 825,
  [SMALL_STATE(32)] = 854,
  [SMALL_STATE(33)] = 883,
  [SMALL_STATE(34)] = 912,
  [SMALL_STATE(35)] = 941,
  [SMALL_STATE(36)] = 970,
  [SMALL_STATE(37)] = 999,
  [SMALL_STATE(38)] = 1028,
  [SMALL_STATE(39)] = 1044,
  [SMALL_STATE(40)] = 1055,
  [SMALL_STATE(41)] = 1068,
  [SMALL_STATE(42)] = 1081,
  [SMALL_STATE(43)] = 1092,
  [SMALL_STATE(44)] = 1105,
  [SMALL_STATE(45)] = 1118,
  [SMALL_STATE(46)] = 1128,
  [SMALL_STATE(47)] = 1136,
  [SMALL_STATE(48)] = 1146,
  [SMALL_STATE(49)] = 1152,
  [SMALL_STATE(50)] = 1162,
  [SMALL_STATE(51)] = 1169,
  [SMALL_STATE(52)] = 1176,
  [SMALL_STATE(53)] = 1183,
  [SMALL_STATE(54)] = 1190,
  [SMALL_STATE(55)] = 1197,
  [SMALL_STATE(56)] = 1204,
  [SMALL_STATE(57)] = 1211,
  [SMALL_STATE(58)] = 1218,
  [SMALL_STATE(59)] = 1225,
  [SMALL_STATE(60)] = 1232,
  [SMALL_STATE(61)] = 1239,
  [SMALL_STATE(62)] = 1246,
  [SMALL_STATE(63)] = 1253,
  [SMALL_STATE(64)] = 1260,
  [SMALL_STATE(65)] = 1267,
  [SMALL_STATE(66)] = 1271,
  [SMALL_STATE(67)] = 1275,
  [SMALL_STATE(68)] = 1279,
  [SMALL_STATE(69)] = 1283,
  [SMALL_STATE(70)] = 1287,
  [SMALL_STATE(71)] = 1291,
  [SMALL_STATE(72)] = 1295,
  [SMALL_STATE(73)] = 1299,
  [SMALL_STATE(74)] = 1303,
  [SMALL_STATE(75)] = 1307,
  [SMALL_STATE(76)] = 1311,
  [SMALL_STATE(77)] = 1315,
  [SMALL_STATE(78)] = 1319,
  [SMALL_STATE(79)] = 1323,
  [SMALL_STATE(80)] = 1327,
  [SMALL_STATE(81)] = 1331,
  [SMALL_STATE(82)] = 1335,
  [SMALL_STATE(83)] = 1339,
  [SMALL_STATE(84)] = 1343,
  [SMALL_STATE(85)] = 1347,
  [SMALL_STATE(86)] = 1351,
  [SMALL_STATE(87)] = 1355,
  [SMALL_STATE(88)] = 1359,
  [SMALL_STATE(89)] = 1363,
  [SMALL_STATE(90)] = 1367,
  [SMALL_STATE(91)] = 1371,
  [SMALL_STATE(92)] = 1375,
  [SMALL_STATE(93)] = 1379,
  [SMALL_STATE(94)] = 1383,
  [SMALL_STATE(95)] = 1387,
  [SMALL_STATE(96)] = 1391,
  [SMALL_STATE(97)] = 1395,
  [SMALL_STATE(98)] = 1399,
  [SMALL_STATE(99)] = 1403,
  [SMALL_STATE(100)] = 1407,
  [SMALL_STATE(101)] = 1411,
  [SMALL_STATE(102)] = 1415,
  [SMALL_STATE(103)] = 1419,
  [SMALL_STATE(104)] = 1423,
  [SMALL_STATE(105)] = 1427,
  [SMALL_STATE(106)] = 1431,
  [SMALL_STATE(107)] = 1435,
  [SMALL_STATE(108)] = 1439,
  [SMALL_STATE(109)] = 1443,
  [SMALL_STATE(110)] = 1447,
  [SMALL_STATE(111)] = 1451,
  [SMALL_STATE(112)] = 1455,
  [SMALL_STATE(113)] = 1459,
  [SMALL_STATE(114)] = 1463,
  [SMALL_STATE(115)] = 1467,
  [SMALL_STATE(116)] = 1471,
  [SMALL_STATE(117)] = 1475,
  [SMALL_STATE(118)] = 1479,
  [SMALL_STATE(119)] = 1483,
  [SMALL_STATE(120)] = 1487,
  [SMALL_STATE(121)] = 1491,
  [SMALL_STATE(122)] = 1495,
  [SMALL_STATE(123)] = 1499,
  [SMALL_STATE(124)] = 1503,
  [SMALL_STATE(125)] = 1507,
  [SMALL_STATE(126)] = 1511,
  [SMALL_STATE(127)] = 1515,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_document, 0, 0, 0),
  [5] = {.entry = {.count = 1, .reusable = false}}, SHIFT(69),
  [7] = {.entry = {.count = 1, .reusable = false}}, SHIFT(3),
  [9] = {.entry = {.count = 1, .reusable = false}}, SHIFT(126),
  [11] = {.entry = {.count = 1, .reusable = false}}, SHIFT(122),
  [13] = {.entry = {.count = 1, .reusable = false}}, SHIFT(121),
  [15] = {.entry = {.count = 1, .reusable = false}}, SHIFT(120),
  [17] = {.entry = {.count = 1, .reusable = false}}, SHIFT(116),
  [19] = {.entry = {.count = 1, .reusable = false}}, SHIFT(41),
  [21] = {.entry = {.count = 1, .reusable = false}}, SHIFT(7),
  [23] = {.entry = {.count = 1, .reusable = false}}, SHIFT(114),
  [25] = {.entry = {.count = 1, .reusable = false}}, SHIFT(54),
  [27] = {.entry = {.count = 1, .reusable = false}}, SHIFT(107),
  [29] = {.entry = {.count = 1, .reusable = false}}, SHIFT(105),
  [31] = {.entry = {.count = 1, .reusable = false}}, SHIFT(104),
  [33] = {.entry = {.count = 1, .reusable = false}}, SHIFT(103),
  [35] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0),
  [37] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(69),
  [40] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(2),
  [43] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(126),
  [46] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(122),
  [49] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(121),
  [52] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(120),
  [55] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(116),
  [58] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(41),
  [61] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(7),
  [64] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(114),
  [67] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(54),
  [70] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(107),
  [73] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(105),
  [76] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(104),
  [79] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(103),
  [82] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_document, 1, 0, 0),
  [84] = {.entry = {.count = 1, .reusable = false}}, SHIFT(2),
  [86] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_table_repeat1, 2, 0, 0),
  [88] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_table_repeat1, 2, 0, 0),
  [90] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_table_repeat1, 2, 0, 0), SHIFT_REPEAT(41),
  [93] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_table_repeat1, 2, 0, 0), SHIFT_REPEAT(4),
  [96] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_list_repeat1, 2, 0, 0),
  [98] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_list_repeat1, 2, 0, 0),
  [100] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_list_repeat1, 2, 0, 0), SHIFT_REPEAT(121),
  [103] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_list_repeat1, 2, 0, 0), SHIFT_REPEAT(120),
  [106] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_list, 1, 0, 0),
  [108] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_list, 1, 0, 0),
  [110] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_table, 1, 0, 0),
  [112] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_table, 1, 0, 0),
  [114] = {.entry = {.count = 1, .reusable = false}}, SHIFT(4),
  [116] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_fixed_width, 1, 0, 0),
  [118] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_fixed_width, 1, 0, 0),
  [120] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_fixed_width_repeat1, 2, 0, 0),
  [122] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_fixed_width_repeat1, 2, 0, 0),
  [124] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_fixed_width_repeat1, 2, 0, 0), SHIFT_REPEAT(105),
  [127] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_list_item, 5, 0, 0),
  [129] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_list_item, 5, 0, 0),
  [131] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_headline, 5, 0, 4),
  [133] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_headline, 5, 0, 4),
  [135] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_headline, 7, 0, 11),
  [137] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_headline, 7, 0, 11),
  [139] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_table_row, 3, 0, 0),
  [141] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_table_row, 3, 0, 0),
  [143] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_directive, 6, 0, 10),
  [145] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_directive, 6, 0, 10),
  [147] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_link, 6, 0, 9),
  [149] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_link, 6, 0, 9),
  [151] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_headline, 6, 0, 8),
  [153] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_headline, 6, 0, 8),
  [155] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_headline, 6, 0, 7),
  [157] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_headline, 6, 0, 7),
  [159] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_fixed_width_repeat1, 3, 0, 0),
  [161] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_fixed_width_repeat1, 3, 0, 0),
  [163] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_block_end, 4, 0, 0),
  [165] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_block_end, 4, 0, 0),
  [167] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_macro, 7, 0, 0),
  [169] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_macro, 7, 0, 0),
  [171] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_headline, 3, 0, 0),
  [173] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_headline, 3, 0, 0),
  [175] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_drawer, 9, 0, 0),
  [177] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_drawer, 9, 0, 0),
  [179] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_directive, 5, 0, 6),
  [181] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_directive, 5, 0, 6),
  [183] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_comment, 3, 0, 0),
  [185] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_comment, 3, 0, 0),
  [187] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_property_drawer, 7, 0, 0),
  [189] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_property_drawer, 7, 0, 0),
  [191] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_headline, 5, 0, 3),
  [193] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_headline, 5, 0, 3),
  [195] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_table_row, 2, 0, 0),
  [197] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_table_row, 2, 0, 0),
  [199] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_block_end, 3, 0, 0),
  [201] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_block_end, 3, 0, 0),
  [203] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_drawer, 8, 0, 0),
  [205] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_drawer, 8, 0, 0),
  [207] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_headline, 8, 0, 12),
  [209] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_headline, 8, 0, 12),
  [211] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_list_item, 4, 0, 0),
  [213] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_list_item, 4, 0, 0),
  [215] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_link, 4, 0, 0),
  [217] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_link, 4, 0, 0),
  [219] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_macro, 4, 0, 0),
  [221] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_macro, 4, 0, 0),
  [223] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_headline, 4, 0, 2),
  [225] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_headline, 4, 0, 2),
  [227] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_paragraph, 2, 0, 0),
  [229] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_paragraph, 2, 0, 0),
  [231] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_block, 3, 0, 0),
  [233] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_block, 3, 0, 0),
  [235] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_block, 2, 0, 0),
  [237] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_block, 2, 0, 0),
  [239] = {.entry = {.count = 1, .reusable = false}}, SHIFT(21),
  [241] = {.entry = {.count = 1, .reusable = false}}, SHIFT(70),
  [243] = {.entry = {.count = 1, .reusable = false}}, SHIFT(73),
  [245] = {.entry = {.count = 1, .reusable = false}}, SHIFT(93),
  [247] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_property_drawer_repeat1, 2, 0, 0), SHIFT_REPEAT(51),
  [250] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_property_drawer_repeat1, 2, 0, 0),
  [252] = {.entry = {.count = 1, .reusable = false}}, SHIFT(26),
  [254] = {.entry = {.count = 1, .reusable = false}}, SHIFT(87),
  [256] = {.entry = {.count = 1, .reusable = false}}, SHIFT(27),
  [258] = {.entry = {.count = 1, .reusable = false}}, SHIFT(43),
  [260] = {.entry = {.count = 1, .reusable = false}}, SHIFT(86),
  [262] = {.entry = {.count = 1, .reusable = false}}, SHIFT(51),
  [264] = {.entry = {.count = 1, .reusable = true}}, SHIFT(100),
  [266] = {.entry = {.count = 1, .reusable = false}}, SHIFT(13),
  [268] = {.entry = {.count = 1, .reusable = false}}, SHIFT(44),
  [270] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_table_row_repeat1, 2, 0, 0),
  [272] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_table_row_repeat1, 2, 0, 0), SHIFT_REPEAT(44),
  [275] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_table_row_repeat1, 2, 0, 0), SHIFT_REPEAT(86),
  [278] = {.entry = {.count = 1, .reusable = false}}, SHIFT(11),
  [280] = {.entry = {.count = 1, .reusable = true}}, SHIFT(51),
  [282] = {.entry = {.count = 1, .reusable = true}}, SHIFT(64),
  [284] = {.entry = {.count = 1, .reusable = false}}, SHIFT(63),
  [286] = {.entry = {.count = 1, .reusable = false}}, SHIFT(12),
  [288] = {.entry = {.count = 1, .reusable = false}}, SHIFT(110),
  [290] = {.entry = {.count = 1, .reusable = true}}, SHIFT(111),
  [292] = {.entry = {.count = 1, .reusable = true}}, SHIFT(98),
  [294] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_property, 6, 0, 0),
  [296] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_property, 6, 0, 0),
  [298] = {.entry = {.count = 1, .reusable = true}}, SHIFT(124),
  [300] = {.entry = {.count = 1, .reusable = true}}, SHIFT(83),
  [302] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_block_begin, 6, 0, 5),
  [304] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_block_begin, 6, 0, 5),
  [306] = {.entry = {.count = 1, .reusable = true}}, SHIFT(119),
  [308] = {.entry = {.count = 1, .reusable = true}}, SHIFT(109),
  [310] = {.entry = {.count = 1, .reusable = true}}, SHIFT(108),
  [312] = {.entry = {.count = 1, .reusable = true}}, SHIFT(101),
  [314] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_block_begin, 5, 0, 5),
  [316] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_block_begin, 5, 0, 5),
  [318] = {.entry = {.count = 1, .reusable = false}}, SHIFT(58),
  [320] = {.entry = {.count = 1, .reusable = false}}, SHIFT(94),
  [322] = {.entry = {.count = 1, .reusable = false}}, SHIFT(67),
  [324] = {.entry = {.count = 1, .reusable = false}}, SHIFT(61),
  [326] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_block_begin, 3, 0, 1),
  [328] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_block_begin, 3, 0, 1),
  [330] = {.entry = {.count = 1, .reusable = false}}, SHIFT(80),
  [332] = {.entry = {.count = 1, .reusable = false}}, SHIFT(81),
  [334] = {.entry = {.count = 1, .reusable = true}}, SHIFT(71),
  [336] = {.entry = {.count = 1, .reusable = false}}, SHIFT(72),
  [338] = {.entry = {.count = 1, .reusable = true}}, SHIFT(63),
  [340] = {.entry = {.count = 1, .reusable = true}}, SHIFT(46),
  [342] = {.entry = {.count = 1, .reusable = true}}, SHIFT(14),
  [344] = {.entry = {.count = 1, .reusable = true}}, SHIFT(59),
  [346] = {.entry = {.count = 1, .reusable = true}}, SHIFT(82),
  [348] = {.entry = {.count = 1, .reusable = true}}, SHIFT(38),
  [350] = {.entry = {.count = 1, .reusable = true}}, SHIFT(40),
  [352] = {.entry = {.count = 1, .reusable = true}}, SHIFT(28),
  [354] = {.entry = {.count = 1, .reusable = true}}, SHIFT(85),
  [356] = {.entry = {.count = 1, .reusable = true}}, SHIFT(45),
  [358] = {.entry = {.count = 1, .reusable = true}}, SHIFT(90),
  [360] = {.entry = {.count = 1, .reusable = true}}, SHIFT(18),
  [362] = {.entry = {.count = 1, .reusable = true}}, SHIFT(91),
  [364] = {.entry = {.count = 1, .reusable = true}}, SHIFT(24),
  [366] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
  [368] = {.entry = {.count = 1, .reusable = true}}, SHIFT(68),
  [370] = {.entry = {.count = 1, .reusable = true}}, SHIFT(23),
  [372] = {.entry = {.count = 1, .reusable = true}}, SHIFT(66),
  [374] = {.entry = {.count = 1, .reusable = true}}, SHIFT(50),
  [376] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_drawer_name, 1, 0, 0),
  [378] = {.entry = {.count = 1, .reusable = true}}, SHIFT(62),
  [380] = {.entry = {.count = 1, .reusable = true}}, SHIFT(19),
  [382] = {.entry = {.count = 1, .reusable = true}}, SHIFT(48),
  [384] = {.entry = {.count = 1, .reusable = true}}, SHIFT(49),
  [386] = {.entry = {.count = 1, .reusable = true}}, SHIFT(17),
  [388] = {.entry = {.count = 1, .reusable = true}}, SHIFT(16),
  [390] = {.entry = {.count = 1, .reusable = true}}, SHIFT(106),
  [392] = {.entry = {.count = 1, .reusable = true}}, SHIFT(15),
  [394] = {.entry = {.count = 1, .reusable = true}}, SHIFT(96),
  [396] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_title, 1, 0, 0),
  [398] = {.entry = {.count = 1, .reusable = true}}, SHIFT(55),
  [400] = {.entry = {.count = 1, .reusable = true}}, SHIFT(97),
  [402] = {.entry = {.count = 1, .reusable = true}}, SHIFT(31),
  [404] = {.entry = {.count = 1, .reusable = true}}, SHIFT(78),
  [406] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_key, 1, 0, 0),
  [408] = {.entry = {.count = 1, .reusable = true}}, SHIFT(112),
  [410] = {.entry = {.count = 1, .reusable = true}}, SHIFT(113),
  [412] = {.entry = {.count = 1, .reusable = true}}, SHIFT(32),
  [414] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [416] = {.entry = {.count = 1, .reusable = true}}, SHIFT(35),
  [418] = {.entry = {.count = 1, .reusable = true}}, SHIFT(65),
  [420] = {.entry = {.count = 1, .reusable = true}}, SHIFT(75),
  [422] = {.entry = {.count = 1, .reusable = true}}, SHIFT(20),
  [424] = {.entry = {.count = 1, .reusable = true}}, SHIFT(77),
  [426] = {.entry = {.count = 1, .reusable = true}}, SHIFT(76),
  [428] = {.entry = {.count = 1, .reusable = true}}, SHIFT(33),
  [430] = {.entry = {.count = 1, .reusable = true}}, SHIFT(117),
  [432] = {.entry = {.count = 1, .reusable = true}}, SHIFT(118),
  [434] = {.entry = {.count = 1, .reusable = true}}, SHIFT(53),
  [436] = {.entry = {.count = 1, .reusable = true}}, SHIFT(25),
  [438] = {.entry = {.count = 1, .reusable = true}}, SHIFT(84),
  [440] = {.entry = {.count = 1, .reusable = true}}, SHIFT(30),
  [442] = {.entry = {.count = 1, .reusable = true}}, SHIFT(60),
  [444] = {.entry = {.count = 1, .reusable = true}}, SHIFT(29),
  [446] = {.entry = {.count = 1, .reusable = true}}, SHIFT(123),
  [448] = {.entry = {.count = 1, .reusable = true}}, SHIFT(74),
  [450] = {.entry = {.count = 1, .reusable = true}}, SHIFT(92),
  [452] = {.entry = {.count = 1, .reusable = true}}, SHIFT(95),
  [454] = {.entry = {.count = 1, .reusable = true}}, SHIFT(57),
  [456] = {.entry = {.count = 1, .reusable = true}}, SHIFT(22),
  [458] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_value, 1, 0, 0),
  [460] = {.entry = {.count = 1, .reusable = true}}, SHIFT(52),
  [462] = {.entry = {.count = 1, .reusable = true}}, SHIFT(56),
  [464] = {.entry = {.count = 1, .reusable = true}}, SHIFT(34),
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
