#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <algorithm>

using std::cin, std::cout, std::string, std::vector;

int main(){
    vector<string> vec1;
    vector<float> vec2;
    string i;

    while (cin >> i){
        vec1.push_back(i);
    }

    for (auto k : vec1){
        k.erase(k.length() - 1);
        float j = std::stof(k);
        vec2.push_back(j);
    }

    float median = 98.2;

    for (auto i = 0; i < vec2.size(); i++){
        if (median > vec2.at(i)){
            if ((median - vec2.at(i)) < 0.5){
                cout << vec2.at(i) << 'F' << std::endl;
            }
        }
        else if (vec2.at(i) > median){
            if ((vec2.at(i) - median) < 0.5){
                cout << vec2.at(i) << 'F' << std::endl;
            }
        }
        else {
            cout << vec2.at(i) << 'F' << std::endl;
        }
    }

    return 0;
}