#include "interpretervisitor.ih"

void InterpreterVisitor::visit(AstCharLiteralNode *node)
{
    // Setting type to match in expression
    d_typeToMatch = Type::CHAR;
}