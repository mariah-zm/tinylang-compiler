#include "semanticvisitor.ih"

void SemanticVisitor::visit(AstAssignmentNode *node)
{
    // Checking if variable has been declared prior to use using try-catch
    try 
    {
        Type leftType = d_symbolTable.findIdentifier(node->idenName())->d_type;
       
        node->right()->acceptVisitor(this);
        
        // Type checking
        if (leftType != d_typeToMatch)
            throw semantic_error("type mismatch in assignment");
    }
    catch (out_of_range &ex)
    {
        throw semantic_error("variable " + node->idenName() 
                                    + " is not defined in this scope");
    }
}