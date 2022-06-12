#include "symboltable.ih"

void SymbolTable::updateIdentifier(string idenName, char newVal)
{
    Identifier *identifier = findIdentifier(idenName);
    identifier->d_val.charVal = newVal;
}