#pragma once
#include <set>
#include <vector>

class ForgetfulVector {
    std::set<int> already_seen;
    std::vector<int> actual_values;

    public:
    ForgetfulVector();
    int size();
    int & at(int);
    void push_back(int);
};