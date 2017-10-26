#include <iostream>

int main(){
  const std::string tens[10] = {
    "",
    "",
    "twenty",
    "thirty",
    "forty",
    "fifty",
    "sixty",
    "seventy",
    "eighty",
    "ninety"
  },
  units[10] = {
    "",
    "one",
    "two",
    "three",
    "four",
    "five",
    "six",
    "seven",
    "eight",
    "nine"
  },
  teens[10] = {
    "ten",
    "eleven",
    "twelve",
    "thirteen",
    "fourteen",
    "fifteen",
    "sixteen",
    "seventeen",
    "eighteen",
    "nineteen"
  };

  int input;
  std::cin >> input;
  int ten = input / 10, unit = input % 10;
  if(ten >= 2){
    if(unit > 0){
      std::cout << tens[ten] << '-' << units[unit] << std::endl;
    }else{
      std::cout << tens[ten] << std::endl;
    }
  }else if(ten == 1){
    std::cout << teens[unit] << std::endl;
  }else{
    std::cout << units[unit] << std::endl;
  }
  return 0;
}
