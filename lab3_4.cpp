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
  int diff = (querySymbol() - querySymbol()) % 3;
  while(diff < 0) diff += 3;
  if(diff == 0){
    cout << "Nobody wins" << endl;
    return 0;
  }
  if(diff == 1){
    cout << "User 2 wins" << endl;
    return 0;
  }
  cout << "User 1 wins" << endl;
  return 0;
}
