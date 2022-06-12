#include "interpretervisitor.ih"

void InterpreterVisitor::visit(AstBoolLiteralNode *node)
{
    // Setting type to match in expression
    d_typeToMatch = Type::BOOL;
}