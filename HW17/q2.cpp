#include "q2.hpp"
#include <vector>

ForgetfulVector::ForgetfulVector(){
    already_seen = {};
}

void ForgetfulVector::push_back(int value){
    auto insert_into_set = already_seen.insert(value);
    if (!insert_into_set.second){
        actual_values.push_back(value);
    }
}

int & ForgetfulVector::at(int index){
    return actual_values.at(index);
}

int ForgetfulVector::size(){
    int val = actual_values.size();
    return val;
}

int main(){
    return 0;
}