#include "interpretervisitor.ih"

void InterpreterVisitor::visit(AstWhileStmtNode *node)
{
    node->condition()->acceptVisitor(this);

    while (d_currentLit.isTrue() && !d_return) 
    {
        node->body()->acceptVisitor(this);
        node->condition()->acceptVisitor(this);
    }
}