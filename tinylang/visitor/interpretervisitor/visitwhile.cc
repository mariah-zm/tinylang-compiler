#include "interpretervisitor.ih"

void InterpreterVisitor::visit(AstWhileStmtNode *node)
{
    node->condition()->acceptVisitor(this);
    node->body()->acceptVisitor(this);
}