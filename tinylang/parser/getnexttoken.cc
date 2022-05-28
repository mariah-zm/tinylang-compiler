#include "parser.ih"

Token Parser::getNextToken()
{
    cout << d_currentTok.value() << endl;

    if (d_isCurrentParsed)
        return d_lexer->getNextToken();
    else 
    {
        // Setting as true to assume it will be parsed
        d_isCurrentParsed = true;
        return d_currentTok;
    }
}