#include "astforstmtnode.h"

void AstForStmtNode::acceptVisitor(Visitor *vis)
{
    vis->visit(this);
}
