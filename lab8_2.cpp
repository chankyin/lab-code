#include <iostream>

using namespace std;

void parseName(string input, string &first, string &last, string &nick){
    size_t delimiter1 = input.find(", "), delimiter2 = input.find(" (", delimiter1 + 2), delimiter3 = input.find(')', delimiter2 + 2);
    first = input.substr(0, delimiter1);
    last = input.substr(delimiter1 + 2, delimiter2 - delimiter1 - 2);
    nick = input.substr(delimiter2 + 2, delimiter3 - delimiter2 - 2);
}

string returnNickNameGivenLastName(string names[], int n, string lastName) {
    for(int i = 0; i < n; ++i){
        string f, l, nick;
        parseName(names[i], f, l, nick);
        if(l == lastName){
            return nick;
        }
    }
    return "Not found!";
}

int main() {
    string name[] = {
            "Dirk, Schnieders (Dirk)",
            "Lingjie, Liu (Maxine)",
            "Chaowei, Fang (Chaowei)",
            "Zhen, Li (Jason)"
    };
    int numOfUsers = 4;
    string lastName;
    cin >> lastName;
    cout << returnNickNameGivenLastName(name, numOfUsers, lastName) << endl;
    return 0;
}
