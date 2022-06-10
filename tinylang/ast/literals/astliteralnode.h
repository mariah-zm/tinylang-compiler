#ifndef INCLUDED_ASTLITERALNODE_
#define INCLUDED_ASTLITERALNODE_

#include "../expressions/astexprnode.h"
#include "../../visitor/visitor.h"

class AstLiteralNode: public AstExprNode
{
    public:
        AstLiteralNode() = default;
        virtual ~AstLiteralNode() = 0;

        virtual void acceptVisitor(Visitor *vis) = 0;

};

#endif