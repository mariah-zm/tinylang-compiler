#include "xmlvisitor.ih"

void XmlVisitor::visit(AstFunctionCallNode *node)
{
    string tabs = "";

    for (size_t t = 0; t < d_indent; ++t) 
        tabs.append("\t");

    d_file << tabs << "<FunctionCall Name=\"" << node->fnName() << "\">" << endl;
    ++d_indent;

    for (auto arg : node->args())
        arg->acceptVisitor(this);
    
    --d_indent;
    d_file << tabs << "</FunctionCall>" << endl;
}