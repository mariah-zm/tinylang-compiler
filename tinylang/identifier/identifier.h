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
        static Type getType(Token::TokenType tokType);
        static std::string typeToString(Type type);

        Identifier(std::string name, Token::TokenType type);
        std::string name() const;
        Type type() const;
        std::string typeAsString() const;
        
};

inline Identifier::Identifier(std::string name, Token::TokenType type)
:
    d_name(name),
    d_type(getType(type))
{}

inline std::string Identifier::name() const
{
    return d_name;
}

inline Identifier::Type Identifier::type() const
{
    return d_type;
}

inline std::string Identifier::typeAsString() const
{
    return Identifier::typeToString(d_type);
}

#endif