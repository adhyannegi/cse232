#pragma once
#include <vector>

class PythonicIntVector
{
private:
    /* data */
    std::vector<int> vec;
public:
    PythonicIntVector();
    void push_back(int num);
    int & at(int index);
};