#include <vector>
#include <algorithm>
#include <iostream>

std::vector<int> SumByIndex(std::vector<std::vector<int>> const & vec){
    std::vector<int> max_size_vec;
    for (auto ele : vec){
        max_size_vec.push_back(ele.size());
    }
    int max_size = *(std::max_element(max_size_vec.begin(), max_size_vec.end()));
    std::vector<int> ans(max_size, 0);
    for (auto ele : vec){
        for (size_t i = 0; i < ele.size(); i++){
            ans.at(i) += ele.at(i);
        }
    }
    return ans;
}

int main(){
    std::vector<std::vector<int>> vec = {{1, 2, 3}, {4, 9}};
    std::vector<int> ans = SumByIndex(vec);
    for (auto ele : ans){
        std::cout << ele;
    }
}