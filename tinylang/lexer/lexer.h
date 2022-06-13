#ifndef INCLUDED_LEXER_
#define INCLUDED_LEXER_

#include "../token/token.h"

#include <fstream>
#include <set>
#include <stack>
#include <map>

class Lexer
{
    struct Input
    {
        enum InputType
        {
            DIGIT,
            DOT,
            LETTER,
            UNDSCR,
            SPACE,
            ESCAPE,
            QUOTE,
            EQ_SIGN,
            LT_SIGN,
            GT_SIGN,
            EXCLM,
            ADD,
            MINUS,
            MUL,
            DIV,
            PUNCT,
            PRINT  // this includes chars which are not the above but printable
        };

        std::string d_punctuation = "{}():;,";
        std::map<char, InputType> d_charInputs = {{'.',  DOT},
                                                  {'_',  UNDSCR},
                                                  {'\\', ESCAPE},
                                                  {'\'', QUOTE},
                                                  {'=',  EQ_SIGN},
                                                  {'<',  LT_SIGN},
                                                  {'>',  GT_SIGN},
                                                  {'!',  EXCLM},
                                                  {'+',  ADD},
                                                  {'-',  MINUS},
                                                  {'*',  MUL},
                                                  {'/',  DIV}};

        InputType getInputType(char val) const ;
    };

    enum State
    {
        S0,     // Start
        S1,     // Integer
        S2,     // Float
        S3,     // Identifier
        S4,     // Open Quote
        S5,     // Char except escape and quote
        S6,     // Escape Char
        S7,     // Quote after escape char
        S8,     // Close Quote - char literal
        S9,     // Assignment [ = ]
        S10,    // Exclamation Mark [ ! ]
        S11,    // RelOp [ < > ]
        S12,    // RelOp [ == <= >= != ]
        S13,    // Addition
        S14,    // Subtraction
        S15,    // Multiplication
        S16,    // Division
        S17,    // Multi-line Comment
        S18,    // One-Line Comment
        S19,    // MLine *
        S20,    // End Of MLine Comment
        S21,    // Function Arrow [ -> ]
        S22,    // Punctuation [ { } ( ) , ; : ]
        Serr    // Error state
    };

    struct TransitionTable
    {
        State d_starting = S0;
        State d_transitions[24][17] = { // DIGIT  DOT    LETTER  UNDSCR  SPACE  ESCAPE  QUOTE  EQ_SIGN  LT_SIGN  GT_SIGN  EXCLM  ADD    MINUS  MUL    DIV    PUNCT  PRINT
                                /*S0*/   { S1,    Serr,  S3,     S3,     Serr,  Serr,   S4,    S9,      S11,     S11,     S10,   S13,   S14,   S15,   S16,   S22,   Serr },
                                /*S1*/   { S1,    S2,    Serr,   Serr,   Serr,  Serr,   Serr,  Serr,    Serr,    Serr,    Serr,  Serr,  Serr,  Serr,  Serr,  Serr,  Serr },
                                /*S2*/   { S2,    Serr,  Serr,   Serr,   Serr,  Serr,   Serr,  Serr,    Serr,    Serr,    Serr,  Serr,  Serr,  Serr,  Serr,  Serr,  Serr },
                                /*S3*/   { S3,    Serr,  S3,     S3,     Serr,  Serr,   Serr,  Serr,    Serr,    Serr,    Serr,  Serr,  Serr,  Serr,  Serr,  Serr,  Serr },
                                /*S4*/   { S5,    S5,    S5,     S5,     S5,    S6,     Serr,  S5,      S5,      S5,      S5,    S5,    S5,    S5,    S5,    S5,    S5   },
                                /*S5*/   { Serr,  Serr,  Serr,   Serr,   Serr,  S8,     Serr,  Serr,    Serr,    Serr,    Serr,  Serr,  Serr,  Serr,  Serr,  Serr,  Serr },
                                /*S6*/   { Serr,  Serr,  Serr,   Serr,   Serr,  Serr,   S7,    Serr,    Serr,    Serr,    Serr,  Serr,  Serr,  Serr,  Serr,  Serr,  Serr },
                                /*S7*/   { Serr,  Serr,  Serr,   Serr,   Serr,  Serr,   S8,    Serr,    Serr,    Serr,    Serr,  Serr,  Serr,  Serr,  Serr,  Serr,  Serr },
                                /*S8*/   { Serr,  Serr,  Serr,   Serr,   Serr,  Serr,   Serr,  Serr,    Serr,    Serr,    Serr,  Serr,  Serr,  Serr,  Serr,  Serr,  Serr },
                                /*S9*/   { Serr,  Serr,  Serr,   Serr,   Serr,  Serr,   Serr,  S12,     Serr,    Serr,    Serr,  Serr,  Serr,  Serr,  Serr,  Serr,  Serr },
                                /*S10*/  { Serr,  Serr,  Serr,   Serr,   Serr,  Serr,   Serr,  S12,     Serr,    Serr,    Serr,  Serr,  Serr,  Serr,  Serr,  Serr,  Serr },
                                /*S11*/  { Serr,  Serr,  Serr,   Serr,   Serr,  Serr,   Serr,  S12,     Serr,    Serr,    Serr,  Serr,  Serr,  Serr,  Serr,  Serr,  Serr },
                                /*S12*/  { Serr,  Serr,  Serr,   Serr,   Serr,  Serr,   Serr,  Serr,    Serr,    Serr,    Serr,  Serr,  Serr,  Serr,  Serr,  Serr,  Serr },
                                /*S13*/  { Serr,  Serr,  Serr,   Serr,   Serr,  Serr,   Serr,  Serr,    Serr,    Serr,    Serr,  Serr,  Serr,  Serr,  Serr,  Serr,  Serr },
                                /*S14*/  { S1,    Serr,  Serr,   Serr,   Serr,  Serr,   Serr,  Serr,    Serr,    S21,     Serr,  Serr,  Serr,  Serr,  Serr,  Serr,  Serr },
                                /*S15*/  { Serr,  Serr,  Serr,   Serr,   Serr,  Serr,   Serr,  Serr,    Serr,    Serr,    Serr,  Serr,  Serr,  Serr,  Serr,  Serr,  Serr },
                                /*S16*/  { Serr,  Serr,  Serr,   Serr,   Serr,  Serr,   Serr,  Serr,    Serr,    Serr,    Serr,  Serr,  Serr,  S17,   S18,   Serr,  Serr },
                                /*S17*/  { S17,   S17,   S17,    S17,    S17,   S17,    Serr,  S17,     S17,     S17,     S17,   S17,   S17,   S19,   S17,   S17,   S17   },
                                /*S18*/  { S18,   S18,   S18,    S18,    S18,   S18,    Serr,  S18,     S18,     S18,     S18,   S18,   S18,   S18,   S18,   S18,   S18  },
                                /*S19*/  { S17,   S17,   S17,    S17,    S17,   S17,    Serr,  S17,     S17,     S17,     S17,   S17,   S17,   S19,   S20,   S17,   S17  },
                                /*S20*/  { Serr,  Serr,  Serr,   Serr,   Serr,  Serr,   Serr,  Serr,    Serr,    Serr,    Serr,  Serr,  Serr,  Serr,  Serr,  Serr,  Serr },
                                /*S21*/  { Serr,  Serr,  Serr,   Serr,   Serr,  Serr,   Serr,  Serr,    Serr,    Serr,    Serr,  Serr,  Serr,  Serr,  Serr,  Serr,  Serr },
                                /*S22*/  { Serr,  Serr,  Serr,   Serr,   Serr,  Serr,   Serr,  Serr,    Serr,    Serr,    Serr,  Serr,  Serr,  Serr,  Serr,  Serr,  Serr },
                                /*Serr*/ { Serr,  Serr,  Serr,   Serr,   Serr,  Serr,   Serr,  Serr,    Serr,    Serr,    Serr,  Serr,  Serr,  Serr,  Serr,  Serr,  Serr }};

        std::set<State> d_accepting = {S1, S2, S3, S7, S8, S9, S11, S12, S13, S14, S15, S16, S18, S20, S21, S22};

        bool isAccepting(State state)
        {
            return d_accepting.find(state) != s_transitions.d_accepting.end();
        }

        bool isCommentState(State state)
        {
            return state == S17 || state == S19;
        }
    };

    struct ValueStatePair
    {
        char d_val;
        State d_state;
    };

    static TransitionTable s_transitions;
    static Input s_inputHelper;

    std::stack<ValueStatePair> d_tokenStack;
    std::ifstream d_programFile;
    std::string d_currentLine;
    State d_currentState = s_transitions.d_starting;

    size_t d_lineNum = 0;
    size_t d_charNum = 0;

    public:
        Lexer(const Lexer &lexer);      // Copy constructor
        Lexer(std::string fileName);

        Token getNextToken();

    private:
        Token::TokenType getTokenType(State state);
};

#endif