#include "semanticvisitor.ih"

void SemanticVisitor::visit(AstProgramNode *node)
{
    for (auto stmt: node->statements())
        stmt->acceptVisitor(this);
}