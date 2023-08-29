#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <utility>
#include <vector>
#include <iterator>

using std::vector, std::string,std::pair;

// Write your functions here!

auto compare_names = [](const auto& a, const auto& b) {
        return a.first < b.first;
    };

auto pass_fail = [](const auto & a){
    return a.second >= 600;
};

void PassOrFail(std::vector<std::pair<std::string, int>> &v) {
  // The line below does nothing, but prevents an "unused variable" warning
  // You may removed any (void) lines once the variable is being used.
    std::sort(v.begin(), v.end(), compare_names);
    std::partition(v.begin(), v.end(), pass_fail);
    (void) v;  
}


void ShiftRange(std::vector<int> &v, int left, int right) {
  // The lines below do nothing, but prevent "unused variable" warnings
  (void) v;
  (void) left;
  (void) right;
}


std::vector<int> Fibonacci(int n) {
  std::vector<int> result(n);
  return result;
}


int BinaryToInt(const std::string &binary_str) {
  // The line below does nothing, but prevents an "unused variable" warning
  (void) binary_str;
  return 0;
}
