#include "token.ih"

Token::Token(string value, TokenType type)
:
    d_value(value)  
{
    // Assigning type as necessary
    if (type == REL_OP)
        d_type = d_relOpMap.at(value);
    else if (type == PUNCT)
        d_type = d_punctMap.at(value);
    else if (type == IDENTIFIER)
        try 
        {
            // Checking if an entered identifier is a keyword
            d_type = d_keywordsMap.at(value);
        } 
        catch (out_of_range &ex)
        {
            d_type = type;
        }
    else 
        d_type = type;
}