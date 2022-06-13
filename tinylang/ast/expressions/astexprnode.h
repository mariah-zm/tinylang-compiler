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
        AstExprNode(size_t lineNum);
        virtual ~AstExprNode() = default;

        virtual void acceptVisitor(Visitor *vis) = 0;

};

inline AstExprNode::AstExprNode(size_t lineNum)
:
    AstNode(lineNum)
{}

#endif