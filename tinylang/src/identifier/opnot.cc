#include "identifier.ih"

bool operator!(Identifier const &iden)
{
    switch (iden.d_type.type())
    {
        case Type::BOOL: 
            return !iden.d_val.boolVal;
        default: 
            return false; // ~ on CHAR, FLOAT, INT not semantically allowed
    }
}
