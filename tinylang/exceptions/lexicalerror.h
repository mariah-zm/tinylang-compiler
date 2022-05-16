#ifndef INCLUDED_LEXICALERROR_
#define INCLUDED_LEXICALERROR_

#include <exception>
#include <string>

class lexical_error: virtual public std::exception
{
    protected:
        std::string error_message;      ///< Error message
    
    public:
        lexical_error(std::string const &msg);
        virtual const char* what() const throw ();

};

inline lexical_error::lexical_error(std::string const &msg)
:
    error_message(msg)
{}

inline const char* lexical_error::what() const throw ()
{
    return error_message.c_str();
}

#endif