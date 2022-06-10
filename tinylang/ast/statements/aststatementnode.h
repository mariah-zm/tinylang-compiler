#ifndef INCLUDED_ASTSTATEMENTNODE_
#define INCLUDED_ASTSTATEMENTNODE_

#include "../astnode.h"

// Forward-declaration due to cyclic dependency
class Visitor;

class AstStatementNode: public AstNode
{
    public:
        AstStatementNode() = default;
        virtual ~AstStatementNode() = default;

        virtual void acceptVisitor(Visitor *vis) = 0;

};

#endif