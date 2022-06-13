#include "parser.ih"

AstLiteralNode *Parser::parseLiteral()
{
    Token::TokenType type = d_currentTok.type();
    if (type == Token::INT_LIT)
    {
        int intVal = stoi(d_currentTok.value());
        return new AstIntLiteralNode{intVal};
    }
    else if (type == Token::FLOAT_LIT)
    {        
        float floatVal = stof(d_currentTok.value());
        return new AstFloatLiteralNode{floatVal};
    }
    else if (type == Token::CHAR_LIT)
    {
        char charVal = d_currentTok.value().at(1);
        return new AstCharLiteralNode{charVal};
    }
    else if (type == Token::TRUE)
        return new AstBoolLiteralNode{true};
    else if (type == Token::FALSE)
        return new AstBoolLiteralNode{false};
    else 
        throw syntax_error("expected a literal type in line " 
                + to_string(d_lexer->lineNumber()));
}