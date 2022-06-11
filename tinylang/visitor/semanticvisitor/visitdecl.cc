#include "semanticvisitor.ih"

void SemanticVisitor::visit(AstVarDeclNode *node)
{
    string varName = node->left()->name();
    Type varType = node->type();
    
    // Adding Identifier declaration to symbol table
    if (!d_symbolTable.addIdentifier(varName, varType))
        throw semantic_error("variable " + varName + " is already defined in this scope");

    // Semantic Analysis on expression on RHS
    node->right()->acceptVisitor(this);

    // Type checking
    if (varType != d_typeToMatch)
        throw semantic_error("type mismatch in variable declaration");
}