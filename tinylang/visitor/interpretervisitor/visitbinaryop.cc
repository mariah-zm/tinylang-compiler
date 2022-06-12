#include "interpretervisitor.ih"

void InterpreterVisitor::visit(AstBinaryOpNode *node)
{
    // Semantic Analysis on expression on LHS
    node->left()->acceptVisitor(this);
    Type leftType = d_typeToMatch;

    // Semantic Analysis on expression on RHS
    node->right()->acceptVisitor(this);
    Type rightType = d_typeToMatch;
    
}