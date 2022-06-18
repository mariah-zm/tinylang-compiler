#include "interpretervisitor.ih"

void InterpreterVisitor::visit(AstBinaryOpNode *node)
{
    // Resolving identifier of expression on LHS
    node->left()->acceptVisitor(this);
    Literal leftLit = d_currentLit;

    // Resolving identifier of expression on RHS
    node->right()->acceptVisitor(this);
    Literal rightLit = d_currentLit;

    if (node->value() == "+")
        d_currentLit = leftLit + rightLit;
    else if (node->value() == "-")
        d_currentLit = leftLit - rightLit;
    else if (node->value() == "*")
        d_currentLit = leftLit * rightLit;
    else if (node->value() == "/")
        d_currentLit = leftLit / rightLit;
    else if (node->value() == "and")
        d_currentLit = Literal{leftLit.andOp(rightLit)};
    else if (node->value() == "or")
        d_currentLit = Literal{leftLit.orOp(rightLit)};
    else if (node->value() == ">")
        d_currentLit = Literal{leftLit > rightLit};
    else if (node->value() == "<")
        d_currentLit = Literal{leftLit < rightLit};
    else if (node->value() == ">=")
        d_currentLit = Literal{leftLit >= rightLit};
    else if (node->value() == "<=")
        d_currentLit = Literal{leftLit <= rightLit};
    else if (node->value() == "==")
        d_currentLit = Literal{leftLit == rightLit};
    else if (node->value() == "!=")
        d_currentLit = Literal{leftLit != rightLit};    
}