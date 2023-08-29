#include "q2.hpp"
#include <vector>
#include <string>
#include <iterator>
#include <iostream>


int main(){
    std::vector<std::string> words = {"wolf", "BanAna", "caRRot", "AprIcots", "BEets", "chiCkPeas", "orAngEs", "apple", "CAT", "dOG"};
    std::vector<std::string> expected = {"wolf", "apple", "orAngEs", "AprIcots", "BanAna", "BEets", "CAT", "chiCkPeas", "dOG", "caRRot"};
    SortByUppercase(words);
    for (auto ele : words){
        std::cout << ele << ' ';
    }
    return 0;
}