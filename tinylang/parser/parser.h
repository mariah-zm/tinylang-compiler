#ifndef INCLUDED_PARSER_
#define INCLUDED_PARSER_

#include "../token/token.h"
#include "../lexer/lexer.h"

#include "../ast/astprogramnode.h"
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
#include "../ast/expressions/astfunctioncallnode.h"
#include "../ast/literals/astliteralnode.h"

class Parser
{
    Token d_currentTok;
    Lexer *d_lexer;
    bool d_isCurrentParsed = true;     // bool variable to allow lookahead
    
    public:
        Parser(Lexer *lexer);
        AstProgramNode *parse();

    private:
        Token getNextToken();
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
        AstExprNode *parseExpr();
        AstExprNode *parseSimpleExpr();
        AstExprNode *parseTerm();
        AstExprNode *parseFactor();
        AstLiteralNode *parseLiteral();
        AstFunctionCallNode *parseFunctionCall(std::string fnName);

        void parseSemiColon();
};

inline Parser::Parser(Lexer *lexer)
:
    d_lexer(lexer)
{}

#endif