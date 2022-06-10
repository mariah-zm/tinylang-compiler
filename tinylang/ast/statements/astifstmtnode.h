#ifndef INCLUDED_ASTIFSTMTNODE_
#define INCLUDED_ASTIFSTMTNODE_

#include "../expressions/astexprnode.h"
#include "astblocknode.h"

// Forward-declaration due to cyclic dependency
class Visitor;

class AstIfStmtNode: public AstStatementNode
{
    AstExprNode *d_condition;
    AstBlockNode *d_body;
    AstBlockNode *d_elseBody = nullptr;

    public:
        AstIfStmtNode(AstExprNode *condition, AstBlockNode *body);
        AstIfStmtNode(AstExprNode *condition, AstBlockNode *body, 
                        AstBlockNode *elseBody);
        virtual ~AstIfStmtNode();

        virtual void acceptVisitor(Visitor *vis);

        // Getters
        AstExprNode *condition();
        AstBlockNode *body();
        AstBlockNode *elseBody();
};

inline AstIfStmtNode::~AstIfStmtNode() = default;

inline AstIfStmtNode::AstIfStmtNode(AstExprNode *condition, AstBlockNode *body)
:
    d_condition(condition),
    d_body(body)
{}

inline AstIfStmtNode::AstIfStmtNode(AstExprNode *condition, AstBlockNode *body,
                                    AstBlockNode *elseBody)
:
    d_condition(condition),
    d_body(body),
    d_elseBody(elseBody)
{}

inline AstExprNode *AstIfStmtNode::condition()
{
    return d_condition;
}

inline AstBlockNode *AstIfStmtNode::body()
{
    return d_body;
}

inline AstBlockNode *AstIfStmtNode::elseBody()
{
    return d_elseBody;
}

#endif