#ifndef INCLUDED_ASTFUNCTIONCALLNODE_
#define INCLUDED_ASTFUNCTIONCALLNODE_

#include "astexprnode.h"

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

};

inline AstFunctionCallNode::AstFunctionCallNode
                        (std::string &name, std::vector<AstExprNode *> &args)
:
    d_fnName(name),
    d_args(args)
{}

#endif