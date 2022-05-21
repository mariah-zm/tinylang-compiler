#ifndef INCLUDED_ASTCHARLITERALNODE_
#define INCLUDED_ASTCHARLITERALNODE_

#include "astfactornode.h"

class AstCharLiteralNode: public AstFactorNode
{
    char d_value;

    public:
        AstCharLiteralNode(char value);
        virtual ~AstCharLiteralNode() = default;

        char value() const;
};

inline AstCharLiteralNode::AstCharLiteralNode(char value)
:
    d_value(value)
{}

inline char AstCharLiteralNode::value() const
{
    return d_value;
}

#endif