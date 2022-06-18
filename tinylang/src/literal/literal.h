 #ifndef INCLUDED_LITERAL_
 #define INCLUDED_LITERAL_

 #include <ostream>

 #include "../type/type.h"

class Literal
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
        Literal() = default;
        Literal(Literal const &other); // copy constructor
        Literal(Type type);
        Literal(int val);
        Literal(float val);
        Literal(char val);
        Literal(bool val);
        Literal(Type type, Value value);

        // Getter for d_type
        Type type() const;
        bool isTrue() const;

        // Output Operator
        friend std::ostream &operator<<(std::ostream &out, Literal const &iden);

        // Binary Operators
        friend Literal operator+(Literal const &left, Literal const &right);
        friend Literal operator-(Literal const &left, Literal const &right);
        friend Literal operator*(Literal const &left, Literal const &right);
        friend Literal operator/(Literal const &left, Literal const &right);

        // Unary Operators
        friend bool operator!(Literal const &iden);
        friend Literal operator-(Literal const &iden);

        // Relational Operators
        friend bool operator>(Literal const &left, Literal const &right);
        friend bool operator<(Literal const &left, Literal const &right);
        friend bool operator>=(Literal const &left, Literal const &right);
        friend bool operator<=(Literal const &left, Literal const &right);
        friend bool operator==(Literal const &left, Literal const &right);
        friend bool operator!=(Literal const &left, Literal const &right);

        // Logical Operators
        bool andOp(Literal const &other);
        bool orOp(Literal const &other);

};

inline Literal::Literal(Type type)
:
    d_type(type)
{}

inline Literal::Literal(int val)
:
    d_type(Type::INT)
{
    d_val.intVal = val;
}

inline Literal::Literal(float val)
:
    d_type(Type::FLOAT)
{
    d_val.floatVal = val;
}

inline Literal::Literal(char val)
:
    d_type(Type::CHAR)
{
    d_val.charVal = val;
}

inline Literal::Literal(bool val)
:
    d_type(Type::BOOL)
{
    d_val.boolVal = val;
}

inline Literal::Literal(Type type, Literal::Value value)
:
    d_type(type),
    d_val(value)
{}

inline Type Literal::type() const
{
    return d_type;
}

 #endif