#include "xmlvisitor.ih"

void XmlVisitor::visit(AstFunctionNode *node)
{
    string tabs = "";

    for (int t = 0; t < d_indent; ++t) 
        tabs.append("\t");

    Identifier::Type retType = node->prototype()->returnType();

    d_file << tabs << "<FunctionDecl Name=\"" << node->prototype()->name() 
            << "\" ReturnType=\"" << Identifier::typeToString(retType)
                << "\">" << endl;

    ++d_indent;
    node->prototype()->acceptVisitor(this);
    node->body()->acceptVisitor(this);
    --d_indent;

    d_file << tabs << "</FunctionDecl>" << endl;
}