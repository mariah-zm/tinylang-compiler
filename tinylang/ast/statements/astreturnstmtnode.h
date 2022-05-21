#ifndef INCLUDED_ASTRETURNSTMTNODE_
#define INCLUDED_ASTRETURNSTMTNODE_

#include "aststatementnode.h"
#include "../expressions/astexprnode.h"

class AstReturnStmtNode: public AstStatementNode
{
    AstExprNode *d_expr;

    public:
        AstReturnStmtNode(AstExprNode *expr);
        virtual ~AstReturnStmtNode() = default;
};

inline AstReturnStmtNode::AstReturnStmtNode(AstExprNode *expr)
:
    d_expr(expr)
{}

#endif