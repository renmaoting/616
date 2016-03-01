#include <iostream>
#include <limits>

int main() {
  float x = 2.5;
  int i = std::numeric_limits<int>::max();
  unsigned int j = i;

  std::cout << "x is: " << static_cast<int>(x) << std::endl;
  std::cout << "i is: " << i << std::endl;
  std::cout << "i+1 is: " << i+1 << std::endl;
  std::cout << "i+1 is: " << static_cast<unsigned int>(i)+1 << std::endl;
  std::cout << "j+1 is: " << j+1 << std::endl;
  std::cout << "2j+1 is: " << 2*(j+1) << std::endl;
  std::cout << "biggest int: " << std::numeric_limits<int>::max() 
            << std::endl;
}
