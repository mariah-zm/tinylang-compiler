#ifndef INCLUDED_ASTVARDECLNODE_
#define INCLUDED_ASTVARDECLNODE_

#include "aststatementnode.h"
#include "../expressions/astidentifiernode.h"
#include "../expressions/astexprnode.h"
#include "../../token/token.h"
#include "../../identifier/identifier.h"

// Forward-declaration due to cyclic dependency
class Visitor;

class AstVarDeclNode: public AstStatementNode
{
    AstIdentifierNode *d_left;
    Identifier::Type d_type;
    AstExprNode *d_right;

    public:
        AstVarDeclNode(AstIdentifierNode *left, Token::TokenType type, AstExprNode *right);
        virtual ~AstVarDeclNode();

        virtual void acceptVisitor(Visitor *vis);

        AstIdentifierNode *left() const;
        Identifier::Type type() const;
        AstExprNode *right() const;

};

inline AstVarDeclNode::~AstVarDeclNode() = default;

inline AstVarDeclNode::AstVarDeclNode
                (AstIdentifierNode *left, Token::TokenType type, AstExprNode *right)
:
    d_left(left),
    d_right(right)
{
    d_type = Identifier::getType(type);
}

inline AstIdentifierNode *AstVarDeclNode::left() const
{
    return d_left;
}

inline Identifier::Type AstVarDeclNode::type() const
{
    return d_type;
}

inline AstExprNode *AstVarDeclNode::right() const
{
    return d_right;
}

#endif