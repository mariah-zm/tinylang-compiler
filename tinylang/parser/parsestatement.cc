#include "parser.ih"

AstStatementNode *Parser::parseStatement()
{
    AstStatementNode *node;
    switch (d_currentTok.type())
    {
        case Token::FN:
        {
            node = parseFunctionDef();
            break;
        }
        case Token::LET:
        {
            node = parseVarDecl();
            parseSemiColon();
            break;
        }
        case Token::IDENTIFIER:
        {
            node = parseAssignment();
            parseSemiColon();
            break;
        }
        case Token::PRINT:
        {
            node = parsePrint();
            parseSemiColon();
            break;
        }
        case Token::IF:
        {
            node = parseIf();
            break;
        }
        case Token::FOR:
        {
            node = parseFor();
            break;
        }
        case Token::WHILE:
        {
            node = parseWhile();
            break;
        }
        case Token::RETURN:
        {
            node = parseReturn();
            parseSemiColon();
            break;
        }
        default:
            throw syntax_error("unexpected token in line " 
                    + to_string(d_lexer->lineNumber()));
    }

    return node;
}