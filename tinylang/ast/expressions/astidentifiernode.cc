#include "astidentifiernode.h"

void AstIdentifierNode::acceptVisitor(Visitor *vis)
{
    vis->visit(this);
}