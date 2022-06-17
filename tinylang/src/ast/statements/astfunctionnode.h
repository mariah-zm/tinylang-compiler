#ifndef INCLUDED_ASTFUNCTIONNODE_
#define INCLUDED_ASTFUNCTIONNODE_

#include "astfunctionprototypenode.h"
#include "astblocknode.h"

// Forward-declaration due to cyclic dependency
class Visitor;

class AstFunctionNode: public AstStatementNode
{
    AstFunctionPrototypeNode *d_prototype;
    AstBlockNode *d_body;

    public:
        AstFunctionNode(AstFunctionPrototypeNode *prototype, AstBlockNode *body);
        virtual ~AstFunctionNode();

        virtual void acceptVisitor(Visitor *vis);

        // Getters
        AstFunctionPrototypeNode *prototype();
        AstBlockNode *body();

};

inline AstFunctionNode::~AstFunctionNode()
{
    delete d_prototype;
    delete d_body;
}

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

inline AstBlockNode *AstFunctionNode::body()
{
    return d_body;
}

#endif