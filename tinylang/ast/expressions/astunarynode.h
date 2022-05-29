#ifndef INCLUDED_ASTUNARYNODE_
#define INCLUDED_ASTUNARYNODE_

#include "astexprnode.h"

#include <string>

class AstUnaryNode: public AstExprNode
{
    std::string d_value; 
    AstExprNode *d_expr;

    public:
        AstUnaryNode(std::string &value, AstExprNode *expr);
        virtual ~AstUnaryNode() = default;

        std::string const &value() const;
};

 inline AstUnaryNode::AstUnaryNode(std::string &value, AstExprNode *expr)
 :
    d_value(value),
    d_expr(expr)
{}

inline std::string const &AstUnaryNode::value() const
{
    return d_value;
}

#endif
