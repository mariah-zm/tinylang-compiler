#include "astprogramnode.h"

#include "../visitor/visitor.h"

void AstProgramNode::acceptVisitor(Visitor *vis)
{
    for (auto stmt: d_childNodes)
        stmt->acceptVisitor(vis);
}