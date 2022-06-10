#include "xmlvisitor.ih"

void XmlVisitor::visit(AstBlockNode *node)
{
    string tabs = "";

    for (int t = 0; t < d_indent; ++t) 
        tabs.append("\t");

    d_file << tabs << "<Block>" << endl;
    ++d_indent;
    node->acceptVisitor(this);
    --d_indent;
    d_file << tabs << "</Block>" << endl;
}