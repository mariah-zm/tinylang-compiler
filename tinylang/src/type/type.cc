#include "type.ih"

Type::Type(Token::TokenType tokType)
{
    switch (tokType)
    {
        case Token::FLOAT: 
            d_type = FLOAT;
            break;
        case Token::INT: 
            d_type = INT;
            break;
        case Token::BOOL: 
            d_type = BOOL;
            break;
        case Token::CHAR: 
            d_type = CHAR;
            break;
        default: throw syntax_error("not a type");;
    }
}