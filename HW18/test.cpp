#include "q1.cpp"
#include <iostream>

int main(){
    Temperature t(13, 'C');
    std::cout << t.AsCelsius() << std::endl;
    std::cout << t.AsKelvin() << std::endl;
    std::cout << t.AsRankine() << std::endl;
    Temperature t2(45.6, 'R');
    std::cout << t2.AsFahrenheit();
}