#include "lexer.ih"

Lexer::InputType Lexer::getInputType(char val) const
{
    string angleB = "><";
    string punctuation = "{}():;,";

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
    else if (val == '=')
        return EQ_SIGN;
    else if (angleB.find(val) != std::string::npos)
        return ANGLE_B;
    else if (val == '!')
        return EXCLM;
    else if (val == '+')
        return ADD;
    else if (val == '-')
        return MINUS;
    else if (val == '*')
        return MUL;
    else if (val == '/')
        return DIV;
    else if (punctuation.find(val) != std::string::npos)
        return PUNCT;
    else if (isprint(val))
        return PRINT;
    else
        throw runtime_error("lexical error - input not accepted");
}