#include <stdexcept>
#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <format>

using namespace std;

 

class Viper {
public:
    Viper(string file_name) : file_name(file_name) {}
    int run() {
        string line;
        try {
            auto f = openScript(file_name);
            
            if (f.is_open()) {
                while(getline(f, line)) {
                    script += line + " ";
                }
                f.close();
            }

            return 0;
        }

        catch(invalid_argument& e) {
            cout << e.what() << endl;

            return -1;
        }
    }

    int run_prompt() {return 0;}

    static ifstream openScript(string file_name) {
        if (!regex_match(file_name, regex("([a-z]|[A-Z]|\\/)*\\.vr"))) {
            throw invalid_argument(file_name + " is not viper script");
        }

        ifstream f;
        f.open(file_name);
        
        return f;
    }
private:
    string file_name;
    string script;
};


int main(int argc, char *argv[]) {
    if (argc <= 1) {
        cout << "Usage: viper [script]" << endl;
        return 1;
    } else if (argc == 2) {
        string file_name(argv[1]);
        Viper viper(file_name);
        return viper.run();
    }
}