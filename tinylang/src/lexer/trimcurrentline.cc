#include "lexer.ih"

void Lexer::trimCurrentLine()
{
    // Removing whitespaces from beginning and end of line
    size_t strBegin = d_currentLine.find_first_not_of(" \t");
    if (strBegin != string::npos)
    {
        size_t strEnd = d_currentLine.find_last_not_of(" \t");
        size_t strRange = strEnd - strBegin + 1;

        d_currentLine = d_currentLine.substr(strBegin, strRange);
    }

}