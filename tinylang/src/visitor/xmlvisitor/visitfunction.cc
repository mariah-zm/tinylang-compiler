#include "xmlvisitor.ih"

void XmlVisitor::visit(AstFunctionNode *node)
{
    string tabs = "";

    for (int t = 0; t < d_indent; ++t) 
        tabs.append("\t");

    d_file << tabs << "<FunctionDecl Name=\"" << node->prototype()->name() 
            << "\" ReturnType=\"" << node->prototype()->returnType()
                << "\">" << endl;

    ++d_indent;
    node->prototype()->acceptVisitor(this);
    node->body()->acceptVisitor(this);
    --d_indent;

    d_file << tabs << "</FunctionDecl>" << endl;
}