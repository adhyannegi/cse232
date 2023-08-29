#include "q1.cpp"
#include <iostream>

int main(){
    LispExpression le("(   ( ) q  ( a ( b ) )  ) ( a )");
    std::string result = le.PrettyPrint();
    std::cout << result;
}