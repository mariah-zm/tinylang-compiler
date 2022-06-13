 #ifndef INCLUDED_IDENTIFIER_
 #define INCLUDED_IDENTIFIER_

 #include <ostream>

 #include "../type/type.h"

class Identifier
{
    union Value
    {
        int intVal;
        float floatVal;
        char charVal;
        bool boolVal;
    };
    
    Type d_type;
    Value d_val;

    public: 
        Identifier() = default;
        Identifier(Identifier const &other); // copy constructor
        Identifier(Type type);
        Identifier(int val);
        Identifier(float val);
        Identifier(char val);
        Identifier(bool val);
        Identifier(Type type, Value value);

        // Getter for d_type
        Type type() const;
        bool isTrue() const;

        // Output Operator
        friend std::ostream &operator<<(std::ostream &out, Identifier const &iden);

        // Binary Operators
        friend Identifier operator+(Identifier const &left, Identifier const &right);
        friend Identifier operator-(Identifier const &left, Identifier const &right);
        friend Identifier operator*(Identifier const &left, Identifier const &right);
        friend Identifier operator/(Identifier const &left, Identifier const &right);

        // Unary Operators
        friend bool operator!(Identifier const &iden);
        friend Identifier operator-(Identifier const &iden);

        // Relational Operators
        friend bool operator>(Identifier const &left, Identifier const &right);
        friend bool operator<(Identifier const &left, Identifier const &right);
        friend bool operator>=(Identifier const &left, Identifier const &right);
        friend bool operator<=(Identifier const &left, Identifier const &right);
        friend bool operator==(Identifier const &left, Identifier const &right);
        friend bool operator!=(Identifier const &left, Identifier const &right);

        // Logical Operators
        bool andOp(Identifier const &other);
        bool orOp(Identifier const &other);

};

inline Identifier::Identifier(Type type)
:
    d_type(type)
{}

inline Identifier::Identifier(int val)
:
    d_type(Type::INT)
{
    d_val.intVal = val;
}

inline Identifier::Identifier(float val)
:
    d_type(Type::FLOAT)
{
    d_val.floatVal = val;
}

inline Identifier::Identifier(char val)
:
    d_type(Type::CHAR)
{
    d_val.charVal = val;
}

inline Identifier::Identifier(bool val)
:
    d_type(Type::BOOL)
{
    d_val.boolVal = val;
}

inline Identifier::Identifier(Type type, Identifier::Value value)
:
    d_type(type),
    d_val(value)
{}

inline Type Identifier::type() const
{
    return d_type;
}

 #endif