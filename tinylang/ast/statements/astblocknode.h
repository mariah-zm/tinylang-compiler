#ifndef INCLUDED_ASTBLOCKNODE_
#define INCLUDED_ASTBLOCKNODE_

#include "aststatementnode.h"

#include <vector>

class AstBlockNode: public AstStatementNode
{
    std::vector<AstStatementNode *> d_statements;

    public:
        AstBlockNode() = default;
        virtual ~AstBlockNode() = default;

        void addStatementChild(AstStatementNode *statement);
};

inline void AstBlockNode::addStatementChild(AstStatementNode *statement)
{
    d_statements.push_back(statement);
}

#endif