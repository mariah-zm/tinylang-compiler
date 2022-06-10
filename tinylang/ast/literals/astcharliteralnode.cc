#include "astcharliteralnode.h"

void AstCharLiteralNode::acceptVisitor(Visitor *vis)
{
    vis->visit(this);
}