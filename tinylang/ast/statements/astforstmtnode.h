#ifndef INCLUDED_ASTFORSTMTNODE_
#define INCLUDED_ASTFORSTMTNODE_

#include "aststatementnode.h"
#include "../expressions/astexprnode.h"
#include "astblocknode.h"
#include "astassignmentnode.h"
#include "astvardeclnode.h"

class AstForStmtNode: public AstStatementNode
{
    AstVarDeclNode *d_varDecl;
    AstExprNode *d_condition;
    AstAssignmentNode *d_assignment;
    AstBlockNode *d_body;

    public:
        AstForStmtNode(AstVarDeclNode *varDecl, AstExprNode *condition, 
                        AstAssignmentNode *assignment, AstBlockNode *body);
        virtual ~AstForStmtNode() = default;
};

inline AstForStmtNode::AstForStmtNode(AstVarDeclNode *varDecl, 
                                        AstExprNode *condition, 
                                        AstAssignmentNode *assignment,
                                        AstBlockNode *body)
:
    d_varDecl(varDecl), 
    d_condition(condition),
    d_assignment(assignment),
    d_body(body)
{}

#endif