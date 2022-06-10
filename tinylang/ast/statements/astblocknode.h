#ifndef INCLUDED_ASTBLOCKNODE_
#define INCLUDED_ASTBLOCKNODE_

#include <vector>

#include "aststatementnode.h"

// Forward-declaration due to cyclic dependency
class Visitor;

class AstBlockNode: public AstStatementNode
{
    std::vector<AstStatementNode *> d_statements;

    public:
        AstBlockNode() = default;
        virtual ~AstBlockNode();

        void addStatementChild(AstStatementNode *statement);

        virtual void acceptVisitor(Visitor *vis);
};

inline AstBlockNode::~AstBlockNode() = default;

inline void AstBlockNode::addStatementChild(AstStatementNode *statement)
{
    d_statements.push_back(statement);
}

#endif