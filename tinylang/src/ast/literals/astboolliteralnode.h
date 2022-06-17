#ifndef INCLUDED_ASTBOOLLITERALNODE_
#define INCLUDED_ASTBOOLLITERALNODE_

#include "astliteralnode.h"

// Forward-declaration due to cyclic dependency
class Visitor;

class AstBoolLiteralNode: public AstLiteralNode
{
    bool d_value;

    public:
        AstBoolLiteralNode(bool value);
        virtual ~AstBoolLiteralNode();

        virtual void acceptVisitor(Visitor *vis);

        bool value() const;
};

inline AstBoolLiteralNode::~AstBoolLiteralNode() = default;

inline AstBoolLiteralNode::AstBoolLiteralNode(bool value)
:
    d_value(value)
{}

inline bool AstBoolLiteralNode::value() const
{
    return d_value;
}

#endif