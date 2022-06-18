#include "interpretervisitor.ih"

void InterpreterVisitor::visit(AstIdentifierNode *node)
{
    // Setting current literal to the literal of the variable
    d_currentLit = Literal{*d_symbolTable->findIdentifier(node->name())};
}