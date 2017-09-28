#include <iostream>
#include "lab4_5.cpp"

using namespace std;

int main(){
  int a, b;
  cin >> a >> b;
  int min, max;
  if(a > b){
    min = b;
    max = a;
  }else{
    min = a;
    max = b;
  }
  for(int i = min; i <= max; ++i){
    if(isPerfect(i)){
      cout << i << endl;
    }
    ++a;
  }
}
