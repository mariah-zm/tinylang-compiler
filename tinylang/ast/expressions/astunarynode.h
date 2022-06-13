#ifndef INCLUDED_ASTUNARYNODE_
#define INCLUDED_ASTUNARYNODE_

#include <string>

#include "astexprnode.h"

// Forward-declaration due to cyclic dependency
class Visitor;

class AstUnaryNode: public AstExprNode
{
    std::string d_value; 
    AstExprNode *d_expr;

    public:
        AstUnaryNode(size_t lineNumber, std::string &value, AstExprNode *expr);
        virtual ~AstUnaryNode();

        virtual void acceptVisitor(Visitor *vis);
        
        std::string value() const;
        AstExprNode *expr() const;
};

inline AstUnaryNode::~AstUnaryNode() = default;

 inline AstUnaryNode::AstUnaryNode(size_t lineNumber, std::string &value, 
                                    AstExprNode *expr)
 :
    AstExprNode(lineNumber),
    d_value(value),
    d_expr(expr)
{}

inline std::string AstUnaryNode::value() const
{
    return d_value;
}

inline AstExprNode *AstUnaryNode::expr() const
{
    return d_expr;
}

#endif
