// Brian Malloy        Game Construction
#include "manager.h"
#include "frameFactory.h"

int main(int, char*[]) {
   try {
      Manager manager;
      manager.play();
   }
   catch (const std::string& msg) { std::cout << msg << std::endl; }
   catch (...) {
      std::cout << "Oops, someone threw an exception!" << std::endl;
   }
   return 0;
}
