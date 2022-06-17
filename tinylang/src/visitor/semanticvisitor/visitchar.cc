#include "semanticvisitor.ih"

void SemanticVisitor::visit(AstCharLiteralNode *node)
{
    // Setting type to match in expression
    d_typeToMatch = Type::CHAR;
}