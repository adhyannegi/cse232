#include <iostream>

double Square(double value) {
    return value * value;
}
double CircleArea(double r) {
  double sqr = Square(r);
   return 3.141592 * sqr;
   }
   int main() {
     double result = CircleArea(12.5);
    std::cout << "Area = " << result << std::endl;
  }