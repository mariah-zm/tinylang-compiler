#include "astforstmtnode.h"

#include "../../visitor/visitor.h"

void AstForStmtNode::acceptVisitor(Visitor *vis)
{
    vis->visit(this);
}
