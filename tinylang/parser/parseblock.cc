#include "parser.ih"

AstBlockNode *Parser::parseBlock()
{
    AstBlockNode *body = new AstBlockNode;
    // Skipping {
    d_currentTok = d_lexer.getNextToken();

    if (d_currentTok.type() != Token::OPEN_SCOPE)
        throw syntax_error("expected \'{\'");

    d_currentTok = d_lexer.getNextToken();

    while (true)
    {
        auto stmtNode = parseStatement();
        body->addStatementChild(stmtNode);

        // Checking for }
        d_currentTok = d_lexer.getNextToken();

        if (d_currentTok.type() != Token::CLOSE_SCOPE)
            break;
    }

    return body;
}