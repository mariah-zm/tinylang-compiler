#include "astprogramnode.h"

#include "../visitor/visitor.h"

void AstProgramNode::acceptVisitor(Visitor *vis)
{
    vis->visit(this);
}