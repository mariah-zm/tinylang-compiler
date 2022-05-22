#ifndef INCLUDED_PARSER_
#define INCLUDED_PARSER_

#include "symboltable/symboltable.h"

#include "../token/token.h"
#include "../lexer/lexer.h"

#include "../ast/astnode.h"
#include "../ast/statements/aststatementnode.h"
#include "../ast/statements/astfunctionnode.h"
#include "../ast/statements/astfunctionprototypenode.h"
#include "../ast/statements/astblocknode.h"
#include "../ast/statements/astvardeclnode.h"
#include "../ast/statements/astifstmtnode.h"
#include "../ast/statements/astforstmtnode.h"
#include "../ast/statements/astwhilestmtnode.h"
#include "../ast/statements/astreturnstmtnode.h"
#include "../ast/statements/astprintstmtnode.h"
#include "../ast/statements/astassignmentnode.h"

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
        AstBlockNode *parseBlock();
        AstVarDeclNode *parseVarDecl();
        AstPrintStmtNode *parsePrint();
        AstReturnStmtNode *parseReturn();
        AstIfStmtNode *parseIf();
        AstForStmtNode *parseFor();
        AstWhileStmtNode *parseWhile();
        AstAssignmentNode *parseAssignment();
};

inline Parser::Parser(Lexer &lexer)
:
    d_lexer(lexer)
{}

#endif