#include "astboolliteralnode.h"

#include "../../visitor/visitor.h"

void AstBoolLiteralNode::acceptVisitor(Visitor *vis)
{
    vis->visit(this);
}
