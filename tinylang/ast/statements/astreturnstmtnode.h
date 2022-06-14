#ifndef INCLUDED_ASTRETURNSTMTNODE_
#define INCLUDED_ASTRETURNSTMTNODE_

#include "aststatementnode.h"
#include "../expressions/astexprnode.h"

// Forward-declaration due to cyclic dependency
class Visitor;

class AstReturnStmtNode: public AstStatementNode
{
    AstExprNode *d_expr;

    public:
        AstReturnStmtNode(size_t lineNumber, AstExprNode *expr);
        virtual ~AstReturnStmtNode();

        virtual void acceptVisitor(Visitor *vis);

        AstExprNode *expr();    // Getter
};

inline AstReturnStmtNode::~AstReturnStmtNode()
{
    delete d_expr;
}

inline AstReturnStmtNode::AstReturnStmtNode(size_t lineNumber, AstExprNode *expr)
:
    AstStatementNode(lineNumber),
    d_expr(expr)
{}

inline AstExprNode *AstReturnStmtNode::expr()
{
    return d_expr;
}

#endif