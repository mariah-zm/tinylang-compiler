#include "parser.ih"

AstAssignmentNode *Parser::parseAssignment()
{
    // Getting identifer name
    d_currentTok = d_lexer.getNextToken();
    
    if (d_currentTok.type() != Token::IDENTIFIER)
        throw syntax_error("expected identifier name");

    string name = d_currentTok.value();

    // Consuming =
    d_currentTok = d_lexer.getNextToken();
    
    if (d_currentTok.type() != Token::ASSIGNMENT)
        throw syntax_error("expected \'=\'");

    AstExprNode *expr = parseExpr();

    return new AstAssignmentNode{name, expr};
}