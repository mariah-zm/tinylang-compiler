#include "identifier.ih"

bool Identifier::isTrue() const
{
    if (d_type != Type::BOOL)
        throw runtime_error("invalid type for function call");
    else
        return d_val.boolVal;
}