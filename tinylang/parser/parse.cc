#include "parser.ih"

AstNode *Parser::parse()
{
    AstProgramNode *rootNode = new AstProgramNode();
    d_currentTok = d_lexer.getNextToken();

    while (!d_currentTok.isEof())
    {
        if (d_currentTok.type() == Token::FN)
            AstFunctionNode *fn = parseFunctionDef();
        else
        {
            AstStatementNode *stmt = parseStatement();
            rootNode->addStatementChild(stmt);
        }

        d_currentTok = d_lexer.getNextToken();
    }

    return rootNode;
}