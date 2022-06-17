#include "parser.ih"

AstReturnStmtNode *Parser::parseReturn()
{
    AstExprNode *expr = parseExpr();
    return new AstReturnStmtNode{d_lexer->lineNumber(), expr};
}