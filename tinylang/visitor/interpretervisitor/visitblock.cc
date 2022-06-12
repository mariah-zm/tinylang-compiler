#include "interpretervisitor.ih"

void InterpreterVisitor::visit(AstBlockNode *node)
{
    // Starting new scope
    d_symbolTable.openScope();

    for (auto stmt: node->statements())
        stmt->acceptVisitor(this);  

    // Ending the scope once the block ends
    d_symbolTable.closeScope();
}