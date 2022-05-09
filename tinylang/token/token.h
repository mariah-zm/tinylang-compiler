#ifndef INCLUDED_TOKEN_
#define INCLUDED_TOKEN_

#include <string>
#include <set>

class Token
{
    public:
        enum TokenType
        {
            NUMBER, 
            IDENTIFIER,
            KEYWORD,
            EOF_TK
        };

    std::set<std::string> s_keywords = {"float", "int", "bool", "char",
                                        "true", "false",
                                        "not", "and", "or",
                                        "for", "while", "fn", "let", 
                                        "return", "print", "if", "else"};

    std::string d_value;
    TokenType d_type;

    public:
        Token(std::string value, TokenType type);

        std::string const &value() const;
        bool isEof() const;
};

inline Token::Token(std::string value, TokenType type)
:
    d_value(value),
    d_type(type)
{}

inline std::string const &Token::value() const
{
    return d_value;
}

inline bool Token::isEof() const
{
    return d_type == EOF_TK;
}

#endif