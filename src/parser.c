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
#define STATE_COUNT 138
#define LARGE_STATE_COUNT 4
#define SYMBOL_COUNT 76
#define ALIAS_COUNT 1
#define TOKEN_COUNT 50
#define EXTERNAL_TOKEN_COUNT 2
#define FIELD_COUNT 6
#define MAX_ALIAS_SEQUENCE_LENGTH 9
#define PRODUCTION_ID_COUNT 21

enum ts_symbol_identifiers {
  anon_sym_SPACE = 1,
  anon_sym_LF = 2,
  sym_stars = 3,
  sym_keyword = 4,
  sym_priority = 5,
  sym_planning_line = 6,
  sym_timestamp = 7,
  anon_sym_LBRACE_LBRACE_LBRACE = 8,
  aux_sym_macro_token1 = 9,
  anon_sym_LPAREN = 10,
  aux_sym_macro_token2 = 11,
  anon_sym_RPAREN = 12,
  anon_sym_RBRACE_RBRACE_RBRACE = 13,
  sym_footnote_reference = 14,
  sym_latex_fragment = 15,
  sym_entity = 16,
  sym_subscript = 17,
  sym_superscript = 18,
  anon_sym_LBRACK_LBRACK = 19,
  aux_sym_link_token1 = 20,
  anon_sym_RBRACK_LBRACK = 21,
  anon_sym_RBRACK_RBRACK = 22,
  aux_sym_list_item_token1 = 23,
  aux_sym_list_item_token2 = 24,
  sym_bullet = 25,
  aux_sym_block_begin_token1 = 26,
  sym_block_type = 27,
  sym_language = 28,
  sym_block_content = 29,
  aux_sym_block_end_token1 = 30,
  anon_sym_PIPE = 31,
  sym_table_cell = 32,
  sym_table_separator = 33,
  aux_sym_directive_token1 = 34,
  anon_sym_COLON = 35,
  aux_sym_directive_token2 = 36,
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
  sym_HEADLINE_TITLE = 48,
  sym_HEADLINE_TAGS = 49,
  sym_document = 50,
  sym__element = 51,
  sym_headline = 52,
  sym_macro = 53,
  sym_link = 54,
  sym_list = 55,
  sym_list_item = 56,
  sym_block = 57,
  sym_block_begin = 58,
  sym_block_end = 59,
  sym_table = 60,
  sym_table_row = 61,
  sym_directive = 62,
  sym_comment = 63,
  sym_property_drawer = 64,
  sym_property = 65,
  sym_key = 66,
  sym_value = 67,
  sym_drawer = 68,
  sym_drawer_name = 69,
  sym_paragraph = 70,
  aux_sym_document_repeat1 = 71,
  aux_sym_list_repeat1 = 72,
  aux_sym_table_repeat1 = 73,
  aux_sym_table_row_repeat1 = 74,
  aux_sym_property_drawer_repeat1 = 75,
  alias_sym_link_description = 76,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [anon_sym_SPACE] = " ",
  [anon_sym_LF] = "\n",
  [sym_stars] = "stars",
  [sym_keyword] = "keyword",
  [sym_priority] = "priority",
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
  [aux_sym_directive_token2] = "directive_token2",
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
  [sym_HEADLINE_TITLE] = "title",
  [sym_HEADLINE_TAGS] = "tags",
  [sym_document] = "document",
  [sym__element] = "_element",
  [sym_headline] = "headline",
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
  [aux_sym_directive_token2] = aux_sym_directive_token2,
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
  [sym_HEADLINE_TITLE] = sym_HEADLINE_TITLE,
  [sym_HEADLINE_TAGS] = sym_HEADLINE_TAGS,
  [sym_document] = sym_document,
  [sym__element] = sym__element,
  [sym_headline] = sym_headline,
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
  [aux_sym_directive_token2] = {
    .visible = false,
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
  [sym_HEADLINE_TITLE] = {
    .visible = true,
    .named = true,
  },
  [sym_HEADLINE_TAGS] = {
    .visible = true,
    .named = true,
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
  field_tags = 4,
  field_title = 5,
  field_type = 6,
};

static const char * const ts_field_names[] = {
  [0] = NULL,
  [field_keyword] = "keyword",
  [field_language] = "language",
  [field_priority] = "priority",
  [field_tags] = "tags",
  [field_title] = "title",
  [field_type] = "type",
};

static const TSFieldMapSlice ts_field_map_slices[PRODUCTION_ID_COUNT] = {
  [1] = {.index = 0, .length = 1},
  [2] = {.index = 1, .length = 1},
  [3] = {.index = 2, .length = 1},
  [4] = {.index = 3, .length = 2},
  [5] = {.index = 5, .length = 1},
  [6] = {.index = 6, .length = 1},
  [7] = {.index = 7, .length = 2},
  [9] = {.index = 9, .length = 2},
  [10] = {.index = 11, .length = 2},
  [11] = {.index = 13, .length = 2},
  [12] = {.index = 15, .length = 2},
  [15] = {.index = 17, .length = 3},
  [16] = {.index = 20, .length = 2},
  [17] = {.index = 22, .length = 3},
  [18] = {.index = 25, .length = 3},
  [19] = {.index = 28, .length = 3},
  [20] = {.index = 31, .length = 4},
};

static const TSFieldMapEntry ts_field_map_entries[] = {
  [0] =
    {field_type, 1},
  [1] =
    {field_title, 2},
  [2] =
    {field_tags, 2},
  [3] =
    {field_tags, 3},
    {field_title, 2},
  [5] =
    {field_keyword, 2},
  [6] =
    {field_priority, 2},
  [7] =
    {field_language, 3},
    {field_type, 1},
  [9] =
    {field_keyword, 2},
    {field_title, 4},
  [11] =
    {field_keyword, 2},
    {field_tags, 4},
  [13] =
    {field_priority, 2},
    {field_title, 4},
  [15] =
    {field_priority, 2},
    {field_tags, 4},
  [17] =
    {field_keyword, 2},
    {field_tags, 5},
    {field_title, 4},
  [20] =
    {field_keyword, 2},
    {field_priority, 4},
  [22] =
    {field_priority, 2},
    {field_tags, 5},
    {field_title, 4},
  [25] =
    {field_keyword, 2},
    {field_priority, 4},
    {field_title, 6},
  [28] =
    {field_keyword, 2},
    {field_priority, 4},
    {field_tags, 6},
  [31] =
    {field_keyword, 2},
    {field_priority, 4},
    {field_tags, 7},
    {field_title, 6},
};

static const TSSymbol ts_alias_sequences[PRODUCTION_ID_COUNT][MAX_ALIAS_SEQUENCE_LENGTH] = {
  [0] = {0},
  [8] = {
    [3] = sym_value,
  },
  [13] = {
    [3] = alias_sym_link_description,
  },
  [14] = {
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
  [128] = 128,
  [129] = 129,
  [130] = 130,
  [131] = 131,
  [132] = 132,
  [133] = 133,
  [134] = 134,
  [135] = 135,
  [136] = 136,
  [137] = 137,
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(137);
      ADVANCE_MAP(
        '#', 20,
        '$', 26,
        '(', 179,
        ')', 182,
        '*', 146,
        '-', 37,
        ':', 223,
        '<', 129,
        'C', 154,
        'D', 172,
        'N', 159,
        'T', 170,
        'W', 155,
        '[', 23,
        '\\', 128,
        ']', 86,
        '_', 207,
        '{', 101,
        '|', 214,
        '}', 103,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(0);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(176);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(177);
      END_STATE();
    case 1:
      if (lookahead == '\n') ADVANCE(186);
      END_STATE();
    case 2:
      if (lookahead == '\n') ADVANCE(186);
      if (lookahead == '{') ADVANCE(104);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(2);
      END_STATE();
    case 3:
      if (lookahead == '\n') ADVANCE(218);
      if (lookahead == '+') ADVANCE(33);
      if (lookahead == '-') ADVANCE(3);
      if (lookahead == '|') ADVANCE(4);
      END_STATE();
    case 4:
      if (lookahead == '\n') ADVANCE(218);
      if (lookahead == '-') ADVANCE(3);
      END_STATE();
    case 5:
      if (lookahead == '\n') ADVANCE(185);
      END_STATE();
    case 6:
      if (lookahead == '\n') ADVANCE(151);
      END_STATE();
    case 7:
      if (lookahead == '\n') ADVANCE(240);
      if (lookahead == '-') ADVANCE(7);
      END_STATE();
    case 8:
      if (lookahead == '\n') ADVANCE(184);
      END_STATE();
    case 9:
      if (lookahead == '\n') ADVANCE(188);
      if (lookahead != 0) ADVANCE(9);
      END_STATE();
    case 10:
      if (lookahead == '\n') ADVANCE(187);
      if (lookahead != 0) ADVANCE(10);
      END_STATE();
    case 11:
      if (lookahead == '\n') ADVANCE(140);
      if (lookahead == 'C') ADVANCE(49);
      if (lookahead == 'D') ADVANCE(76);
      if (lookahead == 'N') ADVANCE(58);
      if (lookahead == 'T') ADVANCE(75);
      if (lookahead == 'W') ADVANCE(50);
      if (lookahead == '[') ADVANCE(22);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(11);
      END_STATE();
    case 12:
      if (lookahead == '\n') ADVANCE(141);
      if (lookahead == '|') ADVANCE(213);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(216);
      if (lookahead != 0) ADVANCE(217);
      END_STATE();
    case 13:
      if (lookahead == '\n') ADVANCE(142);
      if (lookahead == '[') ADVANCE(22);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(13);
      END_STATE();
    case 14:
      if (lookahead == '\n') ADVANCE(143);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(14);
      END_STATE();
    case 15:
      if (lookahead == '\n') SKIP(15);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(196);
      if ((0x0b <= lookahead && lookahead <= '\r')) ADVANCE(226);
      if (lookahead != 0) ADVANCE(228);
      END_STATE();
    case 16:
      if (lookahead == '\n') SKIP(16);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(227);
      if (lookahead != 0) ADVANCE(228);
      END_STATE();
    case 17:
      if (lookahead == '\n') ADVANCE(144);
      if (lookahead == ' ') ADVANCE(138);
      if (('\t' <= lookahead && lookahead <= '\r')) SKIP(17);
      END_STATE();
    case 18:
      if (lookahead == '\n') ADVANCE(323);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(18);
      END_STATE();
    case 19:
      if (lookahead == '\n') SKIP(19);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(191);
      if (lookahead != 0 &&
          lookahead != ']') ADVANCE(192);
      END_STATE();
    case 20:
      if (lookahead == ' ') ADVANCE(230);
      if (lookahead == '+') ADVANCE(219);
      END_STATE();
    case 21:
      if (lookahead == ' ') ADVANCE(139);
      if (('\t' <= lookahead && lookahead <= '\r')) SKIP(21);
      END_STATE();
    case 22:
      if (lookahead == '#') ADVANCE(127);
      END_STATE();
    case 23:
      if (lookahead == '#') ADVANCE(127);
      if (lookahead == '[') ADVANCE(189);
      if (lookahead == 'f') ADVANCE(98);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(88);
      END_STATE();
    case 24:
      if (lookahead == '#') ADVANCE(31);
      if (lookahead == ':') ADVANCE(222);
      if (lookahead == '|') ADVANCE(213);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(24);
      if (lookahead == '-' ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(236);
      END_STATE();
    case 25:
      if (lookahead == '#') ADVANCE(30);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(210);
      if (lookahead != 0) ADVANCE(211);
      END_STATE();
    case 26:
      if (lookahead == '$') ADVANCE(132);
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
      if (lookahead == '+') ADVANCE(113);
      if (lookahead != 0) ADVANCE(211);
      END_STATE();
    case 31:
      if (lookahead == '+') ADVANCE(114);
      END_STATE();
    case 32:
      if (lookahead == '+') ADVANCE(116);
      if (lookahead != 0) ADVANCE(211);
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
      if (lookahead == ':') ADVANCE(235);
      END_STATE();
    case 40:
      if (lookahead == ':') ADVANCE(134);
      if (lookahead == ']') ADVANCE(8);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(40);
      END_STATE();
    case 41:
      if (lookahead == ':') ADVANCE(134);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(40);
      END_STATE();
    case 42:
      if (lookahead == ':') ADVANCE(232);
      END_STATE();
    case 43:
      if (lookahead == ':') ADVANCE(221);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(43);
      if (lookahead == '+' ||
          lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(209);
      END_STATE();
    case 44:
      if (lookahead == ':') ADVANCE(61);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(238);
      if (lookahead != 0) ADVANCE(239);
      END_STATE();
    case 45:
      if (lookahead == ':') ADVANCE(237);
      END_STATE();
    case 46:
      if (lookahead == ':') ADVANCE(237);
      if (lookahead != 0) ADVANCE(239);
      END_STATE();
    case 47:
      if (lookahead == ':') ADVANCE(97);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(47);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(229);
      END_STATE();
    case 48:
      if (lookahead == '>') ADVANCE(6);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(48);
      END_STATE();
    case 49:
      if (lookahead == 'A') ADVANCE(69);
      END_STATE();
    case 50:
      if (lookahead == 'A') ADVANCE(66);
      END_STATE();
    case 51:
      if (lookahead == 'C') ADVANCE(59);
      END_STATE();
    case 52:
      if (lookahead == 'D') ADVANCE(148);
      END_STATE();
    case 53:
      if (lookahead == 'D') ADVANCE(133);
      if (lookahead == 'd') ADVANCE(46);
      if (lookahead != 0) ADVANCE(239);
      END_STATE();
    case 54:
      if (lookahead == 'D') ADVANCE(39);
      END_STATE();
    case 55:
      if (lookahead == 'D') ADVANCE(74);
      END_STATE();
    case 56:
      if (lookahead == 'E') ADVANCE(148);
      END_STATE();
    case 57:
      if (lookahead == 'E') ADVANCE(80);
      END_STATE();
    case 58:
      if (lookahead == 'E') ADVANCE(84);
      END_STATE();
    case 59:
      if (lookahead == 'E') ADVANCE(67);
      END_STATE();
    case 60:
      if (lookahead == 'E') ADVANCE(79);
      END_STATE();
    case 61:
      if (lookahead == 'E') ADVANCE(123);
      if (lookahead == 'e') ADVANCE(71);
      if (lookahead != 0) ADVANCE(239);
      END_STATE();
    case 62:
      if (lookahead == 'E') ADVANCE(52);
      END_STATE();
    case 63:
      if (lookahead == 'G') ADVANCE(148);
      END_STATE();
    case 64:
      if (lookahead == 'I') ADVANCE(57);
      END_STATE();
    case 65:
      if (lookahead == 'I') ADVANCE(70);
      END_STATE();
    case 66:
      if (lookahead == 'I') ADVANCE(83);
      END_STATE();
    case 67:
      if (lookahead == 'L') ADVANCE(62);
      END_STATE();
    case 68:
      if (lookahead == 'N') ADVANCE(54);
      END_STATE();
    case 69:
      if (lookahead == 'N') ADVANCE(51);
      END_STATE();
    case 70:
      if (lookahead == 'N') ADVANCE(63);
      END_STATE();
    case 71:
      if (lookahead == 'N') ADVANCE(110);
      if (lookahead == 'n') ADVANCE(53);
      if (lookahead != 0) ADVANCE(239);
      END_STATE();
    case 72:
      if (lookahead == 'N') ADVANCE(56);
      END_STATE();
    case 73:
      if (lookahead == 'O') ADVANCE(77);
      END_STATE();
    case 74:
      if (lookahead == 'O') ADVANCE(148);
      END_STATE();
    case 75:
      if (lookahead == 'O') ADVANCE(55);
      END_STATE();
    case 76:
      if (lookahead == 'O') ADVANCE(72);
      END_STATE();
    case 77:
      if (lookahead == 'P') ADVANCE(60);
      END_STATE();
    case 78:
      if (lookahead == 'R') ADVANCE(73);
      END_STATE();
    case 79:
      if (lookahead == 'R') ADVANCE(82);
      END_STATE();
    case 80:
      if (lookahead == 'S') ADVANCE(42);
      END_STATE();
    case 81:
      if (lookahead == 'T') ADVANCE(148);
      END_STATE();
    case 82:
      if (lookahead == 'T') ADVANCE(64);
      END_STATE();
    case 83:
      if (lookahead == 'T') ADVANCE(65);
      END_STATE();
    case 84:
      if (lookahead == 'X') ADVANCE(81);
      END_STATE();
    case 85:
      if (lookahead == '[') ADVANCE(189);
      if (lookahead == 'f') ADVANCE(98);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(88);
      END_STATE();
    case 86:
      if (lookahead == '[') ADVANCE(193);
      if (lookahead == ']') ADVANCE(194);
      END_STATE();
    case 87:
      if (lookahead == ']') ADVANCE(149);
      END_STATE();
    case 88:
      if (lookahead == ']') ADVANCE(6);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(88);
      END_STATE();
    case 89:
      if (lookahead == ']') ADVANCE(8);
      if (lookahead != 0) ADVANCE(89);
      END_STATE();
    case 90:
      if (lookahead == '^') ADVANCE(130);
      if (lookahead == '_') ADVANCE(131);
      if (lookahead == ')' ||
          lookahead == '.') ADVANCE(201);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(90);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(92);
      END_STATE();
    case 91:
      if (lookahead == '^') ADVANCE(130);
      if (lookahead == '_') ADVANCE(131);
      if (lookahead == ')' ||
          lookahead == '.') ADVANCE(201);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(92);
      END_STATE();
    case 92:
      if (lookahead == '^') ADVANCE(130);
      if (lookahead == '_') ADVANCE(131);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(92);
      END_STATE();
    case 93:
      if (lookahead == '_') ADVANCE(205);
      END_STATE();
    case 94:
      if (lookahead == '_') ADVANCE(212);
      END_STATE();
    case 95:
      if (lookahead == '_') ADVANCE(212);
      if (lookahead != 0) ADVANCE(211);
      END_STATE();
    case 96:
      if (lookahead == 'd') ADVANCE(45);
      END_STATE();
    case 97:
      if (lookahead == 'e') ADVANCE(99);
      END_STATE();
    case 98:
      if (lookahead == 'n') ADVANCE(38);
      END_STATE();
    case 99:
      if (lookahead == 'n') ADVANCE(96);
      END_STATE();
    case 100:
      if (lookahead == '{') ADVANCE(152);
      END_STATE();
    case 101:
      if (lookahead == '{') ADVANCE(100);
      END_STATE();
    case 102:
      if (lookahead == '}') ADVANCE(183);
      END_STATE();
    case 103:
      if (lookahead == '}') ADVANCE(102);
      END_STATE();
    case 104:
      if (lookahead == '}') ADVANCE(1);
      END_STATE();
    case 105:
      if (lookahead == ')' ||
          lookahead == '.') ADVANCE(201);
      END_STATE();
    case 106:
      if (lookahead == ')' ||
          lookahead == '.') ADVANCE(201);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(106);
      END_STATE();
    case 107:
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(201);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(107);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(106);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(105);
      END_STATE();
    case 108:
      if (lookahead == 'D' ||
          lookahead == 'd') ADVANCE(95);
      if (lookahead != 0) ADVANCE(211);
      END_STATE();
    case 109:
      if (lookahead == 'D' ||
          lookahead == 'd') ADVANCE(135);
      if (lookahead != 0) ADVANCE(211);
      END_STATE();
    case 110:
      if (lookahead == 'D' ||
          lookahead == 'd') ADVANCE(133);
      if (lookahead != 0) ADVANCE(239);
      END_STATE();
    case 111:
      if (lookahead == 'D' ||
          lookahead == 'd') ADVANCE(94);
      END_STATE();
    case 112:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(117);
      END_STATE();
    case 113:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(121);
      if (lookahead != 0) ADVANCE(211);
      END_STATE();
    case 114:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(120);
      END_STATE();
    case 115:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(123);
      if (lookahead != 0) ADVANCE(239);
      END_STATE();
    case 116:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(122);
      if (lookahead != 0) ADVANCE(211);
      END_STATE();
    case 117:
      if (lookahead == 'G' ||
          lookahead == 'g') ADVANCE(118);
      END_STATE();
    case 118:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(119);
      END_STATE();
    case 119:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(93);
      END_STATE();
    case 120:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(111);
      END_STATE();
    case 121:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(108);
      if (lookahead != 0) ADVANCE(211);
      END_STATE();
    case 122:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(109);
      if (lookahead != 0) ADVANCE(211);
      END_STATE();
    case 123:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(110);
      if (lookahead != 0) ADVANCE(239);
      END_STATE();
    case 124:
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(124);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(208);
      END_STATE();
    case 125:
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(125);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(178);
      END_STATE();
    case 126:
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(180);
      if (lookahead != 0 &&
          lookahead != ')' &&
          lookahead != '}') ADVANCE(181);
      END_STATE();
    case 127:
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(87);
      END_STATE();
    case 128:
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(2);
      END_STATE();
    case 129:
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '>') ADVANCE(48);
      END_STATE();
    case 130:
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(9);
      END_STATE();
    case 131:
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(10);
      END_STATE();
    case 132:
      if (lookahead != 0 &&
          lookahead != '$') ADVANCE(29);
      END_STATE();
    case 133:
      if (lookahead != 0 &&
          lookahead != ':') ADVANCE(239);
      END_STATE();
    case 134:
      if (lookahead != 0 &&
          lookahead != ']') ADVANCE(89);
      END_STATE();
    case 135:
      if (lookahead != 0 &&
          lookahead != '_') ADVANCE(211);
      END_STATE();
    case 136:
      if (eof) ADVANCE(137);
      if (lookahead == '\n') SKIP(136);
      if (lookahead == '#') ADVANCE(20);
      if (lookahead == '$') ADVANCE(258);
      if (lookahead == '*') ADVANCE(146);
      if (lookahead == '+') ADVANCE(201);
      if (lookahead == '-') ADVANCE(203);
      if (lookahead == ':') ADVANCE(224);
      if (lookahead == '<') ADVANCE(271);
      if (lookahead == 'C') ADVANCE(289);
      if (lookahead == 'D') ADVANCE(280);
      if (lookahead == 'S') ADVANCE(276);
      if (lookahead == '[') ADVANCE(85);
      if (lookahead == '\\') ADVANCE(319);
      if (lookahead == '{') ADVANCE(101);
      if (lookahead == '|') ADVANCE(214);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(195);
      if ((0x0b <= lookahead && lookahead <= '\r')) ADVANCE(257);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(90);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(307);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(91);
      if (lookahead != 0) ADVANCE(320);
      END_STATE();
    case 137:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 138:
      ACCEPT_TOKEN(anon_sym_SPACE);
      if (lookahead == '\n') ADVANCE(144);
      if (lookahead == ' ') ADVANCE(138);
      END_STATE();
    case 139:
      ACCEPT_TOKEN(anon_sym_SPACE);
      if (lookahead == ' ') ADVANCE(139);
      END_STATE();
    case 140:
      ACCEPT_TOKEN(anon_sym_LF);
      if (lookahead == '\n') ADVANCE(140);
      if (lookahead == 'C') ADVANCE(49);
      if (lookahead == 'D') ADVANCE(76);
      if (lookahead == 'N') ADVANCE(58);
      if (lookahead == 'T') ADVANCE(75);
      if (lookahead == 'W') ADVANCE(50);
      if (lookahead == '[') ADVANCE(22);
      END_STATE();
    case 141:
      ACCEPT_TOKEN(anon_sym_LF);
      if (lookahead == '\n') ADVANCE(141);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(216);
      END_STATE();
    case 142:
      ACCEPT_TOKEN(anon_sym_LF);
      if (lookahead == '\n') ADVANCE(142);
      if (lookahead == '[') ADVANCE(22);
      END_STATE();
    case 143:
      ACCEPT_TOKEN(anon_sym_LF);
      if (lookahead == '\n') ADVANCE(143);
      END_STATE();
    case 144:
      ACCEPT_TOKEN(anon_sym_LF);
      if (lookahead == '\n') ADVANCE(144);
      if (lookahead == ' ') ADVANCE(138);
      END_STATE();
    case 145:
      ACCEPT_TOKEN(anon_sym_LF);
      if (lookahead == '\n') ADVANCE(145);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(197);
      END_STATE();
    case 146:
      ACCEPT_TOKEN(sym_stars);
      if (lookahead == '*') ADVANCE(146);
      END_STATE();
    case 147:
      ACCEPT_TOKEN(sym_stars);
      if (lookahead == '*') ADVANCE(147);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(320);
      END_STATE();
    case 148:
      ACCEPT_TOKEN(sym_keyword);
      END_STATE();
    case 149:
      ACCEPT_TOKEN(sym_priority);
      END_STATE();
    case 150:
      ACCEPT_TOKEN(sym_planning_line);
      END_STATE();
    case 151:
      ACCEPT_TOKEN(sym_timestamp);
      END_STATE();
    case 152:
      ACCEPT_TOKEN(anon_sym_LBRACE_LBRACE_LBRACE);
      END_STATE();
    case 153:
      ACCEPT_TOKEN(anon_sym_LBRACE_LBRACE_LBRACE);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(320);
      END_STATE();
    case 154:
      ACCEPT_TOKEN(aux_sym_macro_token1);
      if (lookahead == 'A') ADVANCE(167);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(178);
      if (('B' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(176);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(177);
      END_STATE();
    case 155:
      ACCEPT_TOKEN(aux_sym_macro_token1);
      if (lookahead == 'A') ADVANCE(164);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(178);
      if (('B' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(176);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(177);
      END_STATE();
    case 156:
      ACCEPT_TOKEN(aux_sym_macro_token1);
      if (lookahead == 'C') ADVANCE(161);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(178);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(176);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(177);
      END_STATE();
    case 157:
      ACCEPT_TOKEN(aux_sym_macro_token1);
      if (lookahead == 'D') ADVANCE(148);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(178);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(176);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(177);
      END_STATE();
    case 158:
      ACCEPT_TOKEN(aux_sym_macro_token1);
      if (lookahead == 'D') ADVANCE(171);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(178);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(176);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(177);
      END_STATE();
    case 159:
      ACCEPT_TOKEN(aux_sym_macro_token1);
      if (lookahead == 'E') ADVANCE(175);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(178);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(176);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(177);
      END_STATE();
    case 160:
      ACCEPT_TOKEN(aux_sym_macro_token1);
      if (lookahead == 'E') ADVANCE(148);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(178);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(176);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(177);
      END_STATE();
    case 161:
      ACCEPT_TOKEN(aux_sym_macro_token1);
      if (lookahead == 'E') ADVANCE(166);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(178);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(176);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(177);
      END_STATE();
    case 162:
      ACCEPT_TOKEN(aux_sym_macro_token1);
      if (lookahead == 'E') ADVANCE(157);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(178);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(176);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(177);
      END_STATE();
    case 163:
      ACCEPT_TOKEN(aux_sym_macro_token1);
      if (lookahead == 'G') ADVANCE(148);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(178);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(176);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(177);
      END_STATE();
    case 164:
      ACCEPT_TOKEN(aux_sym_macro_token1);
      if (lookahead == 'I') ADVANCE(174);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(178);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(176);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(177);
      END_STATE();
    case 165:
      ACCEPT_TOKEN(aux_sym_macro_token1);
      if (lookahead == 'I') ADVANCE(168);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(178);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(176);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(177);
      END_STATE();
    case 166:
      ACCEPT_TOKEN(aux_sym_macro_token1);
      if (lookahead == 'L') ADVANCE(162);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(178);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(176);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(177);
      END_STATE();
    case 167:
      ACCEPT_TOKEN(aux_sym_macro_token1);
      if (lookahead == 'N') ADVANCE(156);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(178);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(176);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(177);
      END_STATE();
    case 168:
      ACCEPT_TOKEN(aux_sym_macro_token1);
      if (lookahead == 'N') ADVANCE(163);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(178);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(176);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(177);
      END_STATE();
    case 169:
      ACCEPT_TOKEN(aux_sym_macro_token1);
      if (lookahead == 'N') ADVANCE(160);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(178);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(176);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(177);
      END_STATE();
    case 170:
      ACCEPT_TOKEN(aux_sym_macro_token1);
      if (lookahead == 'O') ADVANCE(158);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(178);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(176);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(177);
      END_STATE();
    case 171:
      ACCEPT_TOKEN(aux_sym_macro_token1);
      if (lookahead == 'O') ADVANCE(148);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(178);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(176);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(177);
      END_STATE();
    case 172:
      ACCEPT_TOKEN(aux_sym_macro_token1);
      if (lookahead == 'O') ADVANCE(169);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(178);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(176);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(177);
      END_STATE();
    case 173:
      ACCEPT_TOKEN(aux_sym_macro_token1);
      if (lookahead == 'T') ADVANCE(148);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(178);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(176);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(177);
      END_STATE();
    case 174:
      ACCEPT_TOKEN(aux_sym_macro_token1);
      if (lookahead == 'T') ADVANCE(165);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(178);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(176);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(177);
      END_STATE();
    case 175:
      ACCEPT_TOKEN(aux_sym_macro_token1);
      if (lookahead == 'X') ADVANCE(173);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(178);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(176);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(177);
      END_STATE();
    case 176:
      ACCEPT_TOKEN(aux_sym_macro_token1);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(178);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(177);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(176);
      END_STATE();
    case 177:
      ACCEPT_TOKEN(aux_sym_macro_token1);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(178);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(177);
      END_STATE();
    case 178:
      ACCEPT_TOKEN(aux_sym_macro_token1);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(178);
      END_STATE();
    case 179:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      END_STATE();
    case 180:
      ACCEPT_TOKEN(aux_sym_macro_token2);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(180);
      if (lookahead != 0 &&
          lookahead != ')' &&
          lookahead != '}') ADVANCE(181);
      END_STATE();
    case 181:
      ACCEPT_TOKEN(aux_sym_macro_token2);
      if (lookahead != 0 &&
          lookahead != ')' &&
          lookahead != '}') ADVANCE(181);
      END_STATE();
    case 182:
      ACCEPT_TOKEN(anon_sym_RPAREN);
      END_STATE();
    case 183:
      ACCEPT_TOKEN(anon_sym_RBRACE_RBRACE_RBRACE);
      END_STATE();
    case 184:
      ACCEPT_TOKEN(sym_footnote_reference);
      END_STATE();
    case 185:
      ACCEPT_TOKEN(sym_latex_fragment);
      END_STATE();
    case 186:
      ACCEPT_TOKEN(sym_entity);
      END_STATE();
    case 187:
      ACCEPT_TOKEN(sym_subscript);
      END_STATE();
    case 188:
      ACCEPT_TOKEN(sym_superscript);
      END_STATE();
    case 189:
      ACCEPT_TOKEN(anon_sym_LBRACK_LBRACK);
      END_STATE();
    case 190:
      ACCEPT_TOKEN(anon_sym_LBRACK_LBRACK);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(320);
      END_STATE();
    case 191:
      ACCEPT_TOKEN(aux_sym_link_token1);
      if (lookahead == '\t' ||
          (0x0b <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(191);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ']') ADVANCE(192);
      END_STATE();
    case 192:
      ACCEPT_TOKEN(aux_sym_link_token1);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != ']') ADVANCE(192);
      END_STATE();
    case 193:
      ACCEPT_TOKEN(anon_sym_RBRACK_LBRACK);
      END_STATE();
    case 194:
      ACCEPT_TOKEN(anon_sym_RBRACK_RBRACK);
      END_STATE();
    case 195:
      ACCEPT_TOKEN(aux_sym_list_item_token1);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(195);
      if ((0x0b <= lookahead && lookahead <= '\r')) ADVANCE(257);
      END_STATE();
    case 196:
      ACCEPT_TOKEN(aux_sym_list_item_token1);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(196);
      if ((0x0b <= lookahead && lookahead <= '\r')) ADVANCE(226);
      END_STATE();
    case 197:
      ACCEPT_TOKEN(aux_sym_list_item_token2);
      if (lookahead == '\n') ADVANCE(145);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(197);
      if (lookahead != 0) ADVANCE(200);
      END_STATE();
    case 198:
      ACCEPT_TOKEN(aux_sym_list_item_token2);
      if (lookahead == '\t' ||
          (0x0b <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(198);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(199);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead)) ADVANCE(200);
      END_STATE();
    case 199:
      ACCEPT_TOKEN(aux_sym_list_item_token2);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(199);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(200);
      END_STATE();
    case 200:
      ACCEPT_TOKEN(aux_sym_list_item_token2);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(200);
      END_STATE();
    case 201:
      ACCEPT_TOKEN(sym_bullet);
      END_STATE();
    case 202:
      ACCEPT_TOKEN(sym_bullet);
      if (lookahead == '-') ADVANCE(264);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(320);
      END_STATE();
    case 203:
      ACCEPT_TOKEN(sym_bullet);
      if (lookahead == '-') ADVANCE(36);
      END_STATE();
    case 204:
      ACCEPT_TOKEN(sym_bullet);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(320);
      END_STATE();
    case 205:
      ACCEPT_TOKEN(aux_sym_block_begin_token1);
      END_STATE();
    case 206:
      ACCEPT_TOKEN(aux_sym_block_begin_token1);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(320);
      END_STATE();
    case 207:
      ACCEPT_TOKEN(sym_block_type);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(208);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(207);
      END_STATE();
    case 208:
      ACCEPT_TOKEN(sym_block_type);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(208);
      END_STATE();
    case 209:
      ACCEPT_TOKEN(sym_language);
      if (lookahead == '+' ||
          lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(209);
      END_STATE();
    case 210:
      ACCEPT_TOKEN(sym_block_content);
      if (lookahead == '#') ADVANCE(30);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(210);
      if (lookahead != 0) ADVANCE(211);
      END_STATE();
    case 211:
      ACCEPT_TOKEN(sym_block_content);
      if (lookahead == '#') ADVANCE(32);
      if (lookahead != 0) ADVANCE(211);
      END_STATE();
    case 212:
      ACCEPT_TOKEN(aux_sym_block_end_token1);
      END_STATE();
    case 213:
      ACCEPT_TOKEN(anon_sym_PIPE);
      END_STATE();
    case 214:
      ACCEPT_TOKEN(anon_sym_PIPE);
      if (lookahead == '-') ADVANCE(3);
      END_STATE();
    case 215:
      ACCEPT_TOKEN(anon_sym_PIPE);
      if (lookahead == '-') ADVANCE(245);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(320);
      END_STATE();
    case 216:
      ACCEPT_TOKEN(sym_table_cell);
      if (lookahead == '\n') ADVANCE(141);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(216);
      if (lookahead != 0 &&
          lookahead != '|') ADVANCE(217);
      END_STATE();
    case 217:
      ACCEPT_TOKEN(sym_table_cell);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '|') ADVANCE(217);
      END_STATE();
    case 218:
      ACCEPT_TOKEN(sym_table_separator);
      END_STATE();
    case 219:
      ACCEPT_TOKEN(aux_sym_directive_token1);
      if (lookahead == 'B' ||
          lookahead == 'b') ADVANCE(112);
      END_STATE();
    case 220:
      ACCEPT_TOKEN(aux_sym_directive_token1);
      if (lookahead == 'B' ||
          lookahead == 'b') ADVANCE(315);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(320);
      END_STATE();
    case 221:
      ACCEPT_TOKEN(anon_sym_COLON);
      END_STATE();
    case 222:
      ACCEPT_TOKEN(anon_sym_COLON);
      if (lookahead == 'E') ADVANCE(68);
      END_STATE();
    case 223:
      ACCEPT_TOKEN(anon_sym_COLON);
      if (lookahead == 'E') ADVANCE(68);
      if (lookahead == 'P') ADVANCE(78);
      END_STATE();
    case 224:
      ACCEPT_TOKEN(anon_sym_COLON);
      if (lookahead == 'P') ADVANCE(78);
      END_STATE();
    case 225:
      ACCEPT_TOKEN(anon_sym_COLON);
      if (lookahead == 'P') ADVANCE(296);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(320);
      END_STATE();
    case 226:
      ACCEPT_TOKEN(aux_sym_directive_token2);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(196);
      if ((0x0b <= lookahead && lookahead <= '\r')) ADVANCE(226);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead)) ADVANCE(228);
      END_STATE();
    case 227:
      ACCEPT_TOKEN(aux_sym_directive_token2);
      if (lookahead == '\t' ||
          (0x0b <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(227);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead)) ADVANCE(228);
      END_STATE();
    case 228:
      ACCEPT_TOKEN(aux_sym_directive_token2);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(228);
      END_STATE();
    case 229:
      ACCEPT_TOKEN(sym_name);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(229);
      END_STATE();
    case 230:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      END_STATE();
    case 231:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(320);
      END_STATE();
    case 232:
      ACCEPT_TOKEN(anon_sym_COLONPROPERTIES_COLON);
      END_STATE();
    case 233:
      ACCEPT_TOKEN(anon_sym_COLONPROPERTIES_COLON);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(320);
      END_STATE();
    case 234:
      ACCEPT_TOKEN(aux_sym_property_drawer_token1);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(234);
      END_STATE();
    case 235:
      ACCEPT_TOKEN(anon_sym_COLONEND_COLON);
      END_STATE();
    case 236:
      ACCEPT_TOKEN(aux_sym_key_token1);
      if (lookahead == '-' ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(236);
      END_STATE();
    case 237:
      ACCEPT_TOKEN(anon_sym_COLONend_COLON);
      END_STATE();
    case 238:
      ACCEPT_TOKEN(sym_drawer_content);
      if (lookahead == ':') ADVANCE(61);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(238);
      if (lookahead != 0) ADVANCE(239);
      END_STATE();
    case 239:
      ACCEPT_TOKEN(sym_drawer_content);
      if (lookahead == ':') ADVANCE(115);
      if (lookahead != 0) ADVANCE(239);
      END_STATE();
    case 240:
      ACCEPT_TOKEN(sym_horizontal_rule);
      END_STATE();
    case 241:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '\n') ADVANCE(29);
      if (lookahead == '$') ADVANCE(320);
      if (lookahead != 0) ADVANCE(242);
      END_STATE();
    case 242:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '\n') ADVANCE(29);
      if (lookahead == '$') ADVANCE(259);
      if (lookahead != 0) ADVANCE(242);
      END_STATE();
    case 243:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '\n') ADVANCE(186);
      if (lookahead == '{') ADVANCE(313);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(243);
      if (lookahead != 0) ADVANCE(320);
      END_STATE();
    case 244:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '\n') ADVANCE(186);
      if (lookahead != 0) ADVANCE(320);
      END_STATE();
    case 245:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '\n') ADVANCE(218);
      if (lookahead == '+') ADVANCE(261);
      if (lookahead == '-') ADVANCE(245);
      if (lookahead == '|') ADVANCE(246);
      if (lookahead != 0) ADVANCE(320);
      END_STATE();
    case 246:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '\n') ADVANCE(218);
      if (lookahead == '-') ADVANCE(245);
      if (lookahead != 0) ADVANCE(320);
      END_STATE();
    case 247:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '\n') ADVANCE(185);
      if (lookahead != 0) ADVANCE(320);
      END_STATE();
    case 248:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '\n') ADVANCE(151);
      if (lookahead != 0) ADVANCE(320);
      END_STATE();
    case 249:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '\n') ADVANCE(240);
      if (lookahead == '-') ADVANCE(249);
      if (lookahead != 0) ADVANCE(320);
      END_STATE();
    case 250:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '\n') ADVANCE(89);
      if (lookahead == ']') ADVANCE(320);
      if (lookahead != 0) ADVANCE(251);
      END_STATE();
    case 251:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '\n') ADVANCE(89);
      if (lookahead == ']') ADVANCE(252);
      if (lookahead != 0) ADVANCE(251);
      END_STATE();
    case 252:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '\n') ADVANCE(184);
      if (lookahead != 0) ADVANCE(320);
      END_STATE();
    case 253:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '\n') ADVANCE(188);
      if (lookahead != 0) ADVANCE(253);
      END_STATE();
    case 254:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '\n') ADVANCE(187);
      if (lookahead != 0) ADVANCE(254);
      END_STATE();
    case 255:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '\n') ADVANCE(150);
      if (lookahead != 0) ADVANCE(320);
      END_STATE();
    case 256:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == ' ') ADVANCE(231);
      if (lookahead == '+') ADVANCE(220);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(320);
      END_STATE();
    case 257:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      ADVANCE_MAP(
        '#', 256,
        '$', 258,
        '*', 147,
        '+', 204,
        '-', 202,
        ':', 225,
        '<', 271,
        'C', 289,
        'D', 280,
        'S', 276,
        '[', 302,
        '\\', 319,
        '{', 312,
        '|', 215,
        '\t', 195,
        ' ', 195,
      );
      if ((0x0b <= lookahead && lookahead <= '\r')) ADVANCE(257);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(306);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(307);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(307);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead)) ADVANCE(320);
      END_STATE();
    case 258:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '$') ADVANCE(241);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(260);
      END_STATE();
    case 259:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '$') ADVANCE(247);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(320);
      END_STATE();
    case 260:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '$') ADVANCE(247);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(260);
      END_STATE();
    case 261:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '-') ADVANCE(245);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(320);
      END_STATE();
    case 262:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '-') ADVANCE(249);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(320);
      END_STATE();
    case 263:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '-') ADVANCE(262);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(320);
      END_STATE();
    case 264:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '-') ADVANCE(263);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(320);
      END_STATE();
    case 265:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == ':') ADVANCE(267);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(320);
      END_STATE();
    case 266:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == ':') ADVANCE(250);
      if (lookahead == ']') ADVANCE(252);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(266);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(320);
      END_STATE();
    case 267:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == ':') ADVANCE(250);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(266);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(320);
      END_STATE();
    case 268:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == ':') ADVANCE(314);
      if (lookahead == '^') ADVANCE(321);
      if (lookahead == '_') ADVANCE(322);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(308);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(320);
      END_STATE();
    case 269:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == ':') ADVANCE(233);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(320);
      END_STATE();
    case 270:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '<') ADVANCE(272);
      if (lookahead == '[') ADVANCE(303);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(270);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n') ADVANCE(320);
      END_STATE();
    case 271:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '>') ADVANCE(320);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(273);
      END_STATE();
    case 272:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '>') ADVANCE(320);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(274);
      END_STATE();
    case 273:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '>') ADVANCE(248);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(273);
      END_STATE();
    case 274:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '>') ADVANCE(255);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(274);
      END_STATE();
    case 275:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == 'A') ADVANCE(277);
      if (lookahead == '^') ADVANCE(321);
      if (lookahead == '_') ADVANCE(322);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('B' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(308);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(320);
      END_STATE();
    case 276:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == 'C') ADVANCE(286);
      if (lookahead == '^') ADVANCE(321);
      if (lookahead == '_') ADVANCE(322);
      if (lookahead == ')' ||
          lookahead == '.') ADVANCE(204);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(308);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(320);
      END_STATE();
    case 277:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == 'D') ADVANCE(290);
      if (lookahead == '^') ADVANCE(321);
      if (lookahead == '_') ADVANCE(322);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(308);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(320);
      END_STATE();
    case 278:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == 'D') ADVANCE(301);
      if (lookahead == '^') ADVANCE(321);
      if (lookahead == '_') ADVANCE(322);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(308);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(320);
      END_STATE();
    case 279:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == 'D') ADVANCE(268);
      if (lookahead == '^') ADVANCE(321);
      if (lookahead == '_') ADVANCE(322);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(308);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(320);
      END_STATE();
    case 280:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == 'E') ADVANCE(275);
      if (lookahead == '^') ADVANCE(321);
      if (lookahead == '_') ADVANCE(322);
      if (lookahead == ')' ||
          lookahead == '.') ADVANCE(204);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(308);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(320);
      END_STATE();
    case 281:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == 'E') ADVANCE(268);
      if (lookahead == '^') ADVANCE(321);
      if (lookahead == '_') ADVANCE(322);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(308);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(320);
      END_STATE();
    case 282:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == 'E') ADVANCE(298);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(320);
      END_STATE();
    case 283:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == 'E') ADVANCE(278);
      if (lookahead == '^') ADVANCE(321);
      if (lookahead == '_') ADVANCE(322);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(308);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(320);
      END_STATE();
    case 284:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == 'E') ADVANCE(297);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(320);
      END_STATE();
    case 285:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == 'E') ADVANCE(279);
      if (lookahead == '^') ADVANCE(321);
      if (lookahead == '_') ADVANCE(322);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(308);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(320);
      END_STATE();
    case 286:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == 'H') ADVANCE(283);
      if (lookahead == '^') ADVANCE(321);
      if (lookahead == '_') ADVANCE(322);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(308);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(320);
      END_STATE();
    case 287:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == 'I') ADVANCE(292);
      if (lookahead == '^') ADVANCE(321);
      if (lookahead == '_') ADVANCE(322);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(308);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(320);
      END_STATE();
    case 288:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == 'I') ADVANCE(282);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(320);
      END_STATE();
    case 289:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == 'L') ADVANCE(293);
      if (lookahead == '^') ADVANCE(321);
      if (lookahead == '_') ADVANCE(322);
      if (lookahead == ')' ||
          lookahead == '.') ADVANCE(204);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(308);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(320);
      END_STATE();
    case 290:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == 'L') ADVANCE(287);
      if (lookahead == '^') ADVANCE(321);
      if (lookahead == '_') ADVANCE(322);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(308);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(320);
      END_STATE();
    case 291:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == 'L') ADVANCE(285);
      if (lookahead == '^') ADVANCE(321);
      if (lookahead == '_') ADVANCE(322);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(308);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(320);
      END_STATE();
    case 292:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == 'N') ADVANCE(281);
      if (lookahead == '^') ADVANCE(321);
      if (lookahead == '_') ADVANCE(322);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(308);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(320);
      END_STATE();
    case 293:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == 'O') ADVANCE(299);
      if (lookahead == '^') ADVANCE(321);
      if (lookahead == '_') ADVANCE(322);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(308);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(320);
      END_STATE();
    case 294:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == 'O') ADVANCE(295);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(320);
      END_STATE();
    case 295:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == 'P') ADVANCE(284);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(320);
      END_STATE();
    case 296:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == 'R') ADVANCE(294);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(320);
      END_STATE();
    case 297:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == 'R') ADVANCE(300);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(320);
      END_STATE();
    case 298:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == 'S') ADVANCE(269);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(320);
      END_STATE();
    case 299:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == 'S') ADVANCE(285);
      if (lookahead == '^') ADVANCE(321);
      if (lookahead == '_') ADVANCE(322);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(308);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(320);
      END_STATE();
    case 300:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == 'T') ADVANCE(288);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(320);
      END_STATE();
    case 301:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == 'U') ADVANCE(291);
      if (lookahead == '^') ADVANCE(321);
      if (lookahead == '_') ADVANCE(322);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(308);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(320);
      END_STATE();
    case 302:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '[') ADVANCE(190);
      if (lookahead == 'f') ADVANCE(310);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(304);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(320);
      END_STATE();
    case 303:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == ']') ADVANCE(320);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(305);
      END_STATE();
    case 304:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == ']') ADVANCE(248);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(304);
      END_STATE();
    case 305:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == ']') ADVANCE(255);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(305);
      END_STATE();
    case 306:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '^') ADVANCE(321);
      if (lookahead == '_') ADVANCE(322);
      if (lookahead == ')' ||
          lookahead == '.') ADVANCE(204);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(306);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(308);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(320);
      END_STATE();
    case 307:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '^') ADVANCE(321);
      if (lookahead == '_') ADVANCE(322);
      if (lookahead == ')' ||
          lookahead == '.') ADVANCE(204);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(308);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(320);
      END_STATE();
    case 308:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '^') ADVANCE(321);
      if (lookahead == '_') ADVANCE(322);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(308);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(320);
      END_STATE();
    case 309:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '_') ADVANCE(206);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(320);
      END_STATE();
    case 310:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == 'n') ADVANCE(265);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(320);
      END_STATE();
    case 311:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '{') ADVANCE(153);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(320);
      END_STATE();
    case 312:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '{') ADVANCE(311);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(320);
      END_STATE();
    case 313:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '}') ADVANCE(244);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(320);
      END_STATE();
    case 314:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(270);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n') ADVANCE(320);
      END_STATE();
    case 315:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(316);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(320);
      END_STATE();
    case 316:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == 'G' ||
          lookahead == 'g') ADVANCE(317);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(320);
      END_STATE();
    case 317:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(318);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(320);
      END_STATE();
    case 318:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(309);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(320);
      END_STATE();
    case 319:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(243);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(320);
      END_STATE();
    case 320:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(320);
      END_STATE();
    case 321:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(253);
      END_STATE();
    case 322:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(254);
      END_STATE();
    case 323:
      ACCEPT_TOKEN(aux_sym_paragraph_token2);
      if (lookahead == '\n') ADVANCE(323);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0, .external_lex_state = 1},
  [1] = {.lex_state = 136},
  [2] = {.lex_state = 136},
  [3] = {.lex_state = 136},
  [4] = {.lex_state = 136},
  [5] = {.lex_state = 136},
  [6] = {.lex_state = 136},
  [7] = {.lex_state = 136},
  [8] = {.lex_state = 136},
  [9] = {.lex_state = 136},
  [10] = {.lex_state = 136},
  [11] = {.lex_state = 136},
  [12] = {.lex_state = 136},
  [13] = {.lex_state = 136},
  [14] = {.lex_state = 136},
  [15] = {.lex_state = 136},
  [16] = {.lex_state = 136},
  [17] = {.lex_state = 136},
  [18] = {.lex_state = 136},
  [19] = {.lex_state = 136},
  [20] = {.lex_state = 136},
  [21] = {.lex_state = 136},
  [22] = {.lex_state = 136},
  [23] = {.lex_state = 136},
  [24] = {.lex_state = 136},
  [25] = {.lex_state = 136},
  [26] = {.lex_state = 136},
  [27] = {.lex_state = 136},
  [28] = {.lex_state = 136},
  [29] = {.lex_state = 136},
  [30] = {.lex_state = 136},
  [31] = {.lex_state = 136},
  [32] = {.lex_state = 136},
  [33] = {.lex_state = 136},
  [34] = {.lex_state = 136},
  [35] = {.lex_state = 136},
  [36] = {.lex_state = 136},
  [37] = {.lex_state = 136},
  [38] = {.lex_state = 136},
  [39] = {.lex_state = 136},
  [40] = {.lex_state = 136},
  [41] = {.lex_state = 136},
  [42] = {.lex_state = 136},
  [43] = {.lex_state = 11, .external_lex_state = 1},
  [44] = {.lex_state = 24},
  [45] = {.lex_state = 12},
  [46] = {.lex_state = 24},
  [47] = {.lex_state = 12},
  [48] = {.lex_state = 13, .external_lex_state = 1},
  [49] = {.lex_state = 12},
  [50] = {.lex_state = 14, .external_lex_state = 1},
  [51] = {.lex_state = 25},
  [52] = {.lex_state = 43},
  [53] = {.lex_state = 14, .external_lex_state = 1},
  [54] = {.lex_state = 12},
  [55] = {.lex_state = 25},
  [56] = {.lex_state = 14, .external_lex_state = 2},
  [57] = {.lex_state = 197},
  [58] = {.lex_state = 0},
  [59] = {.lex_state = 0},
  [60] = {.lex_state = 25},
  [61] = {.lex_state = 24},
  [62] = {.lex_state = 15},
  [63] = {.lex_state = 24},
  [64] = {.lex_state = 16},
  [65] = {.lex_state = 17},
  [66] = {.lex_state = 44},
  [67] = {.lex_state = 25},
  [68] = {.lex_state = 14, .external_lex_state = 2},
  [69] = {.lex_state = 14, .external_lex_state = 2},
  [70] = {.lex_state = 24},
  [71] = {.lex_state = 198},
  [72] = {.lex_state = 24},
  [73] = {.lex_state = 14, .external_lex_state = 2},
  [74] = {.lex_state = 43},
  [75] = {.lex_state = 21},
  [76] = {.lex_state = 0},
  [77] = {.lex_state = 21},
  [78] = {.lex_state = 0},
  [79] = {.lex_state = 14},
  [80] = {.lex_state = 14},
  [81] = {.lex_state = 16},
  [82] = {.lex_state = 14},
  [83] = {.lex_state = 14},
  [84] = {.lex_state = 14},
  [85] = {.lex_state = 14},
  [86] = {.lex_state = 14},
  [87] = {.lex_state = 14},
  [88] = {.lex_state = 21},
  [89] = {.lex_state = 14},
  [90] = {.lex_state = 43},
  [91] = {.lex_state = 0},
  [92] = {.lex_state = 14},
  [93] = {.lex_state = 21},
  [94] = {.lex_state = 14},
  [95] = {.lex_state = 14},
  [96] = {.lex_state = 43},
  [97] = {.lex_state = 21},
  [98] = {.lex_state = 43},
  [99] = {.lex_state = 43},
  [100] = {.lex_state = 234},
  [101] = {.lex_state = 24},
  [102] = {.lex_state = 198},
  [103] = {.lex_state = 14},
  [104] = {.lex_state = 198},
  [105] = {.lex_state = 14},
  [106] = {.lex_state = 14},
  [107] = {.lex_state = 14},
  [108] = {.lex_state = 234},
  [109] = {.lex_state = 43},
  [110] = {.lex_state = 14},
  [111] = {.lex_state = 14},
  [112] = {.lex_state = 198},
  [113] = {.lex_state = 0},
  [114] = {.lex_state = 234},
  [115] = {.lex_state = 47},
  [116] = {.lex_state = 234},
  [117] = {.lex_state = 14},
  [118] = {.lex_state = 18},
  [119] = {.lex_state = 14},
  [120] = {.lex_state = 14},
  [121] = {.lex_state = 234},
  [122] = {.lex_state = 198},
  [123] = {.lex_state = 19},
  [124] = {.lex_state = 14},
  [125] = {.lex_state = 234},
  [126] = {.lex_state = 14},
  [127] = {.lex_state = 47},
  [128] = {.lex_state = 14},
  [129] = {.lex_state = 124},
  [130] = {.lex_state = 21},
  [131] = {.lex_state = 107},
  [132] = {.lex_state = 14},
  [133] = {.lex_state = 14},
  [134] = {.lex_state = 14},
  [135] = {.lex_state = 19},
  [136] = {.lex_state = 125},
  [137] = {.lex_state = 126},
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
    [sym_HEADLINE_TITLE] = ACTIONS(1),
    [sym_HEADLINE_TAGS] = ACTIONS(1),
  },
  [1] = {
    [sym_document] = STATE(113),
    [sym__element] = STATE(3),
    [sym_headline] = STATE(3),
    [sym_macro] = STATE(3),
    [sym_link] = STATE(3),
    [sym_list] = STATE(3),
    [sym_list_item] = STATE(4),
    [sym_block] = STATE(3),
    [sym_block_begin] = STATE(51),
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
    [sym_block_begin] = STATE(51),
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
    [sym_block_begin] = STATE(51),
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
  [869] = 2,
    ACTIONS(219), 1,
      ts_builtin_sym_end,
    ACTIONS(221), 21,
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
  [896] = 2,
    ACTIONS(223), 1,
      ts_builtin_sym_end,
    ACTIONS(225), 21,
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
  [923] = 2,
    ACTIONS(227), 1,
      ts_builtin_sym_end,
    ACTIONS(229), 21,
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
  [950] = 2,
    ACTIONS(231), 1,
      ts_builtin_sym_end,
    ACTIONS(233), 21,
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
  [977] = 2,
    ACTIONS(235), 1,
      ts_builtin_sym_end,
    ACTIONS(237), 21,
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
  [1004] = 2,
    ACTIONS(239), 1,
      ts_builtin_sym_end,
    ACTIONS(241), 21,
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
  [1031] = 2,
    ACTIONS(243), 1,
      ts_builtin_sym_end,
    ACTIONS(245), 21,
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
  [1058] = 2,
    ACTIONS(247), 1,
      ts_builtin_sym_end,
    ACTIONS(249), 21,
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
  [1085] = 5,
    ACTIONS(251), 1,
      anon_sym_LF,
    ACTIONS(253), 1,
      sym_keyword,
    ACTIONS(255), 1,
      sym_priority,
    ACTIONS(257), 1,
      sym_HEADLINE_TITLE,
    ACTIONS(259), 1,
      sym_HEADLINE_TAGS,
  [1101] = 3,
    ACTIONS(261), 1,
      anon_sym_COLON,
    ACTIONS(263), 1,
      anon_sym_COLONEND_COLON,
    STATE(46), 2,
      sym_property,
      aux_sym_property_drawer_repeat1,
  [1112] = 4,
    ACTIONS(265), 1,
      anon_sym_LF,
    ACTIONS(267), 1,
      anon_sym_PIPE,
    ACTIONS(269), 1,
      sym_table_cell,
    STATE(47), 1,
      aux_sym_table_row_repeat1,
  [1125] = 3,
    ACTIONS(271), 1,
      anon_sym_COLON,
    ACTIONS(274), 1,
      anon_sym_COLONEND_COLON,
    STATE(46), 2,
      sym_property,
      aux_sym_property_drawer_repeat1,
  [1136] = 4,
    ACTIONS(276), 1,
      anon_sym_LF,
    ACTIONS(278), 1,
      anon_sym_PIPE,
    ACTIONS(281), 1,
      sym_table_cell,
    STATE(47), 1,
      aux_sym_table_row_repeat1,
  [1149] = 4,
    ACTIONS(284), 1,
      anon_sym_LF,
    ACTIONS(286), 1,
      sym_priority,
    ACTIONS(288), 1,
      sym_HEADLINE_TITLE,
    ACTIONS(290), 1,
      sym_HEADLINE_TAGS,
  [1162] = 4,
    ACTIONS(269), 1,
      sym_table_cell,
    ACTIONS(292), 1,
      anon_sym_LF,
    ACTIONS(294), 1,
      anon_sym_PIPE,
    STATE(45), 1,
      aux_sym_table_row_repeat1,
  [1175] = 3,
    ACTIONS(296), 1,
      anon_sym_LF,
    ACTIONS(298), 1,
      sym_HEADLINE_TITLE,
    ACTIONS(300), 1,
      sym_HEADLINE_TAGS,
  [1185] = 3,
    ACTIONS(302), 1,
      sym_block_content,
    ACTIONS(304), 1,
      aux_sym_block_end_token1,
    STATE(36), 1,
      sym_block_end,
  [1195] = 2,
    ACTIONS(306), 1,
      anon_sym_COLON,
    STATE(44), 2,
      sym_property,
      aux_sym_property_drawer_repeat1,
  [1203] = 3,
    ACTIONS(308), 1,
      anon_sym_LF,
    ACTIONS(310), 1,
      sym_HEADLINE_TITLE,
    ACTIONS(312), 1,
      sym_HEADLINE_TAGS,
  [1213] = 1,
    ACTIONS(276), 3,
      anon_sym_LF,
      anon_sym_PIPE,
      sym_table_cell,
  [1219] = 2,
    ACTIONS(314), 1,
      sym_block_content,
    ACTIONS(316), 1,
      aux_sym_block_end_token1,
  [1226] = 2,
    ACTIONS(318), 1,
      anon_sym_LF,
    ACTIONS(320), 1,
      sym_HEADLINE_TAGS,
  [1233] = 2,
    ACTIONS(322), 1,
      anon_sym_LF,
    ACTIONS(324), 1,
      aux_sym_list_item_token2,
  [1240] = 2,
    ACTIONS(326), 1,
      anon_sym_LPAREN,
    ACTIONS(328), 1,
      anon_sym_RBRACE_RBRACE_RBRACE,
  [1247] = 2,
    ACTIONS(330), 1,
      anon_sym_RBRACK_LBRACK,
    ACTIONS(332), 1,
      anon_sym_RBRACK_RBRACK,
  [1254] = 2,
    ACTIONS(334), 1,
      sym_block_content,
    ACTIONS(336), 1,
      aux_sym_block_end_token1,
  [1261] = 2,
    ACTIONS(338), 1,
      anon_sym_COLON,
    ACTIONS(340), 1,
      anon_sym_COLONEND_COLON,
  [1268] = 2,
    ACTIONS(342), 1,
      aux_sym_list_item_token1,
    ACTIONS(344), 1,
      aux_sym_directive_token2,
  [1275] = 2,
    ACTIONS(346), 1,
      aux_sym_key_token1,
    STATE(90), 1,
      sym_drawer_name,
  [1282] = 2,
    ACTIONS(348), 1,
      aux_sym_directive_token2,
    STATE(134), 1,
      sym_value,
  [1289] = 2,
    ACTIONS(350), 1,
      anon_sym_SPACE,
    ACTIONS(352), 1,
      anon_sym_LF,
  [1296] = 2,
    ACTIONS(354), 1,
      anon_sym_COLONend_COLON,
    ACTIONS(356), 1,
      sym_drawer_content,
  [1303] = 2,
    ACTIONS(358), 1,
      sym_block_content,
    ACTIONS(360), 1,
      aux_sym_block_end_token1,
  [1310] = 2,
    ACTIONS(362), 1,
      anon_sym_LF,
    ACTIONS(364), 1,
      sym_HEADLINE_TAGS,
  [1317] = 2,
    ACTIONS(366), 1,
      anon_sym_LF,
    ACTIONS(368), 1,
      sym_HEADLINE_TAGS,
  [1324] = 2,
    ACTIONS(370), 1,
      aux_sym_key_token1,
    STATE(99), 1,
      sym_key,
  [1331] = 2,
    ACTIONS(372), 1,
      aux_sym_list_item_token2,
    ACTIONS(374), 1,
      sym_block_type,
  [1338] = 2,
    ACTIONS(376), 1,
      aux_sym_block_end_token1,
    STATE(27), 1,
      sym_block_end,
  [1345] = 2,
    ACTIONS(378), 1,
      anon_sym_LF,
    ACTIONS(380), 1,
      sym_HEADLINE_TAGS,
  [1352] = 1,
    ACTIONS(382), 1,
      anon_sym_COLON,
  [1356] = 1,
    ACTIONS(384), 1,
      anon_sym_SPACE,
  [1360] = 1,
    ACTIONS(386), 1,
      anon_sym_RPAREN,
  [1364] = 1,
    ACTIONS(388), 1,
      anon_sym_SPACE,
  [1368] = 1,
    ACTIONS(390), 1,
      anon_sym_RBRACK_RBRACK,
  [1372] = 1,
    ACTIONS(392), 1,
      anon_sym_LF,
  [1376] = 1,
    ACTIONS(394), 1,
      anon_sym_LF,
  [1380] = 1,
    ACTIONS(396), 1,
      aux_sym_directive_token2,
  [1384] = 1,
    ACTIONS(398), 1,
      anon_sym_LF,
  [1388] = 1,
    ACTIONS(400), 1,
      anon_sym_LF,
  [1392] = 1,
    ACTIONS(402), 1,
      anon_sym_LF,
  [1396] = 1,
    ACTIONS(404), 1,
      anon_sym_LF,
  [1400] = 1,
    ACTIONS(406), 1,
      anon_sym_LF,
  [1404] = 1,
    ACTIONS(408), 1,
      anon_sym_LF,
  [1408] = 1,
    ACTIONS(410), 1,
      anon_sym_SPACE,
  [1412] = 1,
    ACTIONS(412), 1,
      anon_sym_LF,
  [1416] = 1,
    ACTIONS(414), 1,
      anon_sym_COLON,
  [1420] = 1,
    ACTIONS(416), 1,
      anon_sym_RBRACE_RBRACE_RBRACE,
  [1424] = 1,
    ACTIONS(418), 1,
      anon_sym_LF,
  [1428] = 1,
    ACTIONS(420), 1,
      anon_sym_SPACE,
  [1432] = 1,
    ACTIONS(422), 1,
      anon_sym_LF,
  [1436] = 1,
    ACTIONS(424), 1,
      anon_sym_LF,
  [1440] = 1,
    ACTIONS(426), 1,
      anon_sym_COLON,
  [1444] = 1,
    ACTIONS(428), 1,
      anon_sym_SPACE,
  [1448] = 1,
    ACTIONS(430), 1,
      anon_sym_COLON,
  [1452] = 1,
    ACTIONS(432), 1,
      anon_sym_COLON,
  [1456] = 1,
    ACTIONS(434), 1,
      aux_sym_property_drawer_token1,
  [1460] = 1,
    ACTIONS(436), 1,
      anon_sym_PIPE,
  [1464] = 1,
    ACTIONS(438), 1,
      aux_sym_list_item_token2,
  [1468] = 1,
    ACTIONS(440), 1,
      anon_sym_LF,
  [1472] = 1,
    ACTIONS(442), 1,
      aux_sym_list_item_token2,
  [1476] = 1,
    ACTIONS(444), 1,
      anon_sym_LF,
  [1480] = 1,
    ACTIONS(446), 1,
      anon_sym_LF,
  [1484] = 1,
    ACTIONS(448), 1,
      anon_sym_LF,
  [1488] = 1,
    ACTIONS(450), 1,
      aux_sym_property_drawer_token1,
  [1492] = 1,
    ACTIONS(452), 1,
      sym_language,
  [1496] = 1,
    ACTIONS(454), 1,
      anon_sym_LF,
  [1500] = 1,
    ACTIONS(456), 1,
      anon_sym_LF,
  [1504] = 1,
    ACTIONS(458), 1,
      aux_sym_list_item_token2,
  [1508] = 1,
    ACTIONS(460), 1,
      ts_builtin_sym_end,
  [1512] = 1,
    ACTIONS(462), 1,
      aux_sym_property_drawer_token1,
  [1516] = 1,
    ACTIONS(464), 1,
      anon_sym_COLONend_COLON,
  [1520] = 1,
    ACTIONS(466), 1,
      aux_sym_property_drawer_token1,
  [1524] = 1,
    ACTIONS(468), 1,
      anon_sym_LF,
  [1528] = 1,
    ACTIONS(470), 1,
      aux_sym_paragraph_token2,
  [1532] = 1,
    ACTIONS(472), 1,
      anon_sym_LF,
  [1536] = 1,
    ACTIONS(474), 1,
      anon_sym_LF,
  [1540] = 1,
    ACTIONS(476), 1,
      aux_sym_property_drawer_token1,
  [1544] = 1,
    ACTIONS(478), 1,
      aux_sym_list_item_token2,
  [1548] = 1,
    ACTIONS(480), 1,
      aux_sym_link_token1,
  [1552] = 1,
    ACTIONS(482), 1,
      anon_sym_LF,
  [1556] = 1,
    ACTIONS(484), 1,
      aux_sym_property_drawer_token1,
  [1560] = 1,
    ACTIONS(486), 1,
      anon_sym_LF,
  [1564] = 1,
    ACTIONS(488), 1,
      sym_name,
  [1568] = 1,
    ACTIONS(490), 1,
      anon_sym_LF,
  [1572] = 1,
    ACTIONS(492), 1,
      sym_block_type,
  [1576] = 1,
    ACTIONS(494), 1,
      anon_sym_SPACE,
  [1580] = 1,
    ACTIONS(496), 1,
      sym_bullet,
  [1584] = 1,
    ACTIONS(498), 1,
      anon_sym_LF,
  [1588] = 1,
    ACTIONS(500), 1,
      anon_sym_LF,
  [1592] = 1,
    ACTIONS(502), 1,
      anon_sym_LF,
  [1596] = 1,
    ACTIONS(504), 1,
      aux_sym_link_token1,
  [1600] = 1,
    ACTIONS(506), 1,
      aux_sym_macro_token1,
  [1604] = 1,
    ACTIONS(508), 1,
      aux_sym_macro_token2,
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
  [SMALL_STATE(36)] = 896,
  [SMALL_STATE(37)] = 923,
  [SMALL_STATE(38)] = 950,
  [SMALL_STATE(39)] = 977,
  [SMALL_STATE(40)] = 1004,
  [SMALL_STATE(41)] = 1031,
  [SMALL_STATE(42)] = 1058,
  [SMALL_STATE(43)] = 1085,
  [SMALL_STATE(44)] = 1101,
  [SMALL_STATE(45)] = 1112,
  [SMALL_STATE(46)] = 1125,
  [SMALL_STATE(47)] = 1136,
  [SMALL_STATE(48)] = 1149,
  [SMALL_STATE(49)] = 1162,
  [SMALL_STATE(50)] = 1175,
  [SMALL_STATE(51)] = 1185,
  [SMALL_STATE(52)] = 1195,
  [SMALL_STATE(53)] = 1203,
  [SMALL_STATE(54)] = 1213,
  [SMALL_STATE(55)] = 1219,
  [SMALL_STATE(56)] = 1226,
  [SMALL_STATE(57)] = 1233,
  [SMALL_STATE(58)] = 1240,
  [SMALL_STATE(59)] = 1247,
  [SMALL_STATE(60)] = 1254,
  [SMALL_STATE(61)] = 1261,
  [SMALL_STATE(62)] = 1268,
  [SMALL_STATE(63)] = 1275,
  [SMALL_STATE(64)] = 1282,
  [SMALL_STATE(65)] = 1289,
  [SMALL_STATE(66)] = 1296,
  [SMALL_STATE(67)] = 1303,
  [SMALL_STATE(68)] = 1310,
  [SMALL_STATE(69)] = 1317,
  [SMALL_STATE(70)] = 1324,
  [SMALL_STATE(71)] = 1331,
  [SMALL_STATE(72)] = 1338,
  [SMALL_STATE(73)] = 1345,
  [SMALL_STATE(74)] = 1352,
  [SMALL_STATE(75)] = 1356,
  [SMALL_STATE(76)] = 1360,
  [SMALL_STATE(77)] = 1364,
  [SMALL_STATE(78)] = 1368,
  [SMALL_STATE(79)] = 1372,
  [SMALL_STATE(80)] = 1376,
  [SMALL_STATE(81)] = 1380,
  [SMALL_STATE(82)] = 1384,
  [SMALL_STATE(83)] = 1388,
  [SMALL_STATE(84)] = 1392,
  [SMALL_STATE(85)] = 1396,
  [SMALL_STATE(86)] = 1400,
  [SMALL_STATE(87)] = 1404,
  [SMALL_STATE(88)] = 1408,
  [SMALL_STATE(89)] = 1412,
  [SMALL_STATE(90)] = 1416,
  [SMALL_STATE(91)] = 1420,
  [SMALL_STATE(92)] = 1424,
  [SMALL_STATE(93)] = 1428,
  [SMALL_STATE(94)] = 1432,
  [SMALL_STATE(95)] = 1436,
  [SMALL_STATE(96)] = 1440,
  [SMALL_STATE(97)] = 1444,
  [SMALL_STATE(98)] = 1448,
  [SMALL_STATE(99)] = 1452,
  [SMALL_STATE(100)] = 1456,
  [SMALL_STATE(101)] = 1460,
  [SMALL_STATE(102)] = 1464,
  [SMALL_STATE(103)] = 1468,
  [SMALL_STATE(104)] = 1472,
  [SMALL_STATE(105)] = 1476,
  [SMALL_STATE(106)] = 1480,
  [SMALL_STATE(107)] = 1484,
  [SMALL_STATE(108)] = 1488,
  [SMALL_STATE(109)] = 1492,
  [SMALL_STATE(110)] = 1496,
  [SMALL_STATE(111)] = 1500,
  [SMALL_STATE(112)] = 1504,
  [SMALL_STATE(113)] = 1508,
  [SMALL_STATE(114)] = 1512,
  [SMALL_STATE(115)] = 1516,
  [SMALL_STATE(116)] = 1520,
  [SMALL_STATE(117)] = 1524,
  [SMALL_STATE(118)] = 1528,
  [SMALL_STATE(119)] = 1532,
  [SMALL_STATE(120)] = 1536,
  [SMALL_STATE(121)] = 1540,
  [SMALL_STATE(122)] = 1544,
  [SMALL_STATE(123)] = 1548,
  [SMALL_STATE(124)] = 1552,
  [SMALL_STATE(125)] = 1556,
  [SMALL_STATE(126)] = 1560,
  [SMALL_STATE(127)] = 1564,
  [SMALL_STATE(128)] = 1568,
  [SMALL_STATE(129)] = 1572,
  [SMALL_STATE(130)] = 1576,
  [SMALL_STATE(131)] = 1580,
  [SMALL_STATE(132)] = 1584,
  [SMALL_STATE(133)] = 1588,
  [SMALL_STATE(134)] = 1592,
  [SMALL_STATE(135)] = 1596,
  [SMALL_STATE(136)] = 1600,
  [SMALL_STATE(137)] = 1604,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_document, 0, 0, 0),
  [5] = {.entry = {.count = 1, .reusable = false}}, SHIFT(77),
  [7] = {.entry = {.count = 1, .reusable = false}}, SHIFT(3),
  [9] = {.entry = {.count = 1, .reusable = false}}, SHIFT(136),
  [11] = {.entry = {.count = 1, .reusable = false}}, SHIFT(135),
  [13] = {.entry = {.count = 1, .reusable = false}}, SHIFT(131),
  [15] = {.entry = {.count = 1, .reusable = false}}, SHIFT(130),
  [17] = {.entry = {.count = 1, .reusable = false}}, SHIFT(129),
  [19] = {.entry = {.count = 1, .reusable = false}}, SHIFT(49),
  [21] = {.entry = {.count = 1, .reusable = false}}, SHIFT(7),
  [23] = {.entry = {.count = 1, .reusable = false}}, SHIFT(127),
  [25] = {.entry = {.count = 1, .reusable = false}}, SHIFT(63),
  [27] = {.entry = {.count = 1, .reusable = false}}, SHIFT(122),
  [29] = {.entry = {.count = 1, .reusable = false}}, SHIFT(121),
  [31] = {.entry = {.count = 1, .reusable = false}}, SHIFT(118),
  [33] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0),
  [35] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(77),
  [38] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(2),
  [41] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(136),
  [44] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(135),
  [47] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(131),
  [50] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(130),
  [53] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(129),
  [56] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(49),
  [59] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(7),
  [62] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(127),
  [65] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(63),
  [68] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(122),
  [71] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(121),
  [74] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(118),
  [77] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_document, 1, 0, 0),
  [79] = {.entry = {.count = 1, .reusable = false}}, SHIFT(2),
  [81] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_list, 1, 0, 0),
  [83] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_list, 1, 0, 0),
  [85] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_table_repeat1, 2, 0, 0),
  [87] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_table_repeat1, 2, 0, 0),
  [89] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_table_repeat1, 2, 0, 0), SHIFT_REPEAT(49),
  [92] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_table_repeat1, 2, 0, 0), SHIFT_REPEAT(5),
  [95] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_list_repeat1, 2, 0, 0),
  [97] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_list_repeat1, 2, 0, 0),
  [99] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_list_repeat1, 2, 0, 0), SHIFT_REPEAT(131),
  [102] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_list_repeat1, 2, 0, 0), SHIFT_REPEAT(130),
  [105] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_table, 1, 0, 0),
  [107] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_table, 1, 0, 0),
  [109] = {.entry = {.count = 1, .reusable = false}}, SHIFT(5),
  [111] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_table_row, 2, 0, 0),
  [113] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_table_row, 2, 0, 0),
  [115] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_drawer, 8, 0, 0),
  [117] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_drawer, 8, 0, 0),
  [119] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_property_drawer, 7, 0, 0),
  [121] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_property_drawer, 7, 0, 0),
  [123] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_headline, 9, 0, 20),
  [125] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_headline, 9, 0, 20),
  [127] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_macro, 7, 0, 0),
  [129] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_macro, 7, 0, 0),
  [131] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_headline, 7, 0, 17),
  [133] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_headline, 7, 0, 17),
  [135] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_headline, 7, 0, 16),
  [137] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_headline, 7, 0, 16),
  [139] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_headline, 7, 0, 15),
  [141] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_headline, 7, 0, 15),
  [143] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_directive, 6, 0, 14),
  [145] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_directive, 6, 0, 14),
  [147] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_link, 6, 0, 13),
  [149] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_link, 6, 0, 13),
  [151] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_headline, 6, 0, 12),
  [153] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_headline, 6, 0, 12),
  [155] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_table_row, 3, 0, 0),
  [157] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_table_row, 3, 0, 0),
  [159] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_headline, 6, 0, 11),
  [161] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_headline, 6, 0, 11),
  [163] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_headline, 6, 0, 10),
  [165] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_headline, 6, 0, 10),
  [167] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_headline, 6, 0, 9),
  [169] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_headline, 6, 0, 9),
  [171] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_block_end, 4, 0, 0),
  [173] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_block_end, 4, 0, 0),
  [175] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_headline, 4, 0, 3),
  [177] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_headline, 4, 0, 3),
  [179] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_comment, 3, 0, 0),
  [181] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_comment, 3, 0, 0),
  [183] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_directive, 5, 0, 8),
  [185] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_directive, 5, 0, 8),
  [187] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_block, 3, 0, 0),
  [189] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_block, 3, 0, 0),
  [191] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_list_item, 5, 0, 0),
  [193] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_list_item, 5, 0, 0),
  [195] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_headline, 5, 0, 6),
  [197] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_headline, 5, 0, 6),
  [199] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_headline, 5, 0, 5),
  [201] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_headline, 5, 0, 5),
  [203] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_headline, 5, 0, 4),
  [205] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_headline, 5, 0, 4),
  [207] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_block_end, 3, 0, 0),
  [209] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_block_end, 3, 0, 0),
  [211] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_paragraph, 2, 0, 0),
  [213] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_paragraph, 2, 0, 0),
  [215] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_headline, 4, 0, 2),
  [217] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_headline, 4, 0, 2),
  [219] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_list_item, 4, 0, 0),
  [221] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_list_item, 4, 0, 0),
  [223] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_block, 2, 0, 0),
  [225] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_block, 2, 0, 0),
  [227] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_drawer, 9, 0, 0),
  [229] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_drawer, 9, 0, 0),
  [231] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_headline, 8, 0, 19),
  [233] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_headline, 8, 0, 19),
  [235] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_headline, 8, 0, 18),
  [237] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_headline, 8, 0, 18),
  [239] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_link, 4, 0, 0),
  [241] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_link, 4, 0, 0),
  [243] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_macro, 4, 0, 0),
  [245] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_macro, 4, 0, 0),
  [247] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_headline, 3, 0, 0),
  [249] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_headline, 3, 0, 0),
  [251] = {.entry = {.count = 1, .reusable = false}}, SHIFT(42),
  [253] = {.entry = {.count = 1, .reusable = false}}, SHIFT(93),
  [255] = {.entry = {.count = 1, .reusable = false}}, SHIFT(97),
  [257] = {.entry = {.count = 1, .reusable = true}}, SHIFT(73),
  [259] = {.entry = {.count = 1, .reusable = true}}, SHIFT(79),
  [261] = {.entry = {.count = 1, .reusable = false}}, SHIFT(70),
  [263] = {.entry = {.count = 1, .reusable = true}}, SHIFT(100),
  [265] = {.entry = {.count = 1, .reusable = false}}, SHIFT(19),
  [267] = {.entry = {.count = 1, .reusable = false}}, SHIFT(47),
  [269] = {.entry = {.count = 1, .reusable = false}}, SHIFT(101),
  [271] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_property_drawer_repeat1, 2, 0, 0), SHIFT_REPEAT(70),
  [274] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_property_drawer_repeat1, 2, 0, 0),
  [276] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_table_row_repeat1, 2, 0, 0),
  [278] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_table_row_repeat1, 2, 0, 0), SHIFT_REPEAT(47),
  [281] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_table_row_repeat1, 2, 0, 0), SHIFT_REPEAT(101),
  [284] = {.entry = {.count = 1, .reusable = false}}, SHIFT(30),
  [286] = {.entry = {.count = 1, .reusable = false}}, SHIFT(88),
  [288] = {.entry = {.count = 1, .reusable = true}}, SHIFT(69),
  [290] = {.entry = {.count = 1, .reusable = true}}, SHIFT(86),
  [292] = {.entry = {.count = 1, .reusable = false}}, SHIFT(8),
  [294] = {.entry = {.count = 1, .reusable = false}}, SHIFT(45),
  [296] = {.entry = {.count = 1, .reusable = true}}, SHIFT(29),
  [298] = {.entry = {.count = 1, .reusable = true}}, SHIFT(68),
  [300] = {.entry = {.count = 1, .reusable = true}}, SHIFT(89),
  [302] = {.entry = {.count = 1, .reusable = true}}, SHIFT(72),
  [304] = {.entry = {.count = 1, .reusable = false}}, SHIFT(71),
  [306] = {.entry = {.count = 1, .reusable = true}}, SHIFT(70),
  [308] = {.entry = {.count = 1, .reusable = true}}, SHIFT(14),
  [310] = {.entry = {.count = 1, .reusable = true}}, SHIFT(56),
  [312] = {.entry = {.count = 1, .reusable = true}}, SHIFT(120),
  [314] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_block_begin, 6, 0, 7),
  [316] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_block_begin, 6, 0, 7),
  [318] = {.entry = {.count = 1, .reusable = true}}, SHIFT(39),
  [320] = {.entry = {.count = 1, .reusable = true}}, SHIFT(128),
  [322] = {.entry = {.count = 1, .reusable = false}}, SHIFT(67),
  [324] = {.entry = {.count = 1, .reusable = false}}, SHIFT(94),
  [326] = {.entry = {.count = 1, .reusable = true}}, SHIFT(137),
  [328] = {.entry = {.count = 1, .reusable = true}}, SHIFT(126),
  [330] = {.entry = {.count = 1, .reusable = true}}, SHIFT(123),
  [332] = {.entry = {.count = 1, .reusable = true}}, SHIFT(119),
  [334] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_block_begin, 3, 0, 1),
  [336] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_block_begin, 3, 0, 1),
  [338] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_property, 6, 0, 0),
  [340] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_property, 6, 0, 0),
  [342] = {.entry = {.count = 1, .reusable = false}}, SHIFT(81),
  [344] = {.entry = {.count = 1, .reusable = false}}, SHIFT(82),
  [346] = {.entry = {.count = 1, .reusable = true}}, SHIFT(74),
  [348] = {.entry = {.count = 1, .reusable = true}}, SHIFT(133),
  [350] = {.entry = {.count = 1, .reusable = false}}, SHIFT(109),
  [352] = {.entry = {.count = 1, .reusable = false}}, SHIFT(60),
  [354] = {.entry = {.count = 1, .reusable = false}}, SHIFT(114),
  [356] = {.entry = {.count = 1, .reusable = true}}, SHIFT(115),
  [358] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_block_begin, 5, 0, 7),
  [360] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_block_begin, 5, 0, 7),
  [362] = {.entry = {.count = 1, .reusable = true}}, SHIFT(20),
  [364] = {.entry = {.count = 1, .reusable = true}}, SHIFT(107),
  [366] = {.entry = {.count = 1, .reusable = true}}, SHIFT(22),
  [368] = {.entry = {.count = 1, .reusable = true}}, SHIFT(103),
  [370] = {.entry = {.count = 1, .reusable = true}}, SHIFT(98),
  [372] = {.entry = {.count = 1, .reusable = true}}, SHIFT(106),
  [374] = {.entry = {.count = 1, .reusable = false}}, SHIFT(102),
  [376] = {.entry = {.count = 1, .reusable = true}}, SHIFT(71),
  [378] = {.entry = {.count = 1, .reusable = true}}, SHIFT(34),
  [380] = {.entry = {.count = 1, .reusable = true}}, SHIFT(105),
  [382] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_drawer_name, 1, 0, 0),
  [384] = {.entry = {.count = 1, .reusable = true}}, SHIFT(112),
  [386] = {.entry = {.count = 1, .reusable = true}}, SHIFT(91),
  [388] = {.entry = {.count = 1, .reusable = true}}, SHIFT(43),
  [390] = {.entry = {.count = 1, .reusable = true}}, SHIFT(92),
  [392] = {.entry = {.count = 1, .reusable = true}}, SHIFT(24),
  [394] = {.entry = {.count = 1, .reusable = true}}, SHIFT(28),
  [396] = {.entry = {.count = 1, .reusable = true}}, SHIFT(95),
  [398] = {.entry = {.count = 1, .reusable = true}}, SHIFT(26),
  [400] = {.entry = {.count = 1, .reusable = true}}, SHIFT(66),
  [402] = {.entry = {.count = 1, .reusable = true}}, SHIFT(23),
  [404] = {.entry = {.count = 1, .reusable = true}}, SHIFT(52),
  [406] = {.entry = {.count = 1, .reusable = true}}, SHIFT(21),
  [408] = {.entry = {.count = 1, .reusable = true}}, SHIFT(25),
  [410] = {.entry = {.count = 1, .reusable = true}}, SHIFT(53),
  [412] = {.entry = {.count = 1, .reusable = true}}, SHIFT(18),
  [414] = {.entry = {.count = 1, .reusable = true}}, SHIFT(108),
  [416] = {.entry = {.count = 1, .reusable = true}}, SHIFT(110),
  [418] = {.entry = {.count = 1, .reusable = true}}, SHIFT(17),
  [420] = {.entry = {.count = 1, .reusable = true}}, SHIFT(48),
  [422] = {.entry = {.count = 1, .reusable = true}}, SHIFT(55),
  [424] = {.entry = {.count = 1, .reusable = true}}, SHIFT(16),
  [426] = {.entry = {.count = 1, .reusable = true}}, SHIFT(62),
  [428] = {.entry = {.count = 1, .reusable = true}}, SHIFT(50),
  [430] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_key, 1, 0, 0),
  [432] = {.entry = {.count = 1, .reusable = true}}, SHIFT(116),
  [434] = {.entry = {.count = 1, .reusable = true}}, SHIFT(117),
  [436] = {.entry = {.count = 1, .reusable = true}}, SHIFT(54),
  [438] = {.entry = {.count = 1, .reusable = true}}, SHIFT(84),
  [440] = {.entry = {.count = 1, .reusable = true}}, SHIFT(15),
  [442] = {.entry = {.count = 1, .reusable = true}}, SHIFT(111),
  [444] = {.entry = {.count = 1, .reusable = true}}, SHIFT(31),
  [446] = {.entry = {.count = 1, .reusable = true}}, SHIFT(32),
  [448] = {.entry = {.count = 1, .reusable = true}}, SHIFT(13),
  [450] = {.entry = {.count = 1, .reusable = true}}, SHIFT(83),
  [452] = {.entry = {.count = 1, .reusable = true}}, SHIFT(57),
  [454] = {.entry = {.count = 1, .reusable = true}}, SHIFT(12),
  [456] = {.entry = {.count = 1, .reusable = true}}, SHIFT(35),
  [458] = {.entry = {.count = 1, .reusable = true}}, SHIFT(80),
  [460] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [462] = {.entry = {.count = 1, .reusable = true}}, SHIFT(124),
  [464] = {.entry = {.count = 1, .reusable = true}}, SHIFT(125),
  [466] = {.entry = {.count = 1, .reusable = true}}, SHIFT(64),
  [468] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
  [470] = {.entry = {.count = 1, .reusable = true}}, SHIFT(33),
  [472] = {.entry = {.count = 1, .reusable = true}}, SHIFT(40),
  [474] = {.entry = {.count = 1, .reusable = true}}, SHIFT(38),
  [476] = {.entry = {.count = 1, .reusable = true}}, SHIFT(85),
  [478] = {.entry = {.count = 1, .reusable = true}}, SHIFT(87),
  [480] = {.entry = {.count = 1, .reusable = true}}, SHIFT(78),
  [482] = {.entry = {.count = 1, .reusable = true}}, SHIFT(9),
  [484] = {.entry = {.count = 1, .reusable = true}}, SHIFT(132),
  [486] = {.entry = {.count = 1, .reusable = true}}, SHIFT(41),
  [488] = {.entry = {.count = 1, .reusable = true}}, SHIFT(96),
  [490] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
  [492] = {.entry = {.count = 1, .reusable = true}}, SHIFT(65),
  [494] = {.entry = {.count = 1, .reusable = true}}, SHIFT(104),
  [496] = {.entry = {.count = 1, .reusable = true}}, SHIFT(75),
  [498] = {.entry = {.count = 1, .reusable = true}}, SHIFT(37),
  [500] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_value, 1, 0, 0),
  [502] = {.entry = {.count = 1, .reusable = true}}, SHIFT(61),
  [504] = {.entry = {.count = 1, .reusable = true}}, SHIFT(59),
  [506] = {.entry = {.count = 1, .reusable = true}}, SHIFT(58),
  [508] = {.entry = {.count = 1, .reusable = true}}, SHIFT(76),
};

enum ts_external_scanner_symbol_identifiers {
  ts_external_token_HEADLINE_TITLE = 0,
  ts_external_token_HEADLINE_TAGS = 1,
};

static const TSSymbol ts_external_scanner_symbol_map[EXTERNAL_TOKEN_COUNT] = {
  [ts_external_token_HEADLINE_TITLE] = sym_HEADLINE_TITLE,
  [ts_external_token_HEADLINE_TAGS] = sym_HEADLINE_TAGS,
};

static const bool ts_external_scanner_states[3][EXTERNAL_TOKEN_COUNT] = {
  [1] = {
    [ts_external_token_HEADLINE_TITLE] = true,
    [ts_external_token_HEADLINE_TAGS] = true,
  },
  [2] = {
    [ts_external_token_HEADLINE_TAGS] = true,
  },
};

#ifdef __cplusplus
extern "C" {
#endif
void *tree_sitter_org_external_scanner_create(void);
void tree_sitter_org_external_scanner_destroy(void *);
bool tree_sitter_org_external_scanner_scan(void *, TSLexer *, const bool *);
unsigned tree_sitter_org_external_scanner_serialize(void *, char *);
void tree_sitter_org_external_scanner_deserialize(void *, const char *, unsigned);

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
    .external_scanner = {
      &ts_external_scanner_states[0][0],
      ts_external_scanner_symbol_map,
      tree_sitter_org_external_scanner_create,
      tree_sitter_org_external_scanner_destroy,
      tree_sitter_org_external_scanner_scan,
      tree_sitter_org_external_scanner_serialize,
      tree_sitter_org_external_scanner_deserialize,
    },
    .primary_state_ids = ts_primary_state_ids,
  };
  return &language;
}
#ifdef __cplusplus
}
#endif
