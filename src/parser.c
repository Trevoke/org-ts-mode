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
#define STATE_COUNT 155
#define LARGE_STATE_COUNT 4
#define SYMBOL_COUNT 95
#define ALIAS_COUNT 1
#define TOKEN_COUNT 60
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 6
#define MAX_ALIAS_SEQUENCE_LENGTH 9
#define PRODUCTION_ID_COUNT 15

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
  anon_sym_BSLASHbegin_LBRACE = 19,
  aux_sym_latex_env_begin_token1 = 20,
  anon_sym_RBRACE = 21,
  sym_latex_env_content = 22,
  anon_sym_BSLASHend_LBRACE = 23,
  sym_entity = 24,
  sym_subscript = 25,
  sym_superscript = 26,
  anon_sym_LBRACK_LBRACK = 27,
  aux_sym_link_token1 = 28,
  anon_sym_RBRACK_LBRACK = 29,
  anon_sym_RBRACK_RBRACK = 30,
  aux_sym_list_item_token1 = 31,
  aux_sym_list_item_token2 = 32,
  sym_bullet = 33,
  aux_sym_block_begin_token1 = 34,
  sym_block_type = 35,
  sym_language = 36,
  sym_block_content = 37,
  aux_sym_block_end_token1 = 38,
  aux_sym_dynamic_block_begin_token1 = 39,
  aux_sym_dynamic_block_begin_token2 = 40,
  sym_dynamic_block_content = 41,
  aux_sym_dynamic_block_end_token1 = 42,
  anon_sym_PIPE = 43,
  sym_table_cell = 44,
  sym_table_separator = 45,
  aux_sym_directive_token1 = 46,
  anon_sym_COLON = 47,
  sym_name = 48,
  aux_sym_comment_token1 = 49,
  aux_sym_fixed_width_token1 = 50,
  anon_sym_COLONPROPERTIES_COLON = 51,
  aux_sym_property_drawer_token1 = 52,
  anon_sym_COLONEND_COLON = 53,
  aux_sym_key_token1 = 54,
  anon_sym_COLONend_COLON = 55,
  sym_drawer_content = 56,
  sym_horizontal_rule = 57,
  aux_sym_paragraph_token1 = 58,
  aux_sym_paragraph_token2 = 59,
  sym_document = 60,
  sym__element = 61,
  sym_headline = 62,
  sym_title = 63,
  sym_macro = 64,
  sym_latex_environment = 65,
  sym_latex_env_begin = 66,
  sym_latex_env_end = 67,
  sym_link = 68,
  sym_list = 69,
  sym_list_item = 70,
  sym_block = 71,
  sym_block_begin = 72,
  sym_block_end = 73,
  sym_dynamic_block = 74,
  sym_dynamic_block_begin = 75,
  sym_dynamic_block_end = 76,
  sym_table = 77,
  sym_table_row = 78,
  sym_directive = 79,
  sym_comment = 80,
  sym_fixed_width = 81,
  sym_property_drawer = 82,
  sym_property = 83,
  sym_key = 84,
  sym_value = 85,
  sym_drawer = 86,
  sym_drawer_name = 87,
  sym_paragraph = 88,
  aux_sym_document_repeat1 = 89,
  aux_sym_list_repeat1 = 90,
  aux_sym_table_repeat1 = 91,
  aux_sym_table_row_repeat1 = 92,
  aux_sym_fixed_width_repeat1 = 93,
  aux_sym_property_drawer_repeat1 = 94,
  alias_sym_link_description = 95,
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
  [anon_sym_BSLASHbegin_LBRACE] = "\\begin{",
  [aux_sym_latex_env_begin_token1] = "latex_env_begin_token1",
  [anon_sym_RBRACE] = "}",
  [sym_latex_env_content] = "latex_env_content",
  [anon_sym_BSLASHend_LBRACE] = "\\end{",
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
  [sym_latex_environment] = "latex_environment",
  [sym_latex_env_begin] = "latex_env_begin",
  [sym_latex_env_end] = "latex_env_end",
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
  [anon_sym_BSLASHbegin_LBRACE] = anon_sym_BSLASHbegin_LBRACE,
  [aux_sym_latex_env_begin_token1] = aux_sym_latex_env_begin_token1,
  [anon_sym_RBRACE] = anon_sym_RBRACE,
  [sym_latex_env_content] = sym_latex_env_content,
  [anon_sym_BSLASHend_LBRACE] = anon_sym_BSLASHend_LBRACE,
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
  [sym_latex_environment] = sym_latex_environment,
  [sym_latex_env_begin] = sym_latex_env_begin,
  [sym_latex_env_end] = sym_latex_env_end,
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
  [anon_sym_BSLASHbegin_LBRACE] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_latex_env_begin_token1] = {
    .visible = false,
    .named = false,
  },
  [anon_sym_RBRACE] = {
    .visible = true,
    .named = false,
  },
  [sym_latex_env_content] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_BSLASHend_LBRACE] = {
    .visible = true,
    .named = false,
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
  [sym_latex_environment] = {
    .visible = true,
    .named = true,
  },
  [sym_latex_env_begin] = {
    .visible = true,
    .named = true,
  },
  [sym_latex_env_end] = {
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
  [6] = {.index = 5, .length = 1},
  [7] = {.index = 6, .length = 2},
  [9] = {.index = 8, .length = 2},
  [10] = {.index = 10, .length = 2},
  [13] = {.index = 12, .length = 2},
  [14] = {.index = 14, .length = 3},
};

static const TSFieldMapEntry ts_field_map_entries[] = {
  [0] =
    {field_type, 1},
  [1] =
    {field_title, 2},
  [2] =
    {field_name, 1},
  [3] =
    {field_name, 2},
  [4] =
    {field_keyword, 2},
  [5] =
    {field_priority, 2},
  [6] =
    {field_language, 3},
    {field_type, 1},
  [8] =
    {field_keyword, 2},
    {field_title, 4},
  [10] =
    {field_priority, 2},
    {field_title, 4},
  [12] =
    {field_keyword, 2},
    {field_priority, 4},
  [14] =
    {field_keyword, 2},
    {field_priority, 4},
    {field_title, 6},
};

static const TSSymbol ts_alias_sequences[PRODUCTION_ID_COUNT][MAX_ALIAS_SEQUENCE_LENGTH] = {
  [0] = {0},
  [8] = {
    [3] = sym_value,
  },
  [11] = {
    [3] = alias_sym_link_description,
  },
  [12] = {
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
  [141] = 141,
  [142] = 142,
  [143] = 143,
  [144] = 144,
  [145] = 145,
  [146] = 146,
  [147] = 147,
  [148] = 148,
  [149] = 149,
  [150] = 150,
  [151] = 151,
  [152] = 152,
  [153] = 153,
  [154] = 154,
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(182);
      ADVANCE_MAP(
        '#', 31,
        '$', 37,
        '%', 41,
        '(', 260,
        ')', 263,
        '*', 192,
        '-', 56,
        ':', 319,
        '<', 173,
        'C', 233,
        'D', 251,
        'N', 238,
        'T', 249,
        'W', 234,
        '[', 33,
        '\\', 109,
        ']', 93,
        '_', 298,
        '{', 125,
        '|', 311,
        '}', 273,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(0);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(255);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(256);
      END_STATE();
    case 1:
      if (lookahead == '\n') ADVANCE(315);
      if (lookahead == '+') ADVANCE(51);
      if (lookahead == '-') ADVANCE(1);
      if (lookahead == '|') ADVANCE(2);
      END_STATE();
    case 2:
      if (lookahead == '\n') ADVANCE(315);
      if (lookahead == '-') ADVANCE(1);
      END_STATE();
    case 3:
      if (lookahead == '\n') ADVANCE(266);
      END_STATE();
    case 4:
      if (lookahead == '\n') ADVANCE(230);
      END_STATE();
    case 5:
      if (lookahead == '\n') ADVANCE(45);
      if (lookahead == '(') ADVANCE(5);
      if (lookahead == ')') ADVANCE(7);
      if (lookahead != 0) ADVANCE(5);
      END_STATE();
    case 6:
      if (lookahead == '\n') ADVANCE(229);
      END_STATE();
    case 7:
      if (lookahead == '\n') ADVANCE(229);
      if (lookahead == '(') ADVANCE(5);
      if (lookahead == ')') ADVANCE(6);
      if (lookahead != 0) ADVANCE(44);
      END_STATE();
    case 8:
      if (lookahead == '\n') ADVANCE(335);
      if (lookahead == '-') ADVANCE(8);
      END_STATE();
    case 9:
      if (lookahead == '\n') ADVANCE(265);
      END_STATE();
    case 10:
      if (lookahead == '\n') ADVANCE(277);
      END_STATE();
    case 11:
      if (lookahead == '\n') ADVANCE(277);
      if (lookahead == 'e') ADVANCE(12);
      if (lookahead == '{') ADVANCE(128);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(16);
      END_STATE();
    case 12:
      if (lookahead == '\n') ADVANCE(277);
      if (lookahead == 'g') ADVANCE(13);
      if (lookahead == '{') ADVANCE(128);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(16);
      END_STATE();
    case 13:
      if (lookahead == '\n') ADVANCE(277);
      if (lookahead == 'i') ADVANCE(14);
      if (lookahead == '{') ADVANCE(128);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(16);
      END_STATE();
    case 14:
      if (lookahead == '\n') ADVANCE(277);
      if (lookahead == 'n') ADVANCE(15);
      if (lookahead == '{') ADVANCE(128);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(16);
      END_STATE();
    case 15:
      if (lookahead == '\n') ADVANCE(277);
      if (lookahead == '{') ADVANCE(268);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(16);
      END_STATE();
    case 16:
      if (lookahead == '\n') ADVANCE(277);
      if (lookahead == '{') ADVANCE(128);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(16);
      END_STATE();
    case 17:
      if (lookahead == '\n') ADVANCE(279);
      if (lookahead != 0) ADVANCE(17);
      END_STATE();
    case 18:
      if (lookahead == '\n') ADVANCE(278);
      if (lookahead != 0) ADVANCE(18);
      END_STATE();
    case 19:
      if (lookahead == '\n') ADVANCE(228);
      END_STATE();
    case 20:
      if (lookahead == '\n') ADVANCE(228);
      if (lookahead == '-') ADVANCE(52);
      END_STATE();
    case 21:
      if (lookahead == '\n') ADVANCE(185);
      if (lookahead == 'C') ADVANCE(200);
      if (lookahead == 'D') ADVANCE(218);
      if (lookahead == 'N') ADVANCE(206);
      if (lookahead == 'T') ADVANCE(217);
      if (lookahead == 'W') ADVANCE(201);
      if (lookahead == '[') ADVANCE(199);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(196);
      if (lookahead != 0) ADVANCE(226);
      END_STATE();
    case 22:
      if (lookahead == '\n') ADVANCE(186);
      if (lookahead == '|') ADVANCE(310);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(313);
      if (lookahead != 0) ADVANCE(314);
      END_STATE();
    case 23:
      if (lookahead == '\n') ADVANCE(187);
      if (lookahead == '[') ADVANCE(199);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(197);
      if (lookahead != 0) ADVANCE(226);
      END_STATE();
    case 24:
      if (lookahead == '\n') ADVANCE(188);
      if (lookahead == ' ') ADVANCE(183);
      if (('\t' <= lookahead && lookahead <= '\r')) SKIP(24);
      END_STATE();
    case 25:
      if (lookahead == '\n') SKIP(25);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(223);
      if ((0x0b <= lookahead && lookahead <= '\r')) ADVANCE(223);
      if (lookahead != 0) ADVANCE(226);
      END_STATE();
    case 26:
      if (lookahead == '\n') SKIP(26);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(224);
      if (lookahead != 0) ADVANCE(226);
      END_STATE();
    case 27:
      if (lookahead == '\n') ADVANCE(189);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(27);
      END_STATE();
    case 28:
      if (lookahead == '\n') SKIP(28);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(282);
      if (lookahead != 0 &&
          lookahead != ']') ADVANCE(283);
      END_STATE();
    case 29:
      if (lookahead == '\n') ADVANCE(452);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(29);
      END_STATE();
    case 30:
      if (lookahead == '\n') ADVANCE(190);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(198);
      if (lookahead != 0) ADVANCE(226);
      END_STATE();
    case 31:
      if (lookahead == ' ') ADVANCE(323);
      if (lookahead == '+') ADVANCE(316);
      END_STATE();
    case 32:
      if (lookahead == ' ') ADVANCE(184);
      if (('\t' <= lookahead && lookahead <= '\r')) SKIP(32);
      END_STATE();
    case 33:
      if (lookahead == '#') ADVANCE(171);
      if (lookahead == '[') ADVANCE(280);
      if (lookahead == 'f') ADVANCE(117);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(97);
      END_STATE();
    case 34:
      if (lookahead == '#') ADVANCE(47);
      if (lookahead == ':') ADVANCE(321);
      if (lookahead == '|') ADVANCE(310);
      if (lookahead == '}') ADVANCE(272);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(34);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(271);
      END_STATE();
    case 35:
      if (lookahead == '#') ADVANCE(46);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(301);
      if (lookahead != 0) ADVANCE(302);
      END_STATE();
    case 36:
      if (lookahead == '#') ADVANCE(48);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(307);
      if (lookahead != 0) ADVANCE(308);
      END_STATE();
    case 37:
      if (lookahead == '$') ADVANCE(176);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(39);
      END_STATE();
    case 38:
      if (lookahead == '$') ADVANCE(3);
      END_STATE();
    case 39:
      if (lookahead == '$') ADVANCE(3);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(39);
      END_STATE();
    case 40:
      if (lookahead == '$') ADVANCE(38);
      if (lookahead != 0) ADVANCE(40);
      END_STATE();
    case 41:
      if (lookahead == '%') ADVANCE(43);
      END_STATE();
    case 42:
      if (lookahead == '(') ADVANCE(260);
      if (lookahead == ':') ADVANCE(318);
      if (lookahead == '}') ADVANCE(126);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(42);
      if (lookahead == '-' ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(331);
      END_STATE();
    case 43:
      if (lookahead == '(') ADVANCE(44);
      END_STATE();
    case 44:
      if (lookahead == '(') ADVANCE(5);
      if (lookahead == ')') ADVANCE(6);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(44);
      END_STATE();
    case 45:
      if (lookahead == ')') ADVANCE(44);
      if (lookahead != 0) ADVANCE(45);
      END_STATE();
    case 46:
      if (lookahead == '+') ADVANCE(145);
      if (lookahead != 0) ADVANCE(302);
      END_STATE();
    case 47:
      if (lookahead == '+') ADVANCE(146);
      END_STATE();
    case 48:
      if (lookahead == '+') ADVANCE(148);
      if (lookahead != 0) ADVANCE(308);
      END_STATE();
    case 49:
      if (lookahead == '+') ADVANCE(150);
      if (lookahead != 0) ADVANCE(302);
      END_STATE();
    case 50:
      if (lookahead == '+') ADVANCE(151);
      if (lookahead != 0) ADVANCE(308);
      END_STATE();
    case 51:
      if (lookahead == '-') ADVANCE(1);
      END_STATE();
    case 52:
      if (lookahead == '-') ADVANCE(94);
      END_STATE();
    case 53:
      if (lookahead == '-') ADVANCE(8);
      END_STATE();
    case 54:
      if (lookahead == '-') ADVANCE(53);
      END_STATE();
    case 55:
      if (lookahead == '-') ADVANCE(54);
      END_STATE();
    case 56:
      if (lookahead == '-') ADVANCE(55);
      END_STATE();
    case 57:
      if (lookahead == ':') ADVANCE(59);
      END_STATE();
    case 58:
      if (lookahead == ':') ADVANCE(178);
      if (lookahead == ']') ADVANCE(9);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(58);
      END_STATE();
    case 59:
      if (lookahead == ':') ADVANCE(178);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(58);
      END_STATE();
    case 60:
      if (lookahead == ':') ADVANCE(304);
      if (lookahead == '_') ADVANCE(296);
      END_STATE();
    case 61:
      if (lookahead == ':') ADVANCE(327);
      END_STATE();
    case 62:
      if (lookahead == ':') ADVANCE(129);
      if (lookahead == '^') ADVANCE(174);
      if (lookahead == '_') ADVANCE(175);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(107);
      END_STATE();
    case 63:
      if (lookahead == ':') ADVANCE(330);
      END_STATE();
    case 64:
      if (lookahead == ':') ADVANCE(309);
      if (lookahead == '_') ADVANCE(303);
      END_STATE();
    case 65:
      if (lookahead == ':') ADVANCE(309);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(308);
      END_STATE();
    case 66:
      if (lookahead == ':') ADVANCE(332);
      END_STATE();
    case 67:
      if (lookahead == ':') ADVANCE(332);
      if (lookahead != 0) ADVANCE(334);
      END_STATE();
    case 68:
      if (lookahead == ':') ADVANCE(114);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(68);
      if (lookahead == '+' ||
          lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(300);
      END_STATE();
    case 69:
      if (lookahead == ':') ADVANCE(169);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(69);
      END_STATE();
    case 70:
      if (lookahead == ':') ADVANCE(81);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(333);
      if (lookahead != 0) ADVANCE(334);
      END_STATE();
    case 71:
      if (lookahead == '=') ADVANCE(74);
      if (lookahead == '[') ADVANCE(167);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(71);
      END_STATE();
    case 72:
      if (lookahead == '=') ADVANCE(74);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(72);
      END_STATE();
    case 73:
      if (lookahead == '>') ADVANCE(4);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(73);
      END_STATE();
    case 74:
      if (lookahead == '>') ADVANCE(130);
      END_STATE();
    case 75:
      if (lookahead == 'D') ADVANCE(180);
      if (lookahead == 'd') ADVANCE(123);
      if (lookahead != 0) ADVANCE(275);
      END_STATE();
    case 76:
      if (lookahead == 'D') ADVANCE(177);
      if (lookahead == 'd') ADVANCE(67);
      if (lookahead != 0) ADVANCE(334);
      END_STATE();
    case 77:
      if (lookahead == 'D') ADVANCE(63);
      END_STATE();
    case 78:
      if (lookahead == 'E') ADVANCE(90);
      END_STATE();
    case 79:
      if (lookahead == 'E') ADVANCE(89);
      END_STATE();
    case 80:
      if (lookahead == 'E') ADVANCE(158);
      if (lookahead == 'e') ADVANCE(84);
      if (lookahead != 0) ADVANCE(275);
      END_STATE();
    case 81:
      if (lookahead == 'E') ADVANCE(161);
      if (lookahead == 'e') ADVANCE(85);
      if (lookahead != 0) ADVANCE(334);
      END_STATE();
    case 82:
      if (lookahead == 'I') ADVANCE(78);
      END_STATE();
    case 83:
      if (lookahead == 'N') ADVANCE(77);
      END_STATE();
    case 84:
      if (lookahead == 'N') ADVANCE(139);
      if (lookahead == 'n') ADVANCE(75);
      if (lookahead != 0) ADVANCE(275);
      END_STATE();
    case 85:
      if (lookahead == 'N') ADVANCE(142);
      if (lookahead == 'n') ADVANCE(76);
      if (lookahead != 0) ADVANCE(334);
      END_STATE();
    case 86:
      if (lookahead == 'O') ADVANCE(87);
      END_STATE();
    case 87:
      if (lookahead == 'P') ADVANCE(79);
      END_STATE();
    case 88:
      if (lookahead == 'R') ADVANCE(86);
      END_STATE();
    case 89:
      if (lookahead == 'R') ADVANCE(91);
      END_STATE();
    case 90:
      if (lookahead == 'S') ADVANCE(61);
      END_STATE();
    case 91:
      if (lookahead == 'T') ADVANCE(82);
      END_STATE();
    case 92:
      if (lookahead == '[') ADVANCE(280);
      if (lookahead == 'f') ADVANCE(117);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(97);
      END_STATE();
    case 93:
      if (lookahead == '[') ADVANCE(284);
      if (lookahead == ']') ADVANCE(285);
      END_STATE();
    case 94:
      if (lookahead == '[') ADVANCE(168);
      END_STATE();
    case 95:
      if (lookahead == '\\') ADVANCE(80);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(274);
      if (lookahead != 0) ADVANCE(275);
      END_STATE();
    case 96:
      if (lookahead == ']') ADVANCE(195);
      END_STATE();
    case 97:
      if (lookahead == ']') ADVANCE(4);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(97);
      END_STATE();
    case 98:
      if (lookahead == ']') ADVANCE(20);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(98);
      END_STATE();
    case 99:
      if (lookahead == ']') ADVANCE(132);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(99);
      END_STATE();
    case 100:
      if (lookahead == ']') ADVANCE(9);
      if (lookahead != 0) ADVANCE(100);
      END_STATE();
    case 101:
      if (lookahead == '^') ADVANCE(174);
      if (lookahead == '_') ADVANCE(175);
      if (lookahead == ')' ||
          lookahead == '.') ADVANCE(292);
      if (lookahead == 'L' ||
          lookahead == 'l') ADVANCE(106);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(107);
      END_STATE();
    case 102:
      if (lookahead == '^') ADVANCE(174);
      if (lookahead == '_') ADVANCE(175);
      if (lookahead == ')' ||
          lookahead == '.') ADVANCE(292);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(102);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(107);
      END_STATE();
    case 103:
      if (lookahead == '^') ADVANCE(174);
      if (lookahead == '_') ADVANCE(175);
      if (lookahead == ')' ||
          lookahead == '.') ADVANCE(292);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(107);
      END_STATE();
    case 104:
      if (lookahead == '^') ADVANCE(174);
      if (lookahead == '_') ADVANCE(175);
      if (lookahead == 'C' ||
          lookahead == 'c') ADVANCE(105);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(107);
      END_STATE();
    case 105:
      if (lookahead == '^') ADVANCE(174);
      if (lookahead == '_') ADVANCE(175);
      if (lookahead == 'K' ||
          lookahead == 'k') ADVANCE(62);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(107);
      END_STATE();
    case 106:
      if (lookahead == '^') ADVANCE(174);
      if (lookahead == '_') ADVANCE(175);
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(104);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(107);
      END_STATE();
    case 107:
      if (lookahead == '^') ADVANCE(174);
      if (lookahead == '_') ADVANCE(175);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(107);
      END_STATE();
    case 108:
      if (lookahead == '_') ADVANCE(303);
      if (lookahead != 0) ADVANCE(302);
      END_STATE();
    case 109:
      if (lookahead == 'b') ADVANCE(113);
      if (lookahead == 'e') ADVANCE(118);
      END_STATE();
    case 110:
      if (lookahead == 'b') ADVANCE(11);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(16);
      END_STATE();
    case 111:
      if (lookahead == 'd') ADVANCE(122);
      END_STATE();
    case 112:
      if (lookahead == 'd') ADVANCE(66);
      END_STATE();
    case 113:
      if (lookahead == 'e') ADVANCE(115);
      END_STATE();
    case 114:
      if (lookahead == 'e') ADVANCE(119);
      END_STATE();
    case 115:
      if (lookahead == 'g') ADVANCE(116);
      END_STATE();
    case 116:
      if (lookahead == 'i') ADVANCE(120);
      END_STATE();
    case 117:
      if (lookahead == 'n') ADVANCE(57);
      END_STATE();
    case 118:
      if (lookahead == 'n') ADVANCE(111);
      END_STATE();
    case 119:
      if (lookahead == 'n') ADVANCE(112);
      END_STATE();
    case 120:
      if (lookahead == 'n') ADVANCE(124);
      END_STATE();
    case 121:
      if (lookahead == '{') ADVANCE(231);
      END_STATE();
    case 122:
      if (lookahead == '{') ADVANCE(276);
      END_STATE();
    case 123:
      if (lookahead == '{') ADVANCE(276);
      if (lookahead != 0) ADVANCE(275);
      END_STATE();
    case 124:
      if (lookahead == '{') ADVANCE(267);
      END_STATE();
    case 125:
      if (lookahead == '{') ADVANCE(121);
      END_STATE();
    case 126:
      if (lookahead == '}') ADVANCE(127);
      END_STATE();
    case 127:
      if (lookahead == '}') ADVANCE(264);
      END_STATE();
    case 128:
      if (lookahead == '}') ADVANCE(10);
      END_STATE();
    case 129:
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(71);
      END_STATE();
    case 130:
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(131);
      END_STATE();
    case 131:
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(131);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(69);
      END_STATE();
    case 132:
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(72);
      END_STATE();
    case 133:
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(287);
      if (('\n' <= lookahead && lookahead <= '\r')) SKIP(133);
      END_STATE();
    case 134:
      if (lookahead == ')' ||
          lookahead == '.') ADVANCE(292);
      END_STATE();
    case 135:
      if (lookahead == ')' ||
          lookahead == '.') ADVANCE(292);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(135);
      END_STATE();
    case 136:
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(292);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(136);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(135);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(134);
      END_STATE();
    case 137:
      if (lookahead == 'D' ||
          lookahead == 'd') ADVANCE(108);
      if (lookahead != 0) ADVANCE(302);
      END_STATE();
    case 138:
      if (lookahead == 'D' ||
          lookahead == 'd') ADVANCE(179);
      if (lookahead != 0) ADVANCE(302);
      END_STATE();
    case 139:
      if (lookahead == 'D' ||
          lookahead == 'd') ADVANCE(180);
      if (lookahead != 0) ADVANCE(275);
      END_STATE();
    case 140:
      if (lookahead == 'D' ||
          lookahead == 'd') ADVANCE(65);
      if (lookahead != 0) ADVANCE(308);
      END_STATE();
    case 141:
      if (lookahead == 'D' ||
          lookahead == 'd') ADVANCE(172);
      if (lookahead != 0) ADVANCE(308);
      END_STATE();
    case 142:
      if (lookahead == 'D' ||
          lookahead == 'd') ADVANCE(177);
      if (lookahead != 0) ADVANCE(334);
      END_STATE();
    case 143:
      if (lookahead == 'D' ||
          lookahead == 'd') ADVANCE(64);
      END_STATE();
    case 144:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(152);
      END_STATE();
    case 145:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(156);
      if (lookahead != 0) ADVANCE(302);
      END_STATE();
    case 146:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(155);
      END_STATE();
    case 147:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(158);
      if (lookahead != 0) ADVANCE(275);
      END_STATE();
    case 148:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(159);
      if (lookahead != 0) ADVANCE(308);
      END_STATE();
    case 149:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(161);
      if (lookahead != 0) ADVANCE(334);
      END_STATE();
    case 150:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(157);
      if (lookahead != 0) ADVANCE(302);
      END_STATE();
    case 151:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(160);
      if (lookahead != 0) ADVANCE(308);
      END_STATE();
    case 152:
      if (lookahead == 'G' ||
          lookahead == 'g') ADVANCE(153);
      END_STATE();
    case 153:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(154);
      END_STATE();
    case 154:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(60);
      END_STATE();
    case 155:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(143);
      END_STATE();
    case 156:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(137);
      if (lookahead != 0) ADVANCE(302);
      END_STATE();
    case 157:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(138);
      if (lookahead != 0) ADVANCE(302);
      END_STATE();
    case 158:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(139);
      if (lookahead != 0) ADVANCE(275);
      END_STATE();
    case 159:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(140);
      if (lookahead != 0) ADVANCE(308);
      END_STATE();
    case 160:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(141);
      if (lookahead != 0) ADVANCE(308);
      END_STATE();
    case 161:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(142);
      if (lookahead != 0) ADVANCE(334);
      END_STATE();
    case 162:
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(261);
      if (lookahead != 0 &&
          lookahead != ')' &&
          lookahead != '}') ADVANCE(262);
      END_STATE();
    case 163:
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(163);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(306);
      END_STATE();
    case 164:
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(164);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(322);
      END_STATE();
    case 165:
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(165);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(299);
      END_STATE();
    case 166:
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(166);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(259);
      END_STATE();
    case 167:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(98);
      END_STATE();
    case 168:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(99);
      END_STATE();
    case 169:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(170);
      END_STATE();
    case 170:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(19);
      END_STATE();
    case 171:
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(96);
      END_STATE();
    case 172:
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != ':') ADVANCE(308);
      END_STATE();
    case 173:
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '>') ADVANCE(73);
      END_STATE();
    case 174:
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(17);
      END_STATE();
    case 175:
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(18);
      END_STATE();
    case 176:
      if (lookahead != 0 &&
          lookahead != '$') ADVANCE(40);
      END_STATE();
    case 177:
      if (lookahead != 0 &&
          lookahead != ':') ADVANCE(334);
      END_STATE();
    case 178:
      if (lookahead != 0 &&
          lookahead != ']') ADVANCE(100);
      END_STATE();
    case 179:
      if (lookahead != 0 &&
          lookahead != '_') ADVANCE(302);
      END_STATE();
    case 180:
      if (lookahead != 0 &&
          lookahead != '{') ADVANCE(275);
      END_STATE();
    case 181:
      if (eof) ADVANCE(182);
      if (lookahead == '\n') SKIP(181);
      if (lookahead == '#') ADVANCE(31);
      if (lookahead == '$') ADVANCE(363);
      if (lookahead == '%') ADVANCE(366);
      if (lookahead == '*') ADVANCE(192);
      if (lookahead == '+') ADVANCE(292);
      if (lookahead == '-') ADVANCE(294);
      if (lookahead == ':') ADVANCE(319);
      if (lookahead == '<') ADVANCE(385);
      if (lookahead == 'C') ADVANCE(404);
      if (lookahead == 'D') ADVANCE(395);
      if (lookahead == 'S') ADVANCE(391);
      if (lookahead == '[') ADVANCE(92);
      if (lookahead == '\\') ADVANCE(110);
      if (lookahead == 'c') ADVANCE(101);
      if (lookahead == '{') ADVANCE(125);
      if (lookahead == '|') ADVANCE(311);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(286);
      if ((0x0b <= lookahead && lookahead <= '\r')) ADVANCE(362);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(102);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(426);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(103);
      if (lookahead != 0) ADVANCE(449);
      END_STATE();
    case 182:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 183:
      ACCEPT_TOKEN(anon_sym_SPACE);
      if (lookahead == '\n') ADVANCE(188);
      if (lookahead == ' ') ADVANCE(183);
      END_STATE();
    case 184:
      ACCEPT_TOKEN(anon_sym_SPACE);
      if (lookahead == ' ') ADVANCE(184);
      END_STATE();
    case 185:
      ACCEPT_TOKEN(anon_sym_LF);
      if (lookahead == '\n') ADVANCE(185);
      if (lookahead == 'C') ADVANCE(200);
      if (lookahead == 'D') ADVANCE(218);
      if (lookahead == 'N') ADVANCE(206);
      if (lookahead == 'T') ADVANCE(217);
      if (lookahead == 'W') ADVANCE(201);
      if (lookahead == '[') ADVANCE(199);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(196);
      END_STATE();
    case 186:
      ACCEPT_TOKEN(anon_sym_LF);
      if (lookahead == '\n') ADVANCE(186);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(313);
      END_STATE();
    case 187:
      ACCEPT_TOKEN(anon_sym_LF);
      if (lookahead == '\n') ADVANCE(187);
      if (lookahead == '[') ADVANCE(199);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(197);
      END_STATE();
    case 188:
      ACCEPT_TOKEN(anon_sym_LF);
      if (lookahead == '\n') ADVANCE(188);
      if (lookahead == ' ') ADVANCE(183);
      END_STATE();
    case 189:
      ACCEPT_TOKEN(anon_sym_LF);
      if (lookahead == '\n') ADVANCE(189);
      END_STATE();
    case 190:
      ACCEPT_TOKEN(anon_sym_LF);
      if (lookahead == '\n') ADVANCE(190);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(198);
      END_STATE();
    case 191:
      ACCEPT_TOKEN(anon_sym_LF);
      if (lookahead == '\n') ADVANCE(191);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(288);
      END_STATE();
    case 192:
      ACCEPT_TOKEN(sym_stars);
      if (lookahead == '*') ADVANCE(192);
      END_STATE();
    case 193:
      ACCEPT_TOKEN(sym_stars);
      if (lookahead == '*') ADVANCE(193);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(449);
      END_STATE();
    case 194:
      ACCEPT_TOKEN(sym_keyword);
      END_STATE();
    case 195:
      ACCEPT_TOKEN(sym_priority);
      END_STATE();
    case 196:
      ACCEPT_TOKEN(aux_sym_title_token1);
      if (lookahead == '\n') ADVANCE(185);
      if (lookahead == 'C') ADVANCE(200);
      if (lookahead == 'D') ADVANCE(218);
      if (lookahead == 'N') ADVANCE(206);
      if (lookahead == 'T') ADVANCE(217);
      if (lookahead == 'W') ADVANCE(201);
      if (lookahead == '[') ADVANCE(199);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(196);
      if (lookahead != 0) ADVANCE(226);
      END_STATE();
    case 197:
      ACCEPT_TOKEN(aux_sym_title_token1);
      if (lookahead == '\n') ADVANCE(187);
      if (lookahead == '[') ADVANCE(199);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(197);
      if (lookahead != 0) ADVANCE(226);
      END_STATE();
    case 198:
      ACCEPT_TOKEN(aux_sym_title_token1);
      if (lookahead == '\n') ADVANCE(190);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(198);
      if (lookahead != 0) ADVANCE(226);
      END_STATE();
    case 199:
      ACCEPT_TOKEN(aux_sym_title_token1);
      if (lookahead == '#') ADVANCE(225);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(226);
      END_STATE();
    case 200:
      ACCEPT_TOKEN(aux_sym_title_token1);
      if (lookahead == 'A') ADVANCE(213);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(226);
      END_STATE();
    case 201:
      ACCEPT_TOKEN(aux_sym_title_token1);
      if (lookahead == 'A') ADVANCE(210);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(226);
      END_STATE();
    case 202:
      ACCEPT_TOKEN(aux_sym_title_token1);
      if (lookahead == 'C') ADVANCE(207);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(226);
      END_STATE();
    case 203:
      ACCEPT_TOKEN(aux_sym_title_token1);
      if (lookahead == 'D') ADVANCE(194);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(226);
      END_STATE();
    case 204:
      ACCEPT_TOKEN(aux_sym_title_token1);
      if (lookahead == 'D') ADVANCE(216);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(226);
      END_STATE();
    case 205:
      ACCEPT_TOKEN(aux_sym_title_token1);
      if (lookahead == 'E') ADVANCE(194);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(226);
      END_STATE();
    case 206:
      ACCEPT_TOKEN(aux_sym_title_token1);
      if (lookahead == 'E') ADVANCE(221);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(226);
      END_STATE();
    case 207:
      ACCEPT_TOKEN(aux_sym_title_token1);
      if (lookahead == 'E') ADVANCE(212);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(226);
      END_STATE();
    case 208:
      ACCEPT_TOKEN(aux_sym_title_token1);
      if (lookahead == 'E') ADVANCE(203);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(226);
      END_STATE();
    case 209:
      ACCEPT_TOKEN(aux_sym_title_token1);
      if (lookahead == 'G') ADVANCE(194);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(226);
      END_STATE();
    case 210:
      ACCEPT_TOKEN(aux_sym_title_token1);
      if (lookahead == 'I') ADVANCE(220);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(226);
      END_STATE();
    case 211:
      ACCEPT_TOKEN(aux_sym_title_token1);
      if (lookahead == 'I') ADVANCE(214);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(226);
      END_STATE();
    case 212:
      ACCEPT_TOKEN(aux_sym_title_token1);
      if (lookahead == 'L') ADVANCE(208);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(226);
      END_STATE();
    case 213:
      ACCEPT_TOKEN(aux_sym_title_token1);
      if (lookahead == 'N') ADVANCE(202);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(226);
      END_STATE();
    case 214:
      ACCEPT_TOKEN(aux_sym_title_token1);
      if (lookahead == 'N') ADVANCE(209);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(226);
      END_STATE();
    case 215:
      ACCEPT_TOKEN(aux_sym_title_token1);
      if (lookahead == 'N') ADVANCE(205);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(226);
      END_STATE();
    case 216:
      ACCEPT_TOKEN(aux_sym_title_token1);
      if (lookahead == 'O') ADVANCE(194);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(226);
      END_STATE();
    case 217:
      ACCEPT_TOKEN(aux_sym_title_token1);
      if (lookahead == 'O') ADVANCE(204);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(226);
      END_STATE();
    case 218:
      ACCEPT_TOKEN(aux_sym_title_token1);
      if (lookahead == 'O') ADVANCE(215);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(226);
      END_STATE();
    case 219:
      ACCEPT_TOKEN(aux_sym_title_token1);
      if (lookahead == 'T') ADVANCE(194);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(226);
      END_STATE();
    case 220:
      ACCEPT_TOKEN(aux_sym_title_token1);
      if (lookahead == 'T') ADVANCE(211);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(226);
      END_STATE();
    case 221:
      ACCEPT_TOKEN(aux_sym_title_token1);
      if (lookahead == 'X') ADVANCE(219);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(226);
      END_STATE();
    case 222:
      ACCEPT_TOKEN(aux_sym_title_token1);
      if (lookahead == ']') ADVANCE(195);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(226);
      END_STATE();
    case 223:
      ACCEPT_TOKEN(aux_sym_title_token1);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(223);
      if ((0x0b <= lookahead && lookahead <= '\r')) ADVANCE(223);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead)) ADVANCE(226);
      END_STATE();
    case 224:
      ACCEPT_TOKEN(aux_sym_title_token1);
      if (lookahead == '\t' ||
          (0x0b <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(224);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead)) ADVANCE(226);
      END_STATE();
    case 225:
      ACCEPT_TOKEN(aux_sym_title_token1);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(222);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(226);
      END_STATE();
    case 226:
      ACCEPT_TOKEN(aux_sym_title_token1);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(226);
      END_STATE();
    case 227:
      ACCEPT_TOKEN(sym_planning_line);
      END_STATE();
    case 228:
      ACCEPT_TOKEN(sym_clock);
      END_STATE();
    case 229:
      ACCEPT_TOKEN(sym_diary_sexp);
      END_STATE();
    case 230:
      ACCEPT_TOKEN(sym_timestamp);
      END_STATE();
    case 231:
      ACCEPT_TOKEN(anon_sym_LBRACE_LBRACE_LBRACE);
      END_STATE();
    case 232:
      ACCEPT_TOKEN(anon_sym_LBRACE_LBRACE_LBRACE);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(449);
      END_STATE();
    case 233:
      ACCEPT_TOKEN(aux_sym_macro_token1);
      if (lookahead == '*') ADVANCE(270);
      if (lookahead == 'A') ADVANCE(246);
      if (lookahead == '_') ADVANCE(257);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(259);
      if (('B' <= lookahead && lookahead <= 'Z')) ADVANCE(255);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(256);
      END_STATE();
    case 234:
      ACCEPT_TOKEN(aux_sym_macro_token1);
      if (lookahead == '*') ADVANCE(270);
      if (lookahead == 'A') ADVANCE(243);
      if (lookahead == '_') ADVANCE(257);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(259);
      if (('B' <= lookahead && lookahead <= 'Z')) ADVANCE(255);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(256);
      END_STATE();
    case 235:
      ACCEPT_TOKEN(aux_sym_macro_token1);
      if (lookahead == '*') ADVANCE(270);
      if (lookahead == 'C') ADVANCE(240);
      if (lookahead == '_') ADVANCE(257);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(259);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(255);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(256);
      END_STATE();
    case 236:
      ACCEPT_TOKEN(aux_sym_macro_token1);
      if (lookahead == '*') ADVANCE(270);
      if (lookahead == 'D') ADVANCE(194);
      if (lookahead == '_') ADVANCE(257);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(259);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(255);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(256);
      END_STATE();
    case 237:
      ACCEPT_TOKEN(aux_sym_macro_token1);
      if (lookahead == '*') ADVANCE(270);
      if (lookahead == 'D') ADVANCE(250);
      if (lookahead == '_') ADVANCE(257);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(259);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(255);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(256);
      END_STATE();
    case 238:
      ACCEPT_TOKEN(aux_sym_macro_token1);
      if (lookahead == '*') ADVANCE(270);
      if (lookahead == 'E') ADVANCE(254);
      if (lookahead == '_') ADVANCE(257);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(259);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(255);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(256);
      END_STATE();
    case 239:
      ACCEPT_TOKEN(aux_sym_macro_token1);
      if (lookahead == '*') ADVANCE(270);
      if (lookahead == 'E') ADVANCE(194);
      if (lookahead == '_') ADVANCE(257);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(259);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(255);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(256);
      END_STATE();
    case 240:
      ACCEPT_TOKEN(aux_sym_macro_token1);
      if (lookahead == '*') ADVANCE(270);
      if (lookahead == 'E') ADVANCE(245);
      if (lookahead == '_') ADVANCE(257);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(259);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(255);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(256);
      END_STATE();
    case 241:
      ACCEPT_TOKEN(aux_sym_macro_token1);
      if (lookahead == '*') ADVANCE(270);
      if (lookahead == 'E') ADVANCE(236);
      if (lookahead == '_') ADVANCE(257);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(259);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(255);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(256);
      END_STATE();
    case 242:
      ACCEPT_TOKEN(aux_sym_macro_token1);
      if (lookahead == '*') ADVANCE(270);
      if (lookahead == 'G') ADVANCE(194);
      if (lookahead == '_') ADVANCE(257);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(259);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(255);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(256);
      END_STATE();
    case 243:
      ACCEPT_TOKEN(aux_sym_macro_token1);
      if (lookahead == '*') ADVANCE(270);
      if (lookahead == 'I') ADVANCE(253);
      if (lookahead == '_') ADVANCE(257);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(259);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(255);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(256);
      END_STATE();
    case 244:
      ACCEPT_TOKEN(aux_sym_macro_token1);
      if (lookahead == '*') ADVANCE(270);
      if (lookahead == 'I') ADVANCE(247);
      if (lookahead == '_') ADVANCE(257);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(259);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(255);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(256);
      END_STATE();
    case 245:
      ACCEPT_TOKEN(aux_sym_macro_token1);
      if (lookahead == '*') ADVANCE(270);
      if (lookahead == 'L') ADVANCE(241);
      if (lookahead == '_') ADVANCE(257);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(259);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(255);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(256);
      END_STATE();
    case 246:
      ACCEPT_TOKEN(aux_sym_macro_token1);
      if (lookahead == '*') ADVANCE(270);
      if (lookahead == 'N') ADVANCE(235);
      if (lookahead == '_') ADVANCE(257);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(259);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(255);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(256);
      END_STATE();
    case 247:
      ACCEPT_TOKEN(aux_sym_macro_token1);
      if (lookahead == '*') ADVANCE(270);
      if (lookahead == 'N') ADVANCE(242);
      if (lookahead == '_') ADVANCE(257);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(259);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(255);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(256);
      END_STATE();
    case 248:
      ACCEPT_TOKEN(aux_sym_macro_token1);
      if (lookahead == '*') ADVANCE(270);
      if (lookahead == 'N') ADVANCE(239);
      if (lookahead == '_') ADVANCE(257);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(259);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(255);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(256);
      END_STATE();
    case 249:
      ACCEPT_TOKEN(aux_sym_macro_token1);
      if (lookahead == '*') ADVANCE(270);
      if (lookahead == 'O') ADVANCE(237);
      if (lookahead == '_') ADVANCE(257);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(259);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(255);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(256);
      END_STATE();
    case 250:
      ACCEPT_TOKEN(aux_sym_macro_token1);
      if (lookahead == '*') ADVANCE(270);
      if (lookahead == 'O') ADVANCE(194);
      if (lookahead == '_') ADVANCE(257);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(259);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(255);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(256);
      END_STATE();
    case 251:
      ACCEPT_TOKEN(aux_sym_macro_token1);
      if (lookahead == '*') ADVANCE(270);
      if (lookahead == 'O') ADVANCE(248);
      if (lookahead == '_') ADVANCE(257);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(259);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(255);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(256);
      END_STATE();
    case 252:
      ACCEPT_TOKEN(aux_sym_macro_token1);
      if (lookahead == '*') ADVANCE(270);
      if (lookahead == 'T') ADVANCE(194);
      if (lookahead == '_') ADVANCE(257);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(259);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(255);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(256);
      END_STATE();
    case 253:
      ACCEPT_TOKEN(aux_sym_macro_token1);
      if (lookahead == '*') ADVANCE(270);
      if (lookahead == 'T') ADVANCE(244);
      if (lookahead == '_') ADVANCE(257);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(259);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(255);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(256);
      END_STATE();
    case 254:
      ACCEPT_TOKEN(aux_sym_macro_token1);
      if (lookahead == '*') ADVANCE(270);
      if (lookahead == 'X') ADVANCE(252);
      if (lookahead == '_') ADVANCE(257);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(259);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(255);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(256);
      END_STATE();
    case 255:
      ACCEPT_TOKEN(aux_sym_macro_token1);
      if (lookahead == '*') ADVANCE(270);
      if (lookahead == '_') ADVANCE(257);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(259);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(255);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(256);
      END_STATE();
    case 256:
      ACCEPT_TOKEN(aux_sym_macro_token1);
      if (lookahead == '*') ADVANCE(270);
      if (lookahead == '_') ADVANCE(258);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(259);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(256);
      END_STATE();
    case 257:
      ACCEPT_TOKEN(aux_sym_macro_token1);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(259);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(258);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(257);
      END_STATE();
    case 258:
      ACCEPT_TOKEN(aux_sym_macro_token1);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(259);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(258);
      END_STATE();
    case 259:
      ACCEPT_TOKEN(aux_sym_macro_token1);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(259);
      END_STATE();
    case 260:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      END_STATE();
    case 261:
      ACCEPT_TOKEN(aux_sym_macro_token2);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(261);
      if (lookahead != 0 &&
          lookahead != ')' &&
          lookahead != '}') ADVANCE(262);
      END_STATE();
    case 262:
      ACCEPT_TOKEN(aux_sym_macro_token2);
      if (lookahead != 0 &&
          lookahead != ')' &&
          lookahead != '}') ADVANCE(262);
      END_STATE();
    case 263:
      ACCEPT_TOKEN(anon_sym_RPAREN);
      END_STATE();
    case 264:
      ACCEPT_TOKEN(anon_sym_RBRACE_RBRACE_RBRACE);
      END_STATE();
    case 265:
      ACCEPT_TOKEN(sym_footnote_reference);
      END_STATE();
    case 266:
      ACCEPT_TOKEN(sym_latex_fragment);
      END_STATE();
    case 267:
      ACCEPT_TOKEN(anon_sym_BSLASHbegin_LBRACE);
      END_STATE();
    case 268:
      ACCEPT_TOKEN(anon_sym_BSLASHbegin_LBRACE);
      if (lookahead == '}') ADVANCE(10);
      END_STATE();
    case 269:
      ACCEPT_TOKEN(anon_sym_BSLASHbegin_LBRACE);
      if (lookahead == '}') ADVANCE(355);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(449);
      END_STATE();
    case 270:
      ACCEPT_TOKEN(aux_sym_latex_env_begin_token1);
      END_STATE();
    case 271:
      ACCEPT_TOKEN(aux_sym_latex_env_begin_token1);
      if (lookahead == '*') ADVANCE(270);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(271);
      END_STATE();
    case 272:
      ACCEPT_TOKEN(anon_sym_RBRACE);
      END_STATE();
    case 273:
      ACCEPT_TOKEN(anon_sym_RBRACE);
      if (lookahead == '}') ADVANCE(127);
      END_STATE();
    case 274:
      ACCEPT_TOKEN(sym_latex_env_content);
      if (lookahead == '\\') ADVANCE(80);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(274);
      if (lookahead != 0) ADVANCE(275);
      END_STATE();
    case 275:
      ACCEPT_TOKEN(sym_latex_env_content);
      if (lookahead == '\\') ADVANCE(147);
      if (lookahead != 0) ADVANCE(275);
      END_STATE();
    case 276:
      ACCEPT_TOKEN(anon_sym_BSLASHend_LBRACE);
      END_STATE();
    case 277:
      ACCEPT_TOKEN(sym_entity);
      END_STATE();
    case 278:
      ACCEPT_TOKEN(sym_subscript);
      END_STATE();
    case 279:
      ACCEPT_TOKEN(sym_superscript);
      END_STATE();
    case 280:
      ACCEPT_TOKEN(anon_sym_LBRACK_LBRACK);
      END_STATE();
    case 281:
      ACCEPT_TOKEN(anon_sym_LBRACK_LBRACK);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(449);
      END_STATE();
    case 282:
      ACCEPT_TOKEN(aux_sym_link_token1);
      if (lookahead == '\t' ||
          (0x0b <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(282);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ']') ADVANCE(283);
      END_STATE();
    case 283:
      ACCEPT_TOKEN(aux_sym_link_token1);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != ']') ADVANCE(283);
      END_STATE();
    case 284:
      ACCEPT_TOKEN(anon_sym_RBRACK_LBRACK);
      END_STATE();
    case 285:
      ACCEPT_TOKEN(anon_sym_RBRACK_RBRACK);
      END_STATE();
    case 286:
      ACCEPT_TOKEN(aux_sym_list_item_token1);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(286);
      if ((0x0b <= lookahead && lookahead <= '\r')) ADVANCE(362);
      END_STATE();
    case 287:
      ACCEPT_TOKEN(aux_sym_list_item_token1);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(287);
      END_STATE();
    case 288:
      ACCEPT_TOKEN(aux_sym_list_item_token2);
      if (lookahead == '\n') ADVANCE(191);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(288);
      if (lookahead != 0) ADVANCE(291);
      END_STATE();
    case 289:
      ACCEPT_TOKEN(aux_sym_list_item_token2);
      if (lookahead == '\t' ||
          (0x0b <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(289);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(290);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead)) ADVANCE(291);
      END_STATE();
    case 290:
      ACCEPT_TOKEN(aux_sym_list_item_token2);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(290);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(291);
      END_STATE();
    case 291:
      ACCEPT_TOKEN(aux_sym_list_item_token2);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(291);
      END_STATE();
    case 292:
      ACCEPT_TOKEN(sym_bullet);
      END_STATE();
    case 293:
      ACCEPT_TOKEN(sym_bullet);
      if (lookahead == '-') ADVANCE(373);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(449);
      END_STATE();
    case 294:
      ACCEPT_TOKEN(sym_bullet);
      if (lookahead == '-') ADVANCE(55);
      END_STATE();
    case 295:
      ACCEPT_TOKEN(sym_bullet);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(449);
      END_STATE();
    case 296:
      ACCEPT_TOKEN(aux_sym_block_begin_token1);
      END_STATE();
    case 297:
      ACCEPT_TOKEN(aux_sym_block_begin_token1);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(449);
      END_STATE();
    case 298:
      ACCEPT_TOKEN(sym_block_type);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(299);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(298);
      END_STATE();
    case 299:
      ACCEPT_TOKEN(sym_block_type);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(299);
      END_STATE();
    case 300:
      ACCEPT_TOKEN(sym_language);
      if (lookahead == '+' ||
          lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(300);
      END_STATE();
    case 301:
      ACCEPT_TOKEN(sym_block_content);
      if (lookahead == '#') ADVANCE(46);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(301);
      if (lookahead != 0) ADVANCE(302);
      END_STATE();
    case 302:
      ACCEPT_TOKEN(sym_block_content);
      if (lookahead == '#') ADVANCE(49);
      if (lookahead != 0) ADVANCE(302);
      END_STATE();
    case 303:
      ACCEPT_TOKEN(aux_sym_block_end_token1);
      END_STATE();
    case 304:
      ACCEPT_TOKEN(aux_sym_dynamic_block_begin_token1);
      END_STATE();
    case 305:
      ACCEPT_TOKEN(aux_sym_dynamic_block_begin_token1);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(449);
      END_STATE();
    case 306:
      ACCEPT_TOKEN(aux_sym_dynamic_block_begin_token2);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(306);
      END_STATE();
    case 307:
      ACCEPT_TOKEN(sym_dynamic_block_content);
      if (lookahead == '#') ADVANCE(48);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(307);
      if (lookahead != 0) ADVANCE(308);
      END_STATE();
    case 308:
      ACCEPT_TOKEN(sym_dynamic_block_content);
      if (lookahead == '#') ADVANCE(50);
      if (lookahead != 0) ADVANCE(308);
      END_STATE();
    case 309:
      ACCEPT_TOKEN(aux_sym_dynamic_block_end_token1);
      END_STATE();
    case 310:
      ACCEPT_TOKEN(anon_sym_PIPE);
      END_STATE();
    case 311:
      ACCEPT_TOKEN(anon_sym_PIPE);
      if (lookahead == '-') ADVANCE(1);
      END_STATE();
    case 312:
      ACCEPT_TOKEN(anon_sym_PIPE);
      if (lookahead == '-') ADVANCE(338);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(449);
      END_STATE();
    case 313:
      ACCEPT_TOKEN(sym_table_cell);
      if (lookahead == '\n') ADVANCE(186);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(313);
      if (lookahead != 0 &&
          lookahead != '|') ADVANCE(314);
      END_STATE();
    case 314:
      ACCEPT_TOKEN(sym_table_cell);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '|') ADVANCE(314);
      END_STATE();
    case 315:
      ACCEPT_TOKEN(sym_table_separator);
      END_STATE();
    case 316:
      ACCEPT_TOKEN(aux_sym_directive_token1);
      if (lookahead == 'B' ||
          lookahead == 'b') ADVANCE(144);
      END_STATE();
    case 317:
      ACCEPT_TOKEN(aux_sym_directive_token1);
      if (lookahead == 'B' ||
          lookahead == 'b') ADVANCE(441);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(449);
      END_STATE();
    case 318:
      ACCEPT_TOKEN(anon_sym_COLON);
      END_STATE();
    case 319:
      ACCEPT_TOKEN(anon_sym_COLON);
      if (lookahead == ' ') ADVANCE(325);
      if (lookahead == 'P') ADVANCE(88);
      END_STATE();
    case 320:
      ACCEPT_TOKEN(anon_sym_COLON);
      if (lookahead == ' ') ADVANCE(326);
      if (lookahead == 'P') ADVANCE(411);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(449);
      END_STATE();
    case 321:
      ACCEPT_TOKEN(anon_sym_COLON);
      if (lookahead == 'E') ADVANCE(83);
      END_STATE();
    case 322:
      ACCEPT_TOKEN(sym_name);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(322);
      END_STATE();
    case 323:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      END_STATE();
    case 324:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(449);
      END_STATE();
    case 325:
      ACCEPT_TOKEN(aux_sym_fixed_width_token1);
      END_STATE();
    case 326:
      ACCEPT_TOKEN(aux_sym_fixed_width_token1);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(449);
      END_STATE();
    case 327:
      ACCEPT_TOKEN(anon_sym_COLONPROPERTIES_COLON);
      END_STATE();
    case 328:
      ACCEPT_TOKEN(anon_sym_COLONPROPERTIES_COLON);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(449);
      END_STATE();
    case 329:
      ACCEPT_TOKEN(aux_sym_property_drawer_token1);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(329);
      END_STATE();
    case 330:
      ACCEPT_TOKEN(anon_sym_COLONEND_COLON);
      END_STATE();
    case 331:
      ACCEPT_TOKEN(aux_sym_key_token1);
      if (lookahead == '-' ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(331);
      END_STATE();
    case 332:
      ACCEPT_TOKEN(anon_sym_COLONend_COLON);
      END_STATE();
    case 333:
      ACCEPT_TOKEN(sym_drawer_content);
      if (lookahead == ':') ADVANCE(81);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(333);
      if (lookahead != 0) ADVANCE(334);
      END_STATE();
    case 334:
      ACCEPT_TOKEN(sym_drawer_content);
      if (lookahead == ':') ADVANCE(149);
      if (lookahead != 0) ADVANCE(334);
      END_STATE();
    case 335:
      ACCEPT_TOKEN(sym_horizontal_rule);
      END_STATE();
    case 336:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '\n') ADVANCE(40);
      if (lookahead == '$') ADVANCE(449);
      if (lookahead != 0) ADVANCE(337);
      END_STATE();
    case 337:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '\n') ADVANCE(40);
      if (lookahead == '$') ADVANCE(364);
      if (lookahead != 0) ADVANCE(337);
      END_STATE();
    case 338:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '\n') ADVANCE(315);
      if (lookahead == '+') ADVANCE(369);
      if (lookahead == '-') ADVANCE(338);
      if (lookahead == '|') ADVANCE(339);
      if (lookahead != 0) ADVANCE(449);
      END_STATE();
    case 339:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '\n') ADVANCE(315);
      if (lookahead == '-') ADVANCE(338);
      if (lookahead != 0) ADVANCE(449);
      END_STATE();
    case 340:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '\n') ADVANCE(266);
      if (lookahead != 0) ADVANCE(449);
      END_STATE();
    case 341:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '\n') ADVANCE(230);
      if (lookahead != 0) ADVANCE(449);
      END_STATE();
    case 342:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '\n') ADVANCE(45);
      if (lookahead == '(') ADVANCE(342);
      if (lookahead == ')') ADVANCE(343);
      if (lookahead != 0) ADVANCE(342);
      END_STATE();
    case 343:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '\n') ADVANCE(229);
      if (lookahead == '(') ADVANCE(342);
      if (lookahead == ')') ADVANCE(344);
      if (lookahead != 0) ADVANCE(368);
      END_STATE();
    case 344:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '\n') ADVANCE(229);
      if (lookahead != 0) ADVANCE(449);
      END_STATE();
    case 345:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '\n') ADVANCE(335);
      if (lookahead == '-') ADVANCE(345);
      if (lookahead != 0) ADVANCE(449);
      END_STATE();
    case 346:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '\n') ADVANCE(100);
      if (lookahead == ']') ADVANCE(449);
      if (lookahead != 0) ADVANCE(347);
      END_STATE();
    case 347:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '\n') ADVANCE(100);
      if (lookahead == ']') ADVANCE(348);
      if (lookahead != 0) ADVANCE(347);
      END_STATE();
    case 348:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '\n') ADVANCE(265);
      if (lookahead != 0) ADVANCE(449);
      END_STATE();
    case 349:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '\n') ADVANCE(277);
      if (lookahead == 'e') ADVANCE(350);
      if (lookahead == '{') ADVANCE(435);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(353);
      if (lookahead != 0) ADVANCE(449);
      END_STATE();
    case 350:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '\n') ADVANCE(277);
      if (lookahead == 'g') ADVANCE(351);
      if (lookahead == '{') ADVANCE(435);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(353);
      if (lookahead != 0) ADVANCE(449);
      END_STATE();
    case 351:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '\n') ADVANCE(277);
      if (lookahead == 'i') ADVANCE(352);
      if (lookahead == '{') ADVANCE(435);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(353);
      if (lookahead != 0) ADVANCE(449);
      END_STATE();
    case 352:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '\n') ADVANCE(277);
      if (lookahead == 'n') ADVANCE(354);
      if (lookahead == '{') ADVANCE(435);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(353);
      if (lookahead != 0) ADVANCE(449);
      END_STATE();
    case 353:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '\n') ADVANCE(277);
      if (lookahead == '{') ADVANCE(435);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(353);
      if (lookahead != 0) ADVANCE(449);
      END_STATE();
    case 354:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '\n') ADVANCE(277);
      if (lookahead == '{') ADVANCE(269);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(353);
      if (lookahead != 0) ADVANCE(449);
      END_STATE();
    case 355:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '\n') ADVANCE(277);
      if (lookahead != 0) ADVANCE(449);
      END_STATE();
    case 356:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '\n') ADVANCE(279);
      if (lookahead != 0) ADVANCE(356);
      END_STATE();
    case 357:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '\n') ADVANCE(278);
      if (lookahead != 0) ADVANCE(357);
      END_STATE();
    case 358:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '\n') ADVANCE(228);
      if (lookahead == '-') ADVANCE(370);
      if (lookahead != 0) ADVANCE(449);
      END_STATE();
    case 359:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '\n') ADVANCE(228);
      if (lookahead != 0) ADVANCE(449);
      END_STATE();
    case 360:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '\n') ADVANCE(227);
      if (lookahead != 0) ADVANCE(449);
      END_STATE();
    case 361:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == ' ') ADVANCE(324);
      if (lookahead == '+') ADVANCE(317);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(449);
      END_STATE();
    case 362:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      ADVANCE_MAP(
        '#', 361,
        '$', 363,
        '%', 366,
        '*', 193,
        '+', 295,
        '-', 293,
        ':', 320,
        '<', 385,
        'C', 404,
        'D', 395,
        'S', 391,
        '[', 417,
        '\\', 431,
        'c', 424,
        '{', 434,
        '|', 312,
        '\t', 286,
        ' ', 286,
      );
      if ((0x0b <= lookahead && lookahead <= '\r')) ADVANCE(362);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(425);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(426);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(426);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead)) ADVANCE(449);
      END_STATE();
    case 363:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '$') ADVANCE(336);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(365);
      END_STATE();
    case 364:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '$') ADVANCE(340);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(449);
      END_STATE();
    case 365:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '$') ADVANCE(340);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(365);
      END_STATE();
    case 366:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '%') ADVANCE(367);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(449);
      END_STATE();
    case 367:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '(') ADVANCE(368);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(449);
      END_STATE();
    case 368:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '(') ADVANCE(342);
      if (lookahead == ')') ADVANCE(344);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(368);
      END_STATE();
    case 369:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '-') ADVANCE(338);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(449);
      END_STATE();
    case 370:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '-') ADVANCE(418);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(449);
      END_STATE();
    case 371:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '-') ADVANCE(345);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(449);
      END_STATE();
    case 372:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '-') ADVANCE(371);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(449);
      END_STATE();
    case 373:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '-') ADVANCE(372);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(449);
      END_STATE();
    case 374:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == ':') ADVANCE(377);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(449);
      END_STATE();
    case 375:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == ':') ADVANCE(436);
      if (lookahead == '^') ADVANCE(450);
      if (lookahead == '_') ADVANCE(451);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(430);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(449);
      END_STATE();
    case 376:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == ':') ADVANCE(346);
      if (lookahead == ']') ADVANCE(348);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(376);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(449);
      END_STATE();
    case 377:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == ':') ADVANCE(346);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(376);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(449);
      END_STATE();
    case 378:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == ':') ADVANCE(305);
      if (lookahead == '_') ADVANCE(297);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(449);
      END_STATE();
    case 379:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == ':') ADVANCE(328);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(449);
      END_STATE();
    case 380:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == ':') ADVANCE(437);
      if (lookahead == '^') ADVANCE(450);
      if (lookahead == '_') ADVANCE(451);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(430);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(449);
      END_STATE();
    case 381:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == ':') ADVANCE(446);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(381);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(449);
      END_STATE();
    case 382:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '<') ADVANCE(386);
      if (lookahead == '[') ADVANCE(419);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(382);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n') ADVANCE(449);
      END_STATE();
    case 383:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '=') ADVANCE(388);
      if (lookahead == '[') ADVANCE(445);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(383);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n') ADVANCE(449);
      END_STATE();
    case 384:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '=') ADVANCE(388);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(384);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n') ADVANCE(449);
      END_STATE();
    case 385:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '>') ADVANCE(449);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(387);
      END_STATE();
    case 386:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '>') ADVANCE(449);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(389);
      END_STATE();
    case 387:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '>') ADVANCE(341);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(387);
      END_STATE();
    case 388:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '>') ADVANCE(439);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(449);
      END_STATE();
    case 389:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '>') ADVANCE(360);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(389);
      END_STATE();
    case 390:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == 'A') ADVANCE(392);
      if (lookahead == '^') ADVANCE(450);
      if (lookahead == '_') ADVANCE(451);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('B' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(430);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(449);
      END_STATE();
    case 391:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == 'C') ADVANCE(401);
      if (lookahead == '^') ADVANCE(450);
      if (lookahead == '_') ADVANCE(451);
      if (lookahead == ')' ||
          lookahead == '.') ADVANCE(295);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(430);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(449);
      END_STATE();
    case 392:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == 'D') ADVANCE(405);
      if (lookahead == '^') ADVANCE(450);
      if (lookahead == '_') ADVANCE(451);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(430);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(449);
      END_STATE();
    case 393:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == 'D') ADVANCE(416);
      if (lookahead == '^') ADVANCE(450);
      if (lookahead == '_') ADVANCE(451);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(430);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(449);
      END_STATE();
    case 394:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == 'D') ADVANCE(380);
      if (lookahead == '^') ADVANCE(450);
      if (lookahead == '_') ADVANCE(451);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(430);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(449);
      END_STATE();
    case 395:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == 'E') ADVANCE(390);
      if (lookahead == '^') ADVANCE(450);
      if (lookahead == '_') ADVANCE(451);
      if (lookahead == ')' ||
          lookahead == '.') ADVANCE(295);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(430);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(449);
      END_STATE();
    case 396:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == 'E') ADVANCE(413);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(449);
      END_STATE();
    case 397:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == 'E') ADVANCE(393);
      if (lookahead == '^') ADVANCE(450);
      if (lookahead == '_') ADVANCE(451);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(430);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(449);
      END_STATE();
    case 398:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == 'E') ADVANCE(412);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(449);
      END_STATE();
    case 399:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == 'E') ADVANCE(394);
      if (lookahead == '^') ADVANCE(450);
      if (lookahead == '_') ADVANCE(451);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(430);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(449);
      END_STATE();
    case 400:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == 'E') ADVANCE(380);
      if (lookahead == '^') ADVANCE(450);
      if (lookahead == '_') ADVANCE(451);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(430);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(449);
      END_STATE();
    case 401:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == 'H') ADVANCE(397);
      if (lookahead == '^') ADVANCE(450);
      if (lookahead == '_') ADVANCE(451);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(430);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(449);
      END_STATE();
    case 402:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == 'I') ADVANCE(407);
      if (lookahead == '^') ADVANCE(450);
      if (lookahead == '_') ADVANCE(451);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(430);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(449);
      END_STATE();
    case 403:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == 'I') ADVANCE(396);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(449);
      END_STATE();
    case 404:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == 'L') ADVANCE(408);
      if (lookahead == '^') ADVANCE(450);
      if (lookahead == '_') ADVANCE(451);
      if (lookahead == 'l') ADVANCE(429);
      if (lookahead == ')' ||
          lookahead == '.') ADVANCE(295);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(430);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(449);
      END_STATE();
    case 405:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == 'L') ADVANCE(402);
      if (lookahead == '^') ADVANCE(450);
      if (lookahead == '_') ADVANCE(451);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(430);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(449);
      END_STATE();
    case 406:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == 'L') ADVANCE(399);
      if (lookahead == '^') ADVANCE(450);
      if (lookahead == '_') ADVANCE(451);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(430);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(449);
      END_STATE();
    case 407:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == 'N') ADVANCE(400);
      if (lookahead == '^') ADVANCE(450);
      if (lookahead == '_') ADVANCE(451);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(430);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(449);
      END_STATE();
    case 408:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == 'O') ADVANCE(414);
      if (lookahead == '^') ADVANCE(450);
      if (lookahead == '_') ADVANCE(451);
      if (lookahead == 'o') ADVANCE(427);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(430);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(449);
      END_STATE();
    case 409:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == 'O') ADVANCE(410);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(449);
      END_STATE();
    case 410:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == 'P') ADVANCE(398);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(449);
      END_STATE();
    case 411:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == 'R') ADVANCE(409);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(449);
      END_STATE();
    case 412:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == 'R') ADVANCE(415);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(449);
      END_STATE();
    case 413:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == 'S') ADVANCE(379);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(449);
      END_STATE();
    case 414:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == 'S') ADVANCE(399);
      if (lookahead == '^') ADVANCE(450);
      if (lookahead == '_') ADVANCE(451);
      if (lookahead == 'C' ||
          lookahead == 'c') ADVANCE(428);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(430);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(449);
      END_STATE();
    case 415:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == 'T') ADVANCE(403);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(449);
      END_STATE();
    case 416:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == 'U') ADVANCE(406);
      if (lookahead == '^') ADVANCE(450);
      if (lookahead == '_') ADVANCE(451);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(430);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(449);
      END_STATE();
    case 417:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '[') ADVANCE(281);
      if (lookahead == 'f') ADVANCE(432);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(420);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(449);
      END_STATE();
    case 418:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '[') ADVANCE(447);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(449);
      END_STATE();
    case 419:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == ']') ADVANCE(449);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(423);
      END_STATE();
    case 420:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == ']') ADVANCE(341);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(420);
      END_STATE();
    case 421:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == ']') ADVANCE(358);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(421);
      END_STATE();
    case 422:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == ']') ADVANCE(440);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(422);
      END_STATE();
    case 423:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == ']') ADVANCE(360);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(423);
      END_STATE();
    case 424:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '^') ADVANCE(450);
      if (lookahead == '_') ADVANCE(451);
      if (lookahead == ')' ||
          lookahead == '.') ADVANCE(295);
      if (lookahead == 'L' ||
          lookahead == 'l') ADVANCE(429);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(430);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(449);
      END_STATE();
    case 425:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '^') ADVANCE(450);
      if (lookahead == '_') ADVANCE(451);
      if (lookahead == ')' ||
          lookahead == '.') ADVANCE(295);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(425);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(430);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(449);
      END_STATE();
    case 426:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '^') ADVANCE(450);
      if (lookahead == '_') ADVANCE(451);
      if (lookahead == ')' ||
          lookahead == '.') ADVANCE(295);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(430);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(449);
      END_STATE();
    case 427:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '^') ADVANCE(450);
      if (lookahead == '_') ADVANCE(451);
      if (lookahead == 'C' ||
          lookahead == 'c') ADVANCE(428);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(430);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(449);
      END_STATE();
    case 428:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '^') ADVANCE(450);
      if (lookahead == '_') ADVANCE(451);
      if (lookahead == 'K' ||
          lookahead == 'k') ADVANCE(375);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(430);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(449);
      END_STATE();
    case 429:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '^') ADVANCE(450);
      if (lookahead == '_') ADVANCE(451);
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(427);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(430);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(449);
      END_STATE();
    case 430:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '^') ADVANCE(450);
      if (lookahead == '_') ADVANCE(451);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(430);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(449);
      END_STATE();
    case 431:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == 'b') ADVANCE(349);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(353);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(449);
      END_STATE();
    case 432:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == 'n') ADVANCE(374);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(449);
      END_STATE();
    case 433:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '{') ADVANCE(232);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(449);
      END_STATE();
    case 434:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '{') ADVANCE(433);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(449);
      END_STATE();
    case 435:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '}') ADVANCE(355);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(449);
      END_STATE();
    case 436:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(383);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n') ADVANCE(449);
      END_STATE();
    case 437:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(382);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n') ADVANCE(449);
      END_STATE();
    case 438:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(438);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(381);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n') ADVANCE(449);
      END_STATE();
    case 439:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(438);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n') ADVANCE(449);
      END_STATE();
    case 440:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(384);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n') ADVANCE(449);
      END_STATE();
    case 441:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(442);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(449);
      END_STATE();
    case 442:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == 'G' ||
          lookahead == 'g') ADVANCE(443);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(449);
      END_STATE();
    case 443:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(444);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(449);
      END_STATE();
    case 444:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(378);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(449);
      END_STATE();
    case 445:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(421);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(449);
      END_STATE();
    case 446:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(448);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(449);
      END_STATE();
    case 447:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(422);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(449);
      END_STATE();
    case 448:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(359);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(449);
      END_STATE();
    case 449:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(449);
      END_STATE();
    case 450:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(356);
      END_STATE();
    case 451:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(357);
      END_STATE();
    case 452:
      ACCEPT_TOKEN(aux_sym_paragraph_token2);
      if (lookahead == '\n') ADVANCE(452);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 181},
  [2] = {.lex_state = 181},
  [3] = {.lex_state = 181},
  [4] = {.lex_state = 181},
  [5] = {.lex_state = 181},
  [6] = {.lex_state = 181},
  [7] = {.lex_state = 181},
  [8] = {.lex_state = 181},
  [9] = {.lex_state = 181},
  [10] = {.lex_state = 181},
  [11] = {.lex_state = 181},
  [12] = {.lex_state = 181},
  [13] = {.lex_state = 181},
  [14] = {.lex_state = 181},
  [15] = {.lex_state = 181},
  [16] = {.lex_state = 181},
  [17] = {.lex_state = 181},
  [18] = {.lex_state = 181},
  [19] = {.lex_state = 181},
  [20] = {.lex_state = 181},
  [21] = {.lex_state = 181},
  [22] = {.lex_state = 181},
  [23] = {.lex_state = 181},
  [24] = {.lex_state = 181},
  [25] = {.lex_state = 181},
  [26] = {.lex_state = 181},
  [27] = {.lex_state = 181},
  [28] = {.lex_state = 181},
  [29] = {.lex_state = 181},
  [30] = {.lex_state = 181},
  [31] = {.lex_state = 181},
  [32] = {.lex_state = 181},
  [33] = {.lex_state = 181},
  [34] = {.lex_state = 181},
  [35] = {.lex_state = 181},
  [36] = {.lex_state = 181},
  [37] = {.lex_state = 181},
  [38] = {.lex_state = 181},
  [39] = {.lex_state = 181},
  [40] = {.lex_state = 181},
  [41] = {.lex_state = 181},
  [42] = {.lex_state = 181},
  [43] = {.lex_state = 181},
  [44] = {.lex_state = 181},
  [45] = {.lex_state = 21},
  [46] = {.lex_state = 34},
  [47] = {.lex_state = 22},
  [48] = {.lex_state = 34},
  [49] = {.lex_state = 22},
  [50] = {.lex_state = 23},
  [51] = {.lex_state = 22},
  [52] = {.lex_state = 35},
  [53] = {.lex_state = 30},
  [54] = {.lex_state = 42},
  [55] = {.lex_state = 30},
  [56] = {.lex_state = 95},
  [57] = {.lex_state = 36},
  [58] = {.lex_state = 22},
  [59] = {.lex_state = 0},
  [60] = {.lex_state = 288},
  [61] = {.lex_state = 36},
  [62] = {.lex_state = 288},
  [63] = {.lex_state = 36},
  [64] = {.lex_state = 70},
  [65] = {.lex_state = 95},
  [66] = {.lex_state = 24},
  [67] = {.lex_state = 34},
  [68] = {.lex_state = 34},
  [69] = {.lex_state = 35},
  [70] = {.lex_state = 42},
  [71] = {.lex_state = 35},
  [72] = {.lex_state = 42},
  [73] = {.lex_state = 34},
  [74] = {.lex_state = 25},
  [75] = {.lex_state = 289},
  [76] = {.lex_state = 34},
  [77] = {.lex_state = 35},
  [78] = {.lex_state = 0},
  [79] = {.lex_state = 42},
  [80] = {.lex_state = 26},
  [81] = {.lex_state = 42},
  [82] = {.lex_state = 34},
  [83] = {.lex_state = 27},
  [84] = {.lex_state = 289},
  [85] = {.lex_state = 27},
  [86] = {.lex_state = 27},
  [87] = {.lex_state = 32},
  [88] = {.lex_state = 329},
  [89] = {.lex_state = 68},
  [90] = {.lex_state = 0},
  [91] = {.lex_state = 27},
  [92] = {.lex_state = 289},
  [93] = {.lex_state = 0},
  [94] = {.lex_state = 27},
  [95] = {.lex_state = 27},
  [96] = {.lex_state = 28},
  [97] = {.lex_state = 27},
  [98] = {.lex_state = 27},
  [99] = {.lex_state = 27},
  [100] = {.lex_state = 27},
  [101] = {.lex_state = 26},
  [102] = {.lex_state = 27},
  [103] = {.lex_state = 162},
  [104] = {.lex_state = 27},
  [105] = {.lex_state = 27},
  [106] = {.lex_state = 27},
  [107] = {.lex_state = 32},
  [108] = {.lex_state = 27},
  [109] = {.lex_state = 32},
  [110] = {.lex_state = 289},
  [111] = {.lex_state = 32},
  [112] = {.lex_state = 27},
  [113] = {.lex_state = 27},
  [114] = {.lex_state = 27},
  [115] = {.lex_state = 42},
  [116] = {.lex_state = 27},
  [117] = {.lex_state = 27},
  [118] = {.lex_state = 27},
  [119] = {.lex_state = 27},
  [120] = {.lex_state = 42},
  [121] = {.lex_state = 42},
  [122] = {.lex_state = 27},
  [123] = {.lex_state = 34},
  [124] = {.lex_state = 42},
  [125] = {.lex_state = 42},
  [126] = {.lex_state = 329},
  [127] = {.lex_state = 163},
  [128] = {.lex_state = 289},
  [129] = {.lex_state = 32},
  [130] = {.lex_state = 34},
  [131] = {.lex_state = 0},
  [132] = {.lex_state = 29},
  [133] = {.lex_state = 27},
  [134] = {.lex_state = 329},
  [135] = {.lex_state = 289},
  [136] = {.lex_state = 289},
  [137] = {.lex_state = 329},
  [138] = {.lex_state = 68},
  [139] = {.lex_state = 329},
  [140] = {.lex_state = 27},
  [141] = {.lex_state = 164},
  [142] = {.lex_state = 27},
  [143] = {.lex_state = 133},
  [144] = {.lex_state = 27},
  [145] = {.lex_state = 329},
  [146] = {.lex_state = 165},
  [147] = {.lex_state = 32},
  [148] = {.lex_state = 136},
  [149] = {.lex_state = 28},
  [150] = {.lex_state = 27},
  [151] = {.lex_state = 27},
  [152] = {.lex_state = 27},
  [153] = {.lex_state = 34},
  [154] = {.lex_state = 166},
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
    [anon_sym_BSLASHbegin_LBRACE] = ACTIONS(1),
    [aux_sym_latex_env_begin_token1] = ACTIONS(1),
    [anon_sym_RBRACE] = ACTIONS(1),
    [anon_sym_BSLASHend_LBRACE] = ACTIONS(1),
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
    [sym_document] = STATE(131),
    [sym__element] = STATE(3),
    [sym_headline] = STATE(3),
    [sym_macro] = STATE(3),
    [sym_latex_environment] = STATE(3),
    [sym_latex_env_begin] = STATE(56),
    [sym_link] = STATE(3),
    [sym_list] = STATE(3),
    [sym_list_item] = STATE(4),
    [sym_block] = STATE(3),
    [sym_block_begin] = STATE(52),
    [sym_dynamic_block] = STATE(3),
    [sym_dynamic_block_begin] = STATE(57),
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
    [anon_sym_BSLASHbegin_LBRACE] = ACTIONS(11),
    [sym_entity] = ACTIONS(7),
    [sym_subscript] = ACTIONS(7),
    [sym_superscript] = ACTIONS(7),
    [anon_sym_LBRACK_LBRACK] = ACTIONS(13),
    [aux_sym_list_item_token1] = ACTIONS(15),
    [sym_bullet] = ACTIONS(17),
    [aux_sym_block_begin_token1] = ACTIONS(19),
    [aux_sym_dynamic_block_begin_token1] = ACTIONS(21),
    [anon_sym_PIPE] = ACTIONS(23),
    [sym_table_separator] = ACTIONS(25),
    [aux_sym_directive_token1] = ACTIONS(27),
    [anon_sym_COLON] = ACTIONS(29),
    [aux_sym_comment_token1] = ACTIONS(31),
    [aux_sym_fixed_width_token1] = ACTIONS(33),
    [anon_sym_COLONPROPERTIES_COLON] = ACTIONS(35),
    [sym_horizontal_rule] = ACTIONS(7),
    [aux_sym_paragraph_token1] = ACTIONS(37),
  },
  [2] = {
    [sym__element] = STATE(2),
    [sym_headline] = STATE(2),
    [sym_macro] = STATE(2),
    [sym_latex_environment] = STATE(2),
    [sym_latex_env_begin] = STATE(56),
    [sym_link] = STATE(2),
    [sym_list] = STATE(2),
    [sym_list_item] = STATE(4),
    [sym_block] = STATE(2),
    [sym_block_begin] = STATE(52),
    [sym_dynamic_block] = STATE(2),
    [sym_dynamic_block_begin] = STATE(57),
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
    [ts_builtin_sym_end] = ACTIONS(39),
    [sym_stars] = ACTIONS(41),
    [sym_planning_line] = ACTIONS(44),
    [sym_clock] = ACTIONS(44),
    [sym_diary_sexp] = ACTIONS(44),
    [sym_timestamp] = ACTIONS(44),
    [anon_sym_LBRACE_LBRACE_LBRACE] = ACTIONS(47),
    [sym_footnote_reference] = ACTIONS(44),
    [sym_latex_fragment] = ACTIONS(44),
    [anon_sym_BSLASHbegin_LBRACE] = ACTIONS(50),
    [sym_entity] = ACTIONS(44),
    [sym_subscript] = ACTIONS(44),
    [sym_superscript] = ACTIONS(44),
    [anon_sym_LBRACK_LBRACK] = ACTIONS(53),
    [aux_sym_list_item_token1] = ACTIONS(56),
    [sym_bullet] = ACTIONS(59),
    [aux_sym_block_begin_token1] = ACTIONS(62),
    [aux_sym_dynamic_block_begin_token1] = ACTIONS(65),
    [anon_sym_PIPE] = ACTIONS(68),
    [sym_table_separator] = ACTIONS(71),
    [aux_sym_directive_token1] = ACTIONS(74),
    [anon_sym_COLON] = ACTIONS(77),
    [aux_sym_comment_token1] = ACTIONS(80),
    [aux_sym_fixed_width_token1] = ACTIONS(83),
    [anon_sym_COLONPROPERTIES_COLON] = ACTIONS(86),
    [sym_horizontal_rule] = ACTIONS(44),
    [aux_sym_paragraph_token1] = ACTIONS(89),
  },
  [3] = {
    [sym__element] = STATE(2),
    [sym_headline] = STATE(2),
    [sym_macro] = STATE(2),
    [sym_latex_environment] = STATE(2),
    [sym_latex_env_begin] = STATE(56),
    [sym_link] = STATE(2),
    [sym_list] = STATE(2),
    [sym_list_item] = STATE(4),
    [sym_block] = STATE(2),
    [sym_block_begin] = STATE(52),
    [sym_dynamic_block] = STATE(2),
    [sym_dynamic_block_begin] = STATE(57),
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
    [ts_builtin_sym_end] = ACTIONS(92),
    [sym_stars] = ACTIONS(5),
    [sym_planning_line] = ACTIONS(94),
    [sym_clock] = ACTIONS(94),
    [sym_diary_sexp] = ACTIONS(94),
    [sym_timestamp] = ACTIONS(94),
    [anon_sym_LBRACE_LBRACE_LBRACE] = ACTIONS(9),
    [sym_footnote_reference] = ACTIONS(94),
    [sym_latex_fragment] = ACTIONS(94),
    [anon_sym_BSLASHbegin_LBRACE] = ACTIONS(11),
    [sym_entity] = ACTIONS(94),
    [sym_subscript] = ACTIONS(94),
    [sym_superscript] = ACTIONS(94),
    [anon_sym_LBRACK_LBRACK] = ACTIONS(13),
    [aux_sym_list_item_token1] = ACTIONS(15),
    [sym_bullet] = ACTIONS(17),
    [aux_sym_block_begin_token1] = ACTIONS(19),
    [aux_sym_dynamic_block_begin_token1] = ACTIONS(21),
    [anon_sym_PIPE] = ACTIONS(23),
    [sym_table_separator] = ACTIONS(25),
    [aux_sym_directive_token1] = ACTIONS(27),
    [anon_sym_COLON] = ACTIONS(29),
    [aux_sym_comment_token1] = ACTIONS(31),
    [aux_sym_fixed_width_token1] = ACTIONS(33),
    [anon_sym_COLONPROPERTIES_COLON] = ACTIONS(35),
    [sym_horizontal_rule] = ACTIONS(94),
    [aux_sym_paragraph_token1] = ACTIONS(37),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 5,
    ACTIONS(15), 1,
      aux_sym_list_item_token1,
    ACTIONS(17), 1,
      sym_bullet,
    ACTIONS(96), 1,
      ts_builtin_sym_end,
    STATE(6), 2,
      sym_list_item,
      aux_sym_list_repeat1,
    ACTIONS(98), 24,
      sym_stars,
      sym_planning_line,
      sym_clock,
      sym_diary_sexp,
      sym_timestamp,
      anon_sym_LBRACE_LBRACE_LBRACE,
      sym_footnote_reference,
      sym_latex_fragment,
      anon_sym_BSLASHbegin_LBRACE,
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
  [40] = 5,
    ACTIONS(100), 1,
      ts_builtin_sym_end,
    ACTIONS(104), 1,
      anon_sym_PIPE,
    ACTIONS(107), 1,
      sym_table_separator,
    STATE(5), 2,
      sym_table_row,
      aux_sym_table_repeat1,
    ACTIONS(102), 24,
      sym_stars,
      sym_planning_line,
      sym_clock,
      sym_diary_sexp,
      sym_timestamp,
      anon_sym_LBRACE_LBRACE_LBRACE,
      sym_footnote_reference,
      sym_latex_fragment,
      anon_sym_BSLASHbegin_LBRACE,
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
  [80] = 5,
    ACTIONS(110), 1,
      ts_builtin_sym_end,
    ACTIONS(114), 1,
      aux_sym_list_item_token1,
    ACTIONS(117), 1,
      sym_bullet,
    STATE(6), 2,
      sym_list_item,
      aux_sym_list_repeat1,
    ACTIONS(112), 24,
      sym_stars,
      sym_planning_line,
      sym_clock,
      sym_diary_sexp,
      sym_timestamp,
      anon_sym_LBRACE_LBRACE_LBRACE,
      sym_footnote_reference,
      sym_latex_fragment,
      anon_sym_BSLASHbegin_LBRACE,
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
  [120] = 5,
    ACTIONS(23), 1,
      anon_sym_PIPE,
    ACTIONS(120), 1,
      ts_builtin_sym_end,
    ACTIONS(124), 1,
      sym_table_separator,
    STATE(5), 2,
      sym_table_row,
      aux_sym_table_repeat1,
    ACTIONS(122), 24,
      sym_stars,
      sym_planning_line,
      sym_clock,
      sym_diary_sexp,
      sym_timestamp,
      anon_sym_LBRACE_LBRACE_LBRACE,
      sym_footnote_reference,
      sym_latex_fragment,
      anon_sym_BSLASHbegin_LBRACE,
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
  [160] = 4,
    ACTIONS(126), 1,
      ts_builtin_sym_end,
    ACTIONS(130), 1,
      aux_sym_fixed_width_token1,
    STATE(8), 1,
      aux_sym_fixed_width_repeat1,
    ACTIONS(128), 25,
      sym_stars,
      sym_planning_line,
      sym_clock,
      sym_diary_sexp,
      sym_timestamp,
      anon_sym_LBRACE_LBRACE_LBRACE,
      sym_footnote_reference,
      sym_latex_fragment,
      anon_sym_BSLASHbegin_LBRACE,
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
  [197] = 4,
    ACTIONS(33), 1,
      aux_sym_fixed_width_token1,
    ACTIONS(133), 1,
      ts_builtin_sym_end,
    STATE(8), 1,
      aux_sym_fixed_width_repeat1,
    ACTIONS(135), 25,
      sym_stars,
      sym_planning_line,
      sym_clock,
      sym_diary_sexp,
      sym_timestamp,
      anon_sym_LBRACE_LBRACE_LBRACE,
      sym_footnote_reference,
      sym_latex_fragment,
      anon_sym_BSLASHbegin_LBRACE,
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
  [234] = 2,
    ACTIONS(137), 1,
      ts_builtin_sym_end,
    ACTIONS(139), 26,
      sym_stars,
      sym_planning_line,
      sym_clock,
      sym_diary_sexp,
      sym_timestamp,
      anon_sym_LBRACE_LBRACE_LBRACE,
      sym_footnote_reference,
      sym_latex_fragment,
      anon_sym_BSLASHbegin_LBRACE,
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
  [266] = 2,
    ACTIONS(141), 1,
      ts_builtin_sym_end,
    ACTIONS(143), 26,
      sym_stars,
      sym_planning_line,
      sym_clock,
      sym_diary_sexp,
      sym_timestamp,
      anon_sym_LBRACE_LBRACE_LBRACE,
      sym_footnote_reference,
      sym_latex_fragment,
      anon_sym_BSLASHbegin_LBRACE,
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
  [298] = 2,
    ACTIONS(145), 1,
      ts_builtin_sym_end,
    ACTIONS(147), 26,
      sym_stars,
      sym_planning_line,
      sym_clock,
      sym_diary_sexp,
      sym_timestamp,
      anon_sym_LBRACE_LBRACE_LBRACE,
      sym_footnote_reference,
      sym_latex_fragment,
      anon_sym_BSLASHbegin_LBRACE,
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
  [330] = 2,
    ACTIONS(149), 1,
      ts_builtin_sym_end,
    ACTIONS(151), 26,
      sym_stars,
      sym_planning_line,
      sym_clock,
      sym_diary_sexp,
      sym_timestamp,
      anon_sym_LBRACE_LBRACE_LBRACE,
      sym_footnote_reference,
      sym_latex_fragment,
      anon_sym_BSLASHbegin_LBRACE,
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
  [362] = 2,
    ACTIONS(153), 1,
      ts_builtin_sym_end,
    ACTIONS(155), 26,
      sym_stars,
      sym_planning_line,
      sym_clock,
      sym_diary_sexp,
      sym_timestamp,
      anon_sym_LBRACE_LBRACE_LBRACE,
      sym_footnote_reference,
      sym_latex_fragment,
      anon_sym_BSLASHbegin_LBRACE,
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
  [394] = 2,
    ACTIONS(157), 1,
      ts_builtin_sym_end,
    ACTIONS(159), 26,
      sym_stars,
      sym_planning_line,
      sym_clock,
      sym_diary_sexp,
      sym_timestamp,
      anon_sym_LBRACE_LBRACE_LBRACE,
      sym_footnote_reference,
      sym_latex_fragment,
      anon_sym_BSLASHbegin_LBRACE,
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
  [426] = 2,
    ACTIONS(161), 1,
      ts_builtin_sym_end,
    ACTIONS(163), 26,
      sym_stars,
      sym_planning_line,
      sym_clock,
      sym_diary_sexp,
      sym_timestamp,
      anon_sym_LBRACE_LBRACE_LBRACE,
      sym_footnote_reference,
      sym_latex_fragment,
      anon_sym_BSLASHbegin_LBRACE,
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
  [458] = 2,
    ACTIONS(165), 1,
      ts_builtin_sym_end,
    ACTIONS(167), 26,
      sym_stars,
      sym_planning_line,
      sym_clock,
      sym_diary_sexp,
      sym_timestamp,
      anon_sym_LBRACE_LBRACE_LBRACE,
      sym_footnote_reference,
      sym_latex_fragment,
      anon_sym_BSLASHbegin_LBRACE,
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
  [490] = 2,
    ACTIONS(169), 1,
      ts_builtin_sym_end,
    ACTIONS(171), 26,
      sym_stars,
      sym_planning_line,
      sym_clock,
      sym_diary_sexp,
      sym_timestamp,
      anon_sym_LBRACE_LBRACE_LBRACE,
      sym_footnote_reference,
      sym_latex_fragment,
      anon_sym_BSLASHbegin_LBRACE,
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
  [522] = 2,
    ACTIONS(173), 1,
      ts_builtin_sym_end,
    ACTIONS(175), 26,
      sym_stars,
      sym_planning_line,
      sym_clock,
      sym_diary_sexp,
      sym_timestamp,
      anon_sym_LBRACE_LBRACE_LBRACE,
      sym_footnote_reference,
      sym_latex_fragment,
      anon_sym_BSLASHbegin_LBRACE,
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
  [554] = 2,
    ACTIONS(177), 1,
      ts_builtin_sym_end,
    ACTIONS(179), 26,
      sym_stars,
      sym_planning_line,
      sym_clock,
      sym_diary_sexp,
      sym_timestamp,
      anon_sym_LBRACE_LBRACE_LBRACE,
      sym_footnote_reference,
      sym_latex_fragment,
      anon_sym_BSLASHbegin_LBRACE,
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
  [586] = 2,
    ACTIONS(181), 1,
      ts_builtin_sym_end,
    ACTIONS(183), 26,
      sym_stars,
      sym_planning_line,
      sym_clock,
      sym_diary_sexp,
      sym_timestamp,
      anon_sym_LBRACE_LBRACE_LBRACE,
      sym_footnote_reference,
      sym_latex_fragment,
      anon_sym_BSLASHbegin_LBRACE,
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
  [618] = 2,
    ACTIONS(185), 1,
      ts_builtin_sym_end,
    ACTIONS(187), 26,
      sym_stars,
      sym_planning_line,
      sym_clock,
      sym_diary_sexp,
      sym_timestamp,
      anon_sym_LBRACE_LBRACE_LBRACE,
      sym_footnote_reference,
      sym_latex_fragment,
      anon_sym_BSLASHbegin_LBRACE,
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
  [650] = 2,
    ACTIONS(189), 1,
      ts_builtin_sym_end,
    ACTIONS(191), 26,
      sym_stars,
      sym_planning_line,
      sym_clock,
      sym_diary_sexp,
      sym_timestamp,
      anon_sym_LBRACE_LBRACE_LBRACE,
      sym_footnote_reference,
      sym_latex_fragment,
      anon_sym_BSLASHbegin_LBRACE,
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
  [682] = 2,
    ACTIONS(193), 1,
      ts_builtin_sym_end,
    ACTIONS(195), 26,
      sym_stars,
      sym_planning_line,
      sym_clock,
      sym_diary_sexp,
      sym_timestamp,
      anon_sym_LBRACE_LBRACE_LBRACE,
      sym_footnote_reference,
      sym_latex_fragment,
      anon_sym_BSLASHbegin_LBRACE,
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
  [714] = 2,
    ACTIONS(197), 1,
      ts_builtin_sym_end,
    ACTIONS(199), 26,
      sym_stars,
      sym_planning_line,
      sym_clock,
      sym_diary_sexp,
      sym_timestamp,
      anon_sym_LBRACE_LBRACE_LBRACE,
      sym_footnote_reference,
      sym_latex_fragment,
      anon_sym_BSLASHbegin_LBRACE,
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
  [746] = 2,
    ACTIONS(201), 1,
      ts_builtin_sym_end,
    ACTIONS(203), 26,
      sym_stars,
      sym_planning_line,
      sym_clock,
      sym_diary_sexp,
      sym_timestamp,
      anon_sym_LBRACE_LBRACE_LBRACE,
      sym_footnote_reference,
      sym_latex_fragment,
      anon_sym_BSLASHbegin_LBRACE,
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
  [778] = 2,
    ACTIONS(205), 1,
      ts_builtin_sym_end,
    ACTIONS(207), 26,
      sym_stars,
      sym_planning_line,
      sym_clock,
      sym_diary_sexp,
      sym_timestamp,
      anon_sym_LBRACE_LBRACE_LBRACE,
      sym_footnote_reference,
      sym_latex_fragment,
      anon_sym_BSLASHbegin_LBRACE,
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
  [810] = 2,
    ACTIONS(209), 1,
      ts_builtin_sym_end,
    ACTIONS(211), 26,
      sym_stars,
      sym_planning_line,
      sym_clock,
      sym_diary_sexp,
      sym_timestamp,
      anon_sym_LBRACE_LBRACE_LBRACE,
      sym_footnote_reference,
      sym_latex_fragment,
      anon_sym_BSLASHbegin_LBRACE,
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
  [842] = 2,
    ACTIONS(213), 1,
      ts_builtin_sym_end,
    ACTIONS(215), 26,
      sym_stars,
      sym_planning_line,
      sym_clock,
      sym_diary_sexp,
      sym_timestamp,
      anon_sym_LBRACE_LBRACE_LBRACE,
      sym_footnote_reference,
      sym_latex_fragment,
      anon_sym_BSLASHbegin_LBRACE,
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
  [874] = 2,
    ACTIONS(217), 1,
      ts_builtin_sym_end,
    ACTIONS(219), 26,
      sym_stars,
      sym_planning_line,
      sym_clock,
      sym_diary_sexp,
      sym_timestamp,
      anon_sym_LBRACE_LBRACE_LBRACE,
      sym_footnote_reference,
      sym_latex_fragment,
      anon_sym_BSLASHbegin_LBRACE,
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
  [906] = 2,
    ACTIONS(221), 1,
      ts_builtin_sym_end,
    ACTIONS(223), 26,
      sym_stars,
      sym_planning_line,
      sym_clock,
      sym_diary_sexp,
      sym_timestamp,
      anon_sym_LBRACE_LBRACE_LBRACE,
      sym_footnote_reference,
      sym_latex_fragment,
      anon_sym_BSLASHbegin_LBRACE,
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
  [938] = 2,
    ACTIONS(225), 1,
      ts_builtin_sym_end,
    ACTIONS(227), 26,
      sym_stars,
      sym_planning_line,
      sym_clock,
      sym_diary_sexp,
      sym_timestamp,
      anon_sym_LBRACE_LBRACE_LBRACE,
      sym_footnote_reference,
      sym_latex_fragment,
      anon_sym_BSLASHbegin_LBRACE,
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
  [970] = 2,
    ACTIONS(229), 1,
      ts_builtin_sym_end,
    ACTIONS(231), 26,
      sym_stars,
      sym_planning_line,
      sym_clock,
      sym_diary_sexp,
      sym_timestamp,
      anon_sym_LBRACE_LBRACE_LBRACE,
      sym_footnote_reference,
      sym_latex_fragment,
      anon_sym_BSLASHbegin_LBRACE,
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
  [1002] = 2,
    ACTIONS(233), 1,
      ts_builtin_sym_end,
    ACTIONS(235), 26,
      sym_stars,
      sym_planning_line,
      sym_clock,
      sym_diary_sexp,
      sym_timestamp,
      anon_sym_LBRACE_LBRACE_LBRACE,
      sym_footnote_reference,
      sym_latex_fragment,
      anon_sym_BSLASHbegin_LBRACE,
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
    ACTIONS(237), 1,
      ts_builtin_sym_end,
    ACTIONS(239), 26,
      sym_stars,
      sym_planning_line,
      sym_clock,
      sym_diary_sexp,
      sym_timestamp,
      anon_sym_LBRACE_LBRACE_LBRACE,
      sym_footnote_reference,
      sym_latex_fragment,
      anon_sym_BSLASHbegin_LBRACE,
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
  [1066] = 2,
    ACTIONS(241), 1,
      ts_builtin_sym_end,
    ACTIONS(243), 26,
      sym_stars,
      sym_planning_line,
      sym_clock,
      sym_diary_sexp,
      sym_timestamp,
      anon_sym_LBRACE_LBRACE_LBRACE,
      sym_footnote_reference,
      sym_latex_fragment,
      anon_sym_BSLASHbegin_LBRACE,
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
  [1098] = 2,
    ACTIONS(245), 1,
      ts_builtin_sym_end,
    ACTIONS(247), 26,
      sym_stars,
      sym_planning_line,
      sym_clock,
      sym_diary_sexp,
      sym_timestamp,
      anon_sym_LBRACE_LBRACE_LBRACE,
      sym_footnote_reference,
      sym_latex_fragment,
      anon_sym_BSLASHbegin_LBRACE,
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
  [1130] = 2,
    ACTIONS(249), 1,
      ts_builtin_sym_end,
    ACTIONS(251), 26,
      sym_stars,
      sym_planning_line,
      sym_clock,
      sym_diary_sexp,
      sym_timestamp,
      anon_sym_LBRACE_LBRACE_LBRACE,
      sym_footnote_reference,
      sym_latex_fragment,
      anon_sym_BSLASHbegin_LBRACE,
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
  [1162] = 2,
    ACTIONS(253), 1,
      ts_builtin_sym_end,
    ACTIONS(255), 26,
      sym_stars,
      sym_planning_line,
      sym_clock,
      sym_diary_sexp,
      sym_timestamp,
      anon_sym_LBRACE_LBRACE_LBRACE,
      sym_footnote_reference,
      sym_latex_fragment,
      anon_sym_BSLASHbegin_LBRACE,
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
  [1194] = 2,
    ACTIONS(257), 1,
      ts_builtin_sym_end,
    ACTIONS(259), 26,
      sym_stars,
      sym_planning_line,
      sym_clock,
      sym_diary_sexp,
      sym_timestamp,
      anon_sym_LBRACE_LBRACE_LBRACE,
      sym_footnote_reference,
      sym_latex_fragment,
      anon_sym_BSLASHbegin_LBRACE,
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
  [1226] = 2,
    ACTIONS(261), 1,
      ts_builtin_sym_end,
    ACTIONS(263), 26,
      sym_stars,
      sym_planning_line,
      sym_clock,
      sym_diary_sexp,
      sym_timestamp,
      anon_sym_LBRACE_LBRACE_LBRACE,
      sym_footnote_reference,
      sym_latex_fragment,
      anon_sym_BSLASHbegin_LBRACE,
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
  [1258] = 2,
    ACTIONS(265), 1,
      ts_builtin_sym_end,
    ACTIONS(267), 26,
      sym_stars,
      sym_planning_line,
      sym_clock,
      sym_diary_sexp,
      sym_timestamp,
      anon_sym_LBRACE_LBRACE_LBRACE,
      sym_footnote_reference,
      sym_latex_fragment,
      anon_sym_BSLASHbegin_LBRACE,
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
  [1290] = 2,
    ACTIONS(269), 1,
      ts_builtin_sym_end,
    ACTIONS(271), 26,
      sym_stars,
      sym_planning_line,
      sym_clock,
      sym_diary_sexp,
      sym_timestamp,
      anon_sym_LBRACE_LBRACE_LBRACE,
      sym_footnote_reference,
      sym_latex_fragment,
      anon_sym_BSLASHbegin_LBRACE,
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
  [1322] = 2,
    ACTIONS(273), 1,
      ts_builtin_sym_end,
    ACTIONS(275), 26,
      sym_stars,
      sym_planning_line,
      sym_clock,
      sym_diary_sexp,
      sym_timestamp,
      anon_sym_LBRACE_LBRACE_LBRACE,
      sym_footnote_reference,
      sym_latex_fragment,
      anon_sym_BSLASHbegin_LBRACE,
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
  [1354] = 5,
    ACTIONS(277), 1,
      anon_sym_LF,
    ACTIONS(279), 1,
      sym_keyword,
    ACTIONS(281), 1,
      sym_priority,
    ACTIONS(283), 1,
      aux_sym_title_token1,
    STATE(104), 1,
      sym_title,
  [1370] = 3,
    ACTIONS(285), 1,
      anon_sym_COLON,
    ACTIONS(287), 1,
      anon_sym_COLONEND_COLON,
    STATE(48), 2,
      sym_property,
      aux_sym_property_drawer_repeat1,
  [1381] = 4,
    ACTIONS(289), 1,
      anon_sym_LF,
    ACTIONS(291), 1,
      anon_sym_PIPE,
    ACTIONS(293), 1,
      sym_table_cell,
    STATE(49), 1,
      aux_sym_table_row_repeat1,
  [1394] = 3,
    ACTIONS(295), 1,
      anon_sym_COLON,
    ACTIONS(298), 1,
      anon_sym_COLONEND_COLON,
    STATE(48), 2,
      sym_property,
      aux_sym_property_drawer_repeat1,
  [1405] = 4,
    ACTIONS(300), 1,
      anon_sym_LF,
    ACTIONS(302), 1,
      anon_sym_PIPE,
    ACTIONS(305), 1,
      sym_table_cell,
    STATE(49), 1,
      aux_sym_table_row_repeat1,
  [1418] = 4,
    ACTIONS(283), 1,
      aux_sym_title_token1,
    ACTIONS(308), 1,
      anon_sym_LF,
    ACTIONS(310), 1,
      sym_priority,
    STATE(112), 1,
      sym_title,
  [1431] = 4,
    ACTIONS(293), 1,
      sym_table_cell,
    ACTIONS(312), 1,
      anon_sym_LF,
    ACTIONS(314), 1,
      anon_sym_PIPE,
    STATE(47), 1,
      aux_sym_table_row_repeat1,
  [1444] = 3,
    ACTIONS(316), 1,
      sym_block_content,
    ACTIONS(318), 1,
      aux_sym_block_end_token1,
    STATE(44), 1,
      sym_block_end,
  [1454] = 3,
    ACTIONS(283), 1,
      aux_sym_title_token1,
    ACTIONS(320), 1,
      anon_sym_LF,
    STATE(114), 1,
      sym_title,
  [1464] = 2,
    ACTIONS(322), 1,
      anon_sym_COLON,
    STATE(46), 2,
      sym_property,
      aux_sym_property_drawer_repeat1,
  [1472] = 3,
    ACTIONS(283), 1,
      aux_sym_title_token1,
    ACTIONS(324), 1,
      anon_sym_LF,
    STATE(142), 1,
      sym_title,
  [1482] = 3,
    ACTIONS(326), 1,
      sym_latex_env_content,
    ACTIONS(328), 1,
      anon_sym_BSLASHend_LBRACE,
    STATE(43), 1,
      sym_latex_env_end,
  [1492] = 3,
    ACTIONS(330), 1,
      sym_dynamic_block_content,
    ACTIONS(332), 1,
      aux_sym_dynamic_block_end_token1,
    STATE(35), 1,
      sym_dynamic_block_end,
  [1502] = 1,
    ACTIONS(300), 3,
      anon_sym_LF,
      anon_sym_PIPE,
      sym_table_cell,
  [1508] = 2,
    ACTIONS(334), 1,
      anon_sym_RBRACK_LBRACK,
    ACTIONS(336), 1,
      anon_sym_RBRACK_RBRACK,
  [1515] = 2,
    ACTIONS(338), 1,
      anon_sym_LF,
    ACTIONS(340), 1,
      aux_sym_list_item_token2,
  [1522] = 2,
    ACTIONS(342), 1,
      sym_dynamic_block_content,
    ACTIONS(344), 1,
      aux_sym_dynamic_block_end_token1,
  [1529] = 2,
    ACTIONS(346), 1,
      anon_sym_LF,
    ACTIONS(348), 1,
      aux_sym_list_item_token2,
  [1536] = 2,
    ACTIONS(350), 1,
      sym_dynamic_block_content,
    ACTIONS(352), 1,
      aux_sym_dynamic_block_end_token1,
  [1543] = 2,
    ACTIONS(354), 1,
      anon_sym_COLONend_COLON,
    ACTIONS(356), 1,
      sym_drawer_content,
  [1550] = 2,
    ACTIONS(358), 1,
      sym_latex_env_content,
    ACTIONS(360), 1,
      anon_sym_BSLASHend_LBRACE,
  [1557] = 2,
    ACTIONS(362), 1,
      anon_sym_SPACE,
    ACTIONS(364), 1,
      anon_sym_LF,
  [1564] = 2,
    ACTIONS(366), 1,
      aux_sym_latex_env_begin_token1,
    ACTIONS(368), 1,
      anon_sym_RBRACE,
  [1571] = 2,
    ACTIONS(370), 1,
      aux_sym_dynamic_block_end_token1,
    STATE(23), 1,
      sym_dynamic_block_end,
  [1578] = 2,
    ACTIONS(372), 1,
      sym_block_content,
    ACTIONS(374), 1,
      aux_sym_block_end_token1,
  [1585] = 2,
    ACTIONS(376), 1,
      aux_sym_key_token1,
    STATE(125), 1,
      sym_key,
  [1592] = 2,
    ACTIONS(378), 1,
      sym_block_content,
    ACTIONS(380), 1,
      aux_sym_block_end_token1,
  [1599] = 2,
    ACTIONS(382), 1,
      anon_sym_LPAREN,
    ACTIONS(384), 1,
      anon_sym_RBRACE_RBRACE_RBRACE,
  [1606] = 2,
    ACTIONS(386), 1,
      anon_sym_COLON,
    ACTIONS(388), 1,
      anon_sym_COLONEND_COLON,
  [1613] = 2,
    ACTIONS(390), 1,
      aux_sym_title_token1,
    ACTIONS(392), 1,
      aux_sym_list_item_token1,
  [1620] = 2,
    ACTIONS(394), 1,
      aux_sym_list_item_token2,
    ACTIONS(396), 1,
      sym_block_type,
  [1627] = 2,
    ACTIONS(398), 1,
      aux_sym_block_end_token1,
    STATE(38), 1,
      sym_block_end,
  [1634] = 2,
    ACTIONS(400), 1,
      sym_block_content,
    ACTIONS(402), 1,
      aux_sym_block_end_token1,
  [1641] = 2,
    ACTIONS(404), 1,
      anon_sym_BSLASHend_LBRACE,
    STATE(41), 1,
      sym_latex_env_end,
  [1648] = 2,
    ACTIONS(406), 1,
      aux_sym_key_token1,
    STATE(81), 1,
      sym_drawer_name,
  [1655] = 2,
    ACTIONS(408), 1,
      aux_sym_title_token1,
    STATE(152), 1,
      sym_value,
  [1662] = 1,
    ACTIONS(410), 1,
      anon_sym_COLON,
  [1666] = 1,
    ACTIONS(412), 1,
      anon_sym_RBRACE,
  [1670] = 1,
    ACTIONS(414), 1,
      anon_sym_LF,
  [1674] = 1,
    ACTIONS(416), 1,
      aux_sym_list_item_token2,
  [1678] = 1,
    ACTIONS(418), 1,
      anon_sym_LF,
  [1682] = 1,
    ACTIONS(420), 1,
      anon_sym_LF,
  [1686] = 1,
    ACTIONS(422), 1,
      anon_sym_SPACE,
  [1690] = 1,
    ACTIONS(424), 1,
      aux_sym_property_drawer_token1,
  [1694] = 1,
    ACTIONS(426), 1,
      sym_language,
  [1698] = 1,
    ACTIONS(428), 1,
      anon_sym_RPAREN,
  [1702] = 1,
    ACTIONS(430), 1,
      anon_sym_LF,
  [1706] = 1,
    ACTIONS(432), 1,
      aux_sym_list_item_token2,
  [1710] = 1,
    ACTIONS(434), 1,
      anon_sym_RBRACK_RBRACK,
  [1714] = 1,
    ACTIONS(436), 1,
      anon_sym_LF,
  [1718] = 1,
    ACTIONS(438), 1,
      anon_sym_LF,
  [1722] = 1,
    ACTIONS(440), 1,
      aux_sym_link_token1,
  [1726] = 1,
    ACTIONS(442), 1,
      anon_sym_LF,
  [1730] = 1,
    ACTIONS(444), 1,
      anon_sym_LF,
  [1734] = 1,
    ACTIONS(446), 1,
      anon_sym_LF,
  [1738] = 1,
    ACTIONS(448), 1,
      anon_sym_LF,
  [1742] = 1,
    ACTIONS(450), 1,
      aux_sym_title_token1,
  [1746] = 1,
    ACTIONS(452), 1,
      anon_sym_LF,
  [1750] = 1,
    ACTIONS(454), 1,
      aux_sym_macro_token2,
  [1754] = 1,
    ACTIONS(456), 1,
      anon_sym_LF,
  [1758] = 1,
    ACTIONS(458), 1,
      anon_sym_LF,
  [1762] = 1,
    ACTIONS(460), 1,
      anon_sym_LF,
  [1766] = 1,
    ACTIONS(462), 1,
      anon_sym_SPACE,
  [1770] = 1,
    ACTIONS(464), 1,
      anon_sym_LF,
  [1774] = 1,
    ACTIONS(466), 1,
      anon_sym_SPACE,
  [1778] = 1,
    ACTIONS(468), 1,
      aux_sym_list_item_token2,
  [1782] = 1,
    ACTIONS(470), 1,
      anon_sym_SPACE,
  [1786] = 1,
    ACTIONS(472), 1,
      anon_sym_LF,
  [1790] = 1,
    ACTIONS(474), 1,
      anon_sym_LF,
  [1794] = 1,
    ACTIONS(476), 1,
      anon_sym_LF,
  [1798] = 1,
    ACTIONS(478), 1,
      anon_sym_RBRACE_RBRACE_RBRACE,
  [1802] = 1,
    ACTIONS(480), 1,
      anon_sym_LF,
  [1806] = 1,
    ACTIONS(482), 1,
      anon_sym_LF,
  [1810] = 1,
    ACTIONS(484), 1,
      anon_sym_LF,
  [1814] = 1,
    ACTIONS(486), 1,
      anon_sym_LF,
  [1818] = 1,
    ACTIONS(488), 1,
      anon_sym_COLON,
  [1822] = 1,
    ACTIONS(490), 1,
      anon_sym_COLON,
  [1826] = 1,
    ACTIONS(492), 1,
      anon_sym_LF,
  [1830] = 1,
    ACTIONS(494), 1,
      anon_sym_PIPE,
  [1834] = 1,
    ACTIONS(496), 1,
      anon_sym_COLON,
  [1838] = 1,
    ACTIONS(498), 1,
      anon_sym_COLON,
  [1842] = 1,
    ACTIONS(500), 1,
      aux_sym_property_drawer_token1,
  [1846] = 1,
    ACTIONS(502), 1,
      aux_sym_dynamic_block_begin_token2,
  [1850] = 1,
    ACTIONS(504), 1,
      aux_sym_list_item_token2,
  [1854] = 1,
    ACTIONS(506), 1,
      anon_sym_SPACE,
  [1858] = 1,
    ACTIONS(508), 1,
      anon_sym_RBRACE,
  [1862] = 1,
    ACTIONS(510), 1,
      ts_builtin_sym_end,
  [1866] = 1,
    ACTIONS(512), 1,
      aux_sym_paragraph_token2,
  [1870] = 1,
    ACTIONS(514), 1,
      anon_sym_LF,
  [1874] = 1,
    ACTIONS(516), 1,
      aux_sym_property_drawer_token1,
  [1878] = 1,
    ACTIONS(518), 1,
      aux_sym_list_item_token2,
  [1882] = 1,
    ACTIONS(520), 1,
      aux_sym_list_item_token2,
  [1886] = 1,
    ACTIONS(522), 1,
      aux_sym_property_drawer_token1,
  [1890] = 1,
    ACTIONS(524), 1,
      anon_sym_COLONend_COLON,
  [1894] = 1,
    ACTIONS(526), 1,
      aux_sym_property_drawer_token1,
  [1898] = 1,
    ACTIONS(528), 1,
      anon_sym_LF,
  [1902] = 1,
    ACTIONS(530), 1,
      sym_name,
  [1906] = 1,
    ACTIONS(532), 1,
      anon_sym_LF,
  [1910] = 1,
    ACTIONS(534), 1,
      aux_sym_list_item_token1,
  [1914] = 1,
    ACTIONS(536), 1,
      anon_sym_LF,
  [1918] = 1,
    ACTIONS(538), 1,
      aux_sym_property_drawer_token1,
  [1922] = 1,
    ACTIONS(540), 1,
      sym_block_type,
  [1926] = 1,
    ACTIONS(542), 1,
      anon_sym_SPACE,
  [1930] = 1,
    ACTIONS(544), 1,
      sym_bullet,
  [1934] = 1,
    ACTIONS(546), 1,
      aux_sym_link_token1,
  [1938] = 1,
    ACTIONS(548), 1,
      anon_sym_LF,
  [1942] = 1,
    ACTIONS(550), 1,
      anon_sym_LF,
  [1946] = 1,
    ACTIONS(552), 1,
      anon_sym_LF,
  [1950] = 1,
    ACTIONS(554), 1,
      aux_sym_latex_env_begin_token1,
  [1954] = 1,
    ACTIONS(556), 1,
      aux_sym_macro_token1,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(4)] = 0,
  [SMALL_STATE(5)] = 40,
  [SMALL_STATE(6)] = 80,
  [SMALL_STATE(7)] = 120,
  [SMALL_STATE(8)] = 160,
  [SMALL_STATE(9)] = 197,
  [SMALL_STATE(10)] = 234,
  [SMALL_STATE(11)] = 266,
  [SMALL_STATE(12)] = 298,
  [SMALL_STATE(13)] = 330,
  [SMALL_STATE(14)] = 362,
  [SMALL_STATE(15)] = 394,
  [SMALL_STATE(16)] = 426,
  [SMALL_STATE(17)] = 458,
  [SMALL_STATE(18)] = 490,
  [SMALL_STATE(19)] = 522,
  [SMALL_STATE(20)] = 554,
  [SMALL_STATE(21)] = 586,
  [SMALL_STATE(22)] = 618,
  [SMALL_STATE(23)] = 650,
  [SMALL_STATE(24)] = 682,
  [SMALL_STATE(25)] = 714,
  [SMALL_STATE(26)] = 746,
  [SMALL_STATE(27)] = 778,
  [SMALL_STATE(28)] = 810,
  [SMALL_STATE(29)] = 842,
  [SMALL_STATE(30)] = 874,
  [SMALL_STATE(31)] = 906,
  [SMALL_STATE(32)] = 938,
  [SMALL_STATE(33)] = 970,
  [SMALL_STATE(34)] = 1002,
  [SMALL_STATE(35)] = 1034,
  [SMALL_STATE(36)] = 1066,
  [SMALL_STATE(37)] = 1098,
  [SMALL_STATE(38)] = 1130,
  [SMALL_STATE(39)] = 1162,
  [SMALL_STATE(40)] = 1194,
  [SMALL_STATE(41)] = 1226,
  [SMALL_STATE(42)] = 1258,
  [SMALL_STATE(43)] = 1290,
  [SMALL_STATE(44)] = 1322,
  [SMALL_STATE(45)] = 1354,
  [SMALL_STATE(46)] = 1370,
  [SMALL_STATE(47)] = 1381,
  [SMALL_STATE(48)] = 1394,
  [SMALL_STATE(49)] = 1405,
  [SMALL_STATE(50)] = 1418,
  [SMALL_STATE(51)] = 1431,
  [SMALL_STATE(52)] = 1444,
  [SMALL_STATE(53)] = 1454,
  [SMALL_STATE(54)] = 1464,
  [SMALL_STATE(55)] = 1472,
  [SMALL_STATE(56)] = 1482,
  [SMALL_STATE(57)] = 1492,
  [SMALL_STATE(58)] = 1502,
  [SMALL_STATE(59)] = 1508,
  [SMALL_STATE(60)] = 1515,
  [SMALL_STATE(61)] = 1522,
  [SMALL_STATE(62)] = 1529,
  [SMALL_STATE(63)] = 1536,
  [SMALL_STATE(64)] = 1543,
  [SMALL_STATE(65)] = 1550,
  [SMALL_STATE(66)] = 1557,
  [SMALL_STATE(67)] = 1564,
  [SMALL_STATE(68)] = 1571,
  [SMALL_STATE(69)] = 1578,
  [SMALL_STATE(70)] = 1585,
  [SMALL_STATE(71)] = 1592,
  [SMALL_STATE(72)] = 1599,
  [SMALL_STATE(73)] = 1606,
  [SMALL_STATE(74)] = 1613,
  [SMALL_STATE(75)] = 1620,
  [SMALL_STATE(76)] = 1627,
  [SMALL_STATE(77)] = 1634,
  [SMALL_STATE(78)] = 1641,
  [SMALL_STATE(79)] = 1648,
  [SMALL_STATE(80)] = 1655,
  [SMALL_STATE(81)] = 1662,
  [SMALL_STATE(82)] = 1666,
  [SMALL_STATE(83)] = 1670,
  [SMALL_STATE(84)] = 1674,
  [SMALL_STATE(85)] = 1678,
  [SMALL_STATE(86)] = 1682,
  [SMALL_STATE(87)] = 1686,
  [SMALL_STATE(88)] = 1690,
  [SMALL_STATE(89)] = 1694,
  [SMALL_STATE(90)] = 1698,
  [SMALL_STATE(91)] = 1702,
  [SMALL_STATE(92)] = 1706,
  [SMALL_STATE(93)] = 1710,
  [SMALL_STATE(94)] = 1714,
  [SMALL_STATE(95)] = 1718,
  [SMALL_STATE(96)] = 1722,
  [SMALL_STATE(97)] = 1726,
  [SMALL_STATE(98)] = 1730,
  [SMALL_STATE(99)] = 1734,
  [SMALL_STATE(100)] = 1738,
  [SMALL_STATE(101)] = 1742,
  [SMALL_STATE(102)] = 1746,
  [SMALL_STATE(103)] = 1750,
  [SMALL_STATE(104)] = 1754,
  [SMALL_STATE(105)] = 1758,
  [SMALL_STATE(106)] = 1762,
  [SMALL_STATE(107)] = 1766,
  [SMALL_STATE(108)] = 1770,
  [SMALL_STATE(109)] = 1774,
  [SMALL_STATE(110)] = 1778,
  [SMALL_STATE(111)] = 1782,
  [SMALL_STATE(112)] = 1786,
  [SMALL_STATE(113)] = 1790,
  [SMALL_STATE(114)] = 1794,
  [SMALL_STATE(115)] = 1798,
  [SMALL_STATE(116)] = 1802,
  [SMALL_STATE(117)] = 1806,
  [SMALL_STATE(118)] = 1810,
  [SMALL_STATE(119)] = 1814,
  [SMALL_STATE(120)] = 1818,
  [SMALL_STATE(121)] = 1822,
  [SMALL_STATE(122)] = 1826,
  [SMALL_STATE(123)] = 1830,
  [SMALL_STATE(124)] = 1834,
  [SMALL_STATE(125)] = 1838,
  [SMALL_STATE(126)] = 1842,
  [SMALL_STATE(127)] = 1846,
  [SMALL_STATE(128)] = 1850,
  [SMALL_STATE(129)] = 1854,
  [SMALL_STATE(130)] = 1858,
  [SMALL_STATE(131)] = 1862,
  [SMALL_STATE(132)] = 1866,
  [SMALL_STATE(133)] = 1870,
  [SMALL_STATE(134)] = 1874,
  [SMALL_STATE(135)] = 1878,
  [SMALL_STATE(136)] = 1882,
  [SMALL_STATE(137)] = 1886,
  [SMALL_STATE(138)] = 1890,
  [SMALL_STATE(139)] = 1894,
  [SMALL_STATE(140)] = 1898,
  [SMALL_STATE(141)] = 1902,
  [SMALL_STATE(142)] = 1906,
  [SMALL_STATE(143)] = 1910,
  [SMALL_STATE(144)] = 1914,
  [SMALL_STATE(145)] = 1918,
  [SMALL_STATE(146)] = 1922,
  [SMALL_STATE(147)] = 1926,
  [SMALL_STATE(148)] = 1930,
  [SMALL_STATE(149)] = 1934,
  [SMALL_STATE(150)] = 1938,
  [SMALL_STATE(151)] = 1942,
  [SMALL_STATE(152)] = 1946,
  [SMALL_STATE(153)] = 1950,
  [SMALL_STATE(154)] = 1954,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_document, 0, 0, 0),
  [5] = {.entry = {.count = 1, .reusable = false}}, SHIFT(87),
  [7] = {.entry = {.count = 1, .reusable = false}}, SHIFT(3),
  [9] = {.entry = {.count = 1, .reusable = false}}, SHIFT(154),
  [11] = {.entry = {.count = 1, .reusable = false}}, SHIFT(153),
  [13] = {.entry = {.count = 1, .reusable = false}}, SHIFT(149),
  [15] = {.entry = {.count = 1, .reusable = false}}, SHIFT(148),
  [17] = {.entry = {.count = 1, .reusable = false}}, SHIFT(147),
  [19] = {.entry = {.count = 1, .reusable = false}}, SHIFT(146),
  [21] = {.entry = {.count = 1, .reusable = false}}, SHIFT(143),
  [23] = {.entry = {.count = 1, .reusable = false}}, SHIFT(51),
  [25] = {.entry = {.count = 1, .reusable = false}}, SHIFT(7),
  [27] = {.entry = {.count = 1, .reusable = false}}, SHIFT(141),
  [29] = {.entry = {.count = 1, .reusable = false}}, SHIFT(79),
  [31] = {.entry = {.count = 1, .reusable = false}}, SHIFT(136),
  [33] = {.entry = {.count = 1, .reusable = false}}, SHIFT(135),
  [35] = {.entry = {.count = 1, .reusable = false}}, SHIFT(134),
  [37] = {.entry = {.count = 1, .reusable = false}}, SHIFT(132),
  [39] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0),
  [41] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(87),
  [44] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(2),
  [47] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(154),
  [50] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(153),
  [53] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(149),
  [56] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(148),
  [59] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(147),
  [62] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(146),
  [65] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(143),
  [68] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(51),
  [71] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(7),
  [74] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(141),
  [77] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(79),
  [80] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(136),
  [83] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(135),
  [86] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(134),
  [89] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(132),
  [92] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_document, 1, 0, 0),
  [94] = {.entry = {.count = 1, .reusable = false}}, SHIFT(2),
  [96] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_list, 1, 0, 0),
  [98] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_list, 1, 0, 0),
  [100] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_table_repeat1, 2, 0, 0),
  [102] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_table_repeat1, 2, 0, 0),
  [104] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_table_repeat1, 2, 0, 0), SHIFT_REPEAT(51),
  [107] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_table_repeat1, 2, 0, 0), SHIFT_REPEAT(5),
  [110] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_list_repeat1, 2, 0, 0),
  [112] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_list_repeat1, 2, 0, 0),
  [114] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_list_repeat1, 2, 0, 0), SHIFT_REPEAT(148),
  [117] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_list_repeat1, 2, 0, 0), SHIFT_REPEAT(147),
  [120] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_table, 1, 0, 0),
  [122] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_table, 1, 0, 0),
  [124] = {.entry = {.count = 1, .reusable = false}}, SHIFT(5),
  [126] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_fixed_width_repeat1, 2, 0, 0),
  [128] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_fixed_width_repeat1, 2, 0, 0),
  [130] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_fixed_width_repeat1, 2, 0, 0), SHIFT_REPEAT(135),
  [133] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_fixed_width, 1, 0, 0),
  [135] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_fixed_width, 1, 0, 0),
  [137] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_block_end, 4, 0, 0),
  [139] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_block_end, 4, 0, 0),
  [141] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_headline, 5, 0, 5),
  [143] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_headline, 5, 0, 5),
  [145] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_macro, 7, 0, 0),
  [147] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_macro, 7, 0, 0),
  [149] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_headline, 7, 0, 13),
  [151] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_headline, 7, 0, 13),
  [153] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_headline, 3, 0, 0),
  [155] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_headline, 3, 0, 0),
  [157] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_directive, 6, 0, 12),
  [159] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_directive, 6, 0, 12),
  [161] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_fixed_width_repeat1, 3, 0, 0),
  [163] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_fixed_width_repeat1, 3, 0, 0),
  [165] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_comment, 3, 0, 0),
  [167] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_comment, 3, 0, 0),
  [169] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_link, 6, 0, 11),
  [171] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_link, 6, 0, 11),
  [173] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_headline, 6, 0, 10),
  [175] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_headline, 6, 0, 10),
  [177] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_headline, 6, 0, 9),
  [179] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_headline, 6, 0, 9),
  [181] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_drawer, 9, 0, 0),
  [183] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_drawer, 9, 0, 0),
  [185] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_drawer, 8, 0, 0),
  [187] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_drawer, 8, 0, 0),
  [189] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dynamic_block, 3, 0, 0),
  [191] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_dynamic_block, 3, 0, 0),
  [193] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_table_row, 3, 0, 0),
  [195] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_table_row, 3, 0, 0),
  [197] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_headline, 8, 0, 14),
  [199] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_headline, 8, 0, 14),
  [201] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_headline, 4, 0, 2),
  [203] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_headline, 4, 0, 2),
  [205] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_block_end, 3, 0, 0),
  [207] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_block_end, 3, 0, 0),
  [209] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_macro, 4, 0, 0),
  [211] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_macro, 4, 0, 0),
  [213] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_latex_env_end, 4, 0, 3),
  [215] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_latex_env_end, 4, 0, 3),
  [217] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_property_drawer, 7, 0, 0),
  [219] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_property_drawer, 7, 0, 0),
  [221] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_link, 4, 0, 0),
  [223] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_link, 4, 0, 0),
  [225] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_list_item, 4, 0, 0),
  [227] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_list_item, 4, 0, 0),
  [229] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_table_row, 2, 0, 0),
  [231] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_table_row, 2, 0, 0),
  [233] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_directive, 5, 0, 8),
  [235] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_directive, 5, 0, 8),
  [237] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dynamic_block, 2, 0, 0),
  [239] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_dynamic_block, 2, 0, 0),
  [241] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dynamic_block_end, 3, 0, 0),
  [243] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_dynamic_block_end, 3, 0, 0),
  [245] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_latex_env_end, 3, 0, 0),
  [247] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_latex_env_end, 3, 0, 0),
  [249] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_block, 3, 0, 0),
  [251] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_block, 3, 0, 0),
  [253] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_list_item, 5, 0, 0),
  [255] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_list_item, 5, 0, 0),
  [257] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_headline, 5, 0, 6),
  [259] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_headline, 5, 0, 6),
  [261] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_latex_environment, 3, 0, 0),
  [263] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_latex_environment, 3, 0, 0),
  [265] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_paragraph, 2, 0, 0),
  [267] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_paragraph, 2, 0, 0),
  [269] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_latex_environment, 2, 0, 0),
  [271] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_latex_environment, 2, 0, 0),
  [273] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_block, 2, 0, 0),
  [275] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_block, 2, 0, 0),
  [277] = {.entry = {.count = 1, .reusable = false}}, SHIFT(14),
  [279] = {.entry = {.count = 1, .reusable = false}}, SHIFT(109),
  [281] = {.entry = {.count = 1, .reusable = false}}, SHIFT(107),
  [283] = {.entry = {.count = 1, .reusable = false}}, SHIFT(106),
  [285] = {.entry = {.count = 1, .reusable = false}}, SHIFT(70),
  [287] = {.entry = {.count = 1, .reusable = true}}, SHIFT(126),
  [289] = {.entry = {.count = 1, .reusable = false}}, SHIFT(24),
  [291] = {.entry = {.count = 1, .reusable = false}}, SHIFT(49),
  [293] = {.entry = {.count = 1, .reusable = false}}, SHIFT(123),
  [295] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_property_drawer_repeat1, 2, 0, 0), SHIFT_REPEAT(70),
  [298] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_property_drawer_repeat1, 2, 0, 0),
  [300] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_table_row_repeat1, 2, 0, 0),
  [302] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_table_row_repeat1, 2, 0, 0), SHIFT_REPEAT(49),
  [305] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_table_row_repeat1, 2, 0, 0), SHIFT_REPEAT(123),
  [308] = {.entry = {.count = 1, .reusable = false}}, SHIFT(11),
  [310] = {.entry = {.count = 1, .reusable = false}}, SHIFT(111),
  [312] = {.entry = {.count = 1, .reusable = false}}, SHIFT(33),
  [314] = {.entry = {.count = 1, .reusable = false}}, SHIFT(47),
  [316] = {.entry = {.count = 1, .reusable = true}}, SHIFT(76),
  [318] = {.entry = {.count = 1, .reusable = false}}, SHIFT(75),
  [320] = {.entry = {.count = 1, .reusable = false}}, SHIFT(40),
  [322] = {.entry = {.count = 1, .reusable = true}}, SHIFT(70),
  [324] = {.entry = {.count = 1, .reusable = false}}, SHIFT(13),
  [326] = {.entry = {.count = 1, .reusable = true}}, SHIFT(78),
  [328] = {.entry = {.count = 1, .reusable = false}}, SHIFT(67),
  [330] = {.entry = {.count = 1, .reusable = true}}, SHIFT(68),
  [332] = {.entry = {.count = 1, .reusable = false}}, SHIFT(110),
  [334] = {.entry = {.count = 1, .reusable = true}}, SHIFT(96),
  [336] = {.entry = {.count = 1, .reusable = true}}, SHIFT(94),
  [338] = {.entry = {.count = 1, .reusable = false}}, SHIFT(61),
  [340] = {.entry = {.count = 1, .reusable = false}}, SHIFT(99),
  [342] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dynamic_block_begin, 4, 0, 4),
  [344] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_dynamic_block_begin, 4, 0, 4),
  [346] = {.entry = {.count = 1, .reusable = false}}, SHIFT(71),
  [348] = {.entry = {.count = 1, .reusable = false}}, SHIFT(119),
  [350] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dynamic_block_begin, 5, 0, 4),
  [352] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_dynamic_block_begin, 5, 0, 4),
  [354] = {.entry = {.count = 1, .reusable = false}}, SHIFT(137),
  [356] = {.entry = {.count = 1, .reusable = true}}, SHIFT(138),
  [358] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_latex_env_begin, 4, 0, 3),
  [360] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_latex_env_begin, 4, 0, 3),
  [362] = {.entry = {.count = 1, .reusable = false}}, SHIFT(89),
  [364] = {.entry = {.count = 1, .reusable = false}}, SHIFT(69),
  [366] = {.entry = {.count = 1, .reusable = true}}, SHIFT(82),
  [368] = {.entry = {.count = 1, .reusable = true}}, SHIFT(85),
  [370] = {.entry = {.count = 1, .reusable = true}}, SHIFT(110),
  [372] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_block_begin, 3, 0, 1),
  [374] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_block_begin, 3, 0, 1),
  [376] = {.entry = {.count = 1, .reusable = true}}, SHIFT(124),
  [378] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_block_begin, 5, 0, 7),
  [380] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_block_begin, 5, 0, 7),
  [382] = {.entry = {.count = 1, .reusable = true}}, SHIFT(103),
  [384] = {.entry = {.count = 1, .reusable = true}}, SHIFT(98),
  [386] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_property, 6, 0, 0),
  [388] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_property, 6, 0, 0),
  [390] = {.entry = {.count = 1, .reusable = false}}, SHIFT(100),
  [392] = {.entry = {.count = 1, .reusable = false}}, SHIFT(101),
  [394] = {.entry = {.count = 1, .reusable = true}}, SHIFT(83),
  [396] = {.entry = {.count = 1, .reusable = false}}, SHIFT(84),
  [398] = {.entry = {.count = 1, .reusable = true}}, SHIFT(75),
  [400] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_block_begin, 6, 0, 7),
  [402] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_block_begin, 6, 0, 7),
  [404] = {.entry = {.count = 1, .reusable = true}}, SHIFT(67),
  [406] = {.entry = {.count = 1, .reusable = true}}, SHIFT(120),
  [408] = {.entry = {.count = 1, .reusable = true}}, SHIFT(151),
  [410] = {.entry = {.count = 1, .reusable = true}}, SHIFT(88),
  [412] = {.entry = {.count = 1, .reusable = true}}, SHIFT(105),
  [414] = {.entry = {.count = 1, .reusable = true}}, SHIFT(27),
  [416] = {.entry = {.count = 1, .reusable = true}}, SHIFT(108),
  [418] = {.entry = {.count = 1, .reusable = true}}, SHIFT(37),
  [420] = {.entry = {.count = 1, .reusable = true}}, SHIFT(36),
  [422] = {.entry = {.count = 1, .reusable = true}}, SHIFT(45),
  [424] = {.entry = {.count = 1, .reusable = true}}, SHIFT(102),
  [426] = {.entry = {.count = 1, .reusable = true}}, SHIFT(62),
  [428] = {.entry = {.count = 1, .reusable = true}}, SHIFT(115),
  [430] = {.entry = {.count = 1, .reusable = true}}, SHIFT(32),
  [432] = {.entry = {.count = 1, .reusable = true}}, SHIFT(95),
  [434] = {.entry = {.count = 1, .reusable = true}}, SHIFT(116),
  [436] = {.entry = {.count = 1, .reusable = true}}, SHIFT(31),
  [438] = {.entry = {.count = 1, .reusable = true}}, SHIFT(39),
  [440] = {.entry = {.count = 1, .reusable = true}}, SHIFT(93),
  [442] = {.entry = {.count = 1, .reusable = true}}, SHIFT(65),
  [444] = {.entry = {.count = 1, .reusable = true}}, SHIFT(28),
  [446] = {.entry = {.count = 1, .reusable = true}}, SHIFT(63),
  [448] = {.entry = {.count = 1, .reusable = true}}, SHIFT(34),
  [450] = {.entry = {.count = 1, .reusable = true}}, SHIFT(122),
  [452] = {.entry = {.count = 1, .reusable = true}}, SHIFT(64),
  [454] = {.entry = {.count = 1, .reusable = true}}, SHIFT(90),
  [456] = {.entry = {.count = 1, .reusable = true}}, SHIFT(26),
  [458] = {.entry = {.count = 1, .reusable = true}}, SHIFT(29),
  [460] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_title, 1, 0, 0),
  [462] = {.entry = {.count = 1, .reusable = true}}, SHIFT(53),
  [464] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
  [466] = {.entry = {.count = 1, .reusable = true}}, SHIFT(50),
  [468] = {.entry = {.count = 1, .reusable = true}}, SHIFT(86),
  [470] = {.entry = {.count = 1, .reusable = true}}, SHIFT(55),
  [472] = {.entry = {.count = 1, .reusable = true}}, SHIFT(20),
  [474] = {.entry = {.count = 1, .reusable = true}}, SHIFT(54),
  [476] = {.entry = {.count = 1, .reusable = true}}, SHIFT(19),
  [478] = {.entry = {.count = 1, .reusable = true}}, SHIFT(133),
  [480] = {.entry = {.count = 1, .reusable = true}}, SHIFT(18),
  [482] = {.entry = {.count = 1, .reusable = true}}, SHIFT(16),
  [484] = {.entry = {.count = 1, .reusable = true}}, SHIFT(17),
  [486] = {.entry = {.count = 1, .reusable = true}}, SHIFT(77),
  [488] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_drawer_name, 1, 0, 0),
  [490] = {.entry = {.count = 1, .reusable = true}}, SHIFT(74),
  [492] = {.entry = {.count = 1, .reusable = true}}, SHIFT(15),
  [494] = {.entry = {.count = 1, .reusable = true}}, SHIFT(58),
  [496] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_key, 1, 0, 0),
  [498] = {.entry = {.count = 1, .reusable = true}}, SHIFT(139),
  [500] = {.entry = {.count = 1, .reusable = true}}, SHIFT(140),
  [502] = {.entry = {.count = 1, .reusable = true}}, SHIFT(60),
  [504] = {.entry = {.count = 1, .reusable = true}}, SHIFT(91),
  [506] = {.entry = {.count = 1, .reusable = true}}, SHIFT(92),
  [508] = {.entry = {.count = 1, .reusable = true}}, SHIFT(97),
  [510] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [512] = {.entry = {.count = 1, .reusable = true}}, SHIFT(42),
  [514] = {.entry = {.count = 1, .reusable = true}}, SHIFT(12),
  [516] = {.entry = {.count = 1, .reusable = true}}, SHIFT(113),
  [518] = {.entry = {.count = 1, .reusable = true}}, SHIFT(117),
  [520] = {.entry = {.count = 1, .reusable = true}}, SHIFT(118),
  [522] = {.entry = {.count = 1, .reusable = true}}, SHIFT(144),
  [524] = {.entry = {.count = 1, .reusable = true}}, SHIFT(145),
  [526] = {.entry = {.count = 1, .reusable = true}}, SHIFT(80),
  [528] = {.entry = {.count = 1, .reusable = true}}, SHIFT(30),
  [530] = {.entry = {.count = 1, .reusable = true}}, SHIFT(121),
  [532] = {.entry = {.count = 1, .reusable = true}}, SHIFT(25),
  [534] = {.entry = {.count = 1, .reusable = true}}, SHIFT(127),
  [536] = {.entry = {.count = 1, .reusable = true}}, SHIFT(22),
  [538] = {.entry = {.count = 1, .reusable = true}}, SHIFT(150),
  [540] = {.entry = {.count = 1, .reusable = true}}, SHIFT(66),
  [542] = {.entry = {.count = 1, .reusable = true}}, SHIFT(128),
  [544] = {.entry = {.count = 1, .reusable = true}}, SHIFT(129),
  [546] = {.entry = {.count = 1, .reusable = true}}, SHIFT(59),
  [548] = {.entry = {.count = 1, .reusable = true}}, SHIFT(21),
  [550] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_value, 1, 0, 0),
  [552] = {.entry = {.count = 1, .reusable = true}}, SHIFT(73),
  [554] = {.entry = {.count = 1, .reusable = true}}, SHIFT(130),
  [556] = {.entry = {.count = 1, .reusable = true}}, SHIFT(72),
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
