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
    public:
        struct Identifier
        {
            union Value
            {
                int intVal;
                float floatVal;
                char charVal;
                bool boolVal;
            };

            Type d_type;
            Value d_val;
        };

    private:
        typedef std::map<std::string, AstFunctionPrototypeNode *> function_t;
        typedef std::map<std::string, Identifier> scope_t;

        std::vector<scope_t> d_scopeStack;      // to be implemented as stack
        function_t d_declaredFunctions;

    public:
        SymbolTable();

        void openScope();          // push
        void closeScope();         // pop 

        bool addIdentifier(std::string name, Type type);
        bool addFunction(AstFunctionPrototypeNode *fn);

        Identifier *findIdentifier(std::string idenName);
        AstFunctionPrototypeNode *findFnDef(std::string fnName);
        void updateIdentifier(std::string idenName, float newVal);
        void updateIdentifier(std::string idenName, int newVal);
        void updateIdentifier(std::string idenName, char newVal);
        void updateIdentifier(std::string idenName, bool newVal);

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