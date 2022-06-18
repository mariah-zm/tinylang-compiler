#include "semanticvisitor.ih"

void SemanticVisitor::visit(AstFunctionNode *node)
{
    d_requiresReturn = true;

    // Opening scope for function def
    d_symbolTable.openScope();

    // Adding function to symbol table
    if(!d_symbolTable.addFunction(node))
        throw semantic_error("a function with the name " 
            + node->prototype()->name() + " in line " 
            + to_string(node->lineNumber())
            + " has already been defined in this scope");

    node->prototype()->acceptVisitor(this);
    node->body()->acceptVisitor(this);

    // Checking if function contains return statement
    try 
    {
        checkReturn(node->body()->statements());
    }
    catch (semantic_error &ex)
    {
        throw semantic_error("missing return statement in function " 
                            + node->prototype()->name());
    }

    // Closing scope for function def
    d_symbolTable.closeScope();

    d_requiresReturn = false;
}