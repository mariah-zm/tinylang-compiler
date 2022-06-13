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

        size_t lineNumber() const;          // Getter
        void lineNumber(size_t lineNumber); // Setter

};

inline AstNode::AstNode(size_t lineNum)
:
    d_lineNumber(lineNum)
{}

inline size_t AstNode::lineNumber() const
{
    return d_lineNumber;
}

inline void AstNode::lineNumber(size_t lineNumber)
{
    d_lineNumber = lineNumber;
}

#endif