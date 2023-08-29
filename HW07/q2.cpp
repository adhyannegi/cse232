#include <iostream>
#include <string>

void OnlyEvenDigits(int *x){
    std::string temp = "";
    std::string temp2 = "";
    std::string val = std::to_string(*x);
    for (size_t i = 0; i < val.size(); i++){
        int num = static_cast<int>(val.at(i));
        if (num % 2 == 0){
            temp += val.at(i);
        }
    }
    for (auto ch : temp){
        if (ch != '0'){
            temp2 += ch;
        }
    }
    int ans = std::stoi(temp2);
    *x = ans;
}

int main(){
    int number;
    while (std::cin >> number){
        OnlyEvenDigits(&number);
        std::cout << number << std::endl;
    }
    return 0;
}