#pragma once
#include <vector>
#include <string>
#include <sstream>

class Counter
{
private:
    /* data */
    int val;
    int count;
public:
    std::vector<std::string> log_;
    Counter();
    Counter(int num);
    Counter(const Counter & C1);
    int Value();
    friend std::ostream& operator<<(std::ostream & oss, Counter & C1);
    Counter operator+(const Counter & C1);
    Counter operator=(const Counter & C1);
};

