#include "interpretervisitor.ih"

void InterpreterVisitor::visit(AstWhileStmtNode *node)
{
    node->condition()->acceptVisitor(this);

    while (d_currentLit.isTrue()) 
    {
        node->body()->acceptVisitor(this);
        node->condition()->acceptVisitor(this);
    }
}