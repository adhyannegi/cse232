#include <iostream>
#include <string>
#include <sstream>
using std::string, std::cin, std::cout;

int main(){
    string str2;
    while(std::getline(cin, str2)){
        std::istringstream iss(str2);
        string str1;
        while (iss >> str1){    
            if ((str1.at(0) == str1.at(1)) || (str1.at(0) == (str1.at(1) - 1)) || (str1.at(0) == (str1.at(1) + 1))){
                std::cout << str1.at(0);
            }
            size_t i = 1;
            for (i = 1; i < (str1.size() - 1); i++){
                if (((str1.at(i) == str1.at(i+1)) || (str1.at(i) == (str1.at(i+1) - 1)) || (str1.at(i) == (str1.at(i+1) + 1))) ||
                ((str1.at(i) == str1.at(i-1)) || (str1.at(i) == (str1.at(i-1) - 1)) || (str1.at(i) == (str1.at(i-1) + 1)))){
                    std::cout << str1.at(i);
                }
            }
            if ((str1.at(i) == str1.at(i-1)) || (str1.at(i) == (str1.at(i-1) - 1)) || (str1.at(i) == (str1.at(i-1) + 1))){
                std::cout << str1.at(i);
            }
            cout << std::endl;
        }
    }
    return 0;
}