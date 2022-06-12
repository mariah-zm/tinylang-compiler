#include "interpretervisitor.ih"

void InterpreterVisitor::visit(AstPrintStmtNode *node)
{
    node->expr()->acceptVisitor(this);
}