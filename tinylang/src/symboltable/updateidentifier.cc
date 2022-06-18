#include "symboltable.ih"

void SymbolTable::updateIdentifier(string idenName, Literal newVal)
{
    Literal *literal = findIdentifier(idenName);
    *literal = newVal;
}