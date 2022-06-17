#include "xmlvisitor.ih"

void XmlVisitor::visit(AstFloatLiteralNode *node)
{
    string tabs = "";

    for (size_t t = 0; t < d_indent; ++t) 
        tabs.append("\t");

    d_file << tabs << "<FloatLiteral>" << node->value() << "</FloatLiteral>" 
            << endl;
}