#include "identifier.ih"

Identifier::Identifier(string name, Token::TokenType type)
:
    d_name(name)
{  
    switch (type)
    {
        case Token::FLOAT:
            d_type = FLOAT;
            break;
        case Token::INT:
            d_type = INT;
            break;
        case Token::CHAR:
            d_type = CHAR;
            break;
        default:
            d_type = BOOL;
    }
}