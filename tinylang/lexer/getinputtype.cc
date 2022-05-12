#include "lexer.ih"

Lexer::Input::InputType Lexer::Input::getInputType(char val) const
{
    if (isdigit(val))
        return DIGIT;
    else if (isalpha(val))
        return LETTER;
    else if (isspace(val))
        return SPACE;
    else if (d_punctuation.find(val) != std::string::npos)
        return PUNCT;
    else
    {
        try 
        {
            return d_charInputs.at(val);
        } 
        catch (out_of_range &e) 
        {
            if (isprint(val))
                return PRINT;
            else
                throw runtime_error("lexical error - input not accepted");
        }
    }
}