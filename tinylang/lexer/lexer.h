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
        QUOTE,
        EQ_SIGN,
        ANGLE_B,
        EXCLM,
        PRINT,  // this includes chars which are not the above but printable
        OTHER
    };

    enum State
    {
        S0,     // Start
        S1,     // Integer
        S2,     // Float
        S3,     // Identifier
        S4,     // Open Quote
        S5,     // String
        S6,     // Close Quote - char literal
        S7,     // Assignment [ = ]
        S8,     // Exclamation Mark [ ! ]
        S9,     // RelOp [ < > ]
        S10,     // RelOp [ == <= >= != ]
        Serr    // Error state
    };

    struct TransitionTable
    {
        State d_starting = S0;
        State d_transitions[12][10] = { // DIGIT  DOT    LETTER  UNDSCR  SPACE  QUOTE  EQ_SIGN  ANGLE_B  EXCLM  PRINT
                                /*S0*/   { S1,    S2,    S3,     S3,     Serr,  S4,    S7,      S9,      S8,    Serr },
                                /*S1*/   { S1,    S2,    Serr,   Serr,   Serr,  Serr,  Serr,    Serr,    Serr,  Serr },
                                /*S2*/   { S2,    Serr,  Serr,   Serr,   Serr,  Serr,  Serr,    Serr,    Serr,  Serr },
                                /*S3*/   { S3,    Serr,  S3,     S3,     Serr,  Serr,  Serr,    Serr,    Serr,  Serr },
                                /*S4*/   { S5,    S5,    S5,     S5,     S5,    Serr,  S5,      S5,      S5,    S5   },
                                /*S5*/   { S5,    S5,    S5,     S5,     S5,    S6,    S5,      S5,      S5,    S5   },
                                /*S6*/   { Serr,  Serr,  Serr,   Serr,   Serr,  Serr,  Serr,    Serr,    Serr,  Serr },
                                /*S7*/   { Serr,  Serr,  Serr,   Serr,   Serr,  Serr,  S10,     Serr,    Serr,  Serr },
                                /*S8*/   { Serr,  Serr,  Serr,   Serr,   Serr,  Serr,  S10,     Serr,    Serr,  Serr },
                                /*S9*/   { Serr,  Serr,  Serr,   Serr,   Serr,  Serr,  S10,     Serr,    Serr,  Serr },
                                /*S10*/  { Serr,  Serr,  Serr,   Serr,   Serr,  Serr,  Serr,    Serr,    Serr,  Serr },
                                /*Serr*/ { Serr,  Serr,  Serr,   Serr,   Serr,  Serr,  Serr,    Serr,    Serr,  Serr }};

        std::set<State> d_accepting = {S1, S2, S3, S6, S7, S9, S10};

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