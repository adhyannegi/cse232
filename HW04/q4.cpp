#include <iostream>
#include <iomanip>

int main(){
    float num;
    std::cin >> num;
    std::cout <<std::scientific << std::setprecision(1) << std::setw(12) << num << std::endl;
    std::cout <<std::scientific << std::setprecision(3) << std::setw(12) << num << std::endl;
    std::cout <<std::scientific << std::setprecision(5) << std::setw(12) << num << std::endl;
    return 0;
}