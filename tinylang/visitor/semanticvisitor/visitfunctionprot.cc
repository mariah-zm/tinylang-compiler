#include "semanticvisitor.ih"

void SemanticVisitor::visit(AstFunctionPrototypeNode *node)
{
    // Adding function to symbol table
    if(!d_symbolTable.addFunction(node))
        throw semantic_error("a function with the name " + node->name() 
            + "has already been defined in this scope");

    // Adding all parameters to scope
    for (auto param: node->params())
        d_symbolTable.addIdentifier(param.d_name, param.d_type);

    // Setting return type
    d_typeToReturn = node->returnType();
}