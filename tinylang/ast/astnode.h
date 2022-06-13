#ifndef INCLUDED_ASTNODE_
#define INCLUDED_ASTNODE_

#include <cstddef>

// Forward-declaration due to cyclic dependency
class Visitor;

class AstNode
{
    size_t d_lineNumber;

    public:
        AstNode() = default;
        AstNode(size_t lineNum);
        virtual ~AstNode() = default;

        virtual void acceptVisitor(Visitor *vis) = 0;

        size_t lineNumber() const;

};

inline size_t AstNode::lineNumber() const
{
    return d_lineNumber;
}

inline AstNode::AstNode(size_t lineNum)
:
    d_lineNumber(lineNum)
{}

#endif