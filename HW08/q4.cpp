#include <iostream>
#include <string>

int main(){
    std::string line;
    std::string ans;
    while (std::getline(std::cin, line)){
        ans += line;
    }
    int curr_length = 2;
    int count = 1;
    std::cout << '\'' << ans.at(0) << '\'' << " is the first to length " << 1 << std::endl;
    for (size_t i = 0; i < ans.size(); i++){
        if (i == (ans.size()-1)){
            if (count == curr_length){
                std::cout << '\'' << ans.at(i) << '\'' << " is the first to length " << curr_length << std::endl;
            }
            break;
        }
        if (ans.at(i) == ans.at(i+1)){
            count += 1;
            if (count == curr_length){
                std::cout << '\'' << ans.at(i) << '\'' << " is the first to length " << curr_length << std::endl;
                curr_length += 1;
            }
        }
        else {
            count = 1;
        }
    }
}