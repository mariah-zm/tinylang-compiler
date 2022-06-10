#include "parser.ih"

AstProgramNode *Parser::parse()
{
    AstProgramNode *rootNode = new AstProgramNode();
    d_currentTok = getNextToken();

    while (!d_currentTok.isEof())
    {
        if (d_currentTok.type() == Token::FN)
        {    
            AstFunctionNode *fn = parseFunctionDef();
            rootNode->addFunction(fn->prototype());
        }
        else
        {
            AstStatementNode *stmt = parseStatement();
            rootNode->addStatementChild(stmt);
        }

         d_currentTok = getNextToken();
    }

    return rootNode;
}