#ifndef INCLUDED_ASTFORSTMTNODE_
#define INCLUDED_ASTFORSTMTNODE_

#include "../expressions/astexprnode.h"
#include "astblocknode.h"
#include "astassignmentnode.h"
#include "astvardeclnode.h"

// Forward-declaration due to cyclic dependency
class Visitor;

class AstForStmtNode: public AstStatementNode
{
    AstVarDeclNode *d_init;
    AstExprNode *d_condition;
    AstAssignmentNode *d_update;
    AstBlockNode *d_body;

    public:
        AstForStmtNode(size_t lineNumber, AstVarDeclNode *init, 
                        AstExprNode *condition, AstAssignmentNode *update, 
                        AstBlockNode *body);
        virtual ~AstForStmtNode();

        virtual void acceptVisitor(Visitor *vis);

        // Getters
        AstVarDeclNode *init();
        AstExprNode *condition();
        AstAssignmentNode *update();
        AstBlockNode *body();
};

inline AstForStmtNode::~AstForStmtNode()
{
    delete d_init;
    delete d_condition;
    delete d_update;
    delete d_body;
}

inline AstForStmtNode::AstForStmtNode(size_t lineNumber,
                                        AstVarDeclNode *init, 
                                        AstExprNode *condition, 
                                        AstAssignmentNode *update,
                                        AstBlockNode *body)
:
    AstStatementNode(lineNumber),
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