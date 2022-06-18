#include "semanticvisitor.ih"

void SemanticVisitor::visit(AstBinaryOpNode *node)
{
    // Semantic Analysis on expression on LHS
    node->left()->acceptVisitor(this);
    Type leftType = d_typeToMatch;

    validateTypeOp(node);

    // Semantic Analysis on expression on RHS
    node->right()->acceptVisitor(this);
    Type rightType = d_typeToMatch;

    // Type checking
    if (leftType != rightType)
        throw semantic_error("type mismatch in expression in line "
                + to_string(node->lineNumber()));
    
    // Setting type depending on operation
    if (node->value().find_first_of("<>!=") != string::npos)
        d_typeToMatch = Type{Type::BOOL};

}