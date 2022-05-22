#ifndef INCLUDED_IDENTIFIER
#define INCLUDED_IDENTIFIER

#include <string>
#include "../token/token.h"

class Identifier
{
    enum IdentifierType
    {
        INT,
        FLOAT,
        CHAR,
        BOOL
    };

    std::string d_name;
    IdentifierType d_type;

    public:
        Identifier(std::string name, Token::TokenType type);
};

#endif