#include "astblocknode.h"

void AstBlockNode::acceptVisitor(Visitor *vis)
{
    for (auto stmt: d_statements)
        stmt->acceptVisitor(vis);
}

void AstBlockNode::addStatementChild(AstStatementNode *statement)
{
    d_statements.push_back(statement);
}