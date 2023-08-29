#include <iostream>
#include <string>

int main(){
    int x;
    std::string s = "";

    while (!std::cin.fail()) {
        std::cin >> x;
        if(!std::cin.fail())
            s += std::to_string(x) + "+";
    }
    if(s.size()>0) s.pop_back();
    std::cout << s;
    return 0;
}