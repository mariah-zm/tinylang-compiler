#include "astifstmtnode.h"

#include "../../visitor/visitor.h"

void AstIfStmtNode::acceptVisitor(Visitor *vis)
{
    vis->visit(this);
}