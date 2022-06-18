#include "interpretervisitor.ih"

void InterpreterVisitor::visit(AstBlockNode *node)
{
    // Starting new scope
    d_symbolTable.openScope();

    size_t idx = 0;
    auto stmts = node->statements();
    size_t num_stmts = stmts.size();

    while (!d_return && idx < num_stmts)
    {
        stmts[idx]->acceptVisitor(this);
        ++idx;
    }          

    // Ending the scope once the block ends
    d_symbolTable.closeScope();
}