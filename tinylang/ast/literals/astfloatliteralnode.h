#ifndef INCLUDED_ASTFLOATLITERALNODE_
#define INCLUDED_ASTFLOATLITERALNODE_

#include "astliteralnode.h"

// Forward-declaration due to cyclic dependency
class Visitor;

class AstFloatLiteralNode: public AstLiteralNode
{
    float d_value;

    public:
        AstFloatLiteralNode(float value);
        virtual ~AstFloatLiteralNode();

        virtual void acceptVisitor(Visitor *vis);

        float value() const;
};

inline AstFloatLiteralNode::~AstFloatLiteralNode() = default;

inline AstFloatLiteralNode::AstFloatLiteralNode(float value)
:
    d_value(value)
{}

inline float AstFloatLiteralNode::value() const
{
    return d_value;
}

#endif