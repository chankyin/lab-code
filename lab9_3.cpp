#include <iostream>
#include <fstream>
#include <unordered_map>

using namespace std;

const int MAX_ENTRIES = 100;

struct Entry {
    string name;
    char dorm;
    int age;

    void output(ostream &os);
};

void swap(Entry &a, Entry &b);

int readEntries(Entry entries[]){
    ifstream is;
    is.open("lab9_3.entries.txt");
    int count = 0;
    while (is >> entries[count].name >> entries[count].dorm >> entries[count].age) {
        ++count;
    }
    is.close();

    return count;
}

void sortEntries(Entry entries[], int count){
    for (int i = 0; i < count; ++i) {
        int maxKey = i;
        for (int j = i; j < count; ++j) {
            if (entries[maxKey].age > entries[j].age) {
                maxKey = j;
            }
        }
        swap(entries[i], entries[maxKey]);
    }
}

void writeEntries(Entry entries[], int count) {
    ofstream os;
    os.open("lab9_3.sorted.txt");
    for (int i = 0; i < count; ++i) {
        entries[i].output(os);
    }
    os.close();
}


int main() {
    Entry entries[MAX_ENTRIES];

    int count = readEntries(entries);
    sortEntries(entries, count);
    writeEntries(entries, count);
}

void swap(Entry &a, Entry &b) {
    Entry c = a;
    a = b;
    b = c;
}

void Entry::output(ostream &os) {
    os << name << " | " << dorm << " | " << age << endl;
}
