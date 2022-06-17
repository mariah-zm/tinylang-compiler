#include "symboltable.ih"

bool SymbolTable::addIdentifier(string name, Identifier iden)
{
    try 
    {
        d_scopeStack.back().at(name);
        return false;
    }
    catch (out_of_range &ex)
    {
        d_scopeStack.back().insert(pair<string, Identifier>(name, iden));
        return true;
    }
}