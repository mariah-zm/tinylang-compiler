#include "symboltable.ih"

bool SymbolTable::addIdentifier(string name, Literal lit)
{
    try 
    {
        d_scopeStack.back().at(name);
        return false;
    }
    catch (out_of_range &ex)
    {
        d_scopeStack.back().insert(pair<string, Literal>(name, lit));
        return true;
    }
}