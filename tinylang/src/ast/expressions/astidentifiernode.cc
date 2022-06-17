#include "astidentifiernode.h"

#include "../../visitor/visitor.h"

void AstIdentifierNode::acceptVisitor(Visitor *vis)
{
    vis->visit(this);
}