#include "lexer.ih"

void Lexer::trimLine(string *str) const
{
    string whitespace = " \t\n\r";

    const auto strBegin = (*str).find_first_not_of(whitespace);

    if (strBegin != std::string::npos)
    {
        const auto strEnd = (*str).find_last_not_of(whitespace);
        const auto strRange = strEnd - strBegin + 1;

        (*str) = (*str).substr(strBegin, strRange);
    }
}