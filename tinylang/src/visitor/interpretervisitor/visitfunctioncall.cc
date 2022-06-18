#include "interpretervisitor.ih"

void InterpreterVisitor::visit(AstFunctionCallNode *node)
{
    // Not checking for exceptions because we know semantic analysis phase
    // passed
    AstFunctionNode *fnNode = d_symbolTable.findFnDef(node->fnName());

    // Opening scope for function call
    d_symbolTable.openScope();

    vector<string> paramNames;

    // Getting param names to update their values at the beginning of scope
    for (auto param: fnNode->prototype()->params())
        paramNames.push_back(param.d_name);
    
    // Updating param values with arg values
    for (auto arg: node->args())
    {
        arg->acceptVisitor(this);
        d_symbolTable.addIdentifier(paramNames.at(0), d_currentLit);
        paramNames.erase(paramNames.begin());
    }

    // Interpret body
    fnNode->body()->acceptVisitor(this);

    // Closing scope for function call
    d_symbolTable.closeScope();

    d_currentLit = d_LitToReturn;
    d_return = false;
}