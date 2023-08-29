#include <iostream>
#include <math.h>
#include <cmath>
#include <iomanip>
#include <string>

double Fn(double x){
    return ((-6 * pow(x, 2)) + 5*x + 3);
}

double Integral(double x){
    return ((-2* pow(x, 3)) + ((2.5) * (pow(x, 2))) + ((3*x)));
}

double EstimateWithTraps(double a, double b, int n){
    double delta_x = (b-a)/n;
    double sum = 0;
    double x1 = a;
    double x2 = a + delta_x;
    for (int i = 1; i <= n; i++){
        sum += (Fn(x1) + Fn(x2))/2 * delta_x;
        x1 += delta_x;
        x2 += delta_x;
    }
    return sum;
}


int main(){
    double a, b, tolerance;
    int n;
    std::cout << "Lower Range:" << std::endl;
    std::cin >> a;
    std::cout << "Upper Range:" << std::endl;
    std::cin >> b;
    std::cout << "Tolerance:" << std::endl;
    std::cin >> tolerance;
    std::cout << "Initial trapezoid count:" << std::endl;
    std::cin >> n;
    double actual = Integral(b) - Integral(a);
    double est = EstimateWithTraps(a, b, n);
    double difference = std::fabs(actual - est);
    std::cout << std::fixed;
    std::cout << std::setprecision(4);
    std::cout << "Estimate:"  << est << ", Number of Traps:" << n << ", Diff:" << difference << std::endl;
    while (tolerance < difference){  
        n *= 2;      
        est = EstimateWithTraps(a, b, n);
        difference = std::fabs(actual - est);
        std::cout << "Estimate:"  << est << ", Number of Traps:" << n << ", Diff:" << difference << std::endl;
        
    }
}