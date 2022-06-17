#include "interpretervisitor.ih"

void InterpreterVisitor::visit(AstProgramNode *node)
{
    for (auto stmt: node->statements())
        stmt->acceptVisitor(this);
}