#include <iostream>

using namespace std;

void replaceAll(string &input, string from, string to) {
    size_t f;
    while ((f = input.find(from)) != string::npos) {
        input = input.replace(f, from.length(), to);
    }
}

int main() {
    string input;
    getline(cin, input);
    cout << "Before replace:" << endl << input << endl;
    replaceAll(input, "HKU", "The University of Hong Kong");
    cout << "After replace:" << endl << input << endl;
    replaceAll(input, "The University of Hong Kong", "H.K.U.");
    cout << "After replace:" << endl << input << endl;
}
