#include "q1.hpp"
#include <string>
#include <sstream>

LispExpression::LispExpression(std::string str1){  
    str = str1;
}

std::string LispExpression::PrettyPrint(){
    std::istringstream iss(str);
    std::string word;
    std::ostringstream oss;
    int indentation = 0;
    while (iss >> word){
        if (word == ")"){
            indentation--;
            if (indentation == 0){
                oss << word;
                oss << std::endl;
                break;
            }
        }
        for (int i = 0; i < indentation; i++){
            oss << " ";
        }
        oss << word;
        if (word == "("){
            indentation++;
        }
        oss << std::endl;
    }
    return oss.str();
}  