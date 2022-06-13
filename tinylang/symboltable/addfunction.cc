#include "symboltable.ih"

bool SymbolTable::addFunction(AstFunctionNode *fn)
{
    try 
    {
        // No support for function overloading 
        d_declaredFunctions.at(fn->prototype()->name());
        return false;
    }
    catch (out_of_range &ex)
    {
        d_declaredFunctions.insert(
            pair<string, AstFunctionNode*>(fn->prototype()->name(), fn));
        return true;
    }
}