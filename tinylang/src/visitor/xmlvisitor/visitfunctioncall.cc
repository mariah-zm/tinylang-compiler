#include "xmlvisitor.ih"

void XmlVisitor::visit(AstFunctionCallNode *node)
{
    string tabs = "";

    for (int t = 0; t < d_indent; ++t) 
        tabs.append("\t");

    d_file << tabs << "<FunctionCall Name=\"" << node->fnName() << "\">" << endl;

    d_file << tabs << "\t<Args>" << endl;

    d_indent += 2;

    for (auto arg : node->args())
        arg->acceptVisitor(this);
    
    d_indent -= 2;

    d_file << tabs << "\t</Args>" << endl;
    d_file << tabs << "</FunctionCall>" << endl;
}