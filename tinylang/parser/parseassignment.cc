#include "parser.ih"

AstAssignmentNode *Parser::parseAssignment()
{
    string name = d_currentTok.value();

    // Consuming =
    d_currentTok = getNextToken();
    
    if (d_currentTok.type() != Token::ASSIGNMENT)
        throw syntax_error("expected \'=\' in line " 
                + to_string(d_lexer->lineNumber()));

    AstExprNode *expr = parseExpr();

    return new AstAssignmentNode{d_lexer->lineNumber(), name, expr};
}