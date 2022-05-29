#ifndef INCLUDED_ASTNODE_
#define INCLUDED_ASTNODE_

class AstNode
{
    public:
        AstNode() = default;
        virtual ~AstNode() = 0;

};

inline AstNode::~AstNode()
{}

#endif