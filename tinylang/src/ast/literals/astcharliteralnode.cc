#include "astcharliteralnode.h"

#include "../../visitor/visitor.h"

void AstCharLiteralNode::acceptVisitor(Visitor *vis)
{
    vis->visit(this);
}