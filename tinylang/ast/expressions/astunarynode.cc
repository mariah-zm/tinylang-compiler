#include "astunarynode.h"

#include "../../visitor/visitor.h"

void AstUnaryNode::acceptVisitor(Visitor *vis)
{
    vis->visit(this);
}