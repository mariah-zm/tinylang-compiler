#include "semanticvisitor.ih"

void SemanticVisitor::visit(AstFunctionNode *node)
{
    // Opening scope for function def
    d_symbolTable.openScope();

    node->prototype()->acceptVisitor(this);
    node->body()->acceptVisitor(this);

    AstStatementNode *lastStmt = node->body()->statements().back();

    if (dynamic_cast<AstReturnStmtNode *> (lastStmt) == nullptr)
        throw semantic_error("missing return statement in function " 
                            + node->prototype()->name());

    // Closing scope for function def
    d_symbolTable.closeScope();
}