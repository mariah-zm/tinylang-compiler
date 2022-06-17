#include "astbinaryopnode.h"

#include "../../visitor/visitor.h"

void AstBinaryOpNode::acceptVisitor(Visitor *vis)
{
    vis->visit(this);
}
