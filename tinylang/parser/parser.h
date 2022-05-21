#ifndef INCLUDED_PARSER_
#define INCLUDED_PARSER_

#include "symboltable/symboltable.h"

#include "../token/token.h"
#include "../lexer/lexer.h"

#include "../ast/astnode.h"
#include "../ast/aststatementnode.h"
#include "../ast/astfunctionnode.h"
#include "../ast/astfunctionprototypenode.h"
#include "../ast/astblocknode.h"

class Parser
{
    Token d_currentTok;
    Lexer d_lexer;
    SymbolTable d_symbolTable = SymbolTable{};

    public:
        Parser(Lexer &lexer);
        AstNode *parse();

    private:
        AstStatementNode *parseStatement();
        AstFunctionNode *parseFunctionDef();
        AstFunctionPrototypeNode *parseFunctionPrototype();
        AstBlockNode *parseFunctionBody();
};

inline Parser::Parser(Lexer &lexer)
:
    d_lexer(lexer)
{}

#endif