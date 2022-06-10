#ifndef INCLUDED_ASTBOOLLITERALNODE_
#define INCLUDED_ASTBOOLLITERALNODE_

#include "astliteralnode.h"
#include "../../visitor/visitor.h"

class AstBoolLiteralNode: public AstLiteralNode
{
    bool d_value;

    public:
        AstBoolLiteralNode(bool value);
        virtual ~AstBoolLiteralNode() = default;

        virtual void acceptVisitor(Visitor *vis);

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