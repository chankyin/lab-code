#include <iostream>
using namespace std;
int main(){
  int m;
  cin >> m;
  for(int i = 1; i < 3; ++i){
    int input;
    cin >> input;
    if(input < m) m = input;
  }
  cout << m << endl;
}
