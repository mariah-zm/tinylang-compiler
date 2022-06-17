#include "semanticvisitor.ih"

void SemanticVisitor::visit(AstWhileStmtNode *node)
{
    node->condition()->acceptVisitor(this);
    node->body()->acceptVisitor(this);
}