#ifndef INCLUDED_IDENTIFIER
#define INCLUDED_IDENTIFIER

#include <string>
#include "../token/token.h"

class Identifier
{
    public:
        enum Type
        {
            INT,
            FLOAT,
            CHAR,
            BOOL
        };

    private:
        std::string d_name;
        Type d_type;

    public:
        Identifier(std::string name, Token::TokenType type);
        static Type getType(Token::TokenType tokType);
};

inline Identifier::Identifier(std::string name, Token::TokenType type)
:
    d_name(name),
    d_type(getType(type))
{}

#endif