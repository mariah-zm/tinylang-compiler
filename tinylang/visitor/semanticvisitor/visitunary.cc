#include "semanticvisitor.ih"

void SemanticVisitor::visit(AstUnaryNode *node)
{
    node->expr()->acceptVisitor(this);
    validateTypeOp(node);
}