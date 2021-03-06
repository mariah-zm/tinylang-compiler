#include "semanticvisitor.ih"

void SemanticVisitor::visit(AstFunctionPrototypeNode *node)
{
    // Adding all parameters to scope
    for (auto param: node->params())
        d_symbolTable.addIdentifier(param.d_name, param.d_type);

    // Setting return type
    d_typeToReturn = node->returnType();
}