#include <iostream>
#include <string>

std::string SharedLetters(std::string const & s1, std::string const s2, std::string const * const s3_ptr){
    std::string ans = "";
    std::string max = "";
    if ((s1.size() >= s2.size()) && (s1.size() >= (*s3_ptr).size())){
        max = s1;
    }
    else if ((s2.size() >= s1.size()) && (s2.size() >= (*s3_ptr).size())){
        max = s2;
    }
    else if (((*s3_ptr).size() >= s1.size()) && ((*s3_ptr).size()) >= (s1.size())){
        max = (*s3_ptr);
    }
    for (size_t i = 0; i < max.size(); i++){
        std::string count = "0";
        if (i >= s1.size()){
            if ((i >= s2.size()) || (i >= (*s3_ptr).size())){
                count = "0";
            }
            else if (s2.at(i) == (*s3_ptr).at(i)){
                count = "1";
            }
            else {
                count = "0";
            }
        }

        else if (i >= s2.size()){
            if ((i >= s1.size()) || (i >= (*s3_ptr).size())){
                count = "0";
            }
            else if (s1.at(i) == (*s3_ptr).at(i)){
                count = "1";
            }
            else {
                count = "0";
            }
        }

        else if (i >= (*s3_ptr).size()){
            if ((i >= s2.size()) || (i >= s2.size())){
                count = "0";
            }
            else if (s2.at(i) == s2.at(i)){
                count = "1";
            }
            else {
                count = "0";
            }
        }

        else if ((s1.at(i) == s2.at(i)) && (s2.at(i) == (*s3_ptr).at(i))){
            count = "3";
        }
        else if ((s1.at(i) == s2.at(i)) || (s2.at(i) == (*s3_ptr).at(i)) || (s1.at(i) == (*s3_ptr).at(i))){
            count = "1";
        }
        ans = ans + count + ',';
    }
    return ans;
}

int main(){
    std::string str1, s2, str3;
    std::cin >> str1 >> s2 >> str3;
    std::string const & s1 = str1;
    std::string const * const s3_ptr = &str3;
    std::cout << SharedLetters(s1, s2, s3_ptr);
}