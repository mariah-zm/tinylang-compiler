#ifndef INCLUDED_INTERPRETERVISITOR_
#define INCLUDED_INTERPRETERVISITOR_

#include "../visitor.h"
#include "../../symboltable/symboltable.h"
#include "../../type/type.h"
#include "../../literal/literal.h"

class InterpreterVisitor: public Visitor
{
    SymbolTable *d_symbolTable;
    
    Literal d_currentLit;

    public:
        InterpreterVisitor(SymbolTable *symbolTable);

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

inline InterpreterVisitor::InterpreterVisitor(SymbolTable *symbolTable)
:
    d_symbolTable(symbolTable)
{}

#endif