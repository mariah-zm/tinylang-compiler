#ifndef INCLUDED_ASTIFSTMTNODE_
#define INCLUDED_ASTIFSTMTNODE_

#include "aststatementnode.h"
#include "../expressions/astexprnode.h"
#include "astblocknode.h"

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

#endif