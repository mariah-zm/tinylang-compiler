cmake_minimum_required(VERSION 3.16)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++20")

project(tinylang)

set(AST_SOURCE 
        src/ast/astprogramnode.cc
        src/ast/statements/astassignmentnode.cc
        src/ast/statements/astblocknode.cc
        src/ast/statements/astforstmtnode.cc
        src/ast/statements/astfunctionnode.cc
        src/ast/statements/astfunctionprototypenode.cc
        src/ast/statements/astifstmtnode.cc
        src/ast/statements/astprintstmtnode.cc
        src/ast/statements/astreturnstmtnode.cc
        src/ast/statements/astvardeclnode.cc
        src/ast/statements/astwhilestmtnode.cc
        src/ast/expressions/astbinaryopnode.cc
        src/ast/expressions/astfunctioncallnode.cc
        src/ast/expressions/astidentifiernode.cc
        src/ast/expressions/astunarynode.cc
        src/ast/literals/astboolliteralnode.cc
        src/ast/literals/astcharliteralnode.cc
        src/ast/literals/astfloatliteralnode.cc
        src/ast/literals/astintliteralnode.cc)

set(LITERAL_SOURCE 
        src/literal/literal.cc
        src/literal/istrue.cc
        src/literal/opadd.cc
        src/literal/opand.cc
        src/literal/opdiv.cc
        src/literal/opet.cc
        src/literal/opgt.cc
        src/literal/opgte.cc
        src/literal/opmul.cc
        src/literal/opnegate.cc
        src/literal/opnet.cc
        src/literal/opnot.cc
        src/literal/opor.cc
        src/literal/opst.cc
        src/literal/opste.cc
        src/literal/opstream.cc
        src/literal/opsub.cc)


set(LEXER_SOURCE 
        src/lexer/lexer.cc
        src/lexer/getinputtype.cc
        src/lexer/getnexttoken.cc
        src/lexer/gettokentype.cc
        src/lexer/trimcurrentline.cc)

set(PARSER_SOURCE 
        src/parser/getnexttoken.cc
        src/parser/parse.cc
        src/parser/parseassignment.cc
        src/parser/parseblock.cc
        src/parser/parseexpr.cc
        src/parser/parsefactor.cc
        src/parser/parsefor.cc
        src/parser/parsefunctioncall.cc
        src/parser/parsefunctiondef.cc
        src/parser/parsefunctionprototype.cc
        src/parser/parseif.cc
        src/parser/parseliteral.cc
        src/parser/parseprint.cc
        src/parser/parsereturn.cc
        src/parser/parsesemicolon.cc
        src/parser/parsesimpleexpr.cc
        src/parser/parsestatement.cc
        src/parser/parseterm.cc
        src/parser/parsevardecl.cc
        src/parser/parsewhile.cc)

set(SYMBOL_TABLE_SOURCE 
        src/symboltable/addfunction.cc
        src/symboltable/addidentifier.cc
        src/symboltable/addidentifiertype.cc
        src/symboltable/findfndef.cc
        src/symboltable/findidentifier.cc
        src/symboltable/updateidentifier.cc)

set(TOKEN_SOURCE 
        src/token/token.cc
        src/token/isrelop.cc)

set(TYPE_SOURCE 
        src/type/type.cc
        src/type/opstream.cc)

set(XML_VISITOR_SOURCE 
        src/visitor/xmlvisitor/visitassignment.cc
        src/visitor/xmlvisitor/visitbinaryop.cc
        src/visitor/xmlvisitor/visitblock.cc
        src/visitor/xmlvisitor/visitbool.cc
        src/visitor/xmlvisitor/visitchar.cc
        src/visitor/xmlvisitor/visitdecl.cc
        src/visitor/xmlvisitor/visitfloat.cc
        src/visitor/xmlvisitor/visitfor.cc
        src/visitor/xmlvisitor/visitfunction.cc
        src/visitor/xmlvisitor/visitfunctioncall.cc
        src/visitor/xmlvisitor/visitfunctionprot.cc
        src/visitor/xmlvisitor/visitid.cc
        src/visitor/xmlvisitor/visitif.cc
        src/visitor/xmlvisitor/visitint.cc
        src/visitor/xmlvisitor/visitprint.cc
        src/visitor/xmlvisitor/visitprogram.cc
        src/visitor/xmlvisitor/visitreturn.cc
        src/visitor/xmlvisitor/visitunary.cc
        src/visitor/xmlvisitor/visitwhile.cc
        src/visitor/xmlvisitor/xmlvisitor.cc)

set(SEMANTIC_VISITOR_SOURCE 
        src/visitor/semanticvisitor/validatetypebinaryop.cc
        src/visitor/semanticvisitor/validatetypeunaryop.cc
        src/visitor/semanticvisitor/visitassignment.cc
        src/visitor/semanticvisitor/visitbinaryop.cc
        src/visitor/semanticvisitor/visitblock.cc
        src/visitor/semanticvisitor/visitbool.cc
        src/visitor/semanticvisitor/visitchar.cc
        src/visitor/semanticvisitor/visitdecl.cc
        src/visitor/semanticvisitor/visitfloat.cc
        src/visitor/semanticvisitor/visitfor.cc
        src/visitor/semanticvisitor/visitfunction.cc
        src/visitor/semanticvisitor/visitfunctioncall.cc
        src/visitor/semanticvisitor/visitfunctionprot.cc
        src/visitor/semanticvisitor/visitid.cc
        src/visitor/semanticvisitor/visitif.cc
        src/visitor/semanticvisitor/visitint.cc
        src/visitor/semanticvisitor/visitprint.cc
        src/visitor/semanticvisitor/visitprogram.cc
        src/visitor/semanticvisitor/visitreturn.cc
        src/visitor/semanticvisitor/visitunary.cc
        src/visitor/semanticvisitor/visitwhile.cc)

set(INTERPRETER_VISITOR_SOURCE
        src/visitor/interpretervisitor/visitassignment.cc
        src/visitor/interpretervisitor/visitbinaryop.cc
        src/visitor/interpretervisitor/visitblock.cc
        src/visitor/interpretervisitor/visitbool.cc
        src/visitor/interpretervisitor/visitchar.cc
        src/visitor/interpretervisitor/visitdecl.cc
        src/visitor/interpretervisitor/visitfloat.cc
        src/visitor/interpretervisitor/visitfor.cc
        src/visitor/interpretervisitor/visitfunction.cc
        src/visitor/interpretervisitor/visitfunctioncall.cc
        src/visitor/interpretervisitor/visitfunctionprot.cc
        src/visitor/interpretervisitor/visitid.cc
        src/visitor/interpretervisitor/visitif.cc
        src/visitor/interpretervisitor/visitint.cc
        src/visitor/interpretervisitor/visitprint.cc
        src/visitor/interpretervisitor/visitprogram.cc
        src/visitor/interpretervisitor/visitreturn.cc
        src/visitor/interpretervisitor/visitunary.cc
        src/visitor/interpretervisitor/visitwhile.cc)

set(SOURCE_FILES
    ${AST_SOURCE} ${LITERAL_SOURCE} ${LEXER_SOURCE} ${PARSER_SOURCE} 
    ${SYMBOL_TABLE_SOURCE} ${TOKEN_SOURCE} ${TYPE_SOURCE} ${XML_VISITOR_SOURCE} 
    ${SEMANTIC_VISITOR_SOURCE} ${INTERPRETER_VISITOR_SOURCE})

add_executable(tinylang src/main.cc ${SOURCE_FILES})