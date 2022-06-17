#include "astfunctioncallnode.h"

#include "../../visitor/visitor.h"

void AstFunctionCallNode::acceptVisitor(Visitor *vis)
{
    vis->visit(this);
}