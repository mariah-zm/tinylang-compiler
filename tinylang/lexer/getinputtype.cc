#include "lexer.h"

Lexer::InputType Lexer::getInputType(char val) const
{
    if (isdigit(val))
        return DIGIT;
    else if (val == '.')
        return DOT;
    else if (isalpha(val))
        return LETTER;
    else if (val == '_')
        return UNDSCR;
    else if (isspace(val))
        return SPACE;
    else if (val == '\'')
        return QUOTE;
    else if (isprint(val))
        return PRINT;
    else
        return OTHER;
}