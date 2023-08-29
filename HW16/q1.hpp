#include <map>
#include <sstream>
#include <set>
#include <string>
#include <iterator>
#include <algorithm>

std::set<std::string> ReplacementCensor(std::istream & iss, std::ostream & oss, std::map<std::string, std::string> m1){
    std::string line;
    std::set<std::string> set1; 
    while (std::getline(iss, line)){
        std::istringstream iss1(line);
        std::string word;
        while (iss1 >> word){
            std::string lowercase_word;
            std::transform(word.begin(), word.end(), std::back_inserter(lowercase_word), [](unsigned char a){
                return std::tolower(a);
            });
            for (auto it = m1.begin(); it != m1.end(); ++it){
                std::string key = it->first;
                std::string lowercase_key;
                std::transform(key.begin(), key.end(), std::back_inserter(lowercase_key), [](unsigned char a){
                    return std::tolower(a);
                });
                if (lowercase_word.find(lowercase_key) != std::string::npos){
                    set1.insert(word.substr(lowercase_word.find(lowercase_key), key.size()));
                    word.replace(lowercase_word.find(lowercase_key), key.size(), it->second);
                    lowercase_word = "";
                    std::transform(word.begin(), word.end(), std::back_inserter(lowercase_word), [](unsigned char a){
                        return std::tolower(a);
                    });
                }
            }
            if (iss1.eof()){
                oss << word;
            }
            else{
            oss << word << " ";
            }
        }
    }
    return set1;
}