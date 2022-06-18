#include "interpretervisitor.ih"

void InterpreterVisitor::visit(AstVarDeclNode *node)
{
    // Visting RHS to get current val
    node->right()->acceptVisitor(this);

    string varName = node->left()->name();
    d_symbolTable.addIdentifier(varName, d_currentLit);
}