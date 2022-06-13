#include "parser.ih"

AstForStmtNode *Parser::parseFor()
{
    AstVarDeclNode *varDecl = nullptr;
    AstExprNode *expr;
    AstAssignmentNode *assignment = nullptr;
    AstBlockNode *block;

    // Consuming (
    d_currentTok = getNextToken();

    if (d_currentTok.type() != Token::OPEN_BR)
        throw syntax_error("expected \'(\'");

    // Checking if var decl was skipped
    d_currentTok = getNextToken();

    if (d_currentTok.type() == Token::LET)
    {
        varDecl = parseVarDecl();
        d_currentTok = getNextToken();
    }

    // Consuming ;
    if (d_currentTok.type() != Token::SEMI_COLON)
        throw syntax_error("expected \';\'");

    // Parsing expression
    expr = parseExpr();

    parseSemiColon();

    // Checking if  assignmnet was skipped
    d_currentTok = getNextToken();

    if (d_currentTok.type() == Token::IDENTIFIER)
    {
        assignment = parseAssignment();
        d_currentTok = getNextToken();
    }

    // Consuming )
    if (d_currentTok.type() != Token::CLOSE_BR)
        throw syntax_error("expected \')\'");

    block = parseBlock();

    return new AstForStmtNode{varDecl, expr, assignment, block};
}