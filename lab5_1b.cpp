#include <iostream>
int productSelection(){
  while(true){
    std::cout << "1: Chicken ($20)\n2: Milk ($6.5)\n3: Chocolate ($10)\n--> ";
    int sel;
    std::cin >> sel;
    if(1 <= sel && sel <= 3){
      return sel;
    }
  }
}
