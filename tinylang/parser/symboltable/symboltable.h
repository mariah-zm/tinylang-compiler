#ifndef INCLUDED_SYMBOLTABLE_
#define INCLUDED_SYMBOLTABLE_

#include "../identifier/identifier.h"

#include <string>
#include <vector>
#include <stack>

class SymbolTable
{
    private:
        struct Scope 
        {
            std::string d_fnName;
            std::vector<Identifier> d_identifiers;
        };

        std::stack<Scope> d_scopeStack;
        Scope d_globalScope;

    public:
        SymbolTable();
        void openScope(std::string fnName);
        void addIdentifier(std::string &fnName, Identifier &Identifier);
        void endScope();
        bool isInScope(std::string identifierName);

};

inline SymbolTable::SymbolTable()
{
    d_globalScope.d_fnName = "global";
}

#endif