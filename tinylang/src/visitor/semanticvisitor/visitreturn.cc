#include "semanticvisitor.ih"

void SemanticVisitor::visit(AstReturnStmtNode *node)
{
    if (!d_requiresReturn)
        throw semantic_error("return statement not allowed in line "
                + to_string(node->lineNumber()));
    
    node->expr()->acceptVisitor(this);

    // Type checking with function return type    
    if (d_typeToReturn != d_typeToMatch)
        throw semantic_error("type mismatch in return statement in line "
                + to_string(node->lineNumber()));
}