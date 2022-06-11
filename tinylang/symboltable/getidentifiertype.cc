#include "symboltable.ih"

Type SymbolTable::getIdentifierType(string identifierName)
{
    for (size_t idx = d_scopeStack.size()-1; ; --idx)
    {
        try
        {
            return d_scopeStack[idx].at(identifierName);
        }
        catch (out_of_range &ex)
        {
            throw ex;
        }
    }
}