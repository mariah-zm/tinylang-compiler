#ifndef INCLUDED_ASTVARDECLNODE_
#define INCLUDED_ASTVARDECLNODE_

#include "aststatementnode.h"
#include "../factors/astidentifiernode.h"
#include "../expressions/astexprnode.h"
#include "../token/token.h"

class AstVarDeclNode: public AstStatementNode
{
    enum Type
    {
        INT,
        FLOAT,
        CHAR,
        BOOL
    };

    AstIdentifierNode *d_left;
    Type d_type;
    AstExprNode *d_right;

    public:
        AstVarDeclNode(AstIdentifierNode *left, Token::TokenType type, AstExprNode *right);
        virtual ~AstVarDeclNode() = default;

};

inline AstVarDeclNode::AstVarDeclNode
                (AstIdentifierNode *left, Token::TokenType type, AstExprNode *right)
:
    d_left(left),
    d_right(right)
{
    switch (type)
    {
        case Token::INT:
            d_type = INT;
            break;

        case Token::FLOAT:
            d_type = FLOAT;
            break;
        
        case Token::CHAR:
            d_type = CHAR;
            break;

        default:
            d_type = BOOL;
            break;
    }
}


#endif