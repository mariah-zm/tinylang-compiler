#include "parser.ih"

AstExprNode *Parser::parseSimpleExpr()
{
    AstExprNode *termLeft = parseTerm();

    d_currentTok = getNextToken();

    // Checking if expression contains additive operator
    if (d_currentTok.isAddOp())
    {
        string addOpVal = d_currentTok.value();
        AstExprNode *termRight = parseSimpleExpr();

        return new AstAddOpNode{termLeft, addOpVal, termRight};
    }
    else
    {
        // Setting as false as we looked ahead for ad dop
        d_isCurrentParsed = false;
        return termLeft;
    }    
}