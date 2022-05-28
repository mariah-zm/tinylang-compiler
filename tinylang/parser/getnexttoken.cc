#include "parser.ih"

Token Parser::getNextToken()
{
    if (d_isCurrentParsed)
        return d_lexer.getNextToken();
    else 
    {
        // Setting as true as all tokens will be parsed on second attempt
        d_isCurrentParsed = true;
        return d_currentTok;
    }
}