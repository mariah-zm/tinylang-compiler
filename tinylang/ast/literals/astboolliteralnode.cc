#include "astboolliteralnode.h"

void AstBoolLiteralNode::acceptVisitor(Visitor *vis)
{
    vis->visit(this);
}
