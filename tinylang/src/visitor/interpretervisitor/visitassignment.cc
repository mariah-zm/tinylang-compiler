#include "interpretervisitor.ih"

void InterpreterVisitor::visit(AstAssignmentNode *node)
{
    node->right()->acceptVisitor(this);
    // No type checking as type checks were done using SemanticVisitor
    d_symbolTable.updateIdentifier(node->idenName(), d_currentLit);
}