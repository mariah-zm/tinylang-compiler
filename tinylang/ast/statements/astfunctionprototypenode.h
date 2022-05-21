#ifndef INCLUDED_ASTFUNCTIONPROTOTYPENODE_
#define INCLUDED_ASTFUNCTIONPROTOTYPENODE_

#include "../astnode.h"
#include "../../identifier/identifier.h"

#include <vector>

class AstFunctionPrototypeNode: public AstNode
{
    std::string d_fnName;
    std::vector<Identifier> d_params;

    public:
        AstFunctionPrototypeNode(std::string &name);
        AstFunctionPrototypeNode(std::string &name, std::vector<Identifier> &params);
        virtual ~AstFunctionPrototypeNode() = default;

};

inline AstFunctionPrototypeNode::AstFunctionPrototypeNode(std::string &name)
:
    d_fnName(name)
{}

inline AstFunctionPrototypeNode::AstFunctionPrototypeNode
                        (std::string &name, std::vector<Identifier> &params)
:
    d_fnName(name),
    d_params(params)
{}

#endif