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
    Parser parser = Parser{&lexer};
    parser.parse();
}
catch (lexical_error &ex)
{
    cerr << "LEXICAL ERR: " << ex.what() << endl;
}
catch (syntax_error &ex)
{
    cerr << "SYNTAX ERR: " << ex.what() << endl;
}