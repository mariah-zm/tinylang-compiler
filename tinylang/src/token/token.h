#ifndef INCLUDED_TOKEN_
#define INCLUDED_TOKEN_

#include <string>
#include <map>

class Token
{
    public:
        enum TokenType
        {
            INT_LIT, FLOAT_LIT, CHAR_LIT,
            IDENTIFIER, 
            INT, FLOAT, BOOL, CHAR,
            TRUE, FALSE,
            NOT, AND, OR,
            FOR, WHILE, FN, LET, RETURN, PRINT, IF, ELSE,
            ASSIGNMENT, // =
            REL_GT, REL_LT, REL_GTE, REL_LTE, REL_NE, REL_E, // > < >= <= != ==
            ADD, SUB, MUL, DIV, // + - * /
            OPEN_SCOPE, CLOSE_SCOPE, COMMA, SEMI_COLON, COLON, OPEN_BR, CLOSE_BR, // { } , ; : ( )
            ARROW, // ->
            COMMENT,
            EOF_TK, REL_OP, PUNCT
        };

    private:
        std::map<std::string, TokenType> d_keywordsMap = {{"int", INT},
                                                        {"float", FLOAT},
                                                        {"bool", BOOL},
                                                        {"char", CHAR},
                                                        {"true", TRUE},
                                                        {"false", FALSE},
                                                        {"not", NOT},
                                                        {"and", AND},
                                                        {"or", OR},
                                                        {"for", FOR},
                                                        {"while", WHILE},
                                                        {"fn", FN},
                                                        {"let", LET},
                                                        {"return", RETURN},
                                                        {"print", PRINT},
                                                        {"if", IF},
                                                        {"else", ELSE}};

        std::map<std::string, TokenType> d_relOpMap = {{">", REL_GT},
                                                    {"<", REL_LT},
                                                    {">=", REL_GTE},
                                                    {"<=", REL_LTE},
                                                    {"!=", REL_NE},
                                                    {"==", REL_E}};

        std::map<std::string, TokenType> d_punctMap = {{"{", OPEN_SCOPE},
                                                    {"}", CLOSE_SCOPE},
                                                    {",", COMMA},
                                                    {";", SEMI_COLON},
                                                    {":", COLON},
                                                    {"(", OPEN_BR},
                                                    {")", CLOSE_BR}};

        TokenType d_type;
        std::string d_value;

    public:
        Token() = default;
        Token(std::string value, TokenType type);

        TokenType type() const;
        std::string const &value() const;
        bool isEof() const;
        bool isType() const;
        bool isRelOp() const;
        bool isAddOp() const;
        bool isMulOp() const;
        bool isUnaryOp() const;
        bool isLiteral() const;
};

inline Token::TokenType Token::type() const
{
    return d_type;
}

inline std::string const &Token::value() const
{
    return d_value;
}

inline bool Token::isEof() const
{
    return d_type == EOF_TK;
} 

inline bool Token::isType() const
{
    return d_type == INT || d_type == FLOAT || d_type == BOOL || d_type == CHAR;
}

inline bool Token::isAddOp() const
{
    return d_type == ADD || d_type == SUB || d_type == OR;
}

inline bool Token::isMulOp() const
{
    return d_type == MUL || d_type == DIV || d_type == AND;
}

inline bool Token::isUnaryOp() const
{
    return d_type == SUB || d_type == NOT;
}

inline bool Token::isLiteral() const
{
    return d_type == INT_LIT || d_type == FLOAT_LIT || d_type == CHAR_LIT 
                    || d_type == TRUE  || d_type == FALSE;
}

#endif