#include "symboltable.ih"

Identifier *SymbolTable::findIdentifier(string idenName)
{
    size_t scopeSize = d_scopeStack.size();
    
    for (size_t idx = scopeSize - 1; idx >= 0; idx--)
    {
        try
        {
            // if this does not throw ex variable is found in this scope
            return & d_scopeStack[idx].at(idenName); 
        }
        catch (out_of_range &ex)
        {
        }
    }

    throw out_of_range("variable not found");
}