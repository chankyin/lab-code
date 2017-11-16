#include <iostream>

using namespace std;

struct Entry {
    string name;
    char dorm;
    int age;

    bool equal(Entry that) {
        return name == that.name && dorm == that.dorm && age == that.age;
    }
};


int main() {
    Entry e1 = {"Dirk", 'a', 26};
    Entry e2 = {"George", 'b', 28};
    if (e1.equal(e2)) {
        cout << "same" << endl;
    } else {
        cout << "different" << endl;
    }
}