#include "parser.ih"

#include "../exceptions/syntaxerror.h"

AstFunctionNode *Parser::parseFunctionDef()
{
    d_currentTok = d_lexer.getNextToken();
    
    auto prototypeNode = parseFunctionPrototype();
    auto bodyNode = parseBlock();

    return new AstFunctionNode{prototypeNode, bodyNode};
}