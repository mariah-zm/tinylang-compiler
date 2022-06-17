#include "xmlvisitor.ih"

void XmlVisitor::visit(AstForStmtNode *node)
{
    string tabs = "";

    for (int t = 0; t < d_indent; ++t) 
        tabs.append("\t");

    d_file << tabs << "<ForLoop>" << endl;
    ++d_indent;

    // Var decl is optional in grammar
    if (node->init() != nullptr)
        node->init()->acceptVisitor(this);

    node->condition()->acceptVisitor(this);

    // Assignment is optional in grammar
    if (node->update() != nullptr)
        node->update()->acceptVisitor(this);

    node->body()->acceptVisitor(this);

    --d_indent;
    d_file << tabs << "</ForLoop>" << endl;
}