#ifndef INCLUDED_ASTVARDECLNODE_
#define INCLUDED_ASTVARDECLNODE_

#include "aststatementnode.h"
#include "../factors/astidentifiernode.h"
#include "../expressions/astexprnode.h"

class AstVarDeclNode: public AstStatementNode
{
    AstIdentifierNode *d_left;
    AstExprNode *d_right;

    public:
        AstVarDeclNode(AstIdentifierNode *left, AstExprNode *right);
        virtual ~AstVarDeclNode() = default;

};

inline AstVarDeclNode::AstVarDeclNode
                (AstIdentifierNode *left, AstExprNode *right)
:
    d_left(left),
    d_right(right)
{}


#endif