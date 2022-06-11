#include "type.ih"

ostream &operator<<(ostream &out, Type const &type)
{
    switch (type.d_type)
    {
        case Type::FLOAT: 
            out << "float";
            break; 
        case Type::INT: 
            out << "int";
            break;
        case Type::BOOL: 
            out << "bool";
            break;
        case Type::CHAR: 
            out << "char";
            break;
        default: out << "unknown";
    }

    return out;
}