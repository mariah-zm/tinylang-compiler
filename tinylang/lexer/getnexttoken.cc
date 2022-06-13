#include "lexer.ih"

Lexer::TransitionTable Lexer::s_transitions;
Lexer::Input Lexer::s_inputHelper;

Token Lexer::getNextToken()
{
    while (d_currentLine.empty())
    {   
        // If we are done reading from file return end of file token
        if (d_programFile.eof())
        {    
            if (d_tokenStack.empty())
            {    
                d_programFile.close();              // close file once all read
                return Token {"", Token::EOF_TK};
            }
            else 
                throw lexical_error("unexpected end of file");
        }
        else 
        {
            ++d_lineNum;
            getline(d_programFile, d_currentLine);
            trimCurrentLine();
        }    
    }      

    char currentVal;

    while (true)
    {
        if (!d_currentLine.empty())
            currentVal = d_currentLine.at(0);
        else 
            break;

        Input::InputType input = s_inputHelper.getInputType(currentVal);   
        d_currentState = s_transitions.d_transitions[d_currentState][input];

        if (d_currentState == Serr)
        {
            // Removing whitespaces
            while (input == Input::SPACE)
            {
                d_currentLine.erase(0, 1);
                currentVal = d_currentLine.at(0);
                input = s_inputHelper.getInputType(currentVal);
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
        string lexeme = "";
        while (!d_tokenStack.empty())
        {
            ValueStatePair pair = d_tokenStack.top();
            d_tokenStack.pop();
            lexeme.insert(0, 1, pair.d_val);
        }

        // Resetting current state after token has been removed from stack
        d_currentState = S0;

        Token::TokenType tokenType = getTokenType(topState);

        // Ignore tokens that are comments
        if (tokenType == Token::COMMENT)
            return getNextToken();
        else
            return Token {lexeme, tokenType};
    } 
    else if (s_transitions.isCommentState(topState))
        return getNextToken();
    else 
        throw lexical_error("unexpected end of token");
}