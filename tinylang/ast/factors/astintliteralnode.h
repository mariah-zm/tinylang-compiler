#ifndef INCLUDED_ASTINTLITERALNODE_
#define INCLUDED_ASTINTLITERALNODE_

#include "astfactornode.h"

class AstIntLiteralNode: public AstFactorNode
{
    int d_value;

    public:
        AstIntLiteralNode(int value);
        virtual ~AstIntLiteralNode() = default;

        int value() const;
};

inline AstIntLiteralNode::AstIntLiteralNode(int value)
:
    d_value(value)
{}

inline int AstIntLiteralNode::value() const
{
    return d_value;
}

#endif