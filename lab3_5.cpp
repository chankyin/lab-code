#include <iostream>
using namespace std;

int main(){
  int sumPositive = 0, sumNegative = 0;
  for(int i = 0; i < 5; ++i){
    int input = 0;
    cin >> input;
    if(input > 0) sumPositive += input;
    if(input < 0) sumNegative += input;
  }
  cout << "Sum of all positive numbers = " << sumPositive << endl << "Sum of all negative numbers = " << sumNegative << endl << "Sum of all numbers = " << sumPositive + sumNegative << endl;
}
