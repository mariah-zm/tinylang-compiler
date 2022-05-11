#include "lexer.ih"

std::string Lexer::getNextLine()
{
    string line;
    bool isComment = false;
    
    do
    {    
        getline(d_programFile, line);
        trimLine(&line);

        if (line.rfind("//", 0) == 0
            || line.rfind("/*", 0) == 0)
            isComment = true;
        else if (isComment && line.rfind("*", 0) == 0)
            isComment = true;
        else if (isComment && line.rfind("*/", 0) == 0)
            isComment = true;
        else
            isComment = false;
    } while (isComment);

    return line;
}