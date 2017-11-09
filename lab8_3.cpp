#include <iostream>
#include <fstream>

int main(){
    std::ifstream is;
    is.open("lab8_3.test.txt");
    if(is.fail()){
        std::cerr << "Error opening file" << std::endl;
        return 1;
    }
    std::string line;
    while(std::getline(is, line)){
        size_t delimiter1 = line.find(' '), delimiter2 = line.find(' ', delimiter1 + 1); // remember the +1
        if(delimiter1 != std::string::npos){
            std::cout << line.substr(delimiter1 + 1, delimiter2 - delimiter1 - 1) << std::endl;
        }
    }
    is.close();
}