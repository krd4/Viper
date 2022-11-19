#include <stdexcept>
#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <format>

using namespace std;

ifstream openScript(string file_name) {
    if (!regex_match(file_name, regex("([a-z]|[A-Z]|\\/)*\\.vr"))) {
        throw invalid_argument(file_name + " is not viper script");
    }

    ifstream f;
    f.open(file_name);
    
    return f;
}

void run(string file_name) {
    string script;
    try {
        auto f = openScript(file_name);
        
        if (f.is_open()) {
            while(getline(f, script)) {
                cout << script << endl;
            }

            f.close();
        }
    }

    catch(invalid_argument& e) {
        cout << e.what() << endl;
    }
}

void run_prompt() {
}

int main(int argc, char *argv[]) {
    if (argc <= 1) {
        cout << "Usage: viper [script]" << endl;
        return 1;
    } else if (argc == 2) {
        string file_name(argv[1]);
        run(file_name);
    }

    run_prompt();

    return 0;
}