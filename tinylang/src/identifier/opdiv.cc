#include "identifier.ih"

Identifier operator/(Identifier const &left, Identifier const &right)
{
    Type type;
    Identifier::Value val;

    switch (left.d_type.type())
    {
        case Type::FLOAT: 
            type = Type::FLOAT;
            val.floatVal = left.d_val.floatVal / right.d_val.floatVal;
            break;
        case Type::INT: 
            type = Type::INT;
            val.intVal = left.d_val.intVal / right.d_val.intVal;
            break;
        default: ; // / on BOOL and CHAR not semantically allowed
    }

    return Identifier{type, val};
}