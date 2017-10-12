#include <iostream>
using namespace std;
int main(){
  char arr[8] = {};
  for(int i = 0; i < 8; ++i) cin >> arr[i];
  for(int i = 7; i >= 0; --i) cout << arr[i];
}
