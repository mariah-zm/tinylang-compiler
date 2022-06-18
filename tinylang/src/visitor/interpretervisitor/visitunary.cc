#include "interpretervisitor.ih"

void InterpreterVisitor::visit(AstUnaryNode *node)
{
    node->expr()->acceptVisitor(this);

    if (node->value() == "-")
        d_currentLit = -d_currentLit;
    else
        d_currentLit = Literal{!d_currentLit};
}