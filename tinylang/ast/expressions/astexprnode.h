#ifndef INCLUDED_ASTEXPRESSIONNODE_
#define INCLUDED_ASTEXPRESSIONNODE_

#include "../astnode.h"
#include "../../visitor/visitor.h"

class AstExprNode: public AstNode
{
    public:
        AstExprNode() = default;
        virtual ~AstExprNode() = 0;

        virtual void acceptVisitor(Visitor *vis) = 0;
        
};

#endif