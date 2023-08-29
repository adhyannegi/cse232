#include <iostream>
#include <string>
#include <cctype>

int main(){
    std::string input;
    while (std::getline(std::cin, input)){
        if (input.size() == 0){
            continue;
        }
        int i = 0;
        while (true){
            if (isalpha(input.at(i))){
                std::cout << input.at(i);
                break;
            }
            i++;
        }
        for (size_t j = i; j < input.size() - 1; j++){
            if (isblank(input.at(j)) || isdigit(input.at(j)) || ispunct(input.at(j))){
                if (isalpha(input.at(j+1))){
                    std::cout << input.at(j+1);
                }
            }
        }
    }
}