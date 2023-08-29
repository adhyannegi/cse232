#include <iostream>
#include <string>
#include <math.h>

std::int64_t LocToDec(std::string const & loc){
    std::int64_t ans = 0;
    for (size_t i = 0; i < loc.size(); i++){
        std::int64_t val = loc.at(i) - 'a';
        ans += pow(2, val); 
    }
    return ans;
}

std::string Abbreviate(std::string const & loc){
    std::string ans = "";
    for (size_t i = 0; i < loc.size() -1 ; i++){
        if (loc.at(i) == loc.at(i + 1)){
            ans += loc.at(i) + 1;
        }
        else{
            ans += loc.at(i);
        } 
    }
    return ans;
}

std::string DecToLoc(std::int64_t dec){
    std::string ans = "";
    int i = 0;
    if (dec == 0){
        return ans;
    }
    if (dec == 1){
        return "a";
    }
    while (dec != 0){
        while (pow(2, i) > dec){
            i += 1;
        }
        ans += static_cast<char>(97 + i);
        dec -= pow(2, i);
        i = 0;
    }
    return Abbreviate(ans);
}
