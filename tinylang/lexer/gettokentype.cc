#include "lexer.ih"

Token::TokenType Lexer::getTokenType(State state)
{
    switch (state)
    {
    case S1:
        return Token::INT_LIT;
    case S2:
        return Token::FLOAT_LIT;
    case S3:
        return Token::IDENTIFIER;
    case S7:
    case S8:
        return Token::CHAR_LIT;
    case S9:
        return Token::ASSIGNMENT;
    case S11:
    case S12:
        return Token::REL_OP;
    case S13:
        return Token::ADD;
    case S14:
        return Token::SUB;
    case S15:
        return Token::MUL;
    case S16:
        return Token::DIV;
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