#include "xmlvisitor.ih"

void XmlVisitor::visit(AstReturnStmtNode *node)
{
    string tabs = "";

    for (int t = 0; t < d_indent; ++t) 
        tabs.append("\t");

    d_file << tabs << "<Return>" << endl;

    ++d_indent;
    node->expr()->acceptVisitor(this);
    --d_indent;

    d_file << tabs << "</Return>" << endl;
}