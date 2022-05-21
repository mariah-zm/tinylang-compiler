#ifndef INCLUDED_ASTPRINTSTMTNODE_
#define INCLUDED_ASTPRINTSTMTNODE_

#include "aststatementnode.h"
#include "../expressions/astexprnode.h"

class AstPrintStmtNode: public AstStatementNode
{
    AstExprNode *d_expr;

    public:
        AstPrintStmtNode(AstExprNode *expr);
        virtual ~AstPrintStmtNode() = default;
};

inline AstPrintStmtNode::AstPrintStmtNode(AstExprNode *expr)
:
    d_expr(expr)
{}

#endif