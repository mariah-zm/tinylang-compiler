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
    case S11:
    case S12:
    case S13:
    case S14:
        return Token::MATH_OP;
    case S16:
    case S18:
        return Token::COMMENT;
    case S19:
        return Token::ARROW;
    case S20:
        return Token::PUNCT;
    default:
        throw lexical_error("unknown token type");
    }
}