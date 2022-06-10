#include "xmlvisitor.ih"

void XmlVisitor::visit(AstIdentifierNode *node)
{
    string tabs = "";

    for (int t = 0; t < d_indent; ++t) 
        tabs.append("\t");

    d_file << tabs << "<Id>" << node->name() << "</Id>";
}