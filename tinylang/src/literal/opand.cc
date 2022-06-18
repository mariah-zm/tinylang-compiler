#include "literal.ih"

bool Literal::andOp(Literal const &other)
{
    switch (d_type.type())
    {
        case Type::BOOL: 
            return d_val.boolVal && other.d_val.boolVal;
        default: 
            return false; // && on CHAR, FLOAT, INT not semantically allowed
    }
}
