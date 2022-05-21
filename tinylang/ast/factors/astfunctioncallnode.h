#ifndef INCLUDED_ASTFUNCTIONPROTOTYPENODE_
#define INCLUDED_ASTFUNCTIONPROTOTYPENODE_

#include "astfactornode.h"
#include "../identifier/identifier.h"

#include <vector>
#include <string>

class AstFunctionCallNode: public AstFactorNode
{
    std::string d_fnName;
    std::vector<AstFactorNode *> d_args;

    public:
        AstFunctionCallNode() = delete;
        AstFunctionCallNode(std::string &name, std::vector<AstFactorNode *> &args);
        virtual ~AstFunctionCallNode() = default;

};

inline AstFunctionCallNode::AstFunctionCallNode
                        (std::string &name, std::vector<AstFactorNode *> &args)
:
    d_fnName(name),
    d_args(args)
{}

#endif