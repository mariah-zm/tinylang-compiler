#include "xmlvisitor.ih"

void XmlVisitor::visit(AstBoolLiteralNode *node)
{
    string tabs = "";

    for (int t = 0; t < d_indent; ++t) 
        tabs.append("\t");

    d_file << boolalpha << tabs << "<Bool>" << node->value() << "</Bool>"
        << noboolalpha << endl;
}