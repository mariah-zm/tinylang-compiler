#include "interpretervisitor.ih"

void InterpreterVisitor::visit(AstBinaryOpNode *node)
{
    // Resolving identifier of expression on LHS
    node->left()->acceptVisitor(this);
    Identifier leftIden = d_currentIden;

    // Resolving identifier of expression on RHS
    node->right()->acceptVisitor(this);
    Identifier rightIden = d_currentIden;

    if (node->value() == "+")
        d_currentIden = leftIden + rightIden;
    else if (node->value() == "-")
        d_currentIden = leftIden - rightIden;
    else if (node->value() == "*")
        d_currentIden = leftIden * rightIden;
    else if (node->value() == "/")
        d_currentIden = leftIden / rightIden;
    else if (node->value() == "and")
        d_currentIden = Identifier{leftIden.andOp(rightIden)};
    else if (node->value() == "or")
        d_currentIden = Identifier{leftIden.orOp(rightIden)};
    else if (node->value() == ">")
        d_currentIden = Identifier{leftIden > rightIden};
    else if (node->value() == "<")
        d_currentIden = Identifier{leftIden < rightIden};
    else if (node->value() == ">=")
        d_currentIden = Identifier{leftIden >= rightIden};
    else if (node->value() == "<=")
        d_currentIden = Identifier{leftIden <= rightIden};
    else if (node->value() == "==")
        d_currentIden = Identifier{leftIden == rightIden};
    else if (node->value() == "!=")
        d_currentIden = Identifier{leftIden != rightIden};    
}