#include <iostream>
#include <cstdlib>
#include <vector>

void printStats(const std::vector<int>& vec) {
  std::cout << "size: " << vec.size() << ", ";
  std::cout << "cap: " << vec.capacity() << std::endl;
}

int main() {
  std::vector<int> vec;
  for (int i = 0; i < 9; ++i) {
    vec.push_back( rand()%100 );
    printStats(vec);
  }
  vec.push_back( rand()%100 );
  printStats(vec);
}
