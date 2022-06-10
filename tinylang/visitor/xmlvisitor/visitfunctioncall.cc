#include "xmlvisitor.ih"

void XmlVisitor::visit(AstFunctionCallNode *node)
{
    string tabs = "";

    for (int t = 0; t < d_indent; ++t) 
        tabs.append("\t");

    d_file << tabs << "<FunctionCall Name=\"" << node->fnName() << "\">" << endl;

    d_file << tabs << "<Args>" << endl;

    for (auto arg : node->args())
        arg->acceptVisitor(this);

    d_file << tabs << "</Args>" << endl;
}