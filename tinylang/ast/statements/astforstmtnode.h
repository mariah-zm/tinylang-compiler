#ifndef INCLUDED_ASTFORSTMTNODE_
#define INCLUDED_ASTFORSTMTNODE_

#include "aststatementnode.h"
#include "../expressions/astexprnode.h"
#include "astblocknode.h"
#include "astassignmentnode.h"
#include "astvardeclnode.h"

class AstForStmtNode: public AstStatementNode
{
    AstVarDeclNode *d_varDecl = nullptr;
    AstExprNode *d_condition;
    AstAssignmentNode *d_assignment = nullptr;
    AstBlockNode *d_body;

    public:
        AstForStmtNode(AstExprNode *condition, AstBlockNode *body);
        AstForStmtNode(AstVarDeclNode *varDecl, AstExprNode *condition, 
                        AstBlockNode *body);
        AstForStmtNode(AstExprNode *condition, AstBlockNode *body, 
                        AstAssignmentNode *assignment);
        AstForStmtNode(AstVarDeclNode *varDecl, AstExprNode *condition, 
                        AstBlockNode *body, AstAssignmentNode *assignment);
        virtual ~AstForStmtNode() = default;
};

inline AstForStmtNode::AstForStmtNode(AstExprNode *condition, AstBlockNode *body)
:
    d_condition(condition),
    d_body(body)
{}

inline AstForStmtNode::AstForStmtNode(AstVarDeclNode *varDecl, 
                                        AstExprNode *condition, 
                                        AstBlockNode *body)
:
    d_varDecl(varDecl),
    d_condition(condition),
    d_body(body)
{}

inline AstForStmtNode::AstForStmtNode(AstExprNode *condition, 
                                        AstBlockNode *body,
                                        AstAssignmentNode *assignment)
:
    d_condition(condition),
    d_body(body),
    d_assignment(assignment)
{}

inline AstForStmtNode::AstForStmtNode(AstVarDeclNode *varDecl, 
                                        AstExprNode *condition, 
                                        AstBlockNode *body, 
                                        AstAssignmentNode *assignment)
:
    d_varDecl(varDecl), 
    d_condition(condition),
    d_body(body),
    d_assignment(assignment)
{}

#endif