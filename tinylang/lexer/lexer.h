#ifndef INCLUDED_LEXER_
#define INCLUDED_LEXER_

#include "../token/token.h"

#include <fstream>
#include <set>
#include <stack>

class Lexer
{
    struct TransitionTable
    {
        enum State
        {
            S0,     // Start
            S1,     // Integer
            S2,     // Float
            S3,     // Identifier
            S4,     // 
            S5,     // String
            S6,     // MulOp [ * / ]
            S7,     // AddOp [ + - ]
            S8,     // RelOp [ < > != == <= >= ]
            S9,     // Punctuation [ , ( ) ; : { } ]
            Serr    // error state
        };

        State d_starting = S0;
        State d_transitions[11][4] = { //  DIGIT  DOT   LETTER  UNDSCR  PRINT
                                /*S0*/   { S1,   S2,   S3,     S3   },
                                /*S1*/   { S1,   S2,   Serr,   Serr },
                                /*S2*/   { S2,   Serr, Serr,   Serr },
                                /*S3*/   { S3,   Serr, S3,     S3   },
                                /*Serr*/ { Serr, Serr, Serr,   Serr }};

        std::set<State> d_accepting = {S1, S2};
    };

    TransitionTable d_transitions = TransitionTable{};
    std::stack<char> d_tokenStack;

    std::ifstream d_programFile;

    public:
        Lexer(std::string fileName);

        Token getNextToken();

};

#endif