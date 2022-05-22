#include "parser.ih"

AstWhileStmtNode *Parser::parseWhile()
{
    // Consuming (
    d_currentTok = d_lexer.getNextToken();

    if (d_currentTok.type() != Token::OPEN_SCOPE)
        throw syntax_error("expected \'(\'");

    AstExprNode *expr = parseExpr();

    // Consuming )
    d_currentTok = d_lexer.getNextToken();

    if (d_currentTok.type() != Token::OPEN_SCOPE)
        throw syntax_error("expected \')\'");

    AstBlockNode *block = parseBlock();

    return new AstWhileStmtNode{expr, block};
}