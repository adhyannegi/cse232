#include <iostream>
#include <string>
using std::string;

bool AtListPosition(const string &word_list, const string &word, size_t position){
    size_t len = word.size();
    string word_in_string = word_list.substr(position, len);
    if (position == 0){
        if (word_list.at(len) != ','){
            return false;
        }
    }
    else if (word_list.at(position - 1) != ','){
        return false;
    }
    else if ((position + len) < word_list.size()){
        if (word_list.at(position + len) != ','){
            return false;
        }
    }
    return (word_in_string == word);
}

size_t FindInList(const string &word_list, const string &word, size_t position = 0){
    if ((position >= word_list.size()) || (word.size() > word_list.size()) || ((word_list.size() == word.size()) && (word_list != word))){
        return string::npos;
    }
    else if (word_list == word){
        return 0;
    }
    while (true){
        if (position == word_list.size()){
            return string::npos;
        }
        if (AtListPosition(word_list, word, position)){
            if ((position + word.size()) >= word_list.size()){
                return position;
            }
            else if (word_list.at(position + word.size()) == ','){
                return position;
            }
        }
        position++;
    }
}

string GetFirstInList(const string &word_list, string * word1, string * word2){
    if ((FindInList(word_list, *word1) == string::npos) && (FindInList(word_list, *word2) == string::npos)){
        return "N/A";
    }
    else if ((FindInList(word_list, *word1) == string::npos)){
        return (*word2);
    }
    else if (FindInList(word_list, *word2) == string::npos){
        return (*word1);
    }
    else {
        if (FindInList(word_list, *word1) > FindInList(word_list, *word2)){
            return (*word2);
        }
        else {
            return (*word1);
        }
    }
}

size_t CountInList(const string &word_list, const string &word){
    size_t count = 0;
    size_t temp = 0;
    if (word_list == word){
        return 1;
    }
    else if (word_list.size() == word.size()){
        return 0;
    }
    else if (word.size() > word_list.size()){
        return 0;
    }
    while (temp <= word_list.size()){
        size_t pos = FindInList(word_list, word, temp);
        if (pos == string::npos){
            return count;
        }
        temp = pos + word.size();
        count += 1;
    }
    return count;
}

int main(){
    string word1, word2;
    std::cin >> word1 >> word2;
    string str1;
    while (std::cin >> str1){
        std::cout << GetFirstInList(str1, &word1, &word2) << " ";
        std::cout << CountInList(str1, word1) << " " << CountInList(str1, word2) << std::endl;
    }
}
