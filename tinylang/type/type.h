#ifndef INCLUDED_IDENTIFIER
#define INCLUDED_IDENTIFIER

#include <string>
#include <iostream>

#include "../token/token.h"

class Type
{
    public:
        enum TypeEnum
        {
            INT,
            FLOAT,
            CHAR,
            BOOL
        };

    private:
        TypeEnum d_type;

    public:
        Type() = default;
        Type(Type const &type) = default;
        Type(Token::TokenType type);

        friend std::ostream &operator<<(std::ostream &out, Type const &type);

        TypeEnum type() const;
   
};

inline Type::TypeEnum Type::type() const
{
    return d_type;
}

#endif