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
        Type(Type const &type) = default; // copy constructor
        Type(TypeEnum typeEnum);
        Type(Token::TokenType type);

        TypeEnum type() const;

        friend std::ostream &operator<<(std::ostream &out, Type const &type);
        friend bool operator==(Type const &lhs, Type const &rhs);
        friend bool operator!=(Type const &lhs, Type const &rhs);
   
};

inline Type::Type(Type::TypeEnum typeEnum)
:
    d_type(typeEnum)
{}

inline Type::TypeEnum Type::type() const
{
    return d_type;
}

inline bool operator==(Type const &lhs, Type const &rhs)
{
    return lhs.d_type == rhs.d_type;
}

inline bool operator!=(Type const &lhs, Type const &rhs)
{
    return lhs.d_type != rhs.d_type;
}

#endif