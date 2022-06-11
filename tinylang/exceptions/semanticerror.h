#ifndef INCLUDED_SEMANTICERROR_
#define INCLUDED_SEMANTICERROR_

#include <exception>
#include <string>

class semantic_error: virtual public std::exception
{
    protected:
        std::string error_message;
    
    public:
        semantic_error(std::string const &msg);
        virtual const char* what() const throw ();

};

inline semantic_error::semantic_error(std::string const &msg)
:
    error_message(msg)
{}

inline const char* semantic_error::what() const throw ()
{
    return error_message.c_str();
}

#endif