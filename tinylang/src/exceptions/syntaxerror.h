#ifndef INCLUDED_SYNTAXERROR_
#define INCLUDED_SYNTAXERROR_

#include <exception>
#include <string>

class syntax_error: virtual public std::exception
{
    protected:
        std::string error_message;
    
    public:
        syntax_error(std::string const &msg);
        virtual const char* what() const throw ();

};

inline syntax_error::syntax_error(std::string const &msg)
:
    error_message(msg)
{}

inline const char* syntax_error::what() const throw ()
{
    return error_message.c_str();
}

#endif