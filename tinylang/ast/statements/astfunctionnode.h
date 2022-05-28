#ifndef INCLUDED_ASTFUNCTIONNODE_
#define INCLUDED_ASTFUNCTIONNODE_

#include "aststatementnode.h"
#include "astfunctionprototypenode.h"
#include "astblocknode.h"

class AstFunctionNode: public AstStatementNode
{
    AstFunctionPrototypeNode *d_prototype;
    AstBlockNode *d_body;

    public:
        AstFunctionNode(AstFunctionPrototypeNode *prototype, AstBlockNode *body);
        virtual ~AstFunctionNode() = default;
        AstFunctionPrototypeNode *prototype();

};

inline AstFunctionNode::AstFunctionNode
                (AstFunctionPrototypeNode *prototype, AstBlockNode *body)
:
    d_prototype(prototype),
    d_body(body)
{}

inline AstFunctionPrototypeNode *AstFunctionNode::prototype()
{
    return d_prototype;
}

#endif