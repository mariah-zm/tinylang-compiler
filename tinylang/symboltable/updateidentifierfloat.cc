#include "symboltable.ih"

void SymbolTable::updateIdentifier(string idenName, float newVal)
{
    Identifier *identifier = findIdentifier(idenName);
    identifier->d_val.floatVal = newVal;
}