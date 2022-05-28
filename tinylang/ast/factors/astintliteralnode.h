#ifndef INCLUDED_ASTINTLITERALNODE_
#define INCLUDED_ASTINTLITERALNODE_

#include "../expressions/astexprnode.h"

class AstIntLiteralNode: public AstExprNode
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