#include "symboltable.ih"

Literal *SymbolTable::findIdentifier(string idenName)
{
    for (size_t idx = d_scopeStack.size(); idx > 0; idx--)
    {
        try
        {
            // if this does not throw ex variable is found in this scope
            return &d_scopeStack[idx-1].at(idenName); 
        }
        catch (out_of_range &ex)
        {
        }
    }

    throw out_of_range("variable not found");
}