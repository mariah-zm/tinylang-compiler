#include "literal.ih"

Literal operator+(Literal const &left, Literal const &right)
{
    Type type;
    Literal::Value val;

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

    return Literal{type, val};
}