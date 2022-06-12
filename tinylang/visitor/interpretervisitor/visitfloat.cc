#include "interpretervisitor.ih"

void InterpreterVisitor::visit(AstFloatLiteralNode *node)
{
    // Setting type to match in expression
    d_typeToMatch = Type::FLOAT;
}