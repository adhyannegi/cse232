#include <iostream>
#include <string>

char * Sandwich(std::string & line, char * bread_ptr){
    char * ans = nullptr;
    for (size_t i = 0; i < line.size(); i++){
        if (i == (line.size() - 1)){
            break;
        }
        if (line.at(i) == (*bread_ptr)){
            if (line.at(i + 2) == (*bread_ptr)){
                ans = &(line.at(i + 1));
                break;
            }
        }
    }
    return ans;
}

int main(){
    std::string line = "nice nickolas has no banana for nancy or hannah";
    char bread = 'n';
    char * filling_ptr = Sandwich(line, &bread);
    std::cout << *filling_ptr << std::endl;
    * filling_ptr = '*';
    std::cout << line;
}