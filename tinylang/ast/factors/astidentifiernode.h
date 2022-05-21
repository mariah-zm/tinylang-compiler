#ifndef INCLUDED_ASTIDENTIFIERNODE_
#define INCLUDED_ASTIDENTIFIERNODE_

#include "astfactornode.h"
#include "../identifier/identifier.h"

class AstIdentifierNode: public AstFactorNode
{
    Identifier d_iden;

    public:
        AstIdentifierNode(Identifier iden);
        virtual ~AstIdentifierNode() = default;

        Identifier const &value() const;
};

inline AstIdentifierNode::AstIdentifierNode(Identifier iden)
:
    d_iden(iden)
{}

inline Identifier const &AstIdentifierNode::value() const
{
    return d_iden;
}

#endif