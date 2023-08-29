#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using std::string, std::vector;

vector<string> split(string const &s, char sep){
    string word;
    vector<string> ans;
    for (size_t i = 0; i < s.size(); i++){
        if (i == (s.size() - 1)){
            ans.push_back(word);
            return ans;
        }
        if (s.at(i) == sep){
            ans.push_back(word);
        }
        else{
            word += s.at(i);
        }
    }
    return ans;
}

void print_vector(std::ostringstream &out, vector<string> const &v){
    string word;
    for (auto word : v){
        out << word << ' ';
    }
}

int main(){
    return 0;
}