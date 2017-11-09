#include <string>
#include <iostream>
#include <fstream>

const char DELIMITER_BYTE = '\n';

void leftTrim(std::string &str, char c) {
    while (!str.empty() && str[0] == c) {
        str = str.substr(1);
    }
}

/**
 * Returns sgn(a - b)
 * @param a
 * @param b
 * @return 1, 0 or -1
 */
int compareInts(std::string a, std::string b) {
    // assuming both strings are valid
    if (a[0] == '-' && b[0] != '-') return -1;
    if (a[0] != '-' && b[0] == '-') return 1;
    if (a[0] != '-' && b[0] != '-') return compareInts(b.substr(1), a.substr(1)); // recursion: negate and SWAP
    leftTrim(a, '0');
    leftTrim(b, '0');
    int log_a = a.length(); // number of digits left = log(a) + 1
    int log_b = b.length();
    if (log_a > log_b) return 1;
    if (log_a < log_b) return -1;
    for (int i = 0; i < log_a; ++i) {
        if (a[i] > b[i]) return 1;
        if (a[i] < b[i]) return -1;
        // digit is the same, continue to next (smaller) digit
    }
    return 0; // the same!
}

std::string getNthWord(std::string string, char delimiter, int n, int &start) {
    start = 0;
    for (int i = 0; i < n; ++i) {
        start = string.find(delimiter, start) + 1; // + 1 to skip the delimiter byte
        // assuming string size is large enough, i.e. string.find() does not return std::string::npos
    }
    int end = string.find(delimiter, start);
    return string.substr(start, end - start); // even std::string::npos - start must be a valid value here.
}

std::string swapWords(std::string string, char delimiter, int i, int j){
    if(i > j) return swapWords(string, delimiter, j, i);

    int iStart, jStart;
    std::string iWord = getNthWord(string, delimiter, i, iStart) + delimiter;
    std::string jWord = getNthWord(string, delimiter, j, jStart) + delimiter;

    return string.substr(0, iStart) + jWord + string.substr(iStart + iWord.length(), jStart - iStart - iWord.length()) + iWord + string.substr(jStart + jWord.length());
}

std::string stringSelectionSort(std::string string, int size) {
    for (int i = 0; i < size; ++i) {
        int minIndex = 0;
        int dummy; // useless placeholder parameter
        std::string minValue = getNthWord(string, DELIMITER_BYTE, i, dummy);
        for (int j = i + 1; j < size; ++j) {
            std::string word = getNthWord(string, DELIMITER_BYTE, j, dummy);
            if(compareInts(minValue, word) == 1){
                minIndex = j;
                minValue = word;
            }
        }
        string = swapWords(string, DELIMITER_BYTE, i, minIndex);
    }
}

int main() {
    std::string stack = "";
    std::ifstream is;
    is.open("lab8_5.test.txt");
    std::string str;
    int size = 0;
    while (is >> str) {
        stack += str; // append str to stack
        stack += DELIMITER_BYTE; // delimit each number with a linefeed. this is equivalent to reading the whole file then replacing numbers to
        ++size;
    }
    is.close();

    stack = stringSelectionSort(stack, size);

    std::ofstream os;
    os.open("lab8_5.output.txt");
    os << stack;
    os.close();
}