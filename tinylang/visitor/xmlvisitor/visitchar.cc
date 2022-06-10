#include "xmlvisitor.ih"

void XmlVisitor::visit(AstCharLiteralNode *node)
{
    string tabs = "";

    for (int t = 0; t < d_indent; ++t) 
        tabs.append("\t");

    d_file << tabs << "<CharLiteral>" << node->value() << "</CharLiteral>" 
            << endl;
}