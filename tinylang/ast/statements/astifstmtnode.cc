#include "astifstmtnode.h"

void AstIfStmtNode::acceptVisitor(Visitor *vis)
{
    vis->visit(this);
}