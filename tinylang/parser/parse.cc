#include "parser.ih"

AstProgramNode *Parser::parse()
{
    AstProgramNode *rootNode = new AstProgramNode();
    d_currentTok = getNextToken();

    while (!d_currentTok.isEof())
    {
        AstStatementNode *stmt = parseStatement();
        rootNode->addStatement(stmt);

        d_currentTok = getNextToken();
    }

    return rootNode;
}