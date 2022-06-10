#include "astreturnstmtnode.h"

void AstReturnStmtNode::acceptVisitor(Visitor *vis)
{
    vis->visit(this);
}