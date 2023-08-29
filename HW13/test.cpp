#include <vector>
#include <iterator>
#include <iostream>

int main(){
    std::vector<int> vec = {1, 2, 3, 4, 5};
    for (auto i = vec.begin() + 1; i != vec.begin() + 3 + 1; i++){
        std::cout << *i;
    }
    return 0;
}