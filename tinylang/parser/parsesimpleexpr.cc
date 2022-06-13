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

        return new AstBinaryOpNode{d_lexer->lineNumber(), termLeft, addOpVal, termRight};
    }
    else
    {
        // Setting as false as we looked ahead for add op
        d_isCurrentParsed = false;
        return termLeft;
    }    
}