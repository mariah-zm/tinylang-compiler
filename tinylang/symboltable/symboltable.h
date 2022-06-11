#ifndef INCLUDED_SYMBOLTABLE_
#define INCLUDED_SYMBOLTABLE_

#include "../type/type.h"
#include "../ast/statements/astfunctionprototypenode.h"

#include <string>
#include <vector>
#include <stack>
#include <map>

class SymbolTable
{
    typedef std::map<std::string, AstFunctionPrototypeNode *> function_t;
    typedef std::map<std::string, Type> scope_t;

    std::vector<scope_t> d_scopeStack;      // to be implemented as stack
    function_t d_declaredFunctions;

    public:
        SymbolTable();

        void openScope();          // push
        void closeScope();         // pop 

        bool addIdentifier(std::string name, Type type);
        bool addFunction(AstFunctionPrototypeNode *fn);

        Type getIdentifierType(std::string identifierName);
        AstFunctionPrototypeNode *getFnDef(std::string fnName);
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