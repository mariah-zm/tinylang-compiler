#include "semanticvisitor.ih"

void SemanticVisitor::checkReturn(AstBlockNode *block) const
{
    for (auto stmt : block->statements())
        if (dynamic_cast<AstReturnStmtNode *> (stmt) != nullptr)
            return;

    // If there isn't a return statement, there must be at least an if 
    // condition with an else, each having a return statement
    for (auto stmt : block->statements())
    {
        AstIfStmtNode *ifStmt = dynamic_cast<AstIfStmtNode *> (stmt);

        if (ifStmt != nullptr && ifStmt->elseBody() != nullptr)
        {
            checkReturn(ifStmt->body());
            checkReturn(ifStmt->elseBody());
            return;
        }
    }

    // If both loops exit without returning from function
    throw semantic_error("missing return statement");
}