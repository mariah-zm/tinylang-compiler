#include "semanticvisitor.ih"

void SemanticVisitor::visit(AstBoolLiteralNode *node)
{
    // Setting type to match in expression
    d_typeToMatch = Type::BOOL;
}