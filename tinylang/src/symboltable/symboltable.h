#ifndef INCLUDED_SYMBOLTABLE_
#define INCLUDED_SYMBOLTABLE_

#include "../type/type.h"
#include "../ast/statements/astfunctionnode.h"
#include "../literal/literal.h"

#include <string>
#include <vector>
#include <stack>
#include <map>

class SymbolTable
{
    private:
        typedef std::map<std::string, AstFunctionNode *> function_t;
        typedef std::map<std::string, Literal> scope_t;

        std::vector<scope_t> d_scopeStack;      // to be implemented as stack
        function_t d_declaredFunctions;

    public:
        SymbolTable();

        void openScope();          // push
        void closeScope();         // pop 

        bool addIdentifier(std::string name, Literal lit);
        bool addIdentifier(std::string name, Type type);
        bool addFunction(AstFunctionNode *fn);

        Literal *findIdentifier(std::string idenName);
        AstFunctionNode *findFnDef(std::string fnName);
        void updateIdentifier(std::string idenName, Literal newVal);

};

inline SymbolTable::SymbolTable()
{
    openScope(); // adding global scope
}

inline void SymbolTable::openScope() 
{
    d_scopeStack.push_back(scope_t{});
}

inline void SymbolTable::closeScope() 
{
    d_scopeStack.pop_back();
}

#endif