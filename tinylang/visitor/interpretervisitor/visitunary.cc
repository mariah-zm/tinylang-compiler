#include "interpretervisitor.ih"

void InterpreterVisitor::visit(AstUnaryNode *node)
{
    node->expr()->acceptVisitor(this);
}