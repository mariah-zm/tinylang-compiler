#include "parser.ih"

void Parser::parseSemiColon()
{
    // Consuming ;
    d_currentTok = getNextToken();
    
    if (d_currentTok.type() != Token::SEMI_COLON)
        throw syntax_error("expected \';\'");
}