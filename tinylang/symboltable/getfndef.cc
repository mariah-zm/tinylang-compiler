#include "symboltable.ih"

AstFunctionPrototypeNode *SymbolTable::getFnDef(string fnName)
{
    try
    {
        return d_declaredFunctions.at(fnName);
    } 
    catch (out_of_range &ex)
    {
        throw ex;
    }
}