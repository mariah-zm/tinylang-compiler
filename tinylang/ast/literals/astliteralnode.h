#ifndef INCLUDED_ASTLITERALNODE_
#define INCLUDED_ASTLITERALNODE_

#include "../expressions/astexprnode.h"

// Forward-declaration due to cyclic dependency
class Visitor;

class AstLiteralNode: public AstExprNode
{
    public:
        AstLiteralNode() = default;
        virtual ~AstLiteralNode() = default;

        virtual void acceptVisitor(Visitor *vis) = 0;

};

#endif