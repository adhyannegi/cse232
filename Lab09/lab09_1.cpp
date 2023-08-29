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

int main(){
    std::string ans = "";
    if (TestResult(IsSecurePassword("aaaBBB@@123"), 6, "ignores lowercase") == true){
        if (TestResult(IsSecurePassword("aaaBBB@@123"), 6, "ignores digits") == true){
            if (TestResult(IsSecurePassword("aaaBBB@@123"), 6, "allows symbols") == true){
                if (TestResult(IsSecurePassword("aaaBBB@@123"), 6, "fails to count unlisted symbols") == true){
                    if (TestResult(IsSecurePassword("aaaBBB@@123"), 6, "does not provide final bonus") == true){
                        if (TestResult(IsSecurePassword("aaaBBB@@123"), 6, "requires length to give final bonus") == true){
                            if (TestResult(IsSecurePassword("aaaBBB@@123"), 6, "length should be 10") == true){
                                if (TestResult(IsSecurePassword("aaaBBB@@123"), 6, "length should be greater than 10") == true){
                                    if (TestResult(IsSecurePassword("aaaBBB@@123"), 6, "correct IsSecure Password") == true){
                                    std::cout << "Pass";
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    else {
        std::cout << "Fail";
    }
}