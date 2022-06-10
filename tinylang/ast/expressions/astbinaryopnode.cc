#include "astbinaryopnode.h"

void AstBinaryOpNode::acceptVisitor(Visitor *vis)
{
    vis->visit(this);
}
