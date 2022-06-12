#include "interpretervisitor.ih"

void InterpreterVisitor::visit(AstIfStmtNode *node)
{
    node->condition()->acceptVisitor(this);
    node->body()->acceptVisitor(this);

    if (node->elseBody() != nullptr)
        node->elseBody()->acceptVisitor(this);
}