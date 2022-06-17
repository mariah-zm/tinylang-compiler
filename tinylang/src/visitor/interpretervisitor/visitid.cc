#include "interpretervisitor.ih"

void InterpreterVisitor::visit(AstIdentifierNode *node)
{
    // Setting current iden to iden of variable
    d_currentIden = Identifier{*d_symbolTable->findIdentifier(node->name())};
}