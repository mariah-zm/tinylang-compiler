#ifndef INCLUDED_ASTBINARYOPNODE_
#define INCLUDED_ASTBINARYOPNODE_

#include "astexprnode.h"

#include <string>

class AstBinaryOpNode: public AstExprNode
{
    AstExprNode *d_left;
    std::string d_value; 
    AstExprNode *d_right;

    public:
        AstBinaryOpNode(AstExprNode *left, std::string &value, AstExprNode *right);
        virtual ~AstBinaryOpNode() = default;

        std::string const &value() const;
};

inline AstBinaryOpNode::AstBinaryOpNode(AstExprNode *left, std::string &value, 
                                    AstExprNode *right)
:
    d_left(left),
    d_value(value),
    d_right(right)
{}

inline std::string const &AstBinaryOpNode::value() const
{
    return d_value;
}

#endif
