#include "parser.ih"

AstExprNode *Parser::parseFactor()
{
    d_currentTok = getNextToken();

    if (d_currentTok.isLiteral())                       // Literal
        return parseLiteral();
    else if (d_currentTok.type() == Token::IDENTIFIER)  // Identifier or FnCall
    {
        string idenName = d_currentTok.value();

        // Looking ahead to check if function call
        d_currentTok = getNextToken();

        if (d_currentTok.type() == Token::OPEN_BR)
            return parseFunctionCall(idenName);        

        d_isCurrentParsed = false;
        return new AstIdentifierNode{d_lexer->lineNumber(), idenName};
    }
    else if (d_currentTok.type() == Token::OPEN_BR)     // SubExpression
    {
        AstExprNode *expr = parseExpr();

        // Consuming )
        d_currentTok = getNextToken();

        if (d_currentTok.type() != Token::CLOSE_BR)
            throw syntax_error("missing \')\' in line " 
                    + to_string(d_lexer->lineNumber()));

        return expr;
    }
    else if (d_currentTok.isUnaryOp())                  // Unary
    {
        string val = d_currentTok.value();
        AstExprNode *expr = parseExpr();
        return new AstUnaryNode{d_lexer->lineNumber(), val, expr};;
    }
    else
        throw syntax_error("unexpected token in line " + d_lexer->lineNumber());
}