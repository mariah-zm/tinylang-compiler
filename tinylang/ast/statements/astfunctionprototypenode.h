#ifndef INCLUDED_ASTFUNCTIONPROTOTYPENODE_
#define INCLUDED_ASTFUNCTIONPROTOTYPENODE_

#include "../astnode.h"
#include "../../identifier/identifier.h"

// Forward-declaration due to cyclic dependency
class Visitor;

#include <vector>

class AstFunctionPrototypeNode: public AstNode
{
    std::string d_fnName;
    std::vector<Identifier> d_params;
    Identifier::Type d_returnType;

    public:
        AstFunctionPrototypeNode(std::string &name, std::vector<Identifier> &params, Identifier::Type retType);
        virtual ~AstFunctionPrototypeNode();

        virtual void acceptVisitor(Visitor *vis);

        // Getters
        std::string name();
        std::vector<Identifier> &params();
        Identifier::Type returnType();

};

inline AstFunctionPrototypeNode::~AstFunctionPrototypeNode() = default;

inline AstFunctionPrototypeNode::AstFunctionPrototypeNode
                        (std::string &name, std::vector<Identifier> &params,
                         Identifier::Type retType)
:
    d_fnName(name),
    d_params(params),
    d_returnType(retType)
{}

inline std::string AstFunctionPrototypeNode::name()
{
    return d_fnName;
}

inline std::vector<Identifier> &AstFunctionPrototypeNode::params()
{
    return d_params;
}

inline Identifier::Type AstFunctionPrototypeNode::returnType()
{
    return d_returnType;
}

#endif