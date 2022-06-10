#ifndef INCLUDED_ASTFORSTMTNODE_
#define INCLUDED_ASTFORSTMTNODE_

#include "aststatementnode.h"
#include "../expressions/astexprnode.h"
#include "astblocknode.h"
#include "astassignmentnode.h"
#include "astvardeclnode.h"
#include "../../visitor/visitor.h"

class AstForStmtNode: public AstStatementNode
{
    AstVarDeclNode *d_init;
    AstExprNode *d_condition;
    AstAssignmentNode *d_update;
    AstBlockNode *d_body;

    public:
        AstForStmtNode(AstVarDeclNode *init, AstExprNode *condition, 
                        AstAssignmentNode *update, AstBlockNode *body);
        virtual ~AstForStmtNode() = default;

        virtual void acceptVisitor(Visitor *vis);

        // Getters
        AstVarDeclNode *init();
        AstExprNode *condition();
        AstAssignmentNode *update();
        AstBlockNode *body();
};

inline AstForStmtNode::AstForStmtNode(AstVarDeclNode *init, 
                                        AstExprNode *condition, 
                                        AstAssignmentNode *update,
                                        AstBlockNode *body)
:
    d_init(init), 
    d_condition(condition),
    d_update(update),
    d_body(body)
{}

inline AstVarDeclNode *AstForStmtNode::init()
{
    return d_init;
}

inline AstExprNode *AstForStmtNode::condition()
{
    return d_condition;
}

inline AstAssignmentNode *AstForStmtNode::update()
{
    return d_update;
}

inline AstBlockNode *AstForStmtNode::body()
{
    return d_body;
}

#endif