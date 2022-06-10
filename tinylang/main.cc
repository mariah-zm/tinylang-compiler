#include "main.ih"

int main(int argc, char **argv)
try
{
    // File name to be provided as a program argument
    if (argc == 1)
        throw runtime_error(string("program file name not provided"));
    else if (argc > 2)
        throw runtime_error(string("too many arguments provided"));

    string fileName = argv[1];

    Lexer lexer = Lexer{fileName};

    cout << "Begin Parsing..." << endl;

    Parser parser = Parser{&lexer};
    AstProgramNode *program = parser.parse();

    cout << "Parsing Complete." << endl;

    cout << "Begin XML Generation..." << endl;

    XmlVisitor xmlVis = XmlVisitor{fileName};
    xmlVis.visit(program);

    cout << "XML Generation Complete. Written to: " << xmlVis.fileName() << endl;

    xmlVis.close();
}
catch (lexical_error &ex)
{
    cerr << "LEXICAL ERR: " << ex.what() << endl;
}
catch (syntax_error &ex)
{
    cerr << "SYNTAX ERR: " << ex.what() << endl;
}
catch (runtime_error &ex)
{
    cerr << "ERR: " << ex.what() << endl;
}