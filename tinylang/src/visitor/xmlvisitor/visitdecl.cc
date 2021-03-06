#include "xmlvisitor.ih"

void XmlVisitor::visit(AstVarDeclNode *node)
{
    string tabs = "";

    for (size_t t = 0; t < d_indent; ++t) 
        tabs.append("\t");

    d_file << tabs << "<VarDecl>" << endl;
    d_file << tabs << "\t<Id Type=\"" << node->type()
        << "\">" << node->left()->name() << "</Id>" << endl;

    ++d_indent;
    node->right()->acceptVisitor(this);
    --d_indent;

    d_file << tabs << "</VarDecl>" << endl;
}