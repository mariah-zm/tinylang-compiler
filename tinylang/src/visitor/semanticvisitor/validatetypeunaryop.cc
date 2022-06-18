#include "semanticvisitor.ih"

void SemanticVisitor::validateTypeOp(AstUnaryNode *node) const
{
    switch (d_typeToMatch.type())
    {
        case Type::INT:
        {
            if (node->value() == "not")
                throw semantic_error("cannot use type 'int' with operation \'"
                    + node->value() + "\' in line " + to_string(node->lineNumber()));
            break;
        }
        case Type::FLOAT:
        {
            if (node->value() == "not")
                throw semantic_error("cannot use type 'float' with operation \'"
                    + node->value() + "\' in line " + to_string(node->lineNumber()));
            break;
        }
        case Type::BOOL:
        {
            if (node->value() == "-")
                throw semantic_error("cannot use type 'bool' with operation "
                    + node->value() + " in line " + to_string(node->lineNumber()));
            break;
        }
        case Type::CHAR:
        {
            throw semantic_error("cannot use type 'char' with operation "
                + node->value() + " in line " + to_string(node->lineNumber()));
            break;
        }
        default: ; // default case required for no warnings
    }
}