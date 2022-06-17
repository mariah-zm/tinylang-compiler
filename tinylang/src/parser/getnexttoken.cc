#include "parser.ih"

Token Parser::getNextToken()
{
    if (d_isCurrentParsed)
        return d_lexer->getNextToken();
    else 
    {
        // Setting as true to assume it will be parsed
        d_isCurrentParsed = true;
        return d_currentTok;
    }
}