#include "lexer.ih"

Lexer::Input::InputType Lexer::getInputType(char val) const
{
    if (isdigit(val))
        return Input::DIGIT;
    else if (isalpha(val))
        return Input::LETTER;
    else if (isspace(val))
        return Input::SPACE;
    else if (s_inputHelper.d_punctuation.find(val) != string::npos)
        return Input::PUNCT;
    else
    {
        try 
        {
            return s_inputHelper.d_charInputs.at(val);
        } 
        catch (out_of_range &e) 
        {
            if (isprint(val))
                return Input::PRINT;
            else
                throw lexical_error("character not accepted in line " 
                        + to_string(d_lineNumber));
        }
    }
}