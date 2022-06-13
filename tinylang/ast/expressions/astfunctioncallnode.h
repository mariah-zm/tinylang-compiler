#ifndef INCLUDED_ASTFUNCTIONCALLNODE_
#define INCLUDED_ASTFUNCTIONCALLNODE_

#include <vector>
#include <string>

#include "astexprnode.h"

// Forward-declaration due to cyclic dependency
class Visitor;

class AstFunctionCallNode: public AstExprNode
{
    std::string d_fnName;
    std::vector<AstExprNode *> d_args;

    public:
        AstFunctionCallNode() = delete;
        AstFunctionCallNode(size_t lineNumber, std::string &name, 
                            std::vector<AstExprNode *> &args);
        virtual ~AstFunctionCallNode();

        virtual void acceptVisitor(Visitor *vis);

        std::string fnName() const;
        std::vector<AstExprNode *> &args();

};

inline AstFunctionCallNode::~AstFunctionCallNode() = default;

inline AstFunctionCallNode::AstFunctionCallNode(size_t lineNumber,
                        std::string &name, std::vector<AstExprNode *> &args)
:
    AstExprNode(lineNumber),
    d_fnName(name),
    d_args(args)
{}

inline std::string AstFunctionCallNode::fnName() const
{
    return d_fnName;
}

inline std::vector<AstExprNode *> &AstFunctionCallNode::args()
{
    return d_args;
}

#endif