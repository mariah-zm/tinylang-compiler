#ifndef INCLUDED_IDENTIFIER
#define INCLUDED_IDENTIFIER

#include <string>

enum IdentifierType
{
    INT,
    FLOAT,
    CHAR,
    BOOL
};
            
struct Identifier 
{
    std::string d_name;
    IdentifierType d_type;
};

#endif