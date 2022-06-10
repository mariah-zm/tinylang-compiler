#include "astintliteralnode.h"

void AstIntLiteralNode::acceptVisitor(Visitor *vis)
{
    vis->visit(this);
}