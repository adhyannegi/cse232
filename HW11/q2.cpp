#include <string>
#include "q2.hpp"

int Repeat(int num){
    return (num * 2);
}

std::string Repeat(char c){
    std::string ans;
    ans += c;
    ans += c;
    return ans;
}

std::string Repeat(std::string str1){
    std::string ans = str1;
    ans += " ";
    ans += str1;
    return ans;
}

