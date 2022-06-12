#include "interpretervisitor.ih"

void InterpreterVisitor::visit(AstReturnStmtNode *node)
{
    node->expr()->acceptVisitor(this);

}