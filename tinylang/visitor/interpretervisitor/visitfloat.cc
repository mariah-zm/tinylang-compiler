#include "interpretervisitor.ih"

void InterpreterVisitor::visit(AstFloatLiteralNode *node)
{
    // Setting current value (iden) to value in node
    d_currentIden = Identifier{node->value()};
}