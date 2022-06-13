#include "interpretervisitor.ih"

void InterpreterVisitor::visit(AstFunctionPrototypeNode *node)
{
    // Adding all parameter variables to scope
    for (auto param: node->params())
        d_symbolTable->addIdentifier(param.d_name, param.d_type);
}