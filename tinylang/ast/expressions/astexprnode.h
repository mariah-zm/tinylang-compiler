#ifndef INCLUDED_ASTEXPRESSIONNODE_
#define INCLUDED_ASTEXPRESSIONNODE_

#include "../astnode.h"

class AstExprNode: public AstNode
{
    public:
        AstExprNode() = default;
        virtual ~AstExprNode() = 0;
};

inline AstExprNode::~AstExprNode()
{}

#endif