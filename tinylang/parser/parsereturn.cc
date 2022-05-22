#include "parser.ih"

AstReturnStmtNode *Parser::parseReturn()
{
    AstExprNode *expr = parseExpr();
    return new AstReturnStmtNode{expr};
}