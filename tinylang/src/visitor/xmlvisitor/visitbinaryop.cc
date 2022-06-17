#include "xmlvisitor.ih"

void XmlVisitor::visit(AstBinaryOpNode *node)
{
    string tabs = "";

    for (size_t t = 0; t < d_indent; ++t) 
        tabs.append("\t");

    d_file << tabs << "<BinExpr Op=\"" << node->value() << "\">" << endl;
    
    ++d_indent;
    node->left()->acceptVisitor(this);
    node->right()->acceptVisitor(this);
    --d_indent;

    d_file << tabs << "</BinExpr>" << endl;
}