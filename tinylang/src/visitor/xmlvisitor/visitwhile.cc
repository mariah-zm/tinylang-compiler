#include "xmlvisitor.ih"

void XmlVisitor::visit(AstWhileStmtNode *node)
{
    string tabs = "";

    for (int t = 0; t < d_indent; ++t) 
        tabs.append("\t");

    d_file << tabs << "<While>" << endl;

    d_indent += 2;

    d_file << tabs << "\t<Condition>" << endl;
    node->condition()->acceptVisitor(this);
    d_file << tabs << "\t</Condition>" << endl;

    d_file << tabs << "\t<Body>" << endl;
    node->body()->acceptVisitor(this);
    d_file << tabs << "\t</Body>" << endl;

    d_indent -= 2;

    d_file << tabs << "</While>" << endl;
}