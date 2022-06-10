#include "astfunctionnode.h"

void AstFunctionNode::acceptVisitor(Visitor *vis)
{
    vis->visit(this);
}