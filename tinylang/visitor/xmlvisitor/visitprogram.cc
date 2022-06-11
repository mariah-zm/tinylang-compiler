#include "xmlvisitor.ih"

void XmlVisitor::visit(AstProgramNode *node)
{
    d_file << "<Program>" << endl;
    ++d_indent;
    
    for (auto stmt: node->statements())
        stmt->acceptVisitor(this);

    --d_indent;
    d_file << "</Program>" << endl;
}