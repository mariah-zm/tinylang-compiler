#include "interpretervisitor.ih"

void InterpreterVisitor::visit(AstAssignmentNode *node)
{
    // Checking if variable has been declared prior to use using try-catch
    try 
    {
        Type leftType = d_symbolTable.getIdentifierType(node->idenName());
       
        node->right()->acceptVisitor(this);

    }
    catch (out_of_range &ex)
    {
    }
}