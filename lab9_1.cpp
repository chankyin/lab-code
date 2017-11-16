#include <iostream>

using namespace std;
struct Entry {
    string name;
    char dorm;
    int age;
};

bool equal(Entry a, Entry b) {
    return a.name == b.name && a.dorm == b.dorm && a.age == b.age;
}

int main() {
    Entry e1 = {"Dirk", 'a', 26};
    Entry e2 = {"George", 'b', 28};
    if (equal(e1, e2)) {
        cout << "same" << endl;
    } else {
        cout << "different" << endl;
    }
}