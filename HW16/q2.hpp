#pragma once
#include <vector>
#include <algorithm>
#include <string>
template <typename T>

std::vector<T> MaxVector(const std::vector<T> & vec1, const std::vector<T> & vec2){
    size_t max_size = std::max(vec1.size(), vec2.size());
    std::vector<T> ans(max_size);

    if (vec1.size() > vec2.size()){
        std::transform(vec1.begin(), vec1.end(), ans.begin(), [](T a){
            return a;
        });
        std::transform(vec2.begin(), vec2.end(), ans.begin(), ans.begin(), [](T a, T b){
            if (a > b){
                return a;
            }
            return b;
        });
    }
    else {
        std::transform(vec2.begin(), vec2.end(), ans.begin(), [](T a){
            return a;
        });
        std::transform(vec1.begin(), vec1.end(), ans.begin(), ans.begin(), [](T a, T b){
            if (a > b){
                return a;
            }
            return b;
        });
    }
    return ans;
}