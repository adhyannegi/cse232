#include "functions.hpp"
#include <iostream>
#include <string>
#include <sstream>

int main(){
    std::string str1;
    std::cin >> str1;
    char sep;
    std::cin >> sep;
    std::ostringstream out;
    vector<std::string> ans = split(str1, sep);
    print_vector(out, ans);
    std::cout << out.str();
    return 0;
}