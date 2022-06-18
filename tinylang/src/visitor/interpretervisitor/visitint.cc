#include "interpretervisitor.ih"

void InterpreterVisitor::visit(AstIntLiteralNode *node)
{
    // Setting current literal value to value in node
    d_currentLit = Literal{node->value()};
}