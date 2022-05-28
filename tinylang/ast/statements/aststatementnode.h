#ifndef INCLUDED_ASTSTATEMENTNODE_
#define INCLUDED_ASTSTATEMENTNODE_

#include "../astnode.h"

class AstStatementNode: public AstNode
{
    public:
        AstStatementNode() = default;
        virtual ~AstStatementNode() = default;

};

#endif