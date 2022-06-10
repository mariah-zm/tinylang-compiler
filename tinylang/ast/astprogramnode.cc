#include "astprogramnode.h"

void AstProgramNode::acceptVisitor(Visitor *vis)
{
    for (auto stmt: d_childNodes)
        stmt->acceptVisitor(vis);
}