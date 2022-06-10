#include "xmlvisitor.ih"

void XmlVisitor::visit(AstAssignmentNode *node)
{
    string tabs = "";

    for (int t = 0; t < d_indent; ++t) 
        tabs.append("\t");

    d_file << tabs << "<Assignment>" << endl;
    d_file << tabs << "\t<Id>" << node->idenName() << "</Id>" << endl;

    ++d_indent;
    node->right()->acceptVisitor(this);
    --d_indent;

    d_file << tabs << "</Assignment>" << endl;
}