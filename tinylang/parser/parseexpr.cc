#include "parser.ih"

AstExprNode *Parser::parseExpr()
{
    AstExprNode *simpleExprLeft = parseSimpleExpr();

    d_currentTok = getNextToken();

    // Checking if expression contains relational operator
    if (d_currentTok.isRelOp())
    {
        string relOpVal = d_currentTok.value();
        AstExprNode *simpleExprRight = parseExpr();

        return new AstBinaryOpNode{d_lexer->lineNumber(), simpleExprLeft, 
                                    relOpVal, simpleExprRight};
    }
    else
    {
        // Setting as false as we looked ahead for rel op
        d_isCurrentParsed = false;
        return simpleExprLeft;
    }   
}