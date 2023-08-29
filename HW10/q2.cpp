#include <iostream>
#include <string>

std::string wordle_round(std::string word, std::string guess){
    std::string ans = "";
    for (size_t i = 0; i < word.size(); i++){
        if (word.at(i) == guess.at(i)){
            ans += word.at(i);
        }
        else if (word.find(guess.at(i)) != std::string::npos){
            ans += '?';
        }
        else{
            ans += '.';
        }
    }
    return ans;
}

int main(){
    std::string word, guess;
    std::cout << "Give me a secret word: " << std::endl;
    std::cin >> word;
    int count = 0;
    int flag = 0;
    while (std::cin >> guess){
        std::cout << "Give me a guess: " << std::endl;
        count += 1;
        std::string val = wordle_round(word, guess);
        if (val == word){
            std::cout << val << std::endl;
            std::cout << "You Win!";
            flag = 1;
            break;
        }
        else if (count < 6){
            std::cout << val << std::endl;
        }
        else {
            std::cout << val << std::endl;
            std::cout << "You Lose.";
            break;
        }
    }
    if ((count < 6) && (flag == 0)){
        std::cout << std::endl << "Give me a guess: " << std::endl;
        std::cout << "You Lose.";
    }
    return 0;
}