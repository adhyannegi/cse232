#include "q2.hpp"
#include <vector>
#include <cassert>
#include <iostream>
#include <string>

int main() {
    std::vector const vec_a = {1, 4,  8, 13};
    std::vector const vec_b = {0, 10, 8, 11, 14};
    std::vector const expected = {10, 20, -3, 8, 56, 0, -2};
    std::vector result = MaxVector(vec_a, vec_b);
    for (auto ele : result){
        std::cout << ele << " ";
    }
    std::cout << std::endl;
    std::vector<std::string> const vec_c = {"hello", "apple", "CSE"};
    std::vector<std::string> const vec_d = {"bye", "banana"};
    std::vector<std::string> const expected2 = {"hello", "banana", "CSE"};
    std::cout << (MaxVector(vec_c, vec_d) == expected2) << std::endl;
    std::vector result1 = MaxVector(vec_c, vec_d);
    for (auto ele : result1){
        std::cout << ele << " ";
    }
}