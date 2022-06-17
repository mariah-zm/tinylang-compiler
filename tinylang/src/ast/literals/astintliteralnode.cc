#include "astintliteralnode.h"

#include "../../visitor/visitor.h"

void AstIntLiteralNode::acceptVisitor(Visitor *vis)
{
    vis->visit(this);
}