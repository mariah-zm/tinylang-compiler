#ifndef INCLUDED_ASTVARDECLNODE_
#define INCLUDED_ASTVARDECLNODE_

#include "aststatementnode.h"
#include "../factors/astidentifiernode.h"
#include "../expressions/astexprnode.h"
#include "../../token/token.h"

class AstVarDeclNode: public AstStatementNode
{
    AstIdentifierNode *d_left;
    Identifier::Type d_type;
    AstExprNode *d_right;

    public:
        AstVarDeclNode(AstIdentifierNode *left, Token::TokenType type, AstExprNode *right);
        virtual ~AstVarDeclNode() = default;

};

inline AstVarDeclNode::AstVarDeclNode
                (AstIdentifierNode *left, Token::TokenType type, AstExprNode *right)
:
    d_left(left),
    d_type(Identifier::getType(type)),
    d_right(right)
{}


#endif