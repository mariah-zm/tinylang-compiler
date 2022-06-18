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

    // Parsing ----------------------------------------------------------------

    Lexer lexer = Lexer{fileName};
    Parser parser = Parser{&lexer};
    AstProgramNode *program = parser.parse();

    // XML Generation ----------------------------------------------------------

    XmlVisitor xmlVis = XmlVisitor{fileName};
    program->acceptVisitor(&xmlVis);
    cout << "XML Generated written to: " << xmlVis.fileName() << endl;
    xmlVis.close();

    cout << "\n..............................\n" << endl;

    // Semantic Analysis -------------------------------------------------------

    SemanticVisitor semVis = SemanticVisitor{};
    program->acceptVisitor(&semVis);

    // Interpreter Pass --------------------------------------------------------

    InterpreterVisitor intVis = InterpreterVisitor{};
    program->acceptVisitor(&intVis);

    // Deallocating memory allocated to the nodes in the AST
    delete program;
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