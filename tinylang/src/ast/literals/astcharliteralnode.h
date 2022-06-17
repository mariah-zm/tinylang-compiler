#ifndef INCLUDED_ASTCHARLITERALNODE_
#define INCLUDED_ASTCHARLITERALNODE_

#include "astliteralnode.h"

// Forward-declaration due to cyclic dependency
class Visitor;

class AstCharLiteralNode: public AstLiteralNode
{
    char d_value;

    public:
        AstCharLiteralNode(char value);
        virtual ~AstCharLiteralNode();

        virtual void acceptVisitor(Visitor *vis);

        char value() const;
};

inline AstCharLiteralNode::~AstCharLiteralNode() = default;

inline AstCharLiteralNode::AstCharLiteralNode(char value)
:
    d_value(value)
{}

inline char AstCharLiteralNode::value() const
{
    return d_value;
}

#endif