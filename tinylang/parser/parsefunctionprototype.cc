#include "parser.ih"

AstFunctionPrototypeNode *Parser::parseFunctionPrototype()
{
    d_currentTok = getNextToken();
    
    // Identifier name
    if (d_currentTok.type() != Token::IDENTIFIER)
        throw syntax_error("expected function identifier");
    
    string fnName = d_currentTok.value();

    // Skipping (
    d_currentTok = getNextToken();

    if (d_currentTok.type() != Token::OPEN_BR)
        throw syntax_error("expected \'(\'");
    
    // Reading parameters
    vector<AstFunctionPrototypeNode::Param> params;

    while (true)
    {
        string name;
        Token::TokenType type;

        // Param Name
        d_currentTok = getNextToken();

        if (d_currentTok.type() != Token::IDENTIFIER)
            throw syntax_error("expected parameter name");
            
        name = d_currentTok.value();

        // Consuming:
        d_currentTok = getNextToken();

        if (d_currentTok.type() != Token::COLON)
            throw syntax_error("expected \':\'");

        // Param type
        d_currentTok = getNextToken();

        if (!d_currentTok.isType())
            throw syntax_error("expected parameter type");

        type = d_currentTok.type();

        params.push_back(AstFunctionPrototypeNode::Param{name, Type{type}});

        // Consuming comma or )
        d_currentTok = getNextToken();

        if (d_currentTok.type() == Token::COMMA)
            continue;
         else if (d_currentTok.type() == Token::CLOSE_BR)
            break;
        else
            throw syntax_error("expected \',\' OR \')\'");
    }   

    // Consuming -> 
    d_currentTok = getNextToken();

    if (d_currentTok.type() != Token::ARROW)
        throw syntax_error("expected \'->\'");
    
    // Gettin return type
    d_currentTok = getNextToken();

    if (!d_currentTok.isType())
        throw syntax_error("expected \'type\'");

    Type retType = Type{d_currentTok.type()};

    return new AstFunctionPrototypeNode{fnName, params, retType};
}