#include <iostream>
#include <string>

int main(){
    int startmul, endmul, num1, num2;
    std::cin >> startmul >> endmul >> num1 >> num2;
    for (int i = num1; i <= num2; i++){
        for (int j = startmul; j < endmul; j++){
            std::cout << i << '*' << j << '=' << i * j << ", ";
        }
        std::cout << i << '*' << endmul << '=' << i * endmul;
        std::cout << std::endl;
    }
}