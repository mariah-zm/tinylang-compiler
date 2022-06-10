#include "astfloatliteralnode.h"

#include "../../visitor/visitor.h"

void AstFloatLiteralNode::acceptVisitor(Visitor *vis)
{
    vis->visit(this);
}

