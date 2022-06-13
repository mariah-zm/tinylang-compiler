#include "parser.ih"

AstWhileStmtNode *Parser::parseWhile()
{
    // Consuming (
    d_currentTok = getNextToken();

    if (d_currentTok.type() != Token::OPEN_BR)
        throw syntax_error("expected \'(\' in line " 
                + to_string(d_lexer->lineNumber()));

    AstExprNode *expr = parseExpr();

    // Consuming )
    d_currentTok = getNextToken();

    if (d_currentTok.type() != Token::CLOSE_BR)
        throw syntax_error("expected \')\' in line " 
                + to_string(d_lexer->lineNumber()));

    AstBlockNode *block = parseBlock();

    return new AstWhileStmtNode{expr, block};
}