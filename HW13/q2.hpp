#pragma once
#include <algorithm>
#include <numeric>
#include <vector>
#include <string>
#include <iterator>
#include <cctype>
#include <sstream>

bool compare(std::string s1, std::string s2){
    std::string uc1, uc2;
    std::copy_if(s1.begin(), s1.end(), std::back_inserter(uc1), isupper);
    std::copy_if(s2.begin(), s2.end(), std::back_inserter(uc2), isupper);
    if (uc1 > uc1){
        return false;
    }
    else if (uc2 > uc1){
        return true;
    }
    return false;
}

void SortByUppercase(std::vector<std::string> & vec1){
    std::stable_sort(vec1.begin(), vec1.end(), compare);
}

int SumOfOdd(std::vector<int>::const_iterator start, std::vector<int>::const_iterator end){
    int ans = std::accumulate(start, end, 0, [](int sum, int val){
        if (val % 2 != 0){
            return (sum + val);
        }
        return sum;
    });
    return ans;
}

std::string DoubleToPercentString(std::vector<double> const vec){
    std::string ans = "";
    std::string temp1 = std::accumulate(vec.begin(), vec.end(), ans, [](std::string temp, double num){
        int val = num * 100;
        std::string val1 = std::to_string(val) + "% ";
        return temp + val1;
    });
    return temp1;
}
