#ifndef INCLUDED_ASTIDENTIFIERNODE_
#define INCLUDED_ASTIDENTIFIERNODE_

#include "../expressions/astexprnode.h"

class AstIdentifierNode: public AstExprNode
{
    std::string d_name;

    public:
        AstIdentifierNode(std::string name);
        virtual ~AstIdentifierNode() = default;

        std::string const &name() const;
};

inline AstIdentifierNode::AstIdentifierNode(std::string name)
:
    d_name(name)
{}

inline std::string const &AstIdentifierNode::name() const
{
    return d_name;
}

#endif