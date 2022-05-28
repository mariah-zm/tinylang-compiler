#ifndef INCLUDED_ASTMULOPNODE_
#define INCLUDED_ASTMULOPNODE_

#include "../astnode.h"
#include "astexprnode.h"

#include <string>

class AstMulOpNode: public AstExprNode
{
    AstExprNode *d_left;
    std::string d_value; 
    AstExprNode *d_right;

    public:
        AstMulOpNode(AstExprNode *left, std::string &value, AstExprNode *right);
        virtual ~AstMulOpNode() = default;

        std::string const &value() const;
};

inline AstMulOpNode::AstMulOpNode(AstExprNode *left, std::string &value, 
                                    AstExprNode *right)
:
    d_left(left),
    d_value(value),
    d_right(right)
{}

inline std::string const &AstMulOpNode::value() const
{
    return d_value;
}

#endif
