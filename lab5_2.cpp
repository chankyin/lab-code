#include <iostream>
using namespace std;
int reverse(int n);
int main(){
  for(int i = 0; i < 10; ++i){
    int n;
    cin >> n;
    cout << reverse(n) << endl;
  }
  return 0;
}

int reverse(int n){
  int ret = 0;
  while(n > 0){
    ret *= 10;
    ret += n % 10;
    n /= 10;
  }
  return ret;
}
