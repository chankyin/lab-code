#include <iostream>
using namespace std;
int main(){
  int x = 42;
  int y = x + 1;
  cout << "x = " << x << endl;
  cout << "y = " << y << endl;
  x = 1;
  cout << "x = " << x << endl;
  cout << "y = " << y << endl;
}
