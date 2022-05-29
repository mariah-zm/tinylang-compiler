#ifndef INCLUDED_ASTASSIGNMENTNODE_
#define INCLUDED_ASTASSIGNMENTNODE_

#include <string>

#include "aststatementnode.h"
#include "../expressions/astidentifiernode.h"
#include "../expressions/astexprnode.h"

class AstAssignmentNode: public AstStatementNode
{
    std::string d_idenName;
    AstExprNode *d_right;

    public:
        AstAssignmentNode(std::string &name, AstExprNode *right);
        virtual ~AstAssignmentNode() = default;

};

inline AstAssignmentNode::AstAssignmentNode(std::string &name, AstExprNode *right)
:
    d_idenName(name),
    d_right(right)
{}


#endif