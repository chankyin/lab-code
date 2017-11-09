#include <fstream>
#include <iostream>

void swap(int &a, int &b) {
    int c = a;
    a = b;
    b = c;
}

/**
 * @param array the array to sort
 * @param count only elements from array[0] to array[count - 1] will be sorted. Elements from array[count] are garbage.
 *              This is similar to how we normally pass the array length, except that this time the array actually takes more memory.
 */
void selectionSort(int array[], int count) {
    for (int i = 0; i < count; ++i) {
        int minIndex = i, minValue = array[i];
        for (int j = i + 1; j < count; ++j) {
            if (minValue > array[j]) {
                minIndex = j;
                minValue = array[j];
            }
        }
        swap(array[i], array[minIndex]);
    }
}

int main() {
    const int MAXIMUM_INTS_ALLOWED = 100; // hardcoded!

    int count = 0;
    int array[MAXIMUM_INTS_ALLOWED]; // no need to initialize with zeroes

    std::ifstream is;
    is.open("lab8_5.test.txt");
    while (is >> array[count++]) {
    }
    is.close();

    --count; // in the last while-loop iteration that returned false, "count++" was still evaluated.

    selectionSort(array, count);

    std::ofstream os;
    os.open("lab8_5.output.txt");
    for (int i = 0; i < count; ++i) {
        os << array[i] << std::endl;
    }
    os.close();
}
