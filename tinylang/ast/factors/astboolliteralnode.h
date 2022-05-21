#ifndef INCLUDED_ASTBOOLLITERALNODE_
#define INCLUDED_ASTBOOLLITERALNODE_

#include "astfactornode.h"

class AstBoolLiteralNode: public AstFactorNode
{
    bool d_value;

    public:
        AstBoolLiteralNode(bool value);
        virtual ~AstBoolLiteralNode() = default;

        bool value() const;
};

inline AstBoolLiteralNode::AstBoolLiteralNode(bool value)
:
    d_value(value)
{}

inline bool AstBoolLiteralNode::value() const
{
    return d_value;
}

#endif