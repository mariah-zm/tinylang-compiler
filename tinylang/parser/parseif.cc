#include "parser.ih"

AstIfStmtNode *Parser::parseIf()
{
    // Consuming (
    d_currentTok = getNextToken();

    if (d_currentTok.type() != Token::OPEN_BR)
        throw syntax_error("expected \'(\'");

    AstExprNode *condition = parseExpr();

    // Consuming )
    d_currentTok = getNextToken();

    if (d_currentTok.type() != Token::CLOSE_BR)
        throw syntax_error("expected \')\'");

    AstBlockNode *body = parseBlock();

    d_currentTok = getNextToken();

    if (d_currentTok.type() == Token::ELSE)
    {
        AstBlockNode *elseBody = parseBlock();
        return new AstIfStmtNode{condition, body, elseBody}; 
    }
    
    // Setting as false as we looked ahead for else
    d_isCurrentParsed = false;
    return new AstIfStmtNode{condition, body};    
}