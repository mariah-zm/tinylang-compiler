#ifndef INCLUDED_ASTBINARYOPNODE_
#define INCLUDED_ASTBINARYOPNODE_

#include "astexprnode.h"
#include "../../visitor/visitor.h"

#include <string>

class AstBinaryOpNode: public AstExprNode
{
    AstExprNode *d_left;
    std::string d_value; 
    AstExprNode *d_right;

    public:
        AstBinaryOpNode(AstExprNode *left, std::string &value, AstExprNode *right);
        virtual ~AstBinaryOpNode() = default;

        virtual void acceptVisitor(Visitor *vis);

        AstExprNode *left() const;
        std::string value() const;
        AstExprNode *right() const;
};

inline AstBinaryOpNode::AstBinaryOpNode(AstExprNode *left, std::string &value, 
                                    AstExprNode *right)
:
    d_left(left),
    d_value(value),
    d_right(right)
{}

inline AstExprNode *AstBinaryOpNode::left() const
{
    return d_left;
}


inline std::string AstBinaryOpNode::value() const
{
    return d_value;
}

inline AstExprNode *AstBinaryOpNode::right() const
{
    return d_right;
}


#endif
