#include "interpretervisitor.ih"

void InterpreterVisitor::visit(AstBoolLiteralNode *node)
{
    // Setting current value (iden) to value in node
    d_currentIden = Identifier{node->value()};
}