#ifndef INCLUDED_ASTWHILESTMTNODE_
#define INCLUDED_ASTWHILESTMTNODE_

#include "aststatementnode.h"
#include "../expressions/astexprnode.h"
#include "astblocknode.h"

class AstWhileStmtNode: public AstStatementNode
{
    AstExprNode *d_condition;
    AstBlockNode *d_body;

    public:
        AstWhileStmtNode() = delete;
        AstWhileStmtNode(AstExprNode *condition, AstBlockNode *body);
        virtual ~AstWhileStmtNode() = default;
};

inline AstWhileStmtNode::AstWhileStmtNode(AstExprNode *condition, AstBlockNode *body)
:
    d_condition(condition),
    d_body(body)
{}

#endif