#include <string>

using namespace std;

string *addEntry(string *array, int &size, string newEntry) {
    string *newArray = new string[size + 1];
    for(int i = 0; i < size; ++i){
        newArray[i] = array[i];
    }
    newArray[size++] = newEntry;
    delete[] array;
    return newArray;
}

string *deleteEntry(string *array, int &size, string entryToDelete){
    int offset = -1;
    for(int i = 0; i < size; ++i){
        if(array[i] == entryToDelete){
            offset = i;
            break;
        }
    }
    if(offset == -1){
        return array;
    }

    string *newArray = new string[size - 1];
    for(int i = 0; i < offset; ++i){
        newArray[i] = array[i];
    }
    for(int i = offset; i < size - 1; ++i){
        newArray[i] = array[i + 1];
    }
    --size;
    delete[] array;
    return newArray;
}

/**
 * Same as deleteEntry(), except the former only deletes the first match but this one deletes all matches.
 * @param array
 * @param size
 * @param entryToDelete
 * @return
 */
string *g_deleteEntry(string *array, size_t &size, string entryToDelete){
    size_t matchCount = 0;
    for(size_t i = 0; i < size; ++i){
        if(array[i] == entryToDelete){
            ++matchCount;
        }
    }

    size_t matched = 0;
    string *newArray = new string[size - matchCount];
    for(size_t i = 0; i < size; ++i){
        if(array[i] == entryToDelete){
            ++matched;
        }else{
            newArray[i - matched] = array[i];
        }
    }
    size -= matchCount;
    return newArray;
}