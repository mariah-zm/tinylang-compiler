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
    }
}