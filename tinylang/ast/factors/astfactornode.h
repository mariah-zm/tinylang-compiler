#ifndef INCLUDED_ASTVALUENODE_
#define INCLUDED_ASTVALUENODE_

#include "../astnode.h"
#include "../expressions/astexprnode.h"

class AstFactorNode: public AstExprNode
{
    public:
        AstFactorNode();
        virtual ~AstFactorNode() = default;

};

#endif