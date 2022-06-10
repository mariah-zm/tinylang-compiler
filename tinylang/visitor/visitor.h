#ifndef INCLUDED_VISITOR_
#define INCLUDED_VISITOR_

#include "../ast/astprogramnode.h"
#include "../ast/statements/astassignmentnode.h"
#include "../ast/statements/astblocknode.h"
#include "../ast/statements/astforstmtnode.h"
#include "../ast/statements/astfunctionnode.h"
#include "../ast/statements/astfunctionprototypenode.h"
#include "../ast/statements/astifstmtnode.h"
#include "../ast/statements/astprintstmtnode.h"
#include "../ast/statements/astreturnstmtnode.h"
#include "../ast/statements/astvardeclnode.h"
#include "../ast/statements/astwhilestmtnode.h"
#include "../ast/expressions/astbinaryopnode.h"
#include "../ast/expressions/astfunctioncallnode.h"
#include "../ast/expressions/astidentifiernode.h"
#include "../ast/expressions/astunarynode.h"
#include "../ast/literals/astboolliteralnode.h"
#include "../ast/literals/astcharliteralnode.h"
#include "../ast/literals/astfloatliteralnode.h"
#include "../ast/literals/astintliteralnode.h"
#include "../ast/literals/astliteralnode.h"

// Pure abstract Visitor class
class Visitor
{
    public:
        virtual void visit(AstProgramNode *node) = 0;
        virtual void visit(AstAssignmentNode *node) = 0;
        virtual void visit(AstBlockNode *node) = 0;
        virtual void visit(AstForStmtNode *node) = 0;
        virtual void visit(AstFunctionNode *node) = 0;
        virtual void visit(AstFunctionPrototypeNode *node) = 0;
        virtual void visit(AstIfStmtNode *node) = 0;
        virtual void visit(AstPrintStmtNode *node) = 0;
        virtual void visit(AstReturnStmtNode *node) = 0;
        virtual void visit(AstVarDeclNode *node) = 0;
        virtual void visit(AstWhileStmtNode *node) = 0;
        virtual void visit(AstBinaryOpNode *node) = 0;
        virtual void visit(AstFunctionCallNode *node) = 0;
        virtual void visit(AstIdentifierNode *node) = 0;
        virtual void visit(AstUnaryNode *node) = 0;
        virtual void visit(AstBoolLiteralNode *node) = 0;
        virtual void visit(AstCharLiteralNode *node) = 0;
        virtual void visit(AstFloatLiteralNode *node) = 0;
        virtual void visit(AstIntLiteralNode *node) = 0;

};

#endif