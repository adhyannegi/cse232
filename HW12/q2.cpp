#include "q2.hpp"
#include "name_checker.hpp"
#include <iostream>
#include <vector>
#include <string>

std::vector<int> CountExceptions(std::vector<std::string> const & input){
    std::vector<int> ans(3, 0);
    for (std::string ele : input){
        try {
            CheckName(ele);
        }
        catch(std::invalid_argument &){
            ++ans.at(0);
        }
        catch(std::length_error &){
            ++ans.at(1);
        }
        catch(std::out_of_range &){
            ++ans.at(2);
        }
    }
    return ans;
}

#include <string>
#include <vector>
#include <cassert>

int main() {
	std::vector<std::string> names = {"A Game of Thrones", "A Clash of Kings", 
		"A Storm of Swords", "A Feast for Crows", "A Dance with Dragons", 
		"The Winds of Winter", "A Dream of Spring"};
	std::vector<int> exception_count = CountExceptions(names);
	std::vector<int> expected = {1, 0, 2};
	for (int ele : exception_count){
        std::cout << ele << " ";
    }
	return 0;
}