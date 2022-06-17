#include "semanticvisitor.ih"

void SemanticVisitor::visit(AstPrintStmtNode *node)
{
    node->expr()->acceptVisitor(this);
}