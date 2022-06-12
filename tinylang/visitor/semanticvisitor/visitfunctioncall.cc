#include "semanticvisitor.ih"

void SemanticVisitor::visit(AstFunctionCallNode *node)
{
    try
    {
        AstFunctionPrototypeNode *protNode 
                        = d_symbolTable.getFnDef(node->fnName());

        size_t argSize = node->args().size();
        size_t paramSize = protNode->params().size();

        if (argSize != paramSize)
            throw semantic_error("expected " + to_string(paramSize)
                            + " arguments, but received " + to_string(argSize));


        // Type checking params and args
        for (size_t idx = 0; idx < argSize; ++idx)
        {
            node->args().at(idx)->acceptVisitor(this);

            Type expectedType = protNode->params().at(idx).d_type;

            if (d_typeToMatch != expectedType)
                throw semantic_error("type mismatch in function call");
        }

        d_typeToMatch = protNode->returnType();
    }
    catch (out_of_range &ex)
    {
        throw semantic_error("function " + node->fnName() + " not defined");
    }
}