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
    std::vector<AstStatementNode *> d_statements;

    public:
        AstProgramNode() = default;
        virtual ~AstProgramNode();

        void addStatement(AstStatementNode *statement);

        virtual void acceptVisitor(Visitor *vis);

        std::vector<AstStatementNode *> &statements();

};

inline AstProgramNode::~AstProgramNode()
{
    for (auto stmt: d_statements)
        delete stmt;
}

inline void AstProgramNode::addStatement(AstStatementNode *statement)
{
    d_statements.push_back(statement);
}

inline std::vector<AstStatementNode *> &AstProgramNode::statements()
{
    return d_statements;
}

#endif