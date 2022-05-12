#include "lexer.ih"

#include <iostream>

Lexer::TransitionTable Lexer::s_transitions;

Token Lexer::getNextToken()
{
    while (d_currentLine.empty())
    {   
        // If we are done reading from file return end of file token
        if (d_programFile.eof())
        {    
            if (d_tokenStack.empty())
                return Token {"", Token::EOF_TK};
            else 
                throw runtime_error("lexical error - unexpected end of file");
        }
        else 
            getline(d_programFile, d_currentLine);
    }      

    char currentVal;

    while (true)
    {
        if (!d_currentLine.empty())
            currentVal = d_currentLine.at(0);
        else 
            break;

        InputType input = getInputType(currentVal);   
        d_currentState = s_transitions.d_transitions[d_currentState][input];

        if (d_currentState == Serr)
        {
            // Removing whitespace
            while (input == SPACE)
            {
                d_currentLine.erase(0, 1);
                currentVal = d_currentLine.at(0);
                input = getInputType(currentVal);
            }   
            break;
        }
        else 
        {
            ValueStatePair pair;
            pair.d_state = d_currentState;
            pair.d_val = currentVal;
            d_tokenStack.push(pair);
            d_currentLine.erase(0, 1);
        }
    }

    State topState = d_tokenStack.top().d_state;
            
    if (s_transitions.isAccepting(topState))
    {
        string tokenValue = "";
        while (!d_tokenStack.empty())
        {
            ValueStatePair pair = d_tokenStack.top();
            d_tokenStack.pop();
            tokenValue.insert(0, 1, pair.d_val);
        }

        // Resetting current state after token has been removed from stack
        d_currentState = S0;

        Token::TokenType tokenType = getTokenType(topState);
        return Token {tokenValue, tokenType};
    } 
    else if (s_transitions.isCommentState(topState))
        return getNextToken();
    else 
        throw runtime_error("lexical error");
}