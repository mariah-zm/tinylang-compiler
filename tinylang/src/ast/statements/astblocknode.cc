#include "astblocknode.h"

#include "../../visitor/visitor.h"

void AstBlockNode::acceptVisitor(Visitor *vis)
{
    vis->visit(this);
}