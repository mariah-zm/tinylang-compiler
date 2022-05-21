#ifndef INCLUDED_ASTPROGRAMNODE_
#define INCLUDED_ASTPROGRAMNODE_

#include "astnode.h"
#include "aststatementnode.h"

#include <vector>

class AstProgramNode: public AstNode
{
    std::vector<AstStatementNode *> d_childNodes;

    public:
        AstProgramNode();
        virtual ~AstProgramNode() = default;

        void addStatementChild(AstStatementNode *statement);

};

inline void AstProgramNode::addStatementChild(AstStatementNode *statement)
{
    d_childNodes.push_back(statement);
}

#endif