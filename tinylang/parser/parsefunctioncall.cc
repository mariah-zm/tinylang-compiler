#include "parser.ih"

AstFunctionCallNode *Parser::parseFunctionCall(std::string fnName)
{
    vector<AstExprNode *> args;

    d_currentTok = getNextToken();
    d_isCurrentParsed = false;
    
    // Checking if the function has no arguments
    if (d_currentTok.type() != Token::CLOSE_BR)
        do 
        {
            AstExprNode *arg = parseExpr();
            args.push_back(arg);

            d_currentTok = getNextToken();
        } while (d_currentTok.type() == Token::COMMA); // parse more arguments  

    // Consuming )
    if (d_currentTok.type() != Token::CLOSE_BR)
        throw syntax_error("expected \')\'");

    return new AstFunctionCallNode(fnName, args);
}