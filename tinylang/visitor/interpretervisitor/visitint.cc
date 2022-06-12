#include "interpretervisitor.ih"

void InterpreterVisitor::visit(AstIntLiteralNode *node)
{
    // Setting type to match in expression
    d_typeToMatch = Type::INT;
}