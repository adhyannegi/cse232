#include "q2.cpp"
#include <iostream>

int main(){

Counter e;
//CHECK(e.log_.back() == "Default Constructor called.");
std::cout << e.log_.back() << std::endl;
Counter c(5);
Counter d(c);
std::vector expected {
  "Constructor called with a 5",
  "Copy Constructor called.",
};
//CHECK(d.log_ == expected);
for (auto ele : d.log_){
  std::cout << ele << std::endl;
}
e = d;
expected = {
  "Constructor called with a 5",
  "Copy Constructor called.",
  "= called."
};
//CHECK(e.log_ == expected);
for (auto ele : e.log_){
  std::cout << ele << std::endl;
}
Counter f(e);
expected = {
  "Constructor called with a 5",
  "Copy Constructor called.",
  "= called.",
  "Copy Constructor called."
};
//CHECK(f.log_ == expected);
for (auto ele : f.log_){
  std::cout << ele << std::endl;
}
}