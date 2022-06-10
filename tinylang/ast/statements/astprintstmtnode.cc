#include "astprintstmtnode.h"

void AstPrintStmtNode::acceptVisitor(Visitor *vis)
{
    vis->visit(this);
}