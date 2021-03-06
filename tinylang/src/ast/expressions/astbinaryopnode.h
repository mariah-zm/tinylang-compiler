#ifndef INCLUDED_ASTBINARYOPNODE_
#define INCLUDED_ASTBINARYOPNODE_

#include <string>

#include "astexprnode.h"

// Forward-declaration due to cyclic dependency
class Visitor;

class AstBinaryOpNode: public AstExprNode
{
    AstExprNode *d_left;
    std::string d_value; 
    AstExprNode *d_right;

    public:
        AstBinaryOpNode(size_t lineNumber, AstExprNode *left, 
                        std::string &value, AstExprNode *right);
        virtual ~AstBinaryOpNode();

        virtual void acceptVisitor(Visitor *vis);

        AstExprNode *left() const;
        std::string value() const;
        AstExprNode *right() const;
};

inline AstBinaryOpNode::~AstBinaryOpNode()
{
    delete d_left;
    delete d_right;
}

inline AstBinaryOpNode::AstBinaryOpNode(size_t lineNumber, AstExprNode *left,  
                                    std::string &value, AstExprNode *right)
:
    AstExprNode(lineNumber),
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
