#include "q1.hpp"
#include <string>

Penultimate::Penultimate(std::string input){
    str1 = input;
}

std::string Penultimate::push_back(std::string input){
    std::string val = str1;
    str1 = input;
    return val;
}