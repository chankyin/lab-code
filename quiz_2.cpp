#include <iostream>

bool is_cube(int n){
  for(int i = 1; i * i * i <= n; ++i){
    if(i * i * i == n) return true;
  }
  return false;
}

int main()
{
int n;
std::cin >> n;
if (is_cube(n))
{
std::cout << "Yes, it is a perfect cube" << std::endl;
}
else
{
std::cout << "No, it is not a perfect cube" << std::endl;
}
return 0;
}
