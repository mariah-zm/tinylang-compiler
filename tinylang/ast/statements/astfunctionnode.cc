#include "astfunctionnode.h"

#include "../../visitor/visitor.h"

void AstFunctionNode::acceptVisitor(Visitor *vis)
{
    vis->visit(this);
}