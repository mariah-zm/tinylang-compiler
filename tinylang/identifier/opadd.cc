#include "identifier.ih"

Identifier operator+(Identifier const &left, Identifier const &right)
{
    Type type;
    Identifier::Value val;

    switch (left.d_type.type())
    {
        case Type::FLOAT: 
            type = Type::FLOAT;
            val.floatVal = left.d_val.floatVal + right.d_val.floatVal;
            break;
        case Type::INT: 
            type = Type::INT;
            val.intVal = left.d_val.intVal + right.d_val.intVal;
            break;
        case Type::CHAR: 
            type = Type::CHAR;
            val.charVal = left.d_val.charVal + right.d_val.charVal;
            break;
        default: ; // + on BOOL not semantically allowed
    }

    return Identifier{type, val};
}