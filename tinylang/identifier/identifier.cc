#include "identifier.ih"

Identifier::Identifier(Identifier const &other)
:
    d_type(other.d_type)
{
    switch (d_type.type())
    {
        case Type::FLOAT: 
            d_val.floatVal = other.d_val.floatVal;
            break;
        case Type::INT: 
            d_val.intVal = other.d_val.intVal;
            break;
        case Type::CHAR: 
            d_val.charVal = other.d_val.charVal;
            break;
        case Type::BOOL: 
            d_val.boolVal = other.d_val.boolVal;
            break;
        default: 
            ; // default case required by C++ 
    }
}