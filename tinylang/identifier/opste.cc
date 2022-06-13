#include "identifier.ih"

bool operator<=(Identifier const &left, Identifier const &right)
{
    switch (left.d_type.type())
    {
        case Type::FLOAT: 
            return left.d_val.floatVal <= right.d_val.floatVal;
        case Type::INT: 
            return left.d_val.intVal <= right.d_val.intVal;
        case Type::CHAR: 
            return left.d_val.charVal <= right.d_val.charVal;
        default: 
            return false; // > on BOOL not semantically allowed
    }
}
