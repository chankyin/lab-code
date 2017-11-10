#include <string>
#include <iostream>
#include <fstream>

const char DELIMITER_BYTE = ' ';

void leftTrim(std::string &str, char c) {
    std::cout << "leftTrim: start" << std::endl;
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
    std::cout << "compareInts: Comparing " << a << " vs " << b << std::endl;
    if (a[0] == '-' && b[0] != '-') return -1;
    if (a[0] != '-' && b[0] == '-') return 1;
    if (a[0] == '-' && b[0] == '-') return compareInts(b.substr(1), a.substr(
                1)); // negative minus negative! recursion: negate and SWAP
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
    std::cout << "getNthWord: start" << std::endl;
    start = 0;
    for (int i = 0; i < n; ++i) {
        start = string.find(delimiter, start) + 1; // + 1 to skip the delimiter byte
        // assuming string size is large enough, i.e. string.find() does not return std::string::npos
    }
    int end = string.find(delimiter, start);
    std::cout << "getNthWord: Word #" << n << " in " << string << " is in " << start << " - " << end << std::endl;
    return string.substr(start, end - start); // even std::string::npos - start must be a valid value here.
}

std::string swapWords(std::string string, char delimiter, int i, int j) {
    if(i == j) return string;
    std::cout << "swapWords: start (" << i << " & " << j << "): " << string << std::endl;
    if (i > j) {
        return swapWords(string, delimiter, j, i);
    }

    int iStart, jStart;
    std::string iWord = getNthWord(string, delimiter, i, iStart);
    std::string jWord = getNthWord(string, delimiter, j, jStart);

    std::cout << "swapWords: computing: " << iStart << ", " << jStart << std::endl;
    std::string front = string.substr(0, iStart),
            middle = string.substr(iStart + iWord.length(), jStart - iStart - iWord.length()),
            end = string.substr(jStart + jWord.length());
    std::string result = front + jWord + middle + iWord + end;
    std::cout << "swapWords: end:   " << result << std::endl;
    return result;
}

void stringSelectionSort(std::string &string, int size) {
    std::cout << "stringSelectionSort: start" << std::endl;
    for (int i = 0; i < size; ++i) {
        int dummy; // useless placeholder parameter used in getNthWord()
        int minIndex = i;
        std::string minValue = getNthWord(string, DELIMITER_BYTE, i, dummy);
        for (int j = i + 1; j < size; ++j) {
            std::cout << "stringSelectionSort: words #" << i << " and #" << j << std::endl;
            std::string word = getNthWord(string, DELIMITER_BYTE, j, dummy);
            if (compareInts(minValue, word) == 1) {
                minIndex = j;
                minValue = word;
            }
        }
        std::cout << "stringSelectionSort: Swapping " << i << " and " << minIndex << std::endl;
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
        stack += DELIMITER_BYTE; // delimit each number with a delimiter byte (' '). this is equivalent to reading the whole file then replacing different separators to the same delimiter
        ++size;
    }
    is.close();

    stringSelectionSort(stack, size);

    std::cout << "main: " << stack << std::endl;

    std::ofstream os;
    os.open("lab8_5.output.txt");
    os << stack;
    os.close();
}
