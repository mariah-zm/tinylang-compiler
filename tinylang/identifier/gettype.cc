#include "identifier.ih"

Identifier::Type Identifier::getType(Token::TokenType tokType)
{
    if (tokType == Token::FLOAT)
        return FLOAT;
    else if (tokType == Token::INT)
        return INT;
    else if (tokType == Token::CHAR)
        return CHAR;
    else if (tokType == Token::BOOL)
        return BOOL;
    else
        throw syntax_error("not a type");
}