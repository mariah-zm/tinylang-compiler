#ifndef INCLUDED_ASTNODE_
#define INCLUDED_ASTNODE_

// Forward-declaration due to cyclic dependency
class Visitor;

class AstNode
{
    public:
        AstNode() = default;
        virtual ~AstNode() = default;

        virtual void acceptVisitor(Visitor *vis) = 0;

};

#endif