#ifndef INCLUDED_ASTUNARYNODE_
#define INCLUDED_ASTUNARYNODE_

#include "astexprnode.h"
#include "../../visitor/visitor.h"

#include <string>

class AstUnaryNode: public AstExprNode
{
    std::string d_value; 
    AstExprNode *d_expr;

    public:
        AstUnaryNode(std::string &value, AstExprNode *expr);
        virtual ~AstUnaryNode() = default;

        virtual void acceptVisitor(Visitor *vis);
        
        std::string value() const;
        AstExprNode *expr() const;
};

 inline AstUnaryNode::AstUnaryNode(std::string &value, AstExprNode *expr)
 :
    d_value(value),
    d_expr(expr)
{}

inline std::string AstUnaryNode::value() const
{
    return d_value;
}

inline AstExprNode *AstUnaryNode::expr() const
{
    return d_expr;
}

#endif
