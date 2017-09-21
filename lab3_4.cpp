#include <iostream>
using namespace std;

const int P = 0, R = 1, S = 2;

int querySymbol(){
  char input;
  while(true){
    cout << "Input (P/S/R): ";
    cin >> input;
    if(input == 'P' || input == 'p'){
      return P;
    }
    if(input == 'R' || input == 'r'){
      return R;
    }
    if(input == 'S' || input == 's'){
      return S;
    }
    cout << "Wrong input" << endl;
  }
}

int main(){
  int a = querySymbol(), b = querySymbol();
  if(a == b){
    cout << "Nobody wins" << endl;
    return 0;
  }
  if(a + 1 == b || a - 2 == b){
    cout << "User 1 wins" << endl;
    return 0;
  }
  cout << "User 2 wins" << endl;
  return 0;
}
