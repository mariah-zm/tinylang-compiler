#include "xmlvisitor.ih"

void XmlVisitor::visit(AstFunctionPrototypeNode *node)
{
    string tabs = "";

    for (int t = 0; t < d_indent; ++t) 
        tabs.append("\t");

    d_file << tabs << "<Params>" << endl;

    for (auto param : node->params())
    {
        d_file << tabs << "\t<Param Type=\"" << param.typeAsString() << 
            "\">" << param.name() << "</Param>" << endl;
    }

    d_file << tabs << "</Params>" << endl;
}