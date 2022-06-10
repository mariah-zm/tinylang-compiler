#include "astwhilestmtnode.h"

void AstWhileStmtNode::acceptVisitor(Visitor *vis)
{
    vis->visit(this);
}