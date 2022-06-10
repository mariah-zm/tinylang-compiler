#ifndef INCLUDED_XMLVISITOR_
#define INCLUDED_XMLVISITOR_

#include "../visitor.h"

#include <fstream>
#include <string>

// Pure abstract Visitor class
class XmlVisitor: public Visitor
{
    int d_indent = 0;
    std::ofstream d_file;

    public:
        XmlVisitor(std::string fileName);

        virtual void visit(AstProgramNode *node);
        virtual void visit(AstAssignmentNode *node);
        virtual void visit(AstBlockNode *node);
        virtual void visit(AstForStmtNode *node);
        virtual void visit(AstFunctionNode *node);
        virtual void visit(AstFunctionPrototypeNode *node);
        virtual void visit(AstIfStmtNode *node);
        virtual void visit(AstPrintStmtNode *node);
        virtual void visit(AstReturnStmtNode *node);
        virtual void visit(AstVarDeclNode *node);
        virtual void visit(AstWhileStmtNode *node);
        virtual void visit(AstBinaryOpNode *node);
        virtual void visit(AstFunctionCallNode *node);
        virtual void visit(AstIdentifierNode *node);
        virtual void visit(AstUnaryNode *node);
        virtual void visit(AstBoolLiteralNode *node);
        virtual void visit(AstCharLiteralNode *node);
        virtual void visit(AstFloatLiteralNode *node);
        virtual void visit(AstIntLiteralNode *node);

};

#endif