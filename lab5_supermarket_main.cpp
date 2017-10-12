#include <iostream>
#include "lab5_1c.cpp"

using namespace std;

void main0(){
  char c = 'm';
  double price = 0;
  while(c == 'm'){
    price += purchase();
    cout << "Sub-total: $" << price << endl;
    cout << "Enter 'm' to purchase more! --> ";
    cin >> c;
  }
  cout << "Total: $" << price << endl;
}
