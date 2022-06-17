#include "xmlvisitor.ih"

void XmlVisitor::visit(AstWhileStmtNode *node)
{
    string tabs = "";

    for (size_t t = 0; t < d_indent; ++t) 
        tabs.append("\t");

    d_file << tabs << "<While>" << endl;
    ++d_indent;

    node->condition()->acceptVisitor(this);
    node->body()->acceptVisitor(this);

    --d_indent;
    d_file << tabs << "</While>" << endl;
}