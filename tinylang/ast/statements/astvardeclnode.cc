#include "astvardeclnode.h"

#include "../../visitor/visitor.h"

void AstVarDeclNode::acceptVisitor(Visitor *vis)
{
    vis->visit(this);
}
