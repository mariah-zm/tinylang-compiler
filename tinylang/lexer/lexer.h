#ifndef INCLUDED_LEXER_
#define INCLUDED_LEXER_

#include "../token/token.h"

#include <fstream>
#include <set>
#include <stack>

class Lexer
{
    enum InputType
    {
        DIGIT,
        DOT,
        LETTER,
        UNDSCR,
        SPACE,
        PRINT,
        OTHER
    };

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
        Serr    // Error state
    };

    struct TransitionTable
    {
        State d_starting = S0;
        State d_transitions[11][5] = { //  DIGIT  DOT    LETTER  UNDSCR  SPACE  PRINT
                                /*S0*/   { S1,    S2,    S3,     S3,     Serr },
                                /*S1*/   { S1,    S2,    Serr,   Serr,   Serr },
                                /*S2*/   { S2,    Serr,  Serr,   Serr,   Serr },
                                /*S3*/   { S3,    Serr,  S3,     S3,     Serr },
                                /*Serr*/ { Serr,  Serr,  Serr,   Serr,   Serr }};

        std::set<State> d_accepting = {S1, S2, S3};

        bool isAccepting(State state)
        {
            return d_accepting.find(state) != s_transitions.d_accepting.end();
        }
    };

    struct ValueStatePair
    {
        char d_val;
        State d_state;
    };

    static TransitionTable s_transitions;

    std::stack<ValueStatePair> d_tokenStack;
    std::ifstream d_programFile;
    std::string d_currentLine;
    State d_currentState = s_transitions.d_starting;

    public:
        Lexer(std::string fileName);

        Token getNextToken();

    private:
        Token::TokenType getTokenType(State state);
        InputType getInputType(char val) const;

};

#endif