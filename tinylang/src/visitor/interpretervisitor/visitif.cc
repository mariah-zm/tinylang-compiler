#include "interpretervisitor.ih"

void InterpreterVisitor::visit(AstIfStmtNode *node)
{
    node->condition()->acceptVisitor(this);

    if (d_currentIden.isTrue())
        node->body()->acceptVisitor(this);
    else if (node->elseBody() != nullptr)
        node->elseBody()->acceptVisitor(this);
}