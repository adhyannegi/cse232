#include <vector>
#include <iostream>
#include "q1.hpp"

int main(){
    std::vector data = {6, 1, 5, 4, 3, 2, -1};
    auto iter_smallest = FindSmallestIndexRange(data, 2, 5);
    std::cout << (*iter_smallest == 2);
    iter_smallest = FindSmallestIndexRange(data, 2, 4);
    std::cout << (*iter_smallest == 3);
    iter_smallest = FindSmallestIndexRange(data, 1, 5);
    std::cout << (*iter_smallest == 1);
    iter_smallest = FindSmallestIndexRange(data, 0, 5);
    std::cout << (*iter_smallest == 1);
    iter_smallest = FindSmallestIndexRange(data, 0, 6);
    std::cout << (*iter_smallest == -1);
    iter_smallest = FindSmallestIndexRange(data, 0, 20);
    std::cout << (*iter_smallest == -1);
    std::vector data2 = {6, 1, 5, 0, 3, 2, 1};
    iter_smallest = FindSmallestIndexRange(data2, 1, 7);
    std::cout << (*iter_smallest == 0);
    iter_smallest = FindSmallestIndexRange(data2, 4, 7);
    std::cout << (*iter_smallest == 1);
    return 0;    
}