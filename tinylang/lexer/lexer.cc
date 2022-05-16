#include "lexer.ih"

Lexer::Lexer(string fileName)
{
    d_programFile.open(fileName);       // open program file

    // If file couldn't be opened
    if (!d_programFile) 
        throw lexical_error(string("lexer couldn't be initialised. Failed to open file ") + fileName);
}