#pragma once
template <typename T>
#include <string>

T Increment(T val){
    val += 1;
    return (val);
}

template <typename T>

std::string AddToString(const std::string & str1, T val){
    return (str1 + std::to_string(val));
}
