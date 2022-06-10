#include "identifier.ih"

Identifier::Type Identifier::getType(Token::TokenType tokType)
{
    switch (tokType)
    {
        case Token::FLOAT: return FLOAT;
        case Token::INT: return INT;
        case Token::BOOL: return BOOL;
        case Token::CHAR: return CHAR;
        default: throw syntax_error("not a type");;
    }
}