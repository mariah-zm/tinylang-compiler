#include "semanticvisitor.ih"

void SemanticVisitor::visit(AstIntLiteralNode *node)
{
    // Setting type to match in expression
    d_typeToMatch = Type::INT;
}