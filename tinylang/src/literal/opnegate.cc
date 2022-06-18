#include "literal.ih"

Literal operator-(Literal const &iden)
{
    Type type;
    Literal::Value val;

    switch (iden.d_type.type())
    {
        case Type::FLOAT: 
            type = Type::FLOAT;
            val.floatVal = -iden.d_val.floatVal;
            break;
        case Type::INT: 
            type = Type::INT;
            val.intVal = -iden.d_val.intVal;
            break;
        default: ; // negation - on BOOL and CHAR not semantically allowed
    }

    return Literal{type, val};
}
