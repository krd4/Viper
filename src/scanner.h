#include <string>
#include <vector>

#include "token.h"
#include "error.h"

class Scanner {
public:
    Scanner(string source) : source(source) {}
private:
    bool isAtEnd() {
        return false;
    }
    char advance() {
        current++;
        return source.at(current);
    }
    bool match(char expected) {
        if(isAtEnd()) return false;
        if(source.chatAt(current + 1) != expected) return false;

        current++;
        return true;
    }
    Token scanToken() {
        char c = advance();
        switch(c) {
            case '(': Token(TokenType.LEFT_PAREN, "(", line); break;
            case ')': Token(TokenType.RIGHT_PAREN, ")", line); break;
            case '{': Token(TokenType.LEFT_BRACE, "{", line); break;
            case '}': Token(TokenType.RIGHT_PAREN, "}", line); break;
            case ',': Token(TokenType.COMMA, ",", line); break;
            case '.': Token(TokenType.DOT, ".", line); break;
            case '-': Token(TokenType.MINUS, "-", line); break;
            case ';': Token(TokenType.SEMICOLON, ";", line); break;
            case '*': Token(TokenType.STAR, "*", line); break;
            case '!': Token(match("=") ? TokenType.BANG_EQUAL : BANG, "*", line); break;
            case '=': Token(match("=") ? TokenType.EQUAL_EQUAL : EQUAL, "*", line); break;
            case '<': Token(match("=") ? TokenType.LESS_EQUAL : LESS, "*", line); break;
            case '>': Token(match("=") ? TokenType.GREATER_EQUAL : GREATER, "*", line); break;
            default: error(line, "Unexpected character"); break;
        }
    }
private:
    int start = 0;
    int current = -1;
    int line = 1;
    string source;
    vector<Token> tokens;
};