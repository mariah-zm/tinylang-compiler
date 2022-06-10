#ifndef INCLUDED_ASTEXPRNODE_
#define INCLUDED_ASTEXPRNODE_

#include "../astnode.h"

// Forward-declaration due to cyclic dependency
class Visitor;
class AstNode;

class AstExprNode: public AstNode
{
    public:
        AstExprNode() = default;
        virtual ~AstExprNode() = default;

        virtual void acceptVisitor(Visitor *vis) = 0;

};

#endif