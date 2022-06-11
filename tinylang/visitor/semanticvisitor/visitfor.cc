#include "semanticvisitor.ih"

void SemanticVisitor::visit(AstForStmtNode *node)
{
    // Opening scope for loop brackets
    d_symbolTable.openScope();

    node->init()->acceptVisitor(this);
    node->condition()->acceptVisitor(this);
    node->update()->acceptVisitor(this);
    node->body()->acceptVisitor(this);

    // Closing scope for loop brackets
    d_symbolTable.closeScope();
}