#ifndef INCLUDED_ASTLITERALNODE_
#define INCLUDED_ASTLITERALNODE_

#include "../expressions/astexprnode.h"

class AstLiteralNode: public AstExprNode
{
    public:
        AstLiteralNode() = default;
        virtual ~AstLiteralNode() = 0;

};

inline AstLiteralNode::~AstLiteralNode()
{}

#endif