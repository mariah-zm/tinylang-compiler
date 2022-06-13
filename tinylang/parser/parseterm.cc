#include "parser.ih"

AstExprNode *Parser::parseTerm()
{
    AstExprNode *factorLeft = parseFactor();

    d_currentTok = getNextToken();

    // Checking if expression contains multiplicative operator
    if (d_currentTok.isMulOp())
    {
        string mulOpVal = d_currentTok.value();
        AstExprNode *factorRight = parseTerm();

        return new AstBinaryOpNode{d_lexer->lineNumber(), factorLeft, mulOpVal, factorRight};
    }
    else
    {    
        // Setting as false as we looked ahead for mul op
        d_isCurrentParsed = false;
        return factorLeft;
    }
}