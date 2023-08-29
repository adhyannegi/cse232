#include <string>
#include <iostream>

int main(){
    std::string testimony = "hi";   
    std::string & const new_name = testimony;    
    std::cout << new_name;
}