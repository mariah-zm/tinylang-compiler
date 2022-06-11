#include "symboltable.ih"

bool SymbolTable::addFunction(AstFunctionPrototypeNode *fn)
{
    try 
    {
        // no support for function overloading 
        d_declaredFunctions.at(fn->name());
        return false;
    }
    catch (out_of_range &ex)
    {
        d_declaredFunctions.insert(
            pair<string, AstFunctionPrototypeNode*>(fn->name(), fn));
        return true;
    }
}