#include "astwhilestmtnode.h"

#include "../../visitor/visitor.h"

void AstWhileStmtNode::acceptVisitor(Visitor *vis)
{
    vis->visit(this);
}