#include "astunarynode.h"

void AstUnaryNode::acceptVisitor(Visitor *vis)
{
    vis->visit(this);
}