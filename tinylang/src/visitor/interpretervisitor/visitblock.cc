#include "interpretervisitor.ih"

void InterpreterVisitor::visit(AstBlockNode *node)
{
    // Starting new scope
    d_symbolTable.openScope();

    size_t idx = 0;
    auto stmts = node->statements();

    while (!d_return)
    {
        stmts[idx]->acceptVisitor(this);
        ++idx;
    }          

    // Ending the scope once the block ends
    d_symbolTable.closeScope();
}