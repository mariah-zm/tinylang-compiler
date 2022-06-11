#ifndef INCLUDED_SEMANTICVISITOR_
#define INCLUDED_SEMANTICVISITOR_

#include "../visitor.h"
#include "../symboltable/symboltable.h"

class SemanticVisitor: public Visitor
{
    SymbolTable d_symbolTable;

    public:
        SemanticVisitor();

        virtual void visit(AstProgramNode *node) override;
        virtual void visit(AstAssignmentNode *node) override;
        virtual void visit(AstBlockNode *node) override;
        virtual void visit(AstForStmtNode *node) override;
        virtual void visit(AstFunctionNode *node) override;
        virtual void visit(AstFunctionPrototypeNode *node) override;
        virtual void visit(AstIfStmtNode *node) override;
        virtual void visit(AstPrintStmtNode *node) override;
        virtual void visit(AstReturnStmtNode *node) override;
        virtual void visit(AstVarDeclNode *node) override;
        virtual void visit(AstWhileStmtNode *node) override;
        virtual void visit(AstBinaryOpNode *node) override;
        virtual void visit(AstFunctionCallNode *node) override;
        virtual void visit(AstIdentifierNode *node) override;
        virtual void visit(AstUnaryNode *node) override;
        virtual void visit(AstBoolLiteralNode *node) override;
        virtual void visit(AstCharLiteralNode *node) override;
        virtual void visit(AstFloatLiteralNode *node) override;
        virtual void visit(AstIntLiteralNode *node) override;

};

#endif