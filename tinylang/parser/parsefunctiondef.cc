#include "parser.ih"

AstFunctionNode *Parser::parseFunctionDef()
{
    d_currentTok = d_lexer.getNextToken();
}