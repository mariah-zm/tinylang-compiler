#include "parser.ih"

AstIfStmtNode *Parser::parseIf()
{
    // Consuming (
    d_currentTok = d_lexer.getNextToken();

    if (d_currentTok.type() != Token::OPEN_SCOPE)
        throw syntax_error("expected \'(\'");

    AstExprNode *condition = parseExpr();

    // Consuming )
    d_currentTok = d_lexer.getNextToken();

    if (d_currentTok.type() != Token::OPEN_SCOPE)
        throw syntax_error("expected \')\'");

    AstBlockNode *body = parseBlock();

    d_currentTok = d_lexer.getNextToken();

    if (d_currentTok.type() == Token::ELSE)
    {
        AstBlockNode *elseBody = parseBlock();
        return new AstIfStmtNode{condition, body, elseBody}; 
    }
    
    return new AstIfStmtNode{condition, body};    
}