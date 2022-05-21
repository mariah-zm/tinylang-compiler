#ifndef INCLUDED_ASTMULOPNODE_
#define INCLUDED_ASTMULOPNODE_

#include "../astnode.h"
#include "astexprnode.h"

#include <string>

class AstMulOpNode: public AstExprNode
{
    AstExprNode *d_left;
    AstExprNode *d_right;
    std::string d_value; 

    public:
        AstMulOpNode(AstExprNode *left, std::string &value, AstExprNode *right);
        virtual ~AstMulOpNode() = default;

        std::string const &value() const;
};

inline std::string const &AstMulOpNode::value() const
{
    return d_value;
}

#endif
