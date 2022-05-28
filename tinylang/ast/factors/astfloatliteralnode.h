#ifndef INCLUDED_ASTFLOATLITERALNODE_
#define INCLUDED_ASTFLOATLITERALNODE_

#include "astliteralnode.h"

class AstFloatLiteralNode: public AstLiteralNode
{
    float d_value;

    public:
        AstFloatLiteralNode(float value);
        virtual ~AstFloatLiteralNode() = default;

        float value() const;
};

inline AstFloatLiteralNode::AstFloatLiteralNode(float value)
:
    d_value(value)
{}

inline float AstFloatLiteralNode::value() const
{
    return d_value;
}

#endif