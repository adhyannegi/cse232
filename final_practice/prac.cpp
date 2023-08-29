#include <iostream>

void foo(int *p) {
      std::cout << *p << std::endl;
      (*p)++;
  }
  int main() {
      int i = 10;
      foo(&i);
      std::cout << i;
  }