#ifndef INCLUDED_ASTFUNCTIONPROTOTYPENODE_
#define INCLUDED_ASTFUNCTIONPROTOTYPENODE_

#include "../astnode.h"
#include "../../identifier/identifier.h"

#include <vector>

class AstFunctionPrototypeNode: public AstNode
{
    std::string d_fnName;
    std::vector<Identifier> d_params;
    Identifier::Type d_returnType;

    public:
        AstFunctionPrototypeNode(std::string &name, std::vector<Identifier> &params, Identifier::Type retType);
        virtual ~AstFunctionPrototypeNode() = default;

};

inline AstFunctionPrototypeNode::AstFunctionPrototypeNode
                        (std::string &name, std::vector<Identifier> &params,
                         Identifier::Type retType)
:
    d_fnName(name),
    d_params(params),
    d_returnType(retType)
{}

#endif