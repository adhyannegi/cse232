#pragma once
#include <iterator>
#include <vector>

std::vector<int>::const_iterator FindSmallestIndexRange(std::vector<int> & vec, int min_idx, int max_idx){
    std::vector<int>::iterator min_itr = vec.begin() + min_idx;
    int min_num = 9999;
    if (max_idx >= static_cast<int>(vec.size())){
        return std::min_element(vec.begin() + min_idx, vec.end());
    }
    for (auto i = (vec.begin() + min_idx); i != (vec.begin() + max_idx + 1); i++){
        if (*i < min_num){
            min_num = *i;
            min_itr = i;
        }
    }
    return min_itr;
};

template <typename T>

void DoubleIteratorRange(T start, T end){
    for (T i = start; i != end; i++){
        *i = (*i)*2;
    }
};
