#include <iostream>
#include <cstring>

class A {
public:
  A();
  A (int n) : number(n) {}
  A (const A& a) : number(a.number) {}
  int getNumber() const { return number; }
private:
  int number;
};
std::ostream& operator<<(std::ostream& out, const A& a) {
  return out << a.getNumber();
}
A::A() : number(0) { 
  std::cout << "default: " << number << std::endl; 
}

int main() {
  A x = 7;
  A c=x;
  std::cout << x << std::endl;
  return 0;
}
