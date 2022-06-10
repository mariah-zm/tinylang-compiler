#include "astassignmentnode.h"

void AstAssignmentNode::acceptVisitor(Visitor *vis)
{
    vis->visit(this);
}
