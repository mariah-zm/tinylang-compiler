#ifndef INCLUDED_ASTNODE_
#define INCLUDED_ASTNODE_

#include "../visitor/visitor.h"

class AstNode
{
    public:
        AstNode() = default;
        virtual ~AstNode() = default;

        virtual void acceptVisitor(Visitor *vis) = 0;

};

#endif