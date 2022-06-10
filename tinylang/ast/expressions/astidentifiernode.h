#ifndef INCLUDED_ASTIDENTIFIERNODE_
#define INCLUDED_ASTIDENTIFIERNODE_

#include <string>

#include "astexprnode.h"

// Forward-declaration due to cyclic dependency
class Visitor;

class AstIdentifierNode: public AstExprNode
{
    std::string d_name;

    public:
        AstIdentifierNode(std::string name);
        virtual ~AstIdentifierNode();

        virtual void acceptVisitor(Visitor *vis);

        std::string name() const;
};

inline AstIdentifierNode::~AstIdentifierNode() = default;

inline AstIdentifierNode::AstIdentifierNode(std::string name)
:
    d_name(name)
{}

inline std::string AstIdentifierNode::name() const
{
    return d_name;
}

#endif