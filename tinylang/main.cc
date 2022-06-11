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

    cout << "\nBegin XML Generation..." << endl;
    XmlVisitor xmlVis = XmlVisitor{fileName};
    program->acceptVisitor(&xmlVis);
    cout << "XML Generation Complete. Written to: " << xmlVis.fileName() << endl;
    xmlVis.close();

    cout << "\nBegin Semantic Analysis..." << endl;
    SymbolTable symbolTable = SymbolTable{};
    SemanticVisitor semVis = SemanticVisitor{symbolTable};
    program->acceptVisitor(&semVis);
    cout << "Semantic Analysis Complete." << endl;
}
catch (lexical_error &ex)
{
    cerr << "LEXICAL ERR: " << ex.what() << endl;
}
catch (syntax_error &ex)
{
    cerr << "SYNTAX ERR: " << ex.what() << endl;
}
catch (semantic_error &ex)
{
    cerr << "SEMANTIC ERR: " << ex.what() << endl;
}
catch (runtime_error &ex)
{
    cerr << "ERR: " << ex.what() << endl;
}