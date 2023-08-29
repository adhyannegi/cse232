#include <string>
#include <sstream>

int SumButScared(const std::string & str1){
    std::istringstream iss(str1);
    std::string val;
    int sum = 0;
    while (iss >> val){
        int num = std::stoi(val);
        if (num % 13 == 0){
            throw std::invalid_argument("Invalid");
        }
        else {
            sum += num;
        }
    }
    return sum;
}