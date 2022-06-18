#include "literal.ih"

ostream &operator<<(std::ostream &out, Literal const &iden)
{
    switch (iden.d_type.type())
    {
        case Type::FLOAT: 
            out << iden.d_val.floatVal;
            break; 
        case Type::INT: 
            out << iden.d_val.intVal;
            break;
        case Type::BOOL: 
            out << boolalpha << iden.d_val.boolVal << noboolalpha;
            break;
        case Type::CHAR: 
            out << iden.d_val.charVal;
            break;
        default: out << "unknown";
    }

    return out;
}