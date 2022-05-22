#include "parser.ih"

AstFunctionNode *Parser::parseFunctionDef()
{
    auto prototypeNode = parseFunctionPrototype();
    auto bodyNode = parseBlock();

    return new AstFunctionNode{prototypeNode, bodyNode};
}