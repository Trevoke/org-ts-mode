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
#define STATE_COUNT 152
#define LARGE_STATE_COUNT 4
#define SYMBOL_COUNT 97
#define ALIAS_COUNT 1
#define TOKEN_COUNT 61
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 7
#define MAX_ALIAS_SEQUENCE_LENGTH 9
#define PRODUCTION_ID_COUNT 15

enum ts_symbol_identifiers {
  anon_sym_SPACE = 1,
  anon_sym_LF = 2,
  sym_stars = 3,
  sym_keyword = 4,
  sym_priority = 5,
  sym_comment_keyword = 6,
  aux_sym_title_token1 = 7,
  sym_planning_line = 8,
  sym_clock = 9,
  sym_diary_sexp = 10,
  sym_timestamp = 11,
  anon_sym_LBRACE_LBRACE_LBRACE = 12,
  aux_sym_macro_token1 = 13,
  anon_sym_LPAREN = 14,
  aux_sym_macro_token2 = 15,
  anon_sym_RPAREN = 16,
  anon_sym_RBRACE_RBRACE_RBRACE = 17,
  sym_footnote_reference = 18,
  sym_latex_fragment = 19,
  anon_sym_BSLASHbegin_LBRACE = 20,
  aux_sym_latex_env_begin_token1 = 21,
  anon_sym_RBRACE = 22,
  sym_latex_env_content = 23,
  anon_sym_BSLASHend_LBRACE = 24,
  sym_entity = 25,
  sym_subscript = 26,
  sym_superscript = 27,
  anon_sym_LBRACK_LBRACK = 28,
  aux_sym_link_token1 = 29,
  anon_sym_RBRACK_LBRACK = 30,
  anon_sym_RBRACK_RBRACK = 31,
  aux_sym_list_item_token1 = 32,
  aux_sym_list_item_token2 = 33,
  sym_bullet = 34,
  aux_sym_block_begin_token1 = 35,
  sym_block_type = 36,
  sym_language = 37,
  sym_block_content = 38,
  aux_sym_block_end_token1 = 39,
  aux_sym_dynamic_block_begin_token1 = 40,
  aux_sym_dynamic_block_begin_token2 = 41,
  sym_dynamic_block_content = 42,
  aux_sym_dynamic_block_end_token1 = 43,
  anon_sym_PIPE = 44,
  sym_table_cell = 45,
  sym_table_separator = 46,
  aux_sym_directive_token1 = 47,
  anon_sym_COLON = 48,
  sym_name = 49,
  aux_sym_comment_token1 = 50,
  aux_sym_fixed_width_token1 = 51,
  anon_sym_COLONPROPERTIES_COLON = 52,
  aux_sym_property_drawer_token1 = 53,
  anon_sym_COLONEND_COLON = 54,
  aux_sym_key_token1 = 55,
  anon_sym_COLONend_COLON = 56,
  sym_drawer_content = 57,
  sym_horizontal_rule = 58,
  aux_sym_paragraph_token1 = 59,
  aux_sym_paragraph_token2 = 60,
  sym_document = 61,
  sym__element = 62,
  sym_headline = 63,
  sym__headline_prefix = 64,
  sym_title = 65,
  sym_macro = 66,
  sym_latex_environment = 67,
  sym_latex_env_begin = 68,
  sym_latex_env_end = 69,
  sym_link = 70,
  sym_list = 71,
  sym_list_item = 72,
  sym_block = 73,
  sym_block_begin = 74,
  sym_block_end = 75,
  sym_dynamic_block = 76,
  sym_dynamic_block_begin = 77,
  sym_dynamic_block_end = 78,
  sym_table = 79,
  sym_table_row = 80,
  sym_directive = 81,
  sym_comment = 82,
  sym_fixed_width = 83,
  sym_property_drawer = 84,
  sym_property = 85,
  sym_key = 86,
  sym_value = 87,
  sym_drawer = 88,
  sym_drawer_name = 89,
  sym_paragraph = 90,
  aux_sym_document_repeat1 = 91,
  aux_sym_list_repeat1 = 92,
  aux_sym_table_repeat1 = 93,
  aux_sym_table_row_repeat1 = 94,
  aux_sym_fixed_width_repeat1 = 95,
  aux_sym_property_drawer_repeat1 = 96,
  alias_sym_link_description = 97,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [anon_sym_SPACE] = " ",
  [anon_sym_LF] = "\n",
  [sym_stars] = "stars",
  [sym_keyword] = "keyword",
  [sym_priority] = "priority",
  [sym_comment_keyword] = "comment_keyword",
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
  [sym__headline_prefix] = "_headline_prefix",
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
  [sym_comment_keyword] = sym_comment_keyword,
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
  [sym__headline_prefix] = sym__headline_prefix,
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
  [sym_comment_keyword] = {
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
  [sym__headline_prefix] = {
    .visible = false,
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
  field_comment = 1,
  field_keyword = 2,
  field_language = 3,
  field_name = 4,
  field_priority = 5,
  field_title = 6,
  field_type = 7,
};

static const char * const ts_field_names[] = {
  [0] = NULL,
  [field_comment] = "comment",
  [field_keyword] = "keyword",
  [field_language] = "language",
  [field_name] = "name",
  [field_priority] = "priority",
  [field_title] = "title",
  [field_type] = "type",
};

static const TSFieldMapSlice ts_field_map_slices[PRODUCTION_ID_COUNT] = {
  [1] = {.index = 0, .length = 2},
  [2] = {.index = 2, .length = 1},
  [3] = {.index = 3, .length = 3},
  [4] = {.index = 6, .length = 3},
  [5] = {.index = 9, .length = 1},
  [6] = {.index = 10, .length = 1},
  [7] = {.index = 11, .length = 1},
  [8] = {.index = 12, .length = 1},
  [9] = {.index = 13, .length = 2},
  [11] = {.index = 15, .length = 4},
  [12] = {.index = 19, .length = 2},
};

static const TSFieldMapEntry ts_field_map_entries[] = {
  [0] =
    {field_keyword, 0, .inherited = true},
    {field_priority, 0, .inherited = true},
  [2] =
    {field_type, 1},
  [3] =
    {field_comment, 1},
    {field_keyword, 0, .inherited = true},
    {field_priority, 0, .inherited = true},
  [6] =
    {field_keyword, 0, .inherited = true},
    {field_priority, 0, .inherited = true},
    {field_title, 1},
  [9] =
    {field_keyword, 2},
  [10] =
    {field_priority, 2},
  [11] =
    {field_name, 1},
  [12] =
    {field_name, 2},
  [13] =
    {field_language, 3},
    {field_type, 1},
  [15] =
    {field_comment, 1},
    {field_keyword, 0, .inherited = true},
    {field_priority, 0, .inherited = true},
    {field_title, 3},
  [19] =
    {field_keyword, 2},
    {field_priority, 4},
};

static const TSSymbol ts_alias_sequences[PRODUCTION_ID_COUNT][MAX_ALIAS_SEQUENCE_LENGTH] = {
  [0] = {0},
  [10] = {
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
        '(', 272,
        ')', 275,
        '*', 192,
        '-', 56,
        ':', 331,
        '<', 173,
        'C', 240,
        'D', 262,
        'N', 245,
        'T', 260,
        'W', 241,
        '[', 33,
        '\\', 109,
        ']', 93,
        '_', 310,
        '{', 125,
        '|', 323,
        '}', 285,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(0);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(267);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(268);
      END_STATE();
    case 1:
      if (lookahead == '\n') ADVANCE(327);
      if (lookahead == '+') ADVANCE(51);
      if (lookahead == '-') ADVANCE(1);
      if (lookahead == '|') ADVANCE(2);
      END_STATE();
    case 2:
      if (lookahead == '\n') ADVANCE(327);
      if (lookahead == '-') ADVANCE(1);
      END_STATE();
    case 3:
      if (lookahead == '\n') ADVANCE(278);
      END_STATE();
    case 4:
      if (lookahead == '\n') ADVANCE(237);
      END_STATE();
    case 5:
      if (lookahead == '\n') ADVANCE(45);
      if (lookahead == '(') ADVANCE(5);
      if (lookahead == ')') ADVANCE(7);
      if (lookahead != 0) ADVANCE(5);
      END_STATE();
    case 6:
      if (lookahead == '\n') ADVANCE(236);
      END_STATE();
    case 7:
      if (lookahead == '\n') ADVANCE(236);
      if (lookahead == '(') ADVANCE(5);
      if (lookahead == ')') ADVANCE(6);
      if (lookahead != 0) ADVANCE(44);
      END_STATE();
    case 8:
      if (lookahead == '\n') ADVANCE(347);
      if (lookahead == '-') ADVANCE(8);
      END_STATE();
    case 9:
      if (lookahead == '\n') ADVANCE(277);
      END_STATE();
    case 10:
      if (lookahead == '\n') ADVANCE(289);
      END_STATE();
    case 11:
      if (lookahead == '\n') ADVANCE(289);
      if (lookahead == 'e') ADVANCE(12);
      if (lookahead == '{') ADVANCE(128);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(16);
      END_STATE();
    case 12:
      if (lookahead == '\n') ADVANCE(289);
      if (lookahead == 'g') ADVANCE(13);
      if (lookahead == '{') ADVANCE(128);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(16);
      END_STATE();
    case 13:
      if (lookahead == '\n') ADVANCE(289);
      if (lookahead == 'i') ADVANCE(14);
      if (lookahead == '{') ADVANCE(128);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(16);
      END_STATE();
    case 14:
      if (lookahead == '\n') ADVANCE(289);
      if (lookahead == 'n') ADVANCE(15);
      if (lookahead == '{') ADVANCE(128);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(16);
      END_STATE();
    case 15:
      if (lookahead == '\n') ADVANCE(289);
      if (lookahead == '{') ADVANCE(280);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(16);
      END_STATE();
    case 16:
      if (lookahead == '\n') ADVANCE(289);
      if (lookahead == '{') ADVANCE(128);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(16);
      END_STATE();
    case 17:
      if (lookahead == '\n') ADVANCE(291);
      if (lookahead != 0) ADVANCE(17);
      END_STATE();
    case 18:
      if (lookahead == '\n') ADVANCE(290);
      if (lookahead != 0) ADVANCE(18);
      END_STATE();
    case 19:
      if (lookahead == '\n') ADVANCE(235);
      END_STATE();
    case 20:
      if (lookahead == '\n') ADVANCE(235);
      if (lookahead == '-') ADVANCE(52);
      END_STATE();
    case 21:
      if (lookahead == '\n') ADVANCE(185);
      if (lookahead == 'C') ADVANCE(201);
      if (lookahead == 'D') ADVANCE(224);
      if (lookahead == 'N') ADVANCE(207);
      if (lookahead == 'T') ADVANCE(223);
      if (lookahead == 'W') ADVANCE(202);
      if (lookahead == '[') ADVANCE(200);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(197);
      if (lookahead != 0) ADVANCE(233);
      END_STATE();
    case 22:
      if (lookahead == '\n') ADVANCE(186);
      if (lookahead == '|') ADVANCE(322);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(325);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 23:
      if (lookahead == '\n') ADVANCE(187);
      if (lookahead == 'C') ADVANCE(222);
      if (lookahead == '[') ADVANCE(200);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(198);
      if (lookahead != 0) ADVANCE(233);
      END_STATE();
    case 24:
      if (lookahead == '\n') ADVANCE(188);
      if (lookahead == 'C') ADVANCE(222);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(199);
      if (lookahead != 0) ADVANCE(233);
      END_STATE();
    case 25:
      if (lookahead == '\n') SKIP(25);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(231);
      if (lookahead != 0) ADVANCE(233);
      END_STATE();
    case 26:
      if (lookahead == '\n') ADVANCE(189);
      if (lookahead == ' ') ADVANCE(183);
      if (('\t' <= lookahead && lookahead <= '\r')) SKIP(26);
      END_STATE();
    case 27:
      if (lookahead == '\n') SKIP(27);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(230);
      if ((0x0b <= lookahead && lookahead <= '\r')) ADVANCE(230);
      if (lookahead != 0) ADVANCE(233);
      END_STATE();
    case 28:
      if (lookahead == '\n') ADVANCE(190);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(28);
      END_STATE();
    case 29:
      if (lookahead == '\n') SKIP(29);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(294);
      if (lookahead != 0 &&
          lookahead != ']') ADVANCE(295);
      END_STATE();
    case 30:
      if (lookahead == '\n') ADVANCE(464);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(30);
      END_STATE();
    case 31:
      if (lookahead == ' ') ADVANCE(335);
      if (lookahead == '+') ADVANCE(328);
      END_STATE();
    case 32:
      if (lookahead == ' ') ADVANCE(184);
      if (('\t' <= lookahead && lookahead <= '\r')) SKIP(32);
      END_STATE();
    case 33:
      if (lookahead == '#') ADVANCE(171);
      if (lookahead == '[') ADVANCE(292);
      if (lookahead == 'f') ADVANCE(117);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(97);
      END_STATE();
    case 34:
      if (lookahead == '#') ADVANCE(47);
      if (lookahead == ':') ADVANCE(333);
      if (lookahead == '|') ADVANCE(322);
      if (lookahead == '}') ADVANCE(284);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(34);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(283);
      END_STATE();
    case 35:
      if (lookahead == '#') ADVANCE(46);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(319);
      if (lookahead != 0) ADVANCE(320);
      END_STATE();
    case 36:
      if (lookahead == '#') ADVANCE(48);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(313);
      if (lookahead != 0) ADVANCE(314);
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
      if (lookahead == '(') ADVANCE(272);
      if (lookahead == ':') ADVANCE(330);
      if (lookahead == '}') ADVANCE(126);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(42);
      if (lookahead == '-' ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(343);
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
      if (lookahead != 0) ADVANCE(320);
      END_STATE();
    case 47:
      if (lookahead == '+') ADVANCE(146);
      END_STATE();
    case 48:
      if (lookahead == '+') ADVANCE(147);
      if (lookahead != 0) ADVANCE(314);
      END_STATE();
    case 49:
      if (lookahead == '+') ADVANCE(150);
      if (lookahead != 0) ADVANCE(320);
      END_STATE();
    case 50:
      if (lookahead == '+') ADVANCE(151);
      if (lookahead != 0) ADVANCE(314);
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
      if (lookahead == ':') ADVANCE(316);
      if (lookahead == '_') ADVANCE(308);
      END_STATE();
    case 61:
      if (lookahead == ':') ADVANCE(339);
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
      if (lookahead == ':') ADVANCE(342);
      END_STATE();
    case 64:
      if (lookahead == ':') ADVANCE(321);
      if (lookahead == '_') ADVANCE(315);
      END_STATE();
    case 65:
      if (lookahead == ':') ADVANCE(321);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(320);
      END_STATE();
    case 66:
      if (lookahead == ':') ADVANCE(344);
      END_STATE();
    case 67:
      if (lookahead == ':') ADVANCE(344);
      if (lookahead != 0) ADVANCE(346);
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
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(312);
      END_STATE();
    case 69:
      if (lookahead == ':') ADVANCE(169);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(69);
      END_STATE();
    case 70:
      if (lookahead == ':') ADVANCE(81);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(345);
      if (lookahead != 0) ADVANCE(346);
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
      if (lookahead != 0) ADVANCE(287);
      END_STATE();
    case 76:
      if (lookahead == 'D') ADVANCE(177);
      if (lookahead == 'd') ADVANCE(67);
      if (lookahead != 0) ADVANCE(346);
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
      if (lookahead == 'E') ADVANCE(160);
      if (lookahead == 'e') ADVANCE(84);
      if (lookahead != 0) ADVANCE(287);
      END_STATE();
    case 81:
      if (lookahead == 'E') ADVANCE(161);
      if (lookahead == 'e') ADVANCE(85);
      if (lookahead != 0) ADVANCE(346);
      END_STATE();
    case 82:
      if (lookahead == 'I') ADVANCE(78);
      END_STATE();
    case 83:
      if (lookahead == 'N') ADVANCE(77);
      END_STATE();
    case 84:
      if (lookahead == 'N') ADVANCE(141);
      if (lookahead == 'n') ADVANCE(75);
      if (lookahead != 0) ADVANCE(287);
      END_STATE();
    case 85:
      if (lookahead == 'N') ADVANCE(142);
      if (lookahead == 'n') ADVANCE(76);
      if (lookahead != 0) ADVANCE(346);
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
      if (lookahead == '[') ADVANCE(292);
      if (lookahead == 'f') ADVANCE(117);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(97);
      END_STATE();
    case 93:
      if (lookahead == '[') ADVANCE(296);
      if (lookahead == ']') ADVANCE(297);
      END_STATE();
    case 94:
      if (lookahead == '[') ADVANCE(168);
      END_STATE();
    case 95:
      if (lookahead == '\\') ADVANCE(80);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(286);
      if (lookahead != 0) ADVANCE(287);
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
          lookahead == '.') ADVANCE(304);
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
          lookahead == '.') ADVANCE(304);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(102);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(107);
      END_STATE();
    case 103:
      if (lookahead == '^') ADVANCE(174);
      if (lookahead == '_') ADVANCE(175);
      if (lookahead == ')' ||
          lookahead == '.') ADVANCE(304);
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
      if (lookahead == '_') ADVANCE(315);
      if (lookahead != 0) ADVANCE(314);
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
      if (lookahead == '{') ADVANCE(238);
      END_STATE();
    case 122:
      if (lookahead == '{') ADVANCE(288);
      END_STATE();
    case 123:
      if (lookahead == '{') ADVANCE(288);
      if (lookahead != 0) ADVANCE(287);
      END_STATE();
    case 124:
      if (lookahead == '{') ADVANCE(279);
      END_STATE();
    case 125:
      if (lookahead == '{') ADVANCE(121);
      END_STATE();
    case 126:
      if (lookahead == '}') ADVANCE(127);
      END_STATE();
    case 127:
      if (lookahead == '}') ADVANCE(276);
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
          lookahead == ' ') ADVANCE(299);
      if (('\n' <= lookahead && lookahead <= '\r')) SKIP(133);
      END_STATE();
    case 134:
      if (lookahead == ')' ||
          lookahead == '.') ADVANCE(304);
      END_STATE();
    case 135:
      if (lookahead == ')' ||
          lookahead == '.') ADVANCE(304);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(135);
      END_STATE();
    case 136:
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(304);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(136);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(135);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(134);
      END_STATE();
    case 137:
      if (lookahead == 'D' ||
          lookahead == 'd') ADVANCE(65);
      if (lookahead != 0) ADVANCE(320);
      END_STATE();
    case 138:
      if (lookahead == 'D' ||
          lookahead == 'd') ADVANCE(172);
      if (lookahead != 0) ADVANCE(320);
      END_STATE();
    case 139:
      if (lookahead == 'D' ||
          lookahead == 'd') ADVANCE(108);
      if (lookahead != 0) ADVANCE(314);
      END_STATE();
    case 140:
      if (lookahead == 'D' ||
          lookahead == 'd') ADVANCE(179);
      if (lookahead != 0) ADVANCE(314);
      END_STATE();
    case 141:
      if (lookahead == 'D' ||
          lookahead == 'd') ADVANCE(180);
      if (lookahead != 0) ADVANCE(287);
      END_STATE();
    case 142:
      if (lookahead == 'D' ||
          lookahead == 'd') ADVANCE(177);
      if (lookahead != 0) ADVANCE(346);
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
      if (lookahead != 0) ADVANCE(320);
      END_STATE();
    case 146:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(155);
      END_STATE();
    case 147:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(158);
      if (lookahead != 0) ADVANCE(314);
      END_STATE();
    case 148:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(160);
      if (lookahead != 0) ADVANCE(287);
      END_STATE();
    case 149:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(161);
      if (lookahead != 0) ADVANCE(346);
      END_STATE();
    case 150:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(157);
      if (lookahead != 0) ADVANCE(320);
      END_STATE();
    case 151:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(159);
      if (lookahead != 0) ADVANCE(314);
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
      if (lookahead != 0) ADVANCE(320);
      END_STATE();
    case 157:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(138);
      if (lookahead != 0) ADVANCE(320);
      END_STATE();
    case 158:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(139);
      if (lookahead != 0) ADVANCE(314);
      END_STATE();
    case 159:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(140);
      if (lookahead != 0) ADVANCE(314);
      END_STATE();
    case 160:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(141);
      if (lookahead != 0) ADVANCE(287);
      END_STATE();
    case 161:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(142);
      if (lookahead != 0) ADVANCE(346);
      END_STATE();
    case 162:
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(273);
      if (lookahead != 0 &&
          lookahead != ')' &&
          lookahead != '}') ADVANCE(274);
      END_STATE();
    case 163:
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(163);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(318);
      END_STATE();
    case 164:
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(164);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(334);
      END_STATE();
    case 165:
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(165);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(311);
      END_STATE();
    case 166:
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(166);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(271);
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
          lookahead != ':') ADVANCE(320);
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
          lookahead != ':') ADVANCE(346);
      END_STATE();
    case 178:
      if (lookahead != 0 &&
          lookahead != ']') ADVANCE(100);
      END_STATE();
    case 179:
      if (lookahead != 0 &&
          lookahead != '_') ADVANCE(314);
      END_STATE();
    case 180:
      if (lookahead != 0 &&
          lookahead != '{') ADVANCE(287);
      END_STATE();
    case 181:
      if (eof) ADVANCE(182);
      if (lookahead == '\n') SKIP(181);
      if (lookahead == '#') ADVANCE(31);
      if (lookahead == '$') ADVANCE(375);
      if (lookahead == '%') ADVANCE(378);
      if (lookahead == '*') ADVANCE(192);
      if (lookahead == '+') ADVANCE(304);
      if (lookahead == '-') ADVANCE(306);
      if (lookahead == ':') ADVANCE(331);
      if (lookahead == '<') ADVANCE(397);
      if (lookahead == 'C') ADVANCE(416);
      if (lookahead == 'D') ADVANCE(407);
      if (lookahead == 'S') ADVANCE(403);
      if (lookahead == '[') ADVANCE(92);
      if (lookahead == '\\') ADVANCE(110);
      if (lookahead == 'c') ADVANCE(101);
      if (lookahead == '{') ADVANCE(125);
      if (lookahead == '|') ADVANCE(323);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(298);
      if ((0x0b <= lookahead && lookahead <= '\r')) ADVANCE(374);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(102);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(438);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(103);
      if (lookahead != 0) ADVANCE(461);
      END_STATE();
    case 182:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 183:
      ACCEPT_TOKEN(anon_sym_SPACE);
      if (lookahead == '\n') ADVANCE(189);
      if (lookahead == ' ') ADVANCE(183);
      END_STATE();
    case 184:
      ACCEPT_TOKEN(anon_sym_SPACE);
      if (lookahead == ' ') ADVANCE(184);
      END_STATE();
    case 185:
      ACCEPT_TOKEN(anon_sym_LF);
      if (lookahead == '\n') ADVANCE(185);
      if (lookahead == 'C') ADVANCE(201);
      if (lookahead == 'D') ADVANCE(224);
      if (lookahead == 'N') ADVANCE(207);
      if (lookahead == 'T') ADVANCE(223);
      if (lookahead == 'W') ADVANCE(202);
      if (lookahead == '[') ADVANCE(200);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(197);
      END_STATE();
    case 186:
      ACCEPT_TOKEN(anon_sym_LF);
      if (lookahead == '\n') ADVANCE(186);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(325);
      END_STATE();
    case 187:
      ACCEPT_TOKEN(anon_sym_LF);
      if (lookahead == '\n') ADVANCE(187);
      if (lookahead == 'C') ADVANCE(222);
      if (lookahead == '[') ADVANCE(200);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(198);
      END_STATE();
    case 188:
      ACCEPT_TOKEN(anon_sym_LF);
      if (lookahead == '\n') ADVANCE(188);
      if (lookahead == 'C') ADVANCE(222);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(199);
      END_STATE();
    case 189:
      ACCEPT_TOKEN(anon_sym_LF);
      if (lookahead == '\n') ADVANCE(189);
      if (lookahead == ' ') ADVANCE(183);
      END_STATE();
    case 190:
      ACCEPT_TOKEN(anon_sym_LF);
      if (lookahead == '\n') ADVANCE(190);
      END_STATE();
    case 191:
      ACCEPT_TOKEN(anon_sym_LF);
      if (lookahead == '\n') ADVANCE(191);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(300);
      END_STATE();
    case 192:
      ACCEPT_TOKEN(sym_stars);
      if (lookahead == '*') ADVANCE(192);
      END_STATE();
    case 193:
      ACCEPT_TOKEN(sym_stars);
      if (lookahead == '*') ADVANCE(193);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(461);
      END_STATE();
    case 194:
      ACCEPT_TOKEN(sym_keyword);
      END_STATE();
    case 195:
      ACCEPT_TOKEN(sym_priority);
      END_STATE();
    case 196:
      ACCEPT_TOKEN(sym_comment_keyword);
      END_STATE();
    case 197:
      ACCEPT_TOKEN(aux_sym_title_token1);
      if (lookahead == '\n') ADVANCE(185);
      if (lookahead == 'C') ADVANCE(201);
      if (lookahead == 'D') ADVANCE(224);
      if (lookahead == 'N') ADVANCE(207);
      if (lookahead == 'T') ADVANCE(223);
      if (lookahead == 'W') ADVANCE(202);
      if (lookahead == '[') ADVANCE(200);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(197);
      if (lookahead != 0) ADVANCE(233);
      END_STATE();
    case 198:
      ACCEPT_TOKEN(aux_sym_title_token1);
      if (lookahead == '\n') ADVANCE(187);
      if (lookahead == 'C') ADVANCE(222);
      if (lookahead == '[') ADVANCE(200);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(198);
      if (lookahead != 0) ADVANCE(233);
      END_STATE();
    case 199:
      ACCEPT_TOKEN(aux_sym_title_token1);
      if (lookahead == '\n') ADVANCE(188);
      if (lookahead == 'C') ADVANCE(222);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(199);
      if (lookahead != 0) ADVANCE(233);
      END_STATE();
    case 200:
      ACCEPT_TOKEN(aux_sym_title_token1);
      if (lookahead == '#') ADVANCE(232);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(233);
      END_STATE();
    case 201:
      ACCEPT_TOKEN(aux_sym_title_token1);
      if (lookahead == 'A') ADVANCE(217);
      if (lookahead == 'O') ADVANCE(215);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(233);
      END_STATE();
    case 202:
      ACCEPT_TOKEN(aux_sym_title_token1);
      if (lookahead == 'A') ADVANCE(212);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(233);
      END_STATE();
    case 203:
      ACCEPT_TOKEN(aux_sym_title_token1);
      if (lookahead == 'C') ADVANCE(208);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(233);
      END_STATE();
    case 204:
      ACCEPT_TOKEN(aux_sym_title_token1);
      if (lookahead == 'D') ADVANCE(194);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(233);
      END_STATE();
    case 205:
      ACCEPT_TOKEN(aux_sym_title_token1);
      if (lookahead == 'D') ADVANCE(221);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(233);
      END_STATE();
    case 206:
      ACCEPT_TOKEN(aux_sym_title_token1);
      if (lookahead == 'E') ADVANCE(194);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(233);
      END_STATE();
    case 207:
      ACCEPT_TOKEN(aux_sym_title_token1);
      if (lookahead == 'E') ADVANCE(228);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(233);
      END_STATE();
    case 208:
      ACCEPT_TOKEN(aux_sym_title_token1);
      if (lookahead == 'E') ADVANCE(214);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(233);
      END_STATE();
    case 209:
      ACCEPT_TOKEN(aux_sym_title_token1);
      if (lookahead == 'E') ADVANCE(204);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(233);
      END_STATE();
    case 210:
      ACCEPT_TOKEN(aux_sym_title_token1);
      if (lookahead == 'E') ADVANCE(220);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(233);
      END_STATE();
    case 211:
      ACCEPT_TOKEN(aux_sym_title_token1);
      if (lookahead == 'G') ADVANCE(194);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(233);
      END_STATE();
    case 212:
      ACCEPT_TOKEN(aux_sym_title_token1);
      if (lookahead == 'I') ADVANCE(227);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(233);
      END_STATE();
    case 213:
      ACCEPT_TOKEN(aux_sym_title_token1);
      if (lookahead == 'I') ADVANCE(218);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(233);
      END_STATE();
    case 214:
      ACCEPT_TOKEN(aux_sym_title_token1);
      if (lookahead == 'L') ADVANCE(209);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(233);
      END_STATE();
    case 215:
      ACCEPT_TOKEN(aux_sym_title_token1);
      if (lookahead == 'M') ADVANCE(216);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(233);
      END_STATE();
    case 216:
      ACCEPT_TOKEN(aux_sym_title_token1);
      if (lookahead == 'M') ADVANCE(210);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(233);
      END_STATE();
    case 217:
      ACCEPT_TOKEN(aux_sym_title_token1);
      if (lookahead == 'N') ADVANCE(203);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(233);
      END_STATE();
    case 218:
      ACCEPT_TOKEN(aux_sym_title_token1);
      if (lookahead == 'N') ADVANCE(211);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(233);
      END_STATE();
    case 219:
      ACCEPT_TOKEN(aux_sym_title_token1);
      if (lookahead == 'N') ADVANCE(206);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(233);
      END_STATE();
    case 220:
      ACCEPT_TOKEN(aux_sym_title_token1);
      if (lookahead == 'N') ADVANCE(226);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(233);
      END_STATE();
    case 221:
      ACCEPT_TOKEN(aux_sym_title_token1);
      if (lookahead == 'O') ADVANCE(194);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(233);
      END_STATE();
    case 222:
      ACCEPT_TOKEN(aux_sym_title_token1);
      if (lookahead == 'O') ADVANCE(215);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(233);
      END_STATE();
    case 223:
      ACCEPT_TOKEN(aux_sym_title_token1);
      if (lookahead == 'O') ADVANCE(205);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(233);
      END_STATE();
    case 224:
      ACCEPT_TOKEN(aux_sym_title_token1);
      if (lookahead == 'O') ADVANCE(219);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(233);
      END_STATE();
    case 225:
      ACCEPT_TOKEN(aux_sym_title_token1);
      if (lookahead == 'T') ADVANCE(194);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(233);
      END_STATE();
    case 226:
      ACCEPT_TOKEN(aux_sym_title_token1);
      if (lookahead == 'T') ADVANCE(196);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(233);
      END_STATE();
    case 227:
      ACCEPT_TOKEN(aux_sym_title_token1);
      if (lookahead == 'T') ADVANCE(213);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(233);
      END_STATE();
    case 228:
      ACCEPT_TOKEN(aux_sym_title_token1);
      if (lookahead == 'X') ADVANCE(225);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(233);
      END_STATE();
    case 229:
      ACCEPT_TOKEN(aux_sym_title_token1);
      if (lookahead == ']') ADVANCE(195);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(233);
      END_STATE();
    case 230:
      ACCEPT_TOKEN(aux_sym_title_token1);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(230);
      if ((0x0b <= lookahead && lookahead <= '\r')) ADVANCE(230);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead)) ADVANCE(233);
      END_STATE();
    case 231:
      ACCEPT_TOKEN(aux_sym_title_token1);
      if (lookahead == '\t' ||
          (0x0b <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(231);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead)) ADVANCE(233);
      END_STATE();
    case 232:
      ACCEPT_TOKEN(aux_sym_title_token1);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(229);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(233);
      END_STATE();
    case 233:
      ACCEPT_TOKEN(aux_sym_title_token1);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(233);
      END_STATE();
    case 234:
      ACCEPT_TOKEN(sym_planning_line);
      END_STATE();
    case 235:
      ACCEPT_TOKEN(sym_clock);
      END_STATE();
    case 236:
      ACCEPT_TOKEN(sym_diary_sexp);
      END_STATE();
    case 237:
      ACCEPT_TOKEN(sym_timestamp);
      END_STATE();
    case 238:
      ACCEPT_TOKEN(anon_sym_LBRACE_LBRACE_LBRACE);
      END_STATE();
    case 239:
      ACCEPT_TOKEN(anon_sym_LBRACE_LBRACE_LBRACE);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(461);
      END_STATE();
    case 240:
      ACCEPT_TOKEN(aux_sym_macro_token1);
      if (lookahead == '*') ADVANCE(282);
      if (lookahead == 'A') ADVANCE(256);
      if (lookahead == 'O') ADVANCE(254);
      if (lookahead == '_') ADVANCE(269);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(271);
      if (('B' <= lookahead && lookahead <= 'Z')) ADVANCE(267);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(268);
      END_STATE();
    case 241:
      ACCEPT_TOKEN(aux_sym_macro_token1);
      if (lookahead == '*') ADVANCE(282);
      if (lookahead == 'A') ADVANCE(251);
      if (lookahead == '_') ADVANCE(269);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(271);
      if (('B' <= lookahead && lookahead <= 'Z')) ADVANCE(267);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(268);
      END_STATE();
    case 242:
      ACCEPT_TOKEN(aux_sym_macro_token1);
      if (lookahead == '*') ADVANCE(282);
      if (lookahead == 'C') ADVANCE(247);
      if (lookahead == '_') ADVANCE(269);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(271);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(267);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(268);
      END_STATE();
    case 243:
      ACCEPT_TOKEN(aux_sym_macro_token1);
      if (lookahead == '*') ADVANCE(282);
      if (lookahead == 'D') ADVANCE(194);
      if (lookahead == '_') ADVANCE(269);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(271);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(267);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(268);
      END_STATE();
    case 244:
      ACCEPT_TOKEN(aux_sym_macro_token1);
      if (lookahead == '*') ADVANCE(282);
      if (lookahead == 'D') ADVANCE(261);
      if (lookahead == '_') ADVANCE(269);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(271);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(267);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(268);
      END_STATE();
    case 245:
      ACCEPT_TOKEN(aux_sym_macro_token1);
      if (lookahead == '*') ADVANCE(282);
      if (lookahead == 'E') ADVANCE(266);
      if (lookahead == '_') ADVANCE(269);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(271);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(267);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(268);
      END_STATE();
    case 246:
      ACCEPT_TOKEN(aux_sym_macro_token1);
      if (lookahead == '*') ADVANCE(282);
      if (lookahead == 'E') ADVANCE(194);
      if (lookahead == '_') ADVANCE(269);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(271);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(267);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(268);
      END_STATE();
    case 247:
      ACCEPT_TOKEN(aux_sym_macro_token1);
      if (lookahead == '*') ADVANCE(282);
      if (lookahead == 'E') ADVANCE(253);
      if (lookahead == '_') ADVANCE(269);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(271);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(267);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(268);
      END_STATE();
    case 248:
      ACCEPT_TOKEN(aux_sym_macro_token1);
      if (lookahead == '*') ADVANCE(282);
      if (lookahead == 'E') ADVANCE(243);
      if (lookahead == '_') ADVANCE(269);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(271);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(267);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(268);
      END_STATE();
    case 249:
      ACCEPT_TOKEN(aux_sym_macro_token1);
      if (lookahead == '*') ADVANCE(282);
      if (lookahead == 'E') ADVANCE(259);
      if (lookahead == '_') ADVANCE(269);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(271);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(267);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(268);
      END_STATE();
    case 250:
      ACCEPT_TOKEN(aux_sym_macro_token1);
      if (lookahead == '*') ADVANCE(282);
      if (lookahead == 'G') ADVANCE(194);
      if (lookahead == '_') ADVANCE(269);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(271);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(267);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(268);
      END_STATE();
    case 251:
      ACCEPT_TOKEN(aux_sym_macro_token1);
      if (lookahead == '*') ADVANCE(282);
      if (lookahead == 'I') ADVANCE(265);
      if (lookahead == '_') ADVANCE(269);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(271);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(267);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(268);
      END_STATE();
    case 252:
      ACCEPT_TOKEN(aux_sym_macro_token1);
      if (lookahead == '*') ADVANCE(282);
      if (lookahead == 'I') ADVANCE(257);
      if (lookahead == '_') ADVANCE(269);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(271);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(267);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(268);
      END_STATE();
    case 253:
      ACCEPT_TOKEN(aux_sym_macro_token1);
      if (lookahead == '*') ADVANCE(282);
      if (lookahead == 'L') ADVANCE(248);
      if (lookahead == '_') ADVANCE(269);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(271);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(267);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(268);
      END_STATE();
    case 254:
      ACCEPT_TOKEN(aux_sym_macro_token1);
      if (lookahead == '*') ADVANCE(282);
      if (lookahead == 'M') ADVANCE(255);
      if (lookahead == '_') ADVANCE(269);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(271);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(267);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(268);
      END_STATE();
    case 255:
      ACCEPT_TOKEN(aux_sym_macro_token1);
      if (lookahead == '*') ADVANCE(282);
      if (lookahead == 'M') ADVANCE(249);
      if (lookahead == '_') ADVANCE(269);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(271);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(267);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(268);
      END_STATE();
    case 256:
      ACCEPT_TOKEN(aux_sym_macro_token1);
      if (lookahead == '*') ADVANCE(282);
      if (lookahead == 'N') ADVANCE(242);
      if (lookahead == '_') ADVANCE(269);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(271);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(267);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(268);
      END_STATE();
    case 257:
      ACCEPT_TOKEN(aux_sym_macro_token1);
      if (lookahead == '*') ADVANCE(282);
      if (lookahead == 'N') ADVANCE(250);
      if (lookahead == '_') ADVANCE(269);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(271);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(267);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(268);
      END_STATE();
    case 258:
      ACCEPT_TOKEN(aux_sym_macro_token1);
      if (lookahead == '*') ADVANCE(282);
      if (lookahead == 'N') ADVANCE(246);
      if (lookahead == '_') ADVANCE(269);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(271);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(267);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(268);
      END_STATE();
    case 259:
      ACCEPT_TOKEN(aux_sym_macro_token1);
      if (lookahead == '*') ADVANCE(282);
      if (lookahead == 'N') ADVANCE(264);
      if (lookahead == '_') ADVANCE(269);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(271);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(267);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(268);
      END_STATE();
    case 260:
      ACCEPT_TOKEN(aux_sym_macro_token1);
      if (lookahead == '*') ADVANCE(282);
      if (lookahead == 'O') ADVANCE(244);
      if (lookahead == '_') ADVANCE(269);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(271);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(267);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(268);
      END_STATE();
    case 261:
      ACCEPT_TOKEN(aux_sym_macro_token1);
      if (lookahead == '*') ADVANCE(282);
      if (lookahead == 'O') ADVANCE(194);
      if (lookahead == '_') ADVANCE(269);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(271);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(267);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(268);
      END_STATE();
    case 262:
      ACCEPT_TOKEN(aux_sym_macro_token1);
      if (lookahead == '*') ADVANCE(282);
      if (lookahead == 'O') ADVANCE(258);
      if (lookahead == '_') ADVANCE(269);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(271);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(267);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(268);
      END_STATE();
    case 263:
      ACCEPT_TOKEN(aux_sym_macro_token1);
      if (lookahead == '*') ADVANCE(282);
      if (lookahead == 'T') ADVANCE(194);
      if (lookahead == '_') ADVANCE(269);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(271);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(267);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(268);
      END_STATE();
    case 264:
      ACCEPT_TOKEN(aux_sym_macro_token1);
      if (lookahead == '*') ADVANCE(282);
      if (lookahead == 'T') ADVANCE(196);
      if (lookahead == '_') ADVANCE(269);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(271);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(267);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(268);
      END_STATE();
    case 265:
      ACCEPT_TOKEN(aux_sym_macro_token1);
      if (lookahead == '*') ADVANCE(282);
      if (lookahead == 'T') ADVANCE(252);
      if (lookahead == '_') ADVANCE(269);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(271);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(267);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(268);
      END_STATE();
    case 266:
      ACCEPT_TOKEN(aux_sym_macro_token1);
      if (lookahead == '*') ADVANCE(282);
      if (lookahead == 'X') ADVANCE(263);
      if (lookahead == '_') ADVANCE(269);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(271);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(267);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(268);
      END_STATE();
    case 267:
      ACCEPT_TOKEN(aux_sym_macro_token1);
      if (lookahead == '*') ADVANCE(282);
      if (lookahead == '_') ADVANCE(269);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(271);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(267);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(268);
      END_STATE();
    case 268:
      ACCEPT_TOKEN(aux_sym_macro_token1);
      if (lookahead == '*') ADVANCE(282);
      if (lookahead == '_') ADVANCE(270);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(271);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(268);
      END_STATE();
    case 269:
      ACCEPT_TOKEN(aux_sym_macro_token1);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(271);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(270);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(269);
      END_STATE();
    case 270:
      ACCEPT_TOKEN(aux_sym_macro_token1);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(271);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(270);
      END_STATE();
    case 271:
      ACCEPT_TOKEN(aux_sym_macro_token1);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(271);
      END_STATE();
    case 272:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      END_STATE();
    case 273:
      ACCEPT_TOKEN(aux_sym_macro_token2);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(273);
      if (lookahead != 0 &&
          lookahead != ')' &&
          lookahead != '}') ADVANCE(274);
      END_STATE();
    case 274:
      ACCEPT_TOKEN(aux_sym_macro_token2);
      if (lookahead != 0 &&
          lookahead != ')' &&
          lookahead != '}') ADVANCE(274);
      END_STATE();
    case 275:
      ACCEPT_TOKEN(anon_sym_RPAREN);
      END_STATE();
    case 276:
      ACCEPT_TOKEN(anon_sym_RBRACE_RBRACE_RBRACE);
      END_STATE();
    case 277:
      ACCEPT_TOKEN(sym_footnote_reference);
      END_STATE();
    case 278:
      ACCEPT_TOKEN(sym_latex_fragment);
      END_STATE();
    case 279:
      ACCEPT_TOKEN(anon_sym_BSLASHbegin_LBRACE);
      END_STATE();
    case 280:
      ACCEPT_TOKEN(anon_sym_BSLASHbegin_LBRACE);
      if (lookahead == '}') ADVANCE(10);
      END_STATE();
    case 281:
      ACCEPT_TOKEN(anon_sym_BSLASHbegin_LBRACE);
      if (lookahead == '}') ADVANCE(367);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(461);
      END_STATE();
    case 282:
      ACCEPT_TOKEN(aux_sym_latex_env_begin_token1);
      END_STATE();
    case 283:
      ACCEPT_TOKEN(aux_sym_latex_env_begin_token1);
      if (lookahead == '*') ADVANCE(282);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(283);
      END_STATE();
    case 284:
      ACCEPT_TOKEN(anon_sym_RBRACE);
      END_STATE();
    case 285:
      ACCEPT_TOKEN(anon_sym_RBRACE);
      if (lookahead == '}') ADVANCE(127);
      END_STATE();
    case 286:
      ACCEPT_TOKEN(sym_latex_env_content);
      if (lookahead == '\\') ADVANCE(80);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(286);
      if (lookahead != 0) ADVANCE(287);
      END_STATE();
    case 287:
      ACCEPT_TOKEN(sym_latex_env_content);
      if (lookahead == '\\') ADVANCE(148);
      if (lookahead != 0) ADVANCE(287);
      END_STATE();
    case 288:
      ACCEPT_TOKEN(anon_sym_BSLASHend_LBRACE);
      END_STATE();
    case 289:
      ACCEPT_TOKEN(sym_entity);
      END_STATE();
    case 290:
      ACCEPT_TOKEN(sym_subscript);
      END_STATE();
    case 291:
      ACCEPT_TOKEN(sym_superscript);
      END_STATE();
    case 292:
      ACCEPT_TOKEN(anon_sym_LBRACK_LBRACK);
      END_STATE();
    case 293:
      ACCEPT_TOKEN(anon_sym_LBRACK_LBRACK);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(461);
      END_STATE();
    case 294:
      ACCEPT_TOKEN(aux_sym_link_token1);
      if (lookahead == '\t' ||
          (0x0b <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(294);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ']') ADVANCE(295);
      END_STATE();
    case 295:
      ACCEPT_TOKEN(aux_sym_link_token1);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != ']') ADVANCE(295);
      END_STATE();
    case 296:
      ACCEPT_TOKEN(anon_sym_RBRACK_LBRACK);
      END_STATE();
    case 297:
      ACCEPT_TOKEN(anon_sym_RBRACK_RBRACK);
      END_STATE();
    case 298:
      ACCEPT_TOKEN(aux_sym_list_item_token1);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(298);
      if ((0x0b <= lookahead && lookahead <= '\r')) ADVANCE(374);
      END_STATE();
    case 299:
      ACCEPT_TOKEN(aux_sym_list_item_token1);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(299);
      END_STATE();
    case 300:
      ACCEPT_TOKEN(aux_sym_list_item_token2);
      if (lookahead == '\n') ADVANCE(191);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(300);
      if (lookahead != 0) ADVANCE(303);
      END_STATE();
    case 301:
      ACCEPT_TOKEN(aux_sym_list_item_token2);
      if (lookahead == '\t' ||
          (0x0b <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(301);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(302);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead)) ADVANCE(303);
      END_STATE();
    case 302:
      ACCEPT_TOKEN(aux_sym_list_item_token2);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(302);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(303);
      END_STATE();
    case 303:
      ACCEPT_TOKEN(aux_sym_list_item_token2);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(303);
      END_STATE();
    case 304:
      ACCEPT_TOKEN(sym_bullet);
      END_STATE();
    case 305:
      ACCEPT_TOKEN(sym_bullet);
      if (lookahead == '-') ADVANCE(385);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(461);
      END_STATE();
    case 306:
      ACCEPT_TOKEN(sym_bullet);
      if (lookahead == '-') ADVANCE(55);
      END_STATE();
    case 307:
      ACCEPT_TOKEN(sym_bullet);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(461);
      END_STATE();
    case 308:
      ACCEPT_TOKEN(aux_sym_block_begin_token1);
      END_STATE();
    case 309:
      ACCEPT_TOKEN(aux_sym_block_begin_token1);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(461);
      END_STATE();
    case 310:
      ACCEPT_TOKEN(sym_block_type);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(311);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(310);
      END_STATE();
    case 311:
      ACCEPT_TOKEN(sym_block_type);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(311);
      END_STATE();
    case 312:
      ACCEPT_TOKEN(sym_language);
      if (lookahead == '+' ||
          lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(312);
      END_STATE();
    case 313:
      ACCEPT_TOKEN(sym_block_content);
      if (lookahead == '#') ADVANCE(48);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(313);
      if (lookahead != 0) ADVANCE(314);
      END_STATE();
    case 314:
      ACCEPT_TOKEN(sym_block_content);
      if (lookahead == '#') ADVANCE(50);
      if (lookahead != 0) ADVANCE(314);
      END_STATE();
    case 315:
      ACCEPT_TOKEN(aux_sym_block_end_token1);
      END_STATE();
    case 316:
      ACCEPT_TOKEN(aux_sym_dynamic_block_begin_token1);
      END_STATE();
    case 317:
      ACCEPT_TOKEN(aux_sym_dynamic_block_begin_token1);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(461);
      END_STATE();
    case 318:
      ACCEPT_TOKEN(aux_sym_dynamic_block_begin_token2);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(318);
      END_STATE();
    case 319:
      ACCEPT_TOKEN(sym_dynamic_block_content);
      if (lookahead == '#') ADVANCE(46);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(319);
      if (lookahead != 0) ADVANCE(320);
      END_STATE();
    case 320:
      ACCEPT_TOKEN(sym_dynamic_block_content);
      if (lookahead == '#') ADVANCE(49);
      if (lookahead != 0) ADVANCE(320);
      END_STATE();
    case 321:
      ACCEPT_TOKEN(aux_sym_dynamic_block_end_token1);
      END_STATE();
    case 322:
      ACCEPT_TOKEN(anon_sym_PIPE);
      END_STATE();
    case 323:
      ACCEPT_TOKEN(anon_sym_PIPE);
      if (lookahead == '-') ADVANCE(1);
      END_STATE();
    case 324:
      ACCEPT_TOKEN(anon_sym_PIPE);
      if (lookahead == '-') ADVANCE(350);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(461);
      END_STATE();
    case 325:
      ACCEPT_TOKEN(sym_table_cell);
      if (lookahead == '\n') ADVANCE(186);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(325);
      if (lookahead != 0 &&
          lookahead != '|') ADVANCE(326);
      END_STATE();
    case 326:
      ACCEPT_TOKEN(sym_table_cell);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '|') ADVANCE(326);
      END_STATE();
    case 327:
      ACCEPT_TOKEN(sym_table_separator);
      END_STATE();
    case 328:
      ACCEPT_TOKEN(aux_sym_directive_token1);
      if (lookahead == 'B' ||
          lookahead == 'b') ADVANCE(144);
      END_STATE();
    case 329:
      ACCEPT_TOKEN(aux_sym_directive_token1);
      if (lookahead == 'B' ||
          lookahead == 'b') ADVANCE(453);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(461);
      END_STATE();
    case 330:
      ACCEPT_TOKEN(anon_sym_COLON);
      END_STATE();
    case 331:
      ACCEPT_TOKEN(anon_sym_COLON);
      if (lookahead == ' ') ADVANCE(337);
      if (lookahead == 'P') ADVANCE(88);
      END_STATE();
    case 332:
      ACCEPT_TOKEN(anon_sym_COLON);
      if (lookahead == ' ') ADVANCE(338);
      if (lookahead == 'P') ADVANCE(423);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(461);
      END_STATE();
    case 333:
      ACCEPT_TOKEN(anon_sym_COLON);
      if (lookahead == 'E') ADVANCE(83);
      END_STATE();
    case 334:
      ACCEPT_TOKEN(sym_name);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(334);
      END_STATE();
    case 335:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      END_STATE();
    case 336:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(461);
      END_STATE();
    case 337:
      ACCEPT_TOKEN(aux_sym_fixed_width_token1);
      END_STATE();
    case 338:
      ACCEPT_TOKEN(aux_sym_fixed_width_token1);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(461);
      END_STATE();
    case 339:
      ACCEPT_TOKEN(anon_sym_COLONPROPERTIES_COLON);
      END_STATE();
    case 340:
      ACCEPT_TOKEN(anon_sym_COLONPROPERTIES_COLON);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(461);
      END_STATE();
    case 341:
      ACCEPT_TOKEN(aux_sym_property_drawer_token1);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(341);
      END_STATE();
    case 342:
      ACCEPT_TOKEN(anon_sym_COLONEND_COLON);
      END_STATE();
    case 343:
      ACCEPT_TOKEN(aux_sym_key_token1);
      if (lookahead == '-' ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(343);
      END_STATE();
    case 344:
      ACCEPT_TOKEN(anon_sym_COLONend_COLON);
      END_STATE();
    case 345:
      ACCEPT_TOKEN(sym_drawer_content);
      if (lookahead == ':') ADVANCE(81);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(345);
      if (lookahead != 0) ADVANCE(346);
      END_STATE();
    case 346:
      ACCEPT_TOKEN(sym_drawer_content);
      if (lookahead == ':') ADVANCE(149);
      if (lookahead != 0) ADVANCE(346);
      END_STATE();
    case 347:
      ACCEPT_TOKEN(sym_horizontal_rule);
      END_STATE();
    case 348:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '\n') ADVANCE(40);
      if (lookahead == '$') ADVANCE(461);
      if (lookahead != 0) ADVANCE(349);
      END_STATE();
    case 349:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '\n') ADVANCE(40);
      if (lookahead == '$') ADVANCE(376);
      if (lookahead != 0) ADVANCE(349);
      END_STATE();
    case 350:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '\n') ADVANCE(327);
      if (lookahead == '+') ADVANCE(381);
      if (lookahead == '-') ADVANCE(350);
      if (lookahead == '|') ADVANCE(351);
      if (lookahead != 0) ADVANCE(461);
      END_STATE();
    case 351:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '\n') ADVANCE(327);
      if (lookahead == '-') ADVANCE(350);
      if (lookahead != 0) ADVANCE(461);
      END_STATE();
    case 352:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '\n') ADVANCE(278);
      if (lookahead != 0) ADVANCE(461);
      END_STATE();
    case 353:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '\n') ADVANCE(237);
      if (lookahead != 0) ADVANCE(461);
      END_STATE();
    case 354:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '\n') ADVANCE(45);
      if (lookahead == '(') ADVANCE(354);
      if (lookahead == ')') ADVANCE(355);
      if (lookahead != 0) ADVANCE(354);
      END_STATE();
    case 355:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '\n') ADVANCE(236);
      if (lookahead == '(') ADVANCE(354);
      if (lookahead == ')') ADVANCE(356);
      if (lookahead != 0) ADVANCE(380);
      END_STATE();
    case 356:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '\n') ADVANCE(236);
      if (lookahead != 0) ADVANCE(461);
      END_STATE();
    case 357:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '\n') ADVANCE(347);
      if (lookahead == '-') ADVANCE(357);
      if (lookahead != 0) ADVANCE(461);
      END_STATE();
    case 358:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '\n') ADVANCE(100);
      if (lookahead == ']') ADVANCE(461);
      if (lookahead != 0) ADVANCE(359);
      END_STATE();
    case 359:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '\n') ADVANCE(100);
      if (lookahead == ']') ADVANCE(360);
      if (lookahead != 0) ADVANCE(359);
      END_STATE();
    case 360:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '\n') ADVANCE(277);
      if (lookahead != 0) ADVANCE(461);
      END_STATE();
    case 361:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '\n') ADVANCE(289);
      if (lookahead == 'e') ADVANCE(362);
      if (lookahead == '{') ADVANCE(447);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(365);
      if (lookahead != 0) ADVANCE(461);
      END_STATE();
    case 362:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '\n') ADVANCE(289);
      if (lookahead == 'g') ADVANCE(363);
      if (lookahead == '{') ADVANCE(447);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(365);
      if (lookahead != 0) ADVANCE(461);
      END_STATE();
    case 363:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '\n') ADVANCE(289);
      if (lookahead == 'i') ADVANCE(364);
      if (lookahead == '{') ADVANCE(447);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(365);
      if (lookahead != 0) ADVANCE(461);
      END_STATE();
    case 364:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '\n') ADVANCE(289);
      if (lookahead == 'n') ADVANCE(366);
      if (lookahead == '{') ADVANCE(447);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(365);
      if (lookahead != 0) ADVANCE(461);
      END_STATE();
    case 365:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '\n') ADVANCE(289);
      if (lookahead == '{') ADVANCE(447);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(365);
      if (lookahead != 0) ADVANCE(461);
      END_STATE();
    case 366:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '\n') ADVANCE(289);
      if (lookahead == '{') ADVANCE(281);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(365);
      if (lookahead != 0) ADVANCE(461);
      END_STATE();
    case 367:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '\n') ADVANCE(289);
      if (lookahead != 0) ADVANCE(461);
      END_STATE();
    case 368:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '\n') ADVANCE(291);
      if (lookahead != 0) ADVANCE(368);
      END_STATE();
    case 369:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '\n') ADVANCE(290);
      if (lookahead != 0) ADVANCE(369);
      END_STATE();
    case 370:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '\n') ADVANCE(235);
      if (lookahead == '-') ADVANCE(382);
      if (lookahead != 0) ADVANCE(461);
      END_STATE();
    case 371:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '\n') ADVANCE(235);
      if (lookahead != 0) ADVANCE(461);
      END_STATE();
    case 372:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '\n') ADVANCE(234);
      if (lookahead != 0) ADVANCE(461);
      END_STATE();
    case 373:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == ' ') ADVANCE(336);
      if (lookahead == '+') ADVANCE(329);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(461);
      END_STATE();
    case 374:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      ADVANCE_MAP(
        '#', 373,
        '$', 375,
        '%', 378,
        '*', 193,
        '+', 307,
        '-', 305,
        ':', 332,
        '<', 397,
        'C', 416,
        'D', 407,
        'S', 403,
        '[', 429,
        '\\', 443,
        'c', 436,
        '{', 446,
        '|', 324,
        '\t', 298,
        ' ', 298,
      );
      if ((0x0b <= lookahead && lookahead <= '\r')) ADVANCE(374);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(437);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(438);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(438);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead)) ADVANCE(461);
      END_STATE();
    case 375:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '$') ADVANCE(348);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(377);
      END_STATE();
    case 376:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '$') ADVANCE(352);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(461);
      END_STATE();
    case 377:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '$') ADVANCE(352);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(377);
      END_STATE();
    case 378:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '%') ADVANCE(379);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(461);
      END_STATE();
    case 379:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '(') ADVANCE(380);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(461);
      END_STATE();
    case 380:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '(') ADVANCE(354);
      if (lookahead == ')') ADVANCE(356);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(380);
      END_STATE();
    case 381:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '-') ADVANCE(350);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(461);
      END_STATE();
    case 382:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '-') ADVANCE(430);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(461);
      END_STATE();
    case 383:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '-') ADVANCE(357);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(461);
      END_STATE();
    case 384:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '-') ADVANCE(383);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(461);
      END_STATE();
    case 385:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '-') ADVANCE(384);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(461);
      END_STATE();
    case 386:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == ':') ADVANCE(389);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(461);
      END_STATE();
    case 387:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == ':') ADVANCE(448);
      if (lookahead == '^') ADVANCE(462);
      if (lookahead == '_') ADVANCE(463);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(442);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(461);
      END_STATE();
    case 388:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == ':') ADVANCE(358);
      if (lookahead == ']') ADVANCE(360);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(388);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(461);
      END_STATE();
    case 389:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == ':') ADVANCE(358);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(388);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(461);
      END_STATE();
    case 390:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == ':') ADVANCE(317);
      if (lookahead == '_') ADVANCE(309);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(461);
      END_STATE();
    case 391:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == ':') ADVANCE(340);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(461);
      END_STATE();
    case 392:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == ':') ADVANCE(449);
      if (lookahead == '^') ADVANCE(462);
      if (lookahead == '_') ADVANCE(463);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(442);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(461);
      END_STATE();
    case 393:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == ':') ADVANCE(458);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(393);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(461);
      END_STATE();
    case 394:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '<') ADVANCE(398);
      if (lookahead == '[') ADVANCE(431);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(394);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n') ADVANCE(461);
      END_STATE();
    case 395:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '=') ADVANCE(400);
      if (lookahead == '[') ADVANCE(457);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(395);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n') ADVANCE(461);
      END_STATE();
    case 396:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '=') ADVANCE(400);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(396);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n') ADVANCE(461);
      END_STATE();
    case 397:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '>') ADVANCE(461);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(399);
      END_STATE();
    case 398:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '>') ADVANCE(461);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(401);
      END_STATE();
    case 399:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '>') ADVANCE(353);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(399);
      END_STATE();
    case 400:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '>') ADVANCE(451);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(461);
      END_STATE();
    case 401:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '>') ADVANCE(372);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(401);
      END_STATE();
    case 402:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == 'A') ADVANCE(404);
      if (lookahead == '^') ADVANCE(462);
      if (lookahead == '_') ADVANCE(463);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('B' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(442);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(461);
      END_STATE();
    case 403:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == 'C') ADVANCE(413);
      if (lookahead == '^') ADVANCE(462);
      if (lookahead == '_') ADVANCE(463);
      if (lookahead == ')' ||
          lookahead == '.') ADVANCE(307);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(442);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(461);
      END_STATE();
    case 404:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == 'D') ADVANCE(417);
      if (lookahead == '^') ADVANCE(462);
      if (lookahead == '_') ADVANCE(463);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(442);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(461);
      END_STATE();
    case 405:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == 'D') ADVANCE(428);
      if (lookahead == '^') ADVANCE(462);
      if (lookahead == '_') ADVANCE(463);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(442);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(461);
      END_STATE();
    case 406:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == 'D') ADVANCE(392);
      if (lookahead == '^') ADVANCE(462);
      if (lookahead == '_') ADVANCE(463);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(442);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(461);
      END_STATE();
    case 407:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == 'E') ADVANCE(402);
      if (lookahead == '^') ADVANCE(462);
      if (lookahead == '_') ADVANCE(463);
      if (lookahead == ')' ||
          lookahead == '.') ADVANCE(307);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(442);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(461);
      END_STATE();
    case 408:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == 'E') ADVANCE(425);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(461);
      END_STATE();
    case 409:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == 'E') ADVANCE(405);
      if (lookahead == '^') ADVANCE(462);
      if (lookahead == '_') ADVANCE(463);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(442);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(461);
      END_STATE();
    case 410:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == 'E') ADVANCE(424);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(461);
      END_STATE();
    case 411:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == 'E') ADVANCE(406);
      if (lookahead == '^') ADVANCE(462);
      if (lookahead == '_') ADVANCE(463);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(442);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(461);
      END_STATE();
    case 412:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == 'E') ADVANCE(392);
      if (lookahead == '^') ADVANCE(462);
      if (lookahead == '_') ADVANCE(463);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(442);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(461);
      END_STATE();
    case 413:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == 'H') ADVANCE(409);
      if (lookahead == '^') ADVANCE(462);
      if (lookahead == '_') ADVANCE(463);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(442);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(461);
      END_STATE();
    case 414:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == 'I') ADVANCE(419);
      if (lookahead == '^') ADVANCE(462);
      if (lookahead == '_') ADVANCE(463);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(442);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(461);
      END_STATE();
    case 415:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == 'I') ADVANCE(408);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(461);
      END_STATE();
    case 416:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == 'L') ADVANCE(420);
      if (lookahead == '^') ADVANCE(462);
      if (lookahead == '_') ADVANCE(463);
      if (lookahead == 'l') ADVANCE(441);
      if (lookahead == ')' ||
          lookahead == '.') ADVANCE(307);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(442);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(461);
      END_STATE();
    case 417:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == 'L') ADVANCE(414);
      if (lookahead == '^') ADVANCE(462);
      if (lookahead == '_') ADVANCE(463);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(442);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(461);
      END_STATE();
    case 418:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == 'L') ADVANCE(411);
      if (lookahead == '^') ADVANCE(462);
      if (lookahead == '_') ADVANCE(463);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(442);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(461);
      END_STATE();
    case 419:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == 'N') ADVANCE(412);
      if (lookahead == '^') ADVANCE(462);
      if (lookahead == '_') ADVANCE(463);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(442);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(461);
      END_STATE();
    case 420:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == 'O') ADVANCE(426);
      if (lookahead == '^') ADVANCE(462);
      if (lookahead == '_') ADVANCE(463);
      if (lookahead == 'o') ADVANCE(439);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(442);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(461);
      END_STATE();
    case 421:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == 'O') ADVANCE(422);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(461);
      END_STATE();
    case 422:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == 'P') ADVANCE(410);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(461);
      END_STATE();
    case 423:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == 'R') ADVANCE(421);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(461);
      END_STATE();
    case 424:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == 'R') ADVANCE(427);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(461);
      END_STATE();
    case 425:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == 'S') ADVANCE(391);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(461);
      END_STATE();
    case 426:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == 'S') ADVANCE(411);
      if (lookahead == '^') ADVANCE(462);
      if (lookahead == '_') ADVANCE(463);
      if (lookahead == 'C' ||
          lookahead == 'c') ADVANCE(440);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(442);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(461);
      END_STATE();
    case 427:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == 'T') ADVANCE(415);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(461);
      END_STATE();
    case 428:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == 'U') ADVANCE(418);
      if (lookahead == '^') ADVANCE(462);
      if (lookahead == '_') ADVANCE(463);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(442);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(461);
      END_STATE();
    case 429:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '[') ADVANCE(293);
      if (lookahead == 'f') ADVANCE(444);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(432);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(461);
      END_STATE();
    case 430:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '[') ADVANCE(459);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(461);
      END_STATE();
    case 431:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == ']') ADVANCE(461);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(435);
      END_STATE();
    case 432:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == ']') ADVANCE(353);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(432);
      END_STATE();
    case 433:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == ']') ADVANCE(370);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(433);
      END_STATE();
    case 434:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == ']') ADVANCE(452);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(434);
      END_STATE();
    case 435:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == ']') ADVANCE(372);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(435);
      END_STATE();
    case 436:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '^') ADVANCE(462);
      if (lookahead == '_') ADVANCE(463);
      if (lookahead == ')' ||
          lookahead == '.') ADVANCE(307);
      if (lookahead == 'L' ||
          lookahead == 'l') ADVANCE(441);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(442);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(461);
      END_STATE();
    case 437:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '^') ADVANCE(462);
      if (lookahead == '_') ADVANCE(463);
      if (lookahead == ')' ||
          lookahead == '.') ADVANCE(307);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(437);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(442);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(461);
      END_STATE();
    case 438:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '^') ADVANCE(462);
      if (lookahead == '_') ADVANCE(463);
      if (lookahead == ')' ||
          lookahead == '.') ADVANCE(307);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(442);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(461);
      END_STATE();
    case 439:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '^') ADVANCE(462);
      if (lookahead == '_') ADVANCE(463);
      if (lookahead == 'C' ||
          lookahead == 'c') ADVANCE(440);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(442);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(461);
      END_STATE();
    case 440:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '^') ADVANCE(462);
      if (lookahead == '_') ADVANCE(463);
      if (lookahead == 'K' ||
          lookahead == 'k') ADVANCE(387);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(442);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(461);
      END_STATE();
    case 441:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '^') ADVANCE(462);
      if (lookahead == '_') ADVANCE(463);
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(439);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(442);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(461);
      END_STATE();
    case 442:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '^') ADVANCE(462);
      if (lookahead == '_') ADVANCE(463);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(442);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(461);
      END_STATE();
    case 443:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == 'b') ADVANCE(361);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(365);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(461);
      END_STATE();
    case 444:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == 'n') ADVANCE(386);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(461);
      END_STATE();
    case 445:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '{') ADVANCE(239);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(461);
      END_STATE();
    case 446:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '{') ADVANCE(445);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(461);
      END_STATE();
    case 447:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '}') ADVANCE(367);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(461);
      END_STATE();
    case 448:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(395);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n') ADVANCE(461);
      END_STATE();
    case 449:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(394);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n') ADVANCE(461);
      END_STATE();
    case 450:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(450);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(393);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n') ADVANCE(461);
      END_STATE();
    case 451:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(450);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n') ADVANCE(461);
      END_STATE();
    case 452:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(396);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n') ADVANCE(461);
      END_STATE();
    case 453:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(454);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(461);
      END_STATE();
    case 454:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == 'G' ||
          lookahead == 'g') ADVANCE(455);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(461);
      END_STATE();
    case 455:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(456);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(461);
      END_STATE();
    case 456:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(390);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(461);
      END_STATE();
    case 457:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(433);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(461);
      END_STATE();
    case 458:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(460);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(461);
      END_STATE();
    case 459:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(434);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(461);
      END_STATE();
    case 460:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(371);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(461);
      END_STATE();
    case 461:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(461);
      END_STATE();
    case 462:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(368);
      END_STATE();
    case 463:
      ACCEPT_TOKEN(aux_sym_paragraph_token1);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(369);
      END_STATE();
    case 464:
      ACCEPT_TOKEN(aux_sym_paragraph_token2);
      if (lookahead == '\n') ADVANCE(464);
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
  [41] = {.lex_state = 21},
  [42] = {.lex_state = 34},
  [43] = {.lex_state = 22},
  [44] = {.lex_state = 23},
  [45] = {.lex_state = 22},
  [46] = {.lex_state = 24},
  [47] = {.lex_state = 34},
  [48] = {.lex_state = 22},
  [49] = {.lex_state = 22},
  [50] = {.lex_state = 35},
  [51] = {.lex_state = 36},
  [52] = {.lex_state = 95},
  [53] = {.lex_state = 24},
  [54] = {.lex_state = 42},
  [55] = {.lex_state = 24},
  [56] = {.lex_state = 70},
  [57] = {.lex_state = 25},
  [58] = {.lex_state = 35},
  [59] = {.lex_state = 34},
  [60] = {.lex_state = 301},
  [61] = {.lex_state = 300},
  [62] = {.lex_state = 95},
  [63] = {.lex_state = 34},
  [64] = {.lex_state = 0},
  [65] = {.lex_state = 34},
  [66] = {.lex_state = 36},
  [67] = {.lex_state = 26},
  [68] = {.lex_state = 42},
  [69] = {.lex_state = 25},
  [70] = {.lex_state = 34},
  [71] = {.lex_state = 36},
  [72] = {.lex_state = 300},
  [73] = {.lex_state = 36},
  [74] = {.lex_state = 26},
  [75] = {.lex_state = 35},
  [76] = {.lex_state = 27},
  [77] = {.lex_state = 0},
  [78] = {.lex_state = 42},
  [79] = {.lex_state = 42},
  [80] = {.lex_state = 42},
  [81] = {.lex_state = 341},
  [82] = {.lex_state = 32},
  [83] = {.lex_state = 68},
  [84] = {.lex_state = 28},
  [85] = {.lex_state = 34},
  [86] = {.lex_state = 28},
  [87] = {.lex_state = 301},
  [88] = {.lex_state = 28},
  [89] = {.lex_state = 301},
  [90] = {.lex_state = 28},
  [91] = {.lex_state = 28},
  [92] = {.lex_state = 29},
  [93] = {.lex_state = 28},
  [94] = {.lex_state = 0},
  [95] = {.lex_state = 28},
  [96] = {.lex_state = 162},
  [97] = {.lex_state = 0},
  [98] = {.lex_state = 32},
  [99] = {.lex_state = 28},
  [100] = {.lex_state = 32},
  [101] = {.lex_state = 301},
  [102] = {.lex_state = 28},
  [103] = {.lex_state = 28},
  [104] = {.lex_state = 28},
  [105] = {.lex_state = 25},
  [106] = {.lex_state = 28},
  [107] = {.lex_state = 28},
  [108] = {.lex_state = 28},
  [109] = {.lex_state = 28},
  [110] = {.lex_state = 28},
  [111] = {.lex_state = 28},
  [112] = {.lex_state = 28},
  [113] = {.lex_state = 28},
  [114] = {.lex_state = 42},
  [115] = {.lex_state = 32},
  [116] = {.lex_state = 42},
  [117] = {.lex_state = 28},
  [118] = {.lex_state = 42},
  [119] = {.lex_state = 34},
  [120] = {.lex_state = 28},
  [121] = {.lex_state = 163},
  [122] = {.lex_state = 301},
  [123] = {.lex_state = 28},
  [124] = {.lex_state = 32},
  [125] = {.lex_state = 42},
  [126] = {.lex_state = 42},
  [127] = {.lex_state = 341},
  [128] = {.lex_state = 34},
  [129] = {.lex_state = 0},
  [130] = {.lex_state = 30},
  [131] = {.lex_state = 341},
  [132] = {.lex_state = 301},
  [133] = {.lex_state = 28},
  [134] = {.lex_state = 301},
  [135] = {.lex_state = 164},
  [136] = {.lex_state = 133},
  [137] = {.lex_state = 341},
  [138] = {.lex_state = 68},
  [139] = {.lex_state = 341},
  [140] = {.lex_state = 28},
  [141] = {.lex_state = 165},
  [142] = {.lex_state = 28},
  [143] = {.lex_state = 341},
  [144] = {.lex_state = 32},
  [145] = {.lex_state = 136},
  [146] = {.lex_state = 29},
  [147] = {.lex_state = 28},
  [148] = {.lex_state = 28},
  [149] = {.lex_state = 28},
  [150] = {.lex_state = 34},
  [151] = {.lex_state = 166},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [sym_stars] = ACTIONS(1),
    [sym_keyword] = ACTIONS(1),
    [sym_priority] = ACTIONS(1),
    [sym_comment_keyword] = ACTIONS(1),
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
    [sym_document] = STATE(129),
    [sym__element] = STATE(2),
    [sym_headline] = STATE(2),
    [sym__headline_prefix] = STATE(46),
    [sym_macro] = STATE(2),
    [sym_latex_environment] = STATE(2),
    [sym_latex_env_begin] = STATE(52),
    [sym_link] = STATE(2),
    [sym_list] = STATE(2),
    [sym_list_item] = STATE(6),
    [sym_block] = STATE(2),
    [sym_block_begin] = STATE(51),
    [sym_dynamic_block] = STATE(2),
    [sym_dynamic_block_begin] = STATE(50),
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
    [sym__element] = STATE(3),
    [sym_headline] = STATE(3),
    [sym__headline_prefix] = STATE(46),
    [sym_macro] = STATE(3),
    [sym_latex_environment] = STATE(3),
    [sym_latex_env_begin] = STATE(52),
    [sym_link] = STATE(3),
    [sym_list] = STATE(3),
    [sym_list_item] = STATE(6),
    [sym_block] = STATE(3),
    [sym_block_begin] = STATE(51),
    [sym_dynamic_block] = STATE(3),
    [sym_dynamic_block_begin] = STATE(50),
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
    [aux_sym_fixed_width_repeat1] = STATE(9),
    [ts_builtin_sym_end] = ACTIONS(39),
    [sym_stars] = ACTIONS(5),
    [sym_planning_line] = ACTIONS(41),
    [sym_clock] = ACTIONS(41),
    [sym_diary_sexp] = ACTIONS(41),
    [sym_timestamp] = ACTIONS(41),
    [anon_sym_LBRACE_LBRACE_LBRACE] = ACTIONS(9),
    [sym_footnote_reference] = ACTIONS(41),
    [sym_latex_fragment] = ACTIONS(41),
    [anon_sym_BSLASHbegin_LBRACE] = ACTIONS(11),
    [sym_entity] = ACTIONS(41),
    [sym_subscript] = ACTIONS(41),
    [sym_superscript] = ACTIONS(41),
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
    [sym_horizontal_rule] = ACTIONS(41),
    [aux_sym_paragraph_token1] = ACTIONS(37),
  },
  [3] = {
    [sym__element] = STATE(3),
    [sym_headline] = STATE(3),
    [sym__headline_prefix] = STATE(46),
    [sym_macro] = STATE(3),
    [sym_latex_environment] = STATE(3),
    [sym_latex_env_begin] = STATE(52),
    [sym_link] = STATE(3),
    [sym_list] = STATE(3),
    [sym_list_item] = STATE(6),
    [sym_block] = STATE(3),
    [sym_block_begin] = STATE(51),
    [sym_dynamic_block] = STATE(3),
    [sym_dynamic_block_begin] = STATE(50),
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
    [aux_sym_fixed_width_repeat1] = STATE(9),
    [ts_builtin_sym_end] = ACTIONS(43),
    [sym_stars] = ACTIONS(45),
    [sym_planning_line] = ACTIONS(48),
    [sym_clock] = ACTIONS(48),
    [sym_diary_sexp] = ACTIONS(48),
    [sym_timestamp] = ACTIONS(48),
    [anon_sym_LBRACE_LBRACE_LBRACE] = ACTIONS(51),
    [sym_footnote_reference] = ACTIONS(48),
    [sym_latex_fragment] = ACTIONS(48),
    [anon_sym_BSLASHbegin_LBRACE] = ACTIONS(54),
    [sym_entity] = ACTIONS(48),
    [sym_subscript] = ACTIONS(48),
    [sym_superscript] = ACTIONS(48),
    [anon_sym_LBRACK_LBRACK] = ACTIONS(57),
    [aux_sym_list_item_token1] = ACTIONS(60),
    [sym_bullet] = ACTIONS(63),
    [aux_sym_block_begin_token1] = ACTIONS(66),
    [aux_sym_dynamic_block_begin_token1] = ACTIONS(69),
    [anon_sym_PIPE] = ACTIONS(72),
    [sym_table_separator] = ACTIONS(75),
    [aux_sym_directive_token1] = ACTIONS(78),
    [anon_sym_COLON] = ACTIONS(81),
    [aux_sym_comment_token1] = ACTIONS(84),
    [aux_sym_fixed_width_token1] = ACTIONS(87),
    [anon_sym_COLONPROPERTIES_COLON] = ACTIONS(90),
    [sym_horizontal_rule] = ACTIONS(48),
    [aux_sym_paragraph_token1] = ACTIONS(93),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 5,
    ACTIONS(96), 1,
      ts_builtin_sym_end,
    ACTIONS(100), 1,
      anon_sym_PIPE,
    ACTIONS(103), 1,
      sym_table_separator,
    STATE(4), 2,
      sym_table_row,
      aux_sym_table_repeat1,
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
  [40] = 5,
    ACTIONS(106), 1,
      ts_builtin_sym_end,
    ACTIONS(110), 1,
      aux_sym_list_item_token1,
    ACTIONS(113), 1,
      sym_bullet,
    STATE(5), 2,
      sym_list_item,
      aux_sym_list_repeat1,
    ACTIONS(108), 24,
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
  [80] = 5,
    ACTIONS(15), 1,
      aux_sym_list_item_token1,
    ACTIONS(17), 1,
      sym_bullet,
    ACTIONS(116), 1,
      ts_builtin_sym_end,
    STATE(5), 2,
      sym_list_item,
      aux_sym_list_repeat1,
    ACTIONS(118), 24,
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
    STATE(4), 2,
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
  [1226] = 3,
    ACTIONS(263), 1,
      sym_keyword,
    ACTIONS(265), 1,
      sym_priority,
    ACTIONS(261), 3,
      anon_sym_LF,
      sym_comment_keyword,
      aux_sym_title_token1,
  [1238] = 3,
    ACTIONS(267), 1,
      anon_sym_COLON,
    ACTIONS(269), 1,
      anon_sym_COLONEND_COLON,
    STATE(47), 2,
      sym_property,
      aux_sym_property_drawer_repeat1,
  [1249] = 4,
    ACTIONS(271), 1,
      anon_sym_LF,
    ACTIONS(273), 1,
      anon_sym_PIPE,
    ACTIONS(275), 1,
      sym_table_cell,
    STATE(45), 1,
      aux_sym_table_row_repeat1,
  [1262] = 2,
    ACTIONS(279), 1,
      sym_priority,
    ACTIONS(277), 3,
      anon_sym_LF,
      sym_comment_keyword,
      aux_sym_title_token1,
  [1271] = 4,
    ACTIONS(281), 1,
      anon_sym_LF,
    ACTIONS(283), 1,
      anon_sym_PIPE,
    ACTIONS(286), 1,
      sym_table_cell,
    STATE(45), 1,
      aux_sym_table_row_repeat1,
  [1284] = 4,
    ACTIONS(289), 1,
      anon_sym_LF,
    ACTIONS(291), 1,
      sym_comment_keyword,
    ACTIONS(293), 1,
      aux_sym_title_token1,
    STATE(102), 1,
      sym_title,
  [1297] = 3,
    ACTIONS(295), 1,
      anon_sym_COLON,
    ACTIONS(298), 1,
      anon_sym_COLONEND_COLON,
    STATE(47), 2,
      sym_property,
      aux_sym_property_drawer_repeat1,
  [1308] = 4,
    ACTIONS(275), 1,
      sym_table_cell,
    ACTIONS(300), 1,
      anon_sym_LF,
    ACTIONS(302), 1,
      anon_sym_PIPE,
    STATE(43), 1,
      aux_sym_table_row_repeat1,
  [1321] = 1,
    ACTIONS(281), 3,
      anon_sym_LF,
      anon_sym_PIPE,
      sym_table_cell,
  [1327] = 3,
    ACTIONS(304), 1,
      sym_dynamic_block_content,
    ACTIONS(306), 1,
      aux_sym_dynamic_block_end_token1,
    STATE(23), 1,
      sym_dynamic_block_end,
  [1337] = 3,
    ACTIONS(308), 1,
      sym_block_content,
    ACTIONS(310), 1,
      aux_sym_block_end_token1,
    STATE(25), 1,
      sym_block_end,
  [1347] = 3,
    ACTIONS(312), 1,
      sym_latex_env_content,
    ACTIONS(314), 1,
      anon_sym_BSLASHend_LBRACE,
    STATE(26), 1,
      sym_latex_env_end,
  [1357] = 1,
    ACTIONS(316), 3,
      anon_sym_LF,
      sym_comment_keyword,
      aux_sym_title_token1,
  [1363] = 2,
    ACTIONS(318), 1,
      anon_sym_COLON,
    STATE(42), 2,
      sym_property,
      aux_sym_property_drawer_repeat1,
  [1371] = 1,
    ACTIONS(320), 3,
      anon_sym_LF,
      sym_comment_keyword,
      aux_sym_title_token1,
  [1377] = 2,
    ACTIONS(322), 1,
      anon_sym_COLONend_COLON,
    ACTIONS(324), 1,
      sym_drawer_content,
  [1384] = 2,
    ACTIONS(326), 1,
      aux_sym_title_token1,
    STATE(149), 1,
      sym_value,
  [1391] = 2,
    ACTIONS(328), 1,
      sym_dynamic_block_content,
    ACTIONS(330), 1,
      aux_sym_dynamic_block_end_token1,
  [1398] = 2,
    ACTIONS(332), 1,
      aux_sym_block_end_token1,
    STATE(36), 1,
      sym_block_end,
  [1405] = 2,
    ACTIONS(334), 1,
      aux_sym_list_item_token2,
    ACTIONS(336), 1,
      sym_block_type,
  [1412] = 2,
    ACTIONS(338), 1,
      anon_sym_LF,
    ACTIONS(340), 1,
      aux_sym_list_item_token2,
  [1419] = 2,
    ACTIONS(342), 1,
      sym_latex_env_content,
    ACTIONS(344), 1,
      anon_sym_BSLASHend_LBRACE,
  [1426] = 2,
    ACTIONS(346), 1,
      aux_sym_dynamic_block_end_token1,
    STATE(29), 1,
      sym_dynamic_block_end,
  [1433] = 2,
    ACTIONS(348), 1,
      anon_sym_BSLASHend_LBRACE,
    STATE(40), 1,
      sym_latex_env_end,
  [1440] = 2,
    ACTIONS(350), 1,
      aux_sym_latex_env_begin_token1,
    ACTIONS(352), 1,
      anon_sym_RBRACE,
  [1447] = 2,
    ACTIONS(354), 1,
      sym_block_content,
    ACTIONS(356), 1,
      aux_sym_block_end_token1,
  [1454] = 2,
    ACTIONS(358), 1,
      anon_sym_SPACE,
    ACTIONS(360), 1,
      anon_sym_LF,
  [1461] = 2,
    ACTIONS(362), 1,
      aux_sym_key_token1,
    STATE(126), 1,
      sym_key,
  [1468] = 2,
    ACTIONS(364), 1,
      aux_sym_title_token1,
    STATE(109), 1,
      sym_title,
  [1475] = 2,
    ACTIONS(366), 1,
      anon_sym_COLON,
    ACTIONS(368), 1,
      anon_sym_COLONEND_COLON,
  [1482] = 2,
    ACTIONS(370), 1,
      sym_block_content,
    ACTIONS(372), 1,
      aux_sym_block_end_token1,
  [1489] = 2,
    ACTIONS(374), 1,
      anon_sym_LF,
    ACTIONS(376), 1,
      aux_sym_list_item_token2,
  [1496] = 2,
    ACTIONS(378), 1,
      sym_block_content,
    ACTIONS(380), 1,
      aux_sym_block_end_token1,
  [1503] = 2,
    ACTIONS(382), 1,
      anon_sym_SPACE,
    ACTIONS(384), 1,
      anon_sym_LF,
  [1510] = 2,
    ACTIONS(386), 1,
      sym_dynamic_block_content,
    ACTIONS(388), 1,
      aux_sym_dynamic_block_end_token1,
  [1517] = 2,
    ACTIONS(390), 1,
      aux_sym_title_token1,
    ACTIONS(392), 1,
      aux_sym_list_item_token1,
  [1524] = 2,
    ACTIONS(394), 1,
      anon_sym_RBRACK_LBRACK,
    ACTIONS(396), 1,
      anon_sym_RBRACK_RBRACK,
  [1531] = 2,
    ACTIONS(398), 1,
      anon_sym_LPAREN,
    ACTIONS(400), 1,
      anon_sym_RBRACE_RBRACE_RBRACE,
  [1538] = 2,
    ACTIONS(402), 1,
      aux_sym_key_token1,
    STATE(114), 1,
      sym_drawer_name,
  [1545] = 1,
    ACTIONS(404), 1,
      anon_sym_COLON,
  [1549] = 1,
    ACTIONS(406), 1,
      aux_sym_property_drawer_token1,
  [1553] = 1,
    ACTIONS(408), 1,
      anon_sym_SPACE,
  [1557] = 1,
    ACTIONS(410), 1,
      sym_language,
  [1561] = 1,
    ACTIONS(412), 1,
      anon_sym_LF,
  [1565] = 1,
    ACTIONS(414), 1,
      anon_sym_RBRACE,
  [1569] = 1,
    ACTIONS(416), 1,
      anon_sym_LF,
  [1573] = 1,
    ACTIONS(418), 1,
      aux_sym_list_item_token2,
  [1577] = 1,
    ACTIONS(420), 1,
      anon_sym_LF,
  [1581] = 1,
    ACTIONS(422), 1,
      aux_sym_list_item_token2,
  [1585] = 1,
    ACTIONS(424), 1,
      anon_sym_LF,
  [1589] = 1,
    ACTIONS(426), 1,
      anon_sym_LF,
  [1593] = 1,
    ACTIONS(428), 1,
      aux_sym_link_token1,
  [1597] = 1,
    ACTIONS(430), 1,
      anon_sym_LF,
  [1601] = 1,
    ACTIONS(432), 1,
      anon_sym_RPAREN,
  [1605] = 1,
    ACTIONS(434), 1,
      anon_sym_LF,
  [1609] = 1,
    ACTIONS(436), 1,
      aux_sym_macro_token2,
  [1613] = 1,
    ACTIONS(438), 1,
      anon_sym_RBRACK_RBRACK,
  [1617] = 1,
    ACTIONS(440), 1,
      anon_sym_SPACE,
  [1621] = 1,
    ACTIONS(442), 1,
      anon_sym_LF,
  [1625] = 1,
    ACTIONS(444), 1,
      anon_sym_SPACE,
  [1629] = 1,
    ACTIONS(446), 1,
      aux_sym_list_item_token2,
  [1633] = 1,
    ACTIONS(448), 1,
      anon_sym_LF,
  [1637] = 1,
    ACTIONS(450), 1,
      anon_sym_LF,
  [1641] = 1,
    ACTIONS(452), 1,
      anon_sym_LF,
  [1645] = 1,
    ACTIONS(454), 1,
      aux_sym_title_token1,
  [1649] = 1,
    ACTIONS(456), 1,
      anon_sym_LF,
  [1653] = 1,
    ACTIONS(458), 1,
      anon_sym_LF,
  [1657] = 1,
    ACTIONS(460), 1,
      anon_sym_LF,
  [1661] = 1,
    ACTIONS(462), 1,
      anon_sym_LF,
  [1665] = 1,
    ACTIONS(464), 1,
      anon_sym_LF,
  [1669] = 1,
    ACTIONS(466), 1,
      anon_sym_LF,
  [1673] = 1,
    ACTIONS(468), 1,
      anon_sym_LF,
  [1677] = 1,
    ACTIONS(470), 1,
      anon_sym_LF,
  [1681] = 1,
    ACTIONS(472), 1,
      anon_sym_COLON,
  [1685] = 1,
    ACTIONS(474), 1,
      anon_sym_SPACE,
  [1689] = 1,
    ACTIONS(476), 1,
      anon_sym_RBRACE_RBRACE_RBRACE,
  [1693] = 1,
    ACTIONS(478), 1,
      anon_sym_LF,
  [1697] = 1,
    ACTIONS(480), 1,
      anon_sym_COLON,
  [1701] = 1,
    ACTIONS(482), 1,
      anon_sym_PIPE,
  [1705] = 1,
    ACTIONS(484), 1,
      anon_sym_LF,
  [1709] = 1,
    ACTIONS(486), 1,
      aux_sym_dynamic_block_begin_token2,
  [1713] = 1,
    ACTIONS(488), 1,
      aux_sym_list_item_token2,
  [1717] = 1,
    ACTIONS(490), 1,
      anon_sym_LF,
  [1721] = 1,
    ACTIONS(492), 1,
      anon_sym_SPACE,
  [1725] = 1,
    ACTIONS(494), 1,
      anon_sym_COLON,
  [1729] = 1,
    ACTIONS(496), 1,
      anon_sym_COLON,
  [1733] = 1,
    ACTIONS(498), 1,
      aux_sym_property_drawer_token1,
  [1737] = 1,
    ACTIONS(500), 1,
      anon_sym_RBRACE,
  [1741] = 1,
    ACTIONS(502), 1,
      ts_builtin_sym_end,
  [1745] = 1,
    ACTIONS(504), 1,
      aux_sym_paragraph_token2,
  [1749] = 1,
    ACTIONS(506), 1,
      aux_sym_property_drawer_token1,
  [1753] = 1,
    ACTIONS(508), 1,
      aux_sym_list_item_token2,
  [1757] = 1,
    ACTIONS(510), 1,
      anon_sym_LF,
  [1761] = 1,
    ACTIONS(512), 1,
      aux_sym_list_item_token2,
  [1765] = 1,
    ACTIONS(514), 1,
      sym_name,
  [1769] = 1,
    ACTIONS(516), 1,
      aux_sym_list_item_token1,
  [1773] = 1,
    ACTIONS(518), 1,
      aux_sym_property_drawer_token1,
  [1777] = 1,
    ACTIONS(520), 1,
      anon_sym_COLONend_COLON,
  [1781] = 1,
    ACTIONS(522), 1,
      aux_sym_property_drawer_token1,
  [1785] = 1,
    ACTIONS(524), 1,
      anon_sym_LF,
  [1789] = 1,
    ACTIONS(526), 1,
      sym_block_type,
  [1793] = 1,
    ACTIONS(528), 1,
      anon_sym_LF,
  [1797] = 1,
    ACTIONS(530), 1,
      aux_sym_property_drawer_token1,
  [1801] = 1,
    ACTIONS(532), 1,
      anon_sym_SPACE,
  [1805] = 1,
    ACTIONS(534), 1,
      sym_bullet,
  [1809] = 1,
    ACTIONS(536), 1,
      aux_sym_link_token1,
  [1813] = 1,
    ACTIONS(538), 1,
      anon_sym_LF,
  [1817] = 1,
    ACTIONS(540), 1,
      anon_sym_LF,
  [1821] = 1,
    ACTIONS(542), 1,
      anon_sym_LF,
  [1825] = 1,
    ACTIONS(544), 1,
      aux_sym_latex_env_begin_token1,
  [1829] = 1,
    ACTIONS(546), 1,
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
  [SMALL_STATE(42)] = 1238,
  [SMALL_STATE(43)] = 1249,
  [SMALL_STATE(44)] = 1262,
  [SMALL_STATE(45)] = 1271,
  [SMALL_STATE(46)] = 1284,
  [SMALL_STATE(47)] = 1297,
  [SMALL_STATE(48)] = 1308,
  [SMALL_STATE(49)] = 1321,
  [SMALL_STATE(50)] = 1327,
  [SMALL_STATE(51)] = 1337,
  [SMALL_STATE(52)] = 1347,
  [SMALL_STATE(53)] = 1357,
  [SMALL_STATE(54)] = 1363,
  [SMALL_STATE(55)] = 1371,
  [SMALL_STATE(56)] = 1377,
  [SMALL_STATE(57)] = 1384,
  [SMALL_STATE(58)] = 1391,
  [SMALL_STATE(59)] = 1398,
  [SMALL_STATE(60)] = 1405,
  [SMALL_STATE(61)] = 1412,
  [SMALL_STATE(62)] = 1419,
  [SMALL_STATE(63)] = 1426,
  [SMALL_STATE(64)] = 1433,
  [SMALL_STATE(65)] = 1440,
  [SMALL_STATE(66)] = 1447,
  [SMALL_STATE(67)] = 1454,
  [SMALL_STATE(68)] = 1461,
  [SMALL_STATE(69)] = 1468,
  [SMALL_STATE(70)] = 1475,
  [SMALL_STATE(71)] = 1482,
  [SMALL_STATE(72)] = 1489,
  [SMALL_STATE(73)] = 1496,
  [SMALL_STATE(74)] = 1503,
  [SMALL_STATE(75)] = 1510,
  [SMALL_STATE(76)] = 1517,
  [SMALL_STATE(77)] = 1524,
  [SMALL_STATE(78)] = 1531,
  [SMALL_STATE(79)] = 1538,
  [SMALL_STATE(80)] = 1545,
  [SMALL_STATE(81)] = 1549,
  [SMALL_STATE(82)] = 1553,
  [SMALL_STATE(83)] = 1557,
  [SMALL_STATE(84)] = 1561,
  [SMALL_STATE(85)] = 1565,
  [SMALL_STATE(86)] = 1569,
  [SMALL_STATE(87)] = 1573,
  [SMALL_STATE(88)] = 1577,
  [SMALL_STATE(89)] = 1581,
  [SMALL_STATE(90)] = 1585,
  [SMALL_STATE(91)] = 1589,
  [SMALL_STATE(92)] = 1593,
  [SMALL_STATE(93)] = 1597,
  [SMALL_STATE(94)] = 1601,
  [SMALL_STATE(95)] = 1605,
  [SMALL_STATE(96)] = 1609,
  [SMALL_STATE(97)] = 1613,
  [SMALL_STATE(98)] = 1617,
  [SMALL_STATE(99)] = 1621,
  [SMALL_STATE(100)] = 1625,
  [SMALL_STATE(101)] = 1629,
  [SMALL_STATE(102)] = 1633,
  [SMALL_STATE(103)] = 1637,
  [SMALL_STATE(104)] = 1641,
  [SMALL_STATE(105)] = 1645,
  [SMALL_STATE(106)] = 1649,
  [SMALL_STATE(107)] = 1653,
  [SMALL_STATE(108)] = 1657,
  [SMALL_STATE(109)] = 1661,
  [SMALL_STATE(110)] = 1665,
  [SMALL_STATE(111)] = 1669,
  [SMALL_STATE(112)] = 1673,
  [SMALL_STATE(113)] = 1677,
  [SMALL_STATE(114)] = 1681,
  [SMALL_STATE(115)] = 1685,
  [SMALL_STATE(116)] = 1689,
  [SMALL_STATE(117)] = 1693,
  [SMALL_STATE(118)] = 1697,
  [SMALL_STATE(119)] = 1701,
  [SMALL_STATE(120)] = 1705,
  [SMALL_STATE(121)] = 1709,
  [SMALL_STATE(122)] = 1713,
  [SMALL_STATE(123)] = 1717,
  [SMALL_STATE(124)] = 1721,
  [SMALL_STATE(125)] = 1725,
  [SMALL_STATE(126)] = 1729,
  [SMALL_STATE(127)] = 1733,
  [SMALL_STATE(128)] = 1737,
  [SMALL_STATE(129)] = 1741,
  [SMALL_STATE(130)] = 1745,
  [SMALL_STATE(131)] = 1749,
  [SMALL_STATE(132)] = 1753,
  [SMALL_STATE(133)] = 1757,
  [SMALL_STATE(134)] = 1761,
  [SMALL_STATE(135)] = 1765,
  [SMALL_STATE(136)] = 1769,
  [SMALL_STATE(137)] = 1773,
  [SMALL_STATE(138)] = 1777,
  [SMALL_STATE(139)] = 1781,
  [SMALL_STATE(140)] = 1785,
  [SMALL_STATE(141)] = 1789,
  [SMALL_STATE(142)] = 1793,
  [SMALL_STATE(143)] = 1797,
  [SMALL_STATE(144)] = 1801,
  [SMALL_STATE(145)] = 1805,
  [SMALL_STATE(146)] = 1809,
  [SMALL_STATE(147)] = 1813,
  [SMALL_STATE(148)] = 1817,
  [SMALL_STATE(149)] = 1821,
  [SMALL_STATE(150)] = 1825,
  [SMALL_STATE(151)] = 1829,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_document, 0, 0, 0),
  [5] = {.entry = {.count = 1, .reusable = false}}, SHIFT(82),
  [7] = {.entry = {.count = 1, .reusable = false}}, SHIFT(2),
  [9] = {.entry = {.count = 1, .reusable = false}}, SHIFT(151),
  [11] = {.entry = {.count = 1, .reusable = false}}, SHIFT(150),
  [13] = {.entry = {.count = 1, .reusable = false}}, SHIFT(146),
  [15] = {.entry = {.count = 1, .reusable = false}}, SHIFT(145),
  [17] = {.entry = {.count = 1, .reusable = false}}, SHIFT(144),
  [19] = {.entry = {.count = 1, .reusable = false}}, SHIFT(141),
  [21] = {.entry = {.count = 1, .reusable = false}}, SHIFT(136),
  [23] = {.entry = {.count = 1, .reusable = false}}, SHIFT(48),
  [25] = {.entry = {.count = 1, .reusable = false}}, SHIFT(7),
  [27] = {.entry = {.count = 1, .reusable = false}}, SHIFT(135),
  [29] = {.entry = {.count = 1, .reusable = false}}, SHIFT(79),
  [31] = {.entry = {.count = 1, .reusable = false}}, SHIFT(134),
  [33] = {.entry = {.count = 1, .reusable = false}}, SHIFT(132),
  [35] = {.entry = {.count = 1, .reusable = false}}, SHIFT(131),
  [37] = {.entry = {.count = 1, .reusable = false}}, SHIFT(130),
  [39] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_document, 1, 0, 0),
  [41] = {.entry = {.count = 1, .reusable = false}}, SHIFT(3),
  [43] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0),
  [45] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(82),
  [48] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(3),
  [51] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(151),
  [54] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(150),
  [57] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(146),
  [60] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(145),
  [63] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(144),
  [66] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(141),
  [69] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(136),
  [72] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(48),
  [75] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(7),
  [78] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(135),
  [81] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(79),
  [84] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(134),
  [87] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(132),
  [90] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(131),
  [93] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(130),
  [96] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_table_repeat1, 2, 0, 0),
  [98] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_table_repeat1, 2, 0, 0),
  [100] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_table_repeat1, 2, 0, 0), SHIFT_REPEAT(48),
  [103] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_table_repeat1, 2, 0, 0), SHIFT_REPEAT(4),
  [106] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_list_repeat1, 2, 0, 0),
  [108] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_list_repeat1, 2, 0, 0),
  [110] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_list_repeat1, 2, 0, 0), SHIFT_REPEAT(145),
  [113] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_list_repeat1, 2, 0, 0), SHIFT_REPEAT(144),
  [116] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_list, 1, 0, 0),
  [118] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_list, 1, 0, 0),
  [120] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_table, 1, 0, 0),
  [122] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_table, 1, 0, 0),
  [124] = {.entry = {.count = 1, .reusable = false}}, SHIFT(4),
  [126] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_fixed_width_repeat1, 2, 0, 0),
  [128] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_fixed_width_repeat1, 2, 0, 0),
  [130] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_fixed_width_repeat1, 2, 0, 0), SHIFT_REPEAT(132),
  [133] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_fixed_width, 1, 0, 0),
  [135] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_fixed_width, 1, 0, 0),
  [137] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_latex_env_end, 3, 0, 0),
  [139] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_latex_env_end, 3, 0, 0),
  [141] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_headline, 2, 1, 1),
  [143] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_headline, 2, 1, 1),
  [145] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_directive, 6, 0, 14),
  [147] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_directive, 6, 0, 14),
  [149] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_macro, 4, 0, 0),
  [151] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_macro, 4, 0, 0),
  [153] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_link, 4, 0, 0),
  [155] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_link, 4, 0, 0),
  [157] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_link, 6, 0, 13),
  [159] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_link, 6, 0, 13),
  [161] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_fixed_width_repeat1, 3, 0, 0),
  [163] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_fixed_width_repeat1, 3, 0, 0),
  [165] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_drawer, 9, 0, 0),
  [167] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_drawer, 9, 0, 0),
  [169] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_block_end, 4, 0, 0),
  [171] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_block_end, 4, 0, 0),
  [173] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_latex_env_end, 4, 0, 7),
  [175] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_latex_env_end, 4, 0, 7),
  [177] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_headline, 5, 2, 11),
  [179] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_headline, 5, 2, 11),
  [181] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_drawer, 8, 0, 0),
  [183] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_drawer, 8, 0, 0),
  [185] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_property_drawer, 7, 0, 0),
  [187] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_property_drawer, 7, 0, 0),
  [189] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dynamic_block, 2, 0, 0),
  [191] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_dynamic_block, 2, 0, 0),
  [193] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_list_item, 4, 0, 0),
  [195] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_list_item, 4, 0, 0),
  [197] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_block, 2, 0, 0),
  [199] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_block, 2, 0, 0),
  [201] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_latex_environment, 2, 0, 0),
  [203] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_latex_environment, 2, 0, 0),
  [205] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_comment, 3, 0, 0),
  [207] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_comment, 3, 0, 0),
  [209] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_macro, 7, 0, 0),
  [211] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_macro, 7, 0, 0),
  [213] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dynamic_block, 3, 0, 0),
  [215] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_dynamic_block, 3, 0, 0),
  [217] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_directive, 5, 0, 10),
  [219] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_directive, 5, 0, 10),
  [221] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_table_row, 3, 0, 0),
  [223] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_table_row, 3, 0, 0),
  [225] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_paragraph, 2, 0, 0),
  [227] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_paragraph, 2, 0, 0),
  [229] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_headline, 3, 2, 3),
  [231] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_headline, 3, 2, 3),
  [233] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_table_row, 2, 0, 0),
  [235] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_table_row, 2, 0, 0),
  [237] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_list_item, 5, 0, 0),
  [239] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_list_item, 5, 0, 0),
  [241] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_block, 3, 0, 0),
  [243] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_block, 3, 0, 0),
  [245] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dynamic_block_end, 3, 0, 0),
  [247] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_dynamic_block_end, 3, 0, 0),
  [249] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_headline, 3, 1, 4),
  [251] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_headline, 3, 1, 4),
  [253] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_block_end, 3, 0, 0),
  [255] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_block_end, 3, 0, 0),
  [257] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_latex_environment, 3, 0, 0),
  [259] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_latex_environment, 3, 0, 0),
  [261] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__headline_prefix, 2, 0, 0),
  [263] = {.entry = {.count = 1, .reusable = false}}, SHIFT(100),
  [265] = {.entry = {.count = 1, .reusable = false}}, SHIFT(98),
  [267] = {.entry = {.count = 1, .reusable = false}}, SHIFT(68),
  [269] = {.entry = {.count = 1, .reusable = true}}, SHIFT(127),
  [271] = {.entry = {.count = 1, .reusable = false}}, SHIFT(31),
  [273] = {.entry = {.count = 1, .reusable = false}}, SHIFT(45),
  [275] = {.entry = {.count = 1, .reusable = false}}, SHIFT(119),
  [277] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__headline_prefix, 4, 0, 5),
  [279] = {.entry = {.count = 1, .reusable = false}}, SHIFT(115),
  [281] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_table_row_repeat1, 2, 0, 0),
  [283] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_table_row_repeat1, 2, 0, 0), SHIFT_REPEAT(45),
  [286] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_table_row_repeat1, 2, 0, 0), SHIFT_REPEAT(119),
  [289] = {.entry = {.count = 1, .reusable = false}}, SHIFT(11),
  [291] = {.entry = {.count = 1, .reusable = false}}, SHIFT(67),
  [293] = {.entry = {.count = 1, .reusable = false}}, SHIFT(107),
  [295] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_property_drawer_repeat1, 2, 0, 0), SHIFT_REPEAT(68),
  [298] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_property_drawer_repeat1, 2, 0, 0),
  [300] = {.entry = {.count = 1, .reusable = false}}, SHIFT(34),
  [302] = {.entry = {.count = 1, .reusable = false}}, SHIFT(43),
  [304] = {.entry = {.count = 1, .reusable = true}}, SHIFT(63),
  [306] = {.entry = {.count = 1, .reusable = false}}, SHIFT(101),
  [308] = {.entry = {.count = 1, .reusable = true}}, SHIFT(59),
  [310] = {.entry = {.count = 1, .reusable = false}}, SHIFT(60),
  [312] = {.entry = {.count = 1, .reusable = true}}, SHIFT(64),
  [314] = {.entry = {.count = 1, .reusable = false}}, SHIFT(65),
  [316] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__headline_prefix, 6, 0, 12),
  [318] = {.entry = {.count = 1, .reusable = true}}, SHIFT(68),
  [320] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__headline_prefix, 4, 0, 6),
  [322] = {.entry = {.count = 1, .reusable = false}}, SHIFT(137),
  [324] = {.entry = {.count = 1, .reusable = true}}, SHIFT(138),
  [326] = {.entry = {.count = 1, .reusable = true}}, SHIFT(148),
  [328] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dynamic_block_begin, 4, 0, 8),
  [330] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_dynamic_block_begin, 4, 0, 8),
  [332] = {.entry = {.count = 1, .reusable = true}}, SHIFT(60),
  [334] = {.entry = {.count = 1, .reusable = true}}, SHIFT(88),
  [336] = {.entry = {.count = 1, .reusable = false}}, SHIFT(89),
  [338] = {.entry = {.count = 1, .reusable = false}}, SHIFT(73),
  [340] = {.entry = {.count = 1, .reusable = false}}, SHIFT(120),
  [342] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_latex_env_begin, 4, 0, 7),
  [344] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_latex_env_begin, 4, 0, 7),
  [346] = {.entry = {.count = 1, .reusable = true}}, SHIFT(101),
  [348] = {.entry = {.count = 1, .reusable = true}}, SHIFT(65),
  [350] = {.entry = {.count = 1, .reusable = true}}, SHIFT(85),
  [352] = {.entry = {.count = 1, .reusable = true}}, SHIFT(86),
  [354] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_block_begin, 6, 0, 9),
  [356] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_block_begin, 6, 0, 9),
  [358] = {.entry = {.count = 1, .reusable = false}}, SHIFT(69),
  [360] = {.entry = {.count = 1, .reusable = false}}, SHIFT(33),
  [362] = {.entry = {.count = 1, .reusable = true}}, SHIFT(125),
  [364] = {.entry = {.count = 1, .reusable = true}}, SHIFT(107),
  [366] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_property, 6, 0, 0),
  [368] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_property, 6, 0, 0),
  [370] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_block_begin, 3, 0, 2),
  [372] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_block_begin, 3, 0, 2),
  [374] = {.entry = {.count = 1, .reusable = false}}, SHIFT(58),
  [376] = {.entry = {.count = 1, .reusable = false}}, SHIFT(103),
  [378] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_block_begin, 5, 0, 9),
  [380] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_block_begin, 5, 0, 9),
  [382] = {.entry = {.count = 1, .reusable = false}}, SHIFT(83),
  [384] = {.entry = {.count = 1, .reusable = false}}, SHIFT(71),
  [386] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dynamic_block_begin, 5, 0, 8),
  [388] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_dynamic_block_begin, 5, 0, 8),
  [390] = {.entry = {.count = 1, .reusable = false}}, SHIFT(104),
  [392] = {.entry = {.count = 1, .reusable = false}}, SHIFT(105),
  [394] = {.entry = {.count = 1, .reusable = true}}, SHIFT(92),
  [396] = {.entry = {.count = 1, .reusable = true}}, SHIFT(90),
  [398] = {.entry = {.count = 1, .reusable = true}}, SHIFT(96),
  [400] = {.entry = {.count = 1, .reusable = true}}, SHIFT(95),
  [402] = {.entry = {.count = 1, .reusable = true}}, SHIFT(80),
  [404] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_drawer_name, 1, 0, 0),
  [406] = {.entry = {.count = 1, .reusable = true}}, SHIFT(106),
  [408] = {.entry = {.count = 1, .reusable = true}}, SHIFT(41),
  [410] = {.entry = {.count = 1, .reusable = true}}, SHIFT(61),
  [412] = {.entry = {.count = 1, .reusable = true}}, SHIFT(24),
  [414] = {.entry = {.count = 1, .reusable = true}}, SHIFT(110),
  [416] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
  [418] = {.entry = {.count = 1, .reusable = true}}, SHIFT(99),
  [420] = {.entry = {.count = 1, .reusable = true}}, SHIFT(39),
  [422] = {.entry = {.count = 1, .reusable = true}}, SHIFT(113),
  [424] = {.entry = {.count = 1, .reusable = true}}, SHIFT(14),
  [426] = {.entry = {.count = 1, .reusable = true}}, SHIFT(37),
  [428] = {.entry = {.count = 1, .reusable = true}}, SHIFT(97),
  [430] = {.entry = {.count = 1, .reusable = true}}, SHIFT(62),
  [432] = {.entry = {.count = 1, .reusable = true}}, SHIFT(116),
  [434] = {.entry = {.count = 1, .reusable = true}}, SHIFT(13),
  [436] = {.entry = {.count = 1, .reusable = true}}, SHIFT(94),
  [438] = {.entry = {.count = 1, .reusable = true}}, SHIFT(117),
  [440] = {.entry = {.count = 1, .reusable = true}}, SHIFT(55),
  [442] = {.entry = {.count = 1, .reusable = true}}, SHIFT(35),
  [444] = {.entry = {.count = 1, .reusable = true}}, SHIFT(44),
  [446] = {.entry = {.count = 1, .reusable = true}}, SHIFT(91),
  [448] = {.entry = {.count = 1, .reusable = true}}, SHIFT(38),
  [450] = {.entry = {.count = 1, .reusable = true}}, SHIFT(75),
  [452] = {.entry = {.count = 1, .reusable = true}}, SHIFT(30),
  [454] = {.entry = {.count = 1, .reusable = true}}, SHIFT(123),
  [456] = {.entry = {.count = 1, .reusable = true}}, SHIFT(56),
  [458] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_title, 1, 0, 0),
  [460] = {.entry = {.count = 1, .reusable = true}}, SHIFT(54),
  [462] = {.entry = {.count = 1, .reusable = true}}, SHIFT(20),
  [464] = {.entry = {.count = 1, .reusable = true}}, SHIFT(19),
  [466] = {.entry = {.count = 1, .reusable = true}}, SHIFT(16),
  [468] = {.entry = {.count = 1, .reusable = true}}, SHIFT(27),
  [470] = {.entry = {.count = 1, .reusable = true}}, SHIFT(18),
  [472] = {.entry = {.count = 1, .reusable = true}}, SHIFT(81),
  [474] = {.entry = {.count = 1, .reusable = true}}, SHIFT(53),
  [476] = {.entry = {.count = 1, .reusable = true}}, SHIFT(133),
  [478] = {.entry = {.count = 1, .reusable = true}}, SHIFT(15),
  [480] = {.entry = {.count = 1, .reusable = true}}, SHIFT(76),
  [482] = {.entry = {.count = 1, .reusable = true}}, SHIFT(49),
  [484] = {.entry = {.count = 1, .reusable = true}}, SHIFT(66),
  [486] = {.entry = {.count = 1, .reusable = true}}, SHIFT(72),
  [488] = {.entry = {.count = 1, .reusable = true}}, SHIFT(84),
  [490] = {.entry = {.count = 1, .reusable = true}}, SHIFT(12),
  [492] = {.entry = {.count = 1, .reusable = true}}, SHIFT(87),
  [494] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_key, 1, 0, 0),
  [496] = {.entry = {.count = 1, .reusable = true}}, SHIFT(139),
  [498] = {.entry = {.count = 1, .reusable = true}}, SHIFT(140),
  [500] = {.entry = {.count = 1, .reusable = true}}, SHIFT(93),
  [502] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [504] = {.entry = {.count = 1, .reusable = true}}, SHIFT(32),
  [506] = {.entry = {.count = 1, .reusable = true}}, SHIFT(108),
  [508] = {.entry = {.count = 1, .reusable = true}}, SHIFT(111),
  [510] = {.entry = {.count = 1, .reusable = true}}, SHIFT(28),
  [512] = {.entry = {.count = 1, .reusable = true}}, SHIFT(112),
  [514] = {.entry = {.count = 1, .reusable = true}}, SHIFT(118),
  [516] = {.entry = {.count = 1, .reusable = true}}, SHIFT(121),
  [518] = {.entry = {.count = 1, .reusable = true}}, SHIFT(142),
  [520] = {.entry = {.count = 1, .reusable = true}}, SHIFT(143),
  [522] = {.entry = {.count = 1, .reusable = true}}, SHIFT(57),
  [524] = {.entry = {.count = 1, .reusable = true}}, SHIFT(22),
  [526] = {.entry = {.count = 1, .reusable = true}}, SHIFT(74),
  [528] = {.entry = {.count = 1, .reusable = true}}, SHIFT(21),
  [530] = {.entry = {.count = 1, .reusable = true}}, SHIFT(147),
  [532] = {.entry = {.count = 1, .reusable = true}}, SHIFT(122),
  [534] = {.entry = {.count = 1, .reusable = true}}, SHIFT(124),
  [536] = {.entry = {.count = 1, .reusable = true}}, SHIFT(77),
  [538] = {.entry = {.count = 1, .reusable = true}}, SHIFT(17),
  [540] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_value, 1, 0, 0),
  [542] = {.entry = {.count = 1, .reusable = true}}, SHIFT(70),
  [544] = {.entry = {.count = 1, .reusable = true}}, SHIFT(128),
  [546] = {.entry = {.count = 1, .reusable = true}}, SHIFT(78),
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
