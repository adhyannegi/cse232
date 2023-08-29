#include "q2.hpp"

PythonicIntVector::PythonicIntVector(){
    vec = {};
}

void PythonicIntVector::push_back(int num){
    vec.push_back(num);
}

int & PythonicIntVector::at(int index){
    if (index >= 0){
        return vec.at(index);
    }
    int len = vec.size();
    return vec.at(len + index);
}