#ifndef INCLUDED_ASTWHILESTMTNODE_
#define INCLUDED_ASTWHILESTMTNODE_

#include "aststatementnode.h"
#include "../expressions/astexprnode.h"
#include "astblocknode.h"

// Forward-declaration due to cyclic dependency
class Visitor;

class AstWhileStmtNode: public AstStatementNode
{
    AstExprNode *d_condition;
    AstBlockNode *d_body;

    public:
        AstWhileStmtNode(AstExprNode *condition, AstBlockNode *body);
        virtual ~AstWhileStmtNode();

        virtual void acceptVisitor(Visitor *vis);

        AstExprNode *condition() const;
        AstBlockNode *body() const;
};

inline AstWhileStmtNode::~AstWhileStmtNode() = default;

inline AstWhileStmtNode::AstWhileStmtNode(AstExprNode *condition, AstBlockNode *body)
:
    d_condition(condition),
    d_body(body)
{}

inline AstExprNode *AstWhileStmtNode::condition() const
{
    return d_condition;
}

inline AstBlockNode *AstWhileStmtNode::body() const
{
    return d_body;
}

#endif