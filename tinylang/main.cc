#include "main.ih"

int main(int argc, char **argv)
try
{
    // File name to be provided as a program argument
    if (argc == 1)
        throw runtime_error(string("program file name not provided"));
    else if (argc > 2)
        throw runtime_error(string("too many arguments provided"));

    Lexer lexer = Lexer{argv[1]};
    cout << "Program file: " << argv[1] << endl;
}
catch (exception &ex)
{
    cerr << "ERR: " << ex.what() << endl;
}