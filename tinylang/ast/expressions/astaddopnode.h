#ifndef INCLUDED_ASTADDOPNODE_
#define INCLUDED_ASTADDOPNODE_

#include "../astnode.h"
#include "astexprnode.h"

#include <string>

class AstAddOpNode: public AstExprNode
{
    AstExprNode *d_left;
    AstExprNode *d_right;
    std::string d_value; 

    public:
        AstAddOpNode(AstExprNode *left, std::string &value, AstExprNode *right);
        virtual ~AstAddOpNode() = default;

        std::string const &value() const;
};

inline std::string const &AstAddOpNode::value() const
{
    return d_value;
}

#endif
