#include "interpretervisitor.ih"

void InterpreterVisitor::visit(AstFunctionCallNode *node)
{
    try
    {
        AstFunctionPrototypeNode *protNode 
                        = d_symbolTable.getFnDef(node->fnName());

        size_t argSize = node->args().size();
        size_t paramSize = protNode->params().size();


        // Type checking params and args
        for (size_t idx = 0; idx < argSize; ++idx)
        {
            node->args().at(idx)->acceptVisitor(this);

            Type expectedType = protNode->params().at(idx).d_type;
        }

        d_typeToMatch = protNode->returnType();
    }
    catch (out_of_range &ex)
    {
    }
}