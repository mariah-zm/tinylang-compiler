#include "lexer.ih"

Token::TokenType Lexer::getTokenType(State state)
{
    switch (state)
    {
    case S1:
    case S2:
        return Token::NUMBER;
    case S3:
        return Token::IDENTIFIER;
    case S6:
        return Token::CHAR_LITERAL;
    case S7:
        return Token::ASSIGNMENT;
    case S9:
    case S10:
        return Token::REL_OP;
    default:
        return Token::OTHER;    
    }
}