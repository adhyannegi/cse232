#include "q1.hpp"
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <set>

int main(){
  std::map<std::string, std::string> bad_to_good = {{"word", "Grouped-Letter-Unit"}, {"be", "wasp"}, {"not found", "not appearing"}, {"PlaCe", "LoCation"}, {"other", "j"}};
  std::istringstream iss("note: this is a line with multiple WORds that should be rePLACEd bE./n all instances of word eveninlargerWordsshould be repLAced.other");
  std::ostringstream oss;
  std::set result = ReplacementCensor(iss, oss, bad_to_good);
  std::set expected_return = {"PLACE", "WORd", "Word", "be", "pLAce", "word"};
  for (auto ele : result){
    std::cout << ele << " ";
  }
  std::cout << std::endl << oss.str();
}