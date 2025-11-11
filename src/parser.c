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
#define STATE_COUNT 141
#define LARGE_STATE_COUNT 4
#define SYMBOL_COUNT 87
#define ALIAS_COUNT 1
#define TOKEN_COUNT 55
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 6
#define MAX_ALIAS_SEQUENCE_LENGTH 9
#define PRODUCTION_ID_COUNT 14

enum ts_symbol_identifiers {
  anon_sym_SPACE = 1,
  anon_sym_LF = 2,
  sym_stars = 3,
  sym_keyword = 4,
  sym_priority = 5,
  aux_sym_title_token1 = 6,
  sym_planning_line = 7,
  sym_clock = 8,
  sym_diary_sexp = 9,
  sym_timestamp = 10,
  anon_sym_LBRACE_LBRACE_LBRACE = 11,
  aux_sym_macro_token1 = 12,
  anon_sym_LPAREN = 13,
  aux_sym_macro_token2 = 14,
  anon_sym_RPAREN = 15,
  anon_sym_RBRACE_RBRACE_RBRACE = 16,
  sym_footnote_reference = 17,
  sym_latex_fragment = 18,
  sym_entity = 19,
  sym_subscript = 20,
  sym_superscript = 21,
  anon_sym_LBRACK_LBRACK = 22,
  aux_sym_link_token1 = 23,
  anon_sym_RBRACK_LBRACK = 24,
  anon_sym_RBRACK_RBRACK = 25,
  aux_sym_list_item_token1 = 26,
  aux_sym_list_item_token2 = 27,
  sym_bullet = 28,
  aux_sym_block_begin_token1 = 29,
  sym_block_type = 30,
  sym_language = 31,
  sym_block_content = 32,
  aux_sym_block_end_token1 = 33,
  aux_sym_dynamic_block_begin_token1 = 34,
  aux_sym_dynamic_block_begin_token2 = 35,
  sym_dynamic_block_content = 36,
  aux_sym_dynamic_block_end_token1 = 37,
  anon_sym_PIPE = 38,
  sym_table_cell = 39,
  sym_table_separator = 40,
  aux_sym_directive_token1 = 41,
  anon_sym_COLON = 42,
  sym_name = 43,
  aux_sym_comment_token1 = 44,
  aux_sym_fixed_width_token1 = 45,
  anon_sym_COLONPROPERTIES_COLON = 46,
  aux_sym_property_drawer_token1 = 47,
  anon_sym_COLONEND_COLON = 48,
  aux_sym_key_token1 = 49,
  anon_sym_COLONend_COLON = 50,
  sym_drawer_content = 51,
  sym_horizontal_rule = 52,
  aux_sym_paragraph_token1 = 53,
  aux_sym_paragraph_token2 = 54,
  sym_document = 55,
  sym__element = 56,
  sym_headline = 57,
  sym_title = 58,
  sym_macro = 59,
  sym_link = 60,
  sym_list = 61,
  sym_list_item = 62,
  sym_block = 63,
  sym_block_begin = 64,
  sym_block_end = 65,
  sym_dynamic_block = 66,
  sym_dynamic_block_begin = 67,
  sym_dynamic_block_end = 68,
  sym_table = 69,
  sym_table_row = 70,
  sym_directive = 71,
  sym_comment = 72,
  sym_fixed_width = 73,
  sym_property_drawer = 74,
  sym_property = 75,
  sym_key = 76,
  sym_value = 77,
  sym_drawer = 78,
  sym_drawer_name = 79,
  sym_paragraph = 80,
  aux_sym_document_repeat1 = 81,
  aux_sym_list_repeat1 = 82,
  aux_sym_table_repeat1 = 83,
  aux_sym_table_row_repeat1 = 84,
  aux_sym_fixed_width_repeat1 = 85,
  aux_sym_property_drawer_repeat1 = 86,
  alias_sym_link_description = 87,
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
  [sym_diary_sexp] = "diary_sexp",
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
  [aux_sym_dynamic_block_begin_token1] = "dynamic_block_begin_token1",
  [aux_sym_dynamic_block_begin_token2] = "dynamic_block_begin_token2",
  [sym_dynamic_block_content] = "dynamic_block_content",
  [aux_sym_dynamic_block_end_token1] = "dynamic_block_end_token1",
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
  [sym_dynamic_block] = "dynamic_block",
  [sym_dynamic_block_begin] = "dynamic_block_begin",
  [sym_dynamic_block_end] = "dynamic_block_end",
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
  [sym_diary_sexp] = sym_diary_sexp,
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
  [aux_sym_dynamic_block_begin_token1] = aux_sym_dynamic_block_begin_token1,
  [aux_sym_dynamic_block_begin_token2] = aux_sym_dynamic_block_begin_token2,
  [sym_dynamic_block_content] = sym_dynamic_block_content,
  [aux_sym_dynamic_block_end_token1] = aux_sym_dynamic_block_end_token1,
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
  [sym_dynamic_block] = sym_dynamic_block,
  [sym_dynamic_block_begin] = sym_dynamic_block_begin,
  [sym_dynamic_block_end] = sym_dynamic_block_end,
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
  [sym_diary_sexp] = {
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
  [aux_sym_dynamic_block_begin_token1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_dynamic_block_begin_token2] = {
    .visible = false,
    .named = false,
  },
  [sym_dynamic_block_content] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_dynamic_block_end_token1] = {
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
  [sym_dynamic_block] = {
    .visible = true,
    .named = true,
  },
  [sym_dynamic_block_begin] = {
    .visible = true,
    .named = true,
  },
  [sym_dynamic_block_end] = {
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
  field_name = 3,
  field_priority = 4,
  field_title = 5,
  field_type = 6,
};

static const char * const ts_field_names[] = {
  [0] = NULL,
  [field_keyword] = "keyword",
  [field_language] = "language",
  [field_name] = "name",
  [field_priority] = "priority",
  [field_title] = "title",
  [field_type] = "type",
};

static const TSFieldMapSlice ts_field_map_slices[PRODUCTION_ID_COUNT] = {
  [1] = {.index = 0, .length = 1},
  [2] = {.index = 1, .length = 1},
  [3] = {.index = 2, .length = 1},
  [4] = {.index = 3, .length = 1},
  [5] = {.index = 4, .length = 1},
  [6] = {.index = 5, .length = 2},
  [8] = {.index = 7, .length = 2},
  [9] = {.index = 9, .length = 2},
  [12] = {.index = 11, .length = 2},
  [13] = {.index = 13, .length = 3},
};

static const TSFieldMapEntry ts_field_map_entries[] = {
  [0] =
    {field_type, 1},
  [1] =
    {field_title, 2},
  [2] =
    {field_name, 2},
  [3] =
    {field_keyword, 2},
  [4] =
    {field_priority, 2},
  [5] =
    {field_language, 3},
    {field_type, 1},
  [7] =
    {field_keyword, 2},
    {field_title, 4},
  [9] =
    {field_priority, 2},
    {field_title, 4},
  [11] =
    {field_keyword, 2},
    {field_priority, 4},
  [13] =
    {field_keyword, 2},
    {field_priority, 4},
    {field_title, 6},
};

static const TSSymbol ts_alias_sequences[PRODUCTION_ID_COUNT][MAX_ALIAS_SEQUENCE_LENGTH] = {
  [0] = {0},
  [7] = {
    [3] = sym_value,
  },
  [10] = {
    [3] = alias_sym_link_description,
  },
  [11] = {
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
  [138] = 138,
  [139] = 139,
  [140] = 140,
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(158);
      ADVANCE_MAP(
        '#', 26,
        '$', 32,
        '%', 36,
        '(', 234,
        ')', 237,
        '*', 168,
        '-', 50,
        ':', 283,
        '<', 150,
        'C', 209,
        'D', 227,
        'N', 214,
        'T', 225,
        'W', 210,
        '[', 28,
        '\\', 148,
        ']', 85,
        '_', 262,
        '{', 105,
        '|', 275,
        '}', 107,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(0);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(231);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(232);
      END_STATE();
    case 1:
      if (lookahead == '\n') ADVANCE(241);
      END_STATE();
    case 2:
      if (lookahead == '\n') ADVANCE(241);
      if (lookahead == '{') ADVANCE(108);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(2);
      END_STATE();
    case 3:
      if (lookahead == '\n') ADVANCE(279);
      if (lookahead == '+') ADVANCE(45);
      if (lookahead == '-') ADVANCE(3);
      if (lookahead == '|') ADVANCE(4);
      END_STATE();
    case 4:
      if (lookahead == '\n') ADVANCE(279);
      if (lookahead == '-') ADVANCE(3);
      END_STATE();
    case 5:
      if (lookahead == '\n') ADVANCE(240);
      END_STATE();
    case 6:
      if (lookahead == '\n') ADVANCE(206);
      END_STATE();
    case 7:
      if (lookahead == '\n') ADVANCE(39);
      if (lookahead == '(') ADVANCE(7);
      if (lookahead == ')') ADVANCE(9);
      if (lookahead != 0) ADVANCE(7);
      END_STATE();
    case 8:
      if (lookahead == '\n') ADVANCE(205);
      END_STATE();
    case 9:
      if (lookahead == '\n') ADVANCE(205);
      if (lookahead == '(') ADVANCE(7);
      if (lookahead == ')') ADVANCE(8);
      if (lookahead != 0) ADVANCE(38);
      END_STATE();
    case 10:
      if (lookahead == '\n') ADVANCE(299);
      if (lookahead == '-') ADVANCE(10);
      END_STATE();
    case 11:
      if (lookahead == '\n') ADVANCE(239);
      END_STATE();
    case 12:
      if (lookahead == '\n') ADVANCE(243);
      if (lookahead != 0) ADVANCE(12);
      END_STATE();
    case 13:
      if (lookahead == '\n') ADVANCE(242);
      if (lookahead != 0) ADVANCE(13);
      END_STATE();
    case 14:
      if (lookahead == '\n') ADVANCE(204);
      END_STATE();
    case 15:
      if (lookahead == '\n') ADVANCE(204);
      if (lookahead == '-') ADVANCE(46);
      END_STATE();
    case 16:
      if (lookahead == '\n') ADVANCE(161);
      if (lookahead == 'C') ADVANCE(176);
      if (lookahead == 'D') ADVANCE(194);
      if (lookahead == 'N') ADVANCE(182);
      if (lookahead == 'T') ADVANCE(193);
      if (lookahead == 'W') ADVANCE(177);
      if (lookahead == '[') ADVANCE(175);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(172);
      if (lookahead != 0) ADVANCE(202);
      END_STATE();
    case 17:
      if (lookahead == '\n') ADVANCE(162);
      if (lookahead == '[') ADVANCE(175);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(173);
      if (lookahead != 0) ADVANCE(202);
      END_STATE();
    case 18:
      if (lookahead == '\n') ADVANCE(163);
      if (lookahead == '|') ADVANCE(274);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(277);
      if (lookahead != 0) ADVANCE(278);
      END_STATE();
    case 19:
      if (lookahead == '\n') SKIP(19);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(200);
      if (lookahead != 0) ADVANCE(202);
      END_STATE();
    case 20:
      if (lookahead == '\n') ADVANCE(164);
      if (lookahead == ' ') ADVANCE(159);
      if (('\t' <= lookahead && lookahead <= '\r')) SKIP(20);
      END_STATE();
    case 21:
      if (lookahead == '\n') SKIP(21);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(199);
      if ((0x0b <= lookahead && lookahead <= '\r')) ADVANCE(199);
      if (lookahead != 0) ADVANCE(202);
      END_STATE();
    case 22:
      if (lookahead == '\n') ADVANCE(165);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(22);
      END_STATE();
    case 23:
      if (lookahead == '\n') SKIP(23);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(246);
      if (lookahead != 0 &&
          lookahead != ']') ADVANCE(247);
      END_STATE();
    case 24:
      if (lookahead == '\n') ADVANCE(411);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(24);
      END_STATE();
    case 25:
      if (lookahead == '\n') ADVANCE(166);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(174);
      if (lookahead != 0) ADVANCE(202);
      END_STATE();
    case 26:
      if (lookahead == ' ') ADVANCE(287);
      if (lookahead == '+') ADVANCE(280);
      END_STATE();
    case 27:
      if (lookahead == ' ') ADVANCE(160);
      if (('\t' <= lookahead && lookahead <= '\r')) SKIP(27);
      END_STATE();
    case 28:
      if (lookahead == '#') ADVANCE(147);
      if (lookahead == '[') ADVANCE(244);
      if (lookahead == 'f') ADVANCE(102);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(88);
      END_STATE();
    case 29:
      if (lookahead == '#') ADVANCE(41);
      if (lookahead == ':') ADVANCE(285);
      if (lookahead == '|') ADVANCE(274);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(29);
      if (lookahead == '-' ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(295);
      END_STATE();
    case 30:
      if (lookahead == '#') ADVANCE(40);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(271);
      if (lookahead != 0) ADVANCE(272);
      END_STATE();
    case 31:
      if (lookahead == '#') ADVANCE(42);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(265);
      if (lookahead != 0) ADVANCE(266);
      END_STATE();
    case 32:
      if (lookahead == '$') ADVANCE(153);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(34);
      END_STATE();
    case 33:
      if (lookahead == '$') ADVANCE(5);
      END_STATE();
    case 34:
      if (lookahead == '$') ADVANCE(5);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(34);
      END_STATE();
    case 35:
      if (lookahead == '$') ADVANCE(33);
      if (lookahead != 0) ADVANCE(35);
      END_STATE();
    case 36:
      if (lookahead == '%') ADVANCE(37);
      END_STATE();
    case 37:
      if (lookahead == '(') ADVANCE(38);
      END_STATE();
    case 38:
      if (lookahead == '(') ADVANCE(7);
      if (lookahead == ')') ADVANCE(8);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(38);
      END_STATE();
    case 39:
      if (lookahead == ')') ADVANCE(38);
      if (lookahead != 0) ADVANCE(39);
      END_STATE();
    case 40:
      if (lookahead == '+') ADVANCE(124);
      if (lookahead != 0) ADVANCE(272);
      END_STATE();
    case 41:
      if (lookahead == '+') ADVANCE(125);
      END_STATE();
    case 42:
      if (lookahead == '+') ADVANCE(126);
      if (lookahead != 0) ADVANCE(266);
      END_STATE();
    case 43:
      if (lookahead == '+') ADVANCE(128);
      if (lookahead != 0) ADVANCE(272);
      END_STATE();
    case 44:
      if (lookahead == '+') ADVANCE(129);
      if (lookahead != 0) ADVANCE(266);
      END_STATE();
    case 45:
      if (lookahead == '-') ADVANCE(3);
      END_STATE();
    case 46:
      if (lookahead == '-') ADVANCE(86);
      END_STATE();
    case 47:
      if (lookahead == '-') ADVANCE(10);
      END_STATE();
    case 48:
      if (lookahead == '-') ADVANCE(47);
      END_STATE();
    case 49:
      if (lookahead == '-') ADVANCE(48);
      END_STATE();
    case 50:
      if (lookahead == '-') ADVANCE(49);
      END_STATE();
    case 51:
      if (lookahead == ':') ADVANCE(53);
      END_STATE();
    case 52:
      if (lookahead == ':') ADVANCE(155);
      if (lookahead == ']') ADVANCE(11);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(52);
      END_STATE();
    case 53:
      if (lookahead == ':') ADVANCE(155);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(52);
      END_STATE();
    case 54:
      if (lookahead == ':') ADVANCE(268);
      if (lookahead == '_') ADVANCE(260);
      END_STATE();
    case 55:
      if (lookahead == ':') ADVANCE(291);
      END_STATE();
    case 56:
      if (lookahead == ':') ADVANCE(109);
      if (lookahead == '^') ADVANCE(151);
      if (lookahead == '_') ADVANCE(152);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(98);
      END_STATE();
    case 57:
      if (lookahead == ':') ADVANCE(294);
      END_STATE();
    case 58:
      if (lookahead == ':') ADVANCE(273);
      if (lookahead == '_') ADVANCE(267);
      END_STATE();
    case 59:
      if (lookahead == ':') ADVANCE(273);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(272);
      END_STATE();
    case 60:
      if (lookahead == ':') ADVANCE(282);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(60);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(270);
      END_STATE();
    case 61:
      if (lookahead == ':') ADVANCE(74);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(297);
      if (lookahead != 0) ADVANCE(298);
      END_STATE();
    case 62:
      if (lookahead == ':') ADVANCE(296);
      END_STATE();
    case 63:
      if (lookahead == ':') ADVANCE(296);
      if (lookahead != 0) ADVANCE(298);
      END_STATE();
    case 64:
      if (lookahead == ':') ADVANCE(101);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(64);
      if (lookahead == '+' ||
          lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(264);
      END_STATE();
    case 65:
      if (lookahead == ':') ADVANCE(145);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(65);
      END_STATE();
    case 66:
      if (lookahead == '=') ADVANCE(69);
      if (lookahead == '[') ADVANCE(143);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(66);
      END_STATE();
    case 67:
      if (lookahead == '=') ADVANCE(69);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(67);
      END_STATE();
    case 68:
      if (lookahead == '>') ADVANCE(6);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(68);
      END_STATE();
    case 69:
      if (lookahead == '>') ADVANCE(110);
      END_STATE();
    case 70:
      if (lookahead == 'D') ADVANCE(154);
      if (lookahead == 'd') ADVANCE(63);
      if (lookahead != 0) ADVANCE(298);
      END_STATE();
    case 71:
      if (lookahead == 'D') ADVANCE(57);
      END_STATE();
    case 72:
      if (lookahead == 'E') ADVANCE(82);
      END_STATE();
    case 73:
      if (lookahead == 'E') ADVANCE(81);
      END_STATE();
    case 74:
      if (lookahead == 'E') ADVANCE(138);
      if (lookahead == 'e') ADVANCE(77);
      if (lookahead != 0) ADVANCE(298);
      END_STATE();
    case 75:
      if (lookahead == 'I') ADVANCE(72);
      END_STATE();
    case 76:
      if (lookahead == 'N') ADVANCE(71);
      END_STATE();
    case 77:
      if (lookahead == 'N') ADVANCE(121);
      if (lookahead == 'n') ADVANCE(70);
      if (lookahead != 0) ADVANCE(298);
      END_STATE();
    case 78:
      if (lookahead == 'O') ADVANCE(79);
      END_STATE();
    case 79:
      if (lookahead == 'P') ADVANCE(73);
      END_STATE();
    case 80:
      if (lookahead == 'R') ADVANCE(78);
      END_STATE();
    case 81:
      if (lookahead == 'R') ADVANCE(83);
      END_STATE();
    case 82:
      if (lookahead == 'S') ADVANCE(55);
      END_STATE();
    case 83:
      if (lookahead == 'T') ADVANCE(75);
      END_STATE();
    case 84:
      if (lookahead == '[') ADVANCE(244);
      if (lookahead == 'f') ADVANCE(102);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(88);
      END_STATE();
    case 85:
      if (lookahead == '[') ADVANCE(248);
      if (lookahead == ']') ADVANCE(249);
      END_STATE();
    case 86:
      if (lookahead == '[') ADVANCE(144);
      END_STATE();
    case 87:
      if (lookahead == ']') ADVANCE(171);
      END_STATE();
    case 88:
      if (lookahead == ']') ADVANCE(6);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(88);
      END_STATE();
    case 89:
      if (lookahead == ']') ADVANCE(15);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(89);
      END_STATE();
    case 90:
      if (lookahead == ']') ADVANCE(112);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(90);
      END_STATE();
    case 91:
      if (lookahead == ']') ADVANCE(11);
      if (lookahead != 0) ADVANCE(91);
      END_STATE();
    case 92:
      if (lookahead == '^') ADVANCE(151);
      if (lookahead == '_') ADVANCE(152);
      if (lookahead == ')' ||
          lookahead == '.') ADVANCE(256);
      if (lookahead == 'L' ||
          lookahead == 'l') ADVANCE(97);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(98);
      END_STATE();
    case 93:
      if (lookahead == '^') ADVANCE(151);
      if (lookahead == '_') ADVANCE(152);
      if (lookahead == ')' ||
          lookahead == '.') ADVANCE(256);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(93);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(98);
      END_STATE();
    case 94:
      if (lookahead == '^') ADVANCE(151);
      if (lookahead == '_') ADVANCE(152);
      if (lookahead == ')' ||
          lookahead == '.') ADVANCE(256);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(98);
      END_STATE();
    case 95:
      if (lookahead == '^') ADVANCE(151);
      if (lookahead == '_') ADVANCE(152);
      if (lookahead == 'C' ||
          lookahead == 'c') ADVANCE(96);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(98);
      END_STATE();
    case 96:
      if (lookahead == '^') ADVANCE(151);
      if (lookahead == '_') ADVANCE(152);
      if (lookahead == 'K' ||
          lookahead == 'k') ADVANCE(56);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(98);
      END_STATE();
    case 97:
      if (lookahead == '^') ADVANCE(151);
      if (lookahead == '_') ADVANCE(152);
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(95);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(98);
      END_STATE();
    case 98:
      if (lookahead == '^') ADVANCE(151);
      if (lookahead == '_') ADVANCE(152);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(98);
      END_STATE();
    case 99:
      if (lookahead == '_') ADVANCE(267);
      if (lookahead != 0) ADVANCE(266);
      END_STATE();
    case 100:
      if (lookahead == 'd') ADVANCE(62);
      END_STATE();
    case 101:
      if (lookahead == 'e') ADVANCE(103);
      END_STATE();
    case 102:
      if (lookahead == 'n') ADVANCE(51);
      END_STATE();
    case 103:
      if (lookahead == 'n') ADVANCE(100);
      END_STATE();
    case 104:
      if (lookahead == '{') ADVANCE(207);
      END_STATE();
    case 105:
      if (lookahead == '{') ADVANCE(104);
      END_STATE();
    case 106:
      if (lookahead == '}') ADVANCE(238);
      END_STATE();
    case 107:
      if (lookahead == '}') ADVANCE(106);
      END_STATE();
    case 108:
      if (lookahead == '}') ADVANCE(1);
      END_STATE();
    case 109:
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(66);
      END_STATE();
    case 110:
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(111);
      END_STATE();
    case 111:
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(111);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(65);
      END_STATE();
    case 112:
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(67);
      END_STATE();
    case 113:
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(251);
      if (('\n' <= lookahead && lookahead <= '\r')) SKIP(113);
      END_STATE();
    case 114:
      if (lookahead == ')' ||
          lookahead == '.') ADVANCE(256);
      END_STATE();
    case 115:
      if (lookahead == ')' ||
          lookahead == '.') ADVANCE(256);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(115);
      END_STATE();
    case 116:
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(256);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(116);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(115);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(114);
      END_STATE();
    case 117:
      if (lookahead == 'D' ||
          lookahead == 'd') ADVANCE(59);
      if (lookahead != 0) ADVANCE(272);
      END_STATE();
    case 118:
      if (lookahead == 'D' ||
          lookahead == 'd') ADVANCE(149);
      if (lookahead != 0) ADVANCE(272);
      END_STATE();
    case 119:
      if (lookahead == 'D' ||
          lookahead == 'd') ADVANCE(99);
      if (lookahead != 0) ADVANCE(266);
      END_STATE();
    case 120:
      if (lookahead == 'D' ||
          lookahead == 'd') ADVANCE(156);
      if (lookahead != 0) ADVANCE(266);
      END_STATE();
    case 121:
      if (lookahead == 'D' ||
          lookahead == 'd') ADVANCE(154);
      if (lookahead != 0) ADVANCE(298);
      END_STATE();
    case 122:
      if (lookahead == 'D' ||
          lookahead == 'd') ADVANCE(58);
      END_STATE();
    case 123:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(130);
      END_STATE();
    case 124:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(134);
      if (lookahead != 0) ADVANCE(272);
      END_STATE();
    case 125:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(133);
      END_STATE();
    case 126:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(136);
      if (lookahead != 0) ADVANCE(266);
      END_STATE();
    case 127:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(138);
      if (lookahead != 0) ADVANCE(298);
      END_STATE();
    case 128:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(135);
      if (lookahead != 0) ADVANCE(272);
      END_STATE();
    case 129:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(137);
      if (lookahead != 0) ADVANCE(266);
      END_STATE();
    case 130:
      if (lookahead == 'G' ||
          lookahead == 'g') ADVANCE(131);
      END_STATE();
    case 131:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(132);
      END_STATE();
    case 132:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(54);
      END_STATE();
    case 133:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(122);
      END_STATE();
    case 134:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(117);
      if (lookahead != 0) ADVANCE(272);
      END_STATE();
    case 135:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(118);
      if (lookahead != 0) ADVANCE(272);
      END_STATE();
    case 136:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(119);
      if (lookahead != 0) ADVANCE(266);
      END_STATE();
    case 137:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(120);
      if (lookahead != 0) ADVANCE(266);
      END_STATE();
    case 138:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(121);
      if (lookahead != 0) ADVANCE(298);
      END_STATE();
    case 139:
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(235);
      if (lookahead != 0 &&
          lookahead != ')' &&
          lookahead != '}') ADVANCE(236);
      END_STATE();
    case 140:
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(140);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(286);
      END_STATE();
    case 141:
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(141);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(263);
      END_STATE();
    case 142:
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(142);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(233);
      END_STATE();
    case 143:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(89);
      END_STATE();
    case 144:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(90);
      END_STATE();
    case 145:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(146);
      END_STATE();
    case 146:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(14);
      END_STATE();
    case 147:
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(87);
      END_STATE();
    case 148:
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(2);
      END_STATE();
    case 149:
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != ':') ADVANCE(272);
      END_STATE();
    case 150:
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '>') ADVANCE(68);
      END_STATE();
    case 151:
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(12);
      END_STATE();
    case 152:
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(13);
      END_STATE();
    case 153:
      if (lookahead != 0 &&
          lookahead != '$') ADVANCE(35);
      END_STATE();
    case 154:
      if (lookahead != 0 &&
          lookahead != ':') ADVANCE(298);
      END_STATE();
    case 155:
      if (lookahead != 0 &&
          lookahead != ']') ADVANCE(91);
      END_STATE();
    case 156:
      if (lookahead != 0 &&
          lookahead != '_') ADVANCE(266);
      END_STATE();
    case 157:
      if (eof) ADVANCE(158);
      if (lookahead == '\n') SKIP(157);
      if (lookahead == '#') ADVANCE(26);
      if (lookahead == '$') ADVANCE(322);
      if (lookahead == '%') ADVANCE(325);
      if (lookahead == '*') ADVANCE(168);
      if (lookahead == '+') ADVANCE(256);
      if (lookahead == '-') ADVANCE(258);
      if (lookahead == ':') ADVANCE(283);
      if (lookahead == '<') ADVANCE(344);
      if (lookahead == 'C') ADVANCE(363);
      if (lookahead == 'D') ADVANCE(354);
      if (lookahead == 'S') ADVANCE(350);
      if (lookahead == '[') ADVANCE(84);
      if (lookahead == '\\') ADVANCE(407);
      if (lookahead == 'c') ADVANCE(92);
      if (lookahead == '{') ADVANCE(105);
      if (lookahead == '|') ADVANCE(275);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(250);
      if ((0x0b <= lookahead && lookahead <= '\r')) ADVANCE(321);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(93);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(385);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(94);
      if (lookahead != 0) ADVANCE(408);
      END_STATE();
    case 158:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 159:
      ACCEPT_TOKEN(anon_sym_SPACE);
      if (lookahead == '\n') ADVANCE(164);
      if (lookahead == ' ') ADVANCE(159);
      END_STATE();
    case 160:
      ACCEPT_TOKEN(anon_sym_SPACE);
      if (lookahead == ' ') ADVANCE(160);
      END_STATE();
    case 161:
      ACCEPT_TOKEN(anon_sym_LF);
      if (lookahead == '\n') ADVANCE(161);
      if (lookahead == 'C') ADVANCE(176);
      if (lookahead == 'D') ADVANCE(194);
      if (lookahead == 'N') ADVANCE(182);
      if (lookahead == 'T') ADVANCE(193);
      if (lookahead == 'W') ADVANCE(177);
      if (lookahead == '[') ADVANCE(175);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(172);
      END_STATE();
    case 162:
      ACCEPT_TOKEN(anon_sym_LF);
      if (lookahead == '\n') ADVANCE(162);
      if (lookahead == '[') ADVANCE(175);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(173);
      END_STATE();
    case 163:
      ACCEPT_TOKEN(anon_sym_LF);
      if (lookahead == '\n') ADVANCE(163);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(277);
      END_STATE();
    case 164:
      ACCEPT_TOKEN(anon_sym_LF);
      if (lookahead == '\n') ADVANCE(164);
      if (lookahead == ' ') ADVANCE(159);
      END_STATE();
    case 165:
      ACCEPT_TOKEN(anon_sym_LF);
      if (lookahead == '\n') ADVANCE(165);
      END_STATE();
    case 166:
      ACCEPT_TOKEN(anon_sym_LF);
      if (lookahead == '\n') ADVANCE(166);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(174);
      END_STATE();
    case 167:
      ACCEPT_TOKEN(anon_sym_LF);
      if (lookahead == '\n') ADVANCE(167);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(252);
      END_STATE();
    case 168:
      ACCEPT_TOKEN(sym_stars);
      if (lookahead == '*') ADVANCE(168);
      END_STATE();
    case 169:
      ACCEPT_TOKEN(sym_stars);
      if (lookahead == '*') ADVANCE(169);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(408);
      END_STATE();
    case 170:
      ACCEPT_TOKEN(sym_keyword);
      END_STATE();
    case 171:
      ACCEPT_TOKEN(sym_priority);
      END_STATE();
    case 172:
      ACCEPT_TOKEN(aux_sym_title_token1);
      if (lookahead == '\n') ADVANCE(161);
      if (lookahead == 'C') ADVANCE(176);
      if (lookahead == 'D') ADVANCE(194);
      if (lookahead == 'N') ADVANCE(182);
      if (lookahead == 'T') ADVANCE(193);
      if (lookahead == 'W') ADVANCE(177);
      if (lookahead == '[') ADVANCE(175);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(172);
      if (lookahead != 0) ADVANCE(202);
      END_STATE();
    case 173:
      ACCEPT_TOKEN(aux_sym_title_token1);
      if (lookahead == '\n') ADVANCE(162);
      if (lookahead == '[') ADVANCE(175);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(173);
      if (lookahead != 0) ADVANCE(202);
      END_STATE();
    case 174:
      ACCEPT_TOKEN(aux_sym_title_token1);
      if (lookahead == '\n') ADVANCE(166);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(174);
      if (lookahead != 0) ADVANCE(202);
      END_STATE();
    case 175:
      ACCEPT_TOKEN(aux_sym_title_token1);
      if (lookahead == '#') ADVANCE(201);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(202);
      END_STATE();
    case 176:
      ACCEPT_TOKEN(aux_sym_title_token1);
      if (lookahead == 'A') ADVANCE(189);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(202);
      END_STATE();
    case 177:
      ACCEPT_TOKEN(aux_sym_title_token1);
      if (lookahead == 'A') ADVANCE(186);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(202);
      END_STATE();
    case 178:
      ACCEPT_TOKEN(aux_sym_title_token1);
      if (lookahead == 'C') ADVANCE(183);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(202);
      END_STATE();
    case 179:
      ACCEPT_TOKEN(aux_sym_title_token1);
      if (lookahead == 'D') ADVANCE(170);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(202);
      END_STATE();
    case 180:
      ACCEPT_TOKEN(aux_sym_title_token1);
      if (lookahead == 'D') ADVANCE(192);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(202);
      END_STATE();
    case 181:
      ACCEPT_TOKEN(aux_sym_title_token1);
      if (lookahead == 'E') ADVANCE(170);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(202);
      END_STATE();
    case 182:
      ACCEPT_TOKEN(aux_sym_title_token1);
      if (lookahead == 'E') ADVANCE(197);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(202);
      END_STATE();
    case 183:
      ACCEPT_TOKEN(aux_sym_title_token1);
      if (lookahead == 'E') ADVANCE(188);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(202);
      END_STATE();
    case 184:
      ACCEPT_TOKEN(aux_sym_title_token1);
      if (lookahead == 'E') ADVANCE(179);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(202);
      END_STATE();
    case 185:
      ACCEPT_TOKEN(aux_sym_title_token1);
      if (lookahead == 'G') ADVANCE(170);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(202);
      END_STATE();
    case 186:
      ACCEPT_TOKEN(aux_sym_title_token1);
      if (lookahead == 'I') ADVANCE(196);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(202);
      END_STATE();
    case 187:
      ACCEPT_TOKEN(aux_sym_title_token1);
      if (lookahead == 'I') ADVANCE(190);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(202);
      END_STATE();
    case 188:
      ACCEPT_TOKEN(aux_sym_title_token1);
      if (lookahead == 'L') ADVANCE(184);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(202);
      END_STATE();
    case 189:
      ACCEPT_TOKEN(aux_sym_title_token1);
      if (lookahead == 'N') ADVANCE(178);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(202);
      END_STATE();
    case 190:
      ACCEPT_TOKEN(aux_sym_title_token1);
      if (lookahead == 'N') ADVANCE(185);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(202);
      END_STATE();
    case 191:
      ACCEPT_TOKEN(aux_sym_title_token1);
      if (lookahead == 'N') ADVANCE(181);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(202);
      END_STATE();
    case 192:
      ACCEPT_TOKEN(aux_sym_title_token1);
      if (lookahead == 'O') ADVANCE(170);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(202);
      END_STATE();
    case 193:
      ACCEPT_TOKEN(aux_sym_title_token1);
      if (lookahead == 'O') ADVANCE(180);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(202);
      END_STATE();
    case 194:
      ACCEPT_TOKEN(aux_sym_title_token1);
      if (lookahead == 'O') ADVANCE(191);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(202);
      END_STATE();
    case 195:
      ACCEPT_TOKEN(aux_sym_title_token1);
      if (lookahead == 'T') ADVANCE(170);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(202);
      END_STATE();
    case 196:
      ACCEPT_TOKEN(aux_sym_title_token1);
      if (lookahead == 'T') ADVANCE(187);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(202);
      END_STATE();
    case 197:
      ACCEPT_TOKEN(aux_sym_title_token1);
      if (lookahead == 'X') ADVANCE(195);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(202);
      END_STATE();
    case 198:
      ACCEPT_TOKEN(aux_sym_title_token1);
      if (lookahead == ']') ADVANCE(171);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(202);
      END_STATE();
    case 199:
      ACCEPT_TOKEN(aux_sym_title_token1);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(199);
      if ((0x0b <= lookahead && lookahead <= '\r')) ADVANCE(199);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead)) ADVANCE(202);
      END_STATE();
    case 200:
      ACCEPT_TOKEN(aux_sym_title_token1);
      if (lookahead == '\t' ||
          (0x0b <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(200);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead)) ADVANCE(202);
      END_STATE();
    case 201:
      ACCEPT_TOKEN(aux_sym_title_token1);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(198);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(202);
      END_STATE();
    case 202:
      ACCEPT_TOKEN(aux_sym_title_token1);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(202);
      END_STATE();
    case 203:
      ACCEPT_TOKEN(sym_planning_line);
      END_STATE();
    case 204:
      ACCEPT_TOKEN(sym_clock);
      END_STATE();
    case 205:
      ACCEPT_TOKEN(sym_diary_sexp);
      END_STATE();
    case 206:
      ACCEPT_TOKEN(sym_timestamp);
      END_STATE();
    case 207:
      ACCEPT_TOKEN(anon_sym_LBRACE_LBRACE_LBRACE);
      END_STATE();
    case 208:
      ACCEPT_TOKEN(anon_sym_LBRACE_LBRACE_LBRACE);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(408);
      END_STATE();
    case 209:
      ACCEPT_TOKEN(aux_sym_macro_token1);
      if (lookahead == 'A') ADVANCE(222);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(233);
      if (('B' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(231);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(232);
      END_STATE();
    case 210:
      ACCEPT_TOKEN(aux_sym_macro_token1);
      if (lookahead == 'A') ADVANCE(219);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(233);
      if (('B' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(231);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(232);
      END_STATE();
    case 211:
      ACCEPT_TOKEN(aux_sym_macro_token1);
      if (lookahead == 'C') ADVANCE(216);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(233);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(231);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(232);
      END_STATE();
    case 212:
      ACCEPT_TOKEN(aux_sym_macro_token1);
      if (lookahead == 'D') ADVANCE(170);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(233);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(231);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(232);
      END_STATE();
    case 213:
      ACCEPT_TOKEN(aux_sym_macro_token1);
      if (lookahead == 'D') ADVANCE(226);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(233);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(231);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(232);
      END_STATE();
    case 214:
      ACCEPT_TOKEN(aux_sym_macro_token1);
      if (lookahead == 'E') ADVANCE(230);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(233);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(231);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(232);
      END_STATE();
    case 215:
      ACCEPT_TOKEN(aux_sym_macro_token1);
      if (lookahead == 'E') ADVANCE(170);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(233);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(231);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(232);
      END_STATE();
    case 216:
      ACCEPT_TOKEN(aux_sym_macro_token1);
      if (lookahead == 'E') ADVANCE(221);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(233);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(231);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(232);
      END_STATE();
    case 217:
      ACCEPT_TOKEN(aux_sym_macro_token1);
      if (lookahead == 'E') ADVANCE(212);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(233);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(231);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(232);
      END_STATE();
    case 218:
      ACCEPT_TOKEN(aux_sym_macro_token1);
      if (lookahead == 'G') ADVANCE(170);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(233);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(231);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(232);
      END_STATE();
    case 219:
      ACCEPT_TOKEN(aux_sym_macro_token1);
      if (lookahead == 'I') ADVANCE(229);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(233);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(231);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(232);
      END_STATE();
    case 220:
      ACCEPT_TOKEN(aux_sym_macro_token1);
      if (lookahead == 'I') ADVANCE(223);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(233);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(231);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(232);
      END_STATE();
    case 221:
      ACCEPT_TOKEN(aux_sym_macro_token1);
      if (lookahead == 'L') ADVANCE(217);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(233);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(231);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(232);
      END_STATE();
    case 222:
      ACCEPT_TOKEN(aux_sym_macro_token1);
      if (lookahead == 'N') ADVANCE(211);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(233);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(231);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(232);
      END_STATE();
    case 223:
      ACCEPT_TOKEN(aux_sym_macro_token1);
      if (lookahead == 'N') ADVANCE(218);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(233);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(231);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(232);
      END_STATE();
    case 224:
      ACCEPT_TOKEN(aux_sym_macro_token1);
      if (lookahead == 'N') ADVANCE(215);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(233);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(231);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(232);
      END_STATE();
    case 225:
      ACCEPT_TOKEN(aux_sym_macro_token1);
      if (lookahead == 'O') ADVANCE(213);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(233);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(231);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(232);
      END_STATE();
    case 226:
      ACCEPT_TOKEN(aux_sym_macro_token1);
      if (lookahead == 'O') ADVANCE(170);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(233);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(231);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(232);
      END_STATE();
    case 227:
      ACCEPT_TOKEN(aux_sym_macro_token1);
      if (lookahead == 'O') ADVANCE(224);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(233);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(231);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(232);
      END_STATE();
    case 228:
      ACCEPT_TOKEN(aux_sym_macro_token1);
      if (lookahead == 'T') ADVANCE(170);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(233);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(231);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(232);
      END_STATE();
    case 229:
      ACCEPT_TOKEN(aux_sym_macro_token1);
      if (lookahead == 'T') ADVANCE(220);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(233);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(231);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(232);
      END_STATE();
    case 230:
      ACCEPT_TOKEN(aux_sym_macro_token1);
      if (lookahead == 'X') ADVANCE(228);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(233);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(231);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(232);
      END_STATE();
    case 231:
      ACCEPT_TOKEN(aux_sym_macro_token1);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(233);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(232);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(231);
      END_STATE();
    case 232:
      ACCEPT_TOKEN(aux_sym_macro_token1);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(233);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(232);
      END_STATE();
    case 233:
      ACCEPT_TOKEN(aux_sym_macro_token1);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(233);
      END_STATE();
    case 234:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      END_STATE();
    case 235:
      ACCEPT_TOKEN(aux_sym_macro_token2);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(235);
      if (lookahead != 0 &&
          lookahead != ')' &&
          lookahead != '}') ADVANCE(236);
      END_STATE();
    case 236:
      ACCEPT_TOKEN(aux_sym_macro_token2);
      if (lookahead != 0 &&
          lookahead != ')' &&
          lookahead != '}') ADVANCE(236);
      END_STATE();
    case 237:
      ACCEPT_TOKEN(anon_sym_RPAREN);
      END_STATE();
    case 238:
      ACCEPT_TOKEN(anon_sym_RBRACE_RBRACE_RBRACE);
      END_STATE();
    case 239:
      ACCEPT_TOKEN(sym_footnote_reference);
      END_STATE();
    case 240:
      ACCEPT_TOKEN(sym_latex_fragment);
      END_STATE();
    case 241:
      ACCEPT_TOKEN(sym_entity);
      END_STATE();
    case 242:
      ACCEPT_TOKEN(sym_subscript);
      END_STATE();
    case 243:
      ACCEPT_TOKEN(sym_superscript);
      END_STATE();
    case 244:
      ACCEPT_TOKEN(anon_sym_LBRACK_LBRACK);
      END_STATE();
    case 245:
      ACCEPT_TOKEN(anon_sym_LBRACK_LBRACK);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(408);
      END_STATE();
    case 246:
      ACCEPT_TOKEN(aux_sym_link_token1);
      if (lookahead == '\t' ||
          (0x0b <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(246);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ']') ADVANCE(247);
      END_STATE();
    case 247:
      ACCEPT_TOKEN(aux_sym_link_token1);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != ']') ADVANCE(247);
      END_STATE();
    case 248:
      ACCEPT_TOKEN(anon_sym_RBRACK_LBRACK);
      END_STATE();
    case 249:
      ACCEPT_TOKEN(anon_sym_RBRACK_RBRACK);
      END_STATE();
    case 250:
      ACCEPT_TOKEN(aux_sym_list_item_token1);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(250);
      if ((0x0b <= lookahead && lookahead <= '\r')) ADVANCE(321);
      END_STATE();
    case 251:
      ACCEPT_TOKEN(aux_sym_list_item_token1);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(251);
      END_STATE();
    case 252:
      ACCEPT_TOKEN(aux_sym_list_item_token2);
      if (lookahead == '\n') ADVANCE(167);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(252);
      if (lookahead != 0) ADVANCE(255);
      END_STATE();
    case 253:
      ACCEPT_TOKEN(aux_sym_list_item_token2);
      if (lookahead == '\t' ||
          (0x0b <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(253);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(254);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead)) ADVANCE(255);
      END_STATE();
    case 254:
      ACCEPT_TOKEN(aux_sym_list_item_token2);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(254);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(255);
      END_STATE();
    case 255:
      ACCEPT_TOKEN(aux_sym_list_item_token2);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(255);
      END_STATE();
    case 256:
      ACCEPT_TOKEN(sym_bullet);
      END_STATE();
    case 257:
      ACCEPT_TOKEN(sym_bullet);
      if (lookahead == '-') ADVANCE(332);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(408);
      END_STATE();
    case 258:
      ACCEPT_TOKEN(sym_bullet);
      if (lookahead == '-') ADVANCE(49);
      END_STATE();
    case 259:
      ACCEPT_TOKEN(sym_bullet);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(408);
      END_STATE();
    case 260:
      ACCEPT_TOKEN(aux_sym_block_begin_token1);
      END_STATE();
    case 261:
      ACCEPT_TOKEN(aux_sym_block_begin_token1);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(408);
      END_STATE();
    case 262:
      ACCEPT_TOKEN(sym_block_type);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(263);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(262);
      END_STATE();
    case 263:
      ACCEPT_TOKEN(sym_block_type);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(263);
      END_STATE();
    case 264:
      ACCEPT_TOKEN(sym_language);
      if (lookahead == '+' ||
          lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(264);
      END_STATE();
    case 265:
      ACCEPT_TOKEN(sym_block_content);
      if (lookahead == '#') ADVANCE(42);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(265);
      if (lookahead != 0) ADVANCE(266);
      END_STATE();
    case 266:
      ACCEPT_TOKEN(sym_block_content);
      if (lookahead == '#') ADVANCE(44);
      if (lookahead != 0) ADVANCE(266);
      END_STATE();
    case 267:
      ACCEPT_TOKEN(aux_sym_block_end_token1);
      END_STATE();
    case 268:
      ACCEPT_TOKEN(aux_sym_dynamic_block_begin_token1);
      END_STATE();
    case 269:
      ACCEPT_TOKEN(aux_sym_dynamic_block_begin_token1);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(408);
      END_STATE();
    case 270:
      ACCEPT_TOKEN(aux_sym_dynamic_block_begin_token2);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(270);
      END_STATE();
    case 271:
      ACCEPT_TOKEN(sym_dynamic_block_content);
      if (lookahead == '#') ADVANCE(40);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(271);
      if (lookahead != 0) ADVANCE(272);
      END_STATE();
    case 272:
      ACCEPT_TOKEN(sym_dynamic_block_content);
      if (lookahead == '#') ADVANCE(43);
      if (lookahead != 0) ADVANCE(272);
      END_STATE();
    case 273:
      ACCEPT_TOKEN(aux_sym_dynamic_block_end_token1);
      END_STATE();
    case 274:
      ACCEPT_TOKEN(anon_sym_PIPE);
      END_STATE();
    case 275:
      ACCEPT_TOKEN(anon_sym_PIPE);
      if (lookahead == '-') ADVANCE(3);
      END_STATE();
    case 276:
      ACCEPT_TOKEN(anon_sym_PIPE);
      if (lookahead == '-') ADVANCE(304);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(408);
      END_STATE();
    case 277:
      ACCEPT_TOKEN(sym_table_cell);
      if (lookahead == '\n') ADVANCE(163);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(277);
      if (lookahead != 0 &&
          lookahead != '|') ADVANCE(278);
      END_STATE();
    case 278:
      ACCEPT_TOKEN(sym_table_cell);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '|') ADVANCE(278);
      END_STATE();
    case 279:
      ACCEPT_TOKEN(sym_table_separator);
      END_STATE();
    case 280:
      ACCEPT_TOKEN(aux_sym_directive_token1);
      if (lookahead == 'B' ||
          lookahead == 'b') ADVANCE(123);
      END_STATE();
    case 281:
      ACCEPT_TOKEN(aux_sym_directive_token1);
      if (lookahead == 'B' ||
          lookahead == 'b') ADVANCE(399);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(408);
      END_STATE();
    case 282:
      ACCEPT_TOKEN(anon_sym_COLON);
      END_STATE();
    case 283:
      ACCEPT_TOKEN(anon_sym_COLON);
      if (lookahead == ' ') ADVANCE(289);
      if (lookahead == 'P') ADVANCE(80);
      END_STATE();
    case 284:
      ACCEPT_TOKEN(anon_sym_COLON);
      if (lookahead == ' ') ADVANCE(290);
      if (lookahead == 'P') ADVANCE(370);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(408);
      END_STATE();
    case 285:
      ACCEPT_TOKEN(anon_sym_COLON);
      if (lookahead == 'E') ADVANCE(76);
      END_STATE();
    case 286:
      ACCEPT_TOKEN(sym_name);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(286);
      END_STATE();
    case 287:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      END_STATE();
    case 288:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(408);
      END_STATE();
    case 289:
      ACCEPT_TOKEN(aux_sym_fixed_width_token1);
      END_STATE();
    case 290:
      ACCEPT_TOKEN(aux_sym_fixed_width_token1);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(408);
      END_STATE();
    case 291:
      ACCEPT_TOKEN(anon_sym_COLONPROPERTIES_COLON);
      END_STATE();
    case 292:
      ACCEPT_TOKEN(anon_sym_COLONPROPERTIES_COLON);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(408);
      END_STATE();
    case 293:
      ACCEPT_TOKEN(aux_sym_property_drawer_token1);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(293);
      END_STATE();
    case 294:
      ACCEPT_TOKEN(anon_sym_COLONEND_COLON);
      END_STATE();
    case 295:
      ACCEPT_TOKEN(aux_sym_key_token1);
      if (lookahead == '-' ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(295);
      END_STATE();
    case 296:
      ACCEPT_TOKEN(anon_sym_COLONend_COLON);
      END_STATE();
    case 297:
      ACCEPT_TOKEN(sym_drawer_content);
      if (lookahead == ':') ADVANCE(74);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(297);
      if (lookahead != 0) ADVANCE(298);
      END_STATE();
    case 298:
      ACCEPT_TOKEN(sym_drawer_content);
      if (lookahead == ':') ADVANCE(127);
      if (lookahead != 0) ADVANCE(298);
      END_STATE();
    case 299:
      ACCEPT_TOKEN(sym_horizontal_rule);
      END_STATE();
    case 300:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '\n') ADVANCE(35);
      if (lookahead == '$') ADVANCE(408);
      if (lookahead != 0) ADVANCE(301);
      END_STATE();
    case 301:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '\n') ADVANCE(35);
      if (lookahead == '$') ADVANCE(323);
      if (lookahead != 0) ADVANCE(301);
      END_STATE();
    case 302:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '\n') ADVANCE(241);
      if (lookahead == '{') ADVANCE(393);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(302);
      if (lookahead != 0) ADVANCE(408);
      END_STATE();
    case 303:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '\n') ADVANCE(241);
      if (lookahead != 0) ADVANCE(408);
      END_STATE();
    case 304:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '\n') ADVANCE(279);
      if (lookahead == '+') ADVANCE(328);
      if (lookahead == '-') ADVANCE(304);
      if (lookahead == '|') ADVANCE(305);
      if (lookahead != 0) ADVANCE(408);
      END_STATE();
    case 305:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '\n') ADVANCE(279);
      if (lookahead == '-') ADVANCE(304);
      if (lookahead != 0) ADVANCE(408);
      END_STATE();
    case 306:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '\n') ADVANCE(240);
      if (lookahead != 0) ADVANCE(408);
      END_STATE();
    case 307:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '\n') ADVANCE(206);
      if (lookahead != 0) ADVANCE(408);
      END_STATE();
    case 308:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '\n') ADVANCE(39);
      if (lookahead == '(') ADVANCE(308);
      if (lookahead == ')') ADVANCE(309);
      if (lookahead != 0) ADVANCE(308);
      END_STATE();
    case 309:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '\n') ADVANCE(205);
      if (lookahead == '(') ADVANCE(308);
      if (lookahead == ')') ADVANCE(310);
      if (lookahead != 0) ADVANCE(327);
      END_STATE();
    case 310:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '\n') ADVANCE(205);
      if (lookahead != 0) ADVANCE(408);
      END_STATE();
    case 311:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '\n') ADVANCE(299);
      if (lookahead == '-') ADVANCE(311);
      if (lookahead != 0) ADVANCE(408);
      END_STATE();
    case 312:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '\n') ADVANCE(91);
      if (lookahead == ']') ADVANCE(408);
      if (lookahead != 0) ADVANCE(313);
      END_STATE();
    case 313:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '\n') ADVANCE(91);
      if (lookahead == ']') ADVANCE(314);
      if (lookahead != 0) ADVANCE(313);
      END_STATE();
    case 314:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '\n') ADVANCE(239);
      if (lookahead != 0) ADVANCE(408);
      END_STATE();
    case 315:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '\n') ADVANCE(243);
      if (lookahead != 0) ADVANCE(315);
      END_STATE();
    case 316:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '\n') ADVANCE(242);
      if (lookahead != 0) ADVANCE(316);
      END_STATE();
    case 317:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '\n') ADVANCE(204);
      if (lookahead == '-') ADVANCE(329);
      if (lookahead != 0) ADVANCE(408);
      END_STATE();
    case 318:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '\n') ADVANCE(204);
      if (lookahead != 0) ADVANCE(408);
      END_STATE();
    case 319:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '\n') ADVANCE(203);
      if (lookahead != 0) ADVANCE(408);
      END_STATE();
    case 320:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == ' ') ADVANCE(288);
      if (lookahead == '+') ADVANCE(281);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(408);
      END_STATE();
    case 321:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      ADVANCE_MAP(
        '#', 320,
        '$', 322,
        '%', 325,
        '*', 169,
        '+', 259,
        '-', 257,
        ':', 284,
        '<', 344,
        'C', 363,
        'D', 354,
        'S', 350,
        '[', 376,
        '\\', 407,
        'c', 383,
        '{', 392,
        '|', 276,
        '\t', 250,
        ' ', 250,
      );
      if ((0x0b <= lookahead && lookahead <= '\r')) ADVANCE(321);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(384);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(385);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(385);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead)) ADVANCE(408);
      END_STATE();
    case 322:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '$') ADVANCE(300);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(324);
      END_STATE();
    case 323:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '$') ADVANCE(306);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(408);
      END_STATE();
    case 324:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '$') ADVANCE(306);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(324);
      END_STATE();
    case 325:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '%') ADVANCE(326);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(408);
      END_STATE();
    case 326:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '(') ADVANCE(327);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(408);
      END_STATE();
    case 327:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '(') ADVANCE(308);
      if (lookahead == ')') ADVANCE(310);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(327);
      END_STATE();
    case 328:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '-') ADVANCE(304);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(408);
      END_STATE();
    case 329:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '-') ADVANCE(377);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(408);
      END_STATE();
    case 330:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '-') ADVANCE(311);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(408);
      END_STATE();
    case 331:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '-') ADVANCE(330);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(408);
      END_STATE();
    case 332:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '-') ADVANCE(331);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(408);
      END_STATE();
    case 333:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == ':') ADVANCE(336);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(408);
      END_STATE();
    case 334:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == ':') ADVANCE(394);
      if (lookahead == '^') ADVANCE(409);
      if (lookahead == '_') ADVANCE(410);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(389);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(408);
      END_STATE();
    case 335:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == ':') ADVANCE(312);
      if (lookahead == ']') ADVANCE(314);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(335);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(408);
      END_STATE();
    case 336:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == ':') ADVANCE(312);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(335);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(408);
      END_STATE();
    case 337:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == ':') ADVANCE(269);
      if (lookahead == '_') ADVANCE(261);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(408);
      END_STATE();
    case 338:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == ':') ADVANCE(292);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(408);
      END_STATE();
    case 339:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == ':') ADVANCE(395);
      if (lookahead == '^') ADVANCE(409);
      if (lookahead == '_') ADVANCE(410);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(389);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(408);
      END_STATE();
    case 340:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == ':') ADVANCE(404);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(340);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(408);
      END_STATE();
    case 341:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '<') ADVANCE(345);
      if (lookahead == '[') ADVANCE(378);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(341);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n') ADVANCE(408);
      END_STATE();
    case 342:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '=') ADVANCE(347);
      if (lookahead == '[') ADVANCE(403);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(342);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n') ADVANCE(408);
      END_STATE();
    case 343:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '=') ADVANCE(347);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(343);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n') ADVANCE(408);
      END_STATE();
    case 344:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '>') ADVANCE(408);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(346);
      END_STATE();
    case 345:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '>') ADVANCE(408);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(348);
      END_STATE();
    case 346:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '>') ADVANCE(307);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(346);
      END_STATE();
    case 347:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '>') ADVANCE(397);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(408);
      END_STATE();
    case 348:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '>') ADVANCE(319);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(348);
      END_STATE();
    case 349:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == 'A') ADVANCE(351);
      if (lookahead == '^') ADVANCE(409);
      if (lookahead == '_') ADVANCE(410);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('B' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(389);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(408);
      END_STATE();
    case 350:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == 'C') ADVANCE(360);
      if (lookahead == '^') ADVANCE(409);
      if (lookahead == '_') ADVANCE(410);
      if (lookahead == ')' ||
          lookahead == '.') ADVANCE(259);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(389);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(408);
      END_STATE();
    case 351:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == 'D') ADVANCE(364);
      if (lookahead == '^') ADVANCE(409);
      if (lookahead == '_') ADVANCE(410);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(389);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(408);
      END_STATE();
    case 352:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == 'D') ADVANCE(375);
      if (lookahead == '^') ADVANCE(409);
      if (lookahead == '_') ADVANCE(410);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(389);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(408);
      END_STATE();
    case 353:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == 'D') ADVANCE(339);
      if (lookahead == '^') ADVANCE(409);
      if (lookahead == '_') ADVANCE(410);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(389);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(408);
      END_STATE();
    case 354:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == 'E') ADVANCE(349);
      if (lookahead == '^') ADVANCE(409);
      if (lookahead == '_') ADVANCE(410);
      if (lookahead == ')' ||
          lookahead == '.') ADVANCE(259);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(389);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(408);
      END_STATE();
    case 355:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == 'E') ADVANCE(372);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(408);
      END_STATE();
    case 356:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == 'E') ADVANCE(352);
      if (lookahead == '^') ADVANCE(409);
      if (lookahead == '_') ADVANCE(410);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(389);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(408);
      END_STATE();
    case 357:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == 'E') ADVANCE(371);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(408);
      END_STATE();
    case 358:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == 'E') ADVANCE(353);
      if (lookahead == '^') ADVANCE(409);
      if (lookahead == '_') ADVANCE(410);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(389);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(408);
      END_STATE();
    case 359:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == 'E') ADVANCE(339);
      if (lookahead == '^') ADVANCE(409);
      if (lookahead == '_') ADVANCE(410);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(389);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(408);
      END_STATE();
    case 360:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == 'H') ADVANCE(356);
      if (lookahead == '^') ADVANCE(409);
      if (lookahead == '_') ADVANCE(410);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(389);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(408);
      END_STATE();
    case 361:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == 'I') ADVANCE(366);
      if (lookahead == '^') ADVANCE(409);
      if (lookahead == '_') ADVANCE(410);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(389);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(408);
      END_STATE();
    case 362:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == 'I') ADVANCE(355);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(408);
      END_STATE();
    case 363:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == 'L') ADVANCE(367);
      if (lookahead == '^') ADVANCE(409);
      if (lookahead == '_') ADVANCE(410);
      if (lookahead == 'l') ADVANCE(388);
      if (lookahead == ')' ||
          lookahead == '.') ADVANCE(259);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(389);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(408);
      END_STATE();
    case 364:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == 'L') ADVANCE(361);
      if (lookahead == '^') ADVANCE(409);
      if (lookahead == '_') ADVANCE(410);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(389);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(408);
      END_STATE();
    case 365:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == 'L') ADVANCE(358);
      if (lookahead == '^') ADVANCE(409);
      if (lookahead == '_') ADVANCE(410);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(389);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(408);
      END_STATE();
    case 366:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == 'N') ADVANCE(359);
      if (lookahead == '^') ADVANCE(409);
      if (lookahead == '_') ADVANCE(410);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(389);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(408);
      END_STATE();
    case 367:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == 'O') ADVANCE(373);
      if (lookahead == '^') ADVANCE(409);
      if (lookahead == '_') ADVANCE(410);
      if (lookahead == 'o') ADVANCE(386);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(389);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(408);
      END_STATE();
    case 368:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == 'O') ADVANCE(369);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(408);
      END_STATE();
    case 369:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == 'P') ADVANCE(357);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(408);
      END_STATE();
    case 370:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == 'R') ADVANCE(368);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(408);
      END_STATE();
    case 371:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == 'R') ADVANCE(374);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(408);
      END_STATE();
    case 372:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == 'S') ADVANCE(338);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(408);
      END_STATE();
    case 373:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == 'S') ADVANCE(358);
      if (lookahead == '^') ADVANCE(409);
      if (lookahead == '_') ADVANCE(410);
      if (lookahead == 'C' ||
          lookahead == 'c') ADVANCE(387);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(389);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(408);
      END_STATE();
    case 374:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == 'T') ADVANCE(362);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(408);
      END_STATE();
    case 375:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == 'U') ADVANCE(365);
      if (lookahead == '^') ADVANCE(409);
      if (lookahead == '_') ADVANCE(410);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(389);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(408);
      END_STATE();
    case 376:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '[') ADVANCE(245);
      if (lookahead == 'f') ADVANCE(390);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(379);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(408);
      END_STATE();
    case 377:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '[') ADVANCE(405);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(408);
      END_STATE();
    case 378:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == ']') ADVANCE(408);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(382);
      END_STATE();
    case 379:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == ']') ADVANCE(307);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(379);
      END_STATE();
    case 380:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == ']') ADVANCE(317);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(380);
      END_STATE();
    case 381:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == ']') ADVANCE(398);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(381);
      END_STATE();
    case 382:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == ']') ADVANCE(319);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(382);
      END_STATE();
    case 383:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '^') ADVANCE(409);
      if (lookahead == '_') ADVANCE(410);
      if (lookahead == ')' ||
          lookahead == '.') ADVANCE(259);
      if (lookahead == 'L' ||
          lookahead == 'l') ADVANCE(388);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(389);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(408);
      END_STATE();
    case 384:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '^') ADVANCE(409);
      if (lookahead == '_') ADVANCE(410);
      if (lookahead == ')' ||
          lookahead == '.') ADVANCE(259);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(384);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(389);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(408);
      END_STATE();
    case 385:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '^') ADVANCE(409);
      if (lookahead == '_') ADVANCE(410);
      if (lookahead == ')' ||
          lookahead == '.') ADVANCE(259);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(389);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(408);
      END_STATE();
    case 386:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '^') ADVANCE(409);
      if (lookahead == '_') ADVANCE(410);
      if (lookahead == 'C' ||
          lookahead == 'c') ADVANCE(387);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(389);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(408);
      END_STATE();
    case 387:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '^') ADVANCE(409);
      if (lookahead == '_') ADVANCE(410);
      if (lookahead == 'K' ||
          lookahead == 'k') ADVANCE(334);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(389);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(408);
      END_STATE();
    case 388:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '^') ADVANCE(409);
      if (lookahead == '_') ADVANCE(410);
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(386);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(389);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(408);
      END_STATE();
    case 389:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '^') ADVANCE(409);
      if (lookahead == '_') ADVANCE(410);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(389);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(408);
      END_STATE();
    case 390:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == 'n') ADVANCE(333);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(408);
      END_STATE();
    case 391:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '{') ADVANCE(208);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(408);
      END_STATE();
    case 392:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '{') ADVANCE(391);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(408);
      END_STATE();
    case 393:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '}') ADVANCE(303);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(408);
      END_STATE();
    case 394:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(342);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n') ADVANCE(408);
      END_STATE();
    case 395:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(341);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n') ADVANCE(408);
      END_STATE();
    case 396:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(396);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(340);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n') ADVANCE(408);
      END_STATE();
    case 397:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(396);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n') ADVANCE(408);
      END_STATE();
    case 398:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(343);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n') ADVANCE(408);
      END_STATE();
    case 399:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(400);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(408);
      END_STATE();
    case 400:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == 'G' ||
          lookahead == 'g') ADVANCE(401);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(408);
      END_STATE();
    case 401:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(402);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(408);
      END_STATE();
    case 402:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(337);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(408);
      END_STATE();
    case 403:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(380);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(408);
      END_STATE();
    case 404:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(406);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(408);
      END_STATE();
    case 405:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(381);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(408);
      END_STATE();
    case 406:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(318);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(408);
      END_STATE();
    case 407:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(302);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(408);
      END_STATE();
    case 408:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(408);
      END_STATE();
    case 409:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(315);
      END_STATE();
    case 410:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(316);
      END_STATE();
    case 411:
      ACCEPT_TOKEN(aux_sym_paragraph_token2);
      if (lookahead == '\n') ADVANCE(411);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 157},
  [2] = {.lex_state = 157},
  [3] = {.lex_state = 157},
  [4] = {.lex_state = 157},
  [5] = {.lex_state = 157},
  [6] = {.lex_state = 157},
  [7] = {.lex_state = 157},
  [8] = {.lex_state = 157},
  [9] = {.lex_state = 157},
  [10] = {.lex_state = 157},
  [11] = {.lex_state = 157},
  [12] = {.lex_state = 157},
  [13] = {.lex_state = 157},
  [14] = {.lex_state = 157},
  [15] = {.lex_state = 157},
  [16] = {.lex_state = 157},
  [17] = {.lex_state = 157},
  [18] = {.lex_state = 157},
  [19] = {.lex_state = 157},
  [20] = {.lex_state = 157},
  [21] = {.lex_state = 157},
  [22] = {.lex_state = 157},
  [23] = {.lex_state = 157},
  [24] = {.lex_state = 157},
  [25] = {.lex_state = 157},
  [26] = {.lex_state = 157},
  [27] = {.lex_state = 157},
  [28] = {.lex_state = 157},
  [29] = {.lex_state = 157},
  [30] = {.lex_state = 157},
  [31] = {.lex_state = 157},
  [32] = {.lex_state = 157},
  [33] = {.lex_state = 157},
  [34] = {.lex_state = 157},
  [35] = {.lex_state = 157},
  [36] = {.lex_state = 157},
  [37] = {.lex_state = 157},
  [38] = {.lex_state = 157},
  [39] = {.lex_state = 157},
  [40] = {.lex_state = 157},
  [41] = {.lex_state = 16},
  [42] = {.lex_state = 17},
  [43] = {.lex_state = 18},
  [44] = {.lex_state = 29},
  [45] = {.lex_state = 29},
  [46] = {.lex_state = 18},
  [47] = {.lex_state = 18},
  [48] = {.lex_state = 25},
  [49] = {.lex_state = 60},
  [50] = {.lex_state = 18},
  [51] = {.lex_state = 30},
  [52] = {.lex_state = 31},
  [53] = {.lex_state = 25},
  [54] = {.lex_state = 31},
  [55] = {.lex_state = 30},
  [56] = {.lex_state = 29},
  [57] = {.lex_state = 19},
  [58] = {.lex_state = 31},
  [59] = {.lex_state = 29},
  [60] = {.lex_state = 61},
  [61] = {.lex_state = 0},
  [62] = {.lex_state = 30},
  [63] = {.lex_state = 0},
  [64] = {.lex_state = 29},
  [65] = {.lex_state = 253},
  [66] = {.lex_state = 20},
  [67] = {.lex_state = 31},
  [68] = {.lex_state = 252},
  [69] = {.lex_state = 21},
  [70] = {.lex_state = 29},
  [71] = {.lex_state = 252},
  [72] = {.lex_state = 29},
  [73] = {.lex_state = 60},
  [74] = {.lex_state = 22},
  [75] = {.lex_state = 22},
  [76] = {.lex_state = 64},
  [77] = {.lex_state = 293},
  [78] = {.lex_state = 27},
  [79] = {.lex_state = 22},
  [80] = {.lex_state = 253},
  [81] = {.lex_state = 22},
  [82] = {.lex_state = 22},
  [83] = {.lex_state = 22},
  [84] = {.lex_state = 0},
  [85] = {.lex_state = 22},
  [86] = {.lex_state = 0},
  [87] = {.lex_state = 60},
  [88] = {.lex_state = 22},
  [89] = {.lex_state = 60},
  [90] = {.lex_state = 22},
  [91] = {.lex_state = 22},
  [92] = {.lex_state = 19},
  [93] = {.lex_state = 22},
  [94] = {.lex_state = 60},
  [95] = {.lex_state = 29},
  [96] = {.lex_state = 22},
  [97] = {.lex_state = 253},
  [98] = {.lex_state = 27},
  [99] = {.lex_state = 22},
  [100] = {.lex_state = 253},
  [101] = {.lex_state = 22},
  [102] = {.lex_state = 0},
  [103] = {.lex_state = 22},
  [104] = {.lex_state = 27},
  [105] = {.lex_state = 27},
  [106] = {.lex_state = 253},
  [107] = {.lex_state = 22},
  [108] = {.lex_state = 23},
  [109] = {.lex_state = 22},
  [110] = {.lex_state = 22},
  [111] = {.lex_state = 60},
  [112] = {.lex_state = 60},
  [113] = {.lex_state = 293},
  [114] = {.lex_state = 0},
  [115] = {.lex_state = 24},
  [116] = {.lex_state = 293},
  [117] = {.lex_state = 253},
  [118] = {.lex_state = 253},
  [119] = {.lex_state = 22},
  [120] = {.lex_state = 139},
  [121] = {.lex_state = 22},
  [122] = {.lex_state = 140},
  [123] = {.lex_state = 293},
  [124] = {.lex_state = 64},
  [125] = {.lex_state = 293},
  [126] = {.lex_state = 22},
  [127] = {.lex_state = 113},
  [128] = {.lex_state = 22},
  [129] = {.lex_state = 141},
  [130] = {.lex_state = 22},
  [131] = {.lex_state = 293},
  [132] = {.lex_state = 22},
  [133] = {.lex_state = 27},
  [134] = {.lex_state = 116},
  [135] = {.lex_state = 23},
  [136] = {.lex_state = 22},
  [137] = {.lex_state = 22},
  [138] = {.lex_state = 22},
  [139] = {.lex_state = 142},
  [140] = {.lex_state = 27},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [sym_stars] = ACTIONS(1),
    [sym_keyword] = ACTIONS(1),
    [sym_priority] = ACTIONS(1),
    [sym_diary_sexp] = ACTIONS(1),
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
    [aux_sym_dynamic_block_begin_token1] = ACTIONS(1),
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
    [sym_document] = STATE(114),
    [sym__element] = STATE(3),
    [sym_headline] = STATE(3),
    [sym_macro] = STATE(3),
    [sym_link] = STATE(3),
    [sym_list] = STATE(3),
    [sym_list_item] = STATE(4),
    [sym_block] = STATE(3),
    [sym_block_begin] = STATE(52),
    [sym_dynamic_block] = STATE(3),
    [sym_dynamic_block_begin] = STATE(51),
    [sym_table] = STATE(3),
    [sym_table_row] = STATE(7),
    [sym_directive] = STATE(3),
    [sym_comment] = STATE(3),
    [sym_fixed_width] = STATE(3),
    [sym_property_drawer] = STATE(3),
    [sym_drawer] = STATE(3),
    [sym_paragraph] = STATE(3),
    [aux_sym_document_repeat1] = STATE(3),
    [aux_sym_list_repeat1] = STATE(4),
    [aux_sym_table_repeat1] = STATE(7),
    [aux_sym_fixed_width_repeat1] = STATE(9),
    [ts_builtin_sym_end] = ACTIONS(3),
    [sym_stars] = ACTIONS(5),
    [sym_planning_line] = ACTIONS(7),
    [sym_clock] = ACTIONS(7),
    [sym_diary_sexp] = ACTIONS(7),
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
    [aux_sym_dynamic_block_begin_token1] = ACTIONS(19),
    [anon_sym_PIPE] = ACTIONS(21),
    [sym_table_separator] = ACTIONS(23),
    [aux_sym_directive_token1] = ACTIONS(25),
    [anon_sym_COLON] = ACTIONS(27),
    [aux_sym_comment_token1] = ACTIONS(29),
    [aux_sym_fixed_width_token1] = ACTIONS(31),
    [anon_sym_COLONPROPERTIES_COLON] = ACTIONS(33),
    [sym_horizontal_rule] = ACTIONS(7),
    [aux_sym_paragraph_token1] = ACTIONS(35),
  },
  [2] = {
    [sym__element] = STATE(2),
    [sym_headline] = STATE(2),
    [sym_macro] = STATE(2),
    [sym_link] = STATE(2),
    [sym_list] = STATE(2),
    [sym_list_item] = STATE(4),
    [sym_block] = STATE(2),
    [sym_block_begin] = STATE(52),
    [sym_dynamic_block] = STATE(2),
    [sym_dynamic_block_begin] = STATE(51),
    [sym_table] = STATE(2),
    [sym_table_row] = STATE(7),
    [sym_directive] = STATE(2),
    [sym_comment] = STATE(2),
    [sym_fixed_width] = STATE(2),
    [sym_property_drawer] = STATE(2),
    [sym_drawer] = STATE(2),
    [sym_paragraph] = STATE(2),
    [aux_sym_document_repeat1] = STATE(2),
    [aux_sym_list_repeat1] = STATE(4),
    [aux_sym_table_repeat1] = STATE(7),
    [aux_sym_fixed_width_repeat1] = STATE(9),
    [ts_builtin_sym_end] = ACTIONS(37),
    [sym_stars] = ACTIONS(39),
    [sym_planning_line] = ACTIONS(42),
    [sym_clock] = ACTIONS(42),
    [sym_diary_sexp] = ACTIONS(42),
    [sym_timestamp] = ACTIONS(42),
    [anon_sym_LBRACE_LBRACE_LBRACE] = ACTIONS(45),
    [sym_footnote_reference] = ACTIONS(42),
    [sym_latex_fragment] = ACTIONS(42),
    [sym_entity] = ACTIONS(42),
    [sym_subscript] = ACTIONS(42),
    [sym_superscript] = ACTIONS(42),
    [anon_sym_LBRACK_LBRACK] = ACTIONS(48),
    [aux_sym_list_item_token1] = ACTIONS(51),
    [sym_bullet] = ACTIONS(54),
    [aux_sym_block_begin_token1] = ACTIONS(57),
    [aux_sym_dynamic_block_begin_token1] = ACTIONS(60),
    [anon_sym_PIPE] = ACTIONS(63),
    [sym_table_separator] = ACTIONS(66),
    [aux_sym_directive_token1] = ACTIONS(69),
    [anon_sym_COLON] = ACTIONS(72),
    [aux_sym_comment_token1] = ACTIONS(75),
    [aux_sym_fixed_width_token1] = ACTIONS(78),
    [anon_sym_COLONPROPERTIES_COLON] = ACTIONS(81),
    [sym_horizontal_rule] = ACTIONS(42),
    [aux_sym_paragraph_token1] = ACTIONS(84),
  },
  [3] = {
    [sym__element] = STATE(2),
    [sym_headline] = STATE(2),
    [sym_macro] = STATE(2),
    [sym_link] = STATE(2),
    [sym_list] = STATE(2),
    [sym_list_item] = STATE(4),
    [sym_block] = STATE(2),
    [sym_block_begin] = STATE(52),
    [sym_dynamic_block] = STATE(2),
    [sym_dynamic_block_begin] = STATE(51),
    [sym_table] = STATE(2),
    [sym_table_row] = STATE(7),
    [sym_directive] = STATE(2),
    [sym_comment] = STATE(2),
    [sym_fixed_width] = STATE(2),
    [sym_property_drawer] = STATE(2),
    [sym_drawer] = STATE(2),
    [sym_paragraph] = STATE(2),
    [aux_sym_document_repeat1] = STATE(2),
    [aux_sym_list_repeat1] = STATE(4),
    [aux_sym_table_repeat1] = STATE(7),
    [aux_sym_fixed_width_repeat1] = STATE(9),
    [ts_builtin_sym_end] = ACTIONS(87),
    [sym_stars] = ACTIONS(5),
    [sym_planning_line] = ACTIONS(89),
    [sym_clock] = ACTIONS(89),
    [sym_diary_sexp] = ACTIONS(89),
    [sym_timestamp] = ACTIONS(89),
    [anon_sym_LBRACE_LBRACE_LBRACE] = ACTIONS(9),
    [sym_footnote_reference] = ACTIONS(89),
    [sym_latex_fragment] = ACTIONS(89),
    [sym_entity] = ACTIONS(89),
    [sym_subscript] = ACTIONS(89),
    [sym_superscript] = ACTIONS(89),
    [anon_sym_LBRACK_LBRACK] = ACTIONS(11),
    [aux_sym_list_item_token1] = ACTIONS(13),
    [sym_bullet] = ACTIONS(15),
    [aux_sym_block_begin_token1] = ACTIONS(17),
    [aux_sym_dynamic_block_begin_token1] = ACTIONS(19),
    [anon_sym_PIPE] = ACTIONS(21),
    [sym_table_separator] = ACTIONS(23),
    [aux_sym_directive_token1] = ACTIONS(25),
    [anon_sym_COLON] = ACTIONS(27),
    [aux_sym_comment_token1] = ACTIONS(29),
    [aux_sym_fixed_width_token1] = ACTIONS(31),
    [anon_sym_COLONPROPERTIES_COLON] = ACTIONS(33),
    [sym_horizontal_rule] = ACTIONS(89),
    [aux_sym_paragraph_token1] = ACTIONS(35),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 5,
    ACTIONS(13), 1,
      aux_sym_list_item_token1,
    ACTIONS(15), 1,
      sym_bullet,
    ACTIONS(91), 1,
      ts_builtin_sym_end,
    STATE(6), 2,
      sym_list_item,
      aux_sym_list_repeat1,
    ACTIONS(93), 23,
      sym_stars,
      sym_planning_line,
      sym_clock,
      sym_diary_sexp,
      sym_timestamp,
      anon_sym_LBRACE_LBRACE_LBRACE,
      sym_footnote_reference,
      sym_latex_fragment,
      sym_entity,
      sym_subscript,
      sym_superscript,
      anon_sym_LBRACK_LBRACK,
      aux_sym_block_begin_token1,
      aux_sym_dynamic_block_begin_token1,
      anon_sym_PIPE,
      sym_table_separator,
      aux_sym_directive_token1,
      anon_sym_COLON,
      aux_sym_comment_token1,
      aux_sym_fixed_width_token1,
      anon_sym_COLONPROPERTIES_COLON,
      sym_horizontal_rule,
      aux_sym_paragraph_token1,
  [39] = 5,
    ACTIONS(95), 1,
      ts_builtin_sym_end,
    ACTIONS(99), 1,
      anon_sym_PIPE,
    ACTIONS(102), 1,
      sym_table_separator,
    STATE(5), 2,
      sym_table_row,
      aux_sym_table_repeat1,
    ACTIONS(97), 23,
      sym_stars,
      sym_planning_line,
      sym_clock,
      sym_diary_sexp,
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
      aux_sym_dynamic_block_begin_token1,
      aux_sym_directive_token1,
      anon_sym_COLON,
      aux_sym_comment_token1,
      aux_sym_fixed_width_token1,
      anon_sym_COLONPROPERTIES_COLON,
      sym_horizontal_rule,
      aux_sym_paragraph_token1,
  [78] = 5,
    ACTIONS(105), 1,
      ts_builtin_sym_end,
    ACTIONS(109), 1,
      aux_sym_list_item_token1,
    ACTIONS(112), 1,
      sym_bullet,
    STATE(6), 2,
      sym_list_item,
      aux_sym_list_repeat1,
    ACTIONS(107), 23,
      sym_stars,
      sym_planning_line,
      sym_clock,
      sym_diary_sexp,
      sym_timestamp,
      anon_sym_LBRACE_LBRACE_LBRACE,
      sym_footnote_reference,
      sym_latex_fragment,
      sym_entity,
      sym_subscript,
      sym_superscript,
      anon_sym_LBRACK_LBRACK,
      aux_sym_block_begin_token1,
      aux_sym_dynamic_block_begin_token1,
      anon_sym_PIPE,
      sym_table_separator,
      aux_sym_directive_token1,
      anon_sym_COLON,
      aux_sym_comment_token1,
      aux_sym_fixed_width_token1,
      anon_sym_COLONPROPERTIES_COLON,
      sym_horizontal_rule,
      aux_sym_paragraph_token1,
  [117] = 5,
    ACTIONS(21), 1,
      anon_sym_PIPE,
    ACTIONS(115), 1,
      ts_builtin_sym_end,
    ACTIONS(119), 1,
      sym_table_separator,
    STATE(5), 2,
      sym_table_row,
      aux_sym_table_repeat1,
    ACTIONS(117), 23,
      sym_stars,
      sym_planning_line,
      sym_clock,
      sym_diary_sexp,
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
      aux_sym_dynamic_block_begin_token1,
      aux_sym_directive_token1,
      anon_sym_COLON,
      aux_sym_comment_token1,
      aux_sym_fixed_width_token1,
      anon_sym_COLONPROPERTIES_COLON,
      sym_horizontal_rule,
      aux_sym_paragraph_token1,
  [156] = 4,
    ACTIONS(121), 1,
      ts_builtin_sym_end,
    ACTIONS(125), 1,
      aux_sym_fixed_width_token1,
    STATE(8), 1,
      aux_sym_fixed_width_repeat1,
    ACTIONS(123), 24,
      sym_stars,
      sym_planning_line,
      sym_clock,
      sym_diary_sexp,
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
      aux_sym_dynamic_block_begin_token1,
      anon_sym_PIPE,
      sym_table_separator,
      aux_sym_directive_token1,
      anon_sym_COLON,
      aux_sym_comment_token1,
      anon_sym_COLONPROPERTIES_COLON,
      sym_horizontal_rule,
      aux_sym_paragraph_token1,
  [192] = 4,
    ACTIONS(31), 1,
      aux_sym_fixed_width_token1,
    ACTIONS(128), 1,
      ts_builtin_sym_end,
    STATE(8), 1,
      aux_sym_fixed_width_repeat1,
    ACTIONS(130), 24,
      sym_stars,
      sym_planning_line,
      sym_clock,
      sym_diary_sexp,
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
      aux_sym_dynamic_block_begin_token1,
      anon_sym_PIPE,
      sym_table_separator,
      aux_sym_directive_token1,
      anon_sym_COLON,
      aux_sym_comment_token1,
      anon_sym_COLONPROPERTIES_COLON,
      sym_horizontal_rule,
      aux_sym_paragraph_token1,
  [228] = 2,
    ACTIONS(132), 1,
      ts_builtin_sym_end,
    ACTIONS(134), 25,
      sym_stars,
      sym_planning_line,
      sym_clock,
      sym_diary_sexp,
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
      aux_sym_dynamic_block_begin_token1,
      anon_sym_PIPE,
      sym_table_separator,
      aux_sym_directive_token1,
      anon_sym_COLON,
      aux_sym_comment_token1,
      aux_sym_fixed_width_token1,
      anon_sym_COLONPROPERTIES_COLON,
      sym_horizontal_rule,
      aux_sym_paragraph_token1,
  [259] = 2,
    ACTIONS(136), 1,
      ts_builtin_sym_end,
    ACTIONS(138), 25,
      sym_stars,
      sym_planning_line,
      sym_clock,
      sym_diary_sexp,
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
      aux_sym_dynamic_block_begin_token1,
      anon_sym_PIPE,
      sym_table_separator,
      aux_sym_directive_token1,
      anon_sym_COLON,
      aux_sym_comment_token1,
      aux_sym_fixed_width_token1,
      anon_sym_COLONPROPERTIES_COLON,
      sym_horizontal_rule,
      aux_sym_paragraph_token1,
  [290] = 2,
    ACTIONS(140), 1,
      ts_builtin_sym_end,
    ACTIONS(142), 25,
      sym_stars,
      sym_planning_line,
      sym_clock,
      sym_diary_sexp,
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
      aux_sym_dynamic_block_begin_token1,
      anon_sym_PIPE,
      sym_table_separator,
      aux_sym_directive_token1,
      anon_sym_COLON,
      aux_sym_comment_token1,
      aux_sym_fixed_width_token1,
      anon_sym_COLONPROPERTIES_COLON,
      sym_horizontal_rule,
      aux_sym_paragraph_token1,
  [321] = 2,
    ACTIONS(144), 1,
      ts_builtin_sym_end,
    ACTIONS(146), 25,
      sym_stars,
      sym_planning_line,
      sym_clock,
      sym_diary_sexp,
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
      aux_sym_dynamic_block_begin_token1,
      anon_sym_PIPE,
      sym_table_separator,
      aux_sym_directive_token1,
      anon_sym_COLON,
      aux_sym_comment_token1,
      aux_sym_fixed_width_token1,
      anon_sym_COLONPROPERTIES_COLON,
      sym_horizontal_rule,
      aux_sym_paragraph_token1,
  [352] = 2,
    ACTIONS(148), 1,
      ts_builtin_sym_end,
    ACTIONS(150), 25,
      sym_stars,
      sym_planning_line,
      sym_clock,
      sym_diary_sexp,
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
      aux_sym_dynamic_block_begin_token1,
      anon_sym_PIPE,
      sym_table_separator,
      aux_sym_directive_token1,
      anon_sym_COLON,
      aux_sym_comment_token1,
      aux_sym_fixed_width_token1,
      anon_sym_COLONPROPERTIES_COLON,
      sym_horizontal_rule,
      aux_sym_paragraph_token1,
  [383] = 2,
    ACTIONS(152), 1,
      ts_builtin_sym_end,
    ACTIONS(154), 25,
      sym_stars,
      sym_planning_line,
      sym_clock,
      sym_diary_sexp,
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
      aux_sym_dynamic_block_begin_token1,
      anon_sym_PIPE,
      sym_table_separator,
      aux_sym_directive_token1,
      anon_sym_COLON,
      aux_sym_comment_token1,
      aux_sym_fixed_width_token1,
      anon_sym_COLONPROPERTIES_COLON,
      sym_horizontal_rule,
      aux_sym_paragraph_token1,
  [414] = 2,
    ACTIONS(156), 1,
      ts_builtin_sym_end,
    ACTIONS(158), 25,
      sym_stars,
      sym_planning_line,
      sym_clock,
      sym_diary_sexp,
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
      aux_sym_dynamic_block_begin_token1,
      anon_sym_PIPE,
      sym_table_separator,
      aux_sym_directive_token1,
      anon_sym_COLON,
      aux_sym_comment_token1,
      aux_sym_fixed_width_token1,
      anon_sym_COLONPROPERTIES_COLON,
      sym_horizontal_rule,
      aux_sym_paragraph_token1,
  [445] = 2,
    ACTIONS(160), 1,
      ts_builtin_sym_end,
    ACTIONS(162), 25,
      sym_stars,
      sym_planning_line,
      sym_clock,
      sym_diary_sexp,
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
      aux_sym_dynamic_block_begin_token1,
      anon_sym_PIPE,
      sym_table_separator,
      aux_sym_directive_token1,
      anon_sym_COLON,
      aux_sym_comment_token1,
      aux_sym_fixed_width_token1,
      anon_sym_COLONPROPERTIES_COLON,
      sym_horizontal_rule,
      aux_sym_paragraph_token1,
  [476] = 2,
    ACTIONS(164), 1,
      ts_builtin_sym_end,
    ACTIONS(166), 25,
      sym_stars,
      sym_planning_line,
      sym_clock,
      sym_diary_sexp,
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
      aux_sym_dynamic_block_begin_token1,
      anon_sym_PIPE,
      sym_table_separator,
      aux_sym_directive_token1,
      anon_sym_COLON,
      aux_sym_comment_token1,
      aux_sym_fixed_width_token1,
      anon_sym_COLONPROPERTIES_COLON,
      sym_horizontal_rule,
      aux_sym_paragraph_token1,
  [507] = 2,
    ACTIONS(168), 1,
      ts_builtin_sym_end,
    ACTIONS(170), 25,
      sym_stars,
      sym_planning_line,
      sym_clock,
      sym_diary_sexp,
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
      aux_sym_dynamic_block_begin_token1,
      anon_sym_PIPE,
      sym_table_separator,
      aux_sym_directive_token1,
      anon_sym_COLON,
      aux_sym_comment_token1,
      aux_sym_fixed_width_token1,
      anon_sym_COLONPROPERTIES_COLON,
      sym_horizontal_rule,
      aux_sym_paragraph_token1,
  [538] = 2,
    ACTIONS(172), 1,
      ts_builtin_sym_end,
    ACTIONS(174), 25,
      sym_stars,
      sym_planning_line,
      sym_clock,
      sym_diary_sexp,
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
      aux_sym_dynamic_block_begin_token1,
      anon_sym_PIPE,
      sym_table_separator,
      aux_sym_directive_token1,
      anon_sym_COLON,
      aux_sym_comment_token1,
      aux_sym_fixed_width_token1,
      anon_sym_COLONPROPERTIES_COLON,
      sym_horizontal_rule,
      aux_sym_paragraph_token1,
  [569] = 2,
    ACTIONS(176), 1,
      ts_builtin_sym_end,
    ACTIONS(178), 25,
      sym_stars,
      sym_planning_line,
      sym_clock,
      sym_diary_sexp,
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
      aux_sym_dynamic_block_begin_token1,
      anon_sym_PIPE,
      sym_table_separator,
      aux_sym_directive_token1,
      anon_sym_COLON,
      aux_sym_comment_token1,
      aux_sym_fixed_width_token1,
      anon_sym_COLONPROPERTIES_COLON,
      sym_horizontal_rule,
      aux_sym_paragraph_token1,
  [600] = 2,
    ACTIONS(180), 1,
      ts_builtin_sym_end,
    ACTIONS(182), 25,
      sym_stars,
      sym_planning_line,
      sym_clock,
      sym_diary_sexp,
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
      aux_sym_dynamic_block_begin_token1,
      anon_sym_PIPE,
      sym_table_separator,
      aux_sym_directive_token1,
      anon_sym_COLON,
      aux_sym_comment_token1,
      aux_sym_fixed_width_token1,
      anon_sym_COLONPROPERTIES_COLON,
      sym_horizontal_rule,
      aux_sym_paragraph_token1,
  [631] = 2,
    ACTIONS(184), 1,
      ts_builtin_sym_end,
    ACTIONS(186), 25,
      sym_stars,
      sym_planning_line,
      sym_clock,
      sym_diary_sexp,
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
      aux_sym_dynamic_block_begin_token1,
      anon_sym_PIPE,
      sym_table_separator,
      aux_sym_directive_token1,
      anon_sym_COLON,
      aux_sym_comment_token1,
      aux_sym_fixed_width_token1,
      anon_sym_COLONPROPERTIES_COLON,
      sym_horizontal_rule,
      aux_sym_paragraph_token1,
  [662] = 2,
    ACTIONS(188), 1,
      ts_builtin_sym_end,
    ACTIONS(190), 25,
      sym_stars,
      sym_planning_line,
      sym_clock,
      sym_diary_sexp,
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
      aux_sym_dynamic_block_begin_token1,
      anon_sym_PIPE,
      sym_table_separator,
      aux_sym_directive_token1,
      anon_sym_COLON,
      aux_sym_comment_token1,
      aux_sym_fixed_width_token1,
      anon_sym_COLONPROPERTIES_COLON,
      sym_horizontal_rule,
      aux_sym_paragraph_token1,
  [693] = 2,
    ACTIONS(192), 1,
      ts_builtin_sym_end,
    ACTIONS(194), 25,
      sym_stars,
      sym_planning_line,
      sym_clock,
      sym_diary_sexp,
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
      aux_sym_dynamic_block_begin_token1,
      anon_sym_PIPE,
      sym_table_separator,
      aux_sym_directive_token1,
      anon_sym_COLON,
      aux_sym_comment_token1,
      aux_sym_fixed_width_token1,
      anon_sym_COLONPROPERTIES_COLON,
      sym_horizontal_rule,
      aux_sym_paragraph_token1,
  [724] = 2,
    ACTIONS(196), 1,
      ts_builtin_sym_end,
    ACTIONS(198), 25,
      sym_stars,
      sym_planning_line,
      sym_clock,
      sym_diary_sexp,
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
      aux_sym_dynamic_block_begin_token1,
      anon_sym_PIPE,
      sym_table_separator,
      aux_sym_directive_token1,
      anon_sym_COLON,
      aux_sym_comment_token1,
      aux_sym_fixed_width_token1,
      anon_sym_COLONPROPERTIES_COLON,
      sym_horizontal_rule,
      aux_sym_paragraph_token1,
  [755] = 2,
    ACTIONS(200), 1,
      ts_builtin_sym_end,
    ACTIONS(202), 25,
      sym_stars,
      sym_planning_line,
      sym_clock,
      sym_diary_sexp,
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
      aux_sym_dynamic_block_begin_token1,
      anon_sym_PIPE,
      sym_table_separator,
      aux_sym_directive_token1,
      anon_sym_COLON,
      aux_sym_comment_token1,
      aux_sym_fixed_width_token1,
      anon_sym_COLONPROPERTIES_COLON,
      sym_horizontal_rule,
      aux_sym_paragraph_token1,
  [786] = 2,
    ACTIONS(204), 1,
      ts_builtin_sym_end,
    ACTIONS(206), 25,
      sym_stars,
      sym_planning_line,
      sym_clock,
      sym_diary_sexp,
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
      aux_sym_dynamic_block_begin_token1,
      anon_sym_PIPE,
      sym_table_separator,
      aux_sym_directive_token1,
      anon_sym_COLON,
      aux_sym_comment_token1,
      aux_sym_fixed_width_token1,
      anon_sym_COLONPROPERTIES_COLON,
      sym_horizontal_rule,
      aux_sym_paragraph_token1,
  [817] = 2,
    ACTIONS(208), 1,
      ts_builtin_sym_end,
    ACTIONS(210), 25,
      sym_stars,
      sym_planning_line,
      sym_clock,
      sym_diary_sexp,
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
      aux_sym_dynamic_block_begin_token1,
      anon_sym_PIPE,
      sym_table_separator,
      aux_sym_directive_token1,
      anon_sym_COLON,
      aux_sym_comment_token1,
      aux_sym_fixed_width_token1,
      anon_sym_COLONPROPERTIES_COLON,
      sym_horizontal_rule,
      aux_sym_paragraph_token1,
  [848] = 2,
    ACTIONS(212), 1,
      ts_builtin_sym_end,
    ACTIONS(214), 25,
      sym_stars,
      sym_planning_line,
      sym_clock,
      sym_diary_sexp,
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
      aux_sym_dynamic_block_begin_token1,
      anon_sym_PIPE,
      sym_table_separator,
      aux_sym_directive_token1,
      anon_sym_COLON,
      aux_sym_comment_token1,
      aux_sym_fixed_width_token1,
      anon_sym_COLONPROPERTIES_COLON,
      sym_horizontal_rule,
      aux_sym_paragraph_token1,
  [879] = 2,
    ACTIONS(216), 1,
      ts_builtin_sym_end,
    ACTIONS(218), 25,
      sym_stars,
      sym_planning_line,
      sym_clock,
      sym_diary_sexp,
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
      aux_sym_dynamic_block_begin_token1,
      anon_sym_PIPE,
      sym_table_separator,
      aux_sym_directive_token1,
      anon_sym_COLON,
      aux_sym_comment_token1,
      aux_sym_fixed_width_token1,
      anon_sym_COLONPROPERTIES_COLON,
      sym_horizontal_rule,
      aux_sym_paragraph_token1,
  [910] = 2,
    ACTIONS(220), 1,
      ts_builtin_sym_end,
    ACTIONS(222), 25,
      sym_stars,
      sym_planning_line,
      sym_clock,
      sym_diary_sexp,
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
      aux_sym_dynamic_block_begin_token1,
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
    ACTIONS(224), 1,
      ts_builtin_sym_end,
    ACTIONS(226), 25,
      sym_stars,
      sym_planning_line,
      sym_clock,
      sym_diary_sexp,
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
      aux_sym_dynamic_block_begin_token1,
      anon_sym_PIPE,
      sym_table_separator,
      aux_sym_directive_token1,
      anon_sym_COLON,
      aux_sym_comment_token1,
      aux_sym_fixed_width_token1,
      anon_sym_COLONPROPERTIES_COLON,
      sym_horizontal_rule,
      aux_sym_paragraph_token1,
  [972] = 2,
    ACTIONS(228), 1,
      ts_builtin_sym_end,
    ACTIONS(230), 25,
      sym_stars,
      sym_planning_line,
      sym_clock,
      sym_diary_sexp,
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
      aux_sym_dynamic_block_begin_token1,
      anon_sym_PIPE,
      sym_table_separator,
      aux_sym_directive_token1,
      anon_sym_COLON,
      aux_sym_comment_token1,
      aux_sym_fixed_width_token1,
      anon_sym_COLONPROPERTIES_COLON,
      sym_horizontal_rule,
      aux_sym_paragraph_token1,
  [1003] = 2,
    ACTIONS(232), 1,
      ts_builtin_sym_end,
    ACTIONS(234), 25,
      sym_stars,
      sym_planning_line,
      sym_clock,
      sym_diary_sexp,
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
      aux_sym_dynamic_block_begin_token1,
      anon_sym_PIPE,
      sym_table_separator,
      aux_sym_directive_token1,
      anon_sym_COLON,
      aux_sym_comment_token1,
      aux_sym_fixed_width_token1,
      anon_sym_COLONPROPERTIES_COLON,
      sym_horizontal_rule,
      aux_sym_paragraph_token1,
  [1034] = 2,
    ACTIONS(236), 1,
      ts_builtin_sym_end,
    ACTIONS(238), 25,
      sym_stars,
      sym_planning_line,
      sym_clock,
      sym_diary_sexp,
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
      aux_sym_dynamic_block_begin_token1,
      anon_sym_PIPE,
      sym_table_separator,
      aux_sym_directive_token1,
      anon_sym_COLON,
      aux_sym_comment_token1,
      aux_sym_fixed_width_token1,
      anon_sym_COLONPROPERTIES_COLON,
      sym_horizontal_rule,
      aux_sym_paragraph_token1,
  [1065] = 2,
    ACTIONS(240), 1,
      ts_builtin_sym_end,
    ACTIONS(242), 25,
      sym_stars,
      sym_planning_line,
      sym_clock,
      sym_diary_sexp,
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
      aux_sym_dynamic_block_begin_token1,
      anon_sym_PIPE,
      sym_table_separator,
      aux_sym_directive_token1,
      anon_sym_COLON,
      aux_sym_comment_token1,
      aux_sym_fixed_width_token1,
      anon_sym_COLONPROPERTIES_COLON,
      sym_horizontal_rule,
      aux_sym_paragraph_token1,
  [1096] = 2,
    ACTIONS(244), 1,
      ts_builtin_sym_end,
    ACTIONS(246), 25,
      sym_stars,
      sym_planning_line,
      sym_clock,
      sym_diary_sexp,
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
      aux_sym_dynamic_block_begin_token1,
      anon_sym_PIPE,
      sym_table_separator,
      aux_sym_directive_token1,
      anon_sym_COLON,
      aux_sym_comment_token1,
      aux_sym_fixed_width_token1,
      anon_sym_COLONPROPERTIES_COLON,
      sym_horizontal_rule,
      aux_sym_paragraph_token1,
  [1127] = 2,
    ACTIONS(248), 1,
      ts_builtin_sym_end,
    ACTIONS(250), 25,
      sym_stars,
      sym_planning_line,
      sym_clock,
      sym_diary_sexp,
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
      aux_sym_dynamic_block_begin_token1,
      anon_sym_PIPE,
      sym_table_separator,
      aux_sym_directive_token1,
      anon_sym_COLON,
      aux_sym_comment_token1,
      aux_sym_fixed_width_token1,
      anon_sym_COLONPROPERTIES_COLON,
      sym_horizontal_rule,
      aux_sym_paragraph_token1,
  [1158] = 2,
    ACTIONS(252), 1,
      ts_builtin_sym_end,
    ACTIONS(254), 25,
      sym_stars,
      sym_planning_line,
      sym_clock,
      sym_diary_sexp,
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
      aux_sym_dynamic_block_begin_token1,
      anon_sym_PIPE,
      sym_table_separator,
      aux_sym_directive_token1,
      anon_sym_COLON,
      aux_sym_comment_token1,
      aux_sym_fixed_width_token1,
      anon_sym_COLONPROPERTIES_COLON,
      sym_horizontal_rule,
      aux_sym_paragraph_token1,
  [1189] = 5,
    ACTIONS(256), 1,
      anon_sym_LF,
    ACTIONS(258), 1,
      sym_keyword,
    ACTIONS(260), 1,
      sym_priority,
    ACTIONS(262), 1,
      aux_sym_title_token1,
    STATE(121), 1,
      sym_title,
  [1205] = 4,
    ACTIONS(262), 1,
      aux_sym_title_token1,
    ACTIONS(264), 1,
      anon_sym_LF,
    ACTIONS(266), 1,
      sym_priority,
    STATE(99), 1,
      sym_title,
  [1218] = 4,
    ACTIONS(268), 1,
      anon_sym_LF,
    ACTIONS(270), 1,
      anon_sym_PIPE,
    ACTIONS(272), 1,
      sym_table_cell,
    STATE(46), 1,
      aux_sym_table_row_repeat1,
  [1231] = 3,
    ACTIONS(274), 1,
      anon_sym_COLON,
    ACTIONS(276), 1,
      anon_sym_COLONEND_COLON,
    STATE(45), 2,
      sym_property,
      aux_sym_property_drawer_repeat1,
  [1242] = 3,
    ACTIONS(278), 1,
      anon_sym_COLON,
    ACTIONS(281), 1,
      anon_sym_COLONEND_COLON,
    STATE(45), 2,
      sym_property,
      aux_sym_property_drawer_repeat1,
  [1253] = 4,
    ACTIONS(283), 1,
      anon_sym_LF,
    ACTIONS(285), 1,
      anon_sym_PIPE,
    ACTIONS(288), 1,
      sym_table_cell,
    STATE(46), 1,
      aux_sym_table_row_repeat1,
  [1266] = 4,
    ACTIONS(272), 1,
      sym_table_cell,
    ACTIONS(291), 1,
      anon_sym_LF,
    ACTIONS(293), 1,
      anon_sym_PIPE,
    STATE(43), 1,
      aux_sym_table_row_repeat1,
  [1279] = 3,
    ACTIONS(262), 1,
      aux_sym_title_token1,
    ACTIONS(295), 1,
      anon_sym_LF,
    STATE(101), 1,
      sym_title,
  [1289] = 2,
    ACTIONS(297), 1,
      anon_sym_COLON,
    STATE(44), 2,
      sym_property,
      aux_sym_property_drawer_repeat1,
  [1297] = 1,
    ACTIONS(283), 3,
      anon_sym_LF,
      anon_sym_PIPE,
      sym_table_cell,
  [1303] = 3,
    ACTIONS(299), 1,
      sym_dynamic_block_content,
    ACTIONS(301), 1,
      aux_sym_dynamic_block_end_token1,
    STATE(31), 1,
      sym_dynamic_block_end,
  [1313] = 3,
    ACTIONS(303), 1,
      sym_block_content,
    ACTIONS(305), 1,
      aux_sym_block_end_token1,
    STATE(37), 1,
      sym_block_end,
  [1323] = 3,
    ACTIONS(262), 1,
      aux_sym_title_token1,
    ACTIONS(307), 1,
      anon_sym_LF,
    STATE(128), 1,
      sym_title,
  [1333] = 2,
    ACTIONS(309), 1,
      sym_block_content,
    ACTIONS(311), 1,
      aux_sym_block_end_token1,
  [1340] = 2,
    ACTIONS(313), 1,
      sym_dynamic_block_content,
    ACTIONS(315), 1,
      aux_sym_dynamic_block_end_token1,
  [1347] = 2,
    ACTIONS(317), 1,
      anon_sym_COLON,
    ACTIONS(319), 1,
      anon_sym_COLONEND_COLON,
  [1354] = 2,
    ACTIONS(321), 1,
      aux_sym_title_token1,
    STATE(138), 1,
      sym_value,
  [1361] = 2,
    ACTIONS(323), 1,
      sym_block_content,
    ACTIONS(325), 1,
      aux_sym_block_end_token1,
  [1368] = 2,
    ACTIONS(327), 1,
      aux_sym_key_token1,
    STATE(87), 1,
      sym_drawer_name,
  [1375] = 2,
    ACTIONS(329), 1,
      anon_sym_COLONend_COLON,
    ACTIONS(331), 1,
      sym_drawer_content,
  [1382] = 2,
    ACTIONS(333), 1,
      anon_sym_LPAREN,
    ACTIONS(335), 1,
      anon_sym_RBRACE_RBRACE_RBRACE,
  [1389] = 2,
    ACTIONS(337), 1,
      sym_dynamic_block_content,
    ACTIONS(339), 1,
      aux_sym_dynamic_block_end_token1,
  [1396] = 2,
    ACTIONS(341), 1,
      anon_sym_RBRACK_LBRACK,
    ACTIONS(343), 1,
      anon_sym_RBRACK_RBRACK,
  [1403] = 2,
    ACTIONS(345), 1,
      aux_sym_key_token1,
    STATE(112), 1,
      sym_key,
  [1410] = 2,
    ACTIONS(347), 1,
      aux_sym_list_item_token2,
    ACTIONS(349), 1,
      sym_block_type,
  [1417] = 2,
    ACTIONS(351), 1,
      anon_sym_SPACE,
    ACTIONS(353), 1,
      anon_sym_LF,
  [1424] = 2,
    ACTIONS(355), 1,
      sym_block_content,
    ACTIONS(357), 1,
      aux_sym_block_end_token1,
  [1431] = 2,
    ACTIONS(359), 1,
      anon_sym_LF,
    ACTIONS(361), 1,
      aux_sym_list_item_token2,
  [1438] = 2,
    ACTIONS(363), 1,
      aux_sym_title_token1,
    ACTIONS(365), 1,
      aux_sym_list_item_token1,
  [1445] = 2,
    ACTIONS(367), 1,
      aux_sym_block_end_token1,
    STATE(11), 1,
      sym_block_end,
  [1452] = 2,
    ACTIONS(369), 1,
      anon_sym_LF,
    ACTIONS(371), 1,
      aux_sym_list_item_token2,
  [1459] = 2,
    ACTIONS(373), 1,
      aux_sym_dynamic_block_end_token1,
    STATE(40), 1,
      sym_dynamic_block_end,
  [1466] = 1,
    ACTIONS(375), 1,
      aux_sym_dynamic_block_begin_token2,
  [1470] = 1,
    ACTIONS(377), 1,
      anon_sym_LF,
  [1474] = 1,
    ACTIONS(379), 1,
      anon_sym_LF,
  [1478] = 1,
    ACTIONS(381), 1,
      sym_language,
  [1482] = 1,
    ACTIONS(383), 1,
      aux_sym_property_drawer_token1,
  [1486] = 1,
    ACTIONS(385), 1,
      anon_sym_SPACE,
  [1490] = 1,
    ACTIONS(387), 1,
      anon_sym_LF,
  [1494] = 1,
    ACTIONS(389), 1,
      aux_sym_list_item_token2,
  [1498] = 1,
    ACTIONS(391), 1,
      anon_sym_LF,
  [1502] = 1,
    ACTIONS(393), 1,
      anon_sym_LF,
  [1506] = 1,
    ACTIONS(395), 1,
      anon_sym_LF,
  [1510] = 1,
    ACTIONS(397), 1,
      anon_sym_RPAREN,
  [1514] = 1,
    ACTIONS(399), 1,
      anon_sym_LF,
  [1518] = 1,
    ACTIONS(401), 1,
      anon_sym_RBRACK_RBRACK,
  [1522] = 1,
    ACTIONS(403), 1,
      anon_sym_COLON,
  [1526] = 1,
    ACTIONS(405), 1,
      anon_sym_LF,
  [1530] = 1,
    ACTIONS(407), 1,
      anon_sym_COLON,
  [1534] = 1,
    ACTIONS(409), 1,
      anon_sym_LF,
  [1538] = 1,
    ACTIONS(411), 1,
      anon_sym_LF,
  [1542] = 1,
    ACTIONS(413), 1,
      aux_sym_title_token1,
  [1546] = 1,
    ACTIONS(415), 1,
      anon_sym_LF,
  [1550] = 1,
    ACTIONS(417), 1,
      anon_sym_COLON,
  [1554] = 1,
    ACTIONS(419), 1,
      anon_sym_PIPE,
  [1558] = 1,
    ACTIONS(421), 1,
      anon_sym_LF,
  [1562] = 1,
    ACTIONS(423), 1,
      aux_sym_list_item_token2,
  [1566] = 1,
    ACTIONS(425), 1,
      anon_sym_SPACE,
  [1570] = 1,
    ACTIONS(427), 1,
      anon_sym_LF,
  [1574] = 1,
    ACTIONS(429), 1,
      aux_sym_list_item_token2,
  [1578] = 1,
    ACTIONS(431), 1,
      anon_sym_LF,
  [1582] = 1,
    ACTIONS(433), 1,
      anon_sym_RBRACE_RBRACE_RBRACE,
  [1586] = 1,
    ACTIONS(435), 1,
      anon_sym_LF,
  [1590] = 1,
    ACTIONS(437), 1,
      anon_sym_SPACE,
  [1594] = 1,
    ACTIONS(439), 1,
      anon_sym_SPACE,
  [1598] = 1,
    ACTIONS(441), 1,
      aux_sym_list_item_token2,
  [1602] = 1,
    ACTIONS(443), 1,
      anon_sym_LF,
  [1606] = 1,
    ACTIONS(445), 1,
      aux_sym_link_token1,
  [1610] = 1,
    ACTIONS(447), 1,
      anon_sym_LF,
  [1614] = 1,
    ACTIONS(449), 1,
      anon_sym_LF,
  [1618] = 1,
    ACTIONS(451), 1,
      anon_sym_COLON,
  [1622] = 1,
    ACTIONS(453), 1,
      anon_sym_COLON,
  [1626] = 1,
    ACTIONS(455), 1,
      aux_sym_property_drawer_token1,
  [1630] = 1,
    ACTIONS(457), 1,
      ts_builtin_sym_end,
  [1634] = 1,
    ACTIONS(459), 1,
      aux_sym_paragraph_token2,
  [1638] = 1,
    ACTIONS(461), 1,
      aux_sym_property_drawer_token1,
  [1642] = 1,
    ACTIONS(463), 1,
      aux_sym_list_item_token2,
  [1646] = 1,
    ACTIONS(465), 1,
      aux_sym_list_item_token2,
  [1650] = 1,
    ACTIONS(467), 1,
      anon_sym_LF,
  [1654] = 1,
    ACTIONS(469), 1,
      aux_sym_macro_token2,
  [1658] = 1,
    ACTIONS(471), 1,
      anon_sym_LF,
  [1662] = 1,
    ACTIONS(473), 1,
      sym_name,
  [1666] = 1,
    ACTIONS(475), 1,
      aux_sym_property_drawer_token1,
  [1670] = 1,
    ACTIONS(477), 1,
      anon_sym_COLONend_COLON,
  [1674] = 1,
    ACTIONS(479), 1,
      aux_sym_property_drawer_token1,
  [1678] = 1,
    ACTIONS(481), 1,
      anon_sym_LF,
  [1682] = 1,
    ACTIONS(483), 1,
      aux_sym_list_item_token1,
  [1686] = 1,
    ACTIONS(485), 1,
      anon_sym_LF,
  [1690] = 1,
    ACTIONS(487), 1,
      sym_block_type,
  [1694] = 1,
    ACTIONS(489), 1,
      anon_sym_LF,
  [1698] = 1,
    ACTIONS(491), 1,
      aux_sym_property_drawer_token1,
  [1702] = 1,
    ACTIONS(493), 1,
      anon_sym_LF,
  [1706] = 1,
    ACTIONS(495), 1,
      anon_sym_SPACE,
  [1710] = 1,
    ACTIONS(497), 1,
      sym_bullet,
  [1714] = 1,
    ACTIONS(499), 1,
      aux_sym_link_token1,
  [1718] = 1,
    ACTIONS(501), 1,
      anon_sym_LF,
  [1722] = 1,
    ACTIONS(503), 1,
      anon_sym_LF,
  [1726] = 1,
    ACTIONS(505), 1,
      anon_sym_LF,
  [1730] = 1,
    ACTIONS(507), 1,
      aux_sym_macro_token1,
  [1734] = 1,
    ACTIONS(509), 1,
      anon_sym_SPACE,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(4)] = 0,
  [SMALL_STATE(5)] = 39,
  [SMALL_STATE(6)] = 78,
  [SMALL_STATE(7)] = 117,
  [SMALL_STATE(8)] = 156,
  [SMALL_STATE(9)] = 192,
  [SMALL_STATE(10)] = 228,
  [SMALL_STATE(11)] = 259,
  [SMALL_STATE(12)] = 290,
  [SMALL_STATE(13)] = 321,
  [SMALL_STATE(14)] = 352,
  [SMALL_STATE(15)] = 383,
  [SMALL_STATE(16)] = 414,
  [SMALL_STATE(17)] = 445,
  [SMALL_STATE(18)] = 476,
  [SMALL_STATE(19)] = 507,
  [SMALL_STATE(20)] = 538,
  [SMALL_STATE(21)] = 569,
  [SMALL_STATE(22)] = 600,
  [SMALL_STATE(23)] = 631,
  [SMALL_STATE(24)] = 662,
  [SMALL_STATE(25)] = 693,
  [SMALL_STATE(26)] = 724,
  [SMALL_STATE(27)] = 755,
  [SMALL_STATE(28)] = 786,
  [SMALL_STATE(29)] = 817,
  [SMALL_STATE(30)] = 848,
  [SMALL_STATE(31)] = 879,
  [SMALL_STATE(32)] = 910,
  [SMALL_STATE(33)] = 941,
  [SMALL_STATE(34)] = 972,
  [SMALL_STATE(35)] = 1003,
  [SMALL_STATE(36)] = 1034,
  [SMALL_STATE(37)] = 1065,
  [SMALL_STATE(38)] = 1096,
  [SMALL_STATE(39)] = 1127,
  [SMALL_STATE(40)] = 1158,
  [SMALL_STATE(41)] = 1189,
  [SMALL_STATE(42)] = 1205,
  [SMALL_STATE(43)] = 1218,
  [SMALL_STATE(44)] = 1231,
  [SMALL_STATE(45)] = 1242,
  [SMALL_STATE(46)] = 1253,
  [SMALL_STATE(47)] = 1266,
  [SMALL_STATE(48)] = 1279,
  [SMALL_STATE(49)] = 1289,
  [SMALL_STATE(50)] = 1297,
  [SMALL_STATE(51)] = 1303,
  [SMALL_STATE(52)] = 1313,
  [SMALL_STATE(53)] = 1323,
  [SMALL_STATE(54)] = 1333,
  [SMALL_STATE(55)] = 1340,
  [SMALL_STATE(56)] = 1347,
  [SMALL_STATE(57)] = 1354,
  [SMALL_STATE(58)] = 1361,
  [SMALL_STATE(59)] = 1368,
  [SMALL_STATE(60)] = 1375,
  [SMALL_STATE(61)] = 1382,
  [SMALL_STATE(62)] = 1389,
  [SMALL_STATE(63)] = 1396,
  [SMALL_STATE(64)] = 1403,
  [SMALL_STATE(65)] = 1410,
  [SMALL_STATE(66)] = 1417,
  [SMALL_STATE(67)] = 1424,
  [SMALL_STATE(68)] = 1431,
  [SMALL_STATE(69)] = 1438,
  [SMALL_STATE(70)] = 1445,
  [SMALL_STATE(71)] = 1452,
  [SMALL_STATE(72)] = 1459,
  [SMALL_STATE(73)] = 1466,
  [SMALL_STATE(74)] = 1470,
  [SMALL_STATE(75)] = 1474,
  [SMALL_STATE(76)] = 1478,
  [SMALL_STATE(77)] = 1482,
  [SMALL_STATE(78)] = 1486,
  [SMALL_STATE(79)] = 1490,
  [SMALL_STATE(80)] = 1494,
  [SMALL_STATE(81)] = 1498,
  [SMALL_STATE(82)] = 1502,
  [SMALL_STATE(83)] = 1506,
  [SMALL_STATE(84)] = 1510,
  [SMALL_STATE(85)] = 1514,
  [SMALL_STATE(86)] = 1518,
  [SMALL_STATE(87)] = 1522,
  [SMALL_STATE(88)] = 1526,
  [SMALL_STATE(89)] = 1530,
  [SMALL_STATE(90)] = 1534,
  [SMALL_STATE(91)] = 1538,
  [SMALL_STATE(92)] = 1542,
  [SMALL_STATE(93)] = 1546,
  [SMALL_STATE(94)] = 1550,
  [SMALL_STATE(95)] = 1554,
  [SMALL_STATE(96)] = 1558,
  [SMALL_STATE(97)] = 1562,
  [SMALL_STATE(98)] = 1566,
  [SMALL_STATE(99)] = 1570,
  [SMALL_STATE(100)] = 1574,
  [SMALL_STATE(101)] = 1578,
  [SMALL_STATE(102)] = 1582,
  [SMALL_STATE(103)] = 1586,
  [SMALL_STATE(104)] = 1590,
  [SMALL_STATE(105)] = 1594,
  [SMALL_STATE(106)] = 1598,
  [SMALL_STATE(107)] = 1602,
  [SMALL_STATE(108)] = 1606,
  [SMALL_STATE(109)] = 1610,
  [SMALL_STATE(110)] = 1614,
  [SMALL_STATE(111)] = 1618,
  [SMALL_STATE(112)] = 1622,
  [SMALL_STATE(113)] = 1626,
  [SMALL_STATE(114)] = 1630,
  [SMALL_STATE(115)] = 1634,
  [SMALL_STATE(116)] = 1638,
  [SMALL_STATE(117)] = 1642,
  [SMALL_STATE(118)] = 1646,
  [SMALL_STATE(119)] = 1650,
  [SMALL_STATE(120)] = 1654,
  [SMALL_STATE(121)] = 1658,
  [SMALL_STATE(122)] = 1662,
  [SMALL_STATE(123)] = 1666,
  [SMALL_STATE(124)] = 1670,
  [SMALL_STATE(125)] = 1674,
  [SMALL_STATE(126)] = 1678,
  [SMALL_STATE(127)] = 1682,
  [SMALL_STATE(128)] = 1686,
  [SMALL_STATE(129)] = 1690,
  [SMALL_STATE(130)] = 1694,
  [SMALL_STATE(131)] = 1698,
  [SMALL_STATE(132)] = 1702,
  [SMALL_STATE(133)] = 1706,
  [SMALL_STATE(134)] = 1710,
  [SMALL_STATE(135)] = 1714,
  [SMALL_STATE(136)] = 1718,
  [SMALL_STATE(137)] = 1722,
  [SMALL_STATE(138)] = 1726,
  [SMALL_STATE(139)] = 1730,
  [SMALL_STATE(140)] = 1734,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_document, 0, 0, 0),
  [5] = {.entry = {.count = 1, .reusable = false}}, SHIFT(78),
  [7] = {.entry = {.count = 1, .reusable = false}}, SHIFT(3),
  [9] = {.entry = {.count = 1, .reusable = false}}, SHIFT(139),
  [11] = {.entry = {.count = 1, .reusable = false}}, SHIFT(135),
  [13] = {.entry = {.count = 1, .reusable = false}}, SHIFT(134),
  [15] = {.entry = {.count = 1, .reusable = false}}, SHIFT(133),
  [17] = {.entry = {.count = 1, .reusable = false}}, SHIFT(129),
  [19] = {.entry = {.count = 1, .reusable = false}}, SHIFT(127),
  [21] = {.entry = {.count = 1, .reusable = false}}, SHIFT(47),
  [23] = {.entry = {.count = 1, .reusable = false}}, SHIFT(7),
  [25] = {.entry = {.count = 1, .reusable = false}}, SHIFT(122),
  [27] = {.entry = {.count = 1, .reusable = false}}, SHIFT(59),
  [29] = {.entry = {.count = 1, .reusable = false}}, SHIFT(118),
  [31] = {.entry = {.count = 1, .reusable = false}}, SHIFT(117),
  [33] = {.entry = {.count = 1, .reusable = false}}, SHIFT(116),
  [35] = {.entry = {.count = 1, .reusable = false}}, SHIFT(115),
  [37] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0),
  [39] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(78),
  [42] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(2),
  [45] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(139),
  [48] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(135),
  [51] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(134),
  [54] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(133),
  [57] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(129),
  [60] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(127),
  [63] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(47),
  [66] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(7),
  [69] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(122),
  [72] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(59),
  [75] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(118),
  [78] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(117),
  [81] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(116),
  [84] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(115),
  [87] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_document, 1, 0, 0),
  [89] = {.entry = {.count = 1, .reusable = false}}, SHIFT(2),
  [91] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_list, 1, 0, 0),
  [93] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_list, 1, 0, 0),
  [95] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_table_repeat1, 2, 0, 0),
  [97] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_table_repeat1, 2, 0, 0),
  [99] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_table_repeat1, 2, 0, 0), SHIFT_REPEAT(47),
  [102] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_table_repeat1, 2, 0, 0), SHIFT_REPEAT(5),
  [105] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_list_repeat1, 2, 0, 0),
  [107] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_list_repeat1, 2, 0, 0),
  [109] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_list_repeat1, 2, 0, 0), SHIFT_REPEAT(134),
  [112] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_list_repeat1, 2, 0, 0), SHIFT_REPEAT(133),
  [115] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_table, 1, 0, 0),
  [117] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_table, 1, 0, 0),
  [119] = {.entry = {.count = 1, .reusable = false}}, SHIFT(5),
  [121] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_fixed_width_repeat1, 2, 0, 0),
  [123] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_fixed_width_repeat1, 2, 0, 0),
  [125] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_fixed_width_repeat1, 2, 0, 0), SHIFT_REPEAT(117),
  [128] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_fixed_width, 1, 0, 0),
  [130] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_fixed_width, 1, 0, 0),
  [132] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_headline, 5, 0, 5),
  [134] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_headline, 5, 0, 5),
  [136] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_block, 3, 0, 0),
  [138] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_block, 3, 0, 0),
  [140] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_headline, 7, 0, 12),
  [142] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_headline, 7, 0, 12),
  [144] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_directive, 6, 0, 11),
  [146] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_directive, 6, 0, 11),
  [148] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_fixed_width_repeat1, 3, 0, 0),
  [150] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_fixed_width_repeat1, 3, 0, 0),
  [152] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_link, 6, 0, 10),
  [154] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_link, 6, 0, 10),
  [156] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_headline, 6, 0, 9),
  [158] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_headline, 6, 0, 9),
  [160] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_headline, 6, 0, 8),
  [162] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_headline, 6, 0, 8),
  [164] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_comment, 3, 0, 0),
  [166] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_comment, 3, 0, 0),
  [168] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_block_end, 4, 0, 0),
  [170] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_block_end, 4, 0, 0),
  [172] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_headline, 3, 0, 0),
  [174] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_headline, 3, 0, 0),
  [176] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_directive, 5, 0, 7),
  [178] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_directive, 5, 0, 7),
  [180] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_drawer, 8, 0, 0),
  [182] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_drawer, 8, 0, 0),
  [184] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_headline, 8, 0, 13),
  [186] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_headline, 8, 0, 13),
  [188] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_property_drawer, 7, 0, 0),
  [190] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_property_drawer, 7, 0, 0),
  [192] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_list_item, 5, 0, 0),
  [194] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_list_item, 5, 0, 0),
  [196] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_drawer, 9, 0, 0),
  [198] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_drawer, 9, 0, 0),
  [200] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_headline, 5, 0, 4),
  [202] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_headline, 5, 0, 4),
  [204] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dynamic_block_end, 3, 0, 0),
  [206] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_dynamic_block_end, 3, 0, 0),
  [208] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_block_end, 3, 0, 0),
  [210] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_block_end, 3, 0, 0),
  [212] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_table_row, 2, 0, 0),
  [214] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_table_row, 2, 0, 0),
  [216] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dynamic_block, 2, 0, 0),
  [218] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_dynamic_block, 2, 0, 0),
  [220] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_table_row, 3, 0, 0),
  [222] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_table_row, 3, 0, 0),
  [224] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_list_item, 4, 0, 0),
  [226] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_list_item, 4, 0, 0),
  [228] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_link, 4, 0, 0),
  [230] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_link, 4, 0, 0),
  [232] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_macro, 4, 0, 0),
  [234] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_macro, 4, 0, 0),
  [236] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_headline, 4, 0, 2),
  [238] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_headline, 4, 0, 2),
  [240] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_block, 2, 0, 0),
  [242] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_block, 2, 0, 0),
  [244] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_macro, 7, 0, 0),
  [246] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_macro, 7, 0, 0),
  [248] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_paragraph, 2, 0, 0),
  [250] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_paragraph, 2, 0, 0),
  [252] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dynamic_block, 3, 0, 0),
  [254] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_dynamic_block, 3, 0, 0),
  [256] = {.entry = {.count = 1, .reusable = false}}, SHIFT(20),
  [258] = {.entry = {.count = 1, .reusable = false}}, SHIFT(105),
  [260] = {.entry = {.count = 1, .reusable = false}}, SHIFT(140),
  [262] = {.entry = {.count = 1, .reusable = false}}, SHIFT(132),
  [264] = {.entry = {.count = 1, .reusable = false}}, SHIFT(27),
  [266] = {.entry = {.count = 1, .reusable = false}}, SHIFT(98),
  [268] = {.entry = {.count = 1, .reusable = false}}, SHIFT(32),
  [270] = {.entry = {.count = 1, .reusable = false}}, SHIFT(46),
  [272] = {.entry = {.count = 1, .reusable = false}}, SHIFT(95),
  [274] = {.entry = {.count = 1, .reusable = false}}, SHIFT(64),
  [276] = {.entry = {.count = 1, .reusable = true}}, SHIFT(113),
  [278] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_property_drawer_repeat1, 2, 0, 0), SHIFT_REPEAT(64),
  [281] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_property_drawer_repeat1, 2, 0, 0),
  [283] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_table_row_repeat1, 2, 0, 0),
  [285] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_table_row_repeat1, 2, 0, 0), SHIFT_REPEAT(46),
  [288] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_table_row_repeat1, 2, 0, 0), SHIFT_REPEAT(95),
  [291] = {.entry = {.count = 1, .reusable = false}}, SHIFT(30),
  [293] = {.entry = {.count = 1, .reusable = false}}, SHIFT(43),
  [295] = {.entry = {.count = 1, .reusable = false}}, SHIFT(10),
  [297] = {.entry = {.count = 1, .reusable = true}}, SHIFT(64),
  [299] = {.entry = {.count = 1, .reusable = true}}, SHIFT(72),
  [301] = {.entry = {.count = 1, .reusable = false}}, SHIFT(97),
  [303] = {.entry = {.count = 1, .reusable = true}}, SHIFT(70),
  [305] = {.entry = {.count = 1, .reusable = false}}, SHIFT(65),
  [307] = {.entry = {.count = 1, .reusable = false}}, SHIFT(12),
  [309] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_block_begin, 5, 0, 6),
  [311] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_block_begin, 5, 0, 6),
  [313] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dynamic_block_begin, 4, 0, 3),
  [315] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_dynamic_block_begin, 4, 0, 3),
  [317] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_property, 6, 0, 0),
  [319] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_property, 6, 0, 0),
  [321] = {.entry = {.count = 1, .reusable = true}}, SHIFT(137),
  [323] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_block_begin, 6, 0, 6),
  [325] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_block_begin, 6, 0, 6),
  [327] = {.entry = {.count = 1, .reusable = true}}, SHIFT(89),
  [329] = {.entry = {.count = 1, .reusable = false}}, SHIFT(123),
  [331] = {.entry = {.count = 1, .reusable = true}}, SHIFT(124),
  [333] = {.entry = {.count = 1, .reusable = true}}, SHIFT(120),
  [335] = {.entry = {.count = 1, .reusable = true}}, SHIFT(110),
  [337] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dynamic_block_begin, 5, 0, 3),
  [339] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_dynamic_block_begin, 5, 0, 3),
  [341] = {.entry = {.count = 1, .reusable = true}}, SHIFT(108),
  [343] = {.entry = {.count = 1, .reusable = true}}, SHIFT(107),
  [345] = {.entry = {.count = 1, .reusable = true}}, SHIFT(111),
  [347] = {.entry = {.count = 1, .reusable = true}}, SHIFT(79),
  [349] = {.entry = {.count = 1, .reusable = false}}, SHIFT(80),
  [351] = {.entry = {.count = 1, .reusable = false}}, SHIFT(76),
  [353] = {.entry = {.count = 1, .reusable = false}}, SHIFT(67),
  [355] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_block_begin, 3, 0, 1),
  [357] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_block_begin, 3, 0, 1),
  [359] = {.entry = {.count = 1, .reusable = false}}, SHIFT(55),
  [361] = {.entry = {.count = 1, .reusable = false}}, SHIFT(90),
  [363] = {.entry = {.count = 1, .reusable = false}}, SHIFT(91),
  [365] = {.entry = {.count = 1, .reusable = false}}, SHIFT(92),
  [367] = {.entry = {.count = 1, .reusable = true}}, SHIFT(65),
  [369] = {.entry = {.count = 1, .reusable = false}}, SHIFT(54),
  [371] = {.entry = {.count = 1, .reusable = false}}, SHIFT(74),
  [373] = {.entry = {.count = 1, .reusable = true}}, SHIFT(97),
  [375] = {.entry = {.count = 1, .reusable = true}}, SHIFT(68),
  [377] = {.entry = {.count = 1, .reusable = true}}, SHIFT(58),
  [379] = {.entry = {.count = 1, .reusable = true}}, SHIFT(33),
  [381] = {.entry = {.count = 1, .reusable = true}}, SHIFT(71),
  [383] = {.entry = {.count = 1, .reusable = true}}, SHIFT(93),
  [385] = {.entry = {.count = 1, .reusable = true}}, SHIFT(41),
  [387] = {.entry = {.count = 1, .reusable = true}}, SHIFT(29),
  [389] = {.entry = {.count = 1, .reusable = true}}, SHIFT(96),
  [391] = {.entry = {.count = 1, .reusable = true}}, SHIFT(28),
  [393] = {.entry = {.count = 1, .reusable = true}}, SHIFT(49),
  [395] = {.entry = {.count = 1, .reusable = true}}, SHIFT(14),
  [397] = {.entry = {.count = 1, .reusable = true}}, SHIFT(102),
  [399] = {.entry = {.count = 1, .reusable = true}}, SHIFT(18),
  [401] = {.entry = {.count = 1, .reusable = true}}, SHIFT(103),
  [403] = {.entry = {.count = 1, .reusable = true}}, SHIFT(77),
  [405] = {.entry = {.count = 1, .reusable = true}}, SHIFT(25),
  [407] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_drawer_name, 1, 0, 0),
  [409] = {.entry = {.count = 1, .reusable = true}}, SHIFT(62),
  [411] = {.entry = {.count = 1, .reusable = true}}, SHIFT(21),
  [413] = {.entry = {.count = 1, .reusable = true}}, SHIFT(109),
  [415] = {.entry = {.count = 1, .reusable = true}}, SHIFT(60),
  [417] = {.entry = {.count = 1, .reusable = true}}, SHIFT(69),
  [419] = {.entry = {.count = 1, .reusable = true}}, SHIFT(50),
  [421] = {.entry = {.count = 1, .reusable = true}}, SHIFT(19),
  [423] = {.entry = {.count = 1, .reusable = true}}, SHIFT(81),
  [425] = {.entry = {.count = 1, .reusable = true}}, SHIFT(53),
  [427] = {.entry = {.count = 1, .reusable = true}}, SHIFT(17),
  [429] = {.entry = {.count = 1, .reusable = true}}, SHIFT(75),
  [431] = {.entry = {.count = 1, .reusable = true}}, SHIFT(16),
  [433] = {.entry = {.count = 1, .reusable = true}}, SHIFT(119),
  [435] = {.entry = {.count = 1, .reusable = true}}, SHIFT(15),
  [437] = {.entry = {.count = 1, .reusable = true}}, SHIFT(106),
  [439] = {.entry = {.count = 1, .reusable = true}}, SHIFT(42),
  [441] = {.entry = {.count = 1, .reusable = true}}, SHIFT(88),
  [443] = {.entry = {.count = 1, .reusable = true}}, SHIFT(34),
  [445] = {.entry = {.count = 1, .reusable = true}}, SHIFT(86),
  [447] = {.entry = {.count = 1, .reusable = true}}, SHIFT(13),
  [449] = {.entry = {.count = 1, .reusable = true}}, SHIFT(35),
  [451] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_key, 1, 0, 0),
  [453] = {.entry = {.count = 1, .reusable = true}}, SHIFT(125),
  [455] = {.entry = {.count = 1, .reusable = true}}, SHIFT(126),
  [457] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [459] = {.entry = {.count = 1, .reusable = true}}, SHIFT(39),
  [461] = {.entry = {.count = 1, .reusable = true}}, SHIFT(82),
  [463] = {.entry = {.count = 1, .reusable = true}}, SHIFT(83),
  [465] = {.entry = {.count = 1, .reusable = true}}, SHIFT(85),
  [467] = {.entry = {.count = 1, .reusable = true}}, SHIFT(38),
  [469] = {.entry = {.count = 1, .reusable = true}}, SHIFT(84),
  [471] = {.entry = {.count = 1, .reusable = true}}, SHIFT(36),
  [473] = {.entry = {.count = 1, .reusable = true}}, SHIFT(94),
  [475] = {.entry = {.count = 1, .reusable = true}}, SHIFT(130),
  [477] = {.entry = {.count = 1, .reusable = true}}, SHIFT(131),
  [479] = {.entry = {.count = 1, .reusable = true}}, SHIFT(57),
  [481] = {.entry = {.count = 1, .reusable = true}}, SHIFT(24),
  [483] = {.entry = {.count = 1, .reusable = true}}, SHIFT(73),
  [485] = {.entry = {.count = 1, .reusable = true}}, SHIFT(23),
  [487] = {.entry = {.count = 1, .reusable = true}}, SHIFT(66),
  [489] = {.entry = {.count = 1, .reusable = true}}, SHIFT(22),
  [491] = {.entry = {.count = 1, .reusable = true}}, SHIFT(136),
  [493] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_title, 1, 0, 0),
  [495] = {.entry = {.count = 1, .reusable = true}}, SHIFT(100),
  [497] = {.entry = {.count = 1, .reusable = true}}, SHIFT(104),
  [499] = {.entry = {.count = 1, .reusable = true}}, SHIFT(63),
  [501] = {.entry = {.count = 1, .reusable = true}}, SHIFT(26),
  [503] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_value, 1, 0, 0),
  [505] = {.entry = {.count = 1, .reusable = true}}, SHIFT(56),
  [507] = {.entry = {.count = 1, .reusable = true}}, SHIFT(61),
  [509] = {.entry = {.count = 1, .reusable = true}}, SHIFT(48),
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
