#include <iostream>
#include <string>
#include <sstream>
using std::string, std::cin, std::cout;

int main(){
    string str1;
    int count = 0;
    while (std::getline(cin, str1)){
        std::istringstream iss(str1);
        string word;
        while (iss >> word){
            count++;
            if (count == 11){
                cout << std::endl;
                count = 1;
            }
            if (word.size() == 3){
                if (count == 10){
                    cout << word;
                }
                else{
                    cout << word << ' ';
                }
            }
            else {
                for (size_t i = 1; i < (word.size() / 2); i++){
                    char temp = word.at(i);
                    word.at(i) = word.at(word.size() - i - 1);
                    word.at(word.size() - i - 1) = temp;
                }
                if (count == 10){
                    cout << word;
                }
                else{
                cout << word << ' ';
                }
            }
        }
    }
}