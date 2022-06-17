#include "parser.ih"

AstFunctionPrototypeNode *Parser::parseFunctionPrototype()
{
    d_currentTok = getNextToken();
    
    // Identifier name
    if (d_currentTok.type() != Token::IDENTIFIER)
        throw syntax_error("expected function identifier in line " 
                + to_string(d_lexer->lineNumber()));
    
    string fnName = d_currentTok.value();

    // Skipping (
    d_currentTok = getNextToken();

    if (d_currentTok.type() != Token::OPEN_BR)
        throw syntax_error("expected \'(\' in line " 
                + to_string(d_lexer->lineNumber()));

    // Reading parameters
    vector<AstFunctionPrototypeNode::Param> params;

    while (true)
    {
        string name;
        Token::TokenType type;

        // Param Name
        d_currentTok = getNextToken();

        if (d_currentTok.type() != Token::IDENTIFIER)
        {
            if (d_currentTok.type() != Token::CLOSE_BR)
                throw syntax_error("expected parameter name in line " 
                    + to_string(d_lexer->lineNumber()));
            else
                break;
        }    
            
        name = d_currentTok.value();

        // Consuming :
        d_currentTok = getNextToken();

        if (d_currentTok.type() != Token::COLON)
            throw syntax_error("expected \':\' in line " 
                    + to_string(d_lexer->lineNumber()));

        // Param type
        d_currentTok = getNextToken();

        if (!d_currentTok.isType())
            throw syntax_error("expected parameter type in line " 
                    + to_string(d_lexer->lineNumber()));

        type = d_currentTok.type();

        params.push_back(AstFunctionPrototypeNode::Param{name, Type{type}});

        // Consuming comma or )
        d_currentTok = getNextToken();

        if (d_currentTok.type() == Token::COMMA)
            continue;
        else if (d_currentTok.type() == Token::CLOSE_BR)
            break;
        else
            throw syntax_error("expected \')\' or \',\' in line " 
                    + to_string(d_lexer->lineNumber()));
    }   

    // Consuming -> 
    d_currentTok = getNextToken();

    if (d_currentTok.type() != Token::ARROW)
        throw syntax_error("expected \'->\' in line " 
                + to_string(d_lexer->lineNumber()));
    
    // Getting return type
    d_currentTok = getNextToken();

    if (!d_currentTok.isType())
        throw syntax_error("expected \'type\' in line " 
                + to_string(d_lexer->lineNumber()));

    Type retType = Type{d_currentTok.type()};

    return new AstFunctionPrototypeNode{fnName, params, retType};
}