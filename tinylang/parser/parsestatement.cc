#include "parser.ih"

AstStatementNode *Parser::parseStatement()
{
    switch (d_currentTok.type())
    {
        case Token::LET:
            return parseVarDecl();
        case Token::PRINT:
            return parsePrint();
        case Token::RETURN:
            return parseReturn();
        case Token::IF:
            return parseIf();
        case Token::FOR:
            return parseFor();
        case Token::WHILE:
            return parseWhile();
        case Token::IDENTIFIER:
            return parseAssignment();
        default:
            throw syntax_error("unexpected token");
    }
}