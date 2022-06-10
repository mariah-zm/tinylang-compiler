#ifndef INCLUDED_ASTPROGRAMNODE_
#define INCLUDED_ASTPROGRAMNODE_

#include <vector>

#include "astnode.h"
#include "statements/aststatementnode.h"
#include "statements/astfunctionprototypenode.h"

// Forward-declaration due to cyclic dependency
class Visitor;

class AstProgramNode: public virtual AstNode
{
    std::vector<AstStatementNode *> d_childNodes;
    std::vector<AstFunctionPrototypeNode *> d_progFunctions;

    public:
        AstProgramNode() = default;
        virtual ~AstProgramNode() = default;

        void addStatementChild(AstStatementNode *statement);
        void addFunction(AstFunctionPrototypeNode *function);

        virtual void acceptVisitor(Visitor *vis);

};

inline void AstProgramNode::addStatementChild(AstStatementNode *statement)
{
    d_childNodes.push_back(statement);
}

inline void AstProgramNode::addFunction(AstFunctionPrototypeNode *function)
{
    d_progFunctions.push_back(function);
}

#endif