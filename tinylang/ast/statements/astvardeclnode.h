#ifndef INCLUDED_ASTVARDECLNODE_
#define INCLUDED_ASTVARDECLNODE_

#include "aststatementnode.h"
#include "../expressions/astidentifiernode.h"
#include "../expressions/astexprnode.h"
#include "../../token/token.h"
#include "../../type/type.h"

// Forward-declaration due to cyclic dependency
class Visitor;

class AstVarDeclNode: public AstStatementNode
{
    AstIdentifierNode *d_left;
    Type d_type;
    AstExprNode *d_right;

    public:
        AstVarDeclNode(size_t lineNumber, AstIdentifierNode *left, 
                        Token::TokenType type, AstExprNode *right);
        virtual ~AstVarDeclNode();

        virtual void acceptVisitor(Visitor *vis);

        AstIdentifierNode *left() const;
        Type type() const;
        AstExprNode *right() const;

};

inline AstVarDeclNode::~AstVarDeclNode() = default;

inline AstVarDeclNode::AstVarDeclNode(size_t lineNumber, AstIdentifierNode *left, 
                                      Token::TokenType type, AstExprNode *right)
:
    AstStatementNode(lineNumber),
    d_left(left),
    d_type(type),
    d_right(right)
{}

inline AstIdentifierNode *AstVarDeclNode::left() const
{
    return d_left;
}

inline Type AstVarDeclNode::type() const
{
    return d_type;
}

inline AstExprNode *AstVarDeclNode::right() const
{
    return d_right;
}

#endif