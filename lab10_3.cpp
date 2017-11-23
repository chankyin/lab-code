#include <iostream>

using namespace std;

struct SimpleIntVector {
    unsigned int *array = NULL;
    size_t size = 0;

    void push(unsigned int value) {
        int *newArray = new int[size + 1];
        for(size_t i = 0; i < size; ++i){
            newArray[i] = array[i];
        }
        newArray[size++] = value;
    }
};


int main() {
    SimpleIntVector vector;

    unsigned int last = 0;
    while(last != -1){
        cin >> last;
        vector.push(last);
    }
}