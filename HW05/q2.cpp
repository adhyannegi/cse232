#include <iostream>
#include <string>

int main(){
    std::string input;
    while (std::getline(std::cin, input)){
        
        if (input.length() > 0) {
            std::cout << input.at(0);
        }
        for (size_t i =1; i < input.length(); i++){
            if (input.at(i) > input.at(i - 1)){
                std::cout << input.at(i);
            }
            else{
                std::cout << '_';
            }
        }
        std::cout << '\n';
    }
}