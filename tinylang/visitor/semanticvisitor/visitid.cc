#include "semanticvisitor.ih"

void SemanticVisitor::visit(AstIdentifierNode *node)
{
    // Checking if variable has been declared prior to use using try-catch
    try 
    {
        // Setting type to match in expression
        d_typeToMatch = 
                    d_symbolTable.getIdentifierType(node->name());
    }
    catch (out_of_range &ex)
    {
        throw semantic_error("variable " + node->name() 
                                    + " is not defined in this scope");
    }
}