#include "symboltable.ih"

void SymbolTable::updateIdentifier(string idenName, bool newVal)
{
    Identifier *identifier = findIdentifier(idenName);
    identifier->d_val.boolVal = newVal;
}