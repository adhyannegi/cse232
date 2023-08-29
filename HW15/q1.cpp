#include <string>
#include <vector>
#include <iterator>

int Func(int a) 
{
    std::vector<int> b(a);
    int val = 12;
    for (size_t i = 0; i < b.size(); i++){
        b.at(i) = val;
        val += 1;
    }

    std::vector<int> c(b);
    int temp = 0;
    size_t i = 0;
    size_t j = c.size() - 1;
    while (i < j){
        temp = c.at(i);
        c.at(i) = c.at(j);
        c.at(j) = temp;
        i++;
        j--;
    }

    for (size_t i = 0; i < b.size(); i++){
        b.at(i) = 2 * b.at(i) + c.at(i);
    }

    int count = 0;
    for (size_t i = 2; i < b.size() - 2; i++){
        if (std::to_string(b.at(i)).find("2") != std::string::npos){
            count++;
        }
    }
    return count;
}
