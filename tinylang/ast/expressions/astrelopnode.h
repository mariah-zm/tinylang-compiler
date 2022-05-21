#ifndef INCLUDED_ASTRELOPNODE_
#define INCLUDED_ASTRELOPNODE_

#include "../astnode.h"
#include "astexprnode.h"

#include <string>

class AstRelOpNode: public AstExprNode
{
    AstExprNode *d_left;
    AstExprNode *d_right;
    std::string d_value; 

    public:
        AstRelOpNode(AstExprNode *left, std::string &value, AstExprNode *right);
        virtual ~AstRelOpNode() = default;

        std::string const &value() const;
};

inline std::string const &AstRelOpNode::value() const
{
    return d_value;
}

#endif
