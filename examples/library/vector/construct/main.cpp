#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>

class Number {
public:
  Number() : number(0) {
    std::cout << "default" << std::endl;
  }
  Number(int n) : number(n) {
    std::cout << "convert" << std::endl;
  }
  Number(const Number& a) : number(a.number) {
    std::cout << "copy" << std::endl;
  }
  Number& operator=(const Number& rhs) {
    if ( this != &rhs ) {
      number = rhs.number;
    }
    std::cout << "assign" << std::endl;
    return *this;
  }
  int getNumber() const { return number; }
private:
  int number;
};

void print(const std::vector<Number> & vec) {
  for (unsigned int i = 0; i < vec.size(); ++i) {
    std::cout << vec[i].getNumber()  << ", ";
  }
  std::cout << std::endl;
}

int main() {
  std::vector<Number> vec(10);
}
