#ifndef INCLUDED_ASTIDENTIFIERNODE_
#define INCLUDED_ASTIDENTIFIERNODE_

#include <string>

#include "astexprnode.h"
#include "../../visitor/visitor.h"

class AstIdentifierNode: public AstExprNode
{
    std::string d_name;

    public:
        AstIdentifierNode(std::string name);
        virtual ~AstIdentifierNode() = default;

        virtual void acceptVisitor(Visitor *vis);

        std::string name() const;
};

inline AstIdentifierNode::AstIdentifierNode(std::string name)
:
    d_name(name)
{}

inline std::string AstIdentifierNode::name() const
{
    return d_name;
}

#endif