#ifndef INCLUDED_ASTFUNCTIONPROTOTYPENODE_
#define INCLUDED_ASTFUNCTIONPROTOTYPENODE_

#include "../astnode.h"
#include "../../type/type.h"

// Forward-declaration due to cyclic dependency
class Visitor;

#include <vector>

class AstFunctionPrototypeNode: public AstNode
{
    public:
        struct Param
        {
            std::string d_name;
            Type d_type;
        };

    private:
        std::string d_fnName;
        std::vector<Param> d_params;
        Type d_returnType;

    public:
        AstFunctionPrototypeNode(std::string &name, std::vector<Param> &params, Type retType);
        virtual ~AstFunctionPrototypeNode();

        virtual void acceptVisitor(Visitor *vis);

        // Getters
        std::string name();
        std::vector<Param> &params();
        Type returnType();

};

inline AstFunctionPrototypeNode::~AstFunctionPrototypeNode() = default;

inline AstFunctionPrototypeNode::AstFunctionPrototypeNode
                        (std::string &name, std::vector<Param> &params,
                         Type retType)
:
    d_fnName(name),
    d_params(params),
    d_returnType(retType)
{}

inline std::string AstFunctionPrototypeNode::name()
{
    return d_fnName;
}

inline std::vector<AstFunctionPrototypeNode::Param> 
                                    &AstFunctionPrototypeNode::params()
{
    return d_params;
}

inline Type AstFunctionPrototypeNode::returnType()
{
    return d_returnType;
}

#endif