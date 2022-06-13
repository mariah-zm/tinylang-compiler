#include "parser.ih"

AstBlockNode *Parser::parseBlock()
{
    AstBlockNode *body = new AstBlockNode;

    // Consuming {
    d_currentTok = getNextToken();

    if (d_currentTok.type() != Token::OPEN_SCOPE)
        throw syntax_error("expected \'{\' in line " 
                + to_string(d_lexer->lineNumber()));

    d_currentTok = getNextToken();

    while (true)
    {
        auto stmtNode = parseStatement();
        body->addStatementChild(stmtNode);

        // Checking for }
        d_currentTok = getNextToken();

        if (d_currentTok.type() == Token::CLOSE_SCOPE)
            break;
    }

    return body;
}