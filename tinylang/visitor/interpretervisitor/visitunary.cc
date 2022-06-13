#include "interpretervisitor.ih"

void InterpreterVisitor::visit(AstUnaryNode *node)
{
    node->expr()->acceptVisitor(this);

    if (node->value() == "-")
        d_currentIden = -d_currentIden;
    else
        d_currentIden = Identifier{!d_currentIden};
}