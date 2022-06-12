#include "interpretervisitor.ih"

void InterpreterVisitor::visit(AstFunctionNode *node)
{
    // Opening scope for function def
    d_symbolTable.openScope();

    node->prototype()->acceptVisitor(this);
    node->body()->acceptVisitor(this);

    AstStatementNode *lastStmt = node->body()->statements().back();

    // Closing scope for function def
    d_symbolTable.closeScope();
}