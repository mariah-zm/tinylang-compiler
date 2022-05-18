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
    case S7:
    case S8:
        return Token::CHAR_LITERAL;
    case S9:
        return Token::ASSIGNMENT;
    case S11:
    case S12:
        return Token::REL_OP;
    case S13:
    case S14:
    case S15:
    case S16:
        return Token::MATH_OP;
    case S18:
    case S20:
        return Token::COMMENT;
    case S21:
        return Token::ARROW;
    case S22:
        return Token::PUNCT;
    default:
        throw lexical_error("unknown token type");
    }
}