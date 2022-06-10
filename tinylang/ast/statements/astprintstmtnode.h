#ifndef INCLUDED_ASTPRINTSTMTNODE_
#define INCLUDED_ASTPRINTSTMTNODE_

#include "aststatementnode.h"
#include "../expressions/astexprnode.h"

// Forward-declaration due to cyclic dependency
class Visitor;

class AstPrintStmtNode: public AstStatementNode
{
    AstExprNode *d_expr;

    public:
        AstPrintStmtNode(AstExprNode *expr);
        virtual ~AstPrintStmtNode();

        virtual void acceptVisitor(Visitor *vis);

        AstExprNode *expr();    // Getter
};

inline AstPrintStmtNode::~AstPrintStmtNode() = default;

inline AstPrintStmtNode::AstPrintStmtNode(AstExprNode *expr)
:
    d_expr(expr)
{}

inline AstExprNode *AstPrintStmtNode::expr()
{
    return d_expr;
}

#endif