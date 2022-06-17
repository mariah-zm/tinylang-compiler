#include "astprintstmtnode.h"

#include "../../visitor/visitor.h"

void AstPrintStmtNode::acceptVisitor(Visitor *vis)
{
    vis->visit(this);
}