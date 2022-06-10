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
        AstReturnStmtNode(AstExprNode *expr);
        virtual ~AstReturnStmtNode();

        virtual void acceptVisitor(Visitor *vis);

        AstExprNode *expr();    // Getter
};

inline AstReturnStmtNode::~AstReturnStmtNode() = default;

inline AstReturnStmtNode::AstReturnStmtNode(AstExprNode *expr)
:
    d_expr(expr)
{}

inline AstExprNode *AstReturnStmtNode::expr()
{
    return d_expr;
}

#endif