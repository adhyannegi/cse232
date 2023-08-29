#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <iomanip>

std::vector<double> ExtractDoubles(const std::string & str1){
    std::istringstream iss(str1);
    std::string val;
    std::vector<double> ans;
    while (iss >> val){
        double ele = std::stod(val);
        ans.push_back(ele);
    }
    return ans;
}

std::string ReturnPercentFormatted(const std::vector<double> & vec1){
    std::ostringstream oss;
    for (double ele : vec1){
        double val = ele * 100;
        oss << std::fixed << std::setprecision(3) << val << "%, ";
    }
    return oss.str();
}

int main(){
    std::string line;
    while (std::getline(std::cin, line)){
        std::cout << ReturnPercentFormatted(ExtractDoubles(line)) << std::endl;
    }
    return 0;
}