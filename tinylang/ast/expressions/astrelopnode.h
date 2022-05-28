#ifndef INCLUDED_ASTRELOPNODE_
#define INCLUDED_ASTRELOPNODE_

#include "../astnode.h"
#include "astexprnode.h"

#include <string>

class AstRelOpNode: public AstExprNode
{
    AstExprNode *d_left;
    std::string d_value; 
    AstExprNode *d_right;    

    public:
        AstRelOpNode(AstExprNode *left, std::string &value, AstExprNode *right);
        virtual ~AstRelOpNode() = default;

        std::string const &value() const;
};

inline AstRelOpNode::AstRelOpNode(AstExprNode *left, std::string &value, 
                                    AstExprNode *right)
:
    d_left(left),
    d_value(value),
    d_right(right)
{}

inline std::string const &AstRelOpNode::value() const
{
    return d_value;
}

#endif
