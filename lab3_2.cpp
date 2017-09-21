#include <iostream>
using namespace std;
int main(){
  int v[3] = {};
  cin >> v[0] >> v[1] >> v[2];
  int m = v[0];
  for(int i = 1; i < 3; ++i){
    if(v[i] < m) m = v[i];
  }
  cout << m << endl;
}
