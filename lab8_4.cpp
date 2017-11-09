#include <iostream>
#include <fstream>

int main(){
    std::ifstream is;
    is.open("lab8_4.test.txt");
    if(is.fail()){
        std::cerr << "Error opening file" << std::endl;
        return 1;
    }

    int i, max, min;
    bool first = true;
    while(is >> i){
        if(first){
            max = min = i;
            first = false;
        }
        if(max < i) max = i;
        if(min > i) min = i;
    }
    is.close();
    std::ofstream os;
    os.open("lab8_4.test.txt", std::ios::app);
    os << max << std::endl << min << std::endl;
}
