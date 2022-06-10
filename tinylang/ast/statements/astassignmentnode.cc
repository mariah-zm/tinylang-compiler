#include "astassignmentnode.h"

#include "../../visitor/visitor.h"

void AstAssignmentNode::acceptVisitor(Visitor *vis)
{
    vis->visit(this);
}
