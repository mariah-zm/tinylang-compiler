#include "astblocknode.h"

#include "../../visitor/visitor.h"

void AstBlockNode::acceptVisitor(Visitor *vis)
{
    for (auto stmt: d_statements)
        stmt->acceptVisitor(vis);
}