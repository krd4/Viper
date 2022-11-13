#include <iostream>
#include <string>

using namespace std;

int run(string file_name) {
    cout << file_name << endl;
    return 0;
}

int run_prompt() {
    return 0;
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
}