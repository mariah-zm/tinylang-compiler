#include "semanticvisitor.ih"

void SemanticVisitor::visit(AstAssignmentNode *node)
{
    // Checking if variable has been declared prior to use using try-catch
    try 
    {
        Type leftType = d_symbolTable->findIdentifier(node->idenName())->type();
       
        node->right()->acceptVisitor(this);
        
        // Type checking
        if (leftType != d_typeToMatch)
            throw semantic_error("type mismatch in assignment in line "
                + to_string(node->lineNumber()));
    }
    catch (out_of_range &ex)
    {
        throw semantic_error("variable " + node->idenName() + " in line "
                + to_string(node->lineNumber())
                + " is not defined in this scope");
    }
}