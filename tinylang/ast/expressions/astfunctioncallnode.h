#ifndef INCLUDED_ASTFUNCTIONCALLNODE_
#define INCLUDED_ASTFUNCTIONCALLNODE_

#include "astexprnode.h"
#include "../../visitor/visitor.h"

#include <vector>
#include <string>

class AstFunctionCallNode: public AstExprNode
{
    std::string d_fnName;
    std::vector<AstExprNode *> d_args;

    public:
        AstFunctionCallNode() = delete;
        AstFunctionCallNode(std::string &name, std::vector<AstExprNode *> &args);
        virtual ~AstFunctionCallNode() = default;

        virtual void acceptVisitor(Visitor *vis);

        std::string fnName() const;
        std::vector<AstExprNode *> &args();

};

inline AstFunctionCallNode::AstFunctionCallNode
                        (std::string &name, std::vector<AstExprNode *> &args)
:
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