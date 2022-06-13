#ifndef INCLUDED_ASTASSIGNMENTNODE_
#define INCLUDED_ASTASSIGNMENTNODE_

#include <string>

#include "aststatementnode.h"
#include "../expressions/astidentifiernode.h"
#include "../expressions/astexprnode.h"

// Forward-declaration due to cyclic dependency
class Visitor;

class AstAssignmentNode: public AstStatementNode
{
    std::string d_idenName;
    AstExprNode *d_right;

    public:
        AstAssignmentNode(size_t lineNumber, std::string &name, AstExprNode *right);
        virtual ~AstAssignmentNode();

        virtual void acceptVisitor(Visitor *vis);

        // Getters
        std::string idenName() const;
        AstExprNode *right();

};

inline AstAssignmentNode::~AstAssignmentNode() = default;

inline AstAssignmentNode::AstAssignmentNode(size_t lineNumber, 
                                            std::string &name, 
                                            AstExprNode *right)
:
    AstStatementNode(lineNumber),
    d_idenName(name),
    d_right(right)
{}

inline std::string AstAssignmentNode::idenName() const
{
    return d_idenName;
}

inline AstExprNode *AstAssignmentNode::right()
{
    return d_right;
}

#endif