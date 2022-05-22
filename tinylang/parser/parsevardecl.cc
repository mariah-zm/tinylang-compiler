#include "parser.ih"

AstVarDeclNode *Parser::parseVarDecl()
{
    // Getting identifer name
    d_currentTok = d_lexer.getNextToken();
    
    if (d_currentTok.type() != Token::IDENTIFIER)
        throw syntax_error("expected identifier name");

    string name = d_currentTok.value();

    // Consuming :
    d_currentTok = d_lexer.getNextToken();
    
    if (d_currentTok.type() != Token::COLON)
        throw syntax_error("expected \':\'");

    // Getting identifer type
    d_currentTok = d_lexer.getNextToken();
    
    if (!d_currentTok.isType())
        throw syntax_error("expected type");

    Token::TokenType type = d_currentTok.type();

    Identifier identifier = Identifier{name, type};
    AstIdentifierNode *idenNode = new AstIdentifierNode{identifier};

    // Consuming =
    d_currentTok = d_lexer.getNextToken();
    
    if (d_currentTok.type() != Token::ASSIGNMENT)
        throw syntax_error("expected \'=\'");

    AstExprNode *expr = parseExpr();

    return new AstVarDeclNode{idenNode, expr};
}