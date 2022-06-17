#ifndef INCLUDED_ASTINTLITERALNODE_
#define INCLUDED_ASTINTLITERALNODE_

#include "astliteralnode.h"

// Forward-declaration due to cyclic dependency
class Visitor;

class AstIntLiteralNode: public AstLiteralNode
{
    int d_value;

    public:
        AstIntLiteralNode(int value);
        virtual ~AstIntLiteralNode();

        virtual void acceptVisitor(Visitor *vis);

        int value() const;
};

inline AstIntLiteralNode::~AstIntLiteralNode() = default;

inline AstIntLiteralNode::AstIntLiteralNode(int value)
:
    d_value(value)
{}

inline int AstIntLiteralNode::value() const
{
    return d_value;
}

#endif