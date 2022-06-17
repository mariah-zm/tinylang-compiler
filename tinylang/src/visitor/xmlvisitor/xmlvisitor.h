#ifndef INCLUDED_XMLVISITOR_
#define INCLUDED_XMLVISITOR_

#include "../visitor.h"

#include <fstream>
#include <string>

class XmlVisitor: public Visitor
{
    size_t d_indent = 0;
    std::string d_fileName;
    std::ofstream d_file;

    public:
        XmlVisitor(std::string fileName);

        std::string fileName() const; // Getter

        void close();

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

inline std::string XmlVisitor::fileName() const
{
    return d_fileName;
}

inline void XmlVisitor::close()
{
    d_file.close();
}

#endif