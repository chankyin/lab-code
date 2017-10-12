#include "lab5_supermarket_main.cpp"

const int numberOfProducts = 3;
const string name[numberOfProducts] = {"Chicken", "Milk", "Chocolate"};
const double price[numberOfProducts] = {20, 6.5, 10};

int productSelection(){
  while(true){
    for(int i = 1; i <= numberOfProducts; ++i){
      cout << i << ": " << name[i-1] << " ($" << price[i-1] << ")" << endl;
    }
    std::cout << "--> ";
    int sel;
    std::cin >> sel;
    if(1 <= sel && sel <= numberOfProducts){
      return sel;
    }
  }
}

double priceOf(int i){
  cout << "priceOf(" << (i + 1) << ")" << endl;
  return price[i];
}

int main(){
  main0();
}
