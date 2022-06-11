#ifndef INCLUDED_SYMBOLTABLE_
#define INCLUDED_SYMBOLTABLE_

#include "../type/type.h"

#include <string>
#include <vector>
#include <stack>
#include <map>

class SymbolTable
{
    class Identifier;
    class FunctionIdentifier;
    class VariableIdentifer;

    typedef std::map<std::string, Identifier> scope_t;

    class Identfier
    {
        
    };

    private:
        std::stack<scope_t> d_scopeStack;    
        scope_t d_globalScope;

    public:
        SymbolTable() = default;
        void openScope(std::string fnName);     // push
        void addIdentifier(std::string &fnName, Identifier &Identifier);
        void endScope();                        // pop 
        bool isInScope(std::string identifierName);

};

#endif