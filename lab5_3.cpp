#include <iostream>
using namespace std;
void oneMore(int argv[], int argc){
  for(int i = 0; i < argc; ++i){
    argv[i]++;
  }
}

int main(){
  int array[] = {1, 2, 3, 9, 5};
  oneMore(array, 5);
  for(int i : array) cout << i << endl;
}
