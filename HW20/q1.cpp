#include "q1.hpp"
#include <sstream>
#include <iomanip>
#include <string>

Price::Price(){
    value = static_cast<double>(0);
}

Price::Price(double number){
    value = number;
}

std::ostream& operator<<(std::ostream & oss, const Price & P1){
    oss << "$" << std::fixed << std::setprecision(2) << P1.value;
    return oss;
}

Price operator+(const Price & P1, const Price & P2){
    Price ans;
    ans.value = P1.value + P2.value;
    return ans;
}

Price operator+=(Price & P1, const Price & P2){
    P1.value += P2.value;
    return P1;
}

Price operator-(const Price & P1, const Price & P2){
    Price ans;
    ans.value = P1.value - P2.value;
    return ans;
}

Price operator-=(Price & P1, const Price & P2){
    P1.value -= P2.value;
    return P1;
}

Price operator>>(std::istream & iss, Price & P1){
    std::string word;
    iss >> word;
    word = word.substr(1);
    P1.value = std::stod(word);
    return P1;
}