#include "symboltable.ih"

Type SymbolTable::getIdentifierType(string identifierName)
{
    size_t scopeSize = d_scopeStack.size();

    for (size_t idx = scopeSize - 1; idx >= 0; idx--)
    {
        try
        {
            return d_scopeStack[idx].at(identifierName);
        }
        catch (out_of_range &ex)
        {
        }
    }

    throw out_of_range("");
}