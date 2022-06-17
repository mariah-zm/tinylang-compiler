#include "xmlvisitor.ih"

void XmlVisitor::visit(AstIfStmtNode *node)
{
    string tabs = "";

    for (size_t t = 0; t < d_indent; ++t) 
        tabs.append("\t");

    d_file << tabs << "<If>" << endl;
    ++d_indent;

    node->condition()->acceptVisitor(this);

    ++d_indent;
    d_file << tabs << "\t<IfTrue>" << endl;
    node->body()->acceptVisitor(this);
    d_file << tabs << "\t</IfTrue>" << endl;

    AstBlockNode *elseBody = node->elseBody();

    if (elseBody != nullptr)
    {
        d_file << tabs << "\t<IfFalse>" << endl;
        elseBody->acceptVisitor(this);
        d_file << tabs << "\t</IfFalse>" << endl;
    }

    d_indent -= 2;

    d_file << tabs << "</If>" << endl;
}