#ifndef INCLUDED_ASTIFSTMTNODE_
#define INCLUDED_ASTIFSTMTNODE_

#include "aststatementnode.h"
#include "../expressions/astexprnode.h"
#include "astblocknode.h"
#include "../../visitor/visitor.h"

class AstIfStmtNode: public AstStatementNode
{
    AstExprNode *d_condition;
    AstBlockNode *d_body;
    AstBlockNode *d_elseBody = nullptr;

    public:
        AstIfStmtNode(AstExprNode *condition, AstBlockNode *body);
        AstIfStmtNode(AstExprNode *condition, AstBlockNode *body, 
                        AstBlockNode *elseBody);
        virtual ~AstIfStmtNode() = default;

        virtual void acceptVisitor(Visitor *vis);

        // Getters
        AstExprNode *condition();
        AstBlockNode *body();
        AstBlockNode *elseBody();
};

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