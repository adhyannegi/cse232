#include <string>
#include <iostream>
#include <sstream>
#include <string>

int main(){
    std::string str;
    std::cin >> str;
    std::string word;
    std::istringstream iss(str);
    while (std::getline(iss, word)){
        std::istringstream iss1(word);
        std::string hmm;
        while (iss1 >> hmm){
            std::cout << hmm << " ";
        }
    }
}