#include <iostream>

void invert(char&a,char&b,char&c,char&d){
  char tmp=a;a=d;d=tmp;
  tmp=b;b=c;c=tmp;
}

int main(){
  char a, b, c, d;
  std::cin >> a >> b >> c >> d;
  invert(a, b, c, d);
  std::cout << a << b << c << d;
}
