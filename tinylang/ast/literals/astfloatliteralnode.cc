#include "astfloatliteralnode.h"

void AstFloatLiteralNode::acceptVisitor(Visitor *vis)
{
    vis->visit(this);
}

