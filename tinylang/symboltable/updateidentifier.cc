#include "symboltable.ih"

void SymbolTable::updateIdentifier(string idenName, Identifier newVal)
{
    Identifier *identifier = findIdentifier(idenName);
    *identifier = newVal;
}