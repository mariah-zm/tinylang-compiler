#include "interpretervisitor.ih"

void InterpreterVisitor::visit(AstVarDeclNode *node)
{
    string varName = node->left()->name();
    Type varType = node->type();

    // Semantic Analysis on expression on RHS
    node->right()->acceptVisitor(this);
}