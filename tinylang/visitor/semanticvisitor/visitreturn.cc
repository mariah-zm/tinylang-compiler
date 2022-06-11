#include "semanticvisitor.ih"

void SemanticVisitor::visit(AstReturnStmtNode *node)
{
    node->expr()->acceptVisitor(this);

    // Type checking with function return type    
    if (d_typeToReturn != d_typeToMatch)
        throw semantic_error("type mismatch in return statement");
}