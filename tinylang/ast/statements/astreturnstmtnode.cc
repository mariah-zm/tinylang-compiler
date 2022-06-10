#include "astreturnstmtnode.h"

#include "../../visitor/visitor.h"

void AstReturnStmtNode::acceptVisitor(Visitor *vis)
{
    vis->visit(this);
}