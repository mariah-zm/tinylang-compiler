#include "lexer.ih"

void Lexer::trimCurrentLine()
{
    // Removign whitespaces from beginning of line
    size_t strBegin = d_currentLine.find_first_not_of(" \t");
    if (strBegin != string::npos)
    {
        d_currentLine = d_currentLine.substr(strBegin);
    }
}