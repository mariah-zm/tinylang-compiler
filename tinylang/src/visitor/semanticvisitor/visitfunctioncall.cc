#include "semanticvisitor.ih"

void SemanticVisitor::visit(AstFunctionCallNode *node)
{
    try
    {
        AstFunctionNode *fnNode = d_symbolTable.findFnDef(node->fnName());

        auto fnParams = fnNode->prototype()->params();
        size_t argSize = node->args().size();
        size_t paramSize = fnParams.size();

        if (argSize != paramSize)
            throw semantic_error("expected " + to_string(paramSize)
                + " arguments, but received " + to_string(argSize) + " in line "
                + to_string(node->lineNumber()));

        // Type checking params and args
        for (size_t idx = 0; idx < argSize; ++idx)
        {
            node->args().at(idx)->acceptVisitor(this);

            Type expectedType = fnParams.at(idx).d_type;

            if (d_typeToMatch != expectedType)
                throw semantic_error("type mismatch in function call in line "
                    + to_string(node->lineNumber()));
        }

        d_typeToMatch = fnNode->prototype()->returnType();
    }
    catch (out_of_range &ex)
    {
        throw semantic_error("function " + node->fnName() + " in line " 
                + to_string(node->lineNumber()) + " is not defined");
    }
}