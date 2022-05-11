#include "token.ih"

Token::Token(string value, TokenType type)
:
    d_value(value)
{
    // Checking if an entered word is a keyword
    if (type == IDENTIFIER && s_keywords.find(value) != s_keywords.end())
        d_type = KEYWORD;
    else
        d_type = type;
}