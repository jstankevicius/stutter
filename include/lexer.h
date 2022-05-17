#pragma once

#include <vector>
#include <string.h>
#include <unordered_map>

#include "token.h"

// Macros:
#define is_alpha(c) (('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z') || c == '_')
#define is_numeric(c) ('0' <= c && c <= '9')
#define is_whitespace(c) (c == ' ' || c == '\t')
#define is_alphanumeric(c) (is_alpha(c) || is_numeric(c))

#define is_arithmetic_operator(c) (c == '+' || c == '-' || c == '*' || c == '/' || c == '^')
#define is_comparator(c) (c == '=' || c == '<' || c == '>')
#define is_operator(c) (is_comparator(c) || is_arithmetic_operator(c))

struct Lexer {
    int stream_idx = 0;

    int line_num = 1;
    int col_num = 1;

    std::string stream;
    std::vector<Token*> tokens;

    std::unordered_map<std::string, Token_Type> reserved_types;

    Lexer(std::string& stream);

    char cur_char();
    void advance_char();
    char lookahead_char(int lookahead);
    char lookahead_char_at(int idx, int lookahead);
    void skip_whitespace();
    bool done();

};

std::vector<Token*> get_tokens(Lexer* lexer);

