#ifndef INCLUDED_ASTLITERALNODE_
#define INCLUDED_ASTLITERALNODE_

#include "../astnode.h"
#include "../expressions/astexprnode.h"

class AstLiteralNode: public AstExprNode
{
    public:
        AstLiteralNode() = default;
        virtual ~AstLiteralNode() = default;

};

#endif