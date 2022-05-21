#ifndef INCLUDED_ASTASSIGNMENTNODE_
#define INCLUDED_ASTASSIGNMENTNODE_

#include "aststatementnode.h"
#include "../factors/astidentifiernode.h"
#include "../expressions/astexprnode.h"

class AstAssignmentNode: public AstStatementNode
{
    AstIdentifierNode *d_left;
    AstExprNode *d_right;

    public:
        AstAssignmentNode(AstIdentifierNode *left, AstExprNode *right);
        virtual ~AstAssignmentNode() = default;

};

inline AstAssignmentNode::AstAssignmentNode
                (AstIdentifierNode *left, AstExprNode *right)
:
    d_left(left),
    d_right(right)
{}


#endif