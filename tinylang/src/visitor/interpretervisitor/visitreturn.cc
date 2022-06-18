#include "interpretervisitor.ih"

void InterpreterVisitor::visit(AstReturnStmtNode *node)
{
    // The current identifier will be set to the expression in return statement
    node->expr()->acceptVisitor(this);
    d_LitToReturn = d_currentLit;
    d_return = true;
}