#include "symboltable.ih"

bool SymbolTable::addIdentifier(string name, Type type)
{
    try 
    {
        d_scopeStack.back().at(name);
        return false;
    }
    catch (out_of_range &ex)
    {
        Literal literal = Literal{type};
        d_scopeStack.back().insert(pair<string, Literal>(name, literal));
        return true;
    }
}