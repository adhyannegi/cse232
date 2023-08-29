#include <iostream>
#include <string>

int ReverseDigits(int value) {
// WRITE YOUR CODE HERE
    std::string rev = "";
    std::string val = std::to_string(value);
    for (int i = val.size() - 1; i >= 0; i--){
        rev += val.at(i);
    }
    int ans = std::stoi(rev);
    return ans;
}

int main() {
	for (int i = 0; i < 3; ++i) {
		int number;
		std::cin >> number;
		std::cout << ReverseDigits(number) << std::endl;
	}
    return 0;
}