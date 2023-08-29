// WRITE YOUR CODE HERE
#include <iostream>
#include <string>

int main() {
  std::string name1, name2;
  int age1, age2;

  std::cin >> name1 >> age1 >> name2 >> age2;
  std::cout << name1 << " is " << (age1 - age2) << " years older than " << name2 << ".";
  return 0;
}