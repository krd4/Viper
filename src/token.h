#include <string>

using namespace std;

enum TokenType {
    LEFT_PAREN, RIGHT_PAREN, LEFT_BRACE, RIGHT_BRACE,
    COMMA, DOT, MINUS, PLUS, SEMICOLON, SLASH, STAR,
    BANG, BANG_EQUAL,
    EQUAL, EQUAL_EQUAL,
    GREATER, GREATER_EQUAL,
    LESS, LESS_EQUAL,
    TRUE, FALSE, AND, OR, IF, ELSE, NIL, DEF, FOR, RETURN, WHILE, LET
};

class Token {
public:
    Token(TokenType token_type, string lexeme, int line) :
        token_type(token_type),
        lexeme(lexeme),
        line(line) {}
private:
    TokenType token_type;
    string lexeme;
    int line;
};