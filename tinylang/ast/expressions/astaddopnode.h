#ifndef INCLUDED_ASTADDOPNODE_
#define INCLUDED_ASTADDOPNODE_

#include "../astnode.h"
#include "astexprnode.h"

#include <string>

class AstAddOpNode: public AstExprNode
{
    AstExprNode *d_left;
    std::string d_value; 
    AstExprNode *d_right;

    public:
        AstAddOpNode(AstExprNode *left, std::string &value, AstExprNode *right);
        virtual ~AstAddOpNode() = default;

        std::string const &value() const;
};

inline AstAddOpNode::AstAddOpNode(AstExprNode *left, std::string &value, 
                                    AstExprNode *right)
:
    d_left(left),
    d_value(value),
    d_right(right)
{}

inline std::string const &AstAddOpNode::value() const
{
    return d_value;
}

#endif
