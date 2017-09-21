#include <iostream>
using namespace std;

int main(){
  int v[5] = {};
  for(int i = 0; i < 5; ++i) cin >> v[i];
  int sumPositive, sumNegative, sumAll = 0;
  for(int i = 0; i < 5; ++i){
    if(v[i] > 0) sumPositive += v[i];
    if(v[i] < 0) sumNegative += v[i];
    sumAll += v[i];
  }
  cout << "Sum of all positive numbers = " << sumPositive << endl;
  cout << "Sum of all negative numbers = " << sumNegative << endl;
  cout << "Sum of all numbers = " << sumAll << endl;
}
