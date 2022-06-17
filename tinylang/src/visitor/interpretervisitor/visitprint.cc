#include "interpretervisitor.ih"

void InterpreterVisitor::visit(AstPrintStmtNode *node)
{
    node->expr()->acceptVisitor(this);
    cout << d_currentIden << endl;
}