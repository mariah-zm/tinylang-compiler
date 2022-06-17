#include "astfunctionprototypenode.h"

#include "../../visitor/visitor.h"

void AstFunctionPrototypeNode::acceptVisitor(Visitor *vis)
{
    vis->visit(this);
}