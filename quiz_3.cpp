#include <iostream>

int second_largest(int n){
  int first = -1, second = -1;
  while(n > 0){
    int digit = n % 10;
    n /= 10;
    if(digit > first){
      second = first;
      first = digit;
    }else if(digit > second && digit != first){
      second = digit;
    }
  }
  return second;
}

int main()
{
int n;
std::cin >> n;
std::cout << "Second largest digit: " << second_largest(n) << std::endl;
return 0;
}
