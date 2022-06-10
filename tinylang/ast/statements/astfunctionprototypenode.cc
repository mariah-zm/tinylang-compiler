#include "astfunctionprototypenode.h"

void AstFunctionPrototypeNode::acceptVisitor(Visitor *vis)
{
    vis->visit(this);
}