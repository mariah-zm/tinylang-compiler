#include "semanticvisitor.ih"

void SemanticVisitor::visit(AstFloatLiteralNode *node)
{
    // Setting type to match in expression
    d_typeToMatch = Type::FLOAT;
}