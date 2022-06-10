#include "astfunctioncallnode.h"

void AstFunctionCallNode::acceptVisitor(Visitor *vis)
{
    vis->visit(this);
}