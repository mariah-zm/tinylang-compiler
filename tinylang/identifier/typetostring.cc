#include "identifier.ih"

string Identifier::typeToString(Type type)
{
    switch (type)
    {
        case FLOAT: return "float";
        case INT: return "int";
        case BOOL: return "bool";
        case CHAR: return "char";
        default: return "unknown";
    }
}