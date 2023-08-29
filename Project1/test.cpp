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
    else if ((position + len < word_list.size())){
        if (word_list.at(position + len) != ','){
            return false;
        }
    }
    return (word_in_string == word);
}

int main(){
    std::string test_string = "a,string,for,automated,testing,of,various,word,positions";
    size_t next_pos = 1;
    for (size_t pos = 0; pos < test_string.size(); pos = next_pos) {
        next_pos = std::min( test_string.find(',', pos+1), test_string.size() );
        size_t start = pos ? (pos+1) : 0;
        std::string word = test_string.substr(start, next_pos-start);
        for (size_t i = 0; i < test_string.size(); ++i) {
            std::cout << AtListPosition(test_string, word, i) << "Testing for word '"<< word<< "' at position "<< i<<"; actually at position "<< start<<std::endl;
        }
    }
}

/*
int main(){
    string word1, word2, str1, str2, str3;
    string * word1_ptr = &word1;
    string * word2_ptr = &word2;
    std::cin >> word1 >> word2 >> str1 >> str2 >> str3;
    std::cout << GetFirstInList(str1, word1_ptr, word2_ptr) << " ";
    std::cout << CountInList(str1, word1) << " " << CountInList(str1, word2) << std::endl;
    std::cout << GetFirstInList(str2, word1_ptr, word2_ptr) << " ";
    std::cout << CountInList(str2, word1) << " " << CountInList(str2, word2) << std::endl;
    std::cout << GetFirstInList(str3, word1_ptr, word2_ptr) << " ";
    std::cout << CountInList(str3, word1) << " " << CountInList(str3, word2);
}
*/