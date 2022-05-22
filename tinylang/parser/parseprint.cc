#include "parser.ih"

AstPrintStmtNode *Parser::parsePrint()
{
    AstExprNode *expr = parseExpr();
    return new AstPrintStmtNode{expr};
}