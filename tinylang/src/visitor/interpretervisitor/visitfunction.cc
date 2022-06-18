#include "interpretervisitor.ih"

void InterpreterVisitor::visit(AstFunctionNode *node)
{
    d_symbolTable.addFunction(node);
}