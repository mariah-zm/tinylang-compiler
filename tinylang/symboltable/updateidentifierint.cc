#include "symboltable.ih"

void SymbolTable::updateIdentifier(string idenName, int newVal)
{
    Identifier *identifier = findIdentifier(idenName);
    identifier->d_val.intVal = newVal;
}