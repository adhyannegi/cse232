#include <iostream>
#include <string>
#include <cctype>

bool TestResult(int result, int expected, const std::string error_message) {
  if (result != expected) {
    std::cerr << error_message << std::endl
              << "Result: " << result << std::endl
              << "Expected: " << expected << std::endl;
    return false;
  }
  return true;
}

int main() {
    // Place your testcode here!
    std::string password = "HeyGuys@12@3";
    int expected = 6;
    int count = 0;
    if (password.size() >= 10){
    count ++;
    } 

    int lower_count = 0;
    for (int ele : password){
    if (islower(ele)){
        lower_count++;
        }
    }
    if (lower_count){
        count++;
    }

    int upper_count = 0;
    for (int ele : password){
    if (isupper(ele)){
        upper_count++;
        }
    }
    if (upper_count){
        count ++;
    }

    int digit_count = 0;
    for (int ele : password){
    if (isdigit(ele)){
        digit_count++;
        }
    }
    if (digit_count){
        count++;
    }

    int special_char_count = 0;
    for (char ele : password){
        if ((ele == '!') || (ele == '@') || (ele == '#') || (ele == '$') || (ele == '%') || (ele == '^') || (ele == '&') || (ele == '*') || (ele == '(') || (ele == ')')){
            special_char_count++;
        }
    }
    if (special_char_count){
        count++;
    }

    if ((lower_count >= 2) && (upper_count >= 2) && (digit_count >= 2) && (special_char_count >= 2)){
        count++;
    }
    if (TestResult(count, expected, "Failed")){
        std::cout << "Pass";
    }
}