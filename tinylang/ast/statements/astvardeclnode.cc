#include "astvardeclnode.h"

void AstVarDeclNode::acceptVisitor(Visitor *vis)
{
    vis->visit(this);
}
