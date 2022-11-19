#include <iostream>
#include <string>
using namespace std;

void report(int line, string where, string message) {
    cout << "[line " << line << "] Error" << "where" << ": " << message << endl;
}

void error(int line, string message) {
    report(line, "", message);
}